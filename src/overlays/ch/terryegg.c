#include "ch/terryegg.h"

void func_80800BD0_chterryegg(Actor*, s32, s32);
void func_80800C08_chterryegg(Actor*);
s32 func_80800CF4_chterryegg(Actor*, f32);
void func_80800E88_chterryegg(Actor*, s32);
void func_80800FE0_chterryegg(Actor*);
void func_80801050_chterryegg(Actor*);
void func_80801080_chterryegg(Actor*);
void func_808010B0_chterryegg(Actor*);
s32 func_808010DC_chterryegg();
s32 func_80801138_chterryegg(Actor*);
f32 func_80801188_chterryegg(Actor*, s32);

extern s32 D_80801260_chterryegg;
extern ActorData D_80801328_chterryegg;
extern ActorData D_80801370_chterryegg;
extern ActorData D_808013B8_chterryegg;

extern Prop* B_80801460_chterryegg[];
extern u32 D_8080126C_chterryegg;
extern u32 D_80801400_chterryegg;
extern s32 D_80801410_chterryegg;
extern u32 D_80801424_chterryegg;
extern u32 D_80801438_chterryegg;
extern u32 D_80801450_chterryegg;

s32* chterryegg_entrypoint_0(void) {
    return &D_80801260_chterryegg;
}
ActorData* chterryegg_entrypoint_1()
{
    return &D_80801328_chterryegg;
}
ActorData* chterryegg_entrypoint_2()
{
    return &D_80801370_chterryegg;
}
ActorData* chterryegg_entrypoint_3()
{
    return &D_808013B8_chterryegg;
}
void func_80800030_chterryegg(Actor* arg0)
{
    if ((flag_getValue((arg0->unk74_7) + 0x143) != 0) || (func_80801138_chterryegg(arg0) != 0))
    {
        actor_mark_delete(arg0);
        return;
    }
    _glsplinefind_entrypoint_0(0x357U, arg0->position);
    func_80103014(arg0);
    func_80800CF4_chterryegg(arg0, 4.0f);
}

void func_808000A8_chterryegg(Actor* arg0)
{
    s32 temp_v0;
    s32 temp_v0_2;

    switch (arg0->unk70_10)
    {
    case 1:
        temp_v0 = _plsu_entrypoint_3(arg0->unk0);
        if (temp_v0 != -1)
        {
            func_800F7BC8(temp_v0, 0x53, arg0->unk0);
        }
        break;
    case 3:
        if ((arg0->unk7C_12) && (timer_reachedZero(&arg0->unk58) != 0))
        {
            _subaddiepalette_entrypoint_2(arg0, func_80100094(arg0, 1U), 0x7BE, 0x40200000);
            func_80102424(arg0, 4);
            arg0->unk58 = 2.5f;
        }
        break;
    case 4:
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            func_80102424(arg0, 5);
            _subaddieDll_entrypoint_4(arg0, 0U);
        }
        *(f32*)&arg0->actorData[4] = ml_map_f(arg0->unk58, 0, 2.5f, 0.0f, 255.0f);
        break;
    case 5:
        temp_v0_2 = _plsu_entrypoint_3(arg0->unk0);
        if (temp_v0_2 != -1)
        {
            func_800F7BC8(temp_v0_2, 0x53, arg0->unk0);
        }
        break;
    case 6:
        func_808010B0_chterryegg(arg0);
        if (func_80101E14(arg0, 0.3f) != 0)
        {
            _chexploder_entrypoint_3(arg0, arg0->position, 8U);
            func_80102424(arg0, 7);
        }
        break;
    }
    _subaddiepalette_entrypoint_1(arg0, func_80100094(arg0, 1U));
}

