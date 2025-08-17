#include <fstream>
#include <filesystem>

#include "fmt/core.h"
#include "librarezip.h"

#include "tooie_utils.h"

// Reads a binary file and returns a vector containing its contents
std::vector<char> read_file(const char* path) {
    std::vector<char> ret;
    std::ifstream input_file{path, std::ios_base::binary};

    // Check if the file was opened successfully
    if (!input_file.good()) {
        fmt::print(stderr, "Failed to open file {}\n", path);
        std::exit(EXIT_FAILURE);
    }

    // Get the file's size
    input_file.seekg(0, std::ios_base::end);
    size_t file_size = input_file.tellg();
    input_file.seekg(0, std::ios_base::beg);

    // Make room for the file's contents and read it
    ret.resize(file_size);
    input_file.read(ret.data(), file_size);

    return ret;
}

void align_file_pos(std::ofstream& output_file, size_t alignment) {
    size_t file_size = output_file.tellp();
    size_t remainder = file_size % alignment;
    static const char zeroes[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    if (remainder != 0) {
        output_file.write(zeroes, alignment - remainder);
    }
}

void compress_and_write(std::ofstream& output_file, char* begin, char* end, bool dump = false)
{
    (void)dump;
    // Make a buffer to hold the compressed data
    std::vector<char> compression_buffer;
    compression_buffer.resize(end - begin + 0x800);

    // Compress into the buffer
    size_t compressed_size = bt_zip(reinterpret_cast<uint8_t*>(begin), end - begin, reinterpret_cast<uint8_t*>(compression_buffer.data()), compression_buffer.size());

    // Write the buffer to the file
    output_file.write(compression_buffer.data(), compressed_size);
}

void apply_xors(size_t overlay_index, char* rom_start, char* overlay_header, char* overlay_start, size_t decompressed_size) {
    // Get the pointer to the relocs and the number of relocs
    uint16_t num_relocs;
    uint16_t num_entrypoints;
    char* ovl_relocs = get_overlay_reloc_ptr(overlay_header, overlay_header + 0x10, &num_entrypoints, &num_relocs);

    // Read the data from the start of the rom used to xor the relocs
    uint32_t rom_xor = byteswap32(*reinterpret_cast<uint32_t*>(rom_start + 0x40 + overlay_index * sizeof(uint32_t))) & 0xFFFF;
    uint32_t rom_xor_swapped = byteswap16(rom_xor);

    // Remove the reloc vram offsets and apply the xors
    for (uint16_t reloc_index = 0; reloc_index < num_relocs; reloc_index++) {
        uint16_t* reloc_ptr = reinterpret_cast<uint16_t*>(ovl_relocs + reloc_index * sizeof(uint16_t));
        uint16_t reloc = byteswap16(*reloc_ptr);
        *reloc_ptr ^= rom_xor_swapped;
        // Find the word that the reloc points to and remove the base vram offset
        uint32_t reloc_offset = reloc & ~3;
        uint32_t* reloc_word_ptr = reinterpret_cast<uint32_t*>(overlay_start + reloc_offset);
        uint32_t reloc_word = byteswap32(*reloc_word_ptr);
        // Undo the reloc base vram address addend applied by the decompressor
        switch ((TooieRelocType)(reloc & 3)) {
            case TooieRelocType::R_MIPS_26:
                reloc_word &= ~((overlay_vram & ((1 << 26) - 1)) >> 2);
                break;
            case TooieRelocType::R_MIPS_HI16:
                reloc_word &= ~(overlay_vram >> 16);
                break;
            case TooieRelocType::R_MIPS_32:
                reloc_word &= ~overlay_vram;
                break;
            default:
                break;
        }
        *reloc_word_ptr = byteswap32(reloc_word);
    }
    
    // Calculate the CRCs of the decompressed overlay data
    uint32_t crc1, crc2;
    bk_crc(overlay_header + 0x10, decompressed_size - 0x10, crc1, crc2);

    // Apply the CRC xor in the overlay
    *reinterpret_cast<uint32_t*>(overlay_header + 0) ^= byteswap32(crc1);
    *reinterpret_cast<uint32_t*>(overlay_header + 8) ^= byteswap32(crc2);
}

const char* get_symbol_rom_pointer(const std::vector<char>& decompressed_rom_contents, const Segment& core1, const Segment& core2, uint32_t vram_address) {
    // In core2 bss or after core2, no rom address
    if (vram_address >= core2.ram_end.value - core2.bss_size.value) {
        return nullptr;
    }
    // In core2
    else if (vram_address >= core2.ram_start.value) {
        return decompressed_rom_contents.data() + vram_address - core2.ram_start.value + core2.rom_start.value;
    }
    // In core1 bss, no rom address
    else if (vram_address >= core1.ram_end.value - core1.bss_size.value) {
        return nullptr;
    }
    // In core1
    else if (vram_address >= core1.ram_start.value) {
        return decompressed_rom_contents.data() + vram_address - core1.ram_start.value + core1.rom_start.value;
    }
    // Before core1, no rom address
    else {
        return nullptr;
    }
}

// Array in build_data that contains the CRCs and the number of bytes to checksum
struct CrcValues {
    uint32_t crc1;
    uint32_t crc2;
    uint32_t byte_count;
};

// Array in core1 detailing what symbols to calculate the CRC of
struct CrcEntry {
    uint32_t address;
    uint8_t rom_word_offset; // Offset from the start of build_data
    uint8_t in_rom;
};

constexpr size_t num_crc_entries = 8;

void patch_crc_values(std::ofstream& compressed_rom, const std::vector<char>& decompressed_rom_contents, const Segment& core1, const Segment& core2, uint32_t build_data_rom_address, uint32_t crc_entries_vram_address) {
    const char* crc_entries = get_symbol_rom_pointer(decompressed_rom_contents, core1, core2, crc_entries_vram_address);

    if (crc_entries == nullptr) {
        fmt::print(stderr, "Could not find ROM address of symbol crc_entries\n");
        std::exit(EXIT_FAILURE);
    }

    for (size_t entry_index = 0; entry_index < num_crc_entries; entry_index++) {
        const CrcEntry* entry = reinterpret_cast<const CrcEntry*>(crc_entries) + entry_index;
        uint32_t word_offset = entry->rom_word_offset;
        uint32_t byte_offset = word_offset * sizeof(uint32_t);
        uint32_t cur_values_rom_address = build_data_rom_address + byte_offset;
        const CrcValues* values_in = reinterpret_cast<const CrcValues*>(decompressed_rom_contents.data() + cur_values_rom_address);
        uint32_t crc_symbol_vram = byteswap32(entry->address);
        uint32_t byte_count = byteswap32(values_in->byte_count);
        const char* crc_symbol = get_symbol_rom_pointer(decompressed_rom_contents, core1, core2, crc_symbol_vram);
        uint32_t crc1, crc2;

        if (crc_symbol == nullptr) {
            fmt::print(stderr, "Could not find ROM address of symbol at VRAM 0x{:08X}\n", crc_symbol_vram);
            std::exit(EXIT_FAILURE);
        }

        bk_crc(crc_symbol, byte_count, crc1, crc2);

        // Byteswap the CRC values before writing them
        crc1 = byteswap32(crc1);
        crc2 = byteswap32(crc2);
        compressed_rom.seekp(cur_values_rom_address, std::ios_base::beg);
        compressed_rom.write(reinterpret_cast<const char*>(&crc1), sizeof(crc1));
        compressed_rom.write(reinterpret_cast<const char*>(&crc2), sizeof(crc2));
    }
}

int main(int argc, const char** argv) {
    if (argc != 6) {
        fmt::print(stderr,
            "Compresses a decompressed Banjo Tooie ROM, using the elf file to find sections and adjust certain symbols.\n"
            "Usage: {} [decompressed ROM] [elf file] [output compressed ROM path] [base ROM path] [decompressed base ROM path]\n", argv[0]);
        return EXIT_SUCCESS;
    }

    auto exit_failure = [] (const std::string& error_str) {
        fmt::vprint(stderr, error_str, fmt::make_format_args());
        std::exit(EXIT_FAILURE);
    };

    const char* decompressed_rom_path = argv[1];
    const char* elf_path = argv[2];
    const char* compressed_rom_path = argv[3];
    const char* baserom_path = argv[4];
    const char* decompressed_baserom_path = argv[5];

    // Read the input roms
    std::vector<char> decompressed_rom_contents = read_file(decompressed_rom_path);
    std::vector<char> baserom_contents = read_file(baserom_path);
    std::vector<char> decompressed_baserom_contents = read_file(decompressed_baserom_path);
    // Create the output rom file
    std::ofstream compressed_rom{compressed_rom_path, std::ios_base::binary};
    if (!compressed_rom.good()) {
        exit_failure(std::string{"Failed to open "} + compressed_rom_path + " for writing\n");
    }
    // Open the elf file
    ElfHandler elf_file(elf_path);

    std::vector<Segment> overlays = read_config("overlays.us.toml");
    std::vector<Symbol> overlay_header_symbols;
    overlay_header_symbols.resize(overlays.size());

    std::unordered_map<std::string, Segment*> segment_map{};
    std::unordered_map<std::string, Symbol*> symbol_map{};

    auto add_symbol_to_map = [&] (Symbol& sym) {
        symbol_map[sym.name] = &sym;
    };
    auto add_segment_to_maps = [&] (Segment& seg) {
        // Add the segment itself to the segment map
        segment_map[seg.name] = &seg;
        // Add the segment's section sizes to the symbol map
        add_symbol_to_map(seg.ram_start);
        add_symbol_to_map(seg.ram_end);
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

    for (size_t ovl_index = 0; ovl_index < overlay_header_symbols.size(); ovl_index++) {
        if (!overlays[ovl_index].name.empty()) {
            overlay_header_symbols[ovl_index].name = overlays[ovl_index].name + "_header_ROM_START";
            add_symbol_to_map(overlay_header_symbols[ovl_index]);
        }
    }
    
    // Add boot, core1, and core2 to the segment map
    Segment boot{"boot"};
    Segment core1{"core1"};
    Segment core2{"core2"};
    add_segment_to_maps(boot);
    add_segment_to_maps(core1);
    add_segment_to_maps(core2);

    // Add overlay info to the segment and symbol maps
    for (auto& ovl : overlays) {
        if (!ovl.name.empty()) {
            add_segment_to_maps(ovl);
        }
    }

    // Add symbols for patching after compression
    Symbol table_addr_sym{"table_addr_ROM_START"};
    add_symbol_to_map(table_addr_sym);
    Symbol build_data_rom_sym{"build_data_ROM_START"};
    add_symbol_to_map(build_data_rom_sym);
    Symbol crc_entries_sym{"crc_entries"};
    add_symbol_to_map(crc_entries_sym);

    // Search the elf for sections and symbols
    elf_file.find_segments_in_elf(segment_map);
    elf_file.find_symbol_in_elf(symbol_map);

    for (const auto& [name, symbol] : symbol_map) {
        if (symbol->value == symbol_not_found) {
            exit_failure("Failed to find symbol for " + name + "\n");
        }
    }

    // Copy everything up to core1 from the decompressed rom to the compressed one
    compressed_rom.write(decompressed_rom_contents.data(), core1.rom_start.value);

    // Compress core1 and write it to the rom
    size_t core1_compressed_start = compressed_rom.tellp();
    // fmt::print("core1_compressed_start: 0x{:08X}\n", core1_compressed_start);
    char* core1_start = decompressed_rom_contents.data() + core1.rom_start.value;
    char* core1_text_end = core1_start + core1.text_size.value;
    char* core1_end = core1_text_end + core1.rodata_size.value + core1.data_size.value;
    compress_and_write(compressed_rom, core1_start, core1_text_end);
    // size_t core1_compressed_text_end = compressed_rom.tellp();
    compress_and_write(compressed_rom, core1_text_end, core1_end);
    align_file_pos(compressed_rom, 2);
    size_t core1_compressed_end = compressed_rom.tellp();

    // Compress core2 and write it to the rom
    size_t core2_compressed_start = compressed_rom.tellp();
    char* core2_start = decompressed_rom_contents.data() + core2.rom_start.value;
    char* core2_text_end = core2_start + core2.text_size.value;
    char* core2_end = core2_text_end + core2.rodata_size.value + core2.data_size.value;
    compress_and_write(compressed_rom, core2_start, core2_text_end);
    // size_t core2_compressed_text_end = compressed_rom.tellp();
    compress_and_write(compressed_rom, core2_text_end, core2_end, true);
    align_file_pos(compressed_rom, 16);
    size_t core2_compressed_end = compressed_rom.tellp();

    
    // Skip the overlay table since it'll be filled in after the overlays are placed
    size_t overlay_count = overlays.size();
    size_t overlay_table_address = compressed_rom.tellp();
    compressed_rom.seekp((overlay_count + 1) * sizeof(uint32_t), std::ios_base::cur);

    // Create a buffer to hold the position of each overlay
    std::vector<size_t> overlay_ends;
    overlay_ends.resize(overlay_count);

    for (size_t i = 0; i < overlay_count; i++) {
        const auto& overlay = overlays[i];

        // Skip empty overlays
        if (!overlays[i].name.empty()) {
            size_t ovl_header_start_address = overlay_header_symbols[i].value;
            char* ovl_header_start = decompressed_rom_contents.data() + ovl_header_start_address;
            char* ovl_start = decompressed_rom_contents.data() + overlay.rom_start.value;
            char* ovl_end = decompressed_rom_contents.data() + overlay.rom_end.value;
            size_t ovl_size = ovl_end - ovl_header_start;

            char* base_ovl_header_start = decompressed_baserom_contents.data() + ovl_header_start_address;

            // Because of difficulties with matching compression for some overlays, compare the built overlay to
            // the decompressed base ROM contents at the same location. If the overlay is not shift and its contents
            // match that of the decompressed base ROM, copy the original compressed overlay as-is.
            if (decompressed_baserom_contents.size() >= ovl_header_start_address + ovl_size && memcmp(base_ovl_header_start, ovl_header_start, ovl_size) == 0) {
                uint32_t compressed_overlay_start = byteswap32(*reinterpret_cast<uint32_t*>(baserom_contents.data() + us_v10.overlay_table_offset + (i) * sizeof(uint32_t)));
                uint32_t compressed_overlay_end = byteswap32(*reinterpret_cast<uint32_t*>(baserom_contents.data() + us_v10.overlay_table_offset + (i + 1) * sizeof(uint32_t)));
                compressed_rom.write(baserom_contents.data() + us_v10.overlay_table_offset + compressed_overlay_start, compressed_overlay_end - compressed_overlay_start);
            }
            // Otherwise, compress the overlay as normal.
            else {
                // Set the compressed flag(?)
                *reinterpret_cast<uint32_t*>(ovl_header_start + ovl_header_offsets::flags) |= byteswap32(0x80);

                // Apply the xors to the overlay
                apply_xors(i + 1, decompressed_rom_contents.data(), ovl_header_start, ovl_start, ovl_end - ovl_header_start);

                // Write the header
                compressed_rom.write(ovl_header_start, 0x10);

                // Compress the rest of the overlay and write it
                compress_and_write(compressed_rom, ovl_header_start + 0x10, ovl_end);
            }

            align_file_pos(compressed_rom, 4);
        }
        
        overlay_ends[i] = compressed_rom.tellp();
    }
    align_file_pos(compressed_rom, 16);

    // Go back and fill in the overlay table
    compressed_rom.seekp(overlay_table_address);
    uint32_t overlay_table_size_swapped = byteswap32((overlay_count + 1) * sizeof(uint32_t));
    compressed_rom.write(reinterpret_cast<const char*>(&overlay_table_size_swapped), sizeof(overlay_table_size_swapped));
    for (size_t overlay_end : overlay_ends) {
        uint32_t overlay_end_swapped = byteswap32((uint32_t)(overlay_end - overlay_table_address));
        compressed_rom.write(reinterpret_cast<const char*>(&overlay_end_swapped), sizeof(overlay_end_swapped));
    }

    std::vector<Reloc> boot_relocs;
    elf_file.get_all_relocs_in_segment(boot, boot_relocs);

    struct SymbolAddressPair {
        size_t old_value;
        size_t new_value;
    };
    // Holds a mapping of symbol name to a pair containing the original symbol value and the new one
    std::unordered_map<std::string, SymbolAddressPair> symbol_patch_mapping {
        {"core1_compressed_ROM_START", {.old_value = 0x1E29B60, .new_value = core1_compressed_start}},
        {"core1_compressed_ROM_END",   {.old_value = 0x1E42550, .new_value = core1_compressed_end}},
        {"core2_compressed_ROM_START", {.old_value = 0x1E42550, .new_value = core2_compressed_start}},
        {"core2_compressed_ROM_END",   {.old_value = 0x1E899B0, .new_value = core2_compressed_end}},
    };

    // fmt::print("{} relocs in boot\n", boot_relocs.size());

    // Patch relocs that reference any of the compressed segment ROM address symbols
    for (const Reloc& reloc : boot_relocs) {
        auto find_it = symbol_patch_mapping.find(reloc.symbol_name);
        if (find_it != symbol_patch_mapping.end()) {
            size_t patched_word_rom_address = reloc.segment_offset + boot.rom_start.value - boot.ram_start.value;
            // fmt::print("{} @ 0x{:08X}\n", reloc.symbol_name, patched_word_rom_address);
            uint32_t patched_word = byteswap32(*reinterpret_cast<uint32_t*>(decompressed_rom_contents.data() + patched_word_rom_address));
            // uint32_t original_word = patched_word;
            if (reloc.type == RelocType::R_MIPS_32) {
                // Subtract the original symbol value and add the new one to preserve any addends
                patched_word -= find_it->second.old_value;
                patched_word += find_it->second.new_value;
            }
            else if (reloc.type == RelocType::R_MIPS_HI16 || reloc.type == RelocType::R_MIPS_LO16) {
                uint16_t current_immediate = patched_word & 0xFFFF;
                uint16_t old_target_immediate;
                uint16_t new_target_immediate;
                int16_t old_lo = (int16_t)(find_it->second.old_value & 0xFFFF);
                int16_t new_lo = (int16_t)(find_it->second.new_value & 0xFFFF);
                if (reloc.type == RelocType::R_MIPS_HI16) {
                    old_target_immediate = (find_it->second.old_value - old_lo) >> 16;
                    new_target_immediate = (find_it->second.new_value - new_lo) >> 16;
                }
                else {
                    old_target_immediate = old_lo;
                    new_target_immediate = new_lo;
                }
                // Error if an addend is detected since HI/LO pairing isn't implemented here
                if (old_target_immediate != current_immediate) {
                    fmt::print(stderr,
                        "Detected addend for reloc of type {} for patched symbol {} at ROM 0x{:08X}\n"
                        "Addends for HI16/LO16 relocs of patched symbols are currently unsupported",
                            (int)reloc.type, reloc.symbol_name, patched_word_rom_address);
                    return EXIT_FAILURE;
                }
                patched_word = (patched_word & 0xFFFF0000) | new_target_immediate;
            }
            else {
                fmt::print(stderr, "Unhandled reloc type {} for patched symbol {} at ROM 0x{:08X}\n", (int)reloc.type, reloc.symbol_name, patched_word_rom_address);
                return EXIT_FAILURE;
            }

            // fmt::print("Patched word from 0x{:08X} to 0x{:08X} at ROM 0x{:08X} for reloc to {}\n", original_word, patched_word, patched_word_rom_address, reloc.symbol_name);

            // Overwrite the patched word in the output ROM
            compressed_rom.seekp(patched_word_rom_address);
            uint32_t patched_word_swapped = byteswap32(patched_word);
            compressed_rom.write(reinterpret_cast<const char*>(&patched_word_swapped), sizeof(patched_word_swapped));
        }
    }

    // Patch overlay table address
    compressed_rom.seekp(table_addr_sym.value);
    uint32_t table_address_swapped = byteswap32(overlay_table_address);
    compressed_rom.write(reinterpret_cast<const char*>(&table_address_swapped), sizeof(table_address_swapped));

    patch_crc_values(compressed_rom, decompressed_rom_contents, core1, core2, build_data_rom_sym.value, crc_entries_sym.value);

    return EXIT_SUCCESS;
}
