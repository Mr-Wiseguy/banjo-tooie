#include "memory.h"

// __heap_align
s32 func_8001BD30(s32 size) {
    s32 misalign = size & 0xf;
    return(misalign) ? (size - misalign + 0x10) : size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BDAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001C070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001C0A0.s")
