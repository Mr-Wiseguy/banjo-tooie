#include "core2/1EEEF00.h"

s32 func_80115610() 
{
    return 0x38;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_801158B0.s")

void func_801158CC(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void func_801158EC(f32 arg0, f32* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 phi_f0;
    f32 sp38;
    s32 pad34;
    f32 sp30;
    f32 sp2C;

    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    sp30 = time_getDelta();
    sp38 = func_800F1DCC(arg0, *arg1);
    if (mlAbsF(sp38) < arg5) {
        *arg2 = func_800F1344(sp38, 0.0f, arg5, 10.0f, arg4);
    }
    else {
        phi_f0 = arg3 * sp30;
        if (sp38 < 0.0f) {
            phi_f0 = -phi_f0;
        }
        *arg2 += phi_f0;
        if (*arg2 < 0.0f) {
            if (*arg2 < -arg4) {
                *arg2 = -arg4;
            }
        }
        else if (arg4 < *arg2) {
            *arg2 = arg4;
        }
    }
    sp2C = *arg2 * sp30;
    if ((mlAbsF(sp2C) > mlAbsF(sp38)) && ((sp2C * sp38) > 0.0f)) {
        *arg2 = 0.0f;
        *arg1 = arg0;
        sp2C = 0.0f;
    }
    *arg1 = ml_normalizeAngle_f(*arg1 + sp2C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115E88.s")
