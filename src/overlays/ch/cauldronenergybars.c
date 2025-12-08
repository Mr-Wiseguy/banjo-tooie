#include "ch/cauldronenergybars.h"

#define CAULDRONENERGYBARS_DATA(arg0) ((CauldronEnergyBarsData*)(arg0->actorData))

extern s32 D_808002C0_chcauldronenergybars;
extern ActorData D_808002D4_chcauldronenergybars;

void func_80800000_chcauldronenergybars(Actor* arg0)
{
    s32 var_a1;
    s32 sp18;
    u8 var_a0;


    if (arg0->unk74_7 == 0x32)
    {
        var_a0 = 8;
        var_a1 = FLAG_39A_PROGRESS_OPENED_WORLD_CK;
        sp18 = 0x82;
    }
    else
    {
        var_a0 = 9;
        var_a1 = FLAG_39B_PROGRESS_OPENED_WORLD_HAG_1_BATTLE;
        sp18 = 0x83;
    }
    if (_sujiggy_entrypoint_20(var_a0) != 0)
    {
        func_800DA544(var_a1);
    }
    if (func_800DA298(var_a1) != 0)
    {
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(sp18) == 0))
    {
        func_800FFAB0(arg0);
    }
}

void func_808000B8_chcauldronenergybars(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 1:
        if (func_800D9078(&CAULDRONENERGYBARS_DATA(arg0)->unk10) != 0)
        {
            func_8010A590(arg0);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_808002C0_chcauldronenergybars);
        return;
    case 2:
        if (func_800D90A4(&arg0->unk58) != 0)
        {
            func_800FFAB0(arg0);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_808002C0_chcauldronenergybars);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4(arg0->unk58, CAULDRONENERGYBARS_DATA(arg0)->unk1C, 0.0f, 1.4f, 0.7f));
        arg0->alpha = (u8)(s32)func_800F10B4(arg0->unk58, CAULDRONENERGYBARS_DATA(arg0)->unk1C, 0.0f, 255.0f, 0.0f);
        return;
    }
}

s32 func_808001C4_chcauldronenergybars(Actor* arg0, s32 arg1, s32 arg2)
{
    union {
        f32 f;
        s32 s;
        void* p;
    } temp;
    f32 sp30[3];
    s32 new_var[1];
    f32 pad;

    switch (arg1)
    {
    case 0x7:
        temp.f = arg2;
        CAULDRONENERGYBARS_DATA(arg0)->unk1C = temp.f;
        arg0->unk58 = temp.f;
        func_80101FDC(arg0, 2);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_8010A570(arg0);
        func_800DA544((arg0->unk74_7 == 0x32) ? (0x39A) : (0x39B));
        return 1;

    case 0x3F:
        new_var[0] = *(s32*)&arg2;
        func_800EC75C(new_var[0], sp30);
        _chelectricfence_entrypoint_1(arg0, sp30);
        CAULDRONENERGYBARS_DATA(arg0)->unk10 = 0.2f;
        func_8010A570(arg0);
        return 1;
    }

    return 0;
}

ActorData* chcauldronenergybars_entrypoint_0(void)
{
    return &D_808002D4_chcauldronenergybars;
}