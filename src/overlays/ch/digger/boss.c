#include "ch/digger/boss.h"

extern s16 D_80809ED4_chdiggerboss[];
extern u16 D_80809EE4_chdiggerboss[];

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
	s16 unk8;
	s16 unkA;
	f32 unkC;
	f32 unk10;
    s8 pad14[0x2C];
	u8 unk40;
	u8 unk41;
	u8 unk42;
	u8 unk43;
	s16 unk44;
	s16 unk46;
	s32 unk48;
	f32 unk4C;
	u8 pad50[0x30];
    s16 unk80;
    s16 unk82;
    s8 pad84[0x1C];
    s16 unkA0;
    u8 padA2[0xCC-0xA2];
	u8 unkCC;
	u8 unkCD;
	u8 unkCE;
	u8 unkCF;
	u8 padD0[0x14];
    u8 unkE4[2];
    u8 padE8[0x10];
    f32 unkF8;
    u8 unkFC[4];
    s32 unk100;
    s32 unk104;
    s32 unk108;
    OptionState unk10C;
}DiggerBossAdditionalMem0;

typedef struct {
	s16 unk0;
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
	u8 unkA1;
	u8 unkA2;
	u8 unkA3;
}Hag1AdditionalMem0;

void func_80800180_chdiggerboss(Actor*, s32);
void func_808008C0_chdiggerboss(Actor*, s32, s32);
void func_8080041C_chdiggerboss(Actor*, s32);
void func_80801DE0_chdiggerboss(Actor*);
s32 func_80802158_chdiggerboss(Actor*, s32);
s32 func_80802170_chdiggerboss(Actor*, s32);
s32 func_808021E8_chdiggerboss(Actor*, s32);
Actor* func_80802228_chdiggerboss(Actor*);
s32 func_80802248_chdiggerboss(Actor*);
s32 func_80802288_chdiggerboss(Actor*);
void func_80802298_chdiggerboss(Actor*, f32*);
s32 func_80802314_chdiggerboss(void);
Actor* func_808026F8_chdiggerboss(Actor*);
s32 func_80802718_chdiggerboss(Actor*, s32, u32);
s32 func_808027F4_chdiggerboss(Actor*);
void func_80802878_chdiggerboss(Actor*, s32, s32);
void func_8080290C_chdiggerboss(Actor*, s32, s32);
void func_80802938_chdiggerboss(Actor*, s32, s32, s32);
void func_808029C8_chdiggerboss(Actor*);
s32 func_80802AB8_chdiggerboss(Actor*, s32);
void func_80802BE0_chdiggerboss(Actor*, f32);
void func_80802C40_chdiggerboss(Actor*);
void func_80802CDC_chdiggerboss(Actor*);
s32 func_80802D00_chdiggerboss(Actor*);
void func_80802EF8_chdiggerboss(Actor*);
void func_80802F00_chdiggerboss(Actor*, s32);
void func_80802FEC_chdiggerboss(Actor*, s32, s32);
void func_80803078_chdiggerboss(Actor*, void*, s32, s32);
void func_80803224_chdiggerboss(Actor*);
s32 func_80803424_chdiggerboss(Actor*, s32);
void func_80803660_chdiggerboss(Actor*, s32, s32);
void func_80803694_chdiggerboss(Actor*, s32, s32);
void func_808039C0_chdiggerboss(Actor*, s32, s32);
void func_80803BE8_chdiggerboss(Actor*, s32, s32);
void func_80803DC8_chdiggerboss(Actor*, s32, s32);
void func_80803E10_chdiggerboss(Actor*);
void func_80803E84_chdiggerboss(Actor*);
void func_808040D8_chdiggerboss(Actor*);
void func_808041E4_chdiggerboss(Actor*, s32);
void func_808042FC_chdiggerboss(Actor*, s32, s32);
void func_80804784_chdiggerboss(Actor*);
void func_808047A8_chdiggerboss(Actor*);
void func_808049A8_chdiggerboss(Actor*);
void func_80804A50_chdiggerboss(Actor*, s32);
void func_80804A7C_chdiggerboss(Actor*, s32, s32);
void func_80804C28_chdiggerboss(Actor*);
void func_80804D44_chdiggerboss(Actor*);
void func_80804EFC_chdiggerboss(Actor*, GraphicsBuffers*);
void func_808053BC_chdiggerboss(Actor*);
void func_80805448_chdiggerboss(Actor*, s32, s32);
void func_808056B8_chdiggerboss(Actor*);
void func_808059A4_chdiggerboss(Actor*);
void func_808059CC_chdiggerboss(Actor*);
void func_80805A00_chdiggerboss(Actor*, s32);
s32 func_80805A64_chdiggerboss(Actor*);
void func_80805D64_chdiggerboss(Actor*, s32);
s32 func_80805DF4_chdiggerboss(Actor*);
void func_80806300_chdiggerboss(Actor*);
void func_80806528_chdiggerboss(Actor*, s32, s32);
void func_80806648_chdiggerboss(Actor*);
void func_8080666C_chdiggerboss(Actor*);
s32 func_808066A0_chdiggerboss(Actor*);
void func_80806A78_chdiggerboss(Actor*, s32, s32*);
void func_80806CA4_chdiggerboss(Actor*, s32);
void func_80806CF8_chdiggerboss(Actor*, s32);
void func_80806DC4_chdiggerboss(Actor*, s32);
void func_80806EE4_chdiggerboss(Actor*, s32);
s32 func_808070B0_chdiggerboss(Actor*);
void func_80807280_chdiggerboss(Actor*, s32, s32*);
void func_80807304_chdiggerboss(Actor*, s32);
void func_80807640_chdiggerboss(Actor*);
void func_80807664_chdiggerboss(Actor*);
void func_80807698_chdiggerboss(Actor*, s32);
void func_80807754_chdiggerboss(Actor*, s32, f32);
void func_8080783C_chdiggerboss(Actor*, s32);
void func_80807B18_chdiggerboss(Actor*);
void func_80807B4C_chdiggerboss(Actor*);
void func_80807B54_chdiggerboss(Actor*);
void func_80807DC0_chdiggerboss(Actor*, s32);
void func_80807DF4_chdiggerboss(Actor*);
void func_80807E3C_chdiggerboss(Actor*, s32);
void func_80807FD8_chdiggerboss(Actor*);
void func_80808000_chdiggerboss(Actor*);
void func_80808034_chdiggerboss(Actor*);
void func_808080C0_chdiggerboss(Actor*, s32);
void func_80808258_chdiggerboss(Actor*);
void func_8080843C_chdiggerboss(Actor*);
void func_80808470_chdiggerboss(Actor*, s32);
void func_808085E0_chdiggerboss(Actor*, s32);
void func_808086E8_chdiggerboss(Actor*, s32);
void func_808088AC_chdiggerboss(Actor*);
void func_808088CC_chdiggerboss(Actor*);
void func_80808948_chdiggerboss(Actor*);
void func_80808C64_chdiggerboss(Actor*);
void func_80808CD0_chdiggerboss(Actor*);
void func_80809078_chdiggerboss(Actor*, s32, s32);
s32 func_808091E4_chdiggerboss(Actor*);
void func_80809310_chdiggerboss(Actor*);

