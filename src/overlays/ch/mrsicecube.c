#include "ch/mrsicecube.h"

extern s32 D_808008F0_chmrsicecube;
extern u16 D_80800910_chmrsicecube[][2];
extern ActorData D_8080099C_chmrsicecube;
extern ActorData D_808009E4_chmrsicecube;
extern u32 D_80800A2C_chmrsicecube;
extern s32 D_80800A3C_chmrsicecube;
extern s32 D_80800A44_chmrsicecube;
extern s32 D_80800A54_chmrsicecube;
extern u32 D_80800AB8_chmrsicecube;
extern s32 D_80800A64_chmrsicecube;
extern s32 D_80800A74_chmrsicecube;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} MRSICECUBEStruct;

Unk80132ED0* func_80800508_chmrsicecube(Actor*);
void func_80800634_chmrsicecube(Actor*);
void func_8080066C_chmrsicecube(Actor*, f32*);
void func_808006C4_chmrsicecube(Actor*);
void func_80800818_chmrsicecube(Actor*);
void func_80800898_chmrsicecube(Actor*);
ActorData* chmrsicecube_entrypoint_0()
{
    return &D_8080099C_chmrsicecube;
}
ActorData* chmrsicecube_entrypoint_1()
{
    return &D_808009E4_chmrsicecube;
}

void func_80800018_chmrsicecube(Actor* arg0)
{
    s32* sp24;

    sp24 = func_80100094(arg0, 0U);
    func_8010A800(arg0, 0);
    _subaddielink_entrypoint_0(sp24);
    arg0->actorData[4] = (arg0->unk74_7) - 0x32;
    if (arg0->actorData[4] == 0)
    {
        actor_setCollision(arg0, flag_getValue(FLAG_1C5_UNK));
        if (_glcutDll_entrypoint_20() != 0)
        {
            func_80102424(arg0, 7);
            return;
        }
        if (flag_getValue(FLAG_378_PHYSICAL_HFP_KilledMildred) != 0)
        {
            actor_mark_delete(arg0);
        }
    }
}

void func_808000BC_chmrsicecube(Actor* arg0)
{
    s32* sp44;
    Actor* temp_v0;
    s32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    sp44 = func_80100094(arg0, 0U);
    sp3C = 0;
    switch (arg0->unk70_10)
    {
    case 2:
        func_80800634_chmrsicecube(arg0);
        break;
    case 3:
        arg0->unk64_19 = 1;
        func_80800898_chmrsicecube(arg0);
        sp3C = 1;
        if (func_80101DDC(arg0) != 0)
        {
            func_80102424(arg0, 4);
        }
        break;
    case 5:
        sp3C = 1;
        if (func_80101DDC(arg0) != 0)
        {
            arg0->unk64_19 = 0;
            func_80102424(arg0, 2);
        }
        break;
    case 6:
        if (_subaddieDll_entrypoint_6(arg0, 0xA) != 0)
        {
            func_808006C4_chmrsicecube(arg0);
        }
        break;
    case 7:
        func_80800898_chmrsicecube(arg0);
        sp3C = 1;
        arg0->unk64_19 = 1;
        if (func_80101DDC(arg0) != 0)
        {
            func_80102424(arg0, 8);
        }
        break;
    }
    temp_v0 = _subaddielink_entrypoint_4(sp44);
    if (temp_v0 != 0)
    {
        func_8080066C_chmrsicecube(arg0, sp30);
        ml_vec3f_copy(temp_v0->position, sp30);
        if ((sp3C != 0) && (_subaddieskeleton_entrypoint_0(arg0, 3, sp24) != 0))
        {
            temp_v0->position[1] += (sp24[1] - arg0->position[1]);
        }
    }
}

