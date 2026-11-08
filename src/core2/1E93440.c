#include "core2/1E93440.h"
#include "core2/1EC8070.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800B9B50.s")

s32 func_800BA198(unkStruct800BA198* arg0) {
    s32 temp_v1;
    if (arg0 != NULL) {
        temp_v1 = arg0->unk90;
        if (temp_v1 != 0) {
            return (s32) (temp_v1 - arg0->unk8C) / 60;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA22C.s")

int func_800BA28C(unkStruct800BA198* arg0) {
    return (arg0->unk90 - arg0->unk8C) / 60 == 0 && arg0->unk7 == 2;
}

s32 func_800BA2C4(void) {
    heap_free();
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA3FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA450.s")

void func_800BA4B0(unkStruct800BA198* arg0, s32 arg1) {
    arg0->unk83 = arg1;
}

void func_800BA4B8(unkStruct800BA198* arg0, s32 arg1, s32 arg2) {
    arg0->unkAA = arg1;
    arg0->unkBC = arg2;
}

void func_800BA4C4(unkStruct800BA198* arg0, f32 arg1) {
    arg0->unkB0 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA4D0.s")

void func_800BA544(unkStruct800BA198* arg0, s32 arg1) {
    arg0->unkC0 = arg1;
}

void func_800BA54C(unkStruct800BA198* arg0, s32 arg1) {
    arg0->unkA8 = arg1;
}

void func_800BA554(unkStruct800BA198* arg0, f32 arg1, f32 arg2) {
    arg0->unkB4 = arg1;
    arg0->unkB8 = arg2;
}

void func_800BA568(unkStruct800BA198* arg0, s16 arg1) {
    arg0->unkAE = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA574.s")

void func_800BA594(unkStruct800BA198* arg0, f32 arg1, f32 arg2) {
    arg0->unk18 = arg1;
    arg0->unk1C = arg2;
}

void func_800BA5A8(s16* arg0, s32 arg1) {
    *arg0 = arg1;
}

void func_800BA5B0(unkStruct800BA198* arg0, s32 arg1, s32 arg2) {
    arg0->unk84 = arg1;
    arg0->unk86 = arg2;
}

void func_800BA5BC(unkStruct800BA198* arg0, f32 arg1, f32 arg2) {
    arg0->unk78 = arg1;
    arg0->unk7C = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA610.s")

void func_800BA660(unkStruct800BA198* arg0, s32 arg1, s16 arg2) {
    arg0->unk88 = arg1;
    arg0->unk98 = arg2;
}

void func_800BA670(unkStruct800BA198* arg0, s32 arg1) {
    if (arg1 != arg0->unk2) {
        arg0->unk2 = arg1;
        arg0->unkA = func_800D738C(arg1 & 0xFFFF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA6B0.s")

void func_800BA714(unkStruct800BA198* arg0, s16 arg1, s16 arg2) {
    arg0->unk5 = 1;
    arg0->unk28 = arg1;
    arg0->unk2A = arg2;
}

void func_800BA730(unkStruct800BA198* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk5 = 2;
    arg0->unk28 = arg1;
    arg0->unk2A = arg2;
    arg0->unk2C = arg3;
    arg0->unk2E = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA77C.s")

void func_800BA7C4(unkStruct800BA198* arg0, f32 arg1, f32 arg2) {
    arg0->unk9A = (s16) (s32) (arg1 * 256.0f);
    arg0->unk9C = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA7FC(unkStruct800BA198* arg0, f32 arg1, f32 arg2) {
    arg0->unk9E = (s16) (s32) (arg1 * 256.0f);
    arg0->unkA0 = (s16) (s32) (arg2 * 256.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA930.s")

void func_800BA994(unkStruct800BA198* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    arg0->unk4 = 1;
    arg0->unkC4 = ml_normalizeAngle_f((f32)arg2);
    arg0->unkC6 = ml_normalizeAngle_f((f32)arg5);
    arg0->unkC8 = ml_normalizeAngle_f((f32)arg1);
    arg0->unkCA = ml_normalizeAngle_f((f32)arg4);
    arg0->unkCC = arg3;
    arg0->unkCE = arg6;
}

void func_800BAA60(unkStruct800BA198* arg0, f32* arg1, s16 arg2, s16 arg3)
{
    arg0->unk4 = 2;
    arg0->unkC4 = arg2;
    arg0->unkC6 = arg3;
    ml_vec3f_to_vec3s(&arg0->unkC8, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BAA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BAAE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BAB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BAB54.s")

void func_800BAB60(s32 arg0) {
    func_800F2EA0(arg0 + 0x80);
}

void func_800BAB80(s32 arg0, s32* arg1) {
	func_800F2EBC(arg0 + 0x80, arg1);
}

void func_800BABA0(unkStruct800BA198* arg0, f32 arg1) {
    arg0->unk7 = 0;
    arg0->unk24 = arg1;
}

void func_800BABB0(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BABB8.s")

s32 func_800BBCB8(f32* arg0, f32* arg1, f32 arg2, s32 arg3, s32* arg4)
{
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg3);
    func_800BABB8(temp_v0, arg0, arg1, arg2, arg4);
    func_800BA22C(temp_v0, arg3);
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BBD18.s")