extern s32 D_80809C60_chdiggerboss;
extern s32 D_80809C70_chdiggerboss;
extern s32 D_80809C80_chdiggerboss;
extern s32 D_80809C90_chdiggerboss;
extern s32 D_80809CA0_chdiggerboss;
extern s32 D_80809CB0_chdiggerboss;
extern s32 D_80809CC0_chdiggerboss;
extern s32 D_80809CD0_chdiggerboss;
extern s32 D_80809CE0_chdiggerboss;
extern s32 D_80809CF0_chdiggerboss;
extern s32 D_80809D00_chdiggerboss;
extern u32 D_80809DB8_chdiggerboss;
extern u32 D_80809DCC_chdiggerboss;
extern u32 D_80809DE4_chdiggerboss;
extern u32 D_80809DFC_chdiggerboss;
extern u32 D_80809E10_chdiggerboss;
extern s32 D_80809E24_chdiggerboss;
extern u32 D_80809E38_chdiggerboss;
extern s16 D_80809EE0_chdiggerboss[];
extern u32 D_80809F04_chdiggerboss;
extern s32 D_80809F10_chdiggerboss;
extern s32 D_80809F1C_chdiggerboss;
extern f32 B_8080A300_chdiggerboss[3];

//Grunty
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

//Grunty
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

//Hag-1
void func_80800200_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp3C;
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
ActorData* chdiggerboss_entrypoint_0() //Grunty
{
    return &D_80809E44_chdiggerboss;
}
//0xC 80800A4C
//0x14 80800508
//0x28 808019A8
//0x34 808008F8
//0x40 80801A04

extern ActorData D_80809E8C_chdiggerboss; //Hag-1
ActorData* chdiggerboss_entrypoint_1() 
{
    return &D_80809E8C_chdiggerboss;
}
//0xC 808023D8
//0x14 80800650
//0x28 80802550
//0x34 8080233C
//0x40 808025D4

//Grunty Draw
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

