#include "ch/jigsaw.h"

extern ActorData D_80800770_chjigsaw;
extern ActorData D_808007B8_chjigsaw;


void func_80800000_chjigsaw(Actor* arg0, Unk80132ED0* arg1)
{
    if ((func_8010A6B0(arg0, arg1->unk18_5) != 0) && (flag_getValue(FLAG2_665_UNK) == 0))
    {
        func_80108B04(arg0, 0U);
        collectable_collectItem((s32)arg0->unk50, 1U);
        _suautobaddies_entrypoint_3();
    }
}

void func_80800070_chjigsaw(Actor* arg0)
{
    if (collectable_isCollected((u32)(s32)arg0->unk50, 1U) != 0)
    {
        actor_mark_delete(arg0);
        return;
    }
    func_800D05E4((s32)arg0->unk50, 1, arg0->unk0);
    if (arg0->unk58 != 0.0f)
    {
        func_800FC6B0(0x18U);
    }
    func_800D0778((s32)arg0->unk50, 1, arg0->position);
}

void func_8080011C_chjigsaw(Actor* arg0)
{
    f32 temp_f2;

    arg0->unk54 += time_getDelta() * 230.0f;
    temp_f2 = arg0->unk54;
    if (temp_f2 >= 360.0f)
    {
        arg0->unk54 = temp_f2 - 360.0f;
    }
}

void func_8080017C_chjigsaw(Actor* arg0)
{
    func_800D05E4((s32)arg0->unk50, 1, NULL);
    if (arg0->unk6C_0 != 0)
    {
        func_800C8B84(arg0->unk6C_0);
    }
}

void func_808001D0_chjigsaw(Actor* arg0)
{
    func_80105834(arg0);
    func_8080011C_chjigsaw(arg0);
}
void func_808001F8_chjigsaw(Actor* arg0)
{
    s32 temp_s1;
    f32 spA0;
    f32 sp94[3];
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp70[3];
    s32 var_s1;
    f32 sp60[3];
    spA0 = time_getDelta();
    if (arg0->unk7A_3)
    {
        func_800D0778((s32)arg0->unk50, 1, arg0->position);
    }
    else
    {
        if (arg0->unk64_19)
        {
            ml_vec3f_copy(sp94, arg0->position);
            sp94[1] += 100.0f;
            ml_vec3f_copy(sp88, arg0->position);
            sp88[1] -= 100.0f;
            if (func_800BEF00(sp94, sp88, sp7C, arg0->unk14) != 0)
            {
                arg0->position[1] = sp88[1];
            }
            else
            {
                arg0->position[1] += *(f32*)&arg0->actorData[7] * spA0;
            }
        }
    }
    if (arg0->unk7C_12)
    {
        for (var_s1 = 0; var_s1 < 4; var_s1++)
        {
            if (rand_f() < 0.015f)
            {
                func_80103DFC(arg0, sp70);
                func_800EF214(sp70, rand_fBounded(0.0f, 360.0f), rand_fBounded(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_0(sp70);
            }
        }
        if (arg0->unk58 > 0.0f)
        {
            if (rand_f() < (2.0f * (arg0->unk58 / 3.0f)))
            {
                temp_s1 = func_800B5BE4(0x10);
                func_800BABB8(temp_s1, arg0->position, arg0->position, 1.0f, _fxgenlist_entrypoint_1());
                func_800BA22C(temp_s1, 1);
            }
            arg0->unk58 -= spA0;
        }
    }
    if (arg0->unk70_10 == 1)
    {
        // FAKE
        if (arg0->unk7A_3) {}
        if (arg0->unk7A_3 && arg0->unk6C_0)
        {
            ml_vec3f_copy(sp60, arg0->position);
            sp60[1] += 100.0f;
            func_800C8CB8(arg0->unk6C_0, sp60);
        }
        func_8080011C_chjigsaw(arg0);
    }
}

void func_808004A0_chjigsaw(Actor* arg0, s32 arg1)
{
    f32 sp2C[3];

    ml_vec3f_assign_value(sp2C, 0.0f, arg0->unk54, 0.0f);
    func_80101970(arg0);
    func_800DF47C(func_801015D0, arg0);
    func_800DE448(arg0->position, sp2C, arg0->scale, NULL, func_8010347C(arg0->unk0));
}

s32 func_80800518_chjigsaw(Actor* arg0, s32 eventId, s32 arg2)
{
    f32 sp1C[3];

    // FAKE
    if (&arg2) {}
    switch (eventId)
    {
        case EVENT_3E_ACTOR_TOUCHED:
            func_80800000_chjigsaw(arg0, (Unk80132ED0*)arg2);
            break;
        case 0x12:
            arg0->unk64_19 = (u32)arg2;
            break;
        case 0x13:
            arg0->unk50 = (f32)arg2;
            break;
        case 0x14:
            if (arg2 != NULL)
            {
                arg0->unk58 = 3.0f;
            }
            else
            {
                arg0->unk58 = 0.0f;
            }
            break;
        case 0x3D:
            _chjigsawcollect_entrypoint_1(&arg0, (s32)arg0->unk50, arg0->unk70_0);
            actor_mark_delete(arg0);
            break;
        case 0x55:
            arg0->unk6C_0 = func_800C8A98();
            func_800CF9E4((s32)arg0->unk50, 1, arg0->unk6C_0);
            ml_vec3f_copy(&sp1C, arg0->position);
            sp1C[1] += 100.0f;
            func_800C8CB8(arg0->unk6C_0, &sp1C);
            break;
        default:
            return 0;
    }
    return 1;
}

ActorData* chjigsaw_entrypoint_0()
{
    return &D_80800770_chjigsaw;
}

void func_808006CC_chjigsaw(Actor* arg0)
{
    if (func_800D395C() != 0)
    {
        actor_mark_delete(arg0);
        return;
    }
    if ((_subaddiedialog_entrypoint_16() != 0) && (_subaddiedialog_entrypoint_11(NULL, 0xD0AU, 0U, arg0->position, 0x6FU) != 0))
    {
        _gcfrontend_entrypoint_9(0x85);
        actor_mark_delete(arg0);
    }
}

ActorData* chjigsaw_entrypoint_1()
{
    return &D_808007B8_chjigsaw;
}
