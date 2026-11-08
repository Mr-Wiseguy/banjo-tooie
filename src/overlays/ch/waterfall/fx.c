#include "ch/waterfallfx.h"

void func_808001F8_chwaterfallfx(Actor*);
extern s32 D_80800458_chwaterfallfx;
extern s32 D_80800478_chwaterfallfx;


extern ActorData D_80800410_chwaterfallfx;
ActorData* chwaterfallfx_entrypoint_0()
{
    return &D_80800410_chwaterfallfx;
}

void func_8080000C_chwaterfallfx(Actor* arg0)
{
    f32 sp48[2];
    f32 sp40[2];
    f32 sp34[3];
    f32 temp_f0;
    func_800F22B4(sp48, arg0->rotation[1]);
    func_800F23AC(sp40, sp48);
    ml_vec2f_to_vec3f(sp34, sp40);

    ml_vec3f_apply_scale(sp34, arg0->unk74_7);
    ml_vec3f_sum((f32*)&arg0->actorData[4], arg0->position, sp34);
    ml_getdiff_vec3f(arg0->actorData, arg0->position, sp34);
    temp_f0 = ml_vec3f_distance(&arg0->actorData[4], arg0->actorData);
    ((f32*)arg0->actorData)[7] = 0.6f * temp_f0;
    temp_f0 /= 25.0f;
    temp_f0 += 8.0f;
    arg0->actorData[3] = (s32)temp_f0;
    arg0->unk54s = 0;
    arg0->unk64_20 = arg0->unk70_0;
    arg0->unk70_0 = 0;
    arg0->unk58 = 0.0f;
    arg0->unk50 = (f32)((s32)temp_f0 * 1.5f);
}

void func_80800148_chwaterfallfx(Actor* arg0)
{
    _subaddieaudioloop_entrypoint_5(arg0, arg0->position, 1, 0xC80, &D_80800458_chwaterfallfx);
    if (arg0->unk5F != 0)
    {
        if (!(arg0->unk64_19))
        {
            func_800C3058(arg0->unk5F, 0x2AF8);
            arg0->unk64_19 = 1;
        }
    }
    else
    {
        arg0->unk64_19 = 0;
    }
    if (!(arg0->unk64_20))
    {
        func_808001F8_chwaterfallfx(arg0);
    }
}

s32 func_808001E4_chwaterfallfx(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
void func_808001F8_chwaterfallfx(Actor* arg0)
{
    f32 spA4[3];
    s32 temp_fp;
    s32 var_s3;
    s32 var_s4;
    f32 sp8C[3];
    f32 sp80[3];


    func_800E3980(spA4);
    if ((ml_vec3f_distance_sq(arg0->position, spA4) < 2.5e7f) && (func_800E3E8C(arg0->position, ((f32*)arg0->actorData)[7])))
    {
        temp_fp = func_800B5BE4(0x23);
        var_s4 = 0;
        arg0->unk58 += arg0->unk50 * time_getDelta();
        while (arg0->unk58 >= 1.0f)
        {
            arg0->unk58 = (f32)(arg0->unk58 - 1.0f);
            var_s4 += 1;
        }
        for (var_s3 = 0; var_s3 < var_s4; var_s3++)
        {
            func_800EFE50(sp80, &arg0->actorData[4], arg0->actorData, rand_fBounded(0.0f, 1.0f));
            ml_vec3f_copy(sp8C, sp80);
            ml_translateAngleDist(sp8C, arg0->rotation[1], -100.0f);
            sp8C[1] += 100.0f;
            func_800BABB8(temp_fp, sp80, sp8C, arg0->scale * 1.15f, &D_80800478_chwaterfallfx);
            arg0->unk54s++;
            if (arg0->unk54s >= (s32)arg0->actorData[3])
            {
                arg0->unk54s = 0;
            }
        }
    }
}