#include <vector>
#include <string>
#include <filesystem>
#include <unordered_set>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <toml.hpp>
#include "elfio/elfio.hpp"

constexpr uint32_t overlay_vram = 0x80800000;
constexpr uint32_t symbol_not_found = 0xFFFFFFFF;
constexpr uint32_t section_size_divisor = 0x10;

enum class RelocType {
    R_MIPS_NONE = 0,
    R_MIPS_16,
    R_MIPS_32,
    R_MIPS_REL32,
    R_MIPS_26,
    R_MIPS_HI16,
    R_MIPS_LO16,
    R_MIPS_GPREL16,
};

enum class TooieRelocType {
    R_MIPS_32 = 0,
    R_MIPS_26 = 1,
    R_MIPS_HI16 = 2,
    R_MIPS_LO16 = 3
};

const std::unordered_map<RelocType, TooieRelocType> reloc_mapping {
    { RelocType::R_MIPS_32, TooieRelocType::R_MIPS_32 },
    { RelocType::R_MIPS_26, TooieRelocType::R_MIPS_26 },
    { RelocType::R_MIPS_HI16, TooieRelocType::R_MIPS_HI16 },
    { RelocType::R_MIPS_LO16, TooieRelocType::R_MIPS_LO16 },
};

struct Symbol {
    std::string name;
    uint32_t value;
    Symbol(const char* name_) : name(name_), value(symbol_not_found) {}
    Symbol() : name(""), value(symbol_not_found) {}
};

struct Overlay {
    std::string name;
    std::vector<Symbol> entrypoints;
    Symbol text_size;
    Symbol rodata_size;
    Symbol data_size;
    Symbol bss_size;
    ELFIO::section* section;
    ELFIO::section* bss_section;
    ELFIO::section* reloc_section;
    Overlay(const std::string& name_, std::vector<Symbol>&& entrypoints_) : name(name_), entrypoints{std::move(entrypoints_)},
        text_size{}, rodata_size{}, data_size{}, bss_size{},
        section(nullptr), bss_section(nullptr), reloc_section(nullptr) {}
    Overlay(const std::string& name_) : name(name_), entrypoints{},
        text_size{}, rodata_size{}, data_size{}, bss_size{},
        section(nullptr), bss_section(nullptr), reloc_section(nullptr) {}
};

std::vector<Overlay> read_config(const char* path) {
    try {
		const toml::value config_data = toml::parse(path);
		const toml::array& overlay_array = toml::find<toml::array>(config_data, "overlay");

        std::vector<Overlay> overlays{};
        overlays.reserve(overlay_array.size());

        for (const auto& overlay_data : overlay_array) {
            bool is_empty = toml::find_or<bool>(overlay_data, "empty", false);
            if (!is_empty) {
                const toml::value& entrypoint_name = toml::find<toml::value>(overlay_data, "name");
                const toml::array& entrypoint_array = toml::find<toml::array>(overlay_data, "entrypoints");
                std::vector<Symbol> entrypoints{};
                entrypoints.resize(entrypoint_array.size());
                for (size_t i = 0; i < entrypoint_array.size(); i++) {
                    entrypoints[i].name = entrypoint_array[i].as_string();
                    entrypoints[i].value = symbol_not_found;
                }
                overlays.emplace_back(entrypoint_name.as_string().str, std::move(entrypoints));
            }
            else {
                overlays.emplace_back("");
            }
        }
        return overlays;
    }
	catch (const toml::syntax_error& err) {
		fmt::print(stderr, "Syntax error in config file on line {}, full error:\n{}\n", err.location().line(), err.what());
        std::exit(EXIT_FAILURE);
	}
	catch (const toml::type_error& err) {
		fmt::print(stderr, "Incorrect type in config file on line {}, full error:\n{}\n", err.location().line(), err.what());
        std::exit(EXIT_FAILURE);
	}
	catch (const std::out_of_range& err) {
		fmt::print(stderr, "Missing value in config file, full error:\n{}\n", err.what());
        std::exit(EXIT_FAILURE);
	}
    return {};
}

std::vector<uint16_t> read_original_relocs(const std::string& original_reloc_path) {
    std::ifstream reloc_file{original_reloc_path, std::ios_base::binary};
    reloc_file.seekg(0, std::ios_base::end);
    size_t reloc_file_size = reloc_file.tellg();
    reloc_file.seekg(0, std::ios_base::beg);
    
    size_t reloc_count = reloc_file_size / sizeof(uint16_t);

    std::vector<uint16_t> ret;
    ret.resize(reloc_count);
    reloc_file.read(reinterpret_cast<char*>(ret.data()), reloc_count * sizeof(uint16_t));
    
    return ret;
}

