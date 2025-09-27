#include "ch/warppad.h"

extern u8 D_8012762C;

extern u32 D_808012FC_chwarppad;
extern f32 D_8080134C_chwarppad[3];
extern u8 D_80801080_chwarppad[0x20];
extern D_808010A0 D_808010A0_chwarppad[4];
extern D_808010B0 D_808010B0_chwarppad[31];
extern u32 D_80801344_chwarppad;

u32* chwarppad_entrypoint_0(void) {
    return &D_808012FC_chwarppad;
}

void func_8080000C_chwarppad(Actor* arg0, u32 arg1)
{
    OptionState* temp_v0;

    if (func_800EB854() == 3)
    {
        temp_v0 = (OptionState*)func_80100094(arg0, 0U);
        if (temp_v0 != NULL)
        {
            _gcnewoption_entrypoint_1(temp_v0, arg1);
        }
    }
    else
    {
        func_80101870(arg0, arg1);
    }
}

s32 func_80800064_chwarppad(Actor* arg0, s32 arg1)
{
    if ((arg0->unk74_7 == (arg1 + 0x32)))
    {
        return 0;
    }
    return func_800DA298((*(s32*)&arg0->unk2C * 5) + arg1 + 0x3AB);
}

s32 func_808000B4_chwarppad(Actor* arg0)
{
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    if (*(s32*)&arg0->unk18[1] > 0)
    {
        do {
            if (func_80800064_chwarppad(arg0, var_s0) != 0)
            {
                var_s1 += 1;
            }
            var_s0 += 1;
        } while (*(s32*)&arg0->unk18[1] >= var_s0);
    }
    return var_s1;
}

void func_80800124_chwarppad(Actor* arg0, OptionState* arg1)
{
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    _gcnewoption_entrypoint_32(arg1, 0x6F);
    var_s0 = 1;
    if (*(s32*)&arg0->unk18[1] > 0)
    {
        do {
            if (func_80800064_chwarppad(arg0, var_s0) != 0)
            {
                _gcnewoption_entrypoint_31(arg1, var_s1, (s16)(&D_808010B0_chwarppad[*(s32*)&arg0->unk28])[var_s0].unk5);
                var_s1 += 1;
            }
            var_s0 += 1;
        } while (*(s32*)&arg0->unk18[1] >= var_s0);
    }
}

void func_808001F4_chwarppad(Actor* arg0, OptionState* arg1)
{
    s32 var_s0;
    u32 var_s1 = 0;

    for (var_s0 = 1; *(s32*)&arg0->unk18[1] >= var_s0; var_s0++)
    {
        if (func_80800064_chwarppad(arg0, var_s0) != 0)
        {
            _gcnewoption_entrypoint_12(arg1, var_s1, (var_s0 + 9));
            if (func_80090178(D_808010B0_chwarppad[*(s32*)&arg0->unk28 + var_s0].unk8) != 0)
            {
                _gcnewoption_entrypoint_23(arg1, var_s1);
                _gcnewoption_entrypoint_13(arg1, var_s1, &D_80801344_chwarppad);
            }
            var_s1++;
        }
    }
}

s32 func_808002F4_chwarppad(Actor* arg0, s32 arg1)
{
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    for (var_s0 = 1; *(s32*)&arg0->unk18[1] >= var_s0; var_s0++)
    {
        if (func_80800064_chwarppad(arg0, var_s0) != 0)
        {
            if (var_s1 == arg1)
            {
                return var_s0;
            }
            var_s1 += 1;
        }
    }
    return -1;
}

s32 func_80800380_chwarppad(Actor* arg0)
{
    return func_800DA298((*(s32*)&arg0->unk2C) * 5 + (arg0->unk74_7) + 0x379);
}

