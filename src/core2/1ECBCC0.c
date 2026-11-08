#include <ultra64.h>
#include "core1/mlmtx.h"
#include "core2/1ECBCC0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F23D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F24D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F254C.s")

void func_800F26B0(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_800F274C(arg0);
    arg0->m[0][0] = arg1;
    arg0->m[1][1] = arg2;
    arg0->m[2][2] = arg3;
    arg0->m[3][3] = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F274C.s")

//guMtxCatF
void func_800F27D4(f32 lmf[4][4], f32 rmf[4][4], f32 dst[4][4]) {
    s32 i, j, k;
    f32 sp1C[4][4];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            sp1C[i][j] = 0.0f;
            for (k = 0; k < 4; k++) {
                sp1C[i][j] += lmf[i][k] * rmf[k][j];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            dst[i][j] = sp1C[i][j];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F293C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2C1C.s")

// Transforms a Vec4f by a MtxF.
void func_800F2D34(MtxF* mat, f32 out[4], f32 in[4]) {
    s32 pad;
    f32 in_copy[4];

    in_copy[0] = in[0];
    in_copy[1] = in[1];
    in_copy[2] = in[2];
    in_copy[3] = in[3];
    out[0] = in_copy[0] * mat->m[0][0] + in_copy[1] * mat->m[1][0] + in_copy[2] * mat->m[2][0] + in_copy[3] * mat->m[3][0];
    out[1] = in_copy[0] * mat->m[0][1] + in_copy[1] * mat->m[1][1] + in_copy[2] * mat->m[2][1] + in_copy[3] * mat->m[3][1];
    out[2] = in_copy[0] * mat->m[0][2] + in_copy[1] * mat->m[1][2] + in_copy[2] * mat->m[2][2] + in_copy[3] * mat->m[3][2];
    out[3] = in_copy[0] * mat->m[0][3] + in_copy[1] * mat->m[1][3] + in_copy[2] * mat->m[2][3] + in_copy[3] * mat->m[3][3];
}

void ml_vec3i_copy_dupe(s32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void ml_vec4i_copy(s32 dst[4], s32 src[4]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F31DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F31EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F31FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F3214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F32D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F3320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F35AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F362C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F36D4.s")

int ml_vec4i_isEqual(s32 arg0[4], s32 arg1[4]) {
    return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2] && arg0[3] == arg1[3];
}
