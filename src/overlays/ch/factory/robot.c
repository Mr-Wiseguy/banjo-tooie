#include "ch/factory/robot.h"

typedef struct
{
    s16 unk0[3];
    s16 unk6;
    u8 unk8[2];
    s16 unkA;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
}FactoryRobotStruct;

typedef struct
{
    s32 unk0[2];
    s8 unk8[3];
    s8 unkB;
    f32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    s8 unk15;
    s8 unk16;
    s8 unk17;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
}FactoryRobotTubeStruct;

extern ActorData D_80802928_chfactoryrobot;
extern ActorData D_80802970_chfactoryrobot;
extern ActorData D_808029B8_chfactoryrobot;
extern s32 D_80802A00_chfactoryrobot;
extern s32 D_80802A38_chfactoryrobot;
extern s32 D_80802A6C_chfactoryrobot;
extern s32 D_80802A7C_chfactoryrobot;
extern s32 D_80802AB8_chfactoryrobot;
extern s32 D_80802AD4_chfactoryrobot;
extern s32 D_80802AEC_chfactoryrobot;
extern s32 D_80802890_chfactoryrobot[][3];
extern u32 D_80802A8C_chfactoryrobot;
extern s32 D_80802A9C_chfactoryrobot;
extern s32 D_80802AAC_chfactoryrobot;
extern f32 D_80802ACC_chfactoryrobot[2];
extern s32 D_80802AF4_chfactoryrobot;

void func_80800264_chfactoryrobot(Actor*);
void func_80800424_chfactoryrobot(Actor*, s32);
void func_80800508_chfactoryrobot(Actor*);
void func_808005D4_chfactoryrobot(Actor*);
s32 func_808006DC_chfactoryrobot(Actor*, f32, f32);
void func_80801160_chfactoryrobot(Actor*, s32);
s32 func_80801278_chfactoryrobot(Actor*);
void func_8080183C_chfactoryrobot(Actor*);
void func_80801954_chfactoryrobot(Actor*);
s32 func_80801A80_chfactoryrobot(Actor*);
s32 func_80801B3C_chfactoryrobot(Actor*);
s32 func_80801BB0_chfactoryrobot(Actor*);
s32 func_80801C50_chfactoryrobot(s32);
void func_80801C7C_chfactoryrobot(Actor*);
s32 func_80802398_chfactoryrobot(Actor*);
s32 func_80802470_chfactoryrobot(Actor*, s32);
void func_808025D4_chfactoryrobot(Actor*);

//Camera
ActorData* chfactoryrobot_entrypoint_0(void)
{
    return &D_80802928_chfactoryrobot;
}

//Robot
ActorData* chfactoryrobot_entrypoint_1(void)
{
    return &D_80802970_chfactoryrobot;
}

//Robot Tube
ActorData* chfactoryrobot_entrypoint_2(void)
{
    return &D_808029B8_chfactoryrobot;
}

//Camera
void func_80800024_chfactoryrobot(Actor* arg0)
{
    ((f32*)arg0->actorData)[5] = 0.0f;
    ((f32*)arg0->actorData)[7] = 0.0f;
    ((f32*)arg0->actorData)[6] = 20.0f;
    func_80105010(arg0);
}

//Camera Update
void func_80800058_chfactoryrobot(Actor* arg0)
{
    f32 sp3C[3];
    s32 temp[2];
    f32 sp28[3];

    ml_vec3f_copy(sp3C, arg0->position);
    func_800EF1B8(sp3C, arg0->rotation[1], 40.0f);
    func_800F4F34(character_getActiveIndex(), sp3C, 30.0f, 100.0f);
    switch (arg0->unk70_10)
    {
    case 1:
        func_80800264_chfactoryrobot(arg0);
        arg0->unk54 = 50.0f;
        arg0->unk50 = 20.0f;
        if (func_808006DC_chfactoryrobot(arg0, 1.0f, 15.0f) != 0)
        {
            ((f32*)arg0->actorData)[0] = rand_fBounded(1.0f, 1.2f);
            func_80101FDC(arg0, 2U);
            return;
        }
    default:
        return;
    case 2:
        func_80800264_chfactoryrobot(arg0);
        if (timer_reachedZero((f32*)arg0->actorData) != 0)
        {
            func_80101FDC(arg0, 3U);
            return;
        }
        break;
    case 3:
        func_80800264_chfactoryrobot(arg0);
        arg0->unk54 = -50.0f;
        arg0->unk50 = 20.0f;
        if (func_808006DC_chfactoryrobot(arg0, 1.0f, 15.0f) != 0)
        {
            ((f32*)arg0->actorData)[0] = rand_fBounded(1.0f, 1.2f);
            func_80101FDC(arg0, 4U);
            return;
        }
        break;
    case 4:
        func_80800264_chfactoryrobot(arg0);
        if (timer_reachedZero((f32*)arg0->actorData) != 0)
        {
            func_80101FDC(arg0, 1U);
            return;
        }
        break;
    case 5:
        func_80800264_chfactoryrobot(arg0);
        func_8010D254(&sp28[2]);
        func_800F18FC(arg0->position, &sp28[2], sp28);
        arg0->unk54 = sp28[1] - arg0->rotation[1];
        arg0->unk50 = -sp28[0];
        func_808006DC_chfactoryrobot(arg0, 4.0f, 40.0f);
        if (arg0->unk58 == 0.0f)
        {
            func_80101FDC(arg0, 3U);
        }
        break;
    }
}

