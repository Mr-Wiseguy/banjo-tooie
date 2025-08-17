#include <fstream>
#include <filesystem>
#include <cstdint>
#include <vector>
#include <bit>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <string_view>

#include "fmt/ostream.h"
#include "fmt/core.h"
#define ZLIB_CONST
#include "zlib.h"

#include "tooie_utils.h"

constexpr bool generate_splat_files = false;
constexpr bool generate_overlay_toml = false;
constexpr bool generate_any_files = generate_splat_files | generate_overlay_toml;

enum class SymbolType {
    Function,
    Text,
    Rodata,
    Data,
    Bss,
    None
};

const char* reloc_names[] = {
    "MIPS_32",
    "MIPS_26",
    "MIPS_HI16",
    "MIPS_LO16"
};

enum class Section {
    Text,
    Rodata,
    Data,
    Bss
};

struct OverlaySymbol {
    std::string ovl_name;
    uint32_t address;

    std::strong_ordering operator<=>(const OverlaySymbol& rhs) const {
        return std::tie(ovl_name, address) <=> std::tie(rhs.ovl_name, rhs.address);
    }
    bool operator==(const OverlaySymbol&) const = default;
};

struct SymbolDetails {
    uint32_t rom_address;
    SymbolType type;
    std::string name;
};

struct OutputReloc {
    OverlaySymbol symbol;
    uint32_t rom_address;
    TooieRelocType type;
    Section section;
};

struct Overlay {
    std::string name;
    uint32_t rom_start;
    uint32_t code_rom_start;
    uint32_t text_size;
    uint32_t rodata_size;
    uint32_t data_size;
    uint32_t bss_size;
    uint32_t num_relocs;
    std::vector<std::string> entrypoints;
};

namespace std {
    template <>
    struct hash<OverlaySymbol> {
        size_t operator()(const OverlaySymbol& s) const {
            std::size_t h1 = std::hash<std::string>{}(s.ovl_name);
            std::size_t h2 = std::hash<uint32_t>{}(s.address);
            return h1 ^ h2;
        }
    };
};

std::string symbol_name(const OverlaySymbol& symbol, SymbolType type) {
    const char* type_name;
    switch (type) {
        case SymbolType::Function:
        case SymbolType::Text: // Treat all .text symbols as functions, rodata .text references will be ignored (for jtbls) 
            type_name = "func";
            break;
        case SymbolType::Rodata:
            type_name = "R";
            break;
        case SymbolType::Data:
            type_name = "D";
            break;
        case SymbolType::Bss:
            type_name = "B";
            break;
        default:
            type_name = "undefined";
            break;
    }
    return fmt::format("{}_{:08X}_{}", type_name, symbol.address, symbol.ovl_name);
}