s32 func_8080023C_chterryegg(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_v0;
    f32 sp40[3];
    s32 temp_v1;
    Actor* temp_v0_2;

    switch (arg1)
    {
    case 0x18:
        ml_vec3f_copy(sp40, arg0->position);
        func_800EF1B8(sp40, arg0->rotation[1] - 40.0f, 150.0f);
        func_800F77E8(character_getActiveIndex(), sp40);
        func_800F8300(character_getActiveIndex(), 2, arg0->position);
        func_80102424(arg0, 6);
        temp_v0 = func_80106790(arg0->unk3C);
        func_80102424(temp_v0, 2);
        func_80102FDC(temp_v0, func_80801188_chterryegg(temp_v0, 1));
        break;
    case 0xA0:
        temp_v1 = flag_getValue(FLAG_0E5_PROGRESS_TDL_TERRY_DEFEATED) == 0;
        if ((arg2 != 0) && (temp_v1 != 0))
        {
            if (func_800DA9E4(FLAG_039_UNK, 1) == 0)
            {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x180BU, 0xEU, NULL, 0x57U);
            }
            else
            {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x180CU, 0xFU, NULL, 0x57U);
            }
            func_80102424(arg0, 2);
        }
        return temp_v1;
    case 0x2E:
        func_80102424(arg0, 1);
        break;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_6(temp_v0, 600.0f, 800.0f);
        _chexploder_entrypoint_12(temp_v0, 0xA);
        _chexploder_entrypoint_9(temp_v0, 1, 2);
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF6BC(*(f32*)&arg0->actorData[4], 0xFF);
        _subaddiepalette_entrypoint_3(arg0, func_80100094(arg0, 1U), arg2);
        break;
    case 0x29:
        _subaddiepalette_entrypoint_4(arg0, func_80100094(arg0, 1U));
        break;
    case 0x95:
        if (_glcutDll_entrypoint_19(0x33U) != 0)
        {
            _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 1U), 0x7BD);
            func_80102424(arg0, 3);
            _subaddieDll_entrypoint_4(arg0, 1U);
            arg0->unk58 = 3.0f;
            *(f32*)&arg0->actorData[4] = 255.0f;
        }
        else if (flag_getValue(FLAG_0E5_PROGRESS_TDL_TERRY_DEFEATED) != 0)
        {
            func_80102424(arg0, 5);
            _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 1U), 0x7BE);
            *(f32*)&arg0->actorData[4] = 0.0f;
        }
        else
        {
            _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 1U), 0x7BD);
            *(f32*)&arg0->actorData[4] = 255.0f;
        }
        _subaddiefind_entrypoint_7(arg0, 0x3D6, 0x64);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080057C_chterryegg(Actor* arg0)
{
    func_80102FDC(arg0, func_80801188_chterryegg(arg0, NULL));
    func_801088A8(arg0, 0x10002000, 0, 0);
}

//R_80801228_chterryegg needs something special maybe after data migration
#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_808005C4_chterryegg.s")
#else
void func_808005C4_chterryegg(Actor* arg0)
{
    s32 sp44;
    s32* sp40;
    f32 sp34[3];
    s32 playerIndex;
    sp44 = 1;
    switch (arg0->unk70_10)
    {
    case 1:
        sp44 = 0;
        arg0->unk64_16 = 0; arg0->unk74_20 = 0;

        if (flag_getValue(FLAG_0E5_PROGRESS_TDL_TERRY_DEFEATED) != 0)
        {
            func_80800FE0_chterryegg(arg0);
        }
        break;
    case 2:
        arg0->unk64_16 = 1;
        arg0->unk74_20 = arg0->unk64_16;
        sp44 = 0;
        if (func_80101DDC(arg0) != 0)
        {
            func_800F82D4(character_getActiveIndex(), 0);
            if (func_808010DC_chterryegg() == 1)
            {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17FEU, 0xFU, arg0->position, 0U);
                flag_setMultipleValue(FLAG_361_UNK, (arg0->unk74_7) - 0x31, 3);
                func_80102424(arg0, 4);
                actor_enableCollision(arg0);
            }
            else
            {
                sp40 = func_80100094(arg0, 0U);
                flag_setValueTrue((arg0->unk74_7) + 0x143);
                func_800CB698((arg0->unk74_7) - 0x2B, 6);
                func_80102424(arg0, 5);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E1U, 0x44U, arg0->position, 0U);
                _subaddieDll_entrypoint_4(arg0, 1U);
                if (*sp40 != -1)
                {
                    _capod_entrypoint_13(arg0->unk0, NULL, R_80801228_chterryegg[0xE + arg0->unk74_7], 0x31U);
                    func_801058C4(arg0, *sp40, 200.0f, 1U);
                }
            }
        }
        break;
    case 3:
        func_80801080_chterryegg(arg0);
        break;
    case 4:
        func_80801050_chterryegg(arg0);
        break;
    case 5:
        actor_mark_delete(arg0);
        break;
    case 6:
        func_80801050_chterryegg(arg0);
        break;
    case 7:
        func_80801050_chterryegg(arg0);
        break;
    case 8:
        sp44 = 0;
        break;
    case 9:
        sp44 = 0;
        func_80801080_chterryegg(arg0);
        if (_subaddietaxi_entrypoint_1(arg0, (arg0->unk74_7) - 0x2B) != 0)
        {
            func_80102424(arg0, 0xB);
            flag_setValueTrue((arg0->unk74_7) + 0x143);
            event_sendToActorsOfType(0x36F, 0x31, (arg0->unk74_7) - 0x32);
        }
        break;
    case 10:
        func_80801050_chterryegg(arg0);
        if ((_subaddietaxi_entrypoint_11(arg0, (arg0->unk74_7) - 0x2B) != 0) && (_subaddietaxi_entrypoint_5(arg0, (arg0->unk74_7) - 0x2B) != 0))
        {
            _subaddietaxi_entrypoint_14(arg0, (arg0->unk74_7) - 0x2B);
            func_80102424(arg0, 0xC);
        }
        sp44 = _subaddietaxi_entrypoint_12(arg0, (arg0->unk74_7) - 0x2B);
        break;
    case 11:
        ml_vec3f_clear(sp34);
        arg0->unk54 = func_80102D78(arg0, sp34);
        func_80102BF8(arg0, 0.1f, 4.0f, 80.0f);
        func_80801080_chterryegg(arg0);
        break;
    case 12:
        if (_subaddietaxi_entrypoint_15(arg0, (arg0->unk74_7) - 0x2B) != 0)
        {
            func_80102424(arg0, 6);
            actor_enableCollision(arg0);
        }
        break;
    }
    _subaddietaxi_entrypoint_9(arg0, (arg0->unk74_7) - 0x2B);
    if (sp44 != 0)
    {
        playerIndex = character_getActiveIndex();
        func_800F4F34(playerIndex, arg0->position, arg0->scale * 20.0f, arg0->scale * 20.0f);
    }
}
#endif

