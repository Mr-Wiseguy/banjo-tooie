#include "ch/grunty/fireball.h"


extern ActorData D_80800480_chgruntyfireball;
extern u32 D_808004C8_chgruntyfireball;
extern s32 D_808004E0_chgruntyfireball[][3];
extern s32 D_808004F8_chgruntyfireball;
extern f32 D_8080050C_chgruntyfireball;
extern s32 D_80800514_chgruntyfireball;
extern s32 D_80800524_chgruntyfireball;
extern s32 D_80800554_chgruntyfireball;
extern s32 D_80800588_chgruntyfireball;

void func_80800260_chgruntyfireball(Actor*);
void func_808003D8_chgruntyfireball(Actor*);

ActorData* chgruntyfireball_entrypoint_0()
{
    return &D_80800480_chgruntyfireball;
}

void func_8080000C_chgruntyfireball(Actor* actor)
{
    actor->actorData[3] = 0;
    func_80109EEC(actor, 0x40);
}

void func_80800030_chgruntyfireball(Actor* actor)
{
    _subaddieaudioloop_entrypoint_4(actor, actor->position, 1U, &D_808004C8_chgruntyfireball);
    switch (actor->unk70_10)
    {
    case 1:
        func_808003D8_chgruntyfireball(actor);
        break;
    case 2:
        if (func_8010B990(actor, 0x400007) & 0x20)
        {
            func_80018820(0, 1.0f, 0.18f);
            func_800E15CC(0, 22.0f, 0.8f);
            func_80800260_chgruntyfireball(actor);
        }
        else
        {
            func_808003D8_chgruntyfireball(actor);
        }
        break;
    }
    if (((s32*)actor->actorData)[3] != 0)
    {
        func_800C8CB8(((s32*)actor->actorData)[3], actor->position);
        func_800C8E84(((s32*)actor->actorData)[3], D_808004E0_chgruntyfireball[func_8001210C(1)]);
    }
}

s32 func_80800130_chgruntyfireball(Actor* actor, s32 arg1, s32 arg2)
{
    f32 sp34[3];
    s32 temp_v0;
    u32* temp_a0;

    switch (arg1)
    {
    case 0xA:
        actor_enableCollision(actor);
        func_80101FDC(actor, 2U);
        func_8010D09C((arg2 >> 0x10) & 0xFFFF, sp34, 0);
        temp_a0 = &actor->actorData[4];
        sp34[1] += 50.0f;
        ml_getdiff_vec3f((f32*)temp_a0, sp34, actor->position);
        ml_vec3f_set_length((f32*)temp_a0, (f32)(arg2 & 0xFFFF));
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_808004F8_chgruntyfireball);
        break;
    case 0x40:
        func_80800260_chgruntyfireball(actor);
        break;
    case EVENT_95_ACTOR_SPAWNED:
        temp_v0 = func_800C8A98();
        actor->actorData[3] = temp_v0;
        func_800C8CB8(temp_v0, actor->position);
        func_800C8D4C(actor->actorData[3], &D_8080050C_chgruntyfireball);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800260_chgruntyfireball(Actor* actor)
{
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;

    actor_disableCollision(actor);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800514_chgruntyfireball);
    ml_vec3f_copy(sp7C, actor->position);
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 0xA; var_s1++)
    {
        func_800EEB9C(sp70, (f32)var_s1 * 36.0f, rand_fBounded(60.0f, 80.0f));
        ml_vec3f_add(sp70, actor->position);
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, &D_80800524_chgruntyfireball);
    }
    if (((s32*)actor->actorData)[3] != 0)
    {
        ((s32*)actor->actorData)[3] = _chlightfader_entrypoint_1(((s32*)actor->actorData)[3], 1.5f, 2);
    }
    actor_mark_delete(actor);
}

void func_808003D8_chgruntyfireball(Actor* actor)
{
    f32 sp2C[3];
    func_800BBCB8(actor->position, actor->position, 1.0f, 1, &D_80800588_chgruntyfireball);
    ml_vec3f_copy(sp2C, &actor->actorData[4]);
    ml_vec3f_set_length(sp2C, 100.0f);
    ml_vec3f_apply_scale(sp2C, -1.0f);
    ml_vec3f_add(sp2C, actor->position);
    func_800BBCB8(sp2C, actor->position, 0.8f, 1, &D_80800554_chgruntyfireball);
}