//Camera
void func_80800264_chfactoryrobot(Actor* arg0)
{
    s32 var;
    timer_reachedZero(&arg0->unk58);
    if ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_8010D248() != 0) && (func_8010C500(arg0) != 0))
    {
        arg0->unk58 = 4.0f;
    }
    if (arg0->unk58 > 0.0f)
    {
        var = 1;
    }
    else
    {
        var = 0;
    }
    _subaddieDll_entrypoint_4(arg0, var);
    ((f32*)arg0->actorData)[4] = _subaddieaudioloop_entrypoint_8(arg0, arg0->position, arg0->unk58 > 0.0f, ((f32*)arg0->actorData)[4]);
    if (((arg0->unk70_10) != 5) && (arg0->unk58 > 0.0f))
    {
        func_80101FDC(arg0, 5U);
    }
}

//Camera Event Handler
s32 func_80800360_chfactoryrobot(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x40:
        func_80106790(arg0->unk3C)->unk3C = NULL;
        func_808005D4_chfactoryrobot(arg0);
        func_80107070(arg0, 3);
        break;
    case EVENT_1F_ACTOR_ONSCREEN:
        func_80800424_chfactoryrobot(arg0, arg2);

        break;
    case 0x8F:
        //Ugly
        if (*((s32*)&arg2) == 0)
        {
            func_80800508_chfactoryrobot(arg0);
        }
        break;
    case EVENT_95_ACTOR_SPAWNED:

        func_80800508_chfactoryrobot(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

//Camera
void func_80800424_chfactoryrobot(Actor* arg0, s32 arg1)
{
    s32 temp2;
    f32 sp38[3];
    s32 temp_s0;
    f32 sp28[3];

    temp_s0 = func_801040D0();
    func_801015D0(arg0);
    func_800DF41C(temp_s0);
    ml_vec3f_assign_value(sp38, 0U, ((f32*)arg0->actorData)[5], 0);
    func_800D93A0(sp28, sp38);
    func_800DFF2C(temp_s0, 0x12, sp28);
    ml_vec3f_assign_value(sp38, ((f32*)arg0->actorData)[6], 0U, 0);
    func_800D93A0(sp28, sp38);
    func_800DFF2C(temp_s0, 0x6C, sp28);
    func_800AE1E8(arg0->unk0->unk10, func_800B27E0(arg1), temp_s0);
    func_800DF72C(func_800AE080(arg0->unk0->unk10));
}

//Camera
void func_80800508_chfactoryrobot(Actor* arg0)
{
    Actor* temp_v0;

    //Find Robot Tube
    _subaddiefind_entrypoint_10(arg0, 0x3BF, arg0->unk74_7);
    temp_v0 = func_80106790(arg0->unk3C);
    temp_v0->unk3C = arg0->unk0;
    func_80101FDC(temp_v0, 1U);
    func_80103110(temp_v0, 1U);
    arg0->unk70_25 = temp_v0->unk70_25;
    arg0->unk70_4 = (temp_v0->unk70_4 > 0) ? temp_v0->unk70_4 & 0xFFFF : 1;
    func_80107200(arg0);
}

//Camera
void func_808005D4_chfactoryrobot(Actor* arg0)
{
    f32 sp44[3];
    f32 sp38[3];

    ml_vec3f_copy(sp44, arg0->position);
    func_800EF214(sp44, -arg0->rotation[0], arg0->rotation[1], 20.0f);
    func_800BBCB8(sp44, arg0->position, 1.0f, 8, &D_80802A38_chfactoryrobot);
    func_800BBCB8(sp44, arg0->position, 1.0f, 0xC, &D_80802A00_chfactoryrobot);
    func_8010D930(6, arg0->unk70_0, sp44, &D_80802A6C_chfactoryrobot);
    _subaddieaudioquick_entrypoint_2(arg0, sp44, &D_80802A7C_chfactoryrobot);
    ml_vec3f_copy(sp38, arg0->position);
    func_800EF1B8(sp38, arg0->rotation[1], -50.0f);
    _chexploder_entrypoint_3(arg0, sp38, 0);
}

//Camera
s32 func_808006DC_chfactoryrobot(Actor* arg0, f32 arg1, f32 arg2)
{
    f32 gamespeed;
    gamespeed = time_getDelta();
    arg0->unk54 = ml_clamp_f(func_80013728(arg0->unk54), -80.0f, 80.0f);
    arg0->unk50 = ml_clamp_f(func_80013728(arg0->unk50), -60.0f, 60.0f);
    ((f32*)arg0->actorData)[5] = func_800F1FF0(((f32*)arg0->actorData)[5], arg0->unk54, 0.15f, gamespeed * arg1, gamespeed * arg2);
    ((f32*)arg0->actorData)[6] = func_800F1FF0(((f32*)arg0->actorData)[6], arg0->unk50, 0.15f, gamespeed * arg1, gamespeed * arg2);
    return func_800F20BC(((f32*)arg0->actorData)[5], arg0->unk54, 4.0f);
}

//Robot
void func_808007C4_chfactoryrobot(Actor* arg0)
{
    f32 temp_f0;

    f32 sp38;
    FactoryRobotStruct* temp_s1;

    temp_s1 = func_80100094(arg0, 0U);
    func_8010A3E8(arg0, 0.4f);
    actor_enableCollision(arg0);
    ml_vec3f_to_vec3s(temp_s1->unk0, arg0->position);
    temp_f0 = arg0->rotation[1];
    temp_s1->unkC = temp_f0;
    temp_s1->unk10 = temp_f0;
    temp_s1->unk28 = 1.0f;
    temp_s1->unk24 = 0.0f;
    ml_vec3f_copy((f32*)arg0->actorData, arg0->position);
    if (arg0->unk7A_5)
    {
        if (func_80105138(arg0, arg0->position, 0, -500.0f, &sp38) != 0)
        {
            temp_s1->unk0[1] = (s16)(s32)sp38;
        }
        _subaddieDll_entrypoint_1(arg0);
        _subaddierouteDll_entrypoint_3(arg0, &temp_s1->unk34, arg0->position);
        func_80107200(arg0);
        func_80801160_chfactoryrobot(arg0, 3);
        temp_s1->unk6 = rand_fBounded(100.0f, 200.0f);
        return;
    }
    func_80801160_chfactoryrobot(arg0, 1);
    arg0->unk64_24 = 0;
    ((f32*)arg0->actorData)[1] = ((f32*)arg0->actorData)[1] + 300.0f;
    arg0->unk58 = 1.0f;
}

//Robot Update
void func_80800920_chfactoryrobot(Actor* arg0)
{
    s32 pad;
    s32 pad2;
    s32 pad3;
    FactoryRobotStruct* temp_v0;
    f32 sp4C;
    f32 sp48;
    s32 temp_v0_3;
    f32 sp40;
    f32 sp3C;
    s32 sp38;

    temp_v0 = func_80100094(arg0, 0U);
    if (!(arg0->unk7A_2))
    {

        temp_v0->unk8[1] = _subaddieaudioloop_entrypoint_6(temp_v0->unk8[1], arg0->position, temp_v0->unk20 > 0.0f, -1, &D_80802AAC_chfactoryrobot, arg0->unk70_0);
        temp_v0->unk8[0] = _subaddieaudioloop_entrypoint_6(temp_v0->unk8[0], arg0->position, 1, -1, &D_80802A9C_chfactoryrobot, arg0->unk70_0);
        if (temp_v0->unk8[0])
        {
            func_800C31DC(temp_v0->unk8[0], temp_v0->unk28);
        }
        timer_reachedZero(&temp_v0->unk1C);
        temp_v0_3 = timer_reachedZero(&temp_v0->unk20);
        if (temp_v0->unk20 > 0.0f)
        {
            if (temp_v0->unk1C == 0.0f)
            {
                if ((func_8010CFBC(arg0->position, (s32)(arg0->scale * 80.0f), (s32)(arg0->scale * 175.0f)) != 0) && (func_800F7B9C(character_getActiveIndex(), 0x51U) == 2))
                {
                    if (arg0->unk64_29)
                    {
                        temp_v0->unk1C = 1.5f;
                    }
                    else
                    {
                        temp_v0->unk1C = 6.0f;
                    }
                    temp_v0->unk18 = arg0->unk64_29;
                    temp_v0->unk20 = 0.4f;
                    func_800F57F0(character_getActiveIndex(), &sp4C);
                    _chelectricfence_entrypoint_1(arg0, &sp4C);
                }
            }
            func_800C8CB8(temp_v0->unk14, arg0->position);
            func_800C8E84(temp_v0->unk14, D_80802890_chfactoryrobot[rand_percentChance(0.35f)]);
        }
        else if (temp_v0_3 != 0)
        {
            func_800C8FE0(temp_v0->unk14, 0);
        }
        switch (arg0->unk70_10)
        {
        case 1:
            sp38 = timer_reachedZero(&arg0->unk58);
            sp48 = func_800F12D4(arg0->unk58, 0.0f, 1.0f, 1.0f, 0.0f);
            ml_vec3s_to_vec3f(&sp3C, temp_v0);
            func_800EFE50(arg0->position, &sp3C, arg0->actorData, sp48);
            if (sp38 != 0)
            {
                _subaddieDll_entrypoint_1(arg0);
                _subaddierouteDll_entrypoint_3(arg0, &temp_v0->unk34, arg0->position);
                _subaddierouteDll_entrypoint_1(arg0);
                func_80107200(arg0);
                func_80801160_chfactoryrobot(arg0, 2);
                arg0->unk64_24 = 1;
            }
            break;
        case 2:
            if (func_80801278_chfactoryrobot(arg0) != 0)
            {
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(arg0) != 0)
                {
                    func_80801160_chfactoryrobot(arg0, 3);
                    arg0->unk58 = rand_fBounded(2.0f, 4.0f);
                    func_80801C7C_chfactoryrobot(arg0);
                }
            }
            break;
        case 3:
            if (func_80801278_chfactoryrobot(arg0) != 0)
            {
                func_80801BB0_chfactoryrobot(arg0);
                func_80801A80_chfactoryrobot(arg0);
            }
            break;
        case 4:
            if (func_80801278_chfactoryrobot(arg0) != 0)
            {
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(arg0) != 0)
                {
                    func_80801160_chfactoryrobot(arg0, 5);
                    if (arg0->unk64_29)
                    {
                        arg0->unk58 = rand_fBounded(2.0f, 3.0f);
                    }
                    else
                    {
                        arg0->unk58 = rand_fBounded(4.0f, 5.0f);
                    }
                }
            }
            break;
        case 5:
            if (func_80801278_chfactoryrobot(arg0) != 0)
            {
                func_80801B3C_chfactoryrobot(arg0);
            }
            break;
        case 6:
            break;
        }
        if (!(arg0->unk64_29) && (temp_v0->unk18 != 0) && (temp_v0->unk20 == 0.0f) && (ml_vec3f_distance_sq(arg0->position, (f32*)arg0->actorData) < 62500.0f))
        {
            func_800C8FE0(temp_v0->unk14, 1);
            temp_v0->unk20 = rand_fBounded(1.2f, 1.6f);
        }
    }
}

