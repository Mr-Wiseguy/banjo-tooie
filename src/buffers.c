#include "buffers.h"

// gfx task dram stack buffer
u64 D_80000400[SP_DRAM_STACK_SIZE64];
 // gfx task output buffer
u64 D_80000800[GFX_OUTPUT_BUFFER_SIZE64];
u64 D_8000E800[0x2800 / 8]; 
u64 D_80011000[0x1000 / 8];
// core1 .text checksum
u32 D_80012000;
u32 D_80012004;
// core1 .data/.rodata checksum
u32 D_80012008;
u32 D_8001200C;
// Only the first element is used, which holds the compressed ROM addresses of core2.
OverlayEntry D_80012010[2];
u32 pad[4];
