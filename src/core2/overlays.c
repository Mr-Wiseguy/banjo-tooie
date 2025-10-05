#include "types.h"
#include "overlays.h"

extern s32 D_80126CB8;
extern u32 D_80126730;
extern struct Overlay* D_80126738[];
extern s32 D_80126CBC;
struct Overlay* ovl_load(s32 arg0, s32 arg1, s32 arg2);
s32 can_defrag_prev(struct Overlay*);
void* defrag(void*);
void ovl_shift(struct Overlay*, s32);
s32 ovl_unload(struct Overlay* arg0, s32 arg1);
void* heap_alloc_sided(s32 size, s32);
void* heap_alloc(s32 size);

s32 D_80117C60 = 0;
s32 D_80117C64 = 0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_800815C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_800815CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_8008160C.s")

void func_80081724()
{
    func_80081744();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_80081744.s")

struct Overlay* ovl_load(s32 overlay_index, s32 arg1, s32 arg2) {
    s32 overlay_size;
    s32 bss_size;
    s32 overlay_rom_size;
    u32 overlay_end_offset;
    u32 overlay_start_offset;
    u32 stack_padding_1; // Unused
    s32 decompressed_size;
    struct Overlay* overlay;
    u32 header_word_3;
    uintptr_t rom_addr;
    u32 header_word_1;
    s32 crc1;
    s32 crc2;
    volatile u32 compressed_first_word;
    u8* compressed_buffer;
    s32 stack_padding_2; // Unused

    rom_addr = D_80126730 + (overlay_index * sizeof(u32)) - sizeof(u32);
    rom_read_word(rom_addr + 0 * sizeof(u32), &overlay_start_offset); // Read the offset to the start of the overlay
    rom_read_word(rom_addr + 1 * sizeof(u32), &overlay_end_offset); // Read the offset to the end of the overlay
    
    rom_addr = overlay_start_offset + D_80126730;
    overlay_rom_size = overlay_end_offset - overlay_start_offset;
    rom_read_word(rom_addr + 1 * sizeof(u32), &header_word_1); // Read the word containing the overlay's bss size
    rom_read_word(rom_addr + 3 * sizeof(u32), &header_word_3); // Read the word containing the overlay's flags
    bss_size = (s16)header_word_1 * 0x10;

    // Check if the overlay has the compressed flag set
    if ((u8)header_word_3 & 0x80) {
        // Compressed overlay
        rom_read_word(rom_addr + sizeof(struct OverlayHeader), &compressed_first_word);

        // Read and calculate the decompressed size
        decompressed_size = compressed_first_word;
        decompressed_size = (decompressed_size & 0xFFFF0000) >> 0x10;
        decompressed_size = decompressed_size * 0x10;
        overlay_size = decompressed_size + bss_size + sizeof(struct OverlayHeader);
    } else {
        // Uncompressed overlay
        decompressed_size = 0;
        overlay_size = overlay_rom_size + bss_size;
    }
    
    // Allocate memory for the overlay
    if (D_80126CB8) {
        overlay = heap_alloc_sided(overlay_size, 1);
    } else if (arg2 || ((u8)header_word_3 & 8)) {
        overlay = heap_alloc_sided(overlay_size, 1);
    } else {
        overlay = heap_alloc_sided(overlay_size, 0);
    }
    
    func_8001B3B0(overlay);
    if (decompressed_size != 0) {
        // Compressed overlay

        // Allocate memory for the compressed data and load it from the ROM
        compressed_buffer = heap_alloc(overlay_rom_size);
        rom_dma_read(compressed_buffer, rom_addr, overlay_rom_size);

        // Copy the overlay header as-is and decompress the rest of the overlay
        bcopy(compressed_buffer, overlay, sizeof(struct OverlayHeader));
        func_8001C2AC(compressed_buffer + sizeof(struct OverlayHeader), (u8*)overlay + sizeof(struct OverlayHeader));
        
        // Get the decompressed CRCs
        crc1 = func_8001C26C();
        crc2 = func_8001C28C();
        
        // Undo xor obfuscation
        *(s32*)((u8*)overlay + 0x0) ^= crc1;
        *(s32*)((u8*)overlay + 0x8) ^= crc2;

        // Free the compressed data buffer
        heap_free(compressed_buffer);
    } else {
        // Uncompressed overlay
        rom_dma_read(overlay, rom_addr, overlay_rom_size);
    }
    ovl_clear_bss(0, overlay);

    // Update the loaded overlay list and return the loaded overlay
    D_80126738[D_80117C60] = overlay;
    overlay->fields.load_index = D_80117C60;
    D_80117C60++;
    return overlay;
}

struct Overlay* func_80081AA4(void*);

void func_800819B4(void* arg0) {
    struct Overlay* ovl;

    ovl = func_80081AA4(arg0);
    if (ovl != NULL) {
        ovl_unload(ovl, 1);
    }
}

s32 ovl_unload(struct Overlay* ovl, s32 arg1) {
    s16 load_index;
    struct Overlay *swapped_ovl;
    s32 temp_t7;

    if (ovl->header.flags & 4) {
        return 0;
    }
    
    temp_t7 = (ovl->header.flags & 1) != 0;
    if (temp_t7) {
        temp_t7 = ovl->header.bss_size != 0;
    }

    // Turn the entrypoints for the unloaded overlay back into syscalls
    ovl_reset_syscalls(ovl, temp_t7);

    // Get the load index of this overlay
    load_index = ovl->fields.load_index;
    D_80117C60--;
    
    // Swap the last loaded overlay into the unloaded overlay's load index
    D_80126738[load_index] = D_80126738[D_80117C60];
    swapped_ovl = D_80126738[load_index];
    swapped_ovl->fields.load_index = load_index;
    
    // Clean up the overlays list
    D_80126738[D_80117C60] = NULL;
    
    // Free the unloaded overlay's memory
    heap_free(ovl);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_80081A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_80081AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_80081BC0.s")

void defragment_overlays(void) {
    s32 i;
    struct Overlay* ovl;
    static s32 defrag_index = 0;

    D_80126CBC = TRUE;
    for (i = 0; i < 15; i++) {
        defrag_index++;
        if (defrag_index >= D_80117C60) {
            defrag_index = 0;
        }
        ovl = D_80126738[defrag_index];
        if (ovl != NULL) {
            if (!(ovl->header.flags & 0x04)) {
                if (ovl->fields.unk32 >= 2) {
                    if (is_prev_free(ovl) != 0) {
                        ovl_unload(ovl, 0);
                    }
                } else if (!(ovl->header.flags & 0x10)) {
                    // Defragment the overlay
                    struct Overlay* defragged = defrag(ovl);

                    // If the overlay was moved during defragmentation, update its location in memory 
                    if (defragged != ovl) {
                        ovl_shift(defragged, (u8*)defragged - (u8*)ovl);
                        D_80126738[defrag_index] = defragged;
                    }
                }
            }
        }
    }
    D_80126CBC = FALSE;
}

s32 func_80081D28()
{
    return D_80126CBC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_80081D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/overlays/func_80081D80.s")
