#include "types.h"
#include "ba/physics.h"

void init_crc_check();
void ovl_entrypoint();
void func_800A1364();
void func_800965D4();
void func_8001C1C0();
void func_800CFA90();
void func_800D1510();
void set_crc_entry(s32);

extern u8 build_data_ROM_START[];
void rom_read_word(uintptr_t, u32*);

// Do not change these two structs or CRC calculation in the ROM compressor will fail
typedef struct {
    u32 crc1;
    u32 crc2;
    u32 byte_count;
} CrcValues;

typedef struct {
    void* address;
    u8 rom_word_offset;
    u8 in_rom;
} CrcEntry;

// Do not rename this variable or CRC calculation in the ROM compressor will fail
CrcEntry crc_entries[] = {
    {init_crc_check, 9, FALSE},
    {ovl_entrypoint, 12, FALSE},
    {func_800A1364, 15, FALSE},
    {func_800965D4, 18, FALSE},
    {func_8009B7C0, 21, FALSE},
    {func_8001C1C0, 24, FALSE},
    {func_800CFA90, 27, FALSE},
    {func_800D1510, 30, FALSE},
};

u32* next_crc_word;
s32 calculated_crc1;
s32 calculated_crc2;
u32 crc_bytes_remaining;
s32 crc_symbol_index;
s32 crc_good;

void init_crc_check(void) {
    set_crc_entry(0);
    crc_good = TRUE;
}

void set_crc_entry(s32 symbol_index) {    
    crc_symbol_index = symbol_index;
    
    if (symbol_index != 8) {
        next_crc_word = crc_entries[crc_symbol_index].address;
        calculated_crc1 = 0;
        calculated_crc2 = 0;
        rom_read_word((uintptr_t)build_data_ROM_START + crc_entries[crc_symbol_index].rom_word_offset * sizeof(u32) + offsetof(CrcValues, byte_count), &crc_bytes_remaining);
    }
}

// Advances the CRC calculation by 1 word if it's active
s32 advance_crc_check(void) {
    u32 crc1;
    u32 crc2;

    // Mark the CRC as good if the check reached the end of the CRC entries
    if (crc_symbol_index == ARRLEN(crc_entries)) {
        return TRUE;
    }
    // CRC the next word if there are any remaining
    if (crc_bytes_remaining != 0) {
        u8 data[4];
        u8 cur_byte;
        crc1 = calculated_crc1;
        crc2 = calculated_crc2;

        // Read the word from ROM or RAM depending on the entry
        if (crc_entries[crc_symbol_index].in_rom != 0) { /* Needs to be on the same line to match, a backslash achieves this */ \
            rom_read_word((uintptr_t)next_crc_word, (u32*)data);
        } else {
            *(u32*)data = *next_crc_word;
        }

        // Calculate the CRC of the word
        cur_byte = data[0];
        crc1 += cur_byte;
        crc2 ^= cur_byte << (crc1 & 0x17);
        cur_byte = data[1];
        crc1 += cur_byte;
        crc2 ^= cur_byte << (crc1 & 0x17);
        cur_byte = data[2];
        crc1 += cur_byte;
        crc2 ^= cur_byte << (crc1 & 0x17);
        cur_byte = data[3];
        crc1 += cur_byte;
        crc2 ^= cur_byte << (crc1 & 0x17);
        calculated_crc1 = crc1;
        calculated_crc2 = crc2;
        next_crc_word++;
        crc_bytes_remaining -= 4;
    }
    // Otherwise, compare the good CRC values against the calculated values
    else {
        rom_read_word((uintptr_t)build_data_ROM_START + crc_entries[crc_symbol_index].rom_word_offset * sizeof(u32) + offsetof(CrcValues, crc1), &crc1);
        rom_read_word((uintptr_t)build_data_ROM_START + crc_entries[crc_symbol_index].rom_word_offset * sizeof(u32) + offsetof(CrcValues, crc2), &crc2);

        // If either CRC value doesn't match, mark the CRC as bad
        if (crc1 != calculated_crc1) {
            return FALSE;
        }
        
        if (crc2 != calculated_crc2) {
            return FALSE;
        }
        
        // If both CRC values matched, advance to the next symbol
        set_crc_entry(crc_symbol_index + 1);
    }
    return TRUE;
}

void do_crc_check(void) {
    // Check if the CRC has failed
    s32 good = crc_good != FALSE;
    // Don't advance the CRC if it failed already
    if (good) {
        good = (advance_crc_check() != FALSE);
    }
    // Update the CRC status
    crc_good = good;
    // If the CRC failed, enter an infinite loop
    if (!crc_good) {
        while (TRUE) {
        }
    }
}
