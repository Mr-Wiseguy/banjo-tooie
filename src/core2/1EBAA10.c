#include "core2/1EBAA10.h"

extern u8 D_8012D004;

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    s32 unk34[3];
    u8 pad40[0x30];
    s8 unk70;
    s8 unk71;
    s8 unk72;
    s8 unk73;
    u8 unk74;
    u8 unk75;
    s8 unk76;
    u8 unk77;
    u8 unk78;
    s8 unk79;
    s8 unk7A;
    s8 unk7B;
} UNKD_8012CF90;

extern UNKD_8012CF90 D_8012CF90[];

//ml_translate_y_local
void func_800E1120(f32 dst[3], f32 src[3], f32 dy) {
    f32 vec[3];

    ml_vec3f_assign_value(vec, 0.0f, dy, 0.0f);
    func_800EF8BC(vec, vec, src[0]);
    func_800EF934(vec, vec, src[1]);
    ml_vec3f_add(dst, vec);
}

//ml_translate_z_local
void func_800E119C(f32 dst[3], f32 src[3], f32 dz) {
    f32 vec[3];

    ml_vec3f_assign_value(vec, 0.0f, 0.0f, dz);
    func_800EF8BC(vec, vec, src[0]);
    func_800EF934(vec, vec, src[1]);
    ml_vec3f_add(dst, vec);
}

//ml_translate_x_local
void func_800E1218(f32 dst[3], f32 src[3], f32 dx) {
    f32 vec[3];

    ml_vec3f_assign_value(vec, dx, 0.0f, 0.0f);
    func_800EF8BC(vec, vec, src[0]);
    func_800EF934(vec, vec, src[1]);
    ml_vec3f_add(dst, vec);
}

void func_800E1294(s32 arg0, f32 position[3], f32 rotation[3], f32 delta)
{
    switch (arg0) {
    case 1:
        func_800E1218(position, rotation, delta);
        return;
    case 0:
        func_800E1120(position, rotation, delta);
        return;
    case 2:
        func_800E119C(position, rotation, delta);
        return;
    case 3:
        position[1] += delta;
        return;
    }
}

f32 func_800E1338(s32 arg0)
{
    return D_8012CF90[arg0].unk28;
}

s32 func_800E1354(s32 arg0)
{
    return D_8012CF90[arg0].unk74 != 1;
}

void func_800E1378(s32 arg0)
{
    func_800E13F0(arg0, 30.0f);
    func_800E144C(arg0, 0.65f);
    func_800E148C(arg0, 1000.0f, 2000.0f);
    if (func_800EA068(0x20) != 0)
    {
        func_800E146C(arg0, 0.0f);
        return;
    }
    func_800E146C(arg0, 0.5f);
}

void func_800E13F0(s32 arg0, f32 arg1)
{
    D_8012CF90[arg0].unk28 = arg1;
}

void func_800E1410(s32 arg0, f32 arg1, f32 arg2)
{
    D_8012CF90[arg0].unk24 = D_8012CF90[arg0].unk28;
    D_8012CF90[arg0].unk20 = (arg1 + D_8012CF90[arg0].unk28);
    D_8012CF90[arg0].unk30 = arg2;
    D_8012CF90[arg0].unk18 = arg2;
}

void func_800E144C(s32 arg0, f32 arg1)
{
    D_8012CF90[arg0].unk1C = arg1;
}

void func_800E146C(s32 arg0, f32 arg1)
{
    D_8012CF90[arg0].unk14 = arg1;
}

void func_800E148C(s32 arg0, f32 arg1, f32 arg2)
{
    D_8012CF90[arg0].unkC = arg1;
    D_8012CF90[arg0].unk10 = arg2;
}

void func_800E14B8(s32 arg0, f32* arg1)
{
    ml_vec3f_copy(D_8012CF90[arg0].unk0, arg1);
    D_8012CF90[arg0].unk76 = 1;
}

void func_800E14F8(s32 arg0, void* arg1, s32 arg2)
{
    UNKD_8012CF90* obj;
    s16 num;

    obj = &D_8012CF90[arg0];
    num = ((s16*)&arg2)[1];

    obj->unk78 = num;
    rare_memcpy(obj->unk34, arg1, 8 * num);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1540.s")

s32 func_800E15CC(s32 arg0, f32 arg1, f32 arg2)
{
    s32 temp_v0;

    temp_v0 = func_800E1540(arg0);
    func_800E13F0(temp_v0, arg1);
    func_800E144C(temp_v0, arg2);
    return temp_v0;
}

s32 func_800E1610(s32 arg0, f32 arg1, f32 arg2, f32* arg3)
{
    s32 temp_v0;

    temp_v0 = func_800E1540(arg0);
    func_800E13F0(temp_v0, arg1);
    func_800E144C(temp_v0, arg2);
    func_800E14B8(temp_v0, arg3);
    return temp_v0;
}

s32 func_800E1664(s32 arg0, f32 arg1, f32 arg2, f32* arg3, void* arg4, s16 arg5)
{
    s32 temp_v0;

    temp_v0 = func_800E1540(arg0);
    func_800E14F8(temp_v0, arg4, (s32)arg5);
    D_8012CF90[temp_v0].unk74 = 4;
    D_8012CF90[temp_v0].unk20 = arg1;
    D_8012CF90[temp_v0].unk30 = 0.0f;
    D_8012CF90[temp_v0].unk18 = arg2;
    if (arg1 >= 0.0f)
    {
        D_8012CF90[temp_v0].unk2C = 1.0f;
    }
    else
    {
        D_8012CF90[temp_v0].unk2C = -1.0f;
    }
    if (arg3 != NULL)
    {
        func_800E14B8(temp_v0, arg3);
    }
    return temp_v0;
}

void func_800E1720(s32 arg0)
{
    D_8012CF90[arg0].unk74 = 1;
    D_8012CF90[arg0].unk76 = 0;
}

void func_800E1748(void)
{
    s32 var_s0;
    for (var_s0 = 0; var_s0 < 0xA; var_s0++)
    {
        func_800E1720(var_s0);
    }
}

void func_800E1788(void)
{
    s32 var_s0;
    for (var_s0 = 0; var_s0 < 0xA; var_s0++)
    {
        D_8012CF90[var_s0].unk74 = 1;
        D_8012CF90[var_s0].unk30 = 0.0f;
        D_8012CF90[var_s0].unk76 = 0;
        ml_vec3f_clear(D_8012CF90[var_s0].unk0);
        func_800E1378(var_s0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1A58.s")