class output_file_state {
private:
    std::ofstream symbol_addrs_file;
    std::ofstream reloc_addrs_file;
    std::ofstream yaml_file;
    std::ofstream overlay_toml_file;
    std::unordered_map<OverlaySymbol, SymbolDetails> symbols;
    std::vector<OutputReloc> relocs;
    std::vector<Overlay> overlays;
    std::vector<size_t> all_overlays; // Indexes into the overlays array, includes empty ones as size_t(-1)
    std::unordered_set<OverlaySymbol> rejected_symbols;
    size_t overlay_table_rom_start_;
public:
    output_file_state(size_t overlay_table_rom_start) : overlay_table_rom_start_(overlay_table_rom_start) {
        if constexpr (generate_splat_files) {
            symbol_addrs_file = std::ofstream{"ovl_symbol_addrs.us.txt"};
            reloc_addrs_file = std::ofstream{"ovl_reloc_addrs.us.txt"};
            yaml_file = std::ofstream{"ovl.us.yaml"};
            // TODO pull this from a file
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chterryegg", .address = 0x80801236});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "badeathmatch", .address = 0x8080054F});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chlagoonufoint", .address = 0x8080193E});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gemarkersDll", .address = 0xFFFFFDB8});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "bsfirstp", .address = 0x8080AC02});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chdiggerbossbattery", .address = 0x808002E8});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chtransparentfish", .address = 0x808011D0});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chfantasydrillfield", .address = 0x80800A50});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chfantasydrillfield", .address = 0x80800A58});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gczoombox", .address = 0x80803E80});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcintrotext", .address = 0x808005A0});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcfrontend", .address = 0x80800E30});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gclevel", .address = 0x808003B3});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gclevel", .address = 0x80800420});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcegg", .address = 0x80800270});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "glintrosyncDll", .address = 0x808005D0});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "inantab", .address = 0x80807780});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcfrontend", .address = 0x80800D81});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcfrontend", .address = 0x80800D8D});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcfrontend", .address = 0x80800D99});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gcfrontend", .address = 0x80800DA5});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chwarppad", .address = 0x80800E60});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "chwarppad", .address = 0x80800E5C});
            rejected_symbols.insert(OverlaySymbol{.ovl_name = "gczoombox", .address = 0x80803F3E});
        }
        if constexpr (generate_overlay_toml) {
            overlay_toml_file = std::ofstream("overlays.us.toml");
        }
    }

    void add_reloc(const char* ovl_name, uint32_t symbol_address, uint32_t rom_addr, TooieRelocType reloc_type, size_t reloc_offset, size_t text_size, size_t rodata_size, size_t data_size) {
        if constexpr (generate_any_files) {
            Section section = Section::Text;
            if (reloc_offset >= text_size + rodata_size + data_size) {
                section = Section::Bss;
            }
            else if (reloc_offset >= text_size + rodata_size) {
                section = Section::Data;
            }
            else if (reloc_offset >= text_size) {
                section = Section::Rodata;
            }
            relocs.emplace_back(OutputReloc{.symbol = OverlaySymbol{.ovl_name = ovl_name, .address = symbol_address}, .rom_address = rom_addr, .type = reloc_type, .section = section});
        }
    }

    void add_symbol(const char* ovl_name, uint32_t addr, uint32_t rom_addr) {
        if constexpr (generate_any_files) {
            OverlaySymbol sym{.ovl_name = ovl_name, .address = addr};
            if (!symbols.contains(sym)) {
                symbols[sym] = SymbolDetails{.rom_address = rom_addr, .type = SymbolType::None, .name = ""};
            }
        }
    }

    void set_symbol_type(const char* ovl_name, uint32_t addr, SymbolType type) {
        symbols[OverlaySymbol{.ovl_name = ovl_name, .address = addr}].type = type;
    }

    void set_symbol_name(const char* ovl_name, uint32_t addr, const std::string& sym_name) {
        symbols[OverlaySymbol{.ovl_name = ovl_name, .address = addr}].name = sym_name;
    }

    SymbolType get_symbol_type(const char* ovl_name, uint32_t addr) {
        return symbols[OverlaySymbol{.ovl_name = ovl_name, .address = addr}].type;
    }

    void add_bss_symbol(const char* ovl_name, uint32_t addr) {
        if constexpr (generate_any_files) {
            OverlaySymbol sym{.ovl_name = ovl_name, .address = addr};
            if (!symbols.contains(sym)) {
                symbols[sym] = SymbolDetails{0, SymbolType::Bss, ""};
            }
        }
    }

    void print_symbols() {
        if constexpr (generate_splat_files) {
            for (const auto& [s, details] : symbols) {
                uint32_t rom_addr = details.rom_address;
                const std::string& sym_name = details.name;
                // Don't emit symbol entries for generic text relocs
                if (details.type != SymbolType::Text) {
                    if (rom_addr == 0) {
                        // Bss symbol
                        fmt::print(symbol_addrs_file, "{} = 0x{:08X}; // segment:{}\n",
                            sym_name.empty() ? symbol_name(s, details.type) : sym_name, s.address, s.ovl_name);
                    }
                    else {
                        // Non-bss symbol
                        fmt::print(symbol_addrs_file, "{} = 0x{:08X}; // segment:{} rom:0x{:08X} {}\n", 
                            sym_name.empty() ? symbol_name(s, details.type) : sym_name, s.address, s.ovl_name, rom_addr, details.type == SymbolType::Function ? "type:func" : "");
                    }
                }
            }
            for (const auto& reloc : relocs) {
                const auto& symbol_details = symbols[reloc.symbol];
                const std::string& sym_name = symbol_details.name;
                // Don't emit reloc_addrs entries for generic text relocs in rodata
                if (!(symbol_details.type == SymbolType::Text && reloc.section == Section::Rodata)) {
                    fmt::print(reloc_addrs_file, "rom:0x{:08X} symbol:{} reloc:{}\n",
                        reloc.rom_address, sym_name.empty() ? symbol_name(reloc.symbol, symbol_details.type) : sym_name, reloc_names[(size_t)reloc.type]);
                }
            }
        }
    }

    void add_overlay(const char* name, uint32_t rom_start, uint32_t code_rom_start, uint32_t text_size, uint32_t rodata_size, uint32_t data_size, uint32_t bss_size, uint32_t num_relocs, std::vector<std::string>&& entrypoints) {
        if constexpr (generate_any_files) {
            all_overlays.push_back(overlays.size());
            overlays.emplace_back(Overlay{
                .name = name,
                .rom_start = rom_start,
                .code_rom_start = code_rom_start,
                .text_size = text_size,
                .rodata_size = rodata_size,
                .data_size = data_size,
                .bss_size = bss_size,
                .num_relocs = num_relocs,
                .entrypoints = std::move(entrypoints)
            });
        }
    }

    void add_empty_overlay() {
        if constexpr (generate_any_files) {
            all_overlays.push_back((size_t)-1);
        }
    }

    void print_overlays() {
        if constexpr (generate_splat_files) {
            uint32_t rom_end = 0;
            fmt::print(yaml_file,
                "  - name: overlay_table\n"
                "    type: bin\n"
                "    extract: False\n"
                "    start: 0x{0:08X}\n",
                overlay_table_rom_start_);
            for (const auto& overlay : overlays) {
                uint32_t text_start = overlay.code_rom_start;
                uint32_t rodata_start = text_start + overlay.text_size;
                uint32_t data_start = rodata_start + overlay.rodata_size;
                uint32_t data_end = data_start + overlay.data_size;
                fmt::print(yaml_file,
                    "  - name: {0}_header\n"
                    "    dir: overlays/{0}\n"
                    "    type: bin\n"
                    "    start: 0x{1:08X}\n"
                    "    extract: False\n"
                    "  - name: {0}\n"
                    "    dir: overlays/{0}\n"
                    "    type: code\n"
                    "    vram: 0x{7:08X}\n"
                    "    start: 0x{2:08X}\n"
                    "    bss_size: 0x{6:08X}\n"
                    "    exclusive_ram_id: overlay\n"
                    "    symbol_name_format: $VRAM_$SEG\n"
                    "    symbol_name_format_no_rom: $VRAM_$SEG\n"
                    "    subsegments: \n"
                    "      - [0x{2:08X}, c, {0}]\n"
                    "      - [0x{3:08X}, .rodata, {0}]\n"
                    "      - [0x{4:08X}, data, {0}]\n"
                    "      - [0x{5:08X}, bss, {0}]\n",
                    overlay.name, overlay.rom_start, text_start, rodata_start, data_start, data_end, overlay.bss_size, overlay_vram);
                rom_end = data_end;
            }
            fmt::print(yaml_file, "  - [0x{:08X}]\n", rom_end);
        }

        if constexpr (generate_overlay_toml) {
            for (size_t i = 0; i < all_overlays.size(); i++) {
                size_t overlay_index = all_overlays[i];
                if (overlay_index != (size_t)-1) {
                    const auto& overlay = overlays[overlay_index];
                    fmt::print(overlay_toml_file,
                        "[[overlay]] # Overlay {}\n"
                        "name = \"{}\"\n"
                        "entrypoints = [\n",
                        i + 1, overlay.name);
                    for (const std::string& entrypoint : overlay.entrypoints) {
                        fmt::print(overlay_toml_file,
                        "  \"{}\",\n", entrypoint);
                    }
                    fmt::print(overlay_toml_file, "]\n\n");
                }
                // Empty overlay
                else {
                    fmt::print(overlay_toml_file,
                        "[[overlay]] # Overlay {}\n"
                        "empty = true\n\n",
                        i + 1);
                }
            }
        }
    }

    bool is_rejected(const std::string& ovl_name, uint32_t address) {
        return rejected_symbols.contains(OverlaySymbol{ovl_name, address});
    }
};

