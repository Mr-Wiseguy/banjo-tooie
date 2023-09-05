#ifndef __OVERLAY_UTILS_H__
#define __OVERLAY_UTILS_H__

#include <cstdint>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

namespace ELFIO {
    class section;
};

// Relocate overlays to this address for easier disassembly
constexpr uint32_t overlay_vram = 0x80800000;
constexpr uint32_t symbol_not_found = 0xFFFFFFFF;

// Baserom offsets
struct RomOffsets {
    uint32_t core1_start;
    uint32_t core1_text_end;
    uint32_t core1_end;
    uint32_t core2_start;
    uint32_t core2_text_end;
    uint32_t core2_end;
    uint32_t overlay_table_offset;
};

constexpr RomOffsets us_v10 {
    .core1_start = 0x1E29B60,
    .core1_text_end = 0x1E3F718,
    .core1_end = 0x1E42550,
    .core2_start = 0x1E42550,
    .core2_text_end = 0x1E86C76,
    .core2_end = 0x1E899B0,
    .overlay_table_offset = 0x1E899B0,
};

namespace ovl_header_offsets {
    constexpr size_t text_size = 0x0;
    constexpr size_t rodata_size = 0x2;
    constexpr size_t data_size = 0x4;
    constexpr size_t bss_size = 0x6;
    constexpr size_t entrypoint_count = 0x8;
    constexpr size_t reloc_count = 0xA;
    constexpr size_t flags = 0xC;
    constexpr size_t name_length = 0xE;
    constexpr size_t decompressed_size = 0x10;
};

enum class OverlayFlags {
    Compressed = 0x80,
};

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

struct Symbol {
    std::string name;
    uint32_t value;
    Symbol(const std::string& name_) : name(name_), value(symbol_not_found) {}
    Symbol() : name(""), value(symbol_not_found) {}
};

struct Reloc {
    size_t segment_offset;
    RelocType type;
    std::string symbol_name;
};

struct Segment {
    std::string name;
    std::vector<Symbol> entrypoints;
    Symbol ram_start;
    Symbol ram_end;
    Symbol rom_start;
    Symbol rom_end;
    Symbol text_size;
    Symbol rodata_size;
    Symbol data_size;
    Symbol bss_size;
    ELFIO::section* section;
    ELFIO::section* bss_section;
    ELFIO::section* reloc_section;
    Segment(const std::string& name_, std::vector<Symbol>&& entrypoints_) : name(name_), entrypoints{std::move(entrypoints_)},
        ram_start{name + "_VRAM"}, ram_end{name + "_VRAM_END"}, rom_start{name + "_ROM_START"}, rom_end{name + "_ROM_END"}, text_size{name + "_TEXT_SIZE"}, rodata_size{name + "_RODATA_SIZE"}, data_size{name + "_DATA_SIZE"}, bss_size{name + "_BSS_SIZE"},
        section(nullptr), bss_section(nullptr), reloc_section(nullptr) {}
    Segment(const std::string& name_) : name(name_), entrypoints{},
        ram_start{name + "_VRAM"}, ram_end{name + "_VRAM_END"}, rom_start{name + "_ROM_START"}, rom_end{name + "_ROM_END"}, text_size{name + "_TEXT_SIZE"}, rodata_size{name + "_RODATA_SIZE"}, data_size{name + "_DATA_SIZE"}, bss_size{name + "_BSS_SIZE"},
        section(nullptr), bss_section(nullptr), reloc_section(nullptr) {}
};

class ElfHandler {
private:
    struct ElfContext;
    std::unique_ptr<ElfContext> elf_context_;
public:
    ElfHandler(const char* elf_path);
    ~ElfHandler(); // Explicit destructor to allow forward declaration of ElfContext
    void find_segments_in_elf(std::unordered_map<std::string, Segment*>& symbol_map);
    void find_symbol_in_elf(std::unordered_map<std::string, Symbol*>& symbol_map);
    void get_all_relocs_in_segment(const Segment& segment, std::vector<Reloc>& relocs_out);
    void get_tooie_relocs(const Segment& segment, std::vector<uint16_t>& relocs_out);
};

std::vector<Segment> read_config(const char* path);

static inline uint32_t byteswap32(uint32_t in) {
    return __builtin_bswap32(in);
}

static inline uint16_t byteswap16(uint16_t in) {
    return __builtin_bswap16(in);
}

char* get_overlay_reloc_ptr(char* overlay_header, char* overlay_contents, uint16_t* num_entrypoints_out, uint16_t* num_relocs_out);
void bk_crc(const char* bytes, uint32_t size, uint32_t& crc1, uint32_t& crc2, uint32_t start_crc1 = 0, uint32_t start_crc2 = 0);

#endif
