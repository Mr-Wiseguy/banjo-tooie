#include "ch/egg/clockwork.h"

typedef struct {
    s32 unk0[10];
    f32 unk28;
    s16 unk2C;
    s16 unk2E;
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

void func_80800000_cheggclockwork(Actor*);
void func_80800124_cheggclockwork(Actor*);
s32 func_808003B4_cheggclockwork(Actor*, s32, s32);

ActorData D_808008C0_cheggclockwork =
{
	/*0x0*/ 0x270,
	/*0x2*/ PROP_15E_CLOCKWORK_EGG,
	/*0x4*/ 0x9C4,
	/*0x6*/ 0x1,
	/*0x8*/ 0,
	/*0xC*/ func_80800124_cheggclockwork,
	/*0x10*/ func_80105834,
	/*0x14*/ _subaddiedraw25d_entrypoint_2,
	/*0x18*/ 0x0000,
	/*0x1A*/ 0x0000,
	/*0x1C*/ 1.0f,
	/*0x20*/ 0x0000,
	/*0x22*/ 0x0000,
	/*0x24*/ 0x0000,
	/*0x26*/ 0x4,
	/*0x28*/ func_80800000_cheggclockwork,
	/*0x2C*/ _suegg_entrypoint_0,
	/*0x30*/ 0x4C,
	/*0x32*/ 0,
	/*0x34*/ _suegg_entrypoint_5,
	/*0x38*/ func_80107C2C,
	/*0x3C*/ 0x8800,
	/*0x3E*/ 0,
	/*0x40*/ func_808003B4_cheggclockwork,
	/*0x44*/ 0x0000,
	/*0x46*/ 0x0000
};

//I don't know the real data type so it's just s32s for now
s32 D_80800908_cheggclockwork[] =
{
	0x001D0834,
	0x00160002,
	0x00150019,
	0x00B3001E,
	0x001E001E,
	0x002EFFB0,
	0x00000258,
	0xFFB00167,
	0x0258001B,
	0xFA24FA24,
	0x00040099,
	0x00070003,
	0x002B0280,
	0x02800026,
	0x038400C8,
	0x00000384,
	0x00C80000,
	0x00000000
};
s32 D_80800950_cheggclockwork[] =
{
	0x001D0833,
	0x000B001E,
	0x00320050,
	0x001E0015,
	0x001900B3,
	0x002EFFC4,
	0x000000C8,
	0xFFD80167,
	0x0190001B,
	0xFA24FA24,
	0x00040099,
	0x00070003,
	0x002B0200,
	0x02800026,
	0xFF38FF38,
	0xFF3800C8,
	0x00C800C8,
	0x00000000
};
s32 D_80800998_cheggclockwork[] =
{
	0x001D0835,
	0x00160002,
	0x00150019,
	0x00B3001E,
	0x001E001E,
	0x002EFFD8,
	0x0000012C,
	0xFFE20167,
	0x0190001B,
	0xFA24FA24,
	0x00040099,
	0x00070003,
	0x002B0200,
	0x02800026,
	0x000A00C8,
	0x0014000A,
	0x00C80014,
	0x00000000
};
s32 D_808009E0_cheggclockwork[] =
{
	0x001D0836,
	0x00160002,
	0x00150019,
	0x00B3001E,
	0x001E001E,
	0x002C0000,
	0x01F40000,
	0x000001F4,
	0x0000001B,
	0xFA24FA24,
	0x000400B3,
	0x00070005,
	0x002B0300,
	0x03000027,
	0x00320064,
	0x00320064,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000
};

s32 func_80800270_cheggclockwork(Actor*);
void func_808006E8_cheggclockwork(Actor*);
void func_80800048_cheggclockwork(Actor*);
void func_808007B4_cheggclockwork(Actor* arg0);
void func_808007DC_cheggclockwork(Actor*, f32*);
void func_80800850_cheggclockwork(Actor*);
void cheggclockwork_entrypoint_3(s32* arg0, s32 arg1, u32 arg2, s32 arg3);

void func_80800000_cheggclockwork(Actor* arg0)
{
    func_800F7BC8(((EggNormalData*)func_80100094(arg0, 0U))->unk3A, 0x4D, arg0->unk0);
    func_808007B4_cheggclockwork(arg0);
    _suegg_entrypoint_2(arg0);
}

void func_80800048_cheggclockwork(Actor* arg0)
{
    f32 temp_f20;
    EggNormalData* temp_s1;
    f32 sp4C[3];

    temp_s1 = (EggNormalData*)func_80100094(arg0, 0U);
    temp_s1->unk28 -= time_getDelta();
    temp_f20 = ml_map_f(temp_s1->unk30, 0.0f, 2.0f, 0.0333f, 0.1f);
    while (temp_s1->unk28 <= 0)
    {
        temp_s1->unk28 += (temp_f20);
        ml_vec3f_copy(sp4C, arg0->position);
        _fxegg_entrypoint_4(sp4C, arg0->scale);
    }
}

void func_80800124_cheggclockwork(Actor* arg0)
{
    EggNormalData* sp2C;
    s32 var_s0;

    sp2C = (EggNormalData*)func_80100094(arg0, 0U);
    var_s0 = 0;
    if (_suegg_entrypoint_9(arg0, 0) != 0)
    {
        if (func_800F693C((s32)sp2C->unk3A) != 0)
        {
            var_s0 = 2;
        }
        else
        {
            var_s0 = 1;
        }
    }
    else
    {
        arg0->scale = ml_map_f(sp2C->unk30, 0.0f, 0.134f, 0.1f, 0.25f);
        if (_sueggmove_entrypoint_3(arg0) != 0)
        {
            _suegg_entrypoint_23(arg0);
            var_s0 = 1;
        }
        if (ml_vec3f_is_zero(&arg0->actorData[4]) != 0)
        {
            var_s0 = 1;
        }
        if (sp2C->unk30 > 1.0f)
        {
            _suegg_entrypoint_3(arg0);
            var_s0 = 2;
        }
        func_80800048_cheggclockwork(arg0);
        _suegg_entrypoint_16(arg0);
    }
    if (((var_s0 == 1) || (var_s0 == 2)) && (func_80800270_cheggclockwork(arg0) == 0))
    {
        var_s0 = 3;
    }
    if (var_s0 != 0)
    {
        func_80108B04(arg0, var_s0);
        return;
    }
    func_80800850_cheggclockwork(arg0);
}

s32 func_80800270_cheggclockwork(Actor* arg0)
{
    EggNormalData* sp1C;

    sp1C = (EggNormalData*)func_80100094(arg0, 0U);
    if (func_800DB9B0() != 0) {
        return 0;
    }
    if (func_800F6D24(sp1C->unk3A) != 0) {
        return 0;
    }
    if (func_800F8088(sp1C->unk3A) != 0) {
        return 0;
    }
    return 1;
}

void func_808002DC_cheggclockwork(Actor* arg0, s32 arg1)
{
    EggNormalData* sp24;

    sp24 = (EggNormalData*)func_80100094(arg0, 0U);
    switch (arg1)
    {
    case 1:
        if (func_80800270_cheggclockwork(arg0) != 0)
        {
            func_808006E8_cheggclockwork(arg0);
            func_800F7CF4(sp24->unk3A, 0x4C, arg0->position);
        }
        _suegg_entrypoint_3(arg0);
        return;
    case 2:
        cheggclockwork_entrypoint_3(func_8001B798(sp24->unk2C), *(s32*)&arg0->rotation[1], (s32)sp24->unk3A, 1);
        actor_mark_delete(arg0);
        return;
    case 3:
        _suegg_entrypoint_3(arg0);
        return;
    }
}

s32 func_808003B4_cheggclockwork(Actor* arg0, s32 arg1, s32 arg2)
{
    EggNormalData* temp_v0;
    temp_v0 = (EggNormalData*)func_80100094(arg0, 0U);
    switch (arg1)
    {
    case 0x5:
        func_808002DC_cheggclockwork(arg0, 2);
        break;

    case 0x3D:
        if (arg2 == 1)
        {
            if (!temp_v0->unk39_3)
            {
                arg2 = 2;
            }
        }
        func_808002DC_cheggclockwork(arg0, arg2);
        break;

    case 0x2C:
        func_808002DC_cheggclockwork(arg0, 3);
        break;

    case 0x9F:
        func_808002DC_cheggclockwork(arg0, 3);
        break;

    default:
        return (arg2 == 1) * 0;

    }

    return 1;
}

ActorData* cheggclockwork_entrypoint_0(void)
{
    return &D_808008C0_cheggclockwork;
}

Actor* cheggclockwork_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Actor* temp_v0;
    EggNormalData* sp20;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15E, arg1, arg3);
    sp20 = (EggNormalData*)func_80100094(temp_v0, 0U);
    func_808007DC_cheggclockwork(temp_v0, arg0);
    sp20->unk39_3 = arg4;
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -100000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

