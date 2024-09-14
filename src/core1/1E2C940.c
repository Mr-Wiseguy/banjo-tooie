#include "types.h"

extern s16 widescreen_enabled;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800151BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001546C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001559C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800155BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015768.s")

void wait_one_frame(void) {
    while (osViGetCurrentLine() < 5) {
    }
    while (osViGetCurrentLine() > 5) { 
    }
}

void set_widescreen(s32 arg0) {
    widescreen_enabled = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800157EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800158E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001592C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015D14.s")