template <typename T>
void resize_if_larger(std::vector<T>& vec, size_t new_size) {
    if (vec.size() < new_size) {
        vec.resize(new_size);
    }
}

void undo_xors(size_t overlay_index, char* rom_start, char* overlay_data, std::vector<char>& decompressed_buffer, size_t decompressed_size) {
    // Calculate the CRCs of the decompressed overlay data
    uint32_t crc1, crc2;
    bk_crc(decompressed_buffer.data(), decompressed_size, crc1, crc2);
    // printf("crcs: %08X %08X\n", crc1, crc2);

    // Reverse the CRC xor in the overlay
    *reinterpret_cast<uint32_t*>(overlay_data + 0) ^= byteswap32(crc1);
    *reinterpret_cast<uint32_t*>(overlay_data + 8) ^= byteswap32(crc2);

    // Get the pointer to the relocs and the number of relocs
    uint16_t num_relocs;
    uint16_t num_entrypoints;
    char* ovl_relocs = get_overlay_reloc_ptr(overlay_data, decompressed_buffer.data(), &num_entrypoints, &num_relocs);

    // Read the data from the start of the rom used to xor the relocs
    uint32_t rom_xor = byteswap32(*reinterpret_cast<uint32_t*>(rom_start + 0x40 + overlay_index * sizeof(uint32_t))) & 0xFFFF;
    uint32_t rom_xor_swapped = byteswap16(rom_xor);

    // Reverse the reloc xors in the overlay (use the byteswapped xor value to avoid needing to byteswap the reloc value)
    for (uint16_t reloc_index = 0; reloc_index < num_relocs; reloc_index++) {
        *reinterpret_cast<uint16_t*>(ovl_relocs + reloc_index * sizeof(uint16_t)) ^= rom_xor_swapped;
    }
}