//Grunty
void func_80800618_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
    ((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unkFC[arg1] = arg2;
}

//Hag-1 Draw
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

//Grunty
void func_808008C0_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
    ((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unkE4[arg1] = arg2;
}

//Grunty
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

//Grunty Update
void func_80800A4C_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* sp44;
	s32 pad[3];
	Actor* sp34;
	Actor* sp30;
	s32 sp2C;
	s32 pad2;
	Actor* sp24;
	s32 sp20;

	sp44 = func_80100094(arg0, 0U);
	func_80800000_chdiggerboss(arg0);
	func_80806300_chdiggerboss(arg0);
	func_80807B54_chdiggerboss(arg0);
	switch (sp44->unk0)
	{
		case 0x2:
			if (func_80101DDC(arg0) != 0)
			{
				func_80803660_chdiggerboss(arg0, 0x171E, 0x10E);
				func_80803BE8_chdiggerboss(arg0, 3, 8);
			}
			break;
		case 0x4:
			if (func_80101DDC(arg0) != 0)
			{
				if (func_80802170_chdiggerboss(arg0, 0) == 0)
				{
					func_80803BE8_chdiggerboss(arg0, 5, 1);
					func_8080290C_chdiggerboss(arg0, 0x2D, 0x20);
					func_80803660_chdiggerboss(arg0, 0x1720, 0x14C);
				}
				else
				{
					func_800FDC28(0x14U);
					func_80805A00_chdiggerboss(arg0, 6);
				}
			}
			break;
		case 0x6:
			if (func_80805A64_chdiggerboss(arg0) != 0)
			{
				func_80802F00_chdiggerboss(arg0, 7);
			}
			break;
		case 0x7:
			if (func_80101DDC(arg0) != 0)
			{
				if (func_80802170_chdiggerboss(arg0, 1) == 0)
				{
					func_80803BE8_chdiggerboss(arg0, 8, 5);
					func_80803660_chdiggerboss(arg0, 0x172E, 0x10E);
				}
				else {
					func_80802FEC_chdiggerboss(arg0, 9, 0);
				}
			}
			break;
		case 0x9:
			if (func_80802D00_chdiggerboss(arg0) != 0)
			{
				func_80806A78_chdiggerboss(arg0, 0xA, &D_80809C60_chdiggerboss);
			}
			break;
		case 0xA:
			switch (func_808066A0_chdiggerboss(arg0))
			{
			case 1:
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0xB, 3);
				break;
			case 2:
				func_80803BE8_chdiggerboss(arg0, 8, 8);
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803660_chdiggerboss(arg0, 0x1731, 0x10E);
				break;
			}
			break;
		case 0xB:
			if (func_80101DDC(arg0) != 0)
			{
				func_80805A00_chdiggerboss(arg0, 6);
			}
			break;
		case 0xC:
			if (func_80101DDC(arg0) != 0)
			{
				if (func_80802170_chdiggerboss(arg0, 5) == 0)
				{
					func_80803BE8_chdiggerboss(arg0, 0xD, 1);
					func_8080290C_chdiggerboss(arg0, 0x30, 0x20);
					func_80803660_chdiggerboss(arg0, 0x1721, 0x14C);
				}
				else
				{
					func_80805A00_chdiggerboss(arg0, 0xE);
				}
			}
			break;
		case 0xE:
			if (func_80805A64_chdiggerboss(arg0) != 0) {
				func_80802F00_chdiggerboss(arg0, 0xF);
			}
			break;
		case 0xF:
			if (func_80101DDC(arg0) != 0) {
				func_80802FEC_chdiggerboss(arg0, 0x11, 0);
			}
			break;
		case 0x11:
			if (func_80802D00_chdiggerboss(arg0) != 0) {
				func_80806A78_chdiggerboss(arg0, 0x12, &D_80809C70_chdiggerboss);
			}
			break;
		case 0x12:
			switch (func_808066A0_chdiggerboss(arg0))
			{
			case 1:
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x13, 3);
				break;
			case 2:
				func_80803BE8_chdiggerboss(arg0, 0x10, 8);
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803660_chdiggerboss(arg0, 0x1732, 0x10E);
				break;
			}
			break;
		case 0x13:
			if (func_80101DDC(arg0) != 0) {
				func_80805A00_chdiggerboss(arg0, 0xE);
			}
			break;
		case 0x14:
			if (func_80101DDC(arg0) != 0) {
				if (func_80802170_chdiggerboss(arg0, 6) == 0) {
					func_80803BE8_chdiggerboss(arg0, 0x15, 1);
					func_8080290C_chdiggerboss(arg0, 0x33, 0x20);
					func_80803660_chdiggerboss(arg0, 0x1723, 0x14C);
				}
				else {
					func_8080041C_chdiggerboss(func_80802228_chdiggerboss(arg0), 0xE);
					func_80807280_chdiggerboss(arg0, 0x16, &D_80809CF0_chdiggerboss);
				}
			}
			break;
		case 0x16:
			if (func_808070B0_chdiggerboss(arg0) != 0) {
				func_80802F00_chdiggerboss(arg0, 0x17);
			}
			break;
		case 0x17:
			if (func_80101DDC(arg0) != 0) {
				func_80802FEC_chdiggerboss(arg0, 0x19, 1);
			}
			break;
		case 0x19:
			if (func_80802D00_chdiggerboss(arg0) != 0) {
				func_80806A78_chdiggerboss(arg0, 0x1A, &D_80809C80_chdiggerboss);
			}
			break;
		case 0x1A:
			switch (func_808066A0_chdiggerboss(arg0))
			{
			case 1:
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x1B, 3);
				break;
			case 2:
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x1C, 3);
				break;
			}
			break;
		case 0x1B:
			if (func_80101DDC(arg0) != 0) {
				func_80807280_chdiggerboss(arg0, 0x16, &D_80809CF0_chdiggerboss);
			}
			break;
		case 0x1C:
			if (func_80101DDC(arg0) != 0) {
				if (func_80802170_chdiggerboss(arg0, 7) == 0) {
					func_80803BE8_chdiggerboss(arg0, 0x1D, 1);
					func_8080290C_chdiggerboss(arg0, 0x37, 0x20);
					func_80803660_chdiggerboss(arg0, 0x1724, 0x14C);
					func_808008C0_chdiggerboss(func_80802228_chdiggerboss(arg0), 3, 1);
				}
				else {
					func_8080041C_chdiggerboss(func_80802228_chdiggerboss(arg0), 0x10);
					func_80807280_chdiggerboss(arg0, 0x1E, &D_80809D00_chdiggerboss);
				}
			}
			break;
		case 0x1E:
			if (func_808070B0_chdiggerboss(arg0) != 0) {
				func_80802F00_chdiggerboss(arg0, 0x1F);
			}
			break;
		case 0x1F:
			if (func_80101DDC(arg0) != 0) {
				func_80802FEC_chdiggerboss(arg0, 0x21, 1);
			}
			break;
		case 0x21:
			if (func_80802D00_chdiggerboss(arg0) != 0) {
				func_80806A78_chdiggerboss(arg0, 0x22, &D_80809C90_chdiggerboss);
			}
			break;
		case 0x22:
			switch (func_808066A0_chdiggerboss(arg0)) {
			case 1:
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x23, 3);
				break;
			case 2:
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x24, 3);
				break;
			}
			break;
		case 0x23:
			if (func_80101DDC(arg0) != 0) {
				func_80807280_chdiggerboss(arg0, 0x1E, &D_80809D00_chdiggerboss);
			}
			break;
		case 0x24:
			if (func_80101DDC(arg0) != 0) {
				if (func_80802170_chdiggerboss(arg0, 8) == 0) {
					func_80803BE8_chdiggerboss(arg0, 0x25, 1);
					func_8080290C_chdiggerboss(arg0, 0x36, 0x20);
					func_80803660_chdiggerboss(arg0, 0x1725, 0x14C);
				}
				else {
					func_8080041C_chdiggerboss(func_80802228_chdiggerboss(arg0), 0x12);
					func_80803BE8_chdiggerboss(arg0, 0x26, 1);
					func_808027F4_chdiggerboss(arg0);
				}
			}
			break;
		case 0x26:
			sp34 = func_80802228_chdiggerboss(arg0);
			if (func_801022E4(sp34) == 0) {
				func_80805448_chdiggerboss(sp34, 0, 1);
				func_80805448_chdiggerboss(sp34, 3, 1);
				func_80805D64_chdiggerboss(arg0, 0x27);
			}
			break;
		case 0x27:
			if (func_80805DF4_chdiggerboss(arg0) != 0) {
				if (sp44->unk2 != 0x32) {
					func_80802F00_chdiggerboss(arg0, 0x28);
				}
				else {
					func_80807754_chdiggerboss(arg0, 0x2D, 10.0f);
				}
			}
			break;
		case 0x28:
			if (func_80101DDC(arg0) != 0) {
				func_80802FEC_chdiggerboss(arg0, 0x2A, 2);
			}
			break;
		case 0x2A:
			if (func_80802D00_chdiggerboss(arg0) != 0) {
				func_80806A78_chdiggerboss(arg0, 0x2B, &D_80809CA0_chdiggerboss);
			}
			break;
		case 0x2B:
			if (func_808066A0_chdiggerboss(arg0) != 0) {
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x2C, 3);
			}
			break;
		case 0x2C:
			if (func_80101DDC(arg0) != 0) {
				func_80807754_chdiggerboss(arg0, 0x2D, 10.0f);
				if (func_80802170_chdiggerboss(arg0, 9) == 0) {
					func_80803660_chdiggerboss(arg0, 0x1727, 0x106);
				}
			}
			break;
		case 0x2D:
			func_8080783C_chdiggerboss(arg0, 0x27);
			break;
		case 0x2E:
			if (func_80101DDC(arg0) != 0) {
				func_800F82D4(character_getActiveIndex(), 0);
				func_80803660_chdiggerboss(arg0, 0x1733, 0x10E);
				func_80803BE8_chdiggerboss(arg0, 0x30, 8);
			}
			break;
		case 0x2F:
			if (func_80101DDC(arg0) != 0) {
				func_80805D64_chdiggerboss(arg0, 0x31);
			}
			break;
		case 0x31:
			if (func_80805DF4_chdiggerboss(arg0) != 0) {
				if (sp44->unk2 != 0x28) {
					func_80802F00_chdiggerboss(arg0, 0x32);
				}
				else {
					func_80807754_chdiggerboss(arg0, 0x37, 8.0f);
				}
			}
			break;
		case 0x32:
			if (func_80101DDC(arg0) != 0) {
				func_80802FEC_chdiggerboss(arg0, 0x34, 2);
			}
			break;
		case 0x33:
			if (func_80802D00_chdiggerboss(arg0) != 0) {
				func_80806A78_chdiggerboss(arg0, 0x35, &D_80809CB0_chdiggerboss);
			}
			break;
		case 0x34:
			if (func_80802D00_chdiggerboss(arg0) != 0) {
				func_80806A78_chdiggerboss(arg0, 0x35, &D_80809CB0_chdiggerboss);
			}
			break;
		case 0x35:
			if (func_808066A0_chdiggerboss(arg0) != 0) {
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_80803BE8_chdiggerboss(arg0, 0x36, 3);
			}
			break;
		case 0x36:
			if (func_80101DDC(arg0) != 0) {
				func_80807754_chdiggerboss(arg0, 0x37, 8.0f);
			}
			break;
		case 0x37:
			func_8080783C_chdiggerboss(arg0, 0x31);
			break;
		case 0x38:
			if (func_80101DDC(arg0) != 0) {
				func_800F82D4(character_getActiveIndex(), 0);
				if (func_80802170_chdiggerboss(arg0, 0xC) == 0) {
					func_8080290C_chdiggerboss(arg0, 0x3C, 0x20);
					func_80803660_chdiggerboss(arg0, 0x1734, 0x14C);
				}
				else {
					sp30 = func_80802228_chdiggerboss(arg0);
					func_80804A50_chdiggerboss(sp30, 0);
					for (sp2C = 0; sp2C < 4; sp2C++) {
						func_80805448_chdiggerboss(sp30, sp2C, 2);
					}
					func_808041E4_chdiggerboss(sp30, 4);
					func_80802878_chdiggerboss(arg0, 3, 1);
					func_80803660_chdiggerboss(arg0, 0x1729, 0x10E);
				}
				func_80803BE8_chdiggerboss(arg0, 0x39, 8);
			}
			break;
		case 0x3A:
			switch (func_808066A0_chdiggerboss(arg0))
			{
			case 1:
				func_80806A78_chdiggerboss(arg0, 0x3A, &D_80809CC0_chdiggerboss);
				break;
			case 2:
				func_80803BE8_chdiggerboss(arg0, 0x3B, 8);
				if (func_80802170_chdiggerboss(arg0, 0xD) == 0) {
					func_8080290C_chdiggerboss(arg0, 0x40, 0x20);
					func_80803660_chdiggerboss(arg0, 0x172A, 0x14C);
				}
				else {
					func_8080041C_chdiggerboss(func_80802228_chdiggerboss(arg0), 0x14);
					func_80806A78_chdiggerboss(arg0, 0x3C, &D_80809CD0_chdiggerboss);
					func_80806EE4_chdiggerboss(arg0, 1);
				}
				break;
			}
			break;
		case 0x3C:
			switch (func_808066A0_chdiggerboss(arg0))
			{
			case 1:
				func_80806A78_chdiggerboss(arg0, 0x3C, &D_80809CD0_chdiggerboss);
				break;
			case 2:
				if (func_80802170_chdiggerboss(arg0, 0xE) == 0) {
					func_80803BE8_chdiggerboss(arg0, 0x3D, 8);
					func_8080290C_chdiggerboss(arg0, 0x44, 0x20);
					func_80803660_chdiggerboss(arg0, 0x172B, 0x14C);
				}
				else {
					sp24 = func_80802228_chdiggerboss(arg0);
					func_80806A78_chdiggerboss(arg0, 0x3E, &D_80809CE0_chdiggerboss);
					func_80806EE4_chdiggerboss(arg0, 1);
					func_80807DC0_chdiggerboss(arg0, 2);
					func_808080C0_chdiggerboss(sp24, 2);
				}
				break;
			}
			break;
		case 0x3E:
			switch (func_808066A0_chdiggerboss(arg0))
			{
			case 1:
				func_80806A78_chdiggerboss(arg0, 0x3E, &D_80809CE0_chdiggerboss);
				break;
			case 2:
				func_808080C0_chdiggerboss(func_80802228_chdiggerboss(arg0), 0);
				func_80807DF4_chdiggerboss(arg0);
				if (func_808021E8_chdiggerboss(arg0, 0xB) == 0) {
					func_80803BE8_chdiggerboss(arg0, 0x3F, 8);
					func_80802BE0_chdiggerboss(arg0, 3.0f);
					func_80802878_chdiggerboss(arg0, 3, 1);
					func_80803660_chdiggerboss(arg0, 0x172C, 0x10E);
				}
				else
				{
					func_80802BE0_chdiggerboss(arg0, 1.0f);
					sp44->unkCD = 1;
					func_80808470_chdiggerboss(arg0, 0x40);
				}
				break;
			}
			break;
		case 0x40:
			func_80808258_chdiggerboss(arg0);
			break;
		case 0x41:
			if (func_80101DDC(arg0) != 0) {
				func_80803BE8_chdiggerboss(arg0, 0x42, 1);
			}
			break;
		case 0x43:
			if (func_808091E4_chdiggerboss(arg0) == 0) {
				func_80802878_chdiggerboss(arg0, 5, 1);
				func_80803BE8_chdiggerboss(arg0, 0x44, -1);
				sp44->unkF8 = 0.4f;
			}
			break;
		case 0x44:
			if (timer_reachedZero(&sp44->unkF8) != 0) {
				sp20 = func_80802248_chdiggerboss(arg0);
				func_800F7B9C(sp20, 0x63U);
				func_800F7C58(sp20, 0x61, 2);
				func_80803BE8_chdiggerboss(arg0, 0x45, -1);
				sp44->unkF8 = 1.0f;
			}
			break;
		case 0x45:
			if (timer_reachedZero(&sp44->unkF8) != 0)
			{
				if (func_800D395C() != 0)
				{
					func_800FDC28(0U);
					_gcfrontend_entrypoint_10();
				}
				else
				{
					func_80803660_chdiggerboss(arg0, 0x14D8, 0x10E);
					func_80803BE8_chdiggerboss(arg0, 0x46, -1);
				}
			}
			break;
		case 0x47:
			if (func_80101DDC(arg0) != 0)
			{
				func_80803BE8_chdiggerboss(arg0, 0x48, 8);
				if (func_800D395C() != 0)
				{
					func_80803660_chdiggerboss(arg0, 0xCEB, 0x144);
				}
			}
			break;
		case 0x48:
			break;
	}
	if (arg0->unk70_3)
	{
		_suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0U);
	}
}

