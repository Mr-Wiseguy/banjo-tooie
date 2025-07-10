#ifndef __BUFFERS_H__
#define __BUFFERS_H__

#include "common.h"

typedef struct {
    u8* rom_start;
    u8* rom_end;
} OverlayEntry;

#define GFX_OUTPUT_BUFFER_SIZE 0xE000
#define GFX_OUTPUT_BUFFER_SIZE64 ((GFX_OUTPUT_BUFFER_SIZE) / sizeof(u64))
// gfx task dram stack buffer
extern u64 D_80000400[SP_DRAM_STACK_SIZE64];
 // gfx task output buffer
extern u64 D_80000800[GFX_OUTPUT_BUFFER_SIZE64];

extern u64 D_8000E800[];
extern u64 D_80011000[];

// core1 .text checksum
extern u32 D_80012000;
extern u32 D_80012004;

// core1 .data/.rodata checksum
extern u32 D_80012008;
extern u32 D_8001200C;

// Only the first element is used, which holds the compressed ROM addresses of core2.
extern OverlayEntry D_80012010[];

// Region of memory to use for holding compressed data while loading core1.
#define COMPRESSION_BUFFER 0x80200000

#endif
