#include "ch/lagoon/ufoext.h"

extern s32 D_80800500_chlagoonufoext;
extern u32 D_80800510_chlagoonufoext;
extern u32 D_80800524_chlagoonufoext;

extern ActorData D_80800558_chlagoonufoext;

extern u32 D_808005A0_chlagoonufoext;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
}UFOActorData;
#define UFO_DATA(arg0) ((UFOActorData*)(arg0->actorData))
void func_808002A4_chlagoonufoext(Actor*);
s32 func_80800000_chlagoonufoext(Actor* arg0, s32 arg1, s32 arg2)
{
    u32 temp_v0;

    switch (arg1)
    {
    case 0xB:
        if (arg2 == 0x32)
        {
            flag_setValueTrue(FLAG_0B6_PROGRESS_JRL_UFO_LEFT_JRL);
            _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0U));
            if (_gclevel_entrypoint_3(0x17) != 0)
            {
                _glcutDll_entrypoint_6(0x128, 0x4A);
            }
            return 4;
        }
        return 3;
    case 0x32:
        func_808002A4_chlagoonufoext(arg0);
        return 1;
    case EVENT_95_ACTOR_SPAWNED:
        if ((flag_getValue(FLAG3_9F0_UNK) != 0) && (activePlayer_includedInTransformMask(ALLOW_BK) != 0) && (func_800EA090() == 9))
        {
            temp_v0 = character_getActiveIndex();
            func_800F608C(temp_v0, 1);
            func_800F497C(temp_v0);
            func_800F49D4(temp_v0, func_8010D5DC, arg0->unk0);
            func_800F4AC0(temp_v0, &arg0->actorData[4], 300.0f);
            _susubgame_entrypoint_6(arg0, func_80100094(arg0, 0U), 0x42, 0x60, 0);
            func_80102424(arg0, 2);
            return 1;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800168_chlagoonufoext(Actor* arg0) {
    UFO_DATA(arg0)->unk1C = _subaddieaudioloop_entrypoint_3(UFO_DATA(arg0)->unk1C);
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 0U)) != 0)
    {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0U));
    }
}

ActorData* chlagoonufoext_entrypoint_0(void)
{
    return &D_80800558_chlagoonufoext;
}

void func_808001D8_chlagoonufoext(Actor* arg0)
{
    s32 temp3;
    s32 temp2;
    s32 temp_a0;
    f32 sp28[3];

    arg0->actorData[3] = func_800CBDD4(arg0->position, 0x64, 6);
    if (flag_getValue(0xB6) != 0)
    {
        temp_a0 = arg0->actorData[3];
        if (temp_a0 != -1)
        {
            func_800CBB80(temp_a0, 0);
        }
        actor_mark_delete(arg0);
    }
    else
    {
        arg0->unk6C_0 = _subaddiesect_entrypoint_1(arg0);
    }
    if (_subaddiemarker_entrypoint_0(arg0, 0x1C0, sp28, 1) != 0)
    {
        ml_vec3f_copy((f32*)&arg0->actorData[4], sp28);
    }
    _susubgame_entrypoint_0(arg0, func_80100094(arg0, 0), 0);
}

void func_808002A4_chlagoonufoext(Actor* arg0)
{
    func_80101FDC(arg0, 3U);
    func_80101D4C(arg0);
    collectable_spawnItem(JRL_UFO, 1U, NULL, 3U, NULL);
    _susubgame_entrypoint_6(arg0, func_80100094(arg0, 0U), 0x32, 0x30, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1047U, 0x40U, arg0->position, 0U);
}

void func_8080032C_chlagoonufoext(Actor* arg0)
{
    s32 sp34;

    switch (arg0->unk70_10)
    {
    case 1:
        if (_subaddiesect_entrypoint_0(arg0, arg0->unk6C_0, 4) == 0)
        {
        }
        return;
    case 3:
        sp34 = 0;
        if (func_80101E14(arg0, 0.49f) != 0)
        {
            arg0->unk70_0 = 0;
        }
        if (func_80102320(arg0, 0.53f, 0.7f) != 0)
        {
            sp34 = 1;
        }
        else
        {
            _subaddieaudioloop_entrypoint_4(arg0, &UFO_DATA(arg0)->unk0, 1, &D_80800510_chlagoonufoext);
        }
        UFO_DATA(arg0)->unk1C = _subaddieaudioloop_entrypoint_7(UFO_DATA(arg0)->unk1C, arg0->actorData, sp34, &D_80800500_chlagoonufoext, arg0->unk70_0);
        _subaddieaudioquick_entrypoint_4(arg0, &UFO_DATA(arg0)->unk0, &D_80800524_chlagoonufoext, &D_808005A0_chlagoonufoext);
        if (flag_getValue(FLAG_0B6_PROGRESS_JRL_UFO_LEFT_JRL) != 0)
        {
            if (UFO_DATA(arg0)->unkC != -1U)
            {
                func_800CBB80(UFO_DATA(arg0)->unkC, 0);
            }
            actor_mark_delete(arg0);
        }
        break;
    }
}

void func_8080047C_chlagoonufoext(Actor* arg0, s32 arg1) {
    if ((arg0->unk70_10) != 3)
    {
        func_800DF428(9000.0f);
    }
    else
    {
        func_800DF440(0);
    }
    func_80101808(arg0, &func_801015D0);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 4, &arg0->actorData[0]);
}