void cheggclockwork_entrypoint_2(Vec3f arg0, f32 arg3, s32 arg4, s32 arg5)
{
    Vec3f sp24;
    f32 temp;
    sp24.f[0] = arg0.f[0];
    sp24.f[1] = arg0.f[1];
    sp24.f[2] = arg0.f[2];
    temp = *(f32*)&arg3;
    _cheggsplode_entrypoint_2(sp24.f, temp, arg4, 5, arg5);
}

void cheggclockwork_entrypoint_3(s32* arg0, s32 arg1, u32 arg2, s32 arg3)
{
    func_800C9C70(0.4f, 0x5F3U, 1.0f, 0x4E20U, arg0, 250.0f, 5400.0f);
    func_800BBCB8(arg0, NULL, 1.0f, 1, &D_80800908_cheggclockwork);
    func_800BBCB8(arg0, NULL, 1.0f, 6, &D_80800950_cheggclockwork);
    func_800BBCB8(arg0, NULL, 1.0f, 2, &D_80800998_cheggclockwork);
    func_800BBCB8(arg0, NULL, 1.0f, 1, &D_808009E0_cheggclockwork);
    _chbaddiesetup_entrypoint_6(&_cheggclockwork_entrypoint_2, arg0[0], arg0[1], arg0[2], arg1, arg2, arg3);
}

