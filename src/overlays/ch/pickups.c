#include "ch/pickups.h"
#define PICKUPS_DATA(arg0) ((PickupsData*)(arg0->actorData))

extern s32 D_80800790_chpickups;
extern s32 D_808007D8_chpickups;
extern s32 D_80800820_chpickups;
extern s32 D_80800868_chpickups;
extern s32 D_808008B0_chpickups;
extern s32 D_808008F8_chpickups;
extern s32 D_80800940_chpickups;
extern s32 D_80800988_chpickups;
extern s32 D_808009D0_chpickups;
extern s32 D_80800A18_chpickups;
extern s32 D_80800A60_chpickups;
extern s32 D_80800AA8_chpickups;
extern s32 D_80800AB8_chpickups;

s32* chpickups_entrypoint_0(void)
{
    return &D_80800790_chpickups;
}

s32* chpickups_entrypoint_1(void)
{
    return &D_808007D8_chpickups;
}

s32* chpickups_entrypoint_2(void)
{
    return &D_80800820_chpickups;
}

s32* chpickups_entrypoint_3(void)
{
    return &D_80800868_chpickups;
}

s32* chpickups_entrypoint_4(void)
{
    return &D_808008B0_chpickups;
}

s32* chpickups_entrypoint_5(void)
{
    return &D_808008F8_chpickups;
}

s32* chpickups_entrypoint_6(void)
{
    return &D_80800940_chpickups;
}

s32* chpickups_entrypoint_7(void)
{
    return &D_80800988_chpickups;
}

s32* chpickups_entrypoint_8(void)
{
    return &D_808009D0_chpickups;
}

s32* chpickups_entrypoint_9(void)
{
    return &D_80800A18_chpickups;
}

s32* chpickups_entrypoint_10(void)
{
    return &D_80800A60_chpickups;
}

s32 func_80800084_chpickups(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x3E:
        func_80800110_chpickups(arg0);
        return 1;
    case 0x95:
        if (arg0->unk64_23)
        {
            func_800F822C(func_800F54E4(), 0, 0);
            func_80101FDC(arg0, 3);
        }

        return 1;
    default:
        return 0;
    }
}

void func_80800110_chpickups(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 1:
    case 2:
        if (arg0->unk6C_9 == 0x1D9)
        {
            _fxsparkle_entrypoint_1(arg0->position, 5U);
            func_800FC6B0(0xE);
        }
        func_800F6388(func_800F54E4(), arg0->unk6C_9);
        func_800FFAB0(arg0);
    }
}

void func_808001A0_chpickups(Unk80132ED0* arg0, f32* arg1)
{
    Actor* temp_s0;
    s32 sp50[3];
    f32 temp_f0;

    f32 var_f12;
    f32 var_f16;
    f32 var_f14;

    temp_s0 = func_80106790(arg0);
    func_800EE904(sp50, arg1);
    switch (temp_s0->unk6C_9)
    {
    default:
        func_800900D0(temp_s0->unk6C_9);
        break;
    case 0x4E2:
    case 0x4B7:
    case 0x4E3:
    case 0x4E4:
    case 0x515:
    case 0x516:
        break;
    }
    func_80101FDC(temp_s0, 4U);
    func_800EE7F8(PICKUPS_DATA(temp_s0)->unk0, arg1);
    PICKUPS_DATA(temp_s0)->unk10[0] = (sp50[0] - temp_s0->position[0]);
    PICKUPS_DATA(temp_s0)->unk10[1] = 28.0f;
    PICKUPS_DATA(temp_s0)->unk10[2] = (sp50[2] - temp_s0->position[2]);
    var_f16 = 0.0f;
    var_f14 = 28.0f;
    var_f12 = temp_s0->position[1];
    while (!(var_f12 < sp50[1] && (var_f14 < 0.0f)))
    {
        temp_f0 = var_f14 - 5.0f;
        var_f14 = temp_f0;
        var_f12 += temp_f0;
        var_f16 += 1.0f;
    }
    PICKUPS_DATA(temp_s0)->unk10[0] = PICKUPS_DATA(temp_s0)->unk10[0] / var_f16;
    PICKUPS_DATA(temp_s0)->unk10[2] = PICKUPS_DATA(temp_s0)->unk10[2] / var_f16;
    func_800EF334(PICKUPS_DATA(temp_s0)->unk10, 30.0f);
    temp_s0->unk58 = var_f16 * 30.0f;
}

