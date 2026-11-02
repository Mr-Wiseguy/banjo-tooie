#include "ch/digger/boss.h"

extern s16 D_80809ED4_chdiggerboss[];
extern u16 D_80809EE4_chdiggerboss[];

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s8 pad8[0x78];
    s16 unk80;
    s16 unk82;
    s8 pad84[0x1C];
    u8 unkA0;
    u8 padA1[0xE4-0xA1];

    u8 unkE4[2];
    u8 padE8[0x10];
    f32 unkF8;
    u8 unkFC[2];
    u8 unkFE;
    u8 unkFF;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    OptionState unk10C;
}DiggerBossAdditionalMem0;

void func_80800180_chdiggerboss(Actor*, s32);
void func_808008C0_chdiggerboss(Actor*, s32, s32);
void func_8080041C_chdiggerboss(Actor*, s32);
s32 func_80802158_chdiggerboss(Actor*, s32);
s32 func_80802170_chdiggerboss(Actor*, s32);
Actor* func_80802228_chdiggerboss(Actor*);
s32 func_80802248_chdiggerboss(Actor*);
Actor* func_808026F8_chdiggerboss(Actor*);
void func_80802938_chdiggerboss(Actor*, s32, s32, s32);
void func_80802BE0_chdiggerboss(Actor*, f32);
void func_80802CDC_chdiggerboss(Actor*);
void func_80803BE8_chdiggerboss(Actor*, s32, s32);
void func_808041E4_chdiggerboss(Actor*, s32);
void func_808042FC_chdiggerboss(Actor*, s32, s32);
void func_80804A7C_chdiggerboss(Actor*, s32, s32);
void func_80804EFC_chdiggerboss(Actor*, GraphicsBuffers*);
void func_80806528_chdiggerboss(Actor*, s32, s32);
void func_80807DC0_chdiggerboss(Actor*, s32);
void func_80809078_chdiggerboss(Actor*, s32, s32);

extern u32 D_80809DB8_chdiggerboss;
extern u32 D_80809DCC_chdiggerboss;
extern u32 D_80809DE4_chdiggerboss;
extern u32 D_80809DFC_chdiggerboss;
extern u32 D_80809E10_chdiggerboss;
extern s32 D_80809E24_chdiggerboss;
extern u32 D_80809E38_chdiggerboss;
extern s16 D_80809EE0_chdiggerboss[];

void func_80800000_chdiggerboss(Actor* arg0)
{
    switch (func_801022E4(arg0))
    {
        case 0x435:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DB8_chdiggerboss, 0.3f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DCC_chdiggerboss, 0.8f);
            return;
        case 0x43B:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DB8_chdiggerboss, 0.5f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DCC_chdiggerboss, 0.85f);
            return;
        case 0x436:
            if (func_80101DDC(arg0) != 0)
            {
                func_80800180_chdiggerboss(arg0, 5);
                return;
            }
        default:
            return;
        case 0x437:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DE4_chdiggerboss, 0.6f);
            return;
        case 0x440:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DFC_chdiggerboss, 0.6f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809E10_chdiggerboss, 0.85f);
            if (func_80101E14(arg0, 0.5f) != 0)
            {
                ((DiggerBossAdditionalMem0*)func_80100094(func_80802228_chdiggerboss(arg0), 0U))->unk7 = 1;
            }
            break;
    }
}

void func_80800180_chdiggerboss(Actor* arg0, s32 arg1)
{
    func_80102424(arg0, arg1);
    if (func_801022E4(arg0) != 0)
    {
        arg0->unk64_16 = 1;
    }
    else
    {
        arg0->unk64_16 = 0;
    }
    if (arg0->unk3C != NULL)
    {
        func_808008C0_chdiggerboss(func_80802228_chdiggerboss(arg0), 5, (arg0->unk64_16) == 0);
    }
}

void func_80800200_chdiggerboss(Actor* arg0)
{
    DiggerBossAdditionalMem0* sp3C;
    s32 pad[2];
    sp3C = func_80100094(arg0, 0U);
    switch (func_801022E4(arg0))
    {
        case 0x42D:
            sp3C->unkA0 = _subaddieaudioloop_entrypoint_7(sp3C->unkA0, arg0->position, func_80102320(arg0, 0.2f, 0.9f), &D_80809E24_chdiggerboss, arg0->unk70_0);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809E38_chdiggerboss, 0.85f);
            if (func_80101DDC(arg0) != 0) {
                func_808008C0_chdiggerboss(arg0, 1, 0);
                func_808008C0_chdiggerboss(arg0, 2, 0);
                func_8080041C_chdiggerboss(arg0, 0x13);
                return;
            }
        default:
            return;
        case 0x42E:
            if (func_80101DDC(arg0) != 0) {
                sp3C->unk6 = 1;
                func_8080041C_chdiggerboss(arg0, 1);
                func_808041E4_chdiggerboss(arg0, 1);
                return;
            }
            break;
        case 0x429:
        case 0x42B:
            sp3C->unkA0 = _subaddieaudioloop_entrypoint_7(sp3C->unkA0, arg0->position, func_80102320(arg0, 0.0f, 0.6f), &D_80809E24_chdiggerboss, arg0->unk70_0);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809E38_chdiggerboss, 0.65f);
            return;
        case 0x42F:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DB8_chdiggerboss, 0.3f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DCC_chdiggerboss, 0.8f);
            if (func_80101DDC(arg0) != 0) {
                sp3C->unk5 = 1;
                func_8080041C_chdiggerboss(arg0, 1);
                func_80807DC0_chdiggerboss(func_808026F8_chdiggerboss(arg0), 1);
            }
            break;
    }
}

