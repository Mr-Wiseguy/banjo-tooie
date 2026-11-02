#include "ch/grunty/fireballbig.h"

extern ActorData D_80800680_chgruntyfireballbig;
extern u32 D_808006C8_chgruntyfireballbig;
extern s32 D_808006E0_chgruntyfireballbig[][3];
extern s32 D_808006F8_chgruntyfireballbig;
extern f32 D_8080070C_chgruntyfireballbig;
extern s32 D_80800714_chgruntyfireballbig;
extern s32 D_80800724_chgruntyfireballbig;
extern s32 D_80800754_chgruntyfireballbig;
extern s32 D_80800788_chgruntyfireballbig;

void func_8080034C_chgruntyfireballbig(Actor* actor);
void func_808004C4_chgruntyfireballbig(Actor* actor);
void func_80800590_chgruntyfireballbig(Actor* actor);

ActorData* chgruntyfireballbig_entrypoint_0()
{
    return &D_80800680_chgruntyfireballbig;
}

void func_8080000C_chgruntyfireballbig(Actor* actor)
{
    actor->actorData[3] = 0;
    func_80109EEC(actor, 0x40);
}

void func_80800030_chgruntyfireballbig(Actor* actor)
{
    f32 sp2C;

    _subaddieaudioloop_entrypoint_4(actor, actor->position, 1U, &D_808006C8_chgruntyfireballbig);
    switch (actor->unk70_10)
    {
    case 1:
        func_808004C4_chgruntyfireballbig(actor);
        break;
    case 2:
        func_80800590_chgruntyfireballbig(actor);
        if (func_8010B990(actor, 0x400007) & 0x20)
        {
            func_80018820(0, 1.2f, 0.22f);
            func_800E15CC(0, 24.0f, 0.84f);
            func_8080034C_chgruntyfireballbig(actor);
        }
        else
        {
            func_808004C4_chgruntyfireballbig(actor);
        }
        break;
    case 3:
        sp2C = time_getDelta();
        func_808004C4_chgruntyfireballbig(actor);
        actor->position[1] -= ((f32*)actor->actorData)[2] * sp2C;
        ((f32*)actor->actorData)[2] = ((f32*)actor->actorData)[2] + (800.0f * sp2C);
        if (actor->position[1] <= ((f32*)actor->actorData)[1])
        {
            actor_mark_delete(actor);
        }
        break;
    }
    if (((s32*)actor->actorData)[3] != 0)
    {
        func_800C8CB8(((s32*)actor->actorData)[3], actor->position);
        func_800C8E84(((s32*)actor->actorData)[3], D_808006E0_chgruntyfireballbig[func_8001210C(1)]);
    }
}

s32 func_808001B4_chgruntyfireballbig(Actor* actor, s32 arg1, s32 arg2)
{
    f32 sp34[3];
    u32* temp_a0;

    switch (arg1)
    {
    case 0xA:
        actor->unk6C_0 = (arg2 >> 0x10) & 0xFFFF;
        ((f32*)actor->actorData)[0] = func_80101068();
        actor_enableCollision(actor);
        func_80101FDC(actor, 2U);
        character_getCoords(actor->unk6C_0, sp34);
        temp_a0 = &actor->actorData[4];
        sp34[1] += 50.0f;
        ml_getdiff_vec3f((f32*)temp_a0, sp34, actor->position);
        ml_vec3f_set_length((f32*)temp_a0, (f32)(arg2 & 0xFFFF));
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_808006F8_chgruntyfireballbig);
        break;
    case 0x40:
        func_8080034C_chgruntyfireballbig(actor);
        break;
    case EVENT_95_ACTOR_SPAWNED:
        actor->actorData[3] = func_800C8A98();
        func_800C8CB8(actor->actorData[3], actor->position);
        func_800C8D4C(actor->actorData[3], &D_8080070C_chgruntyfireballbig);
        break;
    case 0x9B:
        func_80101FDC(actor, 3U);
        ((f32*)actor->actorData)[1] = arg2;
        ((f32*)actor->actorData)[2] = -150.0f;
        if (((s32*)actor->actorData)[3] != 0)
        {
            actor->actorData[3] = _chlightfader_entrypoint_1(((s32*)actor->actorData)[3], 1.5f, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080034C_chgruntyfireballbig(Actor* actor)
{
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;
    actor_disableCollision(actor);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800714_chgruntyfireballbig);
    ml_vec3f_copy(sp7C, actor->position);
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 0xA; var_s1++)
    {
        func_800EEB9C(sp70, (f32)var_s1 * 36.0f, rand_fBounded(60.0f, 80.0f));
        ml_vec3f_add(sp70, actor->position);
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, &D_80800724_chgruntyfireballbig);
    }

    if (((s32*)actor->actorData)[3])
    {
        ((s32*)actor->actorData)[3] = _chlightfader_entrypoint_1(((s32*)actor->actorData)[3], 1.5f, 2);
    }
    actor_mark_delete(actor);
}

void func_808004C4_chgruntyfireballbig(Actor* actor)
{
    f32 sp2C[3];

    func_800BBCB8(actor->position, actor->position, actor->scale * 1.2f, 1, &D_80800788_chgruntyfireballbig);
    ml_vec3f_copy(sp2C, &actor->actorData[4]);
    ml_vec3f_set_length(sp2C, 100.0f);
    ml_vec3f_apply_scale(sp2C, -1.0f);
    ml_vec3f_add(sp2C, actor->position);
    func_800BBCB8(sp2C, actor->position, actor->scale * 0.8f, 1, &D_80800754_chgruntyfireballbig);
}

void func_80800590_chgruntyfireballbig(Actor* actor)
{
    f32 sp3C[3];
    f32 sp34[2];
    s32 pad;

    if (!(actor->unk64_20) && (func_800F6438(actor->unk6C_0) != 0))
    {
        character_getCoords(actor->unk6C_0, sp3C);
        sp3C[1] += 50.0f;
        if (ml_vec3f_distance_sq(actor->position, sp3C) < (((f32*)actor->actorData)[0] * ((f32*)actor->actorData)[0]))
        {
            actor->unk64_20 = 1;
            return;
        }
        func_800F18FC(actor->position, sp3C, sp34);
        func_800EEBF0(&actor->actorData[4], sp34, ml_vec3f_magnitude(&actor->actorData[4]));
    }
}
