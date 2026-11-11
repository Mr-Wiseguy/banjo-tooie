#include "core2/1E9F060.h"

extern f32 D_801258AC;

void func_800C5770(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C57C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C57F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C59F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5A38.s")

void func_800C5B84(UNKfunc_800C68A0_ARG0* arg0)
{
	func_800C5A10(arg0, 1);
}

void func_800C5BA4(UNKfunc_800C68A0_ARG0* arg0)
{
    heap_free(arg0);
}
void* func_800C5BC4(UNKfunc_800C68A0_ARG0* arg0)
{
    return defrag(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5BE4.s")

void* func_800C5CC0(f32* this, f32 arg1, f32 arg2, u32 arg3, void* arg4) {
    void* phi_v1;

    if (mlAbsF(arg2 - arg1) > 500.0f) {
        if (arg1 < arg2) {
            phi_v1 = func_800C5BE4(this, arg1, arg1 + 500.0f, arg3, arg4);
            if (phi_v1 == NULL) {
                phi_v1 = func_800C5BE4(this, arg1 + 500.0f - 1.0f, arg2, arg3, arg4);
            }
        }
        else {
            phi_v1 = func_800C5BE4(this, arg1, arg1 - 500.0f, arg3, arg4);
            if (phi_v1 == NULL) {
                phi_v1 = func_800C5BE4(this, arg1 - 500.0f + 1.0f, arg2, arg3, arg4);
            }
        }
    }
    else {
        phi_v1 = func_800C5BE4(this, arg1, arg2, arg3, arg4);
    }
    return phi_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6420.s")

void func_800C65E0(UNKfunc_800C68A0_ARG0* arg0) {
    s32 pad[3];
    s32 sp48;
    s32 sp3C[3];
    f32* temp_v0;

    arg0->unk90 = arg0->unk8E;
    arg0->unk91 = arg0->unk8F;
    arg0->unk8F = 0U;
    arg0->unk8E = 0U;

    if (((arg0->unk94 & 0xFF) == 1) || (arg0->unk93))
    {
        arg0->unk93--;
        temp_v0 = func_800C5BE4(arg0->unk4C, -100.0f, 7000.0f, arg0->unk88, &sp3C);
        if (temp_v0 != NULL)
        {
            func_800C5FCC(arg0, sp48, temp_v0);
        }
        if (temp_v0 != NULL)
        {
            temp_v0 = func_800C5A10(arg0, 3);
        }
        else
        {
            temp_v0 = func_800C5A10(arg0, 2);
        }
    }
    switch (arg0->unk94)
    {
    case 2:
        func_800C6060(arg0);
        break;
    case 3:
        func_800C6320(arg0);
        break;
    case 4:
        func_800C6420(arg0);
        break;
    }
    ml_vec3f_copy(arg0->unk58, arg0->unk4C);
}

s32 func_800C6704(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk8E;
}

s32 func_800C670C(UNKfunc_800C68A0_ARG0* arg0)
{
    if (D_801258AC == arg0->unk74)
    {
        return 0;
    }
    return arg0->unk8F;
}


f32 func_800C673C(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk78;
}

s32 func_800C6744(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk7C;
}

s32 func_800C674C(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk8C;
}

s32 func_800C6754(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk95;
}

void func_800C675C(UNKfunc_800C68A0_ARG0* arg0, f32* arg1) {
    ml_vec3f_copy(arg1, arg0->unk64);
}

f32 func_800C6784(UNKfunc_800C68A0_ARG0* arg0)
{
    f32 temp_f2;

    if (arg0->unk95 != 0)
    {
        temp_f2 = arg0->unk74 - 15.0f;
        if (arg0->unk70 < temp_f2)
        {
            return temp_f2;
        }
    }
    return arg0->unk70;
}

s32 func_800C67C8(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk0;
}

s32 func_800C67D0(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk9C;
}

f32 func_800C67D8(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk74;
}

s32 func_800C67E0(UNKfunc_800C68A0_ARG0* arg0) {
    return arg0->unk80;
}

void* func_800C67E8(UNKfunc_800C68A0_ARG0* arg0) {
    return &arg0->unk10;
}

s32 func_800C67F0(UNKfunc_800C68A0_ARG0* arg0) {
    return &arg0->unk4;
}

void func_800C67F8(UNKfunc_800C68A0_ARG0* arg0, u8 arg1[2][4])
{
    s32 var_v0;
    for (var_v0 = 0; var_v0 < 3; var_v0++)
    {
        arg1[var_v0][0] = arg0->unk40[var_v0][0];
        arg1[var_v0][1] = arg0->unk40[var_v0][1];
        arg1[var_v0][2] = arg0->unk40[var_v0][2];
        arg1[var_v0][3] = arg0->unk40[var_v0][3];
    }
}

void func_800C6840(UNKfunc_800C68A0_ARG0* arg0, f32 arg1[3][3])
{
    s32 index;
    for (index = 0; index < 3; index++)
    {
        ml_vec3f_copy(arg1[index], arg0->unk1C[index]);
    }
}

void func_800C68A0(UNKfunc_800C68A0_ARG0* arg0, f32 arg1) {
    arg0->unk78 = arg1;
}

void func_800C68AC(UNKfunc_800C68A0_ARG0* arg0, f32* arg1) {
    ml_vec3f_copy(arg0->unk4C, arg1);
}

void func_800C68CC(UNKfunc_800C68A0_ARG0* arg0, s32 arg1) {
    arg0->unk84 = arg1;
}
void func_800C68D4(UNKfunc_800C68A0_ARG0* arg0, s32 arg1) {
    arg0->unk95 = arg1;
}

void func_800C68DC(UNKfunc_800C68A0_ARG0* arg0) {
    arg0->unk93 = 1;
}

void func_800C68E8(UNKfunc_800C68A0_ARG0* arg0, s32 arg1, f32 arg2)
{
    if ((arg0->unk9C != 0) && (arg1 == 0))
    {
        arg0->unk93 = 1;
    }
    if (arg1 != 0)
    {
        arg0->unk98 = arg2;
    }
    arg0->unk9C = arg1;
}
