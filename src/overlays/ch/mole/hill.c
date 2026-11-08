#include "ch/molehill.h"

extern s32 D_80800AC0_chmolehill;
extern s32 D_80800ACC_chmolehill;
extern s32 D_80800ADC_chmolehill;
extern s32 D_80800B5C_chmolehill[];
extern s32 _chmolehill_entrypoint_0;

s32 func_80800000_chmolehill(Actor* arg0)
{

    if (func_8010CAC0(arg0->position, 0x87U) != 0)
    {
        return 0;
    }

    if (mlAbsF(func_800F1DCC(func_8010CD28(arg0), arg0->rotation[1] + 15.0f)) > 5.0f)
    {
        return 0;
    }
    return 1;
}

void func_80800088_chmolehill(Actor* arg0)
{
    f32 sp34[3];
    f32 sp28[3];
    f32 temp_f0;
    f32 var_f2;

    if (arg0->unk64_20)
    {
        func_8010D254(sp28);
        temp_f0 = func_800F1DF4(arg0->position, sp28);
        var_f2 = ml_absNormalizeAngle_f(func_800F1DCC(temp_f0, arg0->rotation[1] + 15.0f));
        if (var_f2 < -15.0f)
        {
            var_f2 = -15.0f;
        }
        if (var_f2 > 15.0f)
        {
            var_f2 = 15.0f;
        }
        temp_f0 -= var_f2;
        ml_vec3f_copy(sp34, arg0->position);
        ml_translateAngleDist(sp34, temp_f0, 150.0f);
        func_8008F964(sp34);
    }
}

void func_80800160_chmolehill(Actor* arg0)
{
    s32 sp3C;
    s32 pad;

    sp3C = 0;
    arg0->unk64_19 = 0;
    switch (arg0->unk79_4)
    {
    case 0:
    case 2:
    case 5:
    case 6:
        break;
    case 7:
        chmolehill_entrypoint_1(arg0, 0);
        chmolehill_entrypoint_2(arg0, 0xD);
        break;
    case 1:
        func_80800088_chmolehill(arg0);
        if ((arg0->unk3C != NULL) && (func_80800000_chmolehill(arg0) != 0))
        {
            func_8008F8B0();
            chmolehill_entrypoint_1(arg0, 0);
            chmolehill_entrypoint_2(arg0, 2);
        }
        break;
    case 3:
        func_80800088_chmolehill(arg0);
        if ((arg0->unk3C != NULL) && (func_80800000_chmolehill(arg0) != 0))
        {
            func_8008F8B0();
            chmolehill_entrypoint_1(arg0, 0);
            chmolehill_entrypoint_2(arg0, 7);
        }
        break;
    case 4:
        chmolehill_entrypoint_1(arg0, 0);
        chmolehill_entrypoint_2(arg0, 8);
        break;
    }
    switch (arg0->unk70_10)
    {
        case 0xA:
        {
            arg0->unk64_19 = 1;
            break;
        }
        case 9:
        {
            arg0->unk64_19 = 1;
            break;
        }
        default:
        case 2:
        case 7:
            break;
    }
    if ((arg0->unk8C != 0) && (anctrl_getPlaybackType(func_80104248(arg0)) != 3))
    {
        switch (func_801022E4(arg0))
        {
        case 0x229:
            if (func_80101E14(arg0, 0.288f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AC0_chmolehill);
            }
            else if ((func_80101E14(arg0, 0.69f) != 0) || (func_80101E14(arg0, 0.76f) != 0))
            {
                sp3C = 1;
            }
            break;
        case 0x22A:
            if (func_80101E14(arg0, 0.16f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AC0_chmolehill);
            }
            else if ((func_80101E14(arg0, 0.86f) != 0) || (func_80101E14(arg0, 0.98f) != 0))
            {
                sp3C = 1;
            }
            break;
        case 0x22B:
            if (func_80101E14(arg0, 0.2f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800ACC_chmolehill);
            }
            break;
        case 0x22C:
            if (func_80101E14(arg0, 0.48f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AC0_chmolehill);
            }
            else if ((func_80101E14(arg0, 0.7136f) != 0) || (func_80101E14(arg0, 0.9336f) != 0))
            {
                sp3C = 1;
            }
            break;
        case 0x22E:
        {
            s32 sp24[5] = (D_80800B5C_chmolehill);
            if (func_80101E14(arg0, 0.04f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AC0_chmolehill);
            }
            else if (func_80101E4C(arg0, &sp24) != 0)
            {
                sp3C = 1;
            }
            break;
        }
        }
    }
    if (sp3C != 0)
    {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800ADC_chmolehill);
    }
}

void chmolehill_entrypoint_0(Unk80132ED0* arg0)
{
    Actor* sp24;
    Actor* temp_v0;
    s32 pad;

    sp24 = func_80106790(arg0);
    if (arg0) {}
    temp_v0 = func_801084B0(0x18F, &sp24);
    sp24->unk3C = temp_v0->unk0;
    temp_v0->unk3C = sp24->unk0;
    func_80108944(temp_v0, sp24);
    _chmoley_entrypoint_1(temp_v0, sp24->unk70_10);
}

