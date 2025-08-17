#include "toml.hpp"
#include "fmt/core.h"
#include "tooie_utils.h"
#include "elfio/elfio.hpp"

const std::unordered_map<RelocType, TooieRelocType> reloc_mapping {
    { RelocType::R_MIPS_32, TooieRelocType::R_MIPS_32 },
    { RelocType::R_MIPS_26, TooieRelocType::R_MIPS_26 },
    { RelocType::R_MIPS_HI16, TooieRelocType::R_MIPS_HI16 },
    { RelocType::R_MIPS_LO16, TooieRelocType::R_MIPS_LO16 },
};

ELFIO::elfio load_elf_from_path(const char* elf_path) {
    ELFIO::elfio elf_file_;
    if (!elf_file_.load(elf_path)) {
        fmt::print(stderr, "Failed to load provided elf file\n");
        std::exit(EXIT_FAILURE);
    }

    if (elf_file_.get_class() != ELFIO::ELFCLASS32) {
        fmt::print(stderr, "Incorrect elf class\n");
        std::exit(EXIT_FAILURE);
    }

    if (elf_file_.get_encoding() != ELFIO::ELFDATA2MSB) {
        fmt::print(stderr, "Incorrect endianness\n");
        std::exit(EXIT_FAILURE);
    }
    return elf_file_;
}

ELFIO::section* get_symtab(ELFIO::elfio& elf_file_) {
    ELFIO::section* symtab_section_ = nullptr;
    for (const auto& section : elf_file_.sections) {
        std::string section_name = section->get_name();
        ELFIO::Elf_Word type = section->get_type();

        // Check if this section is the symbol table
        if (type == ELFIO::SHT_SYMTAB) {
            symtab_section_ = section.get();
        }
    }

    if (symtab_section_ == nullptr) {
        fmt::print(stderr, "Failed to find symbol table section\n");
        std::exit(EXIT_FAILURE);
    }

    return symtab_section_;
}

struct ElfHandler::ElfContext {
    ELFIO::elfio elf_file;
    ELFIO::section* symtab_section;
    ELFIO::symbol_section_accessor symbol_accessor;
    ElfContext(const char* elf_path) :
        elf_file{load_elf_from_path(elf_path)},
        symtab_section{get_symtab(elf_file)},
        symbol_accessor{elf_file, symtab_section}
    {}
};

ElfHandler::ElfHandler(const char* elf_path) :
    elf_context_{std::make_unique<ElfContext>(elf_path)} {}

ElfHandler::~ElfHandler() = default;

std::vector<Segment> read_config(const char* path) {
    toml::array empty_array{};
    std::string empty_string{};
    try {
		const toml::value config_data = toml::parse(path);
		const toml::array& overlay_array = toml::find_or<toml::array>(config_data, "overlay", empty_array);

        std::vector<Segment> overlays{};
        overlays.reserve(overlay_array.size());

        for (const auto& overlay_data : overlay_array) {
            bool is_empty = toml::find_or<bool>(overlay_data, "empty", false);
            if (!is_empty) {
                const std::string& entrypoint_name = toml::find_or<std::string>(overlay_data, "name", empty_string);
                const toml::array& entrypoint_array = toml::find_or<toml::array>(overlay_data, "entrypoints", empty_array);
                std::vector<Symbol> entrypoints{};
                entrypoints.resize(entrypoint_array.size());
                for (size_t i = 0; i < entrypoint_array.size(); i++) {
                    entrypoints[i].name = entrypoint_array[i].as_string();
                    entrypoints[i].value = symbol_not_found;
                }
                overlays.emplace_back(entrypoint_name, std::move(entrypoints));
            }
            else {
                overlays.emplace_back("");
            }
        }
        return overlays;
    }
	catch (const toml::syntax_error& err) {
		fmt::print(stderr, "Syntax error in config file on line {}, full error:\n{}\n", err.errors().front().locations().front().first.first_line_number(), err.errors().front().title());
        std::exit(EXIT_FAILURE);
	}
	catch (const toml::type_error& err) {
		fmt::print(stderr, "Incorrect type in config file on line {}, full error:\n{}\n", err.location().first_line_number(), err.what());
        std::exit(EXIT_FAILURE);
	}
	catch (const std::out_of_range& err) {
		fmt::print(stderr, "Missing value in config file, full error:\n{}\n", err.what());
        std::exit(EXIT_FAILURE);
	}
    return {};
}