void parse_relocs(output_file_state& output_files, uint32_t ovl_rom_address, const char* ovl_name, char* overlay_header, char* overlay_contents, uint32_t text_size, uint32_t rodata_size, uint32_t data_size, uint32_t bss_size) {
    std::string ovl_asset_dir = std::string{"assets/overlays/"} + ovl_name;
    std::filesystem::create_directories(ovl_asset_dir);
    std::ofstream relocs_bin{ovl_asset_dir + "/relocs.bin", std::ios_base::binary};
    // Get the pointer to the relocs and the number of relocs
    uint16_t num_entrypoints;
    uint16_t num_relocs;
    char* ovl_relocs = get_overlay_reloc_ptr(overlay_header, overlay_contents, &num_entrypoints, &num_relocs);
    char* ovl_relocs_end = ovl_relocs + num_relocs * sizeof(uint16_t);
    size_t ovl_relocs_end_offset = ovl_relocs_end - overlay_contents;
    // Align the overlay offset to 16 bytes to get the location of code
    size_t ovl_code_offset = ((ovl_relocs_end_offset + 16 - 1) & -16);
    char* ovl_code = overlay_contents + ovl_code_offset;

    uint32_t text_end = overlay_vram + text_size;
    uint32_t rodata_end = text_end + rodata_size;
    uint32_t data_end = rodata_end + data_size;
    uint32_t bss_end = data_end + bss_size;

    // fmt::print(" Text {:08X} Rodata {:08X} Data {:08X} Bss {:08X}\n", text_size, rodata_size, data_size, bss_size);
    // fmt::print(" Text {0:08X} - {1:08X}, Rodata {1:08X} - {2:08X}, Data {2:08X} - {3:08X}, Bss {3:08X} - 0x{4:08X}\n",
    //     overlay_vram, text_end, rodata_end, data_end, bss_end);
    // printf("  code offset: 0x%08lX\n", ovl_code_offset);

    bool tracking_hi = false;
    uint32_t prev_hi_addend = 0;
    for (uint16_t reloc_index = 0; reloc_index < num_relocs; reloc_index++) {
        // Read the reloc value
        uint16_t reloc_val = byteswap16(*reinterpret_cast<uint16_t*>(ovl_relocs + reloc_index * sizeof(uint16_t)));
        // Write the reloc value to the overlay's reloc list
        relocs_bin.write(reinterpret_cast<char*>(&reloc_val), sizeof(reloc_val));
        // Determine the reloc offset and type
        TooieRelocType reloc_type = (TooieRelocType)(reloc_val & 0x3);
        uint16_t reloc_offset = reloc_val & ~0x3;
        // Get the overlay word that the reloc corresponds to
        uint32_t reloc_word = byteswap32(*reinterpret_cast<uint32_t*>(ovl_code + reloc_offset));
        // printf("    %4d Type: %-11s Offset: 0x%04X Word: %08X (Val: 0x%04X)\n", reloc_index, reloc_names[(size_t)reloc_type], reloc_offset, reloc_word, reloc_val);

        uint32_t reloc_addend = 0;

        if (reloc_type == TooieRelocType::R_MIPS_HI16) {
            reloc_addend = (reloc_word & 0xFFFF) << 16;
            prev_hi_addend = reloc_addend;
            tracking_hi = true;
            // Get the full addend
            // This wouldn't be needed for just relocating this instruction, but it is for generating a symbol name for splat
            if (reloc_index + 1 < num_relocs) {
                // Read the next reloc value
                uint16_t next_reloc_val = byteswap16(*reinterpret_cast<uint16_t*>(ovl_relocs + (reloc_index + 1) * sizeof(uint16_t)));
                // Determine the next reloc offset and type
                TooieRelocType next_reloc_type = (TooieRelocType)(next_reloc_val & 0x3);
                uint16_t next_reloc_offset = next_reloc_val & ~0x3;
                // Get the overlay word that the next reloc corresponds to
                uint32_t next_reloc_word = byteswap32(*reinterpret_cast<uint32_t*>(ovl_code + next_reloc_offset));
                if (next_reloc_type == TooieRelocType::R_MIPS_LO16) {
                    reloc_addend += (int16_t)(next_reloc_word & 0xFFFF);
                }
                else {
                    fmt::print(stderr, "hi with wrong reloc type afterwards ({})\n", reloc_names[(size_t)next_reloc_type]);
                }

            }
            else {
                fmt::print(stderr, "hi with no reloc afterwards\n");
            }
            // This is safe to do as no overlay could possibly be large enough for these bits to overlap with a reloc's hi offset
            reloc_word |= (overlay_vram >> 16);
        }
        else if (reloc_type == TooieRelocType::R_MIPS_LO16) {
            if (tracking_hi) {
                reloc_addend = prev_hi_addend + (int16_t)(reloc_word & 0xFFFF);
            }
            else {
                fmt::print(stderr, "lo without hi (reloc {} in {})\n", reloc_index, ovl_name);
                reloc_addend = (int16_t)(reloc_word & 0xFFFF);
            }
        }
        else if (reloc_type == TooieRelocType::R_MIPS_32) {
            reloc_addend = reloc_word;
            reloc_word |= overlay_vram;
        }
        else if (reloc_type == TooieRelocType::R_MIPS_26) {
            reloc_addend = (reloc_word & ((1 << 26) - 1)) << 2;
            // Grab the lower 26 bits of the vram offset and right shift by 2 to encode the address as R_MIPS_26
            reloc_word |= (overlay_vram & ((1 << 26) - 1)) >> 2;
        }

        // Write the word back with the vram adjusted to start at the overlay ram address
        *reinterpret_cast<uint32_t*>(ovl_code + reloc_offset) = byteswap32(reloc_word);

        // Stop tracking the previous HI16 if we see anything other than a HI16 or LO16
        if (reloc_type != TooieRelocType::R_MIPS_HI16 && reloc_type != TooieRelocType::R_MIPS_LO16) {
            tracking_hi = false;
        }

        uint32_t symbol_address = overlay_vram | reloc_addend;
        // fmt::print("      0x{:08X}\n", symbol_address);

        // Skip rejected symbols
        if (output_files.is_rejected(ovl_name, symbol_address)) {
            fmt::print(stderr, "Rejected: 0x{:08X} in {}\n", symbol_address, ovl_name);
            continue;
        }
        
        if (symbol_address >= data_end) {
            // fmt::print("      bss\n");
            output_files.add_bss_symbol(ovl_name, symbol_address);
        }
        else {
            output_files.add_symbol(ovl_name, symbol_address, ovl_rom_address + 0x10 + ovl_code_offset + reloc_addend);
        }
        output_files.add_reloc(ovl_name, symbol_address, ovl_rom_address + 0x10 + ovl_code_offset + reloc_offset, reloc_type, reloc_offset, text_size, rodata_size, data_size);

        if (symbol_address < text_end) {
            if (reloc_type == TooieRelocType::R_MIPS_26) {
                output_files.set_symbol_type(ovl_name, symbol_address, SymbolType::Function);
            } else {
                // Don't override functions with generic text symbols
                SymbolType cur_type = output_files.get_symbol_type(ovl_name, symbol_address);
                if (cur_type != SymbolType::Function) {
                    output_files.set_symbol_type(ovl_name, symbol_address, SymbolType::Text);
                }
            }
        }
        else if (symbol_address < rodata_end) {
            output_files.set_symbol_type(ovl_name, symbol_address, SymbolType::Rodata);
        }
        else if (symbol_address < data_end) {
            output_files.set_symbol_type(ovl_name, symbol_address, SymbolType::Data);
        }
        else if (symbol_address < bss_end) {
            output_files.set_symbol_type(ovl_name, symbol_address, SymbolType::Bss);
        }
        else {
            // fmt::print(stderr, "Symbol in reloc {} in {} is beyond the end of bss\n", reloc_index, ovl_name);
        }
    }
}

