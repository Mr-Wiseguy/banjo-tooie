#include "ch/poolkids.h"

extern ActorData D_808013F0_chpoolkids;
extern ActorData D_80801438_chpoolkids;
extern ActorData D_80801480_chpoolkids;

extern s32 D_808012B0_chpoolkids;
extern s32 D_808012D8_chpoolkids;
extern s32 D_808012F8_chpoolkids;
extern s32 D_80801318_chpoolkids;
extern s32 D_80801340_chpoolkids;
extern s32 D_80801360_chpoolkids;
extern s32 D_808014C8_chpoolkids;
extern s32 D_808014D8_chpoolkids;
extern f32 D_80801508_chpoolkids;
extern f32 D_80801514_chpoolkids;
extern s32 D_80801520_chpoolkids;
extern u32 D_8080152C_chpoolkids;
extern u32 D_8080153C_chpoolkids;
extern u32 D_8080154C_chpoolkids;
extern u32 D_8080155C_chpoolkids;
extern u32 D_8080156C_chpoolkids;
extern u32 D_8080157C_chpoolkids;

extern s32 D_808015A0_chpoolkids[3];
extern f32 D_808015EC_chpoolkids[3];

void func_80800884_chpoolkids(Actor*);
void func_808008DC_chpoolkids(Actor*);
void func_80800944_chpoolkids(Actor*, f32);
void func_80800AA0_chpoolkids(Actor*);
void func_80800B38_chpoolkids(Actor*);
void func_80800D74_chpoolkids(Actor*);

ActorData* chpoolkids_entrypoint_0()
{
    return &D_808013F0_chpoolkids;
}
ActorData* chpoolkids_entrypoint_1()
{
    return &D_80801438_chpoolkids;
}
ActorData* chpoolkids_entrypoint_2()
{
    return &D_80801480_chpoolkids;
}

void func_80800024_chpoolkids(Actor* arg0)
{
    u32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1(arg0);
    arg0->actorData[6] = temp_v0;
    _subaddiesect_entrypoint_2(arg0, temp_v0, 1);
}

void func_80800058_chpoolkids(Actor* arg0)
{
    s32 pad;
    f32 temp_f0;

    if (func_80104248(arg0) != NULL)
    {
        if (func_801022E4(arg0) == 0x2B9)
        {
            temp_f0 = func_80101F24(arg0);
            (f32)arg0->actorData[5] = func_80013970(ml_map_f(temp_f0, 0.75f, 0.99f, 0.0f, 180.0f));
            if ((temp_f0 > 0.33f) && (temp_f0 < 0.52f))
            {
                arg0->unk74_0 = 2;
            }
            else
            {
                arg0->unk74_0 = 1;
            }
        }
        else
        {
            arg0->unk74_0 = 1;
            (f32)arg0->actorData[5] = 0;
        }
    }
    func_8008FB58(arg0->position, 60.0f, 60.0f);
    switch (arg0->unk70_10)
    {
    case 1:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8(arg0, arg0->position, (s32)&D_808014C8_chpoolkids, (s32)&D_808012B0_chpoolkids, 5);
        func_80800AA0_chpoolkids(arg0);
        return;
    case 2:
        func_80800AA0_chpoolkids(arg0);
        return;
    case 3:
        func_80800AA0_chpoolkids(arg0);
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            _glcutDll_entrypoint_17();
            return;
        }
    default:
        return;
    case 4:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8(arg0, arg0->position, (s32)&D_808014C8_chpoolkids, (s32)&D_808012D8_chpoolkids, 4);
        func_80800AA0_chpoolkids(arg0);
        return;
    case 5:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8(arg0, arg0->position, (s32)&D_808014C8_chpoolkids, (s32)&D_808012F8_chpoolkids, 4);
        func_80800AA0_chpoolkids(arg0);
        return;
    case 6:
        func_808008DC_chpoolkids(arg0);
        func_80800944_chpoolkids(arg0, 0.55f);
        break;
    }
}

void func_80800290_chpoolkids(Actor* arg0)
{
    func_8008FB58(arg0->position, 60.0f, 60.0f);
    switch (arg0->unk70_10)
    {
    case 1:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_808014D8_chpoolkids, &D_80801318_chpoolkids, 5);
        func_80800B38_chpoolkids(arg0);
        return;
    case 2:
        func_80800B38_chpoolkids(arg0);
        return;
    case 4:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_808014D8_chpoolkids, &D_80801340_chpoolkids, 4);
        func_80800B38_chpoolkids(arg0);
        return;
    case 5:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_808014D8_chpoolkids, &D_80801360_chpoolkids, 4);
        func_80800B38_chpoolkids(arg0);
        return;
    case 6:
        func_80800884_chpoolkids(arg0);
        func_808008DC_chpoolkids(arg0);
        func_80800944_chpoolkids(arg0, 0.9f);
    default:
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_808003DC_chpoolkids.s")