void func_808009B4_chterryegg(Actor* arg0)
{
    if ((arg0->unk70_10) == 5)
    {
        func_80105834(arg0);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801400_chterryegg, 0.25f);
        if (func_80105A5C(arg0) != 0)
        {
            _capod_entrypoint_14();
            actor_mark_delete(arg0);
        }
    }
}

s32 func_80800A2C_chterryegg(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x3E:
        if (_subaddietaxi_entrypoint_2(arg0, (arg0->unk74_7) - 0x2B) != 0)
        {
            func_80102424(arg0, 8);
        }
        break;
    case 0x2E:
        func_80800BD0_chterryegg(arg0, ((s16*)(&arg2))[0], ((s16*)(&arg2))[1]);
        break;
    case 0x44:
        func_80800E88_chterryegg(arg0, arg2);
        break;
    case 0x95:
        if (_glcutDll_entrypoint_19(0x33U) != 0)
        {
            _subaddieDll_entrypoint_4(arg0, 1U);
        }
        if (_subaddietaxi_entrypoint_13(arg0, arg0->unk74_7 - 0x2B, &_chterryegg_entrypoint_0, 3) != 0)
        {
            func_80800C08_chterryegg(arg0);
            if (func_80801138_chterryegg(arg0) != 0)
            {
                arg0->unk64_16 = 1;
                arg0->unk74_20 = arg0->unk64_16;
                func_80102424(arg0, 6);
            }
            else
            {
                actor_disableCollision(arg0);
                arg0->unk64_16 = 0;
                arg0->unk74_20 = arg0->unk64_16;
            }
        }
        else if (arg0->unk7A_5)
        {
            actor_mark_delete(arg0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800BD0_chterryegg(Actor* arg0, s32 arg1, s32 arg2)
{
    if ((arg1 != 0x17E1) && (arg1 == 0x17FE))
    {
        func_80102424(arg0, 6);
    }
}

void func_80800C08_chterryegg(Actor* arg0)
{
    s32* sp1C;

    sp1C = func_80100094(arg0, 0U);
    *sp1C = _glsplinefind_entrypoint_0(0x357U, arg0->position);
}

void func_80800C48_chterryegg(Actor* arg0)
{
    func_8010C964();
    func_80801080_chterryegg(arg0);
}
s32 func_80800C70_chterryegg(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 0x95)
    {
        func_80800CF4_chterryegg(arg0, func_80801188_chterryegg(arg0, NULL));
        func_80101EE4(arg0, rand_f());
        if (flag_getValue((arg0->unk74_7) + 0x143) == 0)
        {
            actor_mark_delete(arg0);
        }
        return 1;
    }
    return 0;
}

s32 func_80800CF4_chterryegg(Actor* arg0, f32 arg1)
{
    func_80102FDC(arg0, arg1);
    return 1;
}

void func_80800D20_chterryegg(s32 arg0, s32* arg1, u32 arg2, Unk80132ED0* arg3)
{
    if (flag_getValue(arg0 + 0x16E) == 0)
    {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, arg1[0], arg1[1], arg1[2], arg2, arg3);
    }
}

void func_80800D88_chterryegg(s32 arg0, f32* arg1)
{
    Prop* temp_a1;
    s32 index;
    s32 temp_v0;

    temp_v0 = _gccubesearch_entrypoint_9(0x3D7, &B_80801460_chterryegg, 4);
    for (index = 0; index < temp_v0; index++)
    {
        if ((arg0 + 0x2B) == (B_80801460_chterryegg[index]->unk6_7))
        {
            ml_vec3s_to_vec3f(arg1, B_80801460_chterryegg[index]->position);
            return;
        }
    }
}

s32 func_80800E0C_chterryegg(s32 arg0, s32 arg1, f32* arg2)
{
    if ((map_getCurrent() == MAP_113_TDL_TERRYS_NEST) && (func_800CBD84(arg1) != -1))
    {
        func_80800D88_chterryegg(arg0, arg2);
        return 2;
    }
    func_800C05B8(0x17E0, 1, NULL, NULL, 0, 0, 0);
    return 1;
}

void func_80800E88_chterryegg(Actor* arg0, s32 arg1)
{
    f32 sp2C[3];

    func_80100120(arg0);
    func_80800CF4_chterryegg(arg0, func_80801188_chterryegg(arg0, 0));
    switch (func_800CB3E0(arg1))
    {
    case 1:
        if ((flag_getValue((arg0->unk74_7) + 0x143) != 0) || (func_80801138_chterryegg(arg0) != 0))
        {
            func_80102424(arg0, 6);
            actor_enableCollision(arg0);
            return;
        }
        func_80800C08_chterryegg(arg0);
        func_80102424(arg0, 1);
        actor_disableCollision(arg0);
        arg0->unk64_16 = 0;
        arg0->unk74_20 = arg0->unk64_16;
        return;
    case 3:
        _subaddietaxi_entrypoint_10(arg0, arg1, 0xA);
        return;
    case 4:
        func_80800D88_chterryegg(arg1, sp2C);
        actor_disableCollision(arg0);
        _subaddietaxi_entrypoint_0(arg0, arg1, sp2C, 9);
        return;
    case 6:
        func_80102424(arg0, 0xB);
        actor_disableCollision(arg0);
        return;
    }
}

void func_80800FE0_chterryegg(Actor* arg0)
{
    timer_reachedZero(&arg0->unk58);
    if (arg0->unk58 <= 0.0f)
    {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801410_chterryegg);
        arg0->unk58 = rand_fBounded(1.5f, 2.5f);
    }
}

