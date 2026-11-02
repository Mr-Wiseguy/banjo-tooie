#include "ch/stonepillar.h"

extern ActorData D_808013F0_chstonepillar;
extern ActorData D_80801438_chstonepillar;
extern s16 D_80801480_chstonepillar[];
extern s32 D_8080148C_chstonepillar;
extern s32 D_80801498_chstonepillar;
extern s32 D_808014B8_chstonepillar;
extern u32 D_808014F0_chstonepillar;

typedef struct StonePillarStruct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24;
    s32 unk28;
    s16 unk2C;
    u8 unk2E;
    u8 unk2F;
    f32 unk30[3];
} StonePillarStruct;

s32 func_80800474_chstonepillar(Actor*);
void func_808005B4_chstonepillar(Actor*, s32, f32*);
void func_808006AC_chstonepillar(Actor*);
void func_80800704_chstonepillar(Actor*);
void func_808007C8_chstonepillar(Actor*);
s32 func_80800870_chstonepillar(Actor*);
void func_80800ADC_chstonepillar(Actor*, s32);
s32 func_80800B58_chstonepillar(Actor*);
void func_80800BDC_chstonepillar(f32*);
void func_80800C10_chstonepillar(f32*);
void func_80800C44_chstonepillar(Actor*);
void func_80800CC8_chstonepillar(Actor*, s32);
void func_80800DA4_chstonepillar(Actor*);
int func_80800DD8_chstonepillar(Actor*);
void func_80800E30_chstonepillar(Actor*);
void func_80800EE0_chstonepillar(Actor*);
void func_80800FE0_chstonepillar(Actor*);
void func_808010CC_chstonepillar(Actor*);
s32 func_8080112C_chstonepillar(Actor*);
void func_80801174_chstonepillar(Actor*);
void func_808011CC_chstonepillar(Actor*, u32, f32, f32);
s32 func_80801238_chstonepillar(Actor*);
void func_80801374_chstonepillar(Actor*, s32);
//Aboveground
ActorData* chstonepillar_entrypoint_0(void)
{
    return &D_808013F0_chstonepillar;
}
//Below Ground
ActorData* chstonepillar_entrypoint_1(void)
{
    return &D_80801438_chstonepillar;
}

void func_80800018_chstonepillar(Actor* arg0)
{
    StonePillarStruct* sp2C;
    u32 actorState;
    u32 var_a3;

    sp2C = func_80100094(arg0, 0U);
    actorState = arg0->unk70_10;
    func_80800FE0_chstonepillar(arg0);
    if ((sp2C->unk2C == 4) || (collectable_isCollected(8U, 1U) != 0))
    {
        if ((_glcutDll_entrypoint_19(0xBU) != 0) && (actorState == 3))
        {
            func_80800ADC_chstonepillar(arg0, 0);
        }
    }
    else if ((flag_getValue(FLAG3_9D7_UNK) != 0) || (func_8080112C_chstonepillar(arg0) != 0))
    {
        func_80801374_chstonepillar(arg0, 2);
        switch (arg0->unk70_10)
        {
        case 1:
            if ((flag_getValue(FLAG3_9D7_UNK) != 0) && (sp2C->unk2C == 0))
            {
                func_80801174_chstonepillar(arg0);
                func_80800B58_chstonepillar(arg0);
                sp2C->unk24 = 0.5f;
                flag_setValueFalse(FLAG3_9D7_UNK);
                if (flag_getValue(FLAG3_9D9_UNK) == 0)
                {
                    var_a3 = 0x810;
                    if (_glcutDll_entrypoint_19(0xBU) != 0)
                    {
                        var_a3 = 0x910;
                    }
                    _capod_entrypoint_13(arg0->unk0, NULL, 0xCU, var_a3);
                    flag_setValueTrue(FLAG3_9D9_UNK);
                    return;
                }
            }
            else if (func_80800474_chstonepillar(arg0) != 0)
            {
                func_808011CC_chstonepillar(arg0, 2U, 1.0f, 1.0f);
                return;
            }
            break;
        case 2:
            if (func_80801238_chstonepillar(arg0) == 0)
            {
                func_80101FDC(arg0, 3U);
                return;
            }
            break;
        case 3:
            if (func_80800870_chstonepillar(arg0) == 0)
            {
                func_80800ADC_chstonepillar(arg0, 1);
            }
            break;
        }
    }
}

void func_808001FC_chstonepillar(Actor* arg0)
{
    _subaddiefade_entrypoint_14(arg0);
    func_80800EE0_chstonepillar(arg0);
}

