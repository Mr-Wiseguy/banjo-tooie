#include "ch/evilmumbo.h"

typedef struct {
    f32 unk0[1][3];
    s8 padC[0x6C];
    f32 unk78[3];
    u8 unk84;
    u8 unk85;
    u8 unk86;
    u8 unk87;
    u8 unk88;
    u8 unk89;
    u8 unk8A;
    u8 unk8B;
    u8 unk8C;
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
    u8 unk90;
    u8 unk91;
    u8 unk92;
    u8 unk93;
    u8 unk94;
    u8 unk95;
    u8 unk96;
}CHEVILMUMBO;

extern s32 D_80804140_chevilmumbo;
extern s32 D_8080414C_chevilmumbo;
extern s32 D_80804190_chevilmumbo;
extern s32 D_80804198_chevilmumbo;
extern s32 D_808041C0_chevilmumbo;
extern u32 D_80804208_chevilmumbo;
extern s32 D_80804220_chevilmumbo;
extern u32 D_80804234_chevilmumbo;
extern f32 D_8080427C_chevilmumbo[3];
extern s32 D_80804294_chevilmumbo;
extern s32 D_808042A0_chevilmumbo;
extern s32 D_808042D0_chevilmumbo;
extern s32 D_808042F4_chevilmumbo;
extern s32 D_80804304_chevilmumbo;
extern s32 D_8080434C_chevilmumbo;
extern s32 D_808044A8_chevilmumbo;
extern u32 D_808044E4_chevilmumbo;
extern f32 D_80804538_chevilmumbo;

void func_808000BC_chevilmumbo(Actor*);
void func_80800ECC_chevilmumbo(Actor*, s32);
void func_8080362C_chevilmumbo(Actor*, s32);

void func_80800000_chevilmumbo(Actor* actor)
{
    CHEVILMUMBO* temp_v0;
    f32 sp20[3];

    temp_v0 = (CHEVILMUMBO*)actor_getAdditionalMem(actor, 0U);
    if ((temp_v0->unk95 == 3) && (func_800F6C88(character_getActiveIndex()) == 0))
    {
        ml_vec3f_copy(sp20, actor->position);
        sp20[1] += 100.0f;
        if (_plcamera_entrypoint_9(character_getActiveIndex(), sp20, 0.25f) == 0)
        {
            temp_v0->unk95 = 0;
            func_808000BC_chevilmumbo(actor);
        }
    }
}

void func_80800098_chevilmumbo(Actor* arg0) {
    _capod_entrypoint_3(0U);
}

void func_808000BC_chevilmumbo(Actor* actor)
{
    CHEVILMUMBO* sp1C;

    sp1C = (CHEVILMUMBO*)actor_getAdditionalMem(actor, 0U);
    switch (sp1C->unk95)
    {
    case 1:
    case 2:
        func_80800098_chevilmumbo(actor);
    case 0:
    case 3:
        sp1C->unk95 = 3U;
        func_800F4AF4(character_getActiveIndex(), 0x14);
        break;
    }
    func_80800000_chevilmumbo(actor);
}

void func_80800144_chevilmumbo(Actor* arg0, s32 arg1, s32 arg2)
{
    CHEVILMUMBO* sp1C;

    sp1C = (CHEVILMUMBO*)actor_getAdditionalMem(arg0, 0U);
    switch (sp1C->unk95)
    {
    case 3:
        func_800F4B20(character_getActiveIndex());
    case 0:
        _capod_entrypoint_2(arg0->unk0, 3U, 0);
    case 1:
        _capod_entrypoint_8(1);
        sp1C->unk95 = 2;
        _gcdialogcamera_entrypoint_6(arg0->unk0);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(arg1, arg2);
        break;
    }

}
void func_808001F4_chevilmumbo(Actor* arg0, s32 arg1, s32 arg2, Unk80132ED0* arg3)
{
    CHEVILMUMBO* sp1C;

    sp1C = (CHEVILMUMBO*)actor_getAdditionalMem(arg0, 0U);
    switch (sp1C->unk95)
    {
    case 3:
        func_800F4B20(character_getActiveIndex());
    case 0:
        _capod_entrypoint_2(arg0->unk0, 3U, arg2);
    case 2:
        sp1C->unk95 = 1;
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
        break;
    }
}