//Robot
void func_80800DC4_chfactoryrobot(Actor* arg0)
{
    FactoryRobotStruct* temp_v0;
    s32 var_s1;

    temp_v0 = func_80100094(arg0, 0U);
    for (var_s1 = 0; var_s1 < 2; var_s1++)
    {
        temp_v0->unk8[var_s1] = _subaddieaudioloop_entrypoint_3(temp_v0->unk8[var_s1]);
    }
    if (temp_v0->unk14 != 0)
    {
        func_800C8B84(temp_v0->unk14);
        temp_v0->unk14 = 0;
    }
}

//Robot Event Handler
s32 func_80800E40_chfactoryrobot(Actor* arg0, s32 arg1, s32 arg2)
{
    FactoryRobotStruct* temp_v0;
    Actor* temp_v0_2;

    temp_v0 = func_80100094(arg0, 0U);
    switch (arg1)
    {
        case 0x40:
            func_80801160_chfactoryrobot(arg0, 7);
            break;
        case 0x2:
            if (_subaddieDll_entrypoint_3(arg0) == 0)
            {
                func_80107070(arg0, 1);
            }
            break;
        case EVENT_3E_ACTOR_TOUCHED:

            temp_v0->unk1C = arg0->unk64_29 ? 1.5f : 6.0f;

            temp_v0->unk18 = arg0->unk64_29;
            break;
        case 0x90:
            temp_v0_2 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(temp_v0_2, 3, 0);
            _chexploder_entrypoint_13(temp_v0_2, 0xAU);
            if (func_80107070(arg0, 3) == 0)
            {
                actor_mark_delete(arg0);
            }
            break;
        case 0x93:
            func_80802470_chfactoryrobot(arg0, 0);
            break;
        case EVENT_95_ACTOR_SPAWNED:
            func_8080183C_chfactoryrobot(arg0);
            break;
        case 0x38:
            return func_80801C50_chfactoryrobot((s32)arg0);
        case 0x8F:
            if (arg2 == 0)
            {
                actor_enableCollision(arg0);
                func_80109FE8(arg0, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

//Robot
void func_80800FFC_chfactoryrobot(Actor* arg0, void* arg1)
{
    FactoryRobotStruct* temp_v0;
    s32 var_s0;
    s32 sp34[3];
    s32 sp28[3];
    FactoryRobotStruct* temp_s0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((temp_v0->unk20 > 0.0f) && !(arg0->unk7A_2))
    {
        temp_s0 = func_80100094(arg0, 0U);
        temp_s0->unkA = rand_iBounded(0, 4);
    }


    var_s0 = temp_v0->unk20 > 0.0f ? ((FactoryRobotStruct*)func_80100094(arg0, 0U))->unkA : 0;

    func_800DF744(3, var_s0);
    _subaddiefade_entrypoint_9(arg0, &sp34);
    var_s0 = temp_v0->unk14 != 0;
    if (var_s0 != 0)
    {
        var_s0 = func_800C9044(temp_v0->unk14) != 0;
    }
    if (arg0->unk74_24)
    {
        _subaddiefade_entrypoint_12(arg0, 0xFF, 0xFF, 0xFF);
    }
    else if (var_s0 != 0)
    {
        func_800C8900(temp_v0->unk14, &sp28);
        _subaddiefade_entrypoint_11(arg0, &sp28);
    }
    func_80101870(arg0, arg1);
    if ((var_s0 != 0) || (arg0->unk74_24))
    {
        _subaddiefade_entrypoint_11(arg0, &sp34);
    }
}

//Robot
void func_80801160_chfactoryrobot(Actor* arg0, s32 arg1)
{
    f32 sp2C[3];

    func_80102424(arg0, arg1);
    switch (arg1)
    {
        case 2:
        case 4:
            func_80109FE8(arg0, 1);
            return;
        case 5:
            func_80109FE8(arg0, 0);
            return;
        case 1:
            func_80109FE8(arg0, 0);
            return;
        case 7:
            func_80103DFC(arg0, sp2C);
            func_80802470_chfactoryrobot(arg0, 1);
            arg0->unk64_24 = 0;
            func_800BBCB8(sp2C, sp2C, 0.8f, 1, _fxgenlist_entrypoint_2());
            func_8010D930(6, arg0->unk70_0, sp2C, &D_80802AB8_chfactoryrobot);
            _chexploder_entrypoint_3(arg0, arg0->position, 0x124);
            return;
        default:
            func_80109FE8(arg0, 1);
            return;
    }
}

//Robot
s32 func_80801278_chfactoryrobot(Actor* arg0)
{
    FactoryRobotStruct* temp_s1;
    f32 gamespeed;
    s32 pad;
    f32 sp50;
    s32 pad2;
    f32 temp_f0_2;
    s32 sp44;
    f32 var_f14;
    f32 temp_f0_3;

    temp_s1 = func_80100094(arg0, 0U);
    gamespeed = time_getDelta();
    sp50 = 1.0f;
    if (_subaddierouteDll_entrypoint_4(arg0) != 0)
    {
        if (temp_s1->unk18 == 0)
        {
            if ((temp_s1->unk1C == 0.0f) && (func_800C0638() == 0)
                && ((arg0->unk64_29) || ((func_8010D248() != 0) && (func_8010C500(arg0) != 0) && (_suchase_entrypoint_0() == arg0->unk0)))) {
                temp_s1->unk18 = 1;
                temp_s1->unk24 = rand_fBounded(2.0f, 4.0f);

                switch (arg0->unk70_10)
                {
                case 4:
                case 5:
                    func_80801160_chfactoryrobot(arg0, 2);
                    temp_s1->unk6 = rand_fBounded(100.0f, 200.0f);
                    break;
                }
            }
        }
        else if (!(arg0->unk64_29) && ((func_8010C500(arg0) == 0) || (_suchase_entrypoint_0() != arg0->unk0)))
        {
            temp_s1->unk18 = 0;
            func_80801C7C_chfactoryrobot(arg0);
        }
    }
    if (temp_s1->unk18 != 0)
    {
        var_f14 = 420.0f;
    }
    else
    {
        var_f14 = (f32)temp_s1->unk6;
    }
    ((f32*)arg0->actorData)[3] = func_800F15F8(((f32*)arg0->actorData)[3], var_f14, gamespeed * 150.0f);
    if (((f32*)arg0->actorData)[3] != 0.0f)
    {
        if (temp_s1->unk18 != 0)
        {
            func_8008FE94(5, arg0->actorData);
            if (arg0->unk64_29 != 0) {
                sp50 = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 1);
                if (temp_s1->unk1C == 0.0f)
                {
                    func_800EEB9C((f32*)&arg0->actorData[4], arg0->unk54, ((f32*)arg0->actorData)[3] * sp50);
                    ((f32*)arg0->actorData)[5] = ml_clamp_f(((f32*)arg0->actorData)[1] - arg0->position[1], -300.0f, 300.0f);
                }
                else {
                    ml_vec3f_clear((f32*)&arg0->actorData[4]);
                }
            }
            else {
                temp_f0_2 = func_80102D78(arg0, arg0->actorData);
                if (_subaddierouteDll_entrypoint_4(arg0) != 0)
                {
                    _subaddierouteDll_entrypoint_7(arg0, &temp_s1->unk34, temp_f0_2, temp_f0_2, 400.0f, 0x5000);
                    temp_s1->unk30 = arg0->unk54;
                }
                temp_s1->unk2C = func_800F1FF0(temp_s1->unk2C, temp_s1->unk30, 0.15f, time_getDelta() * 10.0f, time_getDelta() * 150.0f);
                arg0->unk54 = temp_f0_2;
                func_800EEB9C((f32*)&arg0->actorData[4], temp_s1->unk2C, ((f32*)arg0->actorData)[3]);
                ((f32*)arg0->actorData)[5] = ml_clamp_f(((f32*)arg0->actorData)[1] - arg0->position[1], -300.0f, 300.0f);
            }

            func_80801954_chfactoryrobot(arg0);
            func_8010B990(arg0, arg0->unk64_29 ? 0x204027 : 0x504427);
        }
        else
        {
            sp44 = (((u32)(u16)arg0->unk0->unk12_1)) & 0xF;
            if ((func_8001210C(0xF) == sp44) && (rand_percentChance(0.6f) != 0))
            {
                arg0->unk54 = rand_fBounded(0.0f, 359.0f);
            }
            func_80801954_chfactoryrobot(arg0);
            timer_reachedZero(&temp_s1->unk24);
            if (temp_s1->unk24 == 0.0f)
            {
                if (ml_vec3f_distance_sq((f32*)arg0->actorData, arg0->position) > 6400.0f)
                {
                    temp_f0_3 = func_80102D78(arg0, arg0->actorData);
                    if (_subaddierouteDll_entrypoint_4(arg0) != 0)
                    {
                        _subaddierouteDll_entrypoint_7(arg0, &temp_s1->unk34, temp_f0_3, temp_f0_3, 400.0f, 0x5000);
                        temp_s1->unk30 = arg0->unk54;
                    }

                    temp_s1->unk2C = func_800F1FF0(temp_s1->unk2C, temp_s1->unk30, 0.15f, time_getDelta() * 10.0f, time_getDelta() * 120.0f);
                    arg0->unk54 = temp_f0_3;
                    func_800EEB9C((f32*)&arg0->actorData[4], temp_s1->unk2C, ((f32*)arg0->actorData)[3]);
                    ((f32*)arg0->actorData)[5] = ml_clamp_f(((f32*)arg0->actorData)[1] - arg0->position[1], -300.0f, 300.0f);
                    if (func_8010B990(arg0, 0x504427) & 0x26)
                    {
                        func_80801C7C_chfactoryrobot(arg0);
                    }
                }
                else
                {
                    func_80801C7C_chfactoryrobot(arg0);
                    temp_s1->unk24 = rand_fBounded(2.0f, 4.0f);
                }
            }
            else
            {
                sp50 = 0.0f;
            }
        }
    }
    else
    {
        func_80104580(arg0);
    }

    temp_s1->unk28 += 0.7f * (func_800F12D4(((f32*)arg0->actorData)[3] * sp50, 0.0f, 420.0f, 1.0f, 1.1f) - temp_s1->unk28);
    return 1;
}

//Robot
void func_8080183C_chfactoryrobot(Actor* arg0)
{
    FactoryRobotStruct* temp_v0 = func_80100094(arg0, 0U);
    f32 sp2C[2] = D_80802ACC_chfactoryrobot;
    s32 i;

    for (i = 0; i < 2; i++)
    {
        temp_v0->unk8[i] = 0;
    }
    func_80802398_chfactoryrobot(arg0);
    sp2C[0] *= arg0->scale;
    sp2C[1] *= arg0->scale;
    temp_v0->unk14 = func_800C8A98();
    func_800C8E84(temp_v0->unk14, &D_80802890_chfactoryrobot);
    func_800C8CB8(temp_v0->unk14, arg0->position);
    func_800C8F64(temp_v0->unk14, 3);
    func_800C8D4C(temp_v0->unk14, sp2C);

    func_800C8FE0(temp_v0->unk14, temp_v0->unk20 > 0.0f);
    if ((arg0->unk70_10) != 1)
    {
        _subaddierouteDll_entrypoint_1(arg0);
    }
}

void func_80801954_chfactoryrobot(Actor* arg0)
{
    s32 temp_v0;
    f32 gamespeed;
    FactoryRobotStruct* temp_s0;

    temp_s0 = func_80100094(arg0, 0U);
    gamespeed = time_getDelta();
    if ((arg0->unk70_10) != 5)
    {
        temp_s0->unk10 = func_800F1FF0(temp_s0->unk10, arg0->unk54, 0.1f, gamespeed * 0.5f, gamespeed * 150.0f);
        temp_s0->unkC = func_800F1FF0(temp_s0->unkC, arg0->unk54, 0.2f, gamespeed * 4.0f, gamespeed * 400.0f);
    }
    temp_v0 = func_8010262C(arg0->unk0, 2U);
    if (temp_v0 != 0)
    {
        func_800E0AFC(temp_v0, 3, 1.0f, 0.0f, temp_s0->unk10, 0.0f);
        func_800E0AFC(temp_v0, 0x12, 1.0f, 0.0f, func_800136E4(temp_s0->unkC - temp_s0->unk10), 0.0f);
    }
}

//Robot
s32 func_80801A80_chfactoryrobot(Actor* arg0)
{
    FactoryRobotStruct* temp_v0;
    u32 var_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (temp_v0->unk20 > 0.0f)
    {
        return 0;
    }

    if (arg0->unk64_29 != 0)
    {
        var_v0 = _subaddiejoy_entrypoint_6(arg0, 0);
    }
    else if (temp_v0->unk18 != 0)
    {
        return 0;
    }
    else
    {
        var_v0 = timer_reachedZero(&arg0->unk58);
    }

    if (var_v0 != 0)
    {
        func_80801160_chfactoryrobot(arg0, 4);
        temp_v0->unk20 = 0.0f;
        return 1;
    }
    return 0;
}

//Robot
s32 func_80801B3C_chfactoryrobot(Actor* arg0)
{
    s32 var_v1;
    if (arg0->unk64_29)
    {
        var_v1 = _subaddiejoy_entrypoint_6(arg0, 0);
    }
    else
    {
        var_v1 = 0;
    }
    if (var_v1 != 0 || timer_reachedZero(&arg0->unk58) != 0)
    {
        func_80801160_chfactoryrobot(arg0, 2);
    }
    return var_v1;
}

s32 func_80801BB0_chfactoryrobot(Actor* arg0)
{
    FactoryRobotStruct* temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (temp_v0->unk20 > 0.0f)
    {
        return 1;
    }
    if ((arg0->unk64_29) && (_subaddiejoy_entrypoint_6(arg0, 1) != 0))
    {
        func_800C8FE0(temp_v0->unk14, 1);
        temp_v0->unk20 = rand_fBounded(1.2f, 1.6f);
        return 1;
    }
    return 0;
}

s32 func_80801C50_chfactoryrobot(s32 arg0)
{
    func_80101074(&D_80802AD4_chfactoryrobot);
    return 2;
}

void func_80801C7C_chfactoryrobot(Actor* arg0)
{
    FactoryRobotStruct* temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    func_800CD1E0(arg0->unk70_25 - 1, arg0->actorData, (f32)temp_v0->unk0[1] + 60.0f, arg0);
    temp_v0->unk6 = rand_fBounded(100.0f, 200.0f);
}

//Robot Tube
void func_80801D08_chfactoryrobot(Actor* arg0)
{
    FactoryRobotTubeStruct* temp_v1;

    temp_v1 = func_80100094(arg0, 0U);
    if (arg0->unk70_4 == 0)
    {
        arg0->unk70_4 = 1;
    }
    if (map_getCurrent() == MAP_101_GI_INSIDE)
    {
        temp_v1->unk12 = 1;
        return;
    }
    temp_v1->unk12 = 0;
}

//Robot Tube Update
void func_80801D7C_chfactoryrobot(Actor* arg0)
{
    FactoryRobotTubeStruct* temp_s2;
    u32 temp_v0;
    s32 sp6C;
    s32 sp68;
    s32 pad;
    f32 sp58[3];
    s32 pad2;
    f32 sp50;
    f32 sp44[3];
    s32 temp_s0;
    f32 sp3C;

    temp_s2 = func_80100094(arg0, 0U);
    func_800F4F34(character_getActiveIndex(), arg0->position, 100.0f, 80.0f);
    switch (arg0->unk70_10)
    {
    case 1:
        if (arg0->unk3C == NULL)
        {
            func_80101FDC(arg0, 3U);
            break;
        }
        if ((func_80106790(arg0->unk3C)->unk58 > 0.0f) && (temp_s2->unk14 == 0))
        {
            _sudialog_entrypoint_0(0x364, 4);
            pad = temp_s2->unk10;
            if (pad < temp_s2->unk11)
            {
                sp68 = 0;
                for (sp6C = 0; sp6C < temp_s2->unk10; sp6C++)
                {
                    if (
                        func_800F00A4(
                            arg0->position,
                            150.0f,
                            800.0f,
                            0,
                            func_80106790(((s32*)temp_s2)[sp6C])->position
                        ) != 0
                        )
                    {
                        sp68 = 1;
                        break;
                    }
                }
                if (sp68 == 0)
                {
                    func_80108B04(arg0, 0U);
                    func_80101FDC(arg0, 2U);
                    arg0->unk58 = rand_fBounded(1.5f, 2.5f);
                }
            }
        }
        break;
    case 2:
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            func_80101FDC(arg0, 1U);
        }
        break;
    case 4:
        if ((func_8010D23C() != 0) && (func_8010C500(arg0) != 0) && (func_8008FDC4() & 0x08000000))
        {
            _capod_entrypoint_13(arg0->unk0, NULL, 0xCU, 0x30U);
            func_80101FDC(arg0, 6U);
            arg0->unk64_20 = 0;
            arg0->unk58 = 1.0f;
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x133BU, 7U, arg0->position, 0xA3U);
        }
        break;
    case 6:
        temp_s0 = timer_reachedZero(&arg0->unk58);
        sp50 = func_800F12D4(arg0->unk58, 0.0f, 1.0f, -200.0f, 300.0f);
        ml_vec3f_copy(sp58, arg0->position);
        sp58[1] += sp50;
        func_800D1254(0x39, 1, sp58);
        if (!(arg0->unk64_20) && (arg0->unk58 < 0.7f))
        {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802AEC_chfactoryrobot);
            arg0->unk64_20 = 1;
        }
        if (temp_s0 != 0)
        {
            func_80101FDC(arg0, 9U);
        }
        break;
    case 7:
        temp_s0 = timer_reachedZero(&arg0->unk58);
        sp3C = func_800F12D4(arg0->unk58, 0.0f, 1.0f, 300.0f, -200.0f);
        ml_vec3f_copy(sp44, arg0->position);
        sp44[1] += sp3C;
        func_800D1254(0x39, 1, sp44);
        if (temp_s0 != 0)
        {
            func_80101FDC(arg0, 0xAU);
            flag_setValueTrue(FLAG_1BB_TINTOP_FIGHT_ENDED);
        }
        break;
    case 8:
        func_800D2498(0x101, temp_s2->unk13, 0);
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            func_80101FDC(arg0, 9U);
        }
        break;
    case 9:
        func_800D2498(0x101, temp_s2->unk13, 0);
        if (((s32)temp_s2->unk10 < ml_min_i((s32)temp_s2->unk11, (s32)temp_s2->unk13)) && (temp_s2->unk14 == 0))
        {
            func_80108B04(arg0, 0U);
            func_80101FDC(arg0, 8U);
            arg0->unk58 = rand_fBounded(1.5f, 2.5f);
        }
        break;
    case 3:
    case 5:
    case 10:
        break;
    }
    temp_s2->unk14 = 0U;
}

