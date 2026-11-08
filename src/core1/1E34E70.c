#include "common.h"
#include "core1/1E34F80.h"

extern s32 D_8007D160;

s32 func_8001D340(s32 arg0, s32 arg1, s32 arg2) {
    if (D_8007D160 & 1) {
        func_8001DA00(arg1, arg2);
    }
    return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34E70/func_8001D37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34E70/func_8001D3D8.s")
