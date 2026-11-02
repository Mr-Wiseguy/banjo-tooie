#include "ch/digger/bossbattery.h"

extern ActorData D_808002F0_chdiggerbossbattery;
extern u32 D_80800338_chdiggerbossbattery;

ActorData* chdiggerbossbattery_entrypoint_0()
{
    return &D_808002F0_chdiggerbossbattery;
}
void func_8080000C_chdiggerbossbattery(Actor* arg0)
{
    ml_vec3f_copy(&arg0->actorData[0], arg0->position);
    ml_vec3f_clear(arg0->position);
    func_80102FDC(arg0, 0.25f);
    arg0->unk58 = rand_fBounded(1.5f, 3.0f);
    if (flag_getValue(arg0->unk74_7 + 0xA1D) != 0)
    {
        actor_mark_delete(arg0);
    }
}

void func_80800090_chdiggerbossbattery(Actor* arg0)
{
    f32 sp2C[3];
    f32 var_f0;

    _subaddieaudioloop_entrypoint_4(arg0, &arg0->actorData[0], 1U, &D_80800338_chdiggerbossbattery);
    if (timer_reachedZero(&arg0->unk58) != 0) {
        ml_vec3f_copy(sp2C, &arg0->actorData[0]);
        if (rand_percentChance(0.5f) != 0)
        {
            var_f0 = 1.0f;
        }
        else
        {
            var_f0 = -1.0f;
        }
        func_800EF1B8(sp2C, var_f0 * 90.0f, 80.0f);
        sp2C[1] += 300.0f;
        _chelectricfence_entrypoint_1(arg0, sp2C);
        arg0->unk58 = rand_fBounded(1.5f, 3.0f);
    }
}

s32 func_80800170_chdiggerbossbattery(Actor* arg0, s32 arg1, s32 arg2)
{
    f32 sp2C[3];
    Actor* temp_v0;
    Actor* temp_v0_2;

    switch (arg1)
    {
    case 0x40:
        ml_vec3f_copy(sp2C, (f32*)arg0->actorData);
        func_800EF1B8(sp2C, arg0->rotation[1], -400.0f);
        sp2C[1] -= 80.0f;
        flag_setValueTrue(arg0->unk74_7 + 0xA1D);
        func_8010A624(arg0);
        _chexploder_entrypoint_3(arg0, sp2C, 0xCU);
        func_800FC660(0xE);
        temp_v0 = _subaddiefind_entrypoint_1(arg0, arg0->unk6C_9, -1, 0);
        if (temp_v0 != NULL)
        {
            actor_disableCollision(temp_v0);
        }
        break;
    case 0x90:
        temp_v0_2 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(temp_v0_2, 1, 2);
        _chexploder_entrypoint_15((s32)temp_v0_2, 2U, 1.0f);
        _chexploder_entrypoint_13((s32)temp_v0_2, 1U);
        break;
    case EVENT_95_ACTOR_SPAWNED:
        func_80103140(arg0, ((u16*)&D_808002F0_chdiggerbossbattery)[arg0->unk74_7 - 4], 0U);
        break;
    case EVENT_1F_ACTOR_ONSCREEN:
        func_801015D0(arg0);
        func_800DF744(1, 1);
        break;
    default:
        return 0;
    }
    return 1;
}