void func_80800290_chevilmumbo(Actor* arg0)
{
    CHEVILMUMBO* sp1C;
    sp1C = (CHEVILMUMBO*)actor_getAdditionalMem(arg0, 0U);
    switch (sp1C->unk95)
    {
    case 3:
        func_800F4B20(character_getActiveIndex());
        break;
    case 1:
    case 2:
        func_80800098_chevilmumbo((s32)arg0);
    }
    sp1C->unk95 = 0;
}

void func_80800300_chevilmumbo(Actor* arg0)
{
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(func_8010D5DC, arg0->unk0);
    func_8008F990((s32)&D_80804294_chevilmumbo, 200.0f);
}

void func_80800354_chevilmumbo(Actor* arg0, s16 arg1, s32 arg2)
{
    s32 var_a1;
    s32 var_v0;

    if (arg0->unk64_20)
    {
        var_v0 = 0x77;
    }
    else
    {
        var_v0 = 0x10;
    }
    if (arg2 != 0)
    {
        var_v0 = arg2;
    }
    if (arg1 == 0xCEB)
    {
        var_a1 = 0x46;
    }
    else
    {
        var_a1 = 7;
    }
    func_800C05B8((s32)arg1, var_a1, arg0->position, arg0->unk0, 0, 0, var_v0);
    arg0->unk74_30 = 1;
}

void func_808003DC_chevilmumbo(Actor* arg0, s32 arg1)
{
    CHEVILMUMBO* sp3C;
    f32 sp30[3];

    sp3C = (CHEVILMUMBO*)actor_getAdditionalMem(arg0, 0U);
    switch (sp3C->unk90)
    {
        case 1:
            func_80090708(0);
            break;
        case 4:
            _suexpression_entrypoint_12(actor_getAdditionalMem(arg0, 1U), 60.0f, 0.0f);
            break;
        case 8:
            func_800F4CC0(character_getActiveIndex());
            func_800FDC28(0xAU);
            func_80800ECC_chevilmumbo(arg0, 1);
            break;
    }
    sp3C->unk90 = (s8)arg1;
    switch (sp3C->unk90)
    {
        case 1:
            func_80090734(2, arg0->position);
            func_800F4CEC(character_getActiveIndex(), 0x3FU);
            func_808001F4_chevilmumbo(arg0, 7, 0x20, NULL);
            return;
        case 10:
            func_80800354_chevilmumbo(arg0, 0x11E0, 0);
            return;
        case 6:
            flag_setValueTrue(FLAG3_A33_UNK);
            if (sp3C->unk96 == 0)
            {
                func_808001F4_chevilmumbo(arg0, 1, 0x20, NULL);
                return;
            }
        default:
            return;
        case 8:
            func_80800354_chevilmumbo(arg0, 0x11E3, 0);
            return;
        case 4:
            actor_disableCollision(arg0);
            if (func_800D395C() == 0)
            {
                collectable_spawnItem(0x47U, TYPE_1_JIGGY, NULL, 1U, arg0->unk0);
                func_808001F4_chevilmumbo(arg0, 0xF, 0x20, NULL);
                arg0->unk58 = 2.0f;
                return;
            }
            func_808003DC_chevilmumbo(arg0, 9);
            return;
        case 9:
            func_808001F4_chevilmumbo(arg0, 9, 0x20, NULL);
            ml_vec3f_copy(sp30, arg0->position);
            sp30[1] -= 100.0f;
            _chexploder_entrypoint_3(arg0, sp30, 3U);
            return;
        case 5:
            if (func_800D395C() != 0) {
                _gcfrontend_entrypoint_10();
            }
            else {
                func_80800290_chevilmumbo(arg0);
                func_80090708(0);
            }
            actor_mark_delete(arg0);
            return;
        case 7:
            flag_setValueTrue(FLAG3_A32_UNK);
            func_808001F4_chevilmumbo(arg0, 3, 0x20, NULL);
            break;
    }
}