s32 func_80800260_chmrsicecube(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 temp_v0;
    s32* sp20;

    switch (arg1)
    {
        case EVENT_2E_ACTOR_DIALOG_ENDED:
            temp_v0 = ((s16*)&arg2)[0];
            if (_subaddiedialog_entrypoint_9(arg0, temp_v0, &D_808008F0_chmrsicecube, 4) == 1)
            {
                actor_enableCollision(arg0);
            }
            func_80102424(arg0, 5);
            break;
        case 0x40:
            if (_subaddieDll_entrypoint_5(arg0, arg2) != 0)
            {
                func_80103110(arg0, 1U);
                _subaddieDll_entrypoint_4(arg0, 1U);
                func_80102424(arg0, 6);
            }
            else
            {
                func_808006C4_chmrsicecube(arg0);
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800A2C_chmrsicecube, arg0->scale);
            break;
        case EVENT_95_ACTOR_SPAWNED:
            sp20 = func_80100094(arg0, 0U);
            temp_v0 = func_80800508_chmrsicecube(arg0);
            if (temp_v0 != 0)
            {
                _subaddielink_entrypoint_1(sp20, temp_v0);
            }
            else if ((arg0->actorData[4] != 0) || (_glcutDll_entrypoint_20() == 0))
            {
                actor_mark_delete(arg0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003BC_chmrsicecube(Actor* arg0, void* arg1)
{
    Actor* temp_v0;

    if (func_800E3E8C(arg0->position, func_80103FB8(arg0)) != 0)
    {
        temp_v0 = _subaddielink_entrypoint_4(func_80100094(arg0, 0U));
        if (temp_v0 != 0)
        {
            func_8010A764(temp_v0, arg1);
        }
        func_800DF744(3, arg0->unk64_19);
        func_80101870(arg0, arg1);
    }
}

Actor* func_8080043C_chmrsicecube(Actor* arg0, s32 arg1, f32* arg2)
{
    Actor* temp_v0;

    temp_v0 = _subaddiefind_entrypoint_0(arg0->position, arg1, -1, 0);
    if (temp_v0 != NULL)
    {
        ml_vec3f_copy(arg2, temp_v0->position);
    }
    return temp_v0;
}

Actor* func_8080048C_chmrsicecube(Actor* arg0, s32 arg1, f32* arg2)
{
    u32* temp_v0;
    Actor* var_v1;

    D_80800A3C_chmrsicecube = arg1;
    temp_v0 = _gccubesearch_entrypoint_6(&D_80800A3C_chmrsicecube, arg0->position);
    if (temp_v0 == NULL)
    {
        return NULL;
    }
    var_v1 = _subaddiefind_entrypoint_12(temp_v0[4] >> 21);
    if (var_v1 != NULL)
    {
        ml_vec3s_to_vec3f(arg2, temp_v0);
    }
    return var_v1;
}

Unk80132ED0* func_80800508_chmrsicecube(Actor* arg0)
{
    u32 temp_s0;
    Actor* var_v0;
    f32 sp2C[3];
    MRSICECUBEStruct* sp28;

    temp_s0 = arg0->actorData[4];
    sp28 = func_80100094(arg0, 0U);
    if (D_80800910_chmrsicecube[temp_s0][0] == PROP_1F4_JINJO_REAL)
    {
        var_v0 = func_8080043C_chmrsicecube(arg0, D_80800910_chmrsicecube[temp_s0][0], sp2C);
    }
    else
    {
        var_v0 = func_8080048C_chmrsicecube(arg0, D_80800910_chmrsicecube[temp_s0][0], sp2C);
    }
    if ((var_v0 != NULL) && (ml_vec3f_distance_sq(&sp2C, arg0->position) < 40000.0f))
    {
        sp28->unk8 = var_v0->unk74_20;
        actor_disableCollision(var_v0);
        func_8010A624(var_v0);
        func_80102190(var_v0, 1);
        func_80103110(var_v0, 0U);
        var_v0->unk64_24 = 0;
        var_v0->unk64_16 = 0;
        var_v0->unk74_20 = 0;
        func_8080066C_chmrsicecube(arg0, var_v0->position);
        if (var_v0->unk74_5)
        {
            func_80103014(var_v0);
        }
        return var_v0->unk0;
    }
    return NULL;
}

void func_80800634_chmrsicecube(Actor* arg0)
{
    _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80800A44_chmrsicecube, &D_808008F0_chmrsicecube, 4);
}

void func_8080066C_chmrsicecube(Actor* arg0, f32* arg1)
{
    ml_vec3f_copy(arg1, arg0->position);
    arg1[1] += arg0->scale * 100.0f;
}

void func_808006C4_chmrsicecube(Actor* arg0)
{
    MRSICECUBEStruct* sp2C;
    Actor* temp_s0;
    s32 temp_v1;

    sp2C = func_80100094(arg0, 0U);
    temp_s0 = _subaddielink_entrypoint_4(sp2C);
    temp_v1 = arg0->actorData[4];
    if (!temp_v1)
    {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x12D3U, 0x44U, NULL, 0xA7U);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800A54_chmrsicecube);
        flag_setValueTrue(FLAG_378_PHYSICAL_HFP_KilledMildred);
    }
    if (temp_s0 != 0)
    {
        _subaddielink_entrypoint_0(sp2C);
        actor_enableCollision(temp_s0);
        func_8010A654(temp_s0, func_80102F74(temp_s0, 0x800));
        func_80102190(temp_s0, 0);
        func_80103110(temp_s0, func_80102F74(temp_s0, 0x80000800) == 0);
        temp_s0->unk64_24 = func_80102F74(temp_s0, 0x80000001);
        temp_s0->unk64_16 = 1;
        temp_s0->unk74_20 = sp2C->unk8;
        _chbounce_entrypoint_5(D_80800910_chmrsicecube[arg0->actorData[4]][1], temp_s0);
    }
    func_80800818_chmrsicecube(arg0);
    actor_mark_delete(arg0);
}

void func_80800818_chmrsicecube(Actor* arg0)
{
    f32 sp2C[3];

    func_8080066C_chmrsicecube(arg0, sp2C);
    func_800BBCB8(sp2C, arg0->position, arg0->scale, 0xC, &D_80800A74_chmrsicecube);
    _subaddieaudioquick_entrypoint_2(arg0, &sp2C, &D_80800A64_chmrsicecube);
    func_801094E0(sp2C, arg0->scale * 3.0f);
}
void func_80800898_chmrsicecube(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800AB8_chmrsicecube, 0.1f);
}