void func_808006E8_cheggclockwork(Actor* arg0)
{
    f32* temp_s0;
    temp_s0 = func_8001B798(((EggNormalData*)func_80100094(arg0, 0U))->unk2C);
    if (func_800F6DE0(arg0->position) == 0)
    {
        if (func_800F6DE0(temp_s0) != 0)
        {
            ml_vec3f_copy(arg0->position, temp_s0);
            return;
        }
        if (func_800F6DE0(temp_s0 + 0x3) != 0)
        {
            ml_vec3f_copy(arg0->position, temp_s0 + 0x3);
            return;
        }
        if (func_800F6DE0(temp_s0 + 0x6) != 0)
        {
            ml_vec3f_copy(arg0->position, temp_s0 + 0x6);
            return;
        }
        ml_vec3f_copy(arg0->position, temp_s0 + 0x6);
    }
}

void func_808007B4_cheggclockwork(Actor* arg0)
{
    func_8001B754(((EggNormalData*)func_80100094(arg0, 0U))->unk2C);
}

void func_808007DC_cheggclockwork(Actor* arg0, f32* arg1)
{
    EggNormalData* sp1C;
    f32* temp_v0;

    sp1C = (EggNormalData*)func_80100094(arg0, 0U);
    sp1C->unk2C = func_8001B668(0, 0x24);
    temp_v0 = func_8001B798(sp1C->unk2C);
    ml_vec3f_copy(temp_v0, arg1);
    ml_vec3f_copy(temp_v0 + 0x3, arg1);
    ml_vec3f_copy(temp_v0 + 0x6, arg1);
}

void func_80800850_cheggclockwork(Actor* arg0)
{
    f32 temp;
    f32* temp_v0;

    temp_v0 = func_8001B798(((EggNormalData*)func_80100094(arg0, 0U))->unk2C);
    ml_vec3f_copy(temp_v0 + 6, temp_v0 + 3);
    ml_vec3f_copy(temp_v0 + 3, temp_v0);
    ml_vec3f_copy(temp_v0, arg0->position);
}
