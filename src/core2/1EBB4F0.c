#include "core2/1EBB4F0.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s8 pad8[0x8];
    s32 unk10;
    s32 unk14;
    f32 unk18;
    s16 unk1C;
    s8 unk1E;
    s8 unk1F;
    s8 unk20;
    s8 unk21;
    s8 unk22;
    s8 unk23;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s8 pad38[0x40];
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
}D_8012D470UNK;

extern D_8012D470UNK D_8012D470;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E1C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E1DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E204C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E22F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E23A4.s")

void func_800E2434(s32 arg0) {
    D_8012D470.unk20 = arg0;
}

void func_800E2440(s32 arg0, s32 arg1, s32 arg2)
{
    func_800F31DC(&(D_8012D470.unk4), arg0, arg1, arg2);
}

void func_800E2478(s32 arg0) {
    func_800E24F8(arg0, arg0, arg0);
}

void func_800E249C(s32 arg0) {
    D_8012D470.unk24 = arg0;
}

void func_800E24A8(f32 arg0) {
    D_8012D470.unk34 = arg0;
}

void func_800E24B4(s32 arg0)
{
    D_8012D470.unk1F = arg0;
}

void func_800E24C0(s32 arg0) {
    D_8012D470.unk22 = arg0;
}

void func_800E24CC(s32 arg0) {
    D_8012D470.unk23 = arg0;
}

void func_800E24D8(s32 arg0) {
    D_8012D470.unk21 = arg0;
}

void func_800E24E4(s32 arg0, s32 arg1) {
    D_8012D470.unk78 = arg0;
    D_8012D470.unk7C = arg1;
}

void func_800E24F8(s32 arg0, s32 arg1, s32 arg2) {
    func_800F31DC(&D_8012D470.unk10, arg0, arg1, arg2);
}

void func_800E2530(f32 arg0) {
    D_8012D470.unk28 = arg0;
}

void func_800E253C(f32 arg0) {
    D_8012D470.unk30 = arg0;
    D_8012D470.unk2C = (f32)D_8012D470.unk30;
}

void func_800E2554(f32 arg0, f32 arg1) {
    D_8012D470.unk2C = arg0;
    D_8012D470.unk30 = arg1;
}

void func_800E2568(s32 arg0, s32 arg1) {
    D_8012D470.unk0 = arg0;
    D_8012D470.unk2 = arg1;
}

void func_800E257C(s32 arg0) {
    D_8012D470.unk1C = arg0;
}

void func_800E2588(u32 arg0) {
    D_8012D470.unk1E = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E28A4.s")

void func_800E2A14(s32 arg0) {
    func_800E22F0(arg0, D_8012D470.unk80);
    D_8012D470.unk80 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E30E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E3220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E32CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E35E0.s")

void func_800E368C(s32 arg0) {
    func_800E22F0(arg0, D_8012D470.unk84);
    D_8012D470.unk84 = 0;
    func_800E4640(arg0);
}