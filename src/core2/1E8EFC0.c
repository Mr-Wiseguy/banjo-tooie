#include "core2/1E8EFC0.h"

typedef struct UNKD_80127F28 {
    f32 unk0;
    u32 unk4;
    u32 unk8_31 : 1;
    u32 unk8_21 : 10;
    u32 unk8_0 : 21;
}UNKD_80127F28;
extern UNKD_80127F28 D_80127F28[];
extern u8 D_80127F20;

s32 func_800B56D0(u8 arg0)
{
    if (D_80127F28[arg0].unk4 == 0)
    {
        D_80127F20 = arg0;
        D_80127F28[arg0].unk4 = func_800B53A4(D_80127F28[arg0].unk8_21);
        func_800B5534(D_80127F28[arg0].unk4);
        D_80127F20 = 0;
    }
    D_80127F28[arg0].unk0 = 1.0f;
    return D_80127F28[arg0].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8EFC0/func_800B5758.s")

void func_800B5824(void)
{
    int index;
    for (index = 1; index < 0x2D; index++)
    {
        if (D_80127F28[index].unk8_31 != 0)
        {
            func_800B58D4(index);
        }
    }
}

void func_800B5884(void)
{
    int index;
    for (index = 1; index < 0x2D; index++)
    {
        D_80127F28[index].unk8_31 = 0;
    }
}

void func_800B58D4(u8 arg0)
{
    if (D_80127F28[arg0].unk4 != 0)
    {
        func_800B5450(D_80127F28[arg0].unk4);
    }
    D_80127F28[arg0].unk8_31 = 0;
}

void func_800B592C(void)
{
    int index;
    f32 temp_f20;
    s32 temp_a0;
    temp_f20 = time_getDelta();
    for (index = 1; index < 0x2D; index++)
    {
        if (D_80127F28[index].unk8_31 != 0)
        {
            temp_a0 = D_80127F28[index].unk4;
            if ((temp_a0 != 0) && (func_800BA28C(temp_a0) != 0))
            {
                D_80127F28[index].unk0 = (f32)(D_80127F28[index].unk0 - temp_f20);
                if (D_80127F28[index].unk0 <= 0.0f) {
                    func_800B5450(D_80127F28[index].unk4);
                    D_80127F28[index].unk4 = 0U;
                }
            }
        }
    }
}

void func_800B59E0(void)
{
    int index;
    for (index = 1; index < 0x2D; index++)
    {
        if (D_80127F28[index].unk8_31 != 0)
        {
            if ((D_80127F28[index].unk4 != 0) && (index != D_80127F20))
            {
                func_800B5450(D_80127F28[index].unk4);
                D_80127F28[index].unk4 = 0U;
            }
        }
    }
}

void func_800B5A6C(void)
{
    s32 temp_a0;
    int index;
    for (index = 1; index < 0x2D; index++)
    {
        if (D_80127F28[index].unk8_31 != 0)
        {
            temp_a0 = D_80127F28[index].unk4;
            if (temp_a0 != 0)
            {
                D_80127F28[index].unk4 = func_800B5548(temp_a0);
            }
        }
    }
}

void func_800B5AD4(void)
{
    _fxsparkle_entrypoint_2();
    func_800B4428();
    func_800B5B40();
}

void func_800B5B04(void)
{
    func_800B5B88();
    _fxsparkle_entrypoint_3();
    func_800B43E0();
}