void func_8080041C_chdiggerboss(Actor* arg0, s32 arg1)
{
    s32 pad;
    DiggerBossAdditionalMem0* sp20;

    sp20 = func_80100094(func_808026F8_chdiggerboss(arg0), 0U);
    func_80102424(arg0, arg1);
    switch (func_801022E4(arg0))
    {
        case 0x429:
            func_808008C0_chdiggerboss(arg0, 3, 1);
            func_808008C0_chdiggerboss(arg0, 1, 1);
            return;
        case 0x42B:
            sp20->unk80 = 1;
            func_808008C0_chdiggerboss(arg0, 4, 1);
            func_808008C0_chdiggerboss(arg0, 2, 1);
            return;
        case 0x42D:
            sp20->unk80 = 0;
            return;
    }
}

extern ActorData D_80809E44_chdiggerboss;
ActorData* chdiggerboss_entrypoint_0()
{
    return &D_80809E44_chdiggerboss;
}
extern ActorData D_80809E8C_chdiggerboss;
ActorData* chdiggerboss_entrypoint_1()
{
    return &D_80809E8C_chdiggerboss;
}
void func_80800508_chdiggerboss(Actor* arg0, GraphicsBuffers* arg1)
{
    s32 temp_v0;

    temp_v0 = func_800EB854();
    if (temp_v0 != 0)
    {
        if (temp_v0 == 3)
        {
            _gcnewoption_entrypoint_1(&((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unk10C, arg1);
        }
    }
    else
    {
        func_80101808(arg0, func_801017D0);
    }
}

void func_80800568_chdiggerboss(Actor* arg0, s32 arg1)
{
    DiggerBossAdditionalMem0* temp_s2;
    s32 index;
    temp_s2 = func_80100094(arg0, 0U);
    func_801015D0(arg0);
    for (index = 0; index < 1; index++)
    {
        func_800DF744(D_80809EE0_chdiggerboss[index], temp_s2->unkFC[index]);
    }
}


void func_808005DC_chdiggerboss(Actor* arg0, s32 arg1)
{
    func_80806528_chdiggerboss(arg0, func_800AE6BC(func_801040A8(arg0)), arg1);
}

void func_80800618_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
    ((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unkFC[arg1] = arg2;
}

void func_80800650_chdiggerboss(Actor* arg0, GraphicsBuffers* arg1)
{
    switch (func_800EB854())
    {
        case 1:
            func_800DF830(0);
            func_800DF410(0xC0);
            func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, asset_load(0x959));
            return;
        case 0:
            func_80101808(arg0, func_801017D0);
            return;
        case 2:
            func_80804EFC_chdiggerboss(arg0, arg1);
            return;
    }
}

void func_808006F8_chdiggerboss(Actor* arg0, void* arg1) {
    DiggerBossAdditionalMem0* temp_s2;
    s32 index;
    temp_s2 = func_80100094(arg0, 0U);
    func_801015D0(arg0);
    if (func_801022E4(arg0) == 0)
    {
        arg1 = func_800B27E0(arg1);
        func_800AE1E8(arg0->unk0->unk10, arg1, func_801040D0());
        func_800DF72C(func_801040A8(arg0));
    }
    for (index = 0; index < 6; index++)
    {
        func_800DF744(D_80809ED4_chdiggerboss[index], temp_s2->unkE4[index]);
    }
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 0);
    func_800DF744(4, 0);
}

void func_808007E0_chdiggerboss(Actor* arg0, s32 arg1)
{
    DiggerBossAdditionalMem0* sp2C;
    s32 temp_v0;

    sp2C = func_80100094(arg0, 0U);
    temp_v0 = func_8010262C(arg0->unk0, 0xCU);
    func_808042FC_chdiggerboss(arg0, temp_v0, arg1);
    func_80804A7C_chdiggerboss(arg0, temp_v0, arg1);
    func_80809078_chdiggerboss(arg0, temp_v0, arg1);
    if (sp2C->unk5 != 0) {
        func_800E0AFC(temp_v0, 0x52U, 1.0f, -129.0f, 0.0f, 0.0f);
    }
    if (sp2C->unk6 != 0) {
        func_800E0C20(temp_v0, 0x50, 1.0f, 0, 0.5f, 0.0f);
    }
}

void func_808008C0_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
    ((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unkE4[arg1] = arg2;
}

void func_808008F8_chdiggerboss(Actor* arg0)
{
    GameFlag temp_v0;
    MapId temp_s0;
    s32 var_s0;
    DiggerBossAdditionalMem0* temp_s0_2;

    temp_s0 = map_getCurrent();
    if (flag_getValue(FLAG_043_PROGRESS_DEFEATED_HAG_1) != 0)
    {
        actor_mark_delete(arg0);
        return;
    }
    if ((temp_s0 == MAP_15D_CK_CAULDRON_KEEP) && (func_800EA090() != 6))
    {
        actor_mark_delete(arg0);
        return;
    }
    for (var_s0 = 0; var_s0 < 0xF; var_s0++)
    {
        temp_v0 = func_80802158_chdiggerboss(arg0, var_s0);
        if ((temp_v0 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG) && (flag_getValue(temp_v0) != 0))
        {
            func_80802170_chdiggerboss(arg0, var_s0);
        }
    }
    arg0->unk74_17 = 0;
    temp_s0_2 = func_80100074(arg0, 0U, _gcnewoption_entrypoint_2() + 0x10C);
    func_80109FE8(arg0, 0);
    func_80109EEC(arg0, 0x40);
    func_80102FDC(arg0, 0.25f);
    temp_s0_2->unk2 = 0x64;
    func_8010A828(arg0, 1U);
    func_80803BE8_chdiggerboss(arg0, 1, 1);
    func_80802CDC_chdiggerboss(arg0);
    func_80802BE0_chdiggerboss(arg0, 1.0f);
    flag_setValueFalse(FLAG3_A4F_UNK);
    flag_setValueFalse(FLAG3_A50_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80800A4C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808019A8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80801A04_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80801DE0_chdiggerboss.s")

s32 func_80802158_chdiggerboss(Actor* arg0, s32 arg1) {
    return D_80809EE4_chdiggerboss[arg1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802170_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808021E8_chdiggerboss.s")

Actor* func_80802228_chdiggerboss(Actor* arg0) {
    return func_80106790(arg0->unk3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802248_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802288_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802298_chdiggerboss.s")

s32 func_80802314_chdiggerboss(void) {
    return 2 - func_800DA980(FLAG3_A4F_UNK, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080233C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808023D8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802550_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808025D4_chdiggerboss.s")

Actor* func_808026F8_chdiggerboss(Actor* arg0) {
    return func_80106790(arg0->unk3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802718_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802778_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808027F4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802878_chdiggerboss.s")

void func_8080290C_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2) {
    func_80802938_chdiggerboss(arg0, arg0->unk0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802938_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808029C8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802AB8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802BE0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802C0C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802C40_chdiggerboss.s")

void func_80802CB4_chdiggerboss(Actor* arg0)
{
    func_800F4B20(func_80802248_chdiggerboss(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802CDC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802D00_chdiggerboss.s")

void func_80802EF8_chdiggerboss(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802F00_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802FEC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803078_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803224_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803338_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808033A0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803424_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803524_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803558_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/chdiggerboss_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803610_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803660_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803694_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808039C0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803BE8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803DC8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803E10_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803E84_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808040D8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804140_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808041E4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808042D8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808042FC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808043D8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804450_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804644_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804680_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804784_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808047A8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808049A8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808049DC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804A50_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804A7C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804AC8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804C28_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804D44_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804EFC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804FE4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808053BC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805448_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808056B8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808056F8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805798_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808057D0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808058B0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805960_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808059A4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808059CC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805A00_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805A64_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805B8C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805C1C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805D64_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805DF4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808062B8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806300_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808063C8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808064CC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806528_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806648_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080666C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808066A0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806A78_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806B38_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806C08_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806CA4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806CF8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806D84_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806DC4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806EE4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806F10_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806F8C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808070B0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807280_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807304_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080761C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807640_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807664_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807698_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807754_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080783C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807B18_chdiggerboss.s")

void func_80807B4C_chdiggerboss(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807B54_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807DC0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807DF4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807E3C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807FD8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808000_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808034_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808080C0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080815C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808081AC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808258_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080843C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808470_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808560_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808085E0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808086A8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808086E8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808087F0_chdiggerboss.s")

void func_808088AC_chdiggerboss(s32 arg0)
{
    func_80808B40_chdiggerboss(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808088CC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808948_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808089BC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808B40_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808BE4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808C64_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808CD0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808D54_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808F44_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/chdiggerboss_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809078_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809150_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808091E4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809234_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809310_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808093F8_chdiggerboss.s")