void func_80801050_chterryegg(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801424_chterryegg, 0.81f);
}

void func_80801080_chterryegg(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_8080126C_chterryegg, &D_80801438_chterryegg);
}

void func_808010B0_chterryegg(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801450_chterryegg, 0.0f);
}

s32 func_808010DC_chterryegg()
{
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = flag_getMultipleValue(FLAG_175_UNK, 4);
    var_v1 = 0;
    if (temp_v0 & 1)
    {
        var_v1 = 1;
    }
    if (temp_v0 & 2)
    {
        var_v1 += 1;
    }
    if (temp_v0 & 4)
    {
        var_v1 += 1;
    }
    if (temp_v0 & 8)
    {
        var_v1 += 1;
    }
    return 4 - var_v1;
}

s32 func_80801138_chterryegg(Actor* arg0)
{
    s32 temp_v0;

    temp_v0 = flag_getMultipleValue(FLAG_361_UNK, 3);
    if (temp_v0 == 0)
    {
        return 0;
    }
    return (arg0->unk74_7) == (temp_v0 + 0x31);
}

f32 func_80801188_chterryegg(Actor* arg0, s32 arg1)
{
    if (arg1 != NULL)
    {
        return func_808010DC_chterryegg() == 1 ? 4.0f : 2.0f;
    }

    return func_80801138_chterryegg(arg0) != 0 ? 4.0f : 2.0f;
}