#include "su/baddiefind.h"

Actor* subaddiefind_entrypoint_11(s32, s32);

Actor* subaddiefind_entrypoint_0(f32* arg0, s32 propId, s32 arg2, f32* arg3)
{
    Actor* var_v0;
    Actor* var_s3;
    f32 temp_f0;
    f32 var_f20;
    s32 sp54;
    //Set to True after finding the first object matching the necessary parameters
    s32 found;
    var_s3 = NULL;
    var_f20 = 0.0f;
    found = 0;
    var_v0 = actorList_getLast(&sp54);
    while (var_v0 != NULL)
    {
        if (((propId == var_v0->unk6C_9) || (propId < 0)) && (arg2 != (var_v0->unk70_10)) && (var_v0->unk6C_9 != 0x215) && (var_v0->unk6C_9 != 0x243) && !(var_v0->unk64_17))
        {
            //Get Distance between given coords and actor coords with matching propId
            temp_f0 = ml_vec3f_distance_sq(arg0, var_v0->position);
            //If this object is closer than the last stored distance
            if (temp_f0 < var_f20 || found == 0)
            {
                var_f20 = temp_f0;
                var_s3 = var_v0;
                found = 1;
            }
        }
        var_v0 = actorList_getNext(&sp54);
    }
    if (arg3 != NULL)
    {
        arg3[0] = sqrtf(var_f20);
    }
    return var_s3;
}

Actor* subaddiefind_entrypoint_1(Actor* arg0, s32 arg1, s32 arg2, f32* arg3)
{
    Actor* var_s5;
    Actor* var_v0;
    f32 temp_f0;
    s32 sp48;
    f32 var_f20;

    var_s5 = NULL;
    var_f20 = 1e10f;
    var_v0 = actorList_getLast(&sp48);
    while (var_v0 != NULL)
    {
        if (((arg1 == var_v0->unk6C_9) || (arg1 < 0)) && (arg2 != var_v0->unk70_10) && (var_v0->unk6C_9 != 0x215) && (var_v0->unk6C_9 != 0x243) && !(var_v0->unk64_17) && (var_v0->unk0 != arg0->unk0))
        {
            temp_f0 = ml_vec3f_distance(arg0->position, var_v0->position);
            if (temp_f0 < var_f20)
            {
                var_f20 = temp_f0;
                var_s5 = var_v0;
            }
        }
        var_v0 = actorList_getNext(&sp48);
    }
    if (arg3 != NULL)
    {
        *arg3 = var_f20;
    }
    return var_s5;
}

Actor* subaddiefind_entrypoint_2(s32 propId, s32* arg1)
{
    Actor* var_v0;
    s32 sp20;

    var_v0 = actorList_getLast(&sp20);
    while (var_v0 != NULL)
    {
        if ((propId == var_v0->unk6C_9) && !(var_v0->unk64_17))
        {
            if (arg1 != NULL)
            {
                arg1[0] = sp20;
            }
            return var_v0;
        }
        var_v0 = actorList_getNext(&sp20);
    }
    return NULL;
}

Actor* subaddiefind_entrypoint_3(s32 propId, s32* arg1)
{
    Actor* var_v0;

    var_v0 = actorList_getNext(arg1);
    while (var_v0 != NULL)
    {
        if ((propId == var_v0->unk6C_9) && !(var_v0->unk64_17))
        {
            return var_v0;
        }
        var_v0 = actorList_getNext(arg1);
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_6.s")

s32 subaddiefind_entrypoint_7(Actor* arg0, s32 propId, s32 arg2)
{
    f32 sp24;
    Actor* temp_v0;

    temp_v0 = subaddiefind_entrypoint_0(arg0->position, propId, -1, &sp24);
    if ((temp_v0 != NULL) && (sp24 < (f32)arg2))
    {
        arg0->unk3C = temp_v0->unk0;
    }
    else
    {
        arg0->unk3C = 0;
    }
    return (s32)arg0->unk3C != 0 ? sp24 : -1.0f;
}

Actor* subaddiefind_entrypoint_8(s32 arg0)
{
    Actor* var_v0;
    s32 sp20;

    var_v0 = actorList_getLast(&sp20);
    while (var_v0 != NULL)
    {
        if ((arg0 == var_v0->unk0->unk12_1) && !(var_v0->unk64_17))
        {
            return var_v0;
        }
        var_v0 = actorList_getNext(&sp20);
    }
    return NULL;
}

s32 subaddiefind_entrypoint_9(s32 propId)
{
    Actor* var_v0;
    s32 var_s0;
    s32 sp2C;

    var_s0 = 0;
    var_v0 = actorList_getLast(&sp2C);
    while (var_v0 != NULL)
    {
        if (propId == var_v0->unk6C_9 && !var_v0->unk64_17)
        {
            var_s0 += 1;
        }
        var_v0 = actorList_getNext(&sp2C);
    }
    return var_s0;
}

s32 subaddiefind_entrypoint_10(Actor* arg0, s32 propId, s32 arg2)
{
    Actor* temp_v0;
    temp_v0 = subaddiefind_entrypoint_11(propId, arg2);
    arg0->unk3C = (temp_v0 != NULL) ? temp_v0->unk0 : 0;
    return arg0->unk3C != 0 ? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_11.s")

Actor* subaddiefind_entrypoint_12(s32 arg0)
{
    Actor* var_v0;
    s32 sp20;

    var_v0 = actorList_getLast(&sp20);
    while (var_v0 != NULL)
    {
        if (!(var_v0->unk64_17) && (arg0 == var_v0->unk6C_21))
        {
            return var_v0;
        }
        var_v0 = actorList_getNext(&sp20);
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_13.s")