void func_80800670_chevilmumbo(Actor* actor)
{
    f32 sp44[3];
    CHEVILMUMBO* temp_s1;

    temp_s1 = (CHEVILMUMBO*)actor_getAdditionalMem(actor, 0U);
    ml_vec3f_copy(sp44, actor->position);

    while (ml_vec3f_is_equal(sp44, actor->position) || ml_vec3f_distance_sq(sp44, (f32*)actor->actorData) < 62500.0f)
    {
        ml_vec3f_copy(sp44, temp_s1->unk0[rand_iBounded(0, temp_s1->unk91)]);
    }

    ml_vec3f_copy(actor->position, &sp44);
}

void func_80800774_chevilmumbo(Actor* actor)
{
    func_801032B0(actor, 0x816, actor->unk0->unk16);
    actor->unk64_20 = 1;
    _suexpression_entrypoint_4(actor_getAdditionalMem(actor, 1U), 0x77);
}

void func_808007C4_chevilmumbo(Actor* arg0, s32 arg1)
{
    CHEVILMUMBO* sp2C;

    sp2C = (CHEVILMUMBO*)actor_getAdditionalMem(arg0, 0U);
    switch (arg0->unk70_10)
    {
        case 6:
            func_80800774_chevilmumbo(arg0);
            arg0->unk6C_0 = 0;
            _chintrotext_entrypoint_1(0x18B9, 8, 1, 0);
            func_800FDC28(1U);
            break;
        case 4:
            arg0->unk74_29 = 0;
            break;
        case 9:
        case 19:
            arg0->unk74_29 = 0;
            break;
        case 12:
            func_8010A800(arg0, 1);
            break;
        case 11:
            actor_enableCollision(arg0);
            arg0->unk64_16 = 1;
            break;
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10)
    {
        case 21:
            sp2C->unk84 = 2;
            sp2C->unk85 = 1;
            sp2C->unk86 = 2;
            sp2C->unk87 = 1;
            sp2C->unk88 = 2;
            sp2C->unk89 = 2;
            sp2C->unk8A = 1;
            sp2C->unk8B = 2;
            sp2C->unk8C = 2;
            sp2C->unk8D = 2;
            ml_vec3f_copy(arg0->position, D_8080427C_chevilmumbo);
            func_80800774_chevilmumbo(arg0);
            arg0->unk74_29 = 1;
            return;
        case 2:
            func_80800300_chevilmumbo((s32*)arg0);
            return;
        case 1:
            _suexpression_entrypoint_12(actor_getAdditionalMem(arg0, 1U), 0.0f, 0.0f);
            return;
        case 5:
            func_808001F4_chevilmumbo(arg0, 5, 0x20, NULL);
            return;
        case 4:
            arg0->unk74_29 = 1;
            return;
        case 7:
        case 13:
            arg0->unk74_29 = 1;
            return;
        case 8:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080414C_chevilmumbo);
            arg0->unk6C_0--;
            return;
        case 10:
            func_8010A800(arg0, 2);
            func_80101EE4(arg0, 0.677f);
            func_80101CDC(arg0, 0.75f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804140_chevilmumbo);
            return;
        case 9:
            if ((s32)sp2C->unk93 < 5)
            {
                arg0->unk58 = 0.0f;
                return;
            }
            arg0->unk58 = 0.5f;
            return;
        case 19:
            if ((s32)sp2C->unk93 < 5)
            {
                arg0->unk58 = 2.0f;
            }
            else
            {
                arg0->unk58 = 3.0f;
            }
            arg0->unk74_29 = 0;
            return;
        case 14:
            ml_vec3f_copy((f32*)&arg0->actorData[4], arg0->position);
            ((f32*)arg0->actorData)[3] = 500.0f;
            if (rand_percentChance(0.5f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804190_chevilmumbo);
                return;
            }
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804198_chevilmumbo);
            return;
        case 18:
            func_808001F4_chevilmumbo(arg0, 0xD, 0x30, NULL);
            func_80800354_chevilmumbo(arg0, 0x11E5, 0);
            return;
        case 12:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804140_chevilmumbo);
            func_80800670_chevilmumbo(arg0);
            arg0->rotation[1] = func_800F1DF4(arg0->position, (f32*)arg0->actorData);
            func_80101CDC(arg0, 0.75f);
            return;
        case 11:
            arg0->unk58 = 0.0f;
            actor_disableCollision(arg0);
            arg0->unk64_16 = 0;
            return;
        case 15:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808041C0_chevilmumbo);
            func_80090734(2, arg0->position);
            sp2C->unk92 = 0;
            func_80800144_chevilmumbo(arg0, 3, 1);
            func_80800354_chevilmumbo(arg0, 0x11E1, 0);
            arg0->unk50 = arg0->rotation[1];
            ((f32*)arg0->actorData)[3] = 4.5f;
            return;
        case 16:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808041C0_chevilmumbo);
            arg0->unk58 = 7.0f;
            return;
        case 20:
            if (sp2C->unk95)
            {
                func_80800290_chevilmumbo(arg0);
            }
            func_800FDC28(0U);
        default:
            return;
    }
}

