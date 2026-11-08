#include "core2/1E8F430.h"


typedef struct {
    /* 0x0 */   s16 coordX;
    /* 0x2 */   s16 coordY;
    /* 0x4 */   s16 unk4;
    /* 0x6 */   u8 unk6_4 : 4;
    /* 0x6 */   u8 unk6_3 : 1;
    /* 0x6 */   u8 unk6_2 : 1;
    /* 0x6 */   u8 unk6_1 : 1;
    /* 0x6 */   u8 unk6_0 : 1;
    /* 0x7 */   u8 unk7;
    /* 0x8 */   f32 unk8;
    /* 0xC */   char* text;
    /* 0x10 */  u8 unk10;
    /* 0x11 */  u8 unk11;
    /* 0x12 */  u8 unk12;
    /* 0x13 */  u8 unk13;
} UNKTEXTSTRUCT;

typedef struct {
    Vector* unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    s16 unk14;
    f32 unk18;
} UNK80128180;
extern UNK80128180 D_80128180;

extern s32 D_80127128;
extern s32 D_801282B0[2];

extern u8 D_8011A5C2[][2];
extern u8 D_80128151[];

void func_800B5B40(void)
{
    int index;
    for (index = 0; index < 0x28; index++)
    {
        func_800B58D4(D_80128151[index]);
        D_80128151[index] = 0;
    }
}

void func_800B5B88(void)
{
    int index;
    for (index = 0; index < 0x28; index++)
    {
        D_80128151[index] = func_800B5758(D_8011A5C2[index][1]);
    }
}

s32 func_800B5BE4(s32 arg0) {
    return func_800B56D0(D_80128151[arg0-1]);
}

void* func_800B5C10(s32 arg0, s32 arg1, s32* arg2, s32* arg3)
{
    s32 temp_v0;
    s32* sp18;

    temp_v0 = func_800D3524(arg0);
    sp18 = func_800B0D6C(temp_v0, arg1);
    *arg2 = func_800B0D58(temp_v0);
    *arg3 = sp18[1] + func_800B0D60(temp_v0);
    return sp18;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5C7C.s")

void func_800B5DD4()
{
    func_800B5C7C(0x8);
}

void func_800B5DF4(void) {
}

void func_800B5DFC(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5E04.s")

void func_800B5E3C(void) {
    if (D_80128180.unk0 != 0) {
        D_80128180.unk0 = vector_defrag(D_80128180.unk0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B60C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B62CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B71F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7448.s")

void func_800B798C(s32 coordX, s32 coordY, char* text)
{
    UNKTEXTSTRUCT* textStruct;

    if (text != 0)
    {
        if (D_80128180.unk0 == NULL)
        {
            D_80128180.unk0 = vector_new(sizeof(UNKTEXTSTRUCT), 8U);
        }
        textStruct = vector_push_back(&D_80128180);
        textStruct->coordX = coordX;
        textStruct->coordY = coordY;
        textStruct->text = text;
        textStruct->unk6_4 = D_80128180.unk11;
        textStruct->unk6_3 = D_80128180.unk12;
        textStruct->unk6_2 = D_80128180.unk10;
        textStruct->unk6_1 = D_80128180.unk13;
        textStruct->unk4 = D_80128180.unk14;
        textStruct->unk8 = D_80128180.unk18;
        textStruct->unk10 = D_80128180.unkC;
        textStruct->unk11 = D_80128180.unkD;
        textStruct->unk12 = D_80128180.unkE;
        textStruct->unk13 = D_80128180.unkF;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7A98.s")

void func_800B7ADC(s32 arg0) {
    D_80128180.unkF = arg0;
}

void func_800B7AE8(s32 arg0) {
    if (arg0 != 0) {
        D_80128180.unk10 = 1;
    }
    else {
        D_80128180.unk10 = 0;
    }
    if (arg0 != 0) {
        func_800B7B68(1);
    }
}

void func_800B7B2C(s32 arg0) {
    D_80128180.unk14 = arg0;
}

void func_800B7B38(s32 arg0) {
    D_80128180.unk11 = arg0;
}

void func_800B7B44(s32 arg0)
{
    if (arg0 != 0)
    {
        D_80128180.unk13 = 1;
        return;
    }
    D_80128180.unk13 = 0;
}

void func_800B7B68(s32 arg0)
{
    if (arg0 != 0)
    {
        D_80128180.unk12 = 1;
        return;
    }
    D_80128180.unk12 = 0;
}

//Set Text Colors
void func_800B7B8C(s32 arg0, s32 arg1, s32 arg2) {
    D_80128180.unkC = arg0;
    D_80128180.unkD = arg1;
    D_80128180.unkE = arg2;
}

void func_800B7BA4(f32 arg0) {
    D_80128180.unk18 = arg0;
}

void func_800B7BB0(void) {
    if (D_801282B0[0] != 0) {
        _fxleaves_entrypoint_1(D_801282B0[0]);
    }
    if (D_801282B0[1] != 0) {
        _fxrain_entrypoint_1(D_801282B0[1]);
    }
    if (D_80127128 != 0) {
        func_800B956C();
    }
}

s32 func_800B7C10(void)
{
    if (D_801282B0[0] == 0) {
        D_801282B0[0] = _fxleaves_entrypoint_4(0x32);
    }
    return D_801282B0[0];
}

s32 func_800B7C54(void) {
    if (D_801282B0[1] == 0) {
        D_801282B0[1] = _fxrain_entrypoint_5(0x1E);
    }
    return D_801282B0[1];
}

s32 func_800B7C98()
{
    return D_801282B0[1];
}

void func_800B7CA4()
{
    func_800B9038();
}

void func_800B7CC4(void) {
    if (D_801282B0[0] != 0) {
        _fxleaves_entrypoint_3(D_801282B0[0]);
    }
    if (D_801282B0[1] != 0) {
        _fxrain_entrypoint_4(D_801282B0[1]);
    }
    func_800B8FEC();
}

void func_800B7D14(void) {
    D_801282B0[0] = 0;
    D_801282B0[1] = 0;
}

void func_800B7D28(void) {
    if (D_801282B0[0] != 0) {
        _fxleaves_entrypoint_5(D_801282B0[0]);
    }
    if (D_801282B0[1] != 0) {
        _fxrain_entrypoint_7(D_801282B0[1]);
    }
    func_800B90C8();
}

void func_800B7D78(void) {
    if (D_801282B0[0] != 0) {
        _fxleaves_entrypoint_6(D_801282B0[0]);
    }
    if (D_801282B0[1] != 0) {
        _fxrain_entrypoint_8(D_801282B0[1]);
    }
    func_800B90E8();
}

void func_800B7DC8(void) {
    if (D_801282B0[0] != 0) {
        _fxleaves_entrypoint_0(D_801282B0[0]);
        _fxleaves_entrypoint_6(D_801282B0[0]);
    }
    if (D_801282B0[1] != 0) {
        _fxrain_entrypoint_0(D_801282B0[1]);
        _fxrain_entrypoint_8(D_801282B0[1]);
    }
    func_800B8FE0();
    func_800B90E8();
}

void func_800B7E38(void)
{
    if (D_801282B0[0] != 0) {
        _fxleaves_entrypoint_7(D_801282B0[0]);
    }
    if (D_801282B0[1] != 0) {
        _fxrain_entrypoint_9(D_801282B0[1]);
    }
    if (D_80127128 != 0) {
        func_800B9170();
    }
}