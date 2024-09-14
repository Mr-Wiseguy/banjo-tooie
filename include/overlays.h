#ifndef __OVERLAYS_H__
#define __OVERLAYS_H__

#include <ultra64.h>

struct OverlayFields {
    u32 entry_hook[6]; // Holds the instructions of initial jump point for all entrypoints
    u32 unk28;
    u16 overlay_index;
    u16 syscall_index;
    s16 load_index;
    s16 unk32;
    void* text_start;
};

struct OverlayHeader {
    u16 text_size;
    u16 rodata_size;
    u16 data_size;
    s16 bss_size;
    u16 num_entrypoints;
    u16 num_relocs;
    u16 unkC;
    u8 name_length;
    u8 flags;
};

struct Overlay {
    struct OverlayHeader header; // Pulled from the ROM
    struct OverlayFields fields; // Populated at runtime
    u8 data[1]; // Variable length
};

#endif
