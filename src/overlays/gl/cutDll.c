#include "gl/cutDll.h"
#include "common.h"

typedef struct
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
} CutsceneInformation;

extern CutsceneInformation D_801275E8;
extern u8 D_8012762C;
void glcutDll_entrypoint_16(void);
void glcutDll_entrypoint_11(u32 arg0);
void glcutDll_entrypoint_10(u32 arg0);
void glcutDll_entrypoint_7(u32 arg0);

void func_80800000_glcutDll(u32 arg0)
{
    D_801275E8.unk6 = arg0;
}

void func_8080000C_glcutDll(u32 arg0)
{
    D_801275E8.unk9 = arg0;
}

void func_80800018_glcutDll(u32 arg0)
{
    switch (arg0)
    {
    case 1:
        func_8080000C_glcutDll(0U);
        func_80800000_glcutDll(0U);
        D_801275E8.unkC = 0;
        func_800FE734(0);
        break;
    case 2:
        if ((D_801275E8.unk0 != D_801275E8.unk2) || (func_800DA298(FLAG3_A52_UNK) != 0))
        {
            if (D_801275E8.unkA != 0)
            {
                func_800FE844(2);
                func_800FE734(1);
            }
            if (_gcsectionDll_entrypoint_4(D_801275E8.unk0) != D_8012762C)
            {
                func_800A8230();
            }
            func_800A7990(D_801275E8.unk0, 0, D_801275E8.unk10);
        }
        func_800DA544(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
        if ((D_801275E8.unkB == 0) && (D_801275E8.unkF == 0))
        {
            func_800C78CC(1);
            D_801275E8.unkF = 1U;
        }
        D_801275E8.unkC = 1;
        break;
    case 3:
        if ((D_801275E8.unk8 == 2) && ((D_801275E8.unk0 != D_801275E8.unk2) || (func_800DA298(FLAG3_A52_UNK) != 0)) && (D_801275E8.unk7 != 0))
        {
            func_80800000_glcutDll(1U);
            func_8080000C_glcutDll(0U);
            func_800D9290();
            func_800D9330(1);
        }
        break;
    case 4:
        if (D_801275E8.unk6 != 0)
        {
            func_800D92F4();
        }
        func_800DA524(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
        if ((D_801275E8.unkB == 0) && (D_801275E8.unkF != 0))
        {
            func_800C78CC(0);
            D_801275E8.unkF = 0U;
        }
        if (D_801275E8.unkE != 0)
        {
            func_80090708(0);
        }
        func_8080000C_glcutDll(0U);
        D_801275E8.unk4 = 0;
        func_800DA524(FLAG3_A52_UNK);
        break;
    case 5:
        if (D_801275E8.unkA != 0)
        {
            func_800FE844(2);
            func_800FE734(1);
        }
        if (_gcsectionDll_entrypoint_4(D_801275E8.unk2) != D_8012762C)
        {
            func_800A8230();
        }
        func_800A7990(D_801275E8.unk2, 0, D_801275E8.unk10);
        func_800DA524(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
        if ((D_801275E8.unkB == 0) && (D_801275E8.unkF != 0))
        {
            func_800C78CC(0);
            D_801275E8.unkF = 0U;
        }
        if (D_801275E8.unk6 != 0)
        {
            func_8080000C_glcutDll(1U);
        }
        D_801275E8.unk4 = 0;
        D_801275E8.unkD = 1;
        func_800DA524(FLAG3_A52_UNK);
        break;
    case 6:
        if (D_801275E8.unk9 != 0)
        {
            func_800D92F4();
            func_80800000_glcutDll(0U);
            func_8080000C_glcutDll(0U);
            func_800FE734(0);
        }
        if (D_801275E8.unkC != 0)
        {
            D_801275E8.unkC = 0U;
        }
        if (D_801275E8.unkD != 0)
        {
            D_801275E8.unkD = 0U;
        }
        break;
    }
    D_801275E8.unk8 = (s8)arg0;
}

void glcutDll_entrypoint_0(void)
{
    func_80800018_glcutDll(1U);
    glcutDll_entrypoint_10(func_800EA05C());
    glcutDll_entrypoint_11(1U);
    func_80800000_glcutDll(0U);
    D_801275E8.unkA = 1;
    D_801275E8.unkB = 0;
    D_801275E8.unkF = 0;
    D_801275E8.unk10 = 0;
    D_801275E8.unk4 = 0;
    D_801275E8.unkE = 0;
}

u8 glcutDll_entrypoint_1(void) 
{
    return D_801275E8.unk9;
}

void glcutDll_entrypoint_2(void) {
}

void glcutDll_entrypoint_3(void)
{
    func_800D92EC();
    func_8080000C_glcutDll(0U);
    func_80800000_glcutDll(0U);
    D_801275E8.unkA = 1;
    D_801275E8.unkB = 0;
    D_801275E8.unkF = 0;
    D_801275E8.unk10 = 0;
    D_801275E8.unkC = 0;
    D_801275E8.unkD = 0;
    D_801275E8.unk4 = 0;
    D_801275E8.unkE = 0;
    D_801275E8.unk8 = 0;
    func_80800018_glcutDll(1U);
}

void glcutDll_entrypoint_4(void)
{
    if (D_801275E8.unk8 != 1)
    {
        func_80800018_glcutDll(6);
    }
}

void glcutDll_entrypoint_5(void)
{
    if (D_801275E8.unk8 != 1)
    {
        func_80800018_glcutDll(3);
    }
}

void glcutDll_entrypoint_6(u32 arg0, u32 arg1)
{
    glcutDll_entrypoint_0();
    glcutDll_entrypoint_7(arg0);
    glcutDll_entrypoint_22(arg1);
    glcutDll_entrypoint_16();
}

//Set the Cutscene Map
void glcutDll_entrypoint_7(u32 arg0) 
{
    D_801275E8.unk0 = arg0;
}

//Return the cutscene map
s16 glcutDll_entrypoint_8(void) {
    return D_801275E8.unk0;
}

//Get the map to return to after the cutscene ends
s16 glcutDll_entrypoint_9(void) {
    return  D_801275E8.unk2;
}

//Set the cutscene return map
void glcutDll_entrypoint_10(u32 arg0)
{
    D_801275E8.unk2 = arg0;
}

void glcutDll_entrypoint_11(u32 arg0) 
{
    D_801275E8.unk7 = arg0;
}

void glcutDll_entrypoint_12(s32 arg0)
{
    if (arg0 != 0)
    {
        D_801275E8.unkA = 0;
        return;
    }
    D_801275E8.unkA = 1;
}

void glcutDll_entrypoint_13(s32 arg0)
{
    if (arg0 != 0)
    {
        D_801275E8.unkB = 0;
        return;
    }
    D_801275E8.unkB = 1;
}

void glcutDll_entrypoint_14(u32 arg0)
{
    D_801275E8.unk10 = arg0;
}

void glcutDll_entrypoint_15(u32 arg0)
{
    D_801275E8.unkE = arg0;
}

void glcutDll_entrypoint_16(void)
{
    func_80800018_glcutDll(2);
}

void glcutDll_entrypoint_17(void)
{
    if (func_800EA05C() == D_801275E8.unk2)
    {
        func_80800018_glcutDll(4U);
        func_80800018_glcutDll(1U);
        return;
    }
    func_80800018_glcutDll(5U);
}

s16 glcutDll_entrypoint_18(void) 
{
    return D_801275E8.unk4;
}

u32 glcutDll_entrypoint_19(s32 arg0)
{
    u32 var_v0;

    var_v0 = arg0 == D_801275E8.unk4;
    if (var_v0)
    {
        return func_800DB9B0() != 0;
    }
}

s32 glcutDll_entrypoint_20(void)
{
    s16 temp_v0;

    if (func_800DB9B0() == 0)
    {
        return 0;
    }
    temp_v0 = D_801275E8.unk4;
    if (temp_v0 == 0x8C) {
        return 1;
    }
    if (temp_v0 == 0x8A) {
        return 1;
    }
    return 0;
}

void glcutDll_entrypoint_21(void)
{
    func_800DA544(FLAG3_A52_UNK);
}

void glcutDll_entrypoint_22(u32 arg0)
{
    D_801275E8.unk4 = arg0;
}

s32 glcutDll_entrypoint_23(void)
{
    if ((D_801275E8.unk0 != D_801275E8.unk2) && (func_800EA05C() == D_801275E8.unk0))
    {
        return 1;
    }
    return 0;
}

void glcutDll_entrypoint_24(u32 arg0, u32 arg1, u32 arg2)
{
    u32 sp2C;
    u32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp2C = (u32)D_801275E8.unk2;
    sp28 = (u32)D_801275E8.unk4;
    sp24 = (s32)D_801275E8.unkA;
    sp20 = (s32)D_801275E8.unkB;
    sp1C = (s32)D_801275E8.unk10;
    sp18 = (s32)D_801275E8.unkF;
    glcutDll_entrypoint_0();
    glcutDll_entrypoint_11(0U);
    D_801275E8.unkA = (u8)sp24;
    D_801275E8.unkB = (u8)sp20;
    D_801275E8.unk10 = (u8)sp1C;
    D_801275E8.unkF = (u8)sp18;
    if (arg2 == -1U) {
        glcutDll_entrypoint_22(sp28);
    }
    else {
        glcutDll_entrypoint_22(arg2);
    }
    glcutDll_entrypoint_7(arg0);
    if (arg1 == -1U) {
        glcutDll_entrypoint_10(sp2C);
    }
    else {
        glcutDll_entrypoint_10(arg1);
    }
    glcutDll_entrypoint_16();
    func_80800000_glcutDll(1U);
}