std::vector<char> read_file_contents(const char* file_path) {
    std::vector<char> ret;

    // Open the file    
    std::ifstream input_file{file_path, std::ios::binary};

    // Get the file's length
    input_file.seekg(0, std::ios::end);
    size_t file_size = input_file.tellg();

    // Seek back to the start and read the file's contents
    input_file.seekg(0);
    ret.resize(file_size);
    input_file.read(ret.data(), file_size);

    return ret;
}

template <typename T>
T read_swapped(const std::vector<char>& data, size_t offset) = delete;

template<>
uint32_t read_swapped(const std::vector<char>& data, size_t offset) {
    return byteswap32(*reinterpret_cast<const uint32_t*>(data.data() + offset));
}

template<>
uint16_t read_swapped(const std::vector<char>& data, size_t offset) {
    return byteswap16(*reinterpret_cast<const uint16_t*>(data.data() + offset));
}

template<>
uint8_t read_swapped(const std::vector<char>& data, size_t offset) {
    return static_cast<uint8_t>(*(data.data() + offset));
}


template <typename T>
void write_swapped(std::vector<char>& data, size_t offset, T val) = delete;

template<>
void write_swapped(std::vector<char>& data, size_t offset, uint32_t val) {
    *reinterpret_cast<uint32_t*>(data.data() + offset) = byteswap32(val);
}

