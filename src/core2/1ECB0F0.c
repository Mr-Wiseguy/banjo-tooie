#include "core2/1ECB0F0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F18FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1988.s")

void func_800F1A88(f32* arg0, f32* arg1)
{
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    temp_f0 = arg0[2];
    temp_f2 = arg0[0];
    temp_f0_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    sp1C = temp_f0_2;
    arg1[1] = func_80013B70(arg0[0], arg0[2], temp_f0_2);
    arg1[0] = func_80013B7C(arg0[1], sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1CF0.s")

f32 func_800F1DCC(f32 arg0, f32 arg1)
{
    return ml_absNormalizeAngle_f(arg0 - arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F2094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F20BC.s")
