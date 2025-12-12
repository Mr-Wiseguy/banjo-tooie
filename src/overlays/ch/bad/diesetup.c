#include "ch/baddiesetup.h"

s32 func_80800000_chbaddiesetup(D_80127110_Data* arg0)
{
    if (arg0->unk0 == 0)
    {
        return 0;
    }
    if (arg0->unk4 == 0x16)
    {
        return 0;
    }
    return 1;
}

void chbaddiesetup_entrypoint_0(s32 arg0)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = arg0;
        temp_v0->unk0[temp_v0->unk4].unk1C = 0;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_1(s32 arg0, s32 arg1)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = arg0;
        temp_v0->unk0[temp_v0->unk4].unk4 = arg1;
        temp_v0->unk0[temp_v0->unk4].unk1C = 1;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_2(s32 arg0, s32 arg1, s32 arg2)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = arg0;
        temp_v0->unk0[temp_v0->unk4].unk4 = arg1;
        temp_v0->unk0[temp_v0->unk4].unk8 = arg2;
        temp_v0->unk0[temp_v0->unk4].unk1C = 2;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = arg0;
        temp_v0->unk0[temp_v0->unk4].unk4 = arg1;
        temp_v0->unk0[temp_v0->unk4].unk8 = arg2;
        temp_v0->unk0[temp_v0->unk4].unkC = arg3;
        temp_v0->unk0[temp_v0->unk4].unk1C = 3;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = arg0;
        temp_v0->unk0[temp_v0->unk4].unk4 = arg1;
        temp_v0->unk0[temp_v0->unk4].unk8 = arg2;
        temp_v0->unk0[temp_v0->unk4].unkC = arg3;
        temp_v0->unk0[temp_v0->unk4].unk10 = arg4;
        temp_v0->unk0[temp_v0->unk4].unk1C = 4;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_5(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = arg0;
        temp_v0->unk0[temp_v0->unk4].unk4 = arg1;
        temp_v0->unk0[temp_v0->unk4].unk8 = arg2;
        temp_v0->unk0[temp_v0->unk4].unkC = arg3;
        temp_v0->unk0[temp_v0->unk4].unk10 = arg4;
        temp_v0->unk0[temp_v0->unk4].unk14 = arg5;
        temp_v0->unk0[temp_v0->unk4].unk1C = 5;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_6(void* callback, s32 arg1, s32 x, s32 y, s32 z, s32 arg5, s32 arg6)
{
    D_80127110_Data* temp_v0;

    temp_v0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(temp_v0) != 0)
    {
        temp_v0->unk0[temp_v0->unk4].unk0 = callback;
        temp_v0->unk0[temp_v0->unk4].unk4 = arg1;
        temp_v0->unk0[temp_v0->unk4].unk8 = x;
        temp_v0->unk0[temp_v0->unk4].unkC = y;
        temp_v0->unk0[temp_v0->unk4].unk10 = z;
        temp_v0->unk0[temp_v0->unk4].unk14 = arg5; 
        temp_v0->unk0[temp_v0->unk4].unk18 = arg6;
        temp_v0->unk0[temp_v0->unk4].unk1C = 6;
        temp_v0->unk4 += 1;
    }
}

void chbaddiesetup_entrypoint_7(u32 arg0, Vec3f arg1)
{
    f32 sp1C[3];
    if (&arg0) {}
    sp1C[0] = arg1.pos.x;
    sp1C[1] = arg1.pos.y;
    sp1C[2] = arg1.pos.z;

    func_80108474(arg0, sp1C, 0);
}

void chbaddiesetup_entrypoint_8(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 sp1C[4];

    sp1C[1] = arg1;
    sp1C[2] = arg2;
    sp1C[4] = arg0;
    sp1C[7] = arg3;
    sp1C[3] = arg3;

    func_80108454(arg0, sp1C + 1, 0);
}

void chbaddiesetup_entrypoint_9(s32 arg0, Vec3f arg1)
{
    f32 sp1C[3];
    if (&arg0) {}
    sp1C[0] = arg1.pos.x;
    sp1C[1] = arg1.pos.y;
    sp1C[2] = arg1.pos.z;
    _chbounce_entrypoint_6(arg0, sp1C);
}

void chbaddiesetup_entrypoint_10(s32 arg0, Vec3f arg1, f32 arg2)
{
    f32 sp1C[3];

    sp1C[0] = arg1.pos.x;
    sp1C[1] = arg1.pos.y;
    sp1C[2] = arg1.pos.z;
    _chbounce_entrypoint_2(arg2);
    _chbounce_entrypoint_6(arg0, sp1C);
}