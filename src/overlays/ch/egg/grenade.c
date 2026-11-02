#include "ch/egg/grenade.h"
typedef struct {
    s32 unk0[10];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s8 unk38;
    u8 unk39_7 : 1;
    u8 unk39_6 : 1;
    u8 unk39_5 : 1;
    u8 unk39_4 : 1;
    u8 unk39_3 : 1;
    u8 unk39_2 : 1;
    u8 unk39_1 : 1;
    u8 unk39_0 : 1;
    s16 unk3A;
} EggNormalData;
void func_80800164_chegggrenade(Actor* arg0);
ActorData D_80800450_chegggrenade =
{
    /*0x0*/ 0x26F,
    /*0x2*/ 0x15D,
    /*0x4*/ 0x9C2,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_80800164_chegggrenade,
    /*0x10*/ func_80105834,
    /*0x14*/ _subaddiedraw25d_entrypoint_2,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 1.0f,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x0000,
    /*0x26*/ 0x4,
    /*0x28*/ _suegg_entrypoint_2,
    /*0x2C*/ _suegg_entrypoint_0,
    /*0x30*/ 0x4C,
    /*0x32*/ 0,
    /*0x34*/ _suegg_entrypoint_5,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8800,
    /*0x3E*/ 0,
    /*0x40*/ _suegg_entrypoint_17,
    /*0x44*/ 0x0000,
    /*0x46*/ 0x0000
};

void func_80800000_chegggrenade(Actor* arg0)
{
    s32 temp[2];
    f32 sp68[3];
    f32 sp58[3];
    f32 temp_f24;
    EggNormalData* temp_s3;

    temp_s3 = (EggNormalData*)func_80100094(arg0, 0U);
    temp_s3->unk28 = (f32)(temp_s3->unk28 - time_getDelta());
    temp_f24 = ml_map_f(temp_s3->unk30, 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(arg0, sp58);
    while (temp_s3->unk28 <= 0.0f)
    {
        temp_s3->unk28 += temp_f24;
        ml_vec3f_copy(sp68, arg0->position);
        _fxegg_entrypoint_5(arg0->position, sp58, arg0->scale);
    }
}

void chegggrenade_entrypoint_0(Unk80132ED0* arg0)
{
    Actor* temp_v0;
    s32 pad;
    s32 sp1C;
    temp_v0 = func_80106790(arg0);
    sp1C = ((EggNormalData*)func_80100094(temp_v0, 0U))->unk3A;
    _cheggsplode_entrypoint_1(&temp_v0, sp1C, _gcegg_entrypoint_0((u32)arg0->unk24_22));
    _suegg_entrypoint_4(temp_v0, 0);
}

void func_80800164_chegggrenade(Actor* arg0)
{
    EggNormalData* sp2C;

    // @hack
    do {} while (0);
    sp2C = (EggNormalData*)func_80100094(arg0, 0U);
    switch (arg0->unk70_10)
    {
    case 1:
        if (_suegg_entrypoint_8(arg0) == 0)
        {
            if (ml_vec3f_is_zero(&arg0->actorData[4]) != 0)
            {
                sp2C->unk39_7 = 1;
            }
            else
            {
                func_80800000_chegggrenade(arg0);
                _suegg_entrypoint_16(arg0);
                if (_suegg_entrypoint_14(arg0) != 0)
                {
                    sp2C->unk39_7 = 1;
                }
            }
        }
        break;
    case 2:
        if (_suegg_entrypoint_8(arg0) == 0)
        {
            arg0->scale = ml_map_f(sp2C->unk30, 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(arg0) != 0)
            {
                _suegg_entrypoint_23(arg0);
            }
            if (_suegg_entrypoint_13(arg0) != 0)
            {
                sp2C->unk39_7 = 1;
            }
            else if (_suegg_entrypoint_12(arg0) != 0)
            {
                _sueggmisc_entrypoint_1(arg0);
            }
            else
            {
                func_80800000_chegggrenade(arg0);
                _suegg_entrypoint_16(arg0);
            }
        }

        break;
    }
    if (sp2C->unk39_7 && !sp2C->unk39_6)
    {
        _chbaddiesetup_entrypoint_1(&_chegggrenade_entrypoint_0, arg0->unk0);
    }
}

ActorData* chegggrenade_entrypoint_1(void) {
    return &D_80800450_chegggrenade;
}

Actor* chegggrenade_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    Actor* temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15D, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

Actor* chegggrenade_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Actor* temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15D, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