void ElfHandler::find_segments_in_elf(std::unordered_map<std::string, Segment*>& segment_map) {
    // Find all overlay sections and their reloc sections 
    for (const auto& section : elf_context_->elf_file.sections) {
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

        // Check if this section has a corresponding segment
        if (!section_name.empty()) {
            // Strip the dot off the start of the section name
            auto find_it = segment_map.find(section_name.substr(1));
            if (find_it != segment_map.end()) {
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
    }
}

void ElfHandler::find_symbol_in_elf(std::unordered_map<std::string, Symbol*>& symbol_map) {
    for (size_t sym_index = 0; sym_index < elf_context_->symbol_accessor.get_symbols_num(); sym_index++) {
        std::string   name;
        ELFIO::Elf64_Addr    value = symbol_not_found;
        ELFIO::Elf_Xword     size;
        unsigned char bind;
        unsigned char type;
        ELFIO::Elf_Half      section_index;
        unsigned char other;
        elf_context_->symbol_accessor.get_symbol(sym_index, name, value, size, bind, type, section_index, other);

        auto find_it = symbol_map.find(name);
        if (find_it != symbol_map.end()) {
            find_it->second->value = (uint32_t)value;
        }
    }
}

void ElfHandler::get_all_relocs_in_segment(const Segment& segment, std::vector<Reloc>& relocs_out) {
    // Skip gathering relocs if this overlay doesn't have a reloc section
    if (segment.reloc_section != nullptr) {
        ELFIO::relocation_section_accessor relocs{elf_context_->elf_file, segment.reloc_section};

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
            elf_context_->symbol_accessor.get_symbol(symbol, sym_name, sym_value, sym_size, sym_bind, sym_type, sym_section_index, sym_other);

            // fmt::print("  Reloc at 0x{:04X} type {} for {} in {}\n", (uint16_t)offset, type, sym_name, sym_section_index);
            relocs_out.emplace_back(offset, static_cast<RelocType>(type), std::move(sym_name));
        }
    }
}

void ElfHandler::get_tooie_relocs(const Segment& segment, std::vector<uint16_t>& relocs_out) {
    // Skip gathering relocs if this overlay doesn't have a reloc section
    if (segment.reloc_section != nullptr) {
        ELFIO::relocation_section_accessor relocs{elf_context_->elf_file, segment.reloc_section};

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

            elf_context_->symbol_accessor.get_symbol(symbol, sym_name, sym_value, sym_size, sym_bind, sym_type, sym_section_index, sym_other);
            // fmt::print("  Reloc at 0x{:04X} type {} for {} in {}\n", (uint16_t)offset, type, sym_name, sym_section_index);
            if (sym_section_index == segment.section->get_index() || (segment.bss_section && sym_section_index == segment.bss_section->get_index())) {
                uint16_t reloc_value = (uint16_t)offset;

                auto reloc_it = reloc_mapping.find(static_cast<RelocType>(type));
                if (reloc_it == reloc_mapping.end()) {
                    fmt::print(stderr, "Invalid reloc type at reloc {} in {}: {}\n", reloc_index, segment.name, type);
                    std::exit(EXIT_FAILURE);
                }

                reloc_value |= (uint16_t)reloc_it->second;

                relocs_out.push_back(reloc_value);
            }
            else {
                // fmt::print("    Skipped\n");
            }
        }
    }
}

char* get_overlay_reloc_ptr(char* overlay_header, char* overlay_contents, uint16_t* num_entrypoints_out, uint16_t* num_relocs_out) {
    // Start by reading the entrypoint and reloc counts from the overlay header
    uint16_t num_entrypoints = byteswap16(*reinterpret_cast<uint16_t*>(overlay_header + ovl_header_offsets::entrypoint_count));
    uint16_t num_relocs = byteswap16(*reinterpret_cast<uint16_t*>(overlay_header + ovl_header_offsets::reloc_count));

    // Offset the overlay contents by 0x28 to get to the entrypoints
    char* ovl_entrypoints = overlay_contents + 0x28;
    // Offset the entrypoints by [entrypoint count] 32-bit values
    char* ovl_name = ovl_entrypoints + sizeof(uint32_t) * num_entrypoints;
    // Read the length of the overlay name
    uint8_t name_length = (uint8_t)*(overlay_header + ovl_header_offsets::name_length);
    // Round the overlay name up to the nearest 4 bytes and offset from the name start to get to the relocs
    char* ovl_relocs = ovl_name + ((name_length + 4 - 1) & -4);

    *num_entrypoints_out = num_entrypoints;
    *num_relocs_out = num_relocs;
    return ovl_relocs;
}

void bk_crc(const char* bytes, uint32_t size, uint32_t& crc1, uint32_t& crc2, uint32_t start_crc1, uint32_t start_crc2) {
    crc1 = start_crc1;
    crc2 = start_crc2;
    for (size_t i = 0; i < size; i++) {
        uint32_t byte = (uint32_t)(uint8_t)bytes[i];
        
        crc1 += byte;
        crc2 ^= byte << (crc1 & 0x17);
    }
}