void func_8080058C_chmolehill(Actor* arg0)
{
    f32 sp3C[3];
    f32 sp30[3];
    f32 temp_f0;
    f32 var_f2;

    if (func_80800000_chmolehill(arg0) == 0)
    {
        func_8010D254(sp30);
        temp_f0 = func_800F1DF4(arg0->position, sp30);
        var_f2 = ml_absNormalizeAngle_f(func_800F1DCC(temp_f0, arg0->rotation[1] + 15.0f));
        var_f2 = var_f2;
        if (var_f2 < -15.0f)
        {
            var_f2 = -15.0f;
        }
        if (var_f2 > 15.0f)
        {
            var_f2 = 15.0f;
        }
        temp_f0 -= var_f2;
        ml_vec3f_copy(sp3C, arg0->position);
        ml_translateAngleDist(sp3C, temp_f0, 150.0f);
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F938(1);
        func_8008F904(func_8010D5DC, arg0->unk0);
        func_8008F990(sp3C, 300.0f);
        arg0->unk64_20 = 1;
    }
}

void chmolehill_entrypoint_1(Actor* arg0, s32 arg1)
{
    Unk80132ED0* temp_a0;

    arg0->unk79_4 = arg1;
    switch (arg0->unk79_4)
    {
    case 1:
    case 3:
        _chbaddiesetup_entrypoint_1(&_chmolehill_entrypoint_0, arg0->unk0);
        func_8080058C_chmolehill(arg0);
        break;
    case 7:
        arg0->unk70_10 = 13;
        _chbaddiesetup_entrypoint_1(&_chmolehill_entrypoint_0, arg0->unk0);
        break;
    }
    if (arg0->unk3C != NULL)
    {
        _chmoley_entrypoint_0(func_80106790(arg0->unk3C), arg1);
    }
}

void chmolehill_entrypoint_2(Actor* arg0, s32 arg1)
{
    if (arg1 != arg0->unk70_10)
    {
        func_80102424(arg0, arg1);
        if (arg0->unk70_10 == 1)
        {
            if (arg0->unk3C != NULL)
            {
                func_800FFA88(arg0->unk3C);
                arg0->unk3C = NULL;
            }
        }
        if (arg0->unk3C != NULL)
        {
            _chmoley_entrypoint_1(func_80106790(arg0->unk3C), arg1);
        }
    }
}

s32 chmolehill_entrypoint_3(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 0:
    case 1:
    case 3:
    case 11:
        return 0;
    case 7:
    case 8:
    case 9:
        return 0;
    case 2:
    case 4:
    case 5:
    case 6:
    case 10:
        return 1;
    default:
        return 0;
    }
}
typedef struct {
    s32 unk0;
}MoleHillMem;
void chmolehill_entrypoint_4(Actor* arg0, s32 arg1)
{
    ((MoleHillMem*)actor_getAdditionalMem(arg0, 0U))->unk0 = arg1;
}

s32 chmolehill_entrypoint_5(Actor* arg0)
{
    return ((MoleHillMem*)actor_getAdditionalMem(arg0, 0U))->unk0;
}

void func_80800884_chmolehill(Actor* arg0)
{
    u8 sp27;

    sp27 = func_800D731C(arg0->unk0->unk14);
    if (arg0->unk74_30)
    {
        *(f32*)&arg0->actorData[4] += 15.0f * time_getDelta();
        if (*(f32*)&arg0->actorData[4] >= 8.49f)
        {
            *(f32*)&arg0->actorData[4] = 8.49f;
            arg0->unk74_30 = 0;
        }
    }
    else
    {
        *(f32*)&arg0->actorData[4] -= (15.0f * time_getDelta());
        if (*(f32*)&arg0->actorData[4] <= 0.0f)
        {
            *(f32*)&arg0->actorData[4] = 0.0f;
            arg0->unk74_30 = 1;
        }
    }
    if (sp27 != 0)
    {
        func_800DBE60(sp27, 0, *(f32*)&arg0->actorData[4]);
        func_800DBE60(sp27, 1, *(f32*)&arg0->actorData[4]);
    }
}
s32 func_808009A0_chmolehill(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 var_a1;

    switch (arg1)
    {
    case 0x32:
        func_8080058C_chmolehill(arg0);
        break;
    case EVENT_1F_ACTOR_ONSCREEN:
        func_801015D0(arg0);
        func_80800884_chmolehill(arg0);
        if ((arg0->unk74_29) || (_glcutDll_entrypoint_20() != 0))
        {
            var_a1 = 2;
        }
        else
        {
            var_a1 = 1;
        }
        func_800DF744(3, var_a1);
        break;
    default:
        return 0;
    }
    return 1;

}

extern ActorData D_80800B70_chmolehill;
ActorData* chmolehill_entrypoint_6()
{
    return &D_80800B70_chmolehill;
}