void func_80800C50_chevilmumbo(Actor* actor)
{
    CHEVILMUMBO* sp1C;
    sp1C = (CHEVILMUMBO*)actor_getAdditionalMem(actor, 0U);
    actor->unk79_4++;
    sp1C->unk93--;
    switch (actor->unk79_4)
    {
        case 1:
            if (rand_f() != 0.0f)
            {
                sp1C->unk87 = 2;
                sp1C->unk94 = 0;
            }
            else
            {
                sp1C->unk88 = 2;
                sp1C->unk85 = 1;
                sp1C->unk94 = 1;
            }
            break;
        case 2:
            if (rand_f() != 0.0f)
            {
                sp1C->unk89 = 2;
                sp1C->unk94 = 2;
            }
            else
            {
                sp1C->unk8A = 2;
                sp1C->unk94 = 3;
            }
            break;
        case 3:
            if (sp1C->unk88 == 2)
            {
                sp1C->unk87 = 2;
                sp1C->unk94 = 0;
            }
            else
            {
                sp1C->unk88 = 2U;
                sp1C->unk85 = 1;
                sp1C->unk94 = 1;
            }
            break;
        case 4:
            sp1C->unk86 = 2;
            sp1C->unk94 = 5;
            break;
        case 5:
            sp1C->unk8B = 2;
            sp1C->unk8C = 2;
            sp1C->unk94 = 6;
            break;
        case 6:
            if (sp1C->unk8A == 2)
            {
                sp1C->unk89 = 2;
                sp1C->unk94 = 2;
            }
            else
            {
                sp1C->unk8A = 2U;
                sp1C->unk94 = 3;
            }
            break;
        case 7:
            sp1C->unk86 = 3;
            sp1C->unk94 = 4;
            break;
        case 8:
            sp1C->unk94 = 7;
            break;
    }
    if (sp1C->unk93 > 0)
    {
        func_808007C4_chevilmumbo(actor, 0xE);
        _chexploder_entrypoint_3(actor, actor->position, 3U);
        return;
    }
    func_808007C4_chevilmumbo(actor, 0xF);
}

s32 func_80800E50_chevilmumbo(Actor* actor)
{
    f32 temp_f0;
    s32 var_v0;

    temp_f0 = func_800F1DCC(actor->unk54, actor->rotation[1]);

    if ((temp_f0 < -3.0f) || (temp_f0 > 3.0f))
    {

        actor->rotation[1] += temp_f0 * 0.1f;
        return 0;
    }
    else
    {
        return 1;
    }
}

void func_80800ECC_chevilmumbo(Actor* actor, s32 arg1) 
{
    if (((CHEVILMUMBO*)actor_getAdditionalMem(actor, 0U))->unk93 < 5)
    {
        if (!(actor->unk6C_0))
        {
            actor->unk6C_0 = 4;
        }
    }
    else
    {
        actor->unk6C_0 = 4;
    }
    if (arg1 != 0)
    {
        func_808007C4_chevilmumbo(actor, 7);
        return;
    }
    func_808007C4_chevilmumbo(actor, 8);
}

