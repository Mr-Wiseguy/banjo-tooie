#include "core2/1E78170.h"



extern D_80127040_STRUCT D_80127040;
extern D_80127068_STRUCT D_80127068;

extern f32 D_80127044;
extern f32 D_80127048;
extern u8 D_8012704C;
extern u8 D_80127060;

extern f32 D_8012706C;
extern f32 D_80127070;
extern u8 D_80127074;
extern u8 D_80127075;
extern u8 D_80127076;
extern u8 D_80127077;
extern u8 D_80127078;
extern s16 D_8012707C;
extern s32 D_80127080;

void func_8009E880(void) {
    D_80127068.unkC = 1;
    D_80127068.unkD = 0;
    D_80127040.unkC = 1;
    D_80127040.unk0[0] = 0.0f;
    D_80127040.unk0[1] = 0.0f;
    D_80127040.unk0[2] = 0.0f;
}

void func_8009E8B4(void)
{
    func_800C6E58();
}

void func_8009E8D4(void) 
{
    //Setup BK Ability Flags
    func_800C6E60();
    D_80127040.unkC = func_800D3B60();
    D_80127068.unk18 = 0;
    D_80127068.unkC = 0;
    D_80127068.unkD = 0;
    D_80127068.unkE = 0;
    D_80127068.unkF = 0;
    D_80127068.unk10 = 1;
    D_80127040.unk0[0] = 0.0f;
    D_80127040.unk0[1] = 0.0f;
    D_80127040.unk0[2] = 0.0f;
    D_80127068.unk0[0] = 0.0f;
    D_80127068.unk0[1] = 0.0f;
    D_80127068.unk0[2] = 0.0f;
    flag_setValueFalse(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
    func_8009EAE8(0);
}

u8 func_8009E958(void) {
    return D_8012704C;
}

u8 func_8009E964(void) {
    return D_80127078;
}

f32 func_8009E970(void) {
    return D_80127048;
}

f32 func_8009E97C(void) {
    return D_80127040.unk0[0];
}

f32 func_8009E988(void) {
    return D_80127044;
}

u8 func_8009E994(void) {
    return D_80127075;
}

void func_8009E9A0(void) {
}

void func_8009E9A8(void) {
    func_8009E9FC(0.0f);
    func_8009EB0C(0.0f);
}

void func_8009E9D8(TransformationId arg0) {
    D_8012704C = arg0;
}

void func_8009E9E4(s32 arg0) {
    D_80127078 = arg0;
}


void func_8009E9F0(f32 arg0) {
    D_80127048 = arg0;
}

void func_8009E9FC(f32 arg0) {
    D_80127040.unk0[0] = arg0;
}

void func_8009EA08(f32 arg0) {
    D_80127070 = arg0;
}

f32 func_8009EA14(void) {
    return D_8012706C;
}

u8 func_8009EA20(void) {
    return D_80127077;
}

s32 bs_getDragonKazooieState()
{
    return flag_getValue(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
}

u8 func_8009EA4C(void) {
    return D_80127074;
}

s32 func_8009EA58()
{
    return D_80127080;
}

s32 func_8009EA64(void) {
    return D_8012707C;
}

u8 func_8009EA70(void) {
    return D_80127076;
}

f32 func_8009EA7C(void) {
    return D_80127068.unk0[0];
}

f32 func_8009EA88(void) {
    return D_80127070;
}

void func_8009EA94(f32 arg0) {
    D_8012706C = arg0;
}

void func_8009EAA0(s32 arg0) {
    D_80127077 = arg0;
}

void bs_setDragonKazooieState(s32 arg0) {
    flag_setValue(FLAG_3EC_ABILITY_DRAGON_KAZOOIE, arg0);
}

s32 func_8009EAD0(s32 arg0) {
    D_80127074 = arg0;
}

void func_8009EADC(s32 arg0) {
    D_80127080 = arg0;
}

void func_8009EAE8(s32 arg0) {
    D_8012707C = arg0;
}

void func_8009EAF4(s32 arg0) {
    D_80127076 = arg0;
}

void func_8009EB00(f32 arg0) {
    D_80127068.unk0[0] = arg0;
}

void func_8009EB0C(f32 arg0) {
    D_80127044 = arg0;
}

void func_8009EB18(s32 arg0) {
    D_80127075 = arg0;
}

void func_8009EB24(s16 arg0, s16 arg1) {
    s32 i;

    i = 3;
    while (i > 0) {
        s32* hist = (s32*) &D_80127040.unk10;
        hist[i] = hist[i - 1];
        i--;
    }
    D_80127040.unk20++;
    func_8009EC60(arg0, arg1);
}

void func_8009EB8C(s16 arg0, s16 arg1) {
    func_8009EC3C();
    D_80127040.unk20 = D_80127040.unk20 + 1;
    func_8009EC60(arg0, arg1);
}

void func_8009EBD0(void) {
    s32 i;

    i = 0;
    while (i != 3) {
        s32* hist = (s32*) &D_80127040.unk10;
        hist[i] = hist[i + 1];
        i++;
    }
    D_80127040.unk20 = D_80127040.unk20 - 1;
}

s32 func_8009EC08(s16* arg0, s16* arg1) {
    s16 temp = D_80127040.unk10[0];
    if (temp != 0) {
        *arg0 = temp;
        *arg1 = D_80127040.unk10[1];
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78170/func_8009EC3C.s")

void func_8009EC60(s16 arg0, s16 arg1) {
    D_80127040.unk10[0] = arg0;
    D_80127040.unk10[1] = arg1;
}

u8 func_8009EC7C(void) {
    return D_80127060;
}

s32 func_8009EC88(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < D_80127060; i++) {
        if (arg0 == D_80127040.unk10[i * 2] && arg1 == D_80127040.unk10[i * 2 + 1]) {
            D_80127040.unk10[i * 2] = arg2;
            D_80127040.unk10[i * 2 + 1] = arg3;
            return 1;
        }
    }

    return 0;
}
