#include "ch/switch.h"

extern s32 D_80800DB0_chswitch;
extern s32 D_80800DC4_chswitch;
extern s32 D_80800DD8_chswitch;

s32 func_8080093C_chswitch(Actor*);

s32* chswitch_entrypoint_0(void)
{
    return &D_80800DB0_chswitch;
}

s32* chswitch_entrypoint_1(void) 
{
    return &D_80800DC4_chswitch;
}

s32* chswitch_entrypoint_2(void)
{
    return &D_80800DD8_chswitch;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_80800024_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_808000B8_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_8080012C_chswitch.s")

s32 chswitch_entrypoint_3(Actor* arg0, enum flag_e arg1)
{
    s32 temp_v0;

    temp_v0 = flag_getValue(arg1);
    arg0->actorData[7] = arg1;
    func_80103110(arg0, 0U);
    arg0->unk54 = 0.75f;
    func_80102E08(arg0);
    return temp_v0;
}

void chswitch_entrypoint_4(Actor* arg0)
{
    if (arg0->unk70_10 == 2 && func_80101DDC(arg0) != 0 && !(arg0->unk64_20) && (timer_reachedZero(&arg0->unk54) != 0))
    {
        arg0->unk64_20 = 1;
        func_80102424(arg0, 3);
        func_80103110(arg0, 0U);
        func_800F7F98(arg0->actorData[4], 0);
        flag_setValueTrue((enum flag_e)arg0->actorData[7]);
        event_sendToActor(arg0, 7, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_808002B4_chswitch.s")

s32 chswitch_entrypoint_5(Actor* arg0, s32 arg1, u32 arg2)
{
    switch (arg1)
    {
    case 0x29:
        return func_8080093C_chswitch(arg0);
    case EVENT_91_ACTOR_STOOD_ON:
        if (arg0->unk70_10 == 1)
        {
            _gcaudiolist_entrypoint_0(0);
            func_80102424(arg0, 2);
            actor_disableCollision(arg0);
            func_80103110(arg0, 1U);
            arg0->actorData[4] = arg2;
            func_800F7F98(arg2, 1);
            break;
        }
        return 0;
    case EVENT_95_ACTOR_SPAWNED:
        if (flag_getValue(arg0->actorData[7]) != 0)
        {
            func_80102424(arg0, 3);
            arg0->unk64_20 = 1;
            actor_disableCollision(arg0);
        }
        else
        {
            func_80102424(arg0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void chswitch_entrypoint_6(Actor* arg0)
{
    s32 temp_v0;
    s32 temp;
    switch (arg0->unk70_10)
    {
    case 1:
        break;
    case 2:
        if (func_80101DDC(arg0) != 0)
        {
            func_80102424(arg0, 3);
        }
        break;
    case 3:
        temp_v0 = _character_findCharOfTransform(*(s32*)&arg0->unk50);
        temp = temp_v0 + 1 == 0;
        if (!(arg0->unk64_20) && (temp == 0))
        {
            if (timer_reachedZero(&arg0->unk54) != 0)
            {
                func_800F7F98(temp_v0, 0);
                flag_setValueTrue((enum flag_e)arg0->actorData[7]);
                arg0->unk64_20 = 1;
                if (arg0->actorData[6] != 0)
                {
                    func_80103110(arg0, 0U);
                }
                event_sendToActor(arg0, 7, 0);
            }
        }
        else if (!arg0->unk6C_0 || temp != 0)
        {
            if (timer_reachedZero_dupe(&arg0->unk58) != 0)
            {
                _gcaudiolist_entrypoint_0(0U);
                func_80102424(arg0, 4);
                arg0->unk64_20 = 0;
                arg0->unk54 = 0.375f;
            }
        }
        else
        {
            arg0->unk58 = 0.15f;
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0)
        {
            func_80103110(arg0, 0U);
            func_80102424(arg0, 1);
            flag_setValueFalse((enum flag_e)arg0->actorData[7]);
            (s32)arg0->unk50 = 0;
            event_sendToActor(arg0, 8, 0);
        }
        break;
    }
    arg0->unk6C_0 = 0;
}

s32 chswitch_entrypoint_7(Actor* arg0, enum flag_e arg1)
{
    s32 temp_v0;

    temp_v0 = flag_getValue(arg1);
    arg0->actorData[7] = arg1;
    if (temp_v0 != 0)
    {
        arg0->unk54 = 0.0f;
        func_80102424(arg0, 3);
    }
    else
    {
        arg0->unk54 = 0.375f;
        func_80102424(arg0, 1);
    }
    arg0->actorData[5] = -1U;
    (s32)arg0->unk50 = 0;
    arg0->actorData[6] = 0;

    func_80102E08(arg0);
    return temp_v0;
}

void chswitch_entrypoint_8(Actor* arg0, s32 arg1)
{
    arg0->actorData[5] = arg1;
}

void chswitch_entrypoint_9(Actor* arg0)
{
    arg0->actorData[6] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_80800694_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_8080093C_chswitch.s")

void chswitch_entrypoint_11(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 2:
        if (func_80101DDC(arg0) != 0)
        {
            flag_setValueTrue((enum flag_e)arg0->actorData[7]);
            func_80102424(arg0, 3);
            func_800F7F98(arg0->actorData[4], 0);
            event_sendToActor(arg0, 7, 0);
            return;
        }
    case 1:
        return;
    case 3:
        if (flag_getValue((enum flag_e)arg0->actorData[5]) != 0)
        {
            flag_setValueFalse((enum flag_e)arg0->actorData[5]);
            _gcaudiolist_entrypoint_0(0);
            func_80102424(arg0, 4);
            return;
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0)
        {
            flag_setValueFalse((enum flag_e)arg0->actorData[7]);
            func_80102424(arg0, 1);
            event_sendToActor(arg0, 8, 0);
        }
        break;
    }
}


void chswitch_entrypoint_12(Actor* arg0, enum flag_e arg1, enum flag_e arg2)
{
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = flag_getValue(arg1);
    arg0->actorData[7] = arg1;
    arg0->actorData[5] = arg2;
    if (arg2 != -1)
    {
        flag_setValueFalse(arg2);
    }
    if (temp_v0 != 0)
    {
        var_a1 = 3;
    }
    else
    {
        var_a1 = 1;
    }
    func_80102424(arg0, var_a1);
    func_80102E08(arg0);
}

void chswitch_entrypoint_13(Actor* arg0)
{
    f32 sp24;
    f32 temp_f0;
    f32 temp_f0_2;

    sp24 = time_getDelta();
    switch (arg0->unk70_10)
    {
    case 1:
        if (arg0->unk64_20)
        {
            _gcaudiolist_entrypoint_0(0U);
            func_80102424(arg0, 2);
        }
        temp_f0 = arg0->unk58;
        if (temp_f0 <= 0.0f)
        {
            func_80103110(arg0, 0U);
            return;
        }
        arg0->unk58 = temp_f0 - sp24;
        return;
    case 2:
        if (func_80101E14(arg0, 0.5f) != 0)
        {
            func_80102424(arg0, 3);
            func_80101EE4(arg0, 0.5f);
            if (func_800F6CC8(character_getActiveIndex()) == 0)
            {
                flag_setValueTrue((enum flag_e)arg0->actorData[7]);
                event_sendToActor(arg0, 7, 0);
                return;
            }
        }
        return;
    case 3:
        if (!(arg0->unk64_20))
        {
            _gcaudiolist_entrypoint_0(0U);
            func_80102424(arg0, 4);
        }
        temp_f0_2 = arg0->unk58;
        if (temp_f0_2 <= 0.0f)
        {
            func_80103110(arg0, 0U);
            return;
        }
        arg0->unk58 = temp_f0_2 - sp24;
        return;
    case 4:
        if (func_80101DDC(arg0) != 0)
        {
            flag_setValueFalse((enum flag_e)arg0->actorData[7]);
            func_80102424(arg0, 1);
            event_sendToActor(arg0, 8, 0);
        }
        break;
    }
}

s32 chswitch_entrypoint_14(Actor* arg0, enum flag_e arg1)
{
    s32 temp_v0;

    temp_v0 = flag_getValue(arg1);
    arg0->actorData[7] = arg1;
    if (temp_v0 != 0)
    {
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.5f);
    }
    else
    {
        func_80102424(arg0, 1);
    }
    arg0->unk64_20 = temp_v0;
    func_80103110(arg0, 0U);
    return temp_v0;
}