void func_80800618_chpoolkids(Actor* arg0)
{
    func_80102424(arg0, 6);
    switch (arg0->unk6C_9)
    {
    case 0x3A3:
        ml_vec3f_copy(arg0->position, &D_80801508_chpoolkids);
        break;
    case 0x3A4:
        ml_vec3f_copy(arg0->position, &D_80801514_chpoolkids);
        func_801020DC(arg0, 0);
        func_80101DAC(arg0, 0);
        break;
    }
    if (_glcutDll_entrypoint_20() == 0)
    {
        func_800EF1B8(arg0->position, rand_fBounded(0.0f, 359.0f), rand_fBounded(0.0f, 200.0f));
    }
    func_80103014(arg0);
}

void func_808006F8_chpoolkids(Actor* arg0)
{
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    sp24 = flag_getValue(FLAG_166_UNK);
    sp20 = flag_getValue(FLAG_167_PHYSICAL_HFP_DrainedHotPool);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800618_chpoolkids(arg0);
    }
    else if ((_glcutDll_entrypoint_19(0x2AU) != 0) || (_glcutDll_entrypoint_19(0x29U) != 0))
    {
        sp1C = 1;
    }
    else if ((sp24 != 0) && (sp20 == 0))
    {
        func_80102424(arg0, 4);
    }
    else if ((sp24 == 0) && (sp20 != 0))
    {
        func_80102424(arg0, 5);
    }
    else if ((sp24 != 0) && (sp20 != 0))
    {
        func_80800618_chpoolkids(arg0);
    }
    if (sp1C != 0)
    {
        flag_setValueFalse(FLAG_168_UNK);
        flag_setValueFalse(FLAG_1CE_UNK);
    }
}

void func_808007F0_chpoolkids(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x1020:
    case 0x1021:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_17();
        return;
    case 0x1022:
        func_800D0C78(0x22U, 1U, 0U);
        arg0->unk58 = 4.5f;
        func_80102424(arg0, 3);
        return;
    default:
        func_80102424(arg0, arg0->actorData[4]);
        return;
    }
}

void func_80800884_chpoolkids(Actor* arg0)
{
    f32 sp1C[3];

    if (_glcutDll_entrypoint_20() == 0)
    {
        func_8010D600(sp1C);
        arg0->unk54 = func_80102D78(arg0, sp1C);
        func_80102BF8(arg0, 0.15f, 4.0f, 120.0f);
    }
}

void func_808008DC_chpoolkids(Actor* arg0)
{
    timer_reachedZero(&arg0->unk58);
    if (arg0->unk58 <= 0.0f)
    {
        _fxripple_entrypoint_0(3, arg0->position);
        arg0->unk58 = rand_fBounded(0.6f, 1.2f);
    }
}

void func_80800944_chpoolkids(Actor* arg0, f32 arg1)
{
    f32 sp34[3];
    s32 temp_v0;

    if (func_80101E14(arg0, arg1) != 0)
    {
        ml_vec3f_copy(sp34, arg0->position);
        _subaddieaudioquick_entrypoint_2(arg0, sp34, &D_80801520_chpoolkids);
        _fxripple_entrypoint_0(3, sp34);
        _fxsplash25d_entrypoint_0(sp34);
        temp_v0 = _fxsplash_entrypoint_2(sp34, 35.0f);
        func_800BA930(temp_v0, -0x15E, 0x12C, -0x15E, 0x15E, 0x1F4, 0x15E);
        func_800BA22C(temp_v0, 6);
        func_800BA930(temp_v0, -0x96, 0x1F4, -0x96, 0x96, 0x320, 0x96);
        func_800BA22C(temp_v0, 6);
        sp34[1] -= 30.0f;
        temp_v0 = _fxairbub_entrypoint_1(sp34, 20.0f, arg0->position[1], 1.0f);
        func_800BA930(temp_v0, -0x3C, -0xFA, -0x3C, 0x3C, -0x96, 0x3C);
        func_800BA22C(temp_v0, 4);
    }
}

void func_80800AA0_chpoolkids(Actor* arg0)
{
    f32* temp_s1;

    temp_s1 = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080152C_chpoolkids, 0.4f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080153C_chpoolkids, 0.18f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080154C_chpoolkids, 0.73f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080155C_chpoolkids, 0.77f);
}

void func_80800B38_chpoolkids(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_8080156C_chpoolkids, &D_8080157C_chpoolkids);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800B68_chpoolkids.s")

s32 func_80800D3C_chpoolkids(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 0x95)
    {
        func_80800D74_chpoolkids(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800D74_chpoolkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/chpoolkids_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_808011A8_chpoolkids.s")