void func_80800344_chpickups(s32 arg0)
{
    func_80101FDC(arg0,0x2);
}

void func_80800364_chpickups(Actor* arg0)
{
    f32 var_f12;
    f32 temp_f0;

    temp_f0 = func_800D8FF8();
    var_f12 = PICKUPS_DATA(arg0)->unk0[1];
    PICKUPS_DATA(arg0)->unk10[1] -= 150.0f * (30.0f * temp_f0);
    arg0->position[0] += PICKUPS_DATA(arg0)->unk10[0] * temp_f0;
    arg0->position[1] += PICKUPS_DATA(arg0)->unk10[1] * temp_f0;
    arg0->position[2] += PICKUPS_DATA(arg0)->unk10[2] * temp_f0;
    if ((arg0->position[1] < var_f12) && (PICKUPS_DATA(arg0)->unk10[1] < 0.0f))
    {
        switch (arg0->unk6C_9)
        {
        case 0x3CA:
        case 0x3CB:
        case 0x4B7:
        case 0x4D7:
        case 0x4E2:
        case 0x4E3:
        case 0x4E4:
            break;
        case 0x481:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AA8_chpickups);
            break;
        default:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AB8_chpickups);
            break;
        }
        arg0->position[1] = var_f12;
        if (arg0->unk70_10 == 4)
        {
            if ((arg0->unk0->unk24 >> 0x16 != 0x37) && (arg0->unk0->unk24 >> 0x16 == 0x67))
            {
                func_80101180(0x4A5, 0x7D, 0);
                func_800FFAB0(arg0);
            }
        }
        arg0->unk64_22 = 0;
        arg0->unk64_23 = arg0->unk64_22;
        func_80101FDC(arg0, 2U);
    }
}

void func_80800528_chpickups(Actor* arg0)
{
    s32 pad;
    f32 sp28[3];
    if (func_8008FDEC() != arg0->unk0)
    {
        func_800F63E0(func_800F54E4(), arg0->unk6C_9);
        func_800FFAB0(arg0);
        return;
    }
    if (arg0->unk64_22)
    {
        func_800F5D44(func_800F54E4(), sp28);
        func_808001A0_chpickups(arg0->unk0, sp28);
    }
}

void func_808005B8_chpickups(Actor* arg0, s32 arg1)
{
    s32 var_v0;

    func_8010A5B0(arg0, arg1);
    if ((arg0->unk70_10) == 2)
    {
        var_v0 = 8;
        if (arg1 == 0)
        {
            var_v0 = 0xA;
        }
        _sudeflect_entrypoint_1(arg0->position, func_80103EF4(arg0), 0, func_80103EAC(arg0), var_v0);
    }
}

void func_80800638_chpickups(Actor* arg0)
{

    if (!(arg0->unk64_17))
    {
        switch (arg0->unk70_10)
        {
        case 2:
            break;
        case 5:
            func_80800344_chpickups((s32)arg0);
            break;
        case 1:
            func_80800364_chpickups(arg0);
            break;
        case 3:
            func_80800528_chpickups(arg0);
            break;
        case 4:
            func_80800364_chpickups(arg0);
            break;
        }
        if (((u32)arg0->unk0->unk24 >> 0x16) == 0x1DD)
        {
            if (func_800DA298(0x5A) != 0)
            {
                func_808005B8_chpickups(arg0, 0);
                return;
            }
            if (func_80090178(0x201) != 0)
            {
                func_808005B8_chpickups(arg0, 1);
                return;
            }
            func_808005B8_chpickups(arg0, 0);
        }
    }
}

void func_80800734_chpickups(Actor* arg0)
{
    arg0->rotation[0] = 0.0f;
}

void func_80800740_chpickups(s32 arg0)
{
    func_80800638_chpickups(arg0);
    _chdoubloon_entrypoint_1(arg0);
}
