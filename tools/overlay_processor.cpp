#include <vector>
#include <string>
#include <filesystem>
#include <unordered_set>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <fstream>
#include "tooie_utils.h"

constexpr uint32_t section_size_divisor = 0x10;

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

    auto exit_failure = [] (const std::string& error_str) {
        fmt::vprint(stderr, error_str, fmt::make_format_args());
        std::exit(EXIT_FAILURE);
    };

    const char* elf_path = argv[1];

    ElfHandler elf_file{elf_path};

    std::vector<Segment> overlays = read_config("overlays.us.toml");

    std::unordered_map<std::string, Segment*> segment_map{};
    std::unordered_map<std::string, Symbol*> symbol_map{};

    auto add_symbol_to_map = [&] (Symbol& sym) {
        symbol_map[sym.name] = &sym;
    };
    auto add_segment_to_maps = [&] (Segment& seg) {
        // Add the segment itself to the segment map
        segment_map[seg.name] = &seg;
        // Add the segment's section sizes to the symbol map
        add_symbol_to_map(seg.text_size);
        add_symbol_to_map(seg.rodata_size);
        add_symbol_to_map(seg.data_size);
        add_symbol_to_map(seg.bss_size);
        add_symbol_to_map(seg.rom_start);
        add_symbol_to_map(seg.rom_end);
        // Add the segment's entrypoints to the symbol map
        for (auto& entrypoint : seg.entrypoints) {
            add_symbol_to_map(entrypoint);
        }
    };

    // Gather all the symbols that we need to find in the elf
    Symbol overlay_table_sym{"overlay_table_ROM_START"};
    symbol_map[overlay_table_sym.name] = &overlay_table_sym;

    for (auto& ovl : overlays) {
        if (!ovl.name.empty()) {
            add_segment_to_maps(ovl);
        }
    }

    // Read all the segments in the elf to find the overlays
    elf_file.find_segments_in_elf(segment_map);

    // Read all the symbols in the elf
    elf_file.find_symbol_in_elf(symbol_map);
    
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
            prev_overlay_name = ovl.name.c_str();
            
            fmt::print(overlay_table,
                "    .word {}_ROM_END - 0x{:08X}\n", ovl.name, overlay_table_sym.value);

            // Get the relocs for this overlay and sort them based on their original order
            reloc_values.clear();
            elf_file.get_tooie_relocs(ovl, reloc_values);
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