//Robot Tube
void func_8080219C_chfactoryrobot(Actor* arg0)
{
    u8 temp_a1;

    temp_a1 = ((u8*)arg0->actorData)[16];
    if (temp_a1 != 0)
    {
        func_800E8C08(temp_a1);
        ((u8*)arg0->actorData)[16] = 0U;
    }
}

void func_808021D4_chfactoryrobot(Actor* arg0, s32 arg1)
{
    u8 sp1F;
    s32 sp18;
    s32 temp_v0_2;
    u8 temp_v0;

    func_801015D0(arg0);
    temp_v0 = func_800D731C(arg0->unk0->unk14);
    sp1F = temp_v0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_800E8C58(((u8*)arg0->actorData)[16]);
        sp18 = temp_v0_2;
        func_800DBE60(sp1F, 0, temp_v0_2);
        func_800DBE60(sp1F, 1, sp18);
    }
}

//Robot Tube Event Handler
s32 func_80802240_chfactoryrobot(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_v0;
    u8 temp_a0;

    switch (arg1)
    {
        case 0x3D:
            //Get Robot
            temp_v0 = func_80108528(0x3BE, arg0->position, 0, &arg0);
            if (temp_v0 != NULL)
            {
                temp_v0->unk74_7 = arg0->unk74_7;
            }
            break;
        case EVENT_2E_ACTOR_DIALOG_ENDED:
            _capod_entrypoint_14();
            break;
        case EVENT_1F_ACTOR_ONSCREEN:
            func_808021D4_chfactoryrobot(arg0, *(s32*)&arg2);
            break;
        case EVENT_95_ACTOR_SPAWNED:
            func_808025D4_chfactoryrobot(arg0);
            break;
        case 0x29:
            ((u8*)&arg0->actorData)[0x10] = func_800E8B74(0U);
            func_800E8DB0(((u8*)&arg0->actorData)[0x10], 6);
            func_800E8D28(((u8*)&arg0->actorData)[0x10], 1.2f);
            func_800E8D5C(((u8*)&arg0->actorData)[0x10], &D_80802AF4_chfactoryrobot, 3U);
            break;
        case 0x2A:
            temp_a0 = ((u8*)&arg0->actorData)[0x10];
            if (temp_a0 != 0)
            {
                func_800E8C08(temp_a0);
                ((u8*)&arg0->actorData)[0x10] = 0U;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

//Robot
s32 func_80802398_chfactoryrobot(Actor* arg0)
{
    Actor* sp24;
    FactoryRobotTubeStruct* var_v1;

    if (arg0->unk7A_5) {
        return 0;
    }
    if (_subaddiefind_entrypoint_10(arg0, 0x3BF, arg0->unk74_7) == 0)
    {
        return 0;
    }
    //I think this is getting the tube
    sp24 = func_80106790(arg0->unk3C);
    var_v1 = func_80100094(sp24, 0U);
    if (sp24->unk7C_15 == 0)
    {
        func_808025D4_chfactoryrobot(sp24);
        sp24->unk7C_15 = 1;
    }
    var_v1->unk0[var_v1->unk10] = arg0->unk0;
    var_v1->unk10++;
    return 1;
}

//Robot
s32 func_80802470_chfactoryrobot(Actor* arg0, s32 arg1)
{
    Actor* temp_v0;
    FactoryRobotTubeStruct* sp28;
    s32 index;

    if (arg0->unk7A_5)
    {
        return 0;
    }

    if (arg0->unk3C == NULL)
    {
        return 0;
    }

    temp_v0 = func_80106790(arg0->unk3C);
    sp28 = func_80100094(temp_v0, 0U);
    if ((arg1 != 0) && (sp28->unk12 != 0))
    {
        sp28->unk13--;
        if (!(sp28->unk13))
        {
            _capod_entrypoint_13(temp_v0->unk0, NULL, 0xFU, 0x30U);
            func_80101FDC(temp_v0, 7U);
            temp_v0->unk64_20 = 0;
            temp_v0->unk58 = 1.0f;
            func_800FC660(0x10U);
            _subaddiedialog_entrypoint_11(temp_v0->unk0, 0x137BU, 0x44U, temp_v0->position, 0xA3U);
        }
    }

    arg0->unk3C = NULL;

    for (index = 0; index < sp28->unk10; index++)
    {
        if ((s32)arg0->unk0 == sp28->unk0[index])
        {
            sp28->unk0[index] = sp28->unk0[--sp28->unk10];
            return 1;
        }
    }

    return 0;
}

//Tube?
void func_808025D4_chfactoryrobot(Actor* arg0)
{
    s32 index;
    FactoryRobotTubeStruct* temp_v0;

    f32 sp2C[3];
    s32* var_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (temp_v0->unk12 != 0)
    {
        _subaddieDll_entrypoint_4(arg0, 1U);
        temp_v0->unk13 = 6;
        func_80101FDC(arg0, flag_getValue(FLAG_1BB_TINTOP_FIGHT_ENDED) ? 0xA : 4);
        ml_vec3f_copy(sp2C, arg0->position);
        sp2C[1] += 300.0f;
        func_800D1254(0x39, 1, sp2C);
    }
    else if (_subaddiefind_entrypoint_10(arg0, 0x3BD, arg0->unk74_7) == 0)
    {
        func_80101FDC(arg0, 3U);
        func_80103110(arg0, 0U);
    }
    temp_v0->unk11 = ml_clamp_i((s32)arg0->rotation[1], 1, 4);
    temp_v0->unk10 = 0;
    temp_v0->unk14 = 1;
    index = 0;
    for (index = 0; index < temp_v0->unk11; index++)
    {
        temp_v0->unk0[index] = 0;
    }
    if ((temp_v0->unk12 != 0) && (flag_getValue(FLAG2_6A3_UNK) == 0) && (func_800EA090() == 3))
    {
        _capod_entrypoint_13(arg0->unk0, NULL, 8U, 0x10U);
        flag_setValueTrue(FLAG2_6A3_UNK);
    }
}