template<>
void write_swapped(std::vector<char>& data, size_t offset, uint16_t val) {
    *reinterpret_cast<uint16_t*>(data.data() + offset) = byteswap16(val);
}

template<>
void write_swapped(std::vector<char>& data, size_t offset, uint8_t val) {
    *(data.data() + offset) = static_cast<char>(val);
}

void decompress_copy(z_stream& stream, std::ofstream& output_rom, const std::vector<char> baserom_contents, size_t offset, size_t size) {
    size_t decompressed_size = read_swapped<uint16_t>(baserom_contents, offset) * 16;
    std::vector<char> decompressed_buffer(decompressed_size);

    stream.avail_in = size - sizeof(uint16_t);
    stream.next_in = reinterpret_cast<const Bytef*>(baserom_contents.data() + offset + sizeof(uint16_t));

    stream.avail_out = decompressed_size;
    stream.next_out = reinterpret_cast<Bytef*>(decompressed_buffer.data());
    int err = 0;
    while (!err) {
        err = inflate(&stream, Z_NO_FLUSH);
    }
    if (err != Z_STREAM_END) {
        fmt::print(stderr, "Zlib error: {}\n", err);
        std::exit(EXIT_FAILURE);
    }
    output_rom.write(decompressed_buffer.data(), decompressed_size);

    inflateReset(&stream);
}