void func_808003B8_chwarppad(Actor* arg0)
{
    func_800DA544((*(s32*)&arg0->unk2C * 5) + (arg0->unk74_7) + 0x379);
    _subaddiefade_entrypoint_4(arg0);
    _chappearfx_entrypoint_1(arg0, 2, 3, 0.8f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/warppad/func_80800418_chwarppad.s")

s16 func_808006C0_chwarppad(s32 arg0)
{
    s32 temp_v0;
    u32 temp_a2;
    s32 var_a1;

    temp_a2 = D_8012762C;
    //Get Transformation
    temp_v0 = func_8008FD48();
    for (var_a1 = 0; D_808010A0_chwarppad[var_a1].unk2 != 0; var_a1++)
    {
        if ((temp_a2 == D_808010A0_chwarppad[var_a1].unk2) && (temp_v0 == D_808010A0_chwarppad[var_a1].unk3))
        {
            return D_808010A0_chwarppad[var_a1].unk0;
        }
    }
    return D_808010A0_chwarppad[var_a1].unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/warppad/func_80800748_chwarppad.s")

s32 func_80800A1C_chwarppad(Actor* arg0, u32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x91:
        arg0->unk64_19 = 1;
    case 0x95:
        break;
    case 0x2E:
        func_80800AB8_chwarppad(arg0, *(s16*)&arg2, *((s16*)&arg2 + 1));
        break;
    case 0x20:
        func_80800B34_chwarppad(arg0, (OptionState*)func_80101080(), *(s16*)&arg2, *((s16*)&arg2 + 1));
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800AB8_chwarppad(Actor* arg0, s32 arg1, s32 arg2)
{
    func_80801018_chwarppad(arg0);
}

u8 func_80800ADC_chwarppad(s32 arg0)
{
    s32 temp_v0;
    u8 var_a0;
    u32 var_v1 = 0;
    //Get Transformation
    temp_v0 = func_8008FD48();
    var_a0 = D_80801080_chwarppad[0];
    for (var_v1 = 0; D_80801080_chwarppad[var_v1] != 0; var_v1 += 2)
    {
        if (temp_v0 == D_80801080_chwarppad[var_v1])
        {
            return D_80801080_chwarppad[var_v1 + 1];
        }
    }
    return 0;
}

void func_80800B34_chwarppad(Actor* arg0, OptionState* arg1, s32 arg2, s32 arg3)
{
    u32 sp24;
    u32 temp_v0;
    switch (arg3)
    {
    case 3:
        sp24 = func_808002F4_chwarppad(arg0, arg2);
        if (_gcnewoption_entrypoint_19(arg1, arg2) != 0)
        {
            temp_v0 = func_80800ADC_chwarppad((s32)arg0);
            if (temp_v0 != 0)
            {
                _gcnewoption_entrypoint_34(arg1, temp_v0);
            }
        }
        else
        {
            arg0->unk30 = sp24;
            func_80800418_chwarppad(arg0, 4);
        }

        break;
    case 0:
        func_808001F4_chwarppad(arg0, arg1);
        break;
    case 2:
        func_800C78CC(0);
        func_80800418_chwarppad(arg0, 1);
        func_80801018_chwarppad(arg0);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/warppad/func_80800C00_chwarppad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/warppad/func_80800E10_chwarppad.s")

void func_80800EF8_chwarppad(Actor* arg0)
{
    if (func_80100094(arg0, 0) != 0)
    {
        _gcnewoption_entrypoint_6(arg0, 0);
    }
    func_80801018_chwarppad(arg0);
}

void func_80800F34_chwarppad(Actor* arg0, s32 arg1, s32 arg2)
{
    f32 sp2C[3];
    f32* var_a1;

    if (!(arg0->unk64_20))
    {
        func_800EFA4C(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
        _capod_entrypoint_2(arg0->unk0, 0x1AU, 0);
        _capod_entrypoint_8(1);
        _capod_entrypoint_9(0, &D_8080134C_chwarppad);
        _capod_entrypoint_10(0, arg0->position);

        if (arg1 == 4)
        {
            var_a1 = sp2C;
        }
        else
        {
            var_a1 = arg0->rotation;
        }
        _capod_entrypoint_11(0, var_a1);
        _gcdialogcamera_entrypoint_8();
        arg0->unk64_20 = 1;
        _subaddieDll_entrypoint_4(arg0, 1);
    }
    _capod_entrypoint_7(arg1, arg2);
}

void func_80801018_chwarppad(Actor* arg0)
{
    if (arg0->unk64_20)
    {
        _capod_entrypoint_3(0);
        arg0->unk64_20 = 0;
        _subaddieDll_entrypoint_4(arg0, 0U);
    }
}