void func_80800F60_chevilmumbo(Actor* arg0, f32* arg1, f32* arg2)
{
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    ml_vec3f_copy(sp34, arg1);
    ml_vec3f_copy(sp28, arg1);
    sp34[1] += 50.0f;
    sp28[1] -= 50.0f;
    if (func_800BEF00(sp34, sp28, sp1C, arg0->unk14) != 0)
    {
        arg1[1] = sp28[1];
        func_800F1B78(arg2, sp1C, arg0->rotation[1], 1.0f);
    }
}

void func_80800FF8_chevilmumbo(Actor* arg0)
{
    f32 sp34[3];
    s32 sp30;

    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xC, sp34);
    sp30 = func_800BABB8(0, sp34, NULL, arg0->scale, &D_808042A0_chevilmumbo);
    func_800BA994((unkStruct800BA198*)sp30, -0x4B, arg0->unk50, 0x96, -0x4B, arg0->unk50, 0xFA);
    func_800BA22C(sp30, 8);
    arg0->unk50 += ((f32*)arg0->actorData)[3];
    if (rand_percentChance(0.2f) != 0)
    {
        ((f32*)arg0->actorData)[3] = (f32)-((f32*)arg0->actorData)[3];
    }
}

void func_808010C4_chevilmumbo(Actor* actor)
{
    f32 sp3C[3];
    f32 sp30[3];
    s32 temp_v0;

    _subaddieskeleton_entrypoint_2(actor->unk0, 0xC, sp30);
    sp3C[1] = actor->rotation[1];
    sp3C[0] = 0.0f;
    sp3C[2] = 0.0f;
    func_80800F60_chevilmumbo(actor, sp30, sp3C);
    temp_v0 = func_800BABB8(0, &sp30, NULL, actor->scale * 0.25f, &D_808042D0_chevilmumbo);
    func_800BA77C(temp_v0, sp3C[0], sp3C[1], sp3C[2]);
    func_800BA22C(temp_v0, 1);
    _subaddieaudioquick_entrypoint_2(actor, &sp30, &D_808042F4_chevilmumbo);
}