//Grunty
void func_808019A8_chdiggerboss(Actor* arg0)
{
	func_808027F4_chdiggerboss(arg0);
	func_80802EF8_chdiggerboss(arg0);
	func_80807B4C_chdiggerboss(arg0);
	func_8080666C_chdiggerboss(arg0);
	func_808059CC_chdiggerboss(arg0);
	func_8080843C_chdiggerboss(arg0);
	_suexpression_entrypoint_8(arg0, 1U);
}

//Grunty Event Handler
s32 func_80801A04_chdiggerboss(Actor* arg0, s32 eventId, s32 arg2)
{
	s32 pad;
	Actor* temp_v0;
	Actor* sp2C;
	s32 sp28;
	f32 sp1C[3];

	switch (eventId)
	{
		case 0x49:
			temp_v0 = func_801084B0(0x203, &arg0);
			arg0->unk3C = temp_v0->unk0;
			temp_v0->unk3C = arg0->unk0;
			break;
		case 0x57:
			return func_80802718_chdiggerboss(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 0x10);
		case 0x20:
			func_80803078_chdiggerboss(arg0, func_80101080(), ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
			break;
		case EVENT_95_ACTOR_SPAWNED:
			func_80801DE0_chdiggerboss(arg0);
			break;
		case 0xB:
			return func_80802AB8_chdiggerboss(arg0, arg2);
		case EVENT_2E_ACTOR_DIALOG_ENDED:
			func_80803694_chdiggerboss(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
			break;
		case 0x2F:
			func_808039C0_chdiggerboss(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
			break;
		case 0x52:
			func_808029C8_chdiggerboss(arg0);
			break;
		case EVENT_1F_ACTOR_ONSCREEN:
			func_80800568_chdiggerboss(arg0, ((s32*)&arg2)[0]);
			break;
		case 0x9C:
			func_808005DC_chdiggerboss(arg0, ((s32*)&arg2)[0]);
			break;
		case 0x40:
			if (((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unk3 != 0)
			{
				func_808086E8_chdiggerboss(arg0, ((s32*)&arg2)[0]);
			}
			else
			{
				func_80806DC4_chdiggerboss(arg0, ((s32*)&arg2)[0]);
			}
			break;
		case 0x3D:
			switch (arg2)
			{
			case 0:
				func_80806CF8_chdiggerboss(arg0, arg2);
				break;
			case 1:
			case 2:
				func_80807304_chdiggerboss(arg0, arg2);
				break;
			case 4:
				func_80807E3C_chdiggerboss(arg0, arg2);
				break;
			case 5:
				func_808085E0_chdiggerboss(arg0, arg2);
				break;
			}
			break;
		case 0x96:
			if (func_800D395C() == 0)
			{
				return 0;
			}
			func_80803660_chdiggerboss(arg0, 0xCEB, 0x46);
			break;
		case 0x9F:
			sp2C = func_80802228_chdiggerboss(arg0);
			for (sp28 = 0; sp28 < 4; sp28++)
			{
				func_80805448_chdiggerboss(sp2C, sp28, 0);
			}
			func_800FDC28(0U);
			func_80800618_chdiggerboss(arg0, 0, 0);
			if (func_80802288_chdiggerboss(arg0) != 0)
			{
				func_800D395C();
				func_80803BE8_chdiggerboss(arg0, 0x48, 8);
			}
			else
			{
				func_80803BE8_chdiggerboss(arg0, 0x47, 2);
			}
			break;
		case 0x29:
			_suexpression_entrypoint_7(arg0, 1U, 0x22);
			break;
		case 0x2A:
			_suexpression_entrypoint_8(arg0, 1U);
			break;
		case 0xA2:
			if (!(arg0->unk7C_12) || (func_80802288_chdiggerboss(arg0) == 0))
			{
				return 0;
			}
			func_80802298_chdiggerboss(arg0, B_8080A300_chdiggerboss);
			func_80101074(B_8080A300_chdiggerboss);
			break;
		case 0x90:
			func_80809310_chdiggerboss(arg0);
			break;
		case 0x8D:
			ml_vec3f_copy(sp1C, arg0->position);
			sp1C[1] += 250.0f;
			func_80101010(sp1C);
			break;
		case 0xB5:
			func_80806CA4_chdiggerboss(arg0, arg2);
			break;
		default:
			return 0;
	}
	return 1;
}

//Grunty Spawned
void func_80801DE0_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* sp34;
	Actor* sp30;
	DiggerBossAdditionalMem0* sp2C; //Might be hag1
	s32 sp28;
	s32 sp24;
	Actor* temp_v0_2;
	s16 temp_v1;

	sp34 = func_80100094(arg0, 0U);
	func_80109FE8(arg0, 0);
	func_80807B18_chdiggerboss(arg0);
	func_80806648_chdiggerboss(arg0);
	func_808059A4_chdiggerboss(arg0);
	if (sp34->unkA0 == 0)
	{
		switch (map_getCurrent())
		{
		case MAP_15D_CK_CAULDRON_KEEP:
			if (flag_getValue(FLAG_044_RETRY_BOSS_HAG_1) == 0)
			{
				func_8080290C_chdiggerboss(arg0, 0x1C, 0x20);
				func_80803660_chdiggerboss(arg0, 0x171C, 0x144);
				func_800F82D4(character_getActiveIndex(), 1);
				func_800F8444(character_getActiveIndex(), arg0->rotation);
				event_sendToActorsOfType(0x4F1, 7, 0);
				return;
			}
			actor_mark_delete(arg0);
			actor_mark_delete(func_80802228_chdiggerboss(arg0));
			return;
		case MAP_19A_CK_CAULDRON_KEEP_HAG_1:
			if (flag_getValue(FLAG_044_RETRY_BOSS_HAG_1) == 0)
			{
				func_800F82D4(character_getActiveIndex(), 1);
				func_800F8444(character_getActiveIndex(), arg0->rotation);
				func_8080290C_chdiggerboss(arg0, 0xD, 0x2020);
				_chintrotext_entrypoint_1(0x18B9, 0xF, 1, 0);
				func_800FDC28(1U);
				func_800C964C(0x14);
				return;
			}
			func_80802878_chdiggerboss(arg0, 3, 1);
			func_80800180_chdiggerboss(arg0, 8);
			func_80803660_chdiggerboss(arg0, 0x171F, 0x10E);
			func_800FDC28(1U);
			return;
		}
	}
	else
	{
		temp_v0_2 = func_80802228_chdiggerboss(arg0);
		sp30 = temp_v0_2;
		sp2C = func_80100094(temp_v0_2, 0U);
		temp_v1 = sp34->unk0;
		switch (temp_v1)
		{
		case 0x2D:
			sp28 = func_80802314_chdiggerboss() < 2;
			func_80804A50_chdiggerboss(sp30, 1);
			func_80807698_chdiggerboss(arg0, sp28);
			if (sp28 != 0)
			{
				sp34->unk2 = 0x32;
				func_80803BE8_chdiggerboss(arg0, 0x2E, 2);
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_808041E4_chdiggerboss(sp30, 2);
				func_800F82D4(character_getActiveIndex(), 2);
				func_800F7C58(character_getActiveIndex(), 0x8A, 1);
			}
			else
			{
				func_808041E4_chdiggerboss(sp30, 3);
			}
			break;
		case 0x37:
			sp24 = func_80802314_chdiggerboss() == 0;
			func_808041E4_chdiggerboss(sp30, 2);
			func_80804A50_chdiggerboss(sp30, 1);
			func_80807698_chdiggerboss(arg0, sp24);
			if (sp24 != 0)
			{
				sp34->unk2 = 0x28;
				func_80803BE8_chdiggerboss(arg0, 0x38, 2);
				func_80802878_chdiggerboss(arg0, 3, 1);
				func_800F82D4(character_getActiveIndex(), 2);
				func_800F7C58(character_getActiveIndex(), 0x8A, 1);
			}
			else
			{
				func_808041E4_chdiggerboss(sp30, 3);
			}
			break;
		}
		sp34->unkA0 = 0;
		arg0->unk74_17 = 0;
		sp2C->unk6 = 1;
	}
}

//Grunty
s32 func_80802158_chdiggerboss(Actor* arg0, s32 arg1) {
    return D_80809EE4_chdiggerboss[arg1];
}

//Grunty
s32 func_80802170_chdiggerboss(Actor* arg0, s32 arg1)
{
	DiggerBossAdditionalMem0* sp1C;
	GameFlag temp_v0_2;
	s32 var_v0;

	sp1C = func_80100094(arg0, 0U);
	if (sp1C->unkFC[arg1 + 1] == 0)
	{
		temp_v0_2 = func_80802158_chdiggerboss(arg0, arg1);
		if (temp_v0_2 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
		{
			flag_setValueTrue(temp_v0_2);
		}
		sp1C->unkFC[arg1 + 1] = 1;
		return 0;
	}
	return 1;
}

//Grunty
s32 func_808021E8_chdiggerboss(Actor* arg0, s32 arg1)
{
	if (((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unkFC[arg1 + 1] == 0)
	{
		return 0;
	}
	return 1;
}

//Grunty
Actor* func_80802228_chdiggerboss(Actor* arg0) {
    return func_80106790(arg0->unk3C);
}

//Grunty
s32 func_80802248_chdiggerboss(Actor* arg0)
{
	s32 temp_v0;
	s32 var_v1;

	temp_v0 = func_8010D290(0x10000);
	var_v1 = temp_v0;
	if (temp_v0 == -1)
	{
		var_v1 = character_getActiveIndex();
	}
	return var_v1;
}

//Grunty
s32 func_80802288_chdiggerboss(Actor* arg0)
{
	return arg0->unk64_16;
}

//Grunty
void func_80802298_chdiggerboss(Actor* arg0, f32* arg1)
{
	ml_vec3f_copy(arg1, arg0->position);
	func_800EF1B8(arg1, arg0->rotation[1], arg0->scale * 600.0f);
	arg1[1] += (arg0->scale * 2500.0f);
}

s32 func_80802314_chdiggerboss(void) {
    return 2 - func_800DA980(FLAG3_A4F_UNK, 2);
}

//Hag-1
void func_8080233C_chdiggerboss(Actor* arg0)
{
	func_80102FDC(arg0, 0.25f);
	func_8010A828(arg0, 3U);
	func_80803DC8_chdiggerboss(arg0, 1, 1);
	func_808008C0_chdiggerboss(arg0, 5, 1);
	func_80803E10_chdiggerboss(arg0);
	func_80804784_chdiggerboss(arg0);
	func_80804C28_chdiggerboss(arg0);
	func_80807640_chdiggerboss(arg0);
	func_80807FD8_chdiggerboss(arg0);
	func_808088AC_chdiggerboss(arg0);
	func_80808C64_chdiggerboss(arg0);
	func_80108B04(arg0, 7U);
}

//Hag-1 Update
void func_808023D8_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp3C;
	Actor* temp_v0;
	Actor* temp_v0_2;
	Unk80132ED0* temp_a0;
	u32 var_s0;

	sp3C = func_80100094(arg0, 0U);
	func_80800200_chdiggerboss(arg0);
	func_80803E84_chdiggerboss(arg0);
	func_808047A8_chdiggerboss(arg0);
	func_80804D44_chdiggerboss(arg0);
	func_80808034_chdiggerboss(arg0);
	func_808088CC_chdiggerboss(arg0);
	func_80808CD0_chdiggerboss(arg0);
	_subaddieaudioloop_entrypoint_4(arg0, arg0->position, (u32)sp3C->unk7, &D_80809F04_chdiggerboss);
	if (sp3C->unk7 != 0)
	{
		_subaddieDll_entrypoint_7(arg0, 8);
	}
	for (var_s0 = 0; var_s0 < 8; var_s0++)
	{
		if (func_800F6438(var_s0) != 0)
		{
			func_800F4E5C(var_s0, arg0->position, arg0->rotation, &D_80809F10_chdiggerboss, &D_80809F1C_chdiggerboss);
		}
	}
	if (arg0->unk3C != NULL)
	{
		temp_v0 = func_808026F8_chdiggerboss(arg0);
		ml_vec3f_copy(temp_v0->position, arg0->position);
		temp_v0->rotation[1] = arg0->rotation[1];
	}
	temp_a0 = *(s32*)&sp3C->unk0;
	if (temp_a0 != NULL)
	{
		temp_v0_2 = func_80106790(temp_a0);
		ml_vec3f_copy(temp_v0_2->position, arg0->position);
		temp_v0_2->position[1] += 300.0f;
	}
}

//Hag-1
void func_80802550_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp24;

	sp24 = func_80100094(arg0, 0U);
	func_808040D8_chdiggerboss(arg0);
	func_808049A8_chdiggerboss(arg0);
	func_808053BC_chdiggerboss(arg0);
	func_80807664_chdiggerboss(arg0);
	func_80808000_chdiggerboss(arg0);
	func_80808948_chdiggerboss(arg0);
	if (func_801069A4(*(s32*)&sp24->unk0) != 0)
	{
		func_800FFA88(*(s32*)&sp24->unk0);
		*(s32*)&sp24->unk0 = NULL;
	}
}

//Hag-1 Event handler
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808025D4_chdiggerboss.s")

Actor* func_808026F8_chdiggerboss(Actor* arg0) {
    return func_80106790(arg0->unk3C);
}

//Grunty
s32 func_80802718_chdiggerboss(Actor* arg0, s32 arg1, u32 arg2)
{
	if (_gcdialogcamera_entrypoint_0(arg1, (s32)arg2) != 0)
	{
		if (((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unk8 != 2)
		{
			func_80802878_chdiggerboss(arg0, 2, 1);
		}
		return 2;
	}
	return 1;
}

void func_80802778_chdiggerboss(Actor* arg0, s32 arg1)
{
	DiggerBossAdditionalMem0* sp1C;

	sp1C = func_80100094(arg0, 0U);
	_capod_entrypoint_2(arg0->unk0, 0x22U, arg1 | 0x80000);
	if (sp1C->unkA == 0)
	{
		func_800F7F98(func_80802248_chdiggerboss(arg0), 1);
		sp1C->unkA = 1;
	}
}

//Grunty
s32 func_808027F4_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* temp_s0;
	s32 temp_v0;

	temp_s0 = func_80100094(arg0, 0U);
	temp_v0 = func_80802248_chdiggerboss(arg0);
	if (temp_s0->unkA != 0)
	{
		func_800F7F98(temp_v0, 0);
		temp_s0->unkA = 0;
	}
	if (temp_s0->unk8 != 0)
	{
		_capod_entrypoint_3(0U);
		_plcamera_entrypoint_8(temp_v0);
		temp_s0->unk8 = 0;
		return 1;
	}
	return 0;
}
//Grunty
void func_80802878_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	DiggerBossAdditionalMem0* sp1C;
	s16 temp_v1;

	sp1C = func_80100094(arg0, 0U);
	temp_v1 = sp1C->unk8;
	switch (temp_v1)
	{
	case 0:
		func_80802778_chdiggerboss(arg0, 0);
	case 1:
		_capod_entrypoint_8(1);
		sp1C->unk8 = 2;
	case 2:
		func_808029C8_chdiggerboss(arg0);
		_gcdialogcamera_entrypoint_8();
		_capod_entrypoint_7(arg1, arg2);
		return;
	}
}


//Grunty
void func_8080290C_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2) {
    func_80802938_chdiggerboss(arg0, arg0->unk0, arg1, arg2);
}

void func_80802938_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2, s32 arg3) {
	DiggerBossAdditionalMem0* sp1C;
	sp1C = func_80100094(arg0, 0U);
	switch (sp1C->unk8)
	{
	case 0:
		func_80802778_chdiggerboss(arg0, arg3);
	case 2:
		sp1C->unk8 = 1;
	case 1:
		_capod_entrypoint_6((Unk80132ED0*)arg1, arg2, arg3 | 0x80000);
		return;
	}
}


//Grunty
void func_808029C8_chdiggerboss(Actor* arg0) {
	f32 sp4C[3];
	f32 sp40[3];
	f32 sp30[4];
	f32 temp_f2;
	DiggerBossAdditionalMem0* sp28;

	sp28 = func_80100094(arg0, 0U);
	ml_vec3f_copy(sp4C, arg0->rotation);
	sp4C[1] += sp28->unk10;
	ml_vec3f_copy(sp40, arg0->position);
	func_800EF1B8(sp40, arg0->rotation[1], arg0->scale * 400.0f);
	temp_f2 = arg0->scale * sp28->unkC;
	sp30[0] = arg0->scale * 2700.0f;
	sp30[1] = 800.0f * temp_f2;
	sp30[2] = 500.0f * temp_f2;
	sp30[3] = arg0->scale * 2100.0f;
	_gcdialogcamera_entrypoint_3(sp30, 1.0f);
	_gcdialogcamera_entrypoint_4(sp40);
	_gcdialogcamera_entrypoint_5(sp4C);
}

//Grunty
s32 func_80802AB8_chdiggerboss(Actor* arg0, s32 arg1)
{
	switch (arg1)
	{
		case 0x1C:
			func_8080290C_chdiggerboss(arg0, 0x1F, 0x20);
			return 4;
		case 0x1F:
			func_800F82D4(character_getActiveIndex(), 0);
			_gcgoto_entrypoint_2(MAP_19A_CK_CAULDRON_KEEP_HAG_1, 1, 0);
			func_800A7AD4(1, 0x15);
		default:
			break;
		case 0xD:
			func_800F82D4(character_getActiveIndex(), 0);
			func_80803660_chdiggerboss(arg0, 0x171D, 0x14C);
			func_8080290C_chdiggerboss(arg0, 0x18, 0x20);
			return 4;
		case 0x18:
			flag_setValueTrue(FLAG_044_RETRY_BOSS_HAG_1);
			_gcfrontend_entrypoint_9(0x2C);
			func_80802878_chdiggerboss(arg0, 3, 1);
			func_80803BE8_chdiggerboss(arg0, 2, 2);
			return 4;
		case 0x3B:
			func_80805D64_chdiggerboss(arg0, 0x27);
			return 4;
	}
	return 3;
}

//Grunty
void func_80802BE0_chdiggerboss(Actor* arg0, f32 arg1) {
	((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unkC = arg1;
}

void func_80802C0C_chdiggerboss(Actor* arg0)
{
	func_800F4AF4(func_80802248_chdiggerboss(arg0), 0x14);
	func_80802C40_chdiggerboss(arg0);
}
void func_80802C40_chdiggerboss(Actor* arg0)
{
	f32 sp2C[3];
	s32 pad;
	s32 sp24;
	sp24 = func_80802248_chdiggerboss(arg0);
	ml_vec3f_copy(sp2C, arg0->position);
	sp2C[1] += 500.0f;
	_plcamera_entrypoint_9(sp24, sp2C, 0.0f);
	func_80116088(func_80110014(func_800F5EF8(sp24)), sp2C);
}

void func_80802CB4_chdiggerboss(Actor* arg0)
{
    func_800F4B20(func_80802248_chdiggerboss(arg0));
}

//Grunty
void func_80802CDC_chdiggerboss(Actor* arg0) {
	((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unk42 = 0;
}

//Grunty
s32 func_80802D00_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* temp_s1;
	OptionState* temp_a2;

	temp_s1 = func_80100094(arg0, 0U);
	temp_a2 = &((DiggerBossAdditionalMem0*)func_80100094(arg0, 0U))->unk10C;
	switch (temp_s1->unk40)
	{
		case 1:
			func_80803224_chdiggerboss(arg0);
			break;
		case 2:
			_gcnewoption_entrypoint_0(temp_a2);
			break;
		case 3:
			_gcnewoption_entrypoint_0(temp_a2);
			if (timer_reachedZero(&temp_s1->unk4C) != 0)
			{
				_gcnewoption_entrypoint_37(temp_a2, 1U);
			}
			break;
		case 4:
			_gcnewoption_entrypoint_7(temp_a2);
			temp_s1->unk42 = 0;
			func_8010A828(arg0, 1U);
			if ((temp_s1->unk41 != 0) && (func_80802170_chdiggerboss(arg0, 3) == 0))
			{
				func_80802878_chdiggerboss(arg0, 5, 1);
				func_80803660_chdiggerboss(arg0, 0x172F, 0x106);
				temp_s1->unk40 = 6U;
				temp_s1->unk46 = 1;
			}
			else if ((temp_s1->unk41 == 0) && (func_80802170_chdiggerboss(arg0, 4) == 0))
			{
				func_80802878_chdiggerboss(arg0, 5, 1);
				func_80803660_chdiggerboss(arg0, 0x1730, 0x106);
				temp_s1->unk40 = 6U;
				temp_s1->unk46 = 1;
			}
			else
			{
				func_80800180_chdiggerboss(arg0, 6);
				temp_s1->unk40 = 5U;
			}
			break;
		case 5:
			if (func_80101DDC(arg0) != 0)
			{
				func_800F82D4(character_getActiveIndex(), 0);
				func_80800618_chdiggerboss(arg0, 0, 0);
				func_80800180_chdiggerboss(arg0, 8);
				temp_s1->unk40 = 0U;
				return 1;
			}
			break;
		case 6:
			if (temp_s1->unk46 == 0)
			{
				func_80800180_chdiggerboss(arg0, 6);
				temp_s1->unk40 = 5U;
			}
			break;
		case 0:
			break;
	}
	return 0;
}
//Grunty
void func_80802EF8_chdiggerboss(Actor* arg0)
{
}

//Grunty
void func_80802F00_chdiggerboss(Actor* arg0, s32 arg1)
{
	u32 sp44;
	f32 sp38[3];
	f32 sp2C[3];

	func_80803BE8_chdiggerboss(arg0, arg1, 2);
	func_80802878_chdiggerboss(arg0, 3, 1);
	func_80800618_chdiggerboss(arg0, 0, 1);
	func_808056B8_chdiggerboss(func_80802228_chdiggerboss(arg0));
	sp44 = character_getActiveIndex();
	character_getCoords(sp44, sp38);
	if (func_800EFB8C(sp38, arg0->position) < 550.0f) {
		func_800EEB9C(sp2C, func_800F1DF4(arg0->position, sp38), 550.0f);
		ml_vec3f_add(sp2C, arg0->position);
		sp2C[1] = sp38[1];
		func_800F8418((s32)sp44, &sp2C);
	}
	func_800F7F98(sp44, 1);
}
//Grunty
void func_80802FEC_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = func_80100094(arg0, 0U);
	temp_v0->unk40 = 1;
	temp_v0->unk43 = (s8)arg2;
	temp_v0->unk44 = func_80803424_chdiggerboss(arg0, arg2);
	func_800F7F98(character_getActiveIndex(), 0);
	func_800F8300(character_getActiveIndex(), 2, arg0->position);
	func_80803BE8_chdiggerboss(arg0, arg1, 4);
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803078_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803224_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803338_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808033A0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803424_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803524_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803558_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/chdiggerboss_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803610_chdiggerboss.s")

//Grunty
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

void func_80807B4C_chdiggerboss(Actor* arg0) 
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

void func_808088AC_chdiggerboss(Actor* arg0)
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
