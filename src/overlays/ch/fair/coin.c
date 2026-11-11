#include "ch/fair/coin.h"
extern s32 D_80800150_chfaircoin;
extern ActorData D_8080015C_chfaircoin;

void func_80800000_chfaircoin(Actor* arg0)
{
    f32 sp2C;
    f32 temp_f0;

    timer_reachedZero((f32*)&arg0->actorData[3]);
    temp_f0 = ml_map_f(*(f32*)&arg0->actorData[3], arg0->unk58, 0.0f, 0.0f, 1.0f);
    sp2C = temp_f0;
    func_800EFE50(arg0->position, (f32*)&arg0->actorData[4], (f32*)&arg0->actorData[0], temp_f0);
    arg0->position[1] += func_8001395C(sp2C * 3.1415927f) * 200.0f;
    if (*(f32*)&arg0->actorData[3] == 0.0f) {
        actor_mark_delete(arg0);
        func_800FC660(0xE);
    }
}

Actor* chfaircoin_entrypoint_0(f32* arg0, f32* arg1, f32 arg2)
{
    Actor* temp_v0;

    temp_v0 = func_80108474(0x166U, arg0, 0);
    ml_vec3f_copy(&temp_v0->actorData[0], arg1);
    ml_vec3f_copy((f32*)&temp_v0->actorData[4], arg0);
    (f32)temp_v0->actorData[3] = arg2;
    temp_v0->unk58 = arg2;
    func_800C4AF0(NULL, &D_80800150_chfaircoin);
    return temp_v0;
}

ActorData* chfaircoin_entrypoint_1()
{
    return &D_8080015C_chfaircoin;
}