void func_80800224_chstonepillar(Actor* arg0)
{
    StonePillarStruct* sp24;

    sp24 = func_80100094(arg0, 0U);
    func_80800FE0_chstonepillar(arg0);
    func_80801374_chstonepillar(arg0, 2);
    if (((arg0->unk70_10) == 2) && (func_80800C10_chstonepillar(arg0->position), (func_80801238_chstonepillar(arg0) == 0)) && (func_80101FDC(arg0, 1U), (collectable_isCollected(8U, 1U) == 0)))
    {
        if ((flag_getValue(FLAG3_9D8_UNK) == 0) && (sp24->unk2C == 0))
        {
            flag_setValueTrue(FLAG3_9D8_UNK);
        }
        if (flag_getValue(FLAG3_9D8_UNK) != 0)
        {
            if ((func_8080112C_chstonepillar(arg0) != 0) && (sp24->unk2C != 4))
            {
                func_80800E30_chstonepillar(arg0);
            }
        }
        else
        {
            func_80800DA4_chstonepillar(arg0);
        }
    }
}
s32 func_8080031C_chstonepillar(Actor* arg0, s32 arg1, s32 arg2)
{
    StonePillarStruct* sp1C;

    switch (arg1)
    {
    case EVENT_95_ACTOR_SPAWNED:

        sp1C = (StonePillarStruct*)func_80100094(arg0, 0U);
        func_80800704_chstonepillar(arg0);
        if ((_glcutDll_entrypoint_19(0xBU) != 0) && (sp1C->unk2C == 0))
        {
            func_808006AC_chstonepillar(arg0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_80800390_chstonepillar(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x3F:
        func_80800CC8_chstonepillar(arg0, *(s32*)&arg2);
        break;
    case EVENT_95_ACTOR_SPAWNED:
        func_80800C44_chstonepillar(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808003F4_chstonepillar(Actor* arg0, s32 arg1)
{
    StonePillarStruct* sp28;
    s32 s0;

    for (s0 = 0; s0 < 5; s0++)
    {
        func_800DF744(s0 + 1, 0);
    }
    sp28 = (StonePillarStruct*)func_80100094(arg0, 0U);
    func_800DF744(sp28->unk2E + 1, 1);
    func_80101808(arg0, func_801015D0);
}

s32 func_80800474_chstonepillar(Actor* arg0)
{
    StonePillarStruct* temp_s0;
    f32 sp28;

    temp_s0 = func_80100094(arg0, 0U);
    if ((func_8080112C_chstonepillar(arg0) == 0) || (flag_getValue(FLAG3_9D5_UNK) == 0))
    {
        return 0;
    }
    sp28 = func_800EFB8C(arg0->position, temp_s0->unkC);
    temp_s0->unk30[0] = func_80102D78(arg0, temp_s0->unkC);
    temp_s0->unk30[1] = (f32)((0.3f * sp28) / 0.5f);
    temp_s0->unk30[2] = 822.00006f;
    return 1;
}

void func_80800520_chstonepillar(Actor* arg0)
{
    StonePillarStruct* temp_v0;
    func_80800EE0_chstonepillar(arg0);
    temp_v0 = (StonePillarStruct*)func_80100094(arg0, 0U);
    func_808005B4_chstonepillar(arg0, temp_v0->unk28, temp_v0->unk0);
    func_808005B4_chstonepillar(arg0, temp_v0->unk28 + 1, temp_v0->unkC);
    arg0->position[1] -= (temp_v0->unk28 * 200.0f);
    ((f32*)arg0->actorData)[1] = arg0->position[1];
}

void func_808005B4_chstonepillar(Actor* arg0, s32 arg1, f32* arg2)
{
    Actor* stonePillar;
    StonePillarStruct* stonePillar_2;
    s32 sp2C;
    f32 sp28;
    sp28 = func_80103EF4(arg0);
    //Get Stone Pillar Above Ground
    stonePillar = _subaddiefind_entrypoint_2(0x12E, (s32)&sp2C);
    while (stonePillar != NULL)
    {
        stonePillar_2 = func_80100094(stonePillar, 0U);
        if (arg1 == stonePillar_2->unk2C)
        {
            ml_vec3f_copy(arg2, stonePillar_2->unk18);
            arg2[1] = (f32)(arg2[1] + (sp28 - ((f32)arg1 * 200.0f)));
            return;
        }
        stonePillar = _subaddiefind_entrypoint_3(0x12E, &sp2C);
    }
    stonePillar_2 = (StonePillarStruct*)func_80100094(arg0, 0U);
    ml_vec3f_copy(arg2, stonePillar_2->unk18);
    arg2[1] = (f32)(arg2[1] + (sp28 - ((f32)arg1 * 200.0f)));
}

void func_808006AC_chstonepillar(Actor* arg0)
{
    if (flag_getValue(FLAG3_9D5_UNK) != 0)
    {
        _capod_entrypoint_13(arg0->unk0, NULL, D_80801480_chstonepillar[flag_getMultipleValue(FLAG3_9CD_UNK, 3)], 0x810U);
    }
}

void func_80800704_chstonepillar(Actor* arg0)
{
    StonePillarStruct* temp_v0;
    f32 sp28[3];

    temp_v0 = func_80100094(arg0, 0U);
    temp_v0->unk2F = 0;
    func_808007C8_chstonepillar(arg0);
    func_80101FDC(arg0, 1U);
    if (collectable_isCollected(8U, 1U) != 0)
    {
        temp_v0->unk2C = -1;
        return;
    }
    if (temp_v0->unk2C == 0)
    {
        func_808005B4_chstonepillar(arg0, flag_getMultipleValue(FLAG3_9CD_UNK, 3), sp28);
        func_800D1254(8, 1, sp28);
        if (flag_getValue(FLAG3_9D7_UNK) != 0)
        {
            func_80801174_chstonepillar(arg0);
            flag_setValueTrue(FLAG3_9D7_UNK);
        }
    }
}

void func_808007C8_chstonepillar(Actor* arg0)
{
    Actor* var_v0;
    StonePillarStruct* temp_v0;
    StonePillarStruct* temp_s1;
    s32 sp28;

    temp_s1 = func_80100094(arg0, 0U);
    var_v0 = _subaddiefind_entrypoint_2(arg0->unk6C_9, &sp28);
    while (var_v0 != NULL)
    {
        if (var_v0 != arg0)
        {
            temp_v0 = func_80100094(var_v0, 0U);
            if ((temp_s1->unk2C + 1) == temp_v0->unk2C)
            {
                ml_vec3f_copy(temp_s1->unkC, temp_v0);
            }
        }
        var_v0 = _subaddiefind_entrypoint_3(arg0->unk6C_9, &sp28);
    }
}

s32 func_80800870_chstonepillar(Actor* arg0)
{
    f32 temp_f2;
    f32 gameSpeed;
    f32 sp2C[3];
    f32 temp_f0;


    StonePillarStruct* temp_s0;

    gameSpeed = time_getDelta();
    temp_s0 = func_80100094(arg0, 0U);
    func_800D1218(8, 1, sp2C);
    _fxsparkle_entrypoint_1(sp2C, 0x12U);
    if (temp_s0->unk2F == 0)
    {
        temp_f0 = temp_s0->unkC[1];
        if (sp2C[1] < temp_f0)
        {
            sp2C[1] = temp_f0;
            temp_s0->unk30[2] *= -0.54f;
            temp_s0->unk30[1] *= 0.08f;
            func_800D1254(8, 1, sp2C);
            temp_s0->unk2F = 1U;
            func_8010D930(3, 0, sp2C, &D_8080148C_chstonepillar);
            return 1;
        }
        else
        {
            temp_f2 = temp_s0->unk30[2];
            temp_s0->unk30[2] -= (1200.0f * gameSpeed);
            sp2C[1] += temp_s0->unk30[2] * gameSpeed;
            if ((temp_f2 >= 0.0f) && (temp_s0->unk30[2] < 0.0f))
            {
                temp_s0->unk30[0] = func_800F1DF4(sp2C, temp_s0->unkC);
            }
            func_800EF1B8(sp2C, temp_s0->unk30[0], temp_s0->unk30[1] * gameSpeed);
        }

    }
    else
    {
        temp_f2 = 1200.0f * gameSpeed;
        temp_s0->unk30[2] -= temp_f2;
        sp2C[1] += temp_s0->unk30[2] * gameSpeed;
        func_800EF1B8(sp2C, temp_s0->unk30[0], temp_s0->unk30[1] * gameSpeed);
        if (temp_s0->unk30[2] < 0.0f)
        {
            temp_f0 = temp_s0->unkC[1];
            if (sp2C[1] < temp_f0)
            {
                sp2C[1] = temp_f0;
                temp_s0->unk30[2] = (f32)(temp_s0->unk30[2] * -0.6f);
                func_8010D930(3, 0, sp2C, &D_8080148C_chstonepillar);
                if (temp_s0->unk30[2] < (2.0f * temp_f2))
                {
                    func_800D1254(8, 1, sp2C);
                    return 0;
                }
            }
        }
    }
    func_800D1254(8, 1, sp2C);
    return 1;
}

void func_80800ADC_chstonepillar(Actor* arg0, s32 arg1)
{
    StonePillarStruct* sp1C;

    sp1C = func_80100094(arg0, 0U);
    flag_setValueFalse(FLAG3_9D5_UNK);
    if (arg1 != 0)
    {
        flag_setMultipleValue(FLAG3_9CD_UNK, sp1C->unk2C + 1, 3);
    }
    func_80101FDC(arg0, 1U);
    if (_glcutDll_entrypoint_19(0xBU) != 0)
    {
        _glcutDll_entrypoint_17();
    }
}

s32 func_80800B58_chstonepillar(Actor* arg0)
{
    f32 sp2C[3];
    StonePillarStruct* sp28;

    sp28 = func_80100094(arg0, 0U);
    func_800D1218(8, 1, sp2C);
    func_800BBCB8(sp2C, sp2C, 1.0f, 0xE, _fxgenlist_entrypoint_0());
    sp2C[1] += 40.0f;
    func_80800BDC_chstonepillar(sp2C);
    func_800D1254(8, 1, sp28);
    return 0;
}

void func_80800BDC_chstonepillar(f32* arg0)
{
    func_800BBCB8(arg0, NULL, 1.0f, 1, &D_80801498_chstonepillar);
}

void func_80800C10_chstonepillar(f32* arg0)
{
    func_800BBCB8(arg0, arg0, 1.0f, 3, &D_808014B8_chstonepillar);
}

void func_80800C44_chstonepillar(Actor* arg0)
{
    StonePillarStruct* temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    arg0->rotation[1] = func_800136E4((f32)(3 - temp_v0->unk2C) * 72.0f);
    if (collectable_isCollected(8U, 1U) != 0)
    {
        temp_v0->unk2C = -1;
    }
    ml_vec3f_copy(arg0->position, (f32*)arg0->actorData);
}

void func_80800CC8_chstonepillar(Actor* arg0, s32 arg1)
{
    StonePillarStruct* temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((arg0->unk70_10) != 2)
    {
        if ((temp_v0->unk2C == 0) && (flag_getValue(FLAG3_9D6_UNK) == 0) && (collectable_isCollected(8U, 1U) == 0))
        {
            func_800CE8D8(0, 45.0f, 0x2D);
            func_800CE88C(0, 1);
            flag_setValueTrue(FLAG3_9D6_UNK);
        }
        if (func_80800DD8_chstonepillar(arg0) != 0)
        {
            func_800F7F98(character_getActiveIndex(), 1);
        }
        func_800C3F48(0x7FF57C16U);
        func_808011CC_chstonepillar(arg0, 2U, 1.0f, 1.0f);
    }
}

void func_80800DA4_chstonepillar(Actor* arg0)
{
    if (flag_getValue(FLAG3_9D8_UNK) == 0)
    {
        flag_setValueTrue(FLAG3_9D8_UNK);
    }
}

int func_80800DD8_chstonepillar(Actor* arg0)
{
    StonePillarStruct* sp1C;

    sp1C = (StonePillarStruct*)func_80100094(arg0, 0U);
    return (flag_getMultipleValue(FLAG3_9CD_UNK, 3) == sp1C->unk2C && !flag_getValue(sp1C->unk2C + 0x65C));

}
void func_80800E30_chstonepillar(Actor* arg0)
{
    StonePillarStruct* sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (func_80800DD8_chstonepillar(arg0) == 0)
    {
        flag_setValueFalse(FLAG3_9D5_UNK);
        flag_setMultipleValue(FLAG3_9CD_UNK, sp1C->unk2C + 1, 3);
        return;
    }
    func_800F7F98(character_getActiveIndex(), 0);
    if (func_800F6CC8(character_getActiveIndex()) == 0)
    {
        flag_setValueTrue(FLAG3_9D5_UNK);
        flag_setValueTrue(sp1C->unk2C + 0x65C);
        _glcutDll_entrypoint_6(0xB9U, 0xBU);
    }
}

void func_80800EE0_chstonepillar(Actor* arg0)
{
    StonePillarStruct* temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_v0->unk2C = ((s32)arg0->rotation[1]) - 1;
    temp_v0->unk2F = 0;
    temp_v0->unk24 = 0.0f;
    temp_v0->unk28 = temp_v0->unk2C;
    temp_v0->unk2E = (s8)((s32)arg0->rotation[1] - 1);
    if ((arg0->unk0->unk24_22) == 0x19F)
    {
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] - ((f32)temp_v0->unk2C * 18.0f));
    }
    else
    {
        arg0->rotation[1] = 0.0f;
    }
    ml_vec3f_copy((f32*)arg0->actorData, arg0->position);
    ml_vec3f_copy(temp_v0->unk18, arg0->position);
    if (collectable_isCollected(8U, 1U) != 0) 
    {
        temp_v0->unk2C = -1;
    }
}

void func_80800FE0_chstonepillar(Actor* arg0)
{
    if ((flag_getValue(FLAG3_9D6_UNK) != 0) && (flag_getValue(FLAG3_9D7_UNK) == 0) && (func_8080112C_chstonepillar(arg0) != 0) && ((func_800CEAD0(0) != 0) || (collectable_isCollected(8U, 1U) != 0)))
    {
        if (func_800CEAA8(0) != 0)
        {
            func_800CE88C(0, 0);
        }
        flag_setValueTrue(FLAG3_9D7_UNK);
        if (flag_getValue(FLAG3_9D9_UNK) != 0)
        {
            func_80801174_chstonepillar(arg0);
            if (((u32)arg0->unk0->unk24_22) != 0x19F)
            {
                flag_setValueFalse(FLAG3_9D7_UNK);
            }
        }
        if (collectable_isCollected(8U, 1U) == 0)
        {
            func_808010CC_chstonepillar(arg0);
            func_800FC660(0x17U);
        }
    }
}

void func_808010CC_chstonepillar(Actor* arg0)
{
    if ((flag_getValue(FLAG3_9D9_UNK) == 0) && (map_getCurrent() != MAP_B9_MT_PRISON_COMPOUND) && (func_800F6CC8(character_getActiveIndex()) == 0))
    {
        _glcutDll_entrypoint_6(0xB9U, 0xBU);
    }
}

s32 func_8080112C_chstonepillar(Actor* arg0)
{
    StonePillarStruct* sp1C;

    sp1C = (StonePillarStruct*)func_80100094(arg0, 0U);
    if (flag_getMultipleValue(FLAG3_9CD_UNK, 3) == sp1C->unk2C)
    {
        return 1;
    }
    return 0;
}

void func_80801174_chstonepillar(Actor* arg0)
{
    flag_setMultipleValue(FLAG3_9CD_UNK, 0, 3);
    flag_setMultipleValue(FLAG3_9CD_UNK, 0, 3);
    flag_setValueFalse(FLAG3_9D6_UNK);
    flag_setValueFalse(FLAG3_9D5_UNK);
    func_80101FDC(arg0, 1U);
}

void func_808011CC_chstonepillar(Actor* arg0, u32 arg1, f32 arg2, f32 arg3)
{
    StonePillarStruct* temp;
    if (arg1 != (arg0->unk70_10))
    {
        func_80101FDC(arg0, arg1);
        temp = func_80100094(arg0, 0U);
        temp->unk24 = arg2;
        arg0->unk58 = 0.3f;
        func_80018820(0, 3.0f, arg3);
    }
}

s32 func_80801238_chstonepillar(Actor* arg0)
{
    f32 sp2C[3];
    StonePillarStruct* sp28;

    sp28 = func_80100094(arg0, 0U);
    if ((timer_reachedZero(&arg0->unk58) != 0) && (((u32)arg0->unk0->unk24_22) != 0x19F) && (collectable_isCollected(8U, 1U) == 0) && (sp28->unk2C != 4) && (func_8080112C_chstonepillar(arg0) != 0))
    {
        func_800FC660(0xEU);
    }
    if (sp28->unk24 > 0.0f)
    {
        sp28->unk24 = (f32)(sp28->unk24 - time_getDelta());
        ml_vec3f_copy(&sp2C, (f32*)arg0->actorData);
        sp2C[0] += rand_fBounded(-7.5f, 7.5f);
        sp2C[2] += rand_fBounded(-7.5f, 7.5f);
        ml_vec3f_copy(arg0->position, &sp2C);
        return 1;
    }
    ml_vec3f_copy(arg0->position, (f32*)arg0->actorData);
    return 0;
}

void func_80801374_chstonepillar(Actor* arg0, s32 arg1)
{
    u32 temp_a2;

    temp_a2 = arg1 == (arg0->unk70_10);
    if ((temp_a2 != 0) || ((temp_a2 == 0) && (arg0->unk5F != 0)))
    {
        _subaddieaudioloop_entrypoint_4(arg0, NULL, temp_a2, &D_808014F0_chstonepillar);
    }
}