// Sorts relocs by their offset, but keeps HI16/LO16 pairs together
void sort_relocs(std::vector<uint16_t>& relocs, const std::string& original_reloc_path) {
    // Read the original relocs that were pulled from the ROM
    std::vector<uint16_t> original_relocs = read_original_relocs(original_reloc_path);
    // Convert the generated relocs into a set for quick lookups
    std::unordered_set<uint16_t> reloc_set{relocs.begin(), relocs.end()};
    // Clear the generator reloc vector so it can be filled back in during sorting
    relocs.clear();

    // Iterate over every original reloc and check if it exists in the generated relocs
    for (size_t i = 0; i < original_relocs.size(); i++) {
        uint16_t cur_reloc = original_relocs[i];

        auto find_it = reloc_set.find(cur_reloc);
        // If the reloc does exist, pull it into the output vector
        if (find_it != reloc_set.end()) {
            // If this is a HI16 reloc, pull any paired LO16 relocs with it
            if (TooieRelocType(cur_reloc & 0x3) == TooieRelocType::R_MIPS_HI16) {
                // Determine how many LO16 relocs are paired to this HI16
                // Pulling isn't done here, as we don't want to pull a HI16 unless all of its paired LO16 relocs are present as well
                size_t lo16_count = 0;
                while ((i + lo16_count + 1) < relocs.size() && TooieRelocType(relocs[i + 1] & 0x3) == TooieRelocType::R_MIPS_LO16) {
                    // Check if the current LO16 is in the generated relocs
                    if (reloc_set.contains(original_relocs[i + lo16_count + 1])) {
                        lo16_count++;
                    }
                    else {
                        lo16_count = size_t(-1);
                        break;
                    }
                }
                // If all of the paired LO16 relocs were found, pull them all into the generated reloc vector
                if (lo16_count != size_t(-1)) {
                    // Pull the HI16
                    relocs.push_back(cur_reloc);
                    reloc_set.erase(find_it);
                    // Pull all the LO16
                    for (size_t count_copied = 0; count_copied < lo16_count; count_copied++) {
                        uint16_t reloc_to_copy = original_relocs[i + count_copied + 1];
                        relocs.push_back(reloc_to_copy);
                        reloc_set.erase(reloc_to_copy);
                    }

                    i += lo16_count;
                }
            }
            // Otherwise, just pull this reloc on its own
            else {
                reloc_set.erase(find_it);
                relocs.push_back(cur_reloc);
            }
        }
    }

    // Copy any remaining generated relocs that weren't found during sorting back into the vector
    std::copy(reloc_set.begin(), reloc_set.end(), std::back_inserter(relocs));
}

