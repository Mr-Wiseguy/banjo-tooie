#include <ultra64.h>
#include <PR/gbi.h>
#include "ml/mtx.h"

typedef struct {
    Gfx* unk0;
    Mtx* unk4;
} Unkfunc_800E44FC;

typedef struct {
    u8 unk0[68];
} Unkfunc_800E44FC_2;

extern s32 D_8012D500;
extern s32 D_8012D504;
extern s32 D_8012D508;
extern MtxF D_8012D510;
extern u16 D_8012D550;
extern Mtx* D_8012D554;
extern Mtx* D_8012D558;
extern s16 widescreen_enabled;


s32 func_80018BC4();
s32 func_800A89F8();
s32 func_800C4C34(s32, s32, s32, s32);
void func_800CA314(s32, s32);
s32 func_800CA334();
void func_800CA364(s32);
void func_800CA3F4(s32, s32, f32);
f32 func_800CA6E8(s32);
MtxF* func_800CA7AC(s32);
void func_800CA7E4(s32, f32[3]);
u16 func_800CB124(s32, MtxF*);
void func_800E443C(MtxF*, f32[3], f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E36D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E37E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E39A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E39D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E3F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E401C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E4040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E4064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E4088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E40AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E40DC.s")

#if 0
u32 func_800E4140(s32 arg0, s32 arg1) {
    u32 ret;
    u32 sp20;
    ret = func_800C4C34(func_800A89F8(), arg0, arg1, &sp20) != 0;
    if (!ret) {
        ret = sp20 != 0;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBCFC0/func_800E4140.s")
#endif

void func_800E4190(s32 arg0, s32 arg1, s32 arg2) {
    func_800C4C34(func_800A89F8(), arg0, arg1, arg2);
}

void func_800E41CC() {
    D_8012D504 = func_800CA334();
    func_800CA314(D_8012D504, D_8012D500);
}

void func_800E4208() {
    func_800CA314(D_8012D500, D_8012D504);
    func_800CA364(D_8012D504);
    D_8012D504 = 0;
}

void func_800E4244(s32 arg0, f32 arg1) {
    func_800CA3F4(D_8012D500, arg0, arg1);
}

void func_800E4278() {
    D_8012D500 = D_8012D504 = 0;
}

void func_800E4290() {
    D_8012D500 = D_8012D504 = 0;
}

s32 func_800E42A8() {
    return D_8012D500;
}

void func_800E42B4(s32 arg0) {
    D_8012D500 = arg0;
}

f32 func_800E42C0() {
    return func_800CA6E8(D_8012D500);
}

void func_800E42E4(s32 arg0) {
    D_8012D508 = arg0;
}

void func_800E42F0(Unkfunc_800E44FC* arg0, s32 arg1) {
    Gfx* cur_gfx;
    Mtx* cur_mtx;
    cur_gfx = arg0->unk0;
    cur_mtx = arg0->unk4;
    if (arg1 && widescreen_enabled) {
        guOrtho(cur_mtx, -810.0f, 810.0f, -456.0f, 456.0f, -50.0f, 50.0f, 1.0f);
    } else {
        guOrtho(cur_mtx, -608.0f, 608.0f, -456.0f, 456.0f, -50.0f, 50.0f, 1.0f);
    }
    gSPMatrix(cur_gfx++, OS_K0_TO_PHYSICAL(cur_mtx++), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    D_8012D554 = cur_mtx - 1;
    guMtxIdent(cur_mtx);
    gSPMatrix(cur_gfx++, OS_K0_TO_PHYSICAL(cur_mtx++), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    arg0->unk0 = cur_gfx;
    arg0->unk4 = cur_mtx;
}

void func_800E443C(MtxF* arg0, f32* translation, f32 scale) {
    f32 inv_scale;
    MtxF mat;

    mlMtxSet(arg0);
    func_80018C50(func_800CA7AC(D_8012D500));
    
    inv_scale = 1.0f / scale;
    
    // Fill in matrix diagonals (scale).
    mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = inv_scale;
    // Fill in zeroes for the rest of the matrix.
    mat.m[0][1] = mat.m[0][2] = mat.m[0][3] = mat.m[1][0] = mat.m[1][2] = mat.m[1][3] = mat.m[2][0] = mat.m[2][1] = mat.m[2][3] = 0.0f;
    // Fill out bottom row (translation).
    mat.m[3][0] = -translation[0] * inv_scale;
    mat.m[3][1] = -translation[1] * inv_scale;
    mat.m[3][2] = -translation[2] * inv_scale;
    mat.m[3][3] = 1.0f;
    
    func_80018C50(&mat);
}

void func_800E44FC(Unkfunc_800E44FC* arg0) {
    u16 persp_norm;
    MtxF sp44;
    f32 sp38[3];

    func_800CA7E4(D_8012D500, sp38);
    persp_norm = func_800CB124(D_8012D500, &sp44);
    gSPPerspNormalize(arg0->unk0++, persp_norm);
    func_800E443C(&sp44, sp38, func_800CA6E8(D_8012D500));
    if (func_80018BC4()) {
        func_800E443C(&sp44, sp38, 2.0f * func_800CA6E8(D_8012D500));
    }
    mlMtxApply(arg0->unk4);
    gSPMatrix(arg0->unk0++, OS_K0_TO_PHYSICAL(arg0->unk4++), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    D_8012D558 = arg0->unk4 - 1;
    guMtxIdent(arg0->unk4);
    gSPMatrix(arg0->unk0++, OS_K0_TO_PHYSICAL(arg0->unk4++), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
}

void func_800E4628() {
    D_8012D558 = D_8012D554 = NULL;
}

void func_800E4640(Gfx** gfx) {
    if (D_8012D508 != 0) {
        gSPDisplayList((*gfx)++, 0x08000000);
        return;
    }
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL(D_8012D558), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
}

void func_800E46A4(s32 arg0, s32 arg1) {
    func_800F2D34(&D_8012D510, arg0, arg1);
}

u16 func_800E46D4() {
    return D_8012D550;
}

void func_800E46E0(Gfx** gfx, void* addr) {
    // TODO figure out what segment 8 is.
    gSPSegment((*gfx)++, 0x08, osVirtualToPhysical(addr));
}
