#include <fstream>
#include <filesystem>
#include <fmt/core.h>
#include <librarezip.h>
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

void compress_and_write(std::ofstream& output_file, char* begin, char* end)
{
    // Make a buffer to hold the compressed data
    std::vector<char> compression_buffer;
    compression_buffer.resize(end - begin + 0x800);

    // Compress into the buffer
    size_t compressed_size = bt_zip(reinterpret_cast<uint8_t*>(begin), end - begin, reinterpret_cast<uint8_t*>(compression_buffer.data()), compression_buffer.size());

    // Write the buffer to the file
    output_file.write(compression_buffer.data(), compressed_size);

    // Pad to the nearest multiple of 2 bytes
    align_file_pos(output_file, 2);
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
    
    // Add core1 and core2 to the segment map
    Segment core1{"core1"};
    Segment core2{"core2"};
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
    size_t core1_compressed_text_end = compressed_rom.tellp();
    compress_and_write(compressed_rom, core1_text_end, core1_end);
    size_t core1_compressed_end = compressed_rom.tellp();

    // Compress core2 and write it to the rom
    size_t core2_compressed_start = compressed_rom.tellp();
    char* core2_start = decompressed_rom_contents.data() + core2.rom_start.value;
    char* core2_text_end = core2_start + core2.text_size.value;
    char* core2_end = core2_text_end + core2.rodata_size.value + core2.data_size.value;
    compress_and_write(compressed_rom, core2_start, core2_text_end);
    size_t core2_compressed_text_end = compressed_rom.tellp();
    compress_and_write(compressed_rom, core2_text_end, core2_end);
    size_t core2_compressed_end = compressed_rom.tellp();

    align_file_pos(compressed_rom, 16);
    
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

    // TODO patch relocs to core1/core2 compressed start/end
    // TODO patch overlay table address
    (void)core1_compressed_start;
    (void)core1_compressed_text_end;
    (void)core1_compressed_end;
    (void)core2_compressed_start;
    (void)core2_compressed_text_end;
    (void)core2_compressed_end;

    return EXIT_SUCCESS;
}