int main(int argc, const char **argv) {
    if (argc != 3) {
        fmt::print(stderr,
            "Processes a Banjo Tooie elf file to build overlay headers and the overlay rom table.\n"
            "Usage: {} [elf file] [output asm path]\n", argv[0]);
        return EXIT_SUCCESS;
    }

    (void)argc;
    (void)argv;
    auto exit_failure = [] (const std::string& error_str) {
        fmt::vprint(stderr, error_str, fmt::make_format_args());
        std::exit(EXIT_FAILURE);
    };

    const char* elf_path = argv[1];

    ELFIO::elfio elf_file;
    if (!elf_file.load(elf_path)) {
        exit_failure("Failed to load provided elf file\n");
    }

    if (elf_file.get_class() != ELFIO::ELFCLASS32) {
        exit_failure("Incorrect elf class\n");
    }

    if (elf_file.get_encoding() != ELFIO::ELFDATA2MSB) {
        exit_failure("Incorrect endianness\n");
    }

    std::vector<Overlay> overlays = read_config("overlays.us.v10.toml");

    std::unordered_map<std::string, Overlay*> overlay_map{};
    std::unordered_map<std::string, Symbol*> symbol_map{};

    Symbol overlay_table_sym{"overlay_table_ROM_START"};
    symbol_map[overlay_table_sym.name] = &overlay_table_sym;

    for (auto& ovl : overlays) {
        if (!ovl.name.empty()) {
            overlay_map[ovl.name] = &ovl;

            // Add the overlay's section sizes to the symbol map
            auto setup_size_sym = [&] (Symbol& s, const char* suffix) {
                s.name = ovl.name + suffix;
                symbol_map[s.name] = &s;
            };

            setup_size_sym(ovl.text_size, "_TEXT_SIZE");
            setup_size_sym(ovl.rodata_size, "_RODATA_SIZE");
            setup_size_sym(ovl.data_size, "_DATA_SIZE");
            setup_size_sym(ovl.bss_size, "_BSS_SIZE");

            // Add the overlay's entrypoints to the symbol map
            for (auto& entrypoint : ovl.entrypoints) {
                symbol_map[entrypoint.name] = &entrypoint;
            }
        }
    }

    ELFIO::section* symtab_section = nullptr;

    // Find all overlay sections and their reloc sections 
    for (const auto& section : elf_file.sections) {
        std::string section_name = section->get_name();
        ELFIO::Elf_Word type = section->get_type();

        // Check if this is a reloc section
        bool is_reloc_section = false;
        if (section_name.starts_with(".rel") && type == ELFIO::SHT_REL) {
            is_reloc_section = true;
            section_name = section_name.substr(std::strlen(".rel"));
        }

        bool is_bss_setion = false;
        if (section_name.ends_with("_bss")) {
            is_bss_setion = true;
            section_name = section_name.substr(0, section_name.size() - std::strlen("_bss"));
        }

        // Check if this section has a corresponding overlay
        if (!section_name.empty()) {
            // Strip the dot off the start of the section name
            auto find_it = overlay_map.find(section_name.substr(1));
            if (find_it != overlay_map.end()) {
                if (is_reloc_section) {
                    find_it->second->reloc_section = section.get();
                }
                else if (is_bss_setion) {
                    find_it->second->bss_section = section.get();
                }
                else {
                    find_it->second->section = section.get();
                }
            }
        }

        // Check if this section is the symbol table
        if (type == ELFIO::SHT_SYMTAB) {
            symtab_section = section.get();
        }
    }

    if (symtab_section == nullptr) {
        exit_failure("Failed to find symbol table section\n");
    }

    // Read all the symbols in the elf and find the entrypoints
    ELFIO::symbol_section_accessor symbols{elf_file, symtab_section};
    for (size_t sym_index = 0; sym_index < symbols.get_symbols_num(); sym_index++) {
        std::string   name;
        ELFIO::Elf64_Addr    value = symbol_not_found;
        ELFIO::Elf_Xword     size;
        unsigned char bind;
        unsigned char type;
        ELFIO::Elf_Half      section_index;
        unsigned char other;
        symbols.get_symbol(sym_index, name, value, size, bind, type, section_index, other);

        auto find_it = symbol_map.find(name);
        if (find_it != symbol_map.end()) {
            find_it->second->value = (uint32_t)value;
        }
    }
    
    // Make sure every symbol was found
    if (overlay_table_sym.value == symbol_not_found) {
        exit_failure("Failed to find overlay table symbol (overlay_table_ROM_START)\n");
    }

    for (const auto& [name, symbol] : symbol_map) {
        if (symbol->value == symbol_not_found) {
            exit_failure("Failed to find symbol for " + name + "\n");
        }
    }

    // Make sure every overlay's section and reloc section were found
    for (const auto& ovl : overlays) {
        if (!ovl.name.empty()) {
            if (ovl.section == nullptr) {
                exit_failure("Failed to find section for overlay " + ovl.name + "\n");
            }
            if (ovl.bss_section == nullptr) {
                exit_failure("Failed to find bss section for overlay " + ovl.name + "\n");
            }

            // Make sure the overlay's section sizes are valid
            auto check_section_size = [&] (const Symbol& s) {
                if (s.value > 0xFFFF) {
                    exit_failure(s.name + " is too large\n");
                }
                if (((s.value / section_size_divisor) * section_size_divisor) != s.value) {
                    exit_failure(s.name + " is not divisible by " + std::to_string(section_size_divisor) + "\n");
                }
            };

            check_section_size(ovl.text_size);
            check_section_size(ovl.rodata_size);
            check_section_size(ovl.data_size);
            check_section_size(ovl.bss_size);
        }
    }

    std::string output_path = std::string{argv[2]} + "/";
    std::filesystem::create_directories(output_path);

    
    std::ofstream overlay_table{output_path + "overlay_table.s"};
    fmt::print(overlay_table, 
        ".data\n"
        "    .word overlay_table_ROM_END - 0x{:08X}\n", overlay_table_sym.value);

    std::vector<uint16_t> reloc_values;
    reloc_values.reserve(128); 
    const char* prev_overlay_name = "overlay_table";
    for (const auto& ovl : overlays) {
        if (!ovl.name.empty()) {
            std::filesystem::create_directories(output_path + "overlays/" + ovl.name);
            std::ofstream header{output_path + "overlays/" + ovl.name + "/" + ovl.name + "_header.s"};
            // fmt::print("{} (section {},bss section {})\n", ovl.name, ovl.section->get_index(), ovl.bss_section->get_index());
            prev_overlay_name = ovl.name.c_str();
            // const char* ovl_data = ovl.section->get_data();
            
            fmt::print(overlay_table,
                "    .word {}_ROM_END - 0x{:08X}\n", ovl.name, overlay_table_sym.value);

            reloc_values.clear();
            // Skip gathering relocs if this overlay doesn't have a reloc section
            if (ovl.reloc_section != nullptr) {
                ELFIO::relocation_section_accessor relocs{elf_file, ovl.reloc_section};

                // Find all relocs in this overlay that point back to this overlay
                size_t num_relocs = relocs.get_entries_num();
                for (size_t reloc_index = 0; reloc_index < num_relocs; reloc_index++) {
                    ELFIO::Elf64_Addr offset = 0;
                    ELFIO::Elf_Word symbol = 0;
                    unsigned int type = (int)RelocType::R_MIPS_NONE;
                    ELFIO::Elf_Sxword addend;
                    relocs.get_entry(reloc_index, offset, symbol, type, addend);

                    std::string sym_name;
                    ELFIO::Elf64_Addr sym_value = symbol_not_found;
                    ELFIO::Elf_Xword sym_size;
                    unsigned char sym_bind;
                    unsigned char sym_type;
                    ELFIO::Elf_Half sym_section_index;
                    unsigned char sym_other;

                    symbols.get_symbol(symbol, sym_name, sym_value, sym_size, sym_bind, sym_type, sym_section_index, sym_other);
                    // fmt::print("  Reloc at 0x{:04X} type {} for {} in {}\n", (uint16_t)offset, type, sym_name, sym_section_index);
                    if (sym_section_index == ovl.section->get_index() || sym_section_index == ovl.bss_section->get_index()) {
                        uint16_t reloc_value = (uint16_t)offset;

                        auto reloc_it = reloc_mapping.find(static_cast<RelocType>(type));
                        if (reloc_it == reloc_mapping.end()) {
                            exit_failure("Invalid reloc type at reloc " + std::to_string(reloc_index) + " in overlay " + ovl.name + ": " + std::to_string(type) + "\n");
                        }

                        reloc_value |= (uint16_t)reloc_it->second;

                        reloc_values.push_back(reloc_value);
                    }
                    else {
                        // fmt::print("    Skipped\n");
                    }
                }
            }
            sort_relocs(reloc_values, "assets/overlays/" + ovl.name + "/relocs.bin");

            fmt::print(header, 
                ".data\n"
                "  /* Text Size */\n"
                "  .half 0x{:04X}\n"
                "  /* Rodata Size */\n"
                "  .half 0x{:04X}\n"
                "  /* Data Size */\n"
                "  .half 0x{:04X}\n"
                "  /* Bss Size */\n"
                "  .half 0x{:04X}\n",
                ovl.text_size.value / section_size_divisor,
                ovl.rodata_size.value / section_size_divisor,
                ovl.data_size.value / section_size_divisor,
                ovl.bss_size.value / section_size_divisor);

            fmt::print(header,
                "  /* Entrypoint count */\n"
                "  .half 0x{:04X}\n"
                "  /* Reloc Count */\n"
                "  .half 0x{:04X}\n",
                ovl.entrypoints.size(),
                reloc_values.size());
            
            fmt::print(header, 
                "  /* Unk */\n"
                "  .byte 0x00\n"
                "  .byte 0x00\n"
                "  /* Overlay name length */\n"
                "  .byte 0x{:02X}\n"
                "  /* Unk */\n"
                "  .byte 0x02\n",
                    ovl.name.size() + 1);
            
            fmt::print(header,
                "  /* Unknown */\n"
                "  .zero 0x28\n");
            
            fmt::print(header,
                "  /* Entrypoints */\n");
            
            for (const auto& entrypoint : ovl.entrypoints) {
                fmt::print(header, "  .word 0x{:08X}\n", entrypoint.value & ~overlay_vram);
            }

            fmt::print(header,
                "  /* Name */\n"
                "  .asciiz \"{}\"\n"
                "  .balign 0x4\n",
                ovl.name);
            
            fmt::print(header,
                "  /* Relocs */\n");
            
            for (uint16_t reloc_value : reloc_values) {
                fmt::print(header, "  .half 0x{:04X}\n", reloc_value);
            }
        }
        else {
            fmt::print(overlay_table,
                "    .word {}_ROM_END - 0x{:08X}\n", prev_overlay_name, overlay_table_sym.value);
        }
    }
}