void func_808011B8_chevilmumbo(Actor* arg0)
{
    func_800BBCB8(arg0->position, arg0->position, 1.0f, 1, &D_80804304_chevilmumbo);
}
void func_808011F4_chevilmumbo(Actor* actor)
{
    s32 sp34;
    f32 sp28[3];
    f32 tempf;

    sp34 = func_800B53A4(4);
    tempf = actor->unk58 * 720.0f;
    ml_vec3f_getVecFromYaw(sp28, tempf, 30);
    ml_vec3f_add(sp28, actor->position);
    func_800BABB8(sp34, sp28, NULL, 1.0f, &D_8080434C_chevilmumbo);
    func_800BA22C(sp34, 4);
    if (rand_percentChance(0.4f) != 0)
    {
        func_808011B8_chevilmumbo(actor);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080129C_chevilmumbo.s")

void func_808023E8_chevilmumbo(Actor* arg0) 
{
    if (actor_getAdditionalMem(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080241C_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80802618_chevilmumbo.s")

extern ActorData D_80804460_chevilmumbo;
ActorData* chevilmumbo_entrypoint_0()
{
    return &D_80804460_chevilmumbo;
}
void func_8080300C_chevilmumbo(Actor* arg0)
{
    if (arg0->unk6C_0 != 0)
    {
        arg0->unk6C_0 = _chlightfader_entrypoint_1(arg0->unk6C_0, 1.4f, 3);
    }
    func_800BBCB8(arg0->position, arg0->position, 1.0f, 0xC, &D_808044A8_chevilmumbo);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804220_chevilmumbo);
    actor_disableCollision(arg0);
    actor_mark_delete(arg0);
}

void func_808030AC_chevilmumbo(Actor* arg0)
{
    f32 sp44;
    Actor* sp40;
    CHEVILMUMBO* sp3C;
    f32 sp30[3];
    f32 sp2C;

    sp44 = time_getDelta();
    sp40 = func_80106790(arg0->unk3C);
    sp3C = actor_getAdditionalMem(sp40, 0U);
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1U, &D_80804208_chevilmumbo);
    if (sp3C) {}
    ((f32*)arg0->actorData)[0] += (sp44 * 500.0f);
    if (arg0->unk70_10 == 1)
    {
        func_800C8E54(arg0->unk6C_0, arg0->scale * 400.0f, arg0->scale * 1000.0f);
        func_800C8E84(arg0->unk6C_0, &D_808044E4_chevilmumbo);
        func_800C8CB8(arg0->unk6C_0, arg0->position);
        if (collectable_isSpawned(0x47, TYPE_1_JIGGY) == 0)
        {
            ml_vec3f_copy(sp30, (f32*)sp40->actorData);
            sp30[1] += 100.0f;
            arg0->unk54 = func_800F1DF4(arg0->position, sp30);
            arg0->unk50 = func_800F1828(arg0->position, sp30);
            sp2C = ((f32*)arg0->actorData)[7] * func_800F1DCC(arg0->unk54, arg0->rotation[1]);
            arg0->rotation[1] += sp2C;
            arg0->rotation[0] += func_800F1DCC(arg0->unk50, arg0->rotation[0]) * ((f32*)arg0->actorData)[7];
            if (!(arg0->unk79_0))
            {
                ((f32*)arg0->actorData)[1] += sp2C > 0.0f ? sp2C : -sp2C;
                if (((f32*)arg0->actorData)[1] > 720.0f)
                {
                    _subaddiefade_entrypoint_3(arg0);
                }
            }
            if (((f32*)arg0->actorData)[2] > 0.0f)
            {
                ((f32*)arg0->actorData)[2] -= sp44;
            }
            else
            {
                ((f32*)arg0->actorData)[7] *= 0.5f;
            }
        }
        func_800EEC30((f32*)&arg0->actorData[4], arg0->rotation[0], arg0->rotation[1], ((f32*)arg0->actorData)[3]);
        if (func_8010B990(arg0, 0x400007) & 0x20) {
            func_8080300C_chevilmumbo(arg0);
        }
        ((f32*)arg0->actorData)[3] -= (200.0f * sp44);
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 = arg0->unk58 - sp44;
            return;
        }
        actor_mark_delete(arg0);
    }
}

void func_80803358_chevilmumbo(Actor* arg0)
{
    if (arg0->unk6C_0 != 0)
    {
        func_800C8B84(arg0->unk6C_0);
    }
}

void func_80803388_chevilmumbo(Actor* arg0)
{
    Actor* sp34;
    CHEVILMUMBO* sp30;
    f32 sp24[3];

    sp34 = func_80106790(arg0->unk3C);
    sp30 = (CHEVILMUMBO*)actor_getAdditionalMem(sp34, 0U);
    arg0->scale = 0.4f;
    arg0->unk6C_0 = func_800C8A98();
    if (sp30->unk93 < 5)
    {
        ((f32*)arg0->actorData)[3] = 1000.0f;
    }
    else
    {
        ((f32*)arg0->actorData)[3] = 1000.0f;
    }
    arg0->unk58 = 2.5f;
    if (sp30->unk93 < 5)
    {
        ((f32*)arg0->actorData)[2] = 0.5f;
    }
    else
    {
        ((f32*)arg0->actorData)[2] = 0.25f;
    }
    if (sp30->unk93 < 5)
    {
        ((f32*)arg0->actorData)[7] = 0.7999878f;
    }
    else
    {
        ((f32*)arg0->actorData)[7] = 0.3999939f;
    }
    ml_vec3f_copy(sp24, (f32*)sp34->actorData);
    sp24[1] += 100.0f;
    arg0->rotation[1] = func_800F1DF4(arg0->position, sp24);
    arg0->rotation[0] = func_800F1828(arg0->position, sp24);
}

s32 func_808034C8_chevilmumbo(Actor* arg0, s32 eventId, s32 arg2)
{
    s32 pad2;
    s32 sp38;
    f32 sp2C[3];
    s32 pad;
    f32 sp1C[3];
    switch (eventId)
    {
        case 0x40:
            func_8080300C_chevilmumbo(arg0);
            break;
        case 0x1C:
            if (func_80106790(arg0->unk3C)->unk64_19)
            {
                return 2;
            }
            else
            {
                return 1;
            }
            break;
        case EVENT_1F_ACTOR_ONSCREEN:
            sp38 = func_801040D0();
            func_801015D0(arg0);
            func_800DF41C(sp38);
            ml_vec3f_assign_value(sp2C, ((f32*)arg0->actorData)[0], 0.0f, 0.0f);
            func_800D93A0(sp1C, sp2C);
            func_800DFF2C(sp38, 0x2A, sp1C);
            break;

        default:
            return 0;
    }
    return 1;
}

void func_808035A8_chevilmumbo(Actor* arg0, s32 arg1)
{
    arg0->rotation[0] = -arg0->rotation[0];
    func_80101970(arg0);
    func_800DF830(2);
    func_800DE448(arg0->position, arg0->rotation, arg0->scale, NULL, asset_load(0x69E));
    func_801018A4(arg0, arg1);
    arg0->rotation[0] = -arg0->rotation[0];
}

extern ActorData D_808044F0_chevilmumbo;
ActorData* chevilmumbo_entrypoint_1()
{
    return &D_808044F0_chevilmumbo;
}
void func_8080362C_chevilmumbo(Actor* arg0, s32 arg1)
{
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10)
    {
        case 4:
            arg0->unk64_19 = 1;
            break;
        case 2:
            arg0->unk64_16 = 1;
            arg0->unk64_19 = 1;
            break;
        case 3:
            flag_setValueFalse(FLAG3_A33_UNK);
            ml_vec3f_assign_value(arg0->position, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            flag_setValueFalse(FLAG3_A32_UNK);
            ml_vec3f_copy(arg0->position, (f32*)arg0->actorData);
            arg0->unk64_16 = 0;
            break;
    }

    arg0->unk58 = 0.0f;
}

void func_80803700_chevilmumbo(Actor* arg0)
{
    f32 sp2C;
    f32 temp_f12;
    f32 temp_f12_2;

    sp2C = time_getDelta();
    switch (arg0->unk70_10)
    {
    case 1:
        if (flag_getValue(FLAG3_A33_UNK) != 0)
        {
            func_8080362C_chevilmumbo(arg0, 2);
            return;
        }
        return;
    case 2:
        temp_f12 = arg0->unk58;
        if (temp_f12 <= 2.5f)
        {
            ml_getScaledVec3f(arg0->position, (f32*)arg0->actorData, ml_map_f(temp_f12, 0.0f, 2.5f, 1.0f, 0.0f));
            arg0->unk58 += sp2C;
            _subaddieaudioloop_entrypoint_4(arg0, &D_80804538_chevilmumbo, 1U, &D_80804234_chevilmumbo);
            return;
        }
        if (arg0->unk64_19)
        {
            func_800C4140(0x665194CCU, &D_80804538_chevilmumbo, 0x138809C4U);
            arg0->unk64_19 = 0;
        }
        func_8080362C_chevilmumbo(arg0, 3);
        return;
    case 3:
        if (flag_getValue(FLAG3_A32_UNK) != 0) {
            func_8080362C_chevilmumbo(arg0, 4);
            return;
        }
        break;
    case 4:
        temp_f12_2 = arg0->unk58;
        if (temp_f12_2 <= 3.0f) {
            ml_getScaledVec3f(arg0->position, (f32*)arg0->actorData, ml_map_f(temp_f12_2, 0.0f, 3.0f, 0.0f, 1.0f));
            arg0->unk58 += sp2C;
            _subaddieaudioloop_entrypoint_4(arg0, &D_80804538_chevilmumbo, 1U, &D_80804234_chevilmumbo);
            return;
        }
        if (arg0->unk64_19) {
            func_800C4140(0x7FEBBCCCU, &D_80804538_chevilmumbo, 0x138809C4U);
            arg0->unk64_19 = 0;
        }
        func_8080362C_chevilmumbo(arg0, 1);
        break;
    }
}

void func_80803918_chevilmumbo(s32 arg0) 
{
}
void func_80803920_chevilmumbo(Actor* arg0)
{
    ml_vec3f_assign_value((f32*)arg0->actorData, -130.0f, 0.0f, -430.0f);
    func_8080362C_chevilmumbo(arg0, 1);
}

s32 func_8080395C_chevilmumbo(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 0xB)
    {
        return 3;
    }
    return 0;
}

extern ActorData D_80804544_chevilmumbo;
ActorData* chevilmumbo_entrypoint_2()
{
    return &D_80804544_chevilmumbo;
}

void func_8080398C_chevilmumbo(Actor* arg0, s32 arg1)
{
    s32 pad;
    f32 sp38[3];
    CHEVILMUMBO* temp_v0;
    temp_v0 = (CHEVILMUMBO*)actor_getAdditionalMem(func_80106790(arg0->unk3C), 0U);
    ml_vec3f_copy(arg0->position, temp_v0->unk78);
    ml_vec3f_assign_value(sp38, 0.0f, 0.0f, 0.0f);
    func_800DF47C(func_801017D0, arg0);
    func_800DE448(arg0->position, sp38, arg0->scale, NULL, func_801039E4(arg0->unk0));
}

void func_80803A24_chevilmumbo(Actor* arg0, s32 arg1)
{
    f32 temp_f0;

    switch (arg1)
    {
    case 2:
        ((f32*)arg0->actorData)[4] = 0.3f;
        ((f32*)arg0->actorData)[5] = 0.0f;
        break;
    case 3:
        ((f32*)arg0->actorData)[5] = 1.0f;
        arg0->scale = 1.0f;
        ((f32*)arg0->actorData)[4] = 0.15f;
        break;
    case 4:
        arg0->scale = 1.0f;
        temp_f0 = ml_map_f(((f32*)arg0->actorData)[5], 0.0f, 1.0f, 0.0f, 0.2f);
        ((f32*)arg0->actorData)[4] = temp_f0;
        if (temp_f0 == 0.0f)
        {
            ((f32*)arg0->actorData)[4] += +0.01f;
        }
        break;
    case 5:
        ((f32*)arg0->actorData)[5] = 0.0f;
        break;
    }
    arg0->unk70_10 = arg1;
}

void func_80803B28_chevilmumbo(Actor* arg0)
{
    func_80803A24_chevilmumbo(arg0,0x2);
}

void func_80803B48_chevilmumbo(s32 arg0) 
{
}
void func_80803B50_chevilmumbo(Actor* arg0)
{

    switch (arg0->unk70_10)
    {
    case 2:
        ((f32*)arg0->actorData)[5] = ml_map_f(((f32*)arg0->actorData)[4], 0.0f, 0.3f, 1, 0.0f);
        if (timer_reachedZero(&((f32*)arg0->actorData)[4]) != 0)
        {
            func_80803A24_chevilmumbo(arg0, 3);
            return;
        }
        return;
    case 3:
        if (arg0->scale == 1.0f)
        {
            arg0->scale = 0.75f;
        }
        else
        {
            arg0->scale = 1.0f;
        }
        if (timer_reachedZero(&((f32*)arg0->actorData)[4]) != 0)
        {
            func_80803A24_chevilmumbo(arg0, 4);
            return;
        }
        break;
    case 4:
        ((f32*)arg0->actorData)[5] = ml_map_f(((f32*)arg0->actorData)[4], 0, 0.2f, 0, 1);
        if (timer_reachedZero(&((f32*)arg0->actorData)[4]) != 0)
        {
            func_80803A24_chevilmumbo(arg0, 5);
            return;
        }
        break;
    case 5:
        actor_mark_delete(arg0);
        break;
    }
}
s32 func_80803C88_chevilmumbo(Actor* arg0, s32 eventId, s32 arg2)
{
    switch (eventId)
    {
        case EVENT_1F_ACTOR_ONSCREEN:
        {
            func_800DF410((s32)ml_map_f(((f32*)arg0->actorData)[5], 0.0f, 1.0f, 0.0f, 255.0f));
            func_800DF830(2);
            break;
        }
        default:
            return 0;
    }
    return 1;
}

extern ActorData D_8080458C_chevilmumbo;
ActorData* chevilmumbo_entrypoint_3()
{
    return &D_8080458C_chevilmumbo;
}