int main(int argc, const char** argv) {
    if (argc != 3) {
        fmt::print(stderr, "Decompresses a Banjo Tooie ROM.\n");
        fmt::print(stderr, "Usage: {} [base ROM] [output ROM path]\n", argv[0]);
        return EXIT_SUCCESS;
    }

    const char* baserom_path = argv[1];
    const char* output_rom_path = argv[2];
    
    // Read the contents of the base ROM
    std::vector<char> baserom_contents = read_file_contents(baserom_path);

    std::ofstream output_rom_file{output_rom_path, std::ios::binary};
    
    // Write the contents up to core1
    output_rom_file.write(baserom_contents.data(), us_v10.core1_start);

    z_stream stream;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    stream.avail_in = 0;
    stream.next_in = Z_NULL;
    inflateInit2(&stream, -MAX_WBITS);

    decompress_copy(stream, output_rom_file, baserom_contents, us_v10.core1_start, us_v10.core1_text_end - us_v10.core1_start);
    decompress_copy(stream, output_rom_file, baserom_contents, us_v10.core1_text_end, us_v10.core1_end - us_v10.core1_text_end);
    decompress_copy(stream, output_rom_file, baserom_contents, us_v10.core2_start, us_v10.core2_text_end - us_v10.core2_start);
    decompress_copy(stream, output_rom_file, baserom_contents, us_v10.core2_text_end, us_v10.core2_end - us_v10.core2_text_end);

    output_file_state output_files{(size_t)output_rom_file.tellp()};

    uint32_t overlay_table_size = read_swapped<uint32_t>(baserom_contents, us_v10.overlay_table_offset);
    
    // Record the current output file position to know where to write the overlay table later
    size_t cur_output_pos = output_rom_file.tellp();
    // Align the overlay table to 16 bytes like in the compressed rom
    size_t output_overlay_table_pos = (cur_output_pos + 15) & -16;
    // Pad with zeroes to read the alignment
    static const char zeroes[]  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    output_rom_file.write(zeroes, output_overlay_table_pos - cur_output_pos);

    size_t overlay_count = overlay_table_size / sizeof(uint32_t) - 1;
    std::vector<uint32_t> overlay_table;
    overlay_table.resize(overlay_count + 1);

    for (size_t i = 0; i < overlay_count + 1; i++) {
        overlay_table[i] = read_swapped<uint32_t>(baserom_contents, us_v10.overlay_table_offset + sizeof(uint32_t) * i);
    }

    std::vector<char> decompressed_buffer;
    decompressed_buffer.resize(1024);

    size_t total_compressed = 0;
    size_t total_decompressed = 0;

    // Seek past the overlay table since that'll be written afterwards
    output_rom_file.seekp((overlay_count + 1) * sizeof(uint32_t), std::ios::cur);
    
    // Track the file offsets of each overlay as they're written
    std::vector<uint32_t> byteswapped_overlay_offsets;
    byteswapped_overlay_offsets.resize(overlay_count + 1);

    // Overlays are 1-indexed, so start at 1 and include the count in iteration
    for (size_t overlay_index = 1; overlay_index <= overlay_count; overlay_index++) {
        byteswapped_overlay_offsets[overlay_index - 1] = byteswap32((uint32_t)output_rom_file.tellp() - output_overlay_table_pos);

        uint32_t overlay_start = overlay_table[overlay_index - 1];
        uint32_t overlay_end   = overlay_table[overlay_index];
        // fmt::print("Ovl {}: 0x{:04X} bytes\n", overlay_index, overlay_end - overlay_start);
        char* overlay_contents;
        size_t overlay_contents_length;

        if (overlay_end != overlay_start) {
            size_t ovl_rom_start = us_v10.overlay_table_offset + overlay_start;
            char* overlay_header = baserom_contents.data() + ovl_rom_start;

            uint32_t flags = read_swapped<uint32_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::flags);
            // fmt::print("  sp3C: 0x{:04X} Flags: 0x{:02X}\n", sp3C, flags);

            if (flags & (uint32_t)OverlayFlags::Compressed) {
                uint32_t decompressed_size = read_swapped<uint16_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::decompressed_size) * 16;
                flags &= ~(uint32_t)OverlayFlags::Compressed;
                write_swapped<uint32_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::flags, flags);

                // fmt::print("  Compressed, decompressed size: 0x%04X\n", decompressed_size);
                total_compressed += overlay_end - overlay_start;
                total_decompressed += decompressed_size;

                resize_if_larger(decompressed_buffer, decompressed_size);

                constexpr int header_size = 0x12;
                stream.avail_in = overlay_end - overlay_start - header_size;
                stream.next_in = reinterpret_cast<const Bytef*>(overlay_header + header_size);

                stream.avail_out = decompressed_size;
                stream.next_out = reinterpret_cast<Bytef*>(decompressed_buffer.data());
                int err = 0;
                while (!err) {
                    err = inflate(&stream, Z_NO_FLUSH);
                }
                if (err != Z_STREAM_END) {
                    printf("Zlib error: %d\n", err);
                    return err;
                }
                inflateReset(&stream);

                undo_xors(overlay_index, baserom_contents.data(), overlay_header, decompressed_buffer, decompressed_size);

                // printf("  %08X %08X %08X %08X\n",
                //     byteswap32(*reinterpret_cast<uint32_t*>(overlay_header.data() + 0)),
                //     byteswap32(*reinterpret_cast<uint32_t*>(overlay_header.data() + 4)),
                //     byteswap32(*reinterpret_cast<uint32_t*>(overlay_header.data() + 8)),
                //     byteswap32(*reinterpret_cast<uint32_t*>(overlay_header.data() + 12)));
                // for (int i = 0; i < 15; i++) {
                //     printf("  %08X %08X %08X %08X\n",
                //         byteswap32(*reinterpret_cast<uint32_t*>(decompressed_buffer.data() + 16 * i + 0)),
                //         byteswap32(*reinterpret_cast<uint32_t*>(decompressed_buffer.data() + 16 * i + 4)),
                //         byteswap32(*reinterpret_cast<uint32_t*>(decompressed_buffer.data() + 16 * i + 8)),
                //         byteswap32(*reinterpret_cast<uint32_t*>(decompressed_buffer.data() + 16 * i + 12)));
                // }
                overlay_contents = decompressed_buffer.data();
                overlay_contents_length = decompressed_size;
            } else {
                overlay_contents = overlay_header + 0x10;
                overlay_contents_length = overlay_end - overlay_start - 0x10;
                // fmt::print("  Uncompressed\n");
            }
            
            uint32_t text_size = 16 * read_swapped<uint16_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::text_size);
            uint32_t rodata_size = 16 * read_swapped<uint16_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::rodata_size);
            uint32_t data_size = 16 * read_swapped<uint16_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::data_size);
            uint32_t bss_size = 16 * read_swapped<uint16_t>(baserom_contents, ovl_rom_start + ovl_header_offsets::bss_size);
            // fmt::print(" Parsed Text {:08X} Rodata {:08X} Data {:08X} Bss {:08X}\n", text_size, rodata_size, data_size, bss_size);

            // Get the pointer to the relocs and the number of relocs
            uint16_t num_relocs;
            uint16_t num_entrypoints;
            char* ovl_relocs = get_overlay_reloc_ptr(overlay_header, overlay_contents, &num_entrypoints, &num_relocs);
            char* ovl_relocs_end = ovl_relocs + num_relocs * sizeof(uint16_t);
            size_t ovl_relocs_end_offset = ovl_relocs_end - overlay_contents;
            // Align the overlay offset to 16 bytes to get the location of code
            size_t ovl_code_offset = ((ovl_relocs_end_offset + 16 - 1) & -16);
            const char* ovl_entrypoints = overlay_contents + 0x28;
            const char* ovl_name = ovl_entrypoints + num_entrypoints * sizeof(uint32_t);
            // printf("  Name: %s\n", ovl_name);

            size_t before = output_rom_file.tellp();
            size_t pad_amount = 16 - (before & (16 - 1));

            std::vector<std::string> entrypoints{};
            entrypoints.reserve(num_entrypoints);

            for (size_t i = 0; i < num_entrypoints; i++) {
                uint32_t entrypoint_offset = byteswap32(*reinterpret_cast<const uint32_t*>(ovl_entrypoints + i * sizeof(uint32_t)));
                output_files.add_symbol(ovl_name, entrypoint_offset | overlay_vram, before + 0x10 + ovl_code_offset + entrypoint_offset);
                std::string entrypoint_name = ovl_name + std::string{"_entrypoint_"} + std::to_string(i);
                output_files.set_symbol_name(ovl_name, entrypoint_offset | overlay_vram, entrypoint_name);
                entrypoints.emplace_back(std::move(entrypoint_name));
            }

            if (pad_amount != 16) {
                output_rom_file.write(zeroes, pad_amount);
                before = output_rom_file.tellp();
                byteswapped_overlay_offsets[overlay_index - 1] = byteswap32((uint32_t)before - output_overlay_table_pos);
            }
            
            parse_relocs(output_files, before, ovl_name, overlay_header, overlay_contents, text_size, rodata_size, data_size, bss_size);

            output_rom_file.write(overlay_header, 0x10);
            output_rom_file.write(overlay_contents, overlay_contents_length);

            // size_t after = output_rom_file.tellp();

            // printf("  Code Size: 0x%08lX Total Size: 0x%08lX From: 0x%08lX to 0x%08lX\n", after - before - ovl_code_offset - 0x10, after - before, before, after);
            // printf("  Num Entrypoints: %u\n", num_entrypoints);
            output_files.add_overlay(ovl_name, before, before + ovl_code_offset + 0x10, text_size, rodata_size, data_size, bss_size, num_relocs, std::move(entrypoints));
        } else {
            // fmt::print("  Empty overlay\n");
            output_files.add_empty_overlay();
        }
    }

    output_files.print_symbols();
    output_files.print_overlays();

    // printf("Compression ratio: %5.3f\n", (float)total_compressed / total_decompressed);
    byteswapped_overlay_offsets[overlay_count] = byteswap32((uint32_t)output_rom_file.tellp() - output_overlay_table_pos);

    // Overlay 0 is empty, so make its start equal the next overlay's start in case any padding was added after the overlay table
    byteswapped_overlay_offsets[0] = byteswapped_overlay_offsets[1];

    // Rewind the output rom file and write the overlay table
    output_rom_file.seekp(output_overlay_table_pos);
    output_rom_file.write(reinterpret_cast<char*>(byteswapped_overlay_offsets.data()), byteswapped_overlay_offsets.size() * sizeof(byteswapped_overlay_offsets[0]));

    return 0;
}
