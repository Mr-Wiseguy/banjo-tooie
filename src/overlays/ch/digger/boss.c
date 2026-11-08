#include "ch/digger/boss.h"



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
	f32 unk14;
	f32 unk18;
	f32 unk1C;
	f32 unk20;
	u8 unk24;
	u8 unk25;
	u8 unk26;
	u8 unk27;
	s16 unk28;
	s16 unk2A;
	f32 unk2C;
	f32 unk30;
	f32 unk34;
	f32 unk38;
	f32 unk3C;
	u8 unk40;
	u8 unk41;
	u8 unk42;
	u8 unk43;
	u16 unk44;
	s16 unk46;
	u8 unk48;
	u8 unk49;
	u8 unk4A;
	u8 unk4B;
	f32 unk4C;
	u8 unk50;
	u8 unk51;
	u8 unk52;
	u8 unk53;
	u8 unk54;
	u8 unk55;
	u8 unk56;
	u8 unk57;
	u8 unk58;
	u8 unk59;
	u8 unk5A;
	u8 unk5B;
	u8 unk5C;
	u8 unk5D;
	u8 unk5E;
	u8 unk5F;
	f32 unk60;
	s32 unk64;
	Unk80132ED0* unk68;
	u8 unk6C;
	u8 unk6D;
	u8 unk6E;
	u8 unk6F;
	u8 unk70;
	u8 unk71;
	u8 unk72;
	u8 unk73;
	u8 unk74;
	u8 unk75;
	u8 unk76;
	u8 unk77;
	u8 unk78;
	u8 unk79;
	u8 unk7A;
	u8 unk7B;
	s16 unk7C;
	s16 unk7E;
    s16 unk80;
    s16 unk82;
	f32 unk84;
	s32 unk88;
	s32 unk8C;
	s32 unk90;
	s32 unk94;
	f32 unk98;
	f32 unk9C;
    s16 unkA0;
	u8 unkA2;
	u8 unkA3;
	u8 unkA4;
	u8 unkA5;
	u8 unkA6;
	u8 unkA7;
    u8 padA8[0xC0-0xA8];
	f32 unkC0;
	f32 unkC4;
	s32 unkC8;
	u8 unkCC;
	u8 unkCD;
	u8 unkCE;
	u8 unkCF;
	f32 unkD0;
	Unk80132ED0* unkD4;
	u8 unkD8;
	u8 unkD9;
	u8 unkDA;
	u8 unkDB;
	s32 unkDC;
	f32 unkE0;
	Unk80132ED0* unkE4;
	s32 unkE8;
	s32 unkEC;
	s32 unkF0;
	s32 unkF4;
    f32 unkF8;
    u8 unkFC[4];
    s32 unk100;
    s32 unk104;
    s32 unk108;
    OptionState unk10C;
}DiggerBossAdditionalMem0;//Size 0x10C + the option state I guess

struct unk30Struct {
	s32 unk0;
	s16 unk4;
	s16 unk6;
	s32 unk8;
	f32 unkC[3];
	u8 unk18;
	u8 unk19;
	u8 unk1A;
	u8 unk1B;
};

typedef struct {
	s16 unk0;
	u8 unk2;
	u8 unk3;
	u8 unk4;
	u8 unk5;
	u8 unk6;
	u8 unk7;
	u8 unk8;
	u8 unk9;
	u8 unkA;
	u8 unkB;
	u8 unkC;
	u8 unkD;
	u8 unkE;
	u8 unkF;
	f32 unk10;
	f32 unk14;
	s16 unk18;
	u8 unk1A;
	u8 unk1B;
	f32 unk1C;
	f32 unk20; //Theres an array with elements of size 0x1C in here somewhere
	u8 unk24;
	u8 unk25;
	u8 unk26;
	u8 unk27;
	f32 unk28;
	f32 unk2C;
	struct unk30Struct unk30[4];
	u8 unkA0;
	u8 unkA1;
	u8 unkA2;
	u8 unkA3;
	s16 unkA4;
	u8 unkA6;
	u8 unkA7;
	s32 unkA8;
	s32 unkAC;
	Unk80132ED0* unkB0[4];
	f32 unkC0[2];
	s32 unkC8;
	s32 unkCC;
	s32 unkD0;
	f32 unkD4[3];
	f32 unkE0;
	u8 unkE4[4];
	s32 unkE8;
}Hag1AdditionalMem0;//Size 0xEC

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
u8* func_808033A0_chdiggerboss(Actor*, s32, s32*);
s32 func_80803424_chdiggerboss(Actor*, s32);
s32 func_80803524_chdiggerboss(u8*, s32);
void func_80803558_chdiggerboss(s32, s32, s32);
void func_80803660_chdiggerboss(Actor*, s32, s32);
void func_80803694_chdiggerboss(Actor*, s32, s32);
void func_808039C0_chdiggerboss(Actor*, s32, s32);
void func_80803BE8_chdiggerboss(Actor*, s32, s32);
void func_80803DC8_chdiggerboss(Actor*, s32, s32);
void func_80803E10_chdiggerboss(Actor*);
void func_80803E84_chdiggerboss(Actor*);
void func_808040D8_chdiggerboss(Actor*);
void func_80804140_chdiggerboss(Actor*);
void func_808041E4_chdiggerboss(Actor*, s32);
void func_808042FC_chdiggerboss(Actor*, s32, s32);
void func_808043D8_chdiggerboss(Actor*, f32, s32*);
void func_80804450_chdiggerboss(Actor*);
s32 func_80804644_chdiggerboss(f32, f32, f32);
void func_80804680_chdiggerboss(Actor*);
void func_80804784_chdiggerboss(Actor*);
void func_808047A8_chdiggerboss(Actor*);
void func_808049A8_chdiggerboss(Actor*);
void func_808049DC_chdiggerboss(Actor*);
void func_80804A50_chdiggerboss(Actor*, s32);
void func_80804A7C_chdiggerboss(Actor*, s32, s32);
void func_80804AC8_chdiggerboss(Actor*, s32);
void func_80804C28_chdiggerboss(Actor*);
void func_80804D44_chdiggerboss(Actor*);
void func_80804EFC_chdiggerboss(Actor*, GraphicsBuffers*);
void func_80804FE4_chdiggerboss(Actor*, s32, GraphicsBuffers*);
void func_808053BC_chdiggerboss(Actor*);
void func_80805448_chdiggerboss(Actor*, s32, s32);
void func_808056B8_chdiggerboss(Actor*);
void func_808057D0_chdiggerboss(Actor*);
void func_808059A4_chdiggerboss(Actor*);
void func_808059CC_chdiggerboss(Actor*);
void func_80805A00_chdiggerboss(Actor*, s32);
s32 func_80805A64_chdiggerboss(Actor*);
void func_80805B8C_chdiggerboss(Actor*, f32);
void func_80805D64_chdiggerboss(Actor*, s32);
s32 func_80805DF4_chdiggerboss(Actor*);
void func_808062B8_chdiggerboss(Actor*);
s32 func_80806300_chdiggerboss(Actor*);
s32 func_808063C8_chdiggerboss(Actor*, s32, f32);
void func_808064CC_chdiggerboss(Actor*, s32);
void func_80806528_chdiggerboss(Actor*, s32, s32);
void func_80806648_chdiggerboss(Actor*);
void func_8080666C_chdiggerboss(Actor*);
s32 func_808066A0_chdiggerboss(Actor*);
void func_80806A78_chdiggerboss(Actor*, s32, u8*);
void func_80806B38_chdiggerboss(Actor*);
void func_80806CA4_chdiggerboss(Actor*, s32);
void func_80806CF8_chdiggerboss(Actor*, s32);
void func_80806DC4_chdiggerboss(Actor*, s32);
void func_80806EE4_chdiggerboss(Actor*, s32);
s32 func_808070B0_chdiggerboss(Actor*);
void func_80807280_chdiggerboss(Actor*, s32, s16*);
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
void func_808081AC_chdiggerboss(Actor*);
void func_80808258_chdiggerboss(Actor*);
void func_8080843C_chdiggerboss(Actor*);
void func_80808470_chdiggerboss(Actor*, s32);
void func_80808560_chdiggerboss(Actor*);
void func_808085E0_chdiggerboss(Actor*, s32);
Actor* func_808086A8_chdiggerboss(Actor*);
void func_808086E8_chdiggerboss(Actor*, s32);
void func_808087F0_chdiggerboss(Actor*);
void func_808088AC_chdiggerboss(Actor*);
void func_808088CC_chdiggerboss(Actor*);
void func_80808948_chdiggerboss(Actor*);
void func_80808B40_chdiggerboss(Actor*, s32);
void func_80808BE4_chdiggerboss(Actor*, Actor*, s32);
void func_80808C64_chdiggerboss(Actor*);
void func_80808CD0_chdiggerboss(Actor*);
void func_80808D54_chdiggerboss(Actor*, s32, f32, s32*);
void func_80808F44_chdiggerboss(Actor*);
void func_80809078_chdiggerboss(Actor*, s32, s32);
void func_80809150_chdiggerboss(Actor*);
s32 func_808091E4_chdiggerboss(Actor*);
s32 func_80809234_chdiggerboss(Actor*);
void func_80809310_chdiggerboss(Actor*);
void func_808093F8_chdiggerboss(Actor*);

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
extern s16 D_80809ED4_chdiggerboss[];
extern s16 D_80809EE0_chdiggerboss[];
extern u16 D_80809EE4_chdiggerboss[];
extern u32 D_80809F04_chdiggerboss;
extern s32 D_80809F10_chdiggerboss;
extern s32 D_80809F1C_chdiggerboss;
extern u16 D_80809F28_chdiggerboss[][2];
extern s32 D_80809F34_chdiggerboss;
extern s32 D_80809F3C_chdiggerboss;
extern s32 D_80809F40_chdiggerboss;
extern s32 D_80809F44_chdiggerboss;
extern s32 D_80809F5C_chdiggerboss;
extern s32 D_80809F74_chdiggerboss;
extern s32 D_80809F88_chdiggerboss;
extern s32 D_80809F98_chdiggerboss;
extern s32 D_80809FB0_chdiggerboss;
extern s32 D_80809FC0_chdiggerboss;
extern s32 D_80809FD0_chdiggerboss;
extern s32 D_80809FE0_chdiggerboss;
extern s32 D_8080A028_chdiggerboss;
extern f32 D_8080A038_chdiggerboss;
extern s16 D_8080A060_chdiggerboss[4];
extern s32 D_8080A06C_chdiggerboss[][3];
extern s32 D_8080A0EC_chdiggerboss;
extern s16 D_8080A104_chdiggerboss;
extern s16 D_8080A11C_chdiggerboss[];
extern s32 D_8080A160_chdiggerboss;
extern s32 D_8080A16C_chdiggerboss;
extern f32 D_8080A1AC_chdiggerboss[];
extern f32 D_8080A1BC_chdiggerboss[];
extern f32 D_8080A1CC_chdiggerboss[];
extern s32 D_8080A1DC_chdiggerboss;
extern s32 D_8080A1E8_chdiggerboss;
extern s16 D_8080A1F4_chdiggerboss[3];
extern s16 D_8080A1FC_chdiggerboss[3];
extern s16 D_8080A1FE_chdiggerboss[][4];
extern s16 D_8080A200_chdiggerboss[][4];
extern s16 D_8080A202_chdiggerboss[][4];
extern s16 D_8080A204_chdiggerboss[][4];
extern s16 D_8080A206_chdiggerboss[][4];
extern f32 D_8080A208_chdiggerboss[][2];
extern s32 D_8080A240_chdiggerboss;
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
                ((DiggerBossAdditionalMem0*)actor_getAdditionalMem(func_80802228_chdiggerboss(arg0), 0U))->unk7 = 1;
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
    sp3C = actor_getAdditionalMem(arg0, 0U);
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

    sp20 = actor_getAdditionalMem(func_808026F8_chdiggerboss(arg0), 0U);
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
            _gcnewoption_entrypoint_1(&((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk10C, arg1);
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
    temp_s2 = actor_getAdditionalMem(arg0, 0U);
    func_801015D0(arg0);
    for (index = 0; index < 1; index++)
    {
        func_800DF744(D_80809EE0_chdiggerboss[index], temp_s2->unkFC[index]);
    }
}

//Grunty
void func_808005DC_chdiggerboss(Actor* arg0, s32 arg1)
{
    func_80806528_chdiggerboss(arg0, func_800AE6BC(func_801040A8(arg0)), arg1);
}

//Grunty
void func_80800618_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
    ((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unkFC[arg1] = arg2;
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
	Hag1AdditionalMem0* temp_s2;
    s32 index;
    temp_s2 = actor_getAdditionalMem(arg0, 0U);
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
	Hag1AdditionalMem0* sp2C;
    s32 temp_v0;

    sp2C = actor_getAdditionalMem(arg0, 0U);
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

//Hag-1
void func_808008C0_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
    ((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unkE4[arg1] = arg2;
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

	sp44 = actor_getAdditionalMem(arg0, 0U);
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
		_suexpression_entrypoint_10(actor_getAdditionalMem(arg0, 1U), arg0->unk0, 0U);
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
			if (((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk3 != 0)
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

	sp34 = actor_getAdditionalMem(arg0, 0U);
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
		sp2C = actor_getAdditionalMem(temp_v0_2, 0U);
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

	sp1C = actor_getAdditionalMem(arg0, 0U);
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
	if (((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unkFC[arg1 + 1] == 0)
	{
		return 0;
	}
	return 1;
}

//Get the other actor Hag-1 for Grunty and Grunty for Hag-1
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
	ml_translateAngleDist(arg1, arg0->rotation[1], arg0->scale * 600.0f);
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

	sp3C = actor_getAdditionalMem(arg0, 0U);
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

	sp24 = actor_getAdditionalMem(arg0, 0U);
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
		if (((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk8 != 2)
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

	sp1C = actor_getAdditionalMem(arg0, 0U);
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

	temp_s0 = actor_getAdditionalMem(arg0, 0U);
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

	sp1C = actor_getAdditionalMem(arg0, 0U);
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
	sp1C = actor_getAdditionalMem(arg0, 0U);
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

	sp28 = actor_getAdditionalMem(arg0, 0U);
	ml_vec3f_copy(sp4C, arg0->rotation);
	sp4C[1] += sp28->unk10;
	ml_vec3f_copy(sp40, arg0->position);
	ml_translateAngleDist(sp40, arg0->rotation[1], arg0->scale * 400.0f);
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
	((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unkC = arg1;
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
	((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk42 = 0;
}

//Grunty
s32 func_80802D00_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* temp_s1;
	OptionState* temp_a2;

	temp_s1 = actor_getAdditionalMem(arg0, 0U);
	temp_a2 = &((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk10C;
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
		ml_vec3f_getVecFromYaw(sp2C, func_800F1DF4(arg0->position, sp38), 550.0f);
		ml_vec3f_add(sp2C, arg0->position);
		sp2C[1] = sp38[1];
		func_800F8418((s32)sp44, &sp2C);
	}
	func_800F7F98(sp44, 1);
}
//Grunty
void func_80802FEC_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unk40 = 1;
	temp_v0->unk43 = (s8)arg2;
	temp_v0->unk44 = func_80803424_chdiggerboss(arg0, arg2);
	func_800F7F98(character_getActiveIndex(), 0);
	func_800F8300(character_getActiveIndex(), 2, arg0->position);
	func_80803BE8_chdiggerboss(arg0, arg1, 4);
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803078_chdiggerboss.s")

//Grunty
void func_80803224_chdiggerboss(Actor* arg0)
{
	OptionState* optionState;
	DiggerBossAdditionalMem0* temp_s1;

	temp_s1 = actor_getAdditionalMem(arg0, 0U);
	optionState = &((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk10C;
	bzero(optionState, _gcnewoption_entrypoint_2());
	_gcnewoption_entrypoint_5(optionState, _gcnewoption_entrypoint_35, 0U, temp_s1->unk44, (s32)arg0->unk0);
	_gcnewoption_entrypoint_8(optionState, 3U);
	_gcnewoption_entrypoint_9(optionState, 3U);
	_gcnewoption_entrypoint_10(optionState, 2U);
	_gcnewoption_entrypoint_14(optionState, 0U, 0U, 0U, 4.0f);
	_gcnewoption_entrypoint_32(optionState, 0x22U);
	_gcnewoption_entrypoint_30(optionState, &D_80809F34_chdiggerboss);
	_gcnewoption_entrypoint_28(optionState);
	_gcnewoption_entrypoint_29(optionState, 1);
	_gcnewoption_entrypoint_11(optionState);
	temp_s1->unk40 = 2;
	temp_s1->unk42 = 1;
	temp_s1->unk48 = 1;
	func_8010A828(arg0, 9U);
}

void func_80803338_chdiggerboss(OptionState* arg0) {
	u32 var_s0;
	for (var_s0 = 0; var_s0 < 3; var_s0++)
	{
		_gcnewoption_entrypoint_12(arg0, var_s0, (var_s0 + 0xA));
		_gcnewoption_entrypoint_21(arg0, var_s0);
	}
}

//Grunty
u8* func_808033A0_chdiggerboss(Actor* arg0, s32 arg1, s32* arg2) {
	DiggerBossAdditionalMem0* temp_v1;

	temp_v1 = actor_getAdditionalMem(arg0, 0U);
	switch (arg1)
	{
		case 0:
			*arg2 = 0x14;
			return &temp_v1->unk50;
		case 1:
			*arg2 = 0x14;
			return &temp_v1->unk53;
		case 2:
			*arg2 = 0x14;
			return &temp_v1->unk56;
		default:
			return NULL;
	}
}

//Grunty
s32 func_80803424_chdiggerboss(Actor* arg0, s32 arg1)
{
	s32 sp34;
	s32 temp_s2;
	s32 var_s0;
	s32 var_s1;

	temp_s2 = func_808033A0_chdiggerboss(arg0, arg1, &sp34);
	var_s0 = rand_iBounded(0, sp34);
	for (var_s1 = 0; var_s1 < sp34; var_s1++)
	{
		if (func_80803524_chdiggerboss(temp_s2, var_s0) == 0)
		{
			func_80803558_chdiggerboss(temp_s2, var_s0, 1);
			return D_80809F28_chdiggerboss[arg1][0] + var_s0;
		}
		var_s0 += 1;
		if (var_s0 == sp34)
		{
			var_s0 = 0;
		}
	}
	bzero((void*)temp_s2, (sp34 + 7) >> 3);
	var_s0 = rand_iBounded(0, sp34);
	func_80803558_chdiggerboss(temp_s2, var_s0, 1);
	return D_80809F28_chdiggerboss[arg1][0] + var_s0;
}

//Hag-1
s32 func_80803524_chdiggerboss(u8* arg0, s32 arg1)
{
	s32 tempV0;
	if (*((arg1 >> 3) + arg0) & (1 << (arg1 & 7)))
	{
		tempV0 = 1;
	}
	else
		tempV0 = 0;
	return tempV0;
}

//Hag-1
void func_80803558_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
	u8* temp_v0;
	u8* temp_v0_2;

	if (arg2 != 0) {
		temp_v0 = (arg1 >> 3) + arg0;
		*temp_v0 |= 1 << (arg1 & 7);
		return;
	}
	temp_v0_2 = (arg1 >> 3) + arg0;
	*temp_v0_2 &= ~(1 << (arg1 & 7));
}

void chdiggerboss_entrypoint_2(s32 arg0, Unk80132ED0* arg1)
{
	Actor* sp1C;
	DiggerBossAdditionalMem0* sp18;
	OptionState* optionState;

	sp1C = func_80106790(arg1);
	sp18 = actor_getAdditionalMem(sp1C, 0U);
	optionState = &((DiggerBossAdditionalMem0*)actor_getAdditionalMem(sp1C, 0U))->unk10C;
	if (sp18->unk40 == 2) {
		_gcnewoption_entrypoint_37(optionState, 1U);
	}
}

void func_80803610_chdiggerboss(s32 arg0)
{
	if (func_800CEAA8(8) != 0)
	{
		func_800CE928(8, 0, 0);
		func_800CE88C(8, 0);
		func_800CEBD8(8, 0);
	}
}

//Grunty
void func_80803660_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	_subaddiedialog_entrypoint_11(arg0->unk0, (u32)arg1, (u32)arg2, arg0->position, 0x22U);
}

//Grunty
void func_80803694_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	DiggerBossAdditionalMem0* sp24;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	switch (arg1)
	{
		case 0x171D:
			return;
		case 0x171E:
		case 0x171F:
			func_80803BE8_chdiggerboss(arg0, 4, 3);
			return;
		case 0x1720:
			func_800FDC28(0x14U);
			func_80805A00_chdiggerboss(arg0, 6);
			return;
		case 0x172E:
			func_80802FEC_chdiggerboss(arg0, 9, 0);
			return;
		case 0x172F:
		case 0x1730:
			func_80802878_chdiggerboss(arg0, 3, 1);
			if (func_80802170_chdiggerboss(arg0, 2) == 0)
			{
				func_80803660_chdiggerboss(arg0, 0x1722, 0x106);
				return;
			}
			func_800C0850();
			sp24->unk46 = 0;
			return;
		case 0x1722:
			sp24->unk46 = 0;
			return;
		case 0x1721:
			func_80805A00_chdiggerboss(arg0, 0xE);
			return;
		case 0x1723:
			func_80807280_chdiggerboss(arg0, 0x16, &D_80809CF0_chdiggerboss);
			return;
		case 0x1724:
			func_80807280_chdiggerboss(arg0, 0x1E, &D_80809D00_chdiggerboss);
			return;
		case 0x1725:
			func_8080290C_chdiggerboss(arg0, 0x3B, 0);
			func_80803660_chdiggerboss(arg0, 0x1726, 0x14C);
			return;
		case 0x1731:
			func_80803BE8_chdiggerboss(arg0, 0xC, 3);
			return;
		case 0x1732:
			func_80803BE8_chdiggerboss(arg0, 0x14, 3);
			return;
		case 0x1733:
			func_80803BE8_chdiggerboss(arg0, 0x2F, 3);
			return;
		case 0x1734:
			func_80802878_chdiggerboss(arg0, 3, 1);
			func_80803660_chdiggerboss(arg0, 0x1729, 0x10E);
			return;
		case 0x1729:
			func_80806A78_chdiggerboss(arg0, 0x3A, &D_80809CC0_chdiggerboss);
			func_80806EE4_chdiggerboss(arg0, 1);
			sp24->unk4 = 1;
			return;
		case 0x172A:
			func_80806A78_chdiggerboss(arg0, 0x3C, &D_80809CD0_chdiggerboss);
			func_80806EE4_chdiggerboss(arg0, 1);
			return;
		case 0x172B:
			func_80806A78_chdiggerboss(arg0, 0x3E, &D_80809CE0_chdiggerboss);
			func_80806EE4_chdiggerboss(arg0, 1);
			func_80807DC0_chdiggerboss(arg0, 2);
			func_808080C0_chdiggerboss(func_80802228_chdiggerboss(arg0), 2);
			return;
		case 0x172C:
			func_80808470_chdiggerboss(arg0, 0x40);
			return;
		case 0x172D:
			func_80802BE0_chdiggerboss(arg0, 1.0f);
			func_80808560_chdiggerboss(arg0);
			return;
		case 0x1735:
			func_80809150_chdiggerboss(arg0);
			return;
		case 0x14D8:
			func_800FDC28(0U);
			_gcgoto_entrypoint_1(0x191U, 1U);
			return;
		case 0xCEB:
			if (arg2 > 0) {
				_gcfrontend_entrypoint_11();
				return;
			}
			_gcfrontend_entrypoint_10();
			return;
	}
}
//Grunty
void func_808039C0_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	Actor* temp_s2;
	s32 var_s0;
	s32 var_s0_2;

	temp_s2 = func_80802228_chdiggerboss(arg0);
	switch (arg1)
	{
		case 0x1720:
			func_80805448_chdiggerboss(temp_s2, 0, 1);
			func_80805448_chdiggerboss(temp_s2, 2, 1);
			return;
		case 0x1721:
			for (var_s0 = 0; var_s0 < 4; var_s0++)
			{
				func_80805448_chdiggerboss(temp_s2, var_s0, 1);
			}
			return;
		case 0x1723:
			func_8080041C_chdiggerboss(temp_s2, 0xE);
			return;
		case 0x1724:
			func_8080041C_chdiggerboss(temp_s2, 0x10);
			return;
		case 0x1725:
			switch (arg2) 
			{
				case 1:
					func_8080041C_chdiggerboss(temp_s2, 0x12);
					return;
				case 2:
					func_80805448_chdiggerboss(temp_s2, 0, 1);
					func_80805448_chdiggerboss(temp_s2, 3, 1);
					return;
			}
			break;
		case 0x1726:
			if (arg2 == 1) 
			{
				func_80804A50_chdiggerboss(temp_s2, 2);
				return;
			}
		default:
			return;
		case 0x1734:
			switch (arg2) 
			{
				case 1:
					func_80804A50_chdiggerboss(temp_s2, 0);
					return;
				case 2:
					var_s0_2 = 0;
					do {
						func_80805448_chdiggerboss(temp_s2, var_s0_2, 2);
						var_s0_2 += 1;
					} while (var_s0_2 != 4);
					return;
				case 3:
					func_808041E4_chdiggerboss(temp_s2, 4);
					return;
			}
			break;
		case 0x172A:
			switch (arg2) 
			{
				case 1:
					func_8080041C_chdiggerboss(temp_s2, 0x14);
					return;
				case 2:
					func_80807DC0_chdiggerboss(arg0, 1);
					return;
			}
			break;
		case 0x172B:
			if (arg2 == 1)
			{
				func_808080C0_chdiggerboss(func_80802228_chdiggerboss(arg0), 1);
			}
			break;
	}
}

//Grunty
void func_80803BE8_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	s32 var_s0;
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unk0 = (s16)arg1;
	if (arg2 != -1)
	{
		func_80800180_chdiggerboss(arg0, arg2);
	}
	switch (arg1)
	{
		case 6:
			func_80805448_chdiggerboss(func_80802228_chdiggerboss(arg0), 0, 1);
			func_80805448_chdiggerboss(func_80802228_chdiggerboss(arg0), 2, 1);
			temp_v0->unk20 = 40.0f;
			temp_v0->unk1C = 10.0f;
			return;
		case 14:
			for (var_s0 = 0; var_s0 < 4; var_s0++)
			{
				func_80805448_chdiggerboss(func_80802228_chdiggerboss(arg0), var_s0, 1);
			}
			temp_v0->unk1C = 10.0f;
			temp_v0->unk20 = -60.0f;
			return;
		case 39:
			func_80805448_chdiggerboss(func_80802228_chdiggerboss(arg0), 0, 1);
			func_80805448_chdiggerboss(func_80802228_chdiggerboss(arg0), 3, 1);
			temp_v0->unk30 = 5.0f;
			temp_v0->unk34 = 5.0f;
			temp_v0->unk3C = 40.0f;
			temp_v0->unk20 = 40.0f;
			temp_v0->unk38 = 250.0f;
			return;
		case 49:
			for (var_s0 = 0; var_s0 < 4; var_s0++)
			{
				func_80805448_chdiggerboss(func_80802228_chdiggerboss(arg0), var_s0, 1);
			}
			temp_v0->unk30 = 5.0f;
			temp_v0->unk34 = 5.0f;
			temp_v0->unk3C = 60.0f;
			temp_v0->unk38 = 350.0f;
			temp_v0->unk20 = -60.0f;
			return;
	}
}

//Hag-1
void func_80803DC8_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk4 = arg1;
	if (arg2 != -1)
	{
		func_8080041C_chdiggerboss(arg0, arg2);
	}
}

//Hag-1
void func_80803E10_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unkB = 0;
	sp1C->unkC = 0;
	sp1C->unkD = 0;
	sp1C->unk14 = rand_fBounded(0.85f, 2.5f);
	sp1C->unkA = func_800E8B74(0U);
	func_800E8D5C(sp1C->unkA, &D_80809F98_chdiggerboss, 3U);
}

//Hag-1
void func_80803E84_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* temp_v0;
	f32 sp30;
	s32 sp2C;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	switch (temp_v0->unk8)
	{
		case 0:
			break;
		case 1:
			temp_v0->unkD = _subaddieaudioloop_entrypoint_7(temp_v0->unkD, arg0->position, 1, &D_80809FB0_chdiggerboss, arg0->unk70_0);
			if (timer_reachedZero(&temp_v0->unk10) != 0) {
				func_808041E4_chdiggerboss(arg0, 2);
			}
			break;
		case 2:
			sp30 = ml_map_f(((f32*)arg0->actorData)[3], 0.0f, 350.0f, 0.85f, 1.1f);
			sp2C = ml_map_f(((f32*)arg0->actorData)[3], 0.0f, 350.0f, 25000.0f, 32000.0f);
			if (temp_v0->unkB == 0)
			{
				func_800C4B64(sp30);
				func_800C4B70(sp2C);
			}
			temp_v0->unkB = _subaddieaudioloop_entrypoint_7((s32)temp_v0->unkB, arg0->position, 1, &D_80809FC0_chdiggerboss, arg0->unk70_0);
			if (temp_v0->unkB != 0) {
				func_800C31DC(temp_v0->unkB, sp30);
				func_800C3058(temp_v0->unkB, sp2C);
			}
			if ((func_80802314_chdiggerboss() < 2) && (timer_reachedZero_dupe(&temp_v0->unk14) != 0)) {
				_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
				temp_v0->unk14 = rand_fBounded(0.85f, 2.5f);
				temp_v0->unk9 = 4U;
			}
			func_80804680_chdiggerboss(arg0);
			if (func_8001210C(1) != 0) {
				if (temp_v0->unk9 != 0) {
					func_808043D8_chdiggerboss(arg0, 1.25f, &D_80809F3C_chdiggerboss);
					temp_v0->unk9 = (u8)(temp_v0->unk9 - 1);
				}
				else {
					func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F40_chdiggerboss);
				}
			}
			break;
		case 3:
			temp_v0->unkC = _subaddieaudioloop_entrypoint_7((s32)temp_v0->unkC, arg0->position, 1, &D_80809FD0_chdiggerboss, arg0->unk70_0);
			break;
		case 4:
			func_80804450_chdiggerboss(arg0);
			break;
	}
	func_80804140_chdiggerboss(arg0);
}

//Hag-1
void func_808040D8_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	if (temp_v0->unkA != 0) {
		func_800E8C08(temp_v0->unkA);
		temp_v0->unkA = 0U;
	}
	temp_v0->unkB = _subaddieaudioloop_entrypoint_3(temp_v0->unkB);
	temp_v0->unkC = _subaddieaudioloop_entrypoint_3(temp_v0->unkC);
	temp_v0->unkD = _subaddieaudioloop_entrypoint_3(temp_v0->unkD);
}

//Hag-1
void func_80804140_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp2C;
	s32 sp28;
	f32 sp24;

	sp2C = actor_getAdditionalMem(arg0, 0U);
	sp28 = ml_map_f(((f32*)arg0->actorData)[3], 0.0f, 350.0f, 15.0f, 25.0f);
	sp24 = ml_map_f(((f32*)arg0->actorData)[3], 0.0f, 350.0f, 0.35f, 0.2f);
	func_800E8DB0(sp2C->unkA, sp28);
	func_800E8D28(sp2C->unkA, sp24);
}

//Hag-1
void func_808041E4_chdiggerboss(Actor* arg0, s32 arg1) {
	Hag1AdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unk8 = arg1;
	switch (arg1) {
		case 0:
			temp_v0->unkB = _subaddieaudioloop_entrypoint_3(temp_v0->unkB);
			temp_v0->unkC = _subaddieaudioloop_entrypoint_3(temp_v0->unkC);
			temp_v0->unkD = _subaddieaudioloop_entrypoint_3(temp_v0->unkD);
			return;
		case 1:
			temp_v0->unk10 = 1.4f;
			return;
		case 2:
			temp_v0->unkC = _subaddieaudioloop_entrypoint_3(temp_v0->unkC);
			temp_v0->unkD = _subaddieaudioloop_entrypoint_3(temp_v0->unkD);
			return;
		case 3:
			temp_v0->unkB = _subaddieaudioloop_entrypoint_3(temp_v0->unkB);
			temp_v0->unkD = _subaddieaudioloop_entrypoint_3(temp_v0->unkD);
			return;
		case 4:
			temp_v0->unkB = _subaddieaudioloop_entrypoint_3(temp_v0->unkB);
			temp_v0->unkC = _subaddieaudioloop_entrypoint_3(temp_v0->unkC);
			temp_v0->unkD = _subaddieaudioloop_entrypoint_3(temp_v0->unkD);
			temp_v0->unk10 = 0.0f;
		default:
			return;
	}
}
s32 func_808042D8_chdiggerboss(Actor* arg0) {
	return ((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk8;
}

void func_808042FC_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	Hag1AdditionalMem0* temp_v0;
	f32 sp30;
	f32 sp2C;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	if (temp_v0->unk8 != 0)
	{
		sp30 = func_800E8C58(temp_v0->unkA);
		sp2C = 1.0f / _dbskeleton_entrypoint_1(func_800B27E0((void*)arg2));
		func_800E0C20((Unkfunc_800E0960_1*)arg1, 3U, sp2C, 0.0f, sp30, 0.0f);
		func_800E0C20((Unkfunc_800E0960_1*)arg1, 0xAU, sp2C, 0.0f, -sp30, 0.0f);
		func_800E0C20((Unkfunc_800E0960_1*)arg1, 0x18U, sp2C, 0.0f, -sp30, 0.0f);
	}
}

void func_808043D8_chdiggerboss(Actor* arg0, f32 arg1, s32* arg2) {
	f32 sp24[3];
	s32 sp20;

	if (_subaddieskeleton_entrypoint_2(arg0->unk0, 7, &sp24) != 0) {
		sp20 = func_800B53A4(1);
		func_800BAB80(sp20, arg2);
		func_800BABB8(sp20, &sp24, arg0->position, arg1, &D_80809FE0_chdiggerboss);
	}
}

void func_80804450_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp2C;
	f32 sp28;
	s32 sp24;

	sp2C = actor_getAdditionalMem(arg0, 0U);
	sp28 = sp2C->unk10;
	sp24 = timer_reachedValueInc(&sp2C->unk10, 4.0f);
	if (func_80804644_chdiggerboss(sp2C->unk10, sp28, 0.1f) != 0) {
		_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
		func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F3C_chdiggerboss);
	}
	if (func_80804644_chdiggerboss(sp2C->unk10, sp28, 0.4f) != 0) {
		_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
		func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F3C_chdiggerboss);
	}
	if (func_80804644_chdiggerboss(sp2C->unk10, sp28, 1.2f) != 0) {
		_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F74_chdiggerboss);
		func_808043D8_chdiggerboss(arg0, 1.25f, &D_80809F3C_chdiggerboss);
	}
	if (func_80804644_chdiggerboss(sp2C->unk10, sp28, 2.0f) != 0) {
		_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
		func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F3C_chdiggerboss);
	}
	if (func_80804644_chdiggerboss(sp2C->unk10, sp28, 2.4f) != 0) {
		_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F5C_chdiggerboss);
		func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F40_chdiggerboss);
	}
	if (func_80804644_chdiggerboss(sp2C->unk10, sp28, 3.4f) != 0) {
		_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F88_chdiggerboss);
		func_808043D8_chdiggerboss(arg0, 1.5f, &D_80809F3C_chdiggerboss);
	}
	if (sp24 != 0) {
		func_808041E4_chdiggerboss(arg0, 0);
	}
}

s32 func_80804644_chdiggerboss(f32 arg0, f32 arg1, f32 arg2)
{
	if ((arg2 < arg0) && (arg1 <= arg2))
	{
		return 1;
	}
	return 0;
}

void func_80804680_chdiggerboss(Actor* arg0)
{
	s32 sp5C;
	f32 sp50[3];
	f32 sp44[3];
	f32 sp38[3];
	f32 sp34;
	s32 pad;
	f32 sp24[3];

	if (_subaddieskeleton_entrypoint_2(arg0->unk0, 7, sp44) != 0)
	{
		ml_translateAngleDist(sp44, arg0->rotation[1], 150.0f);
		ml_vec3f_getVecFromYaw(sp38, arg0->rotation[1] - 180.0f, 1000.0f);
		sp5C = func_8010D490(sp44, sp38, 650.0f, 325.0f, -1);
		if (sp5C != -1)
		{
			character_getCoords(sp5C, sp50);
			sp34 = ml_map_f(func_800EFB8C(sp44, sp50), 0.0f, 650.0f, 1400.0f, 100.0f);
			ml_vec3f_getVecFromYaw(sp24, func_800F1DF4(sp44, sp50), sp34);
			func_800F48BC(sp5C, sp24);
		}
	}
}

void func_80804784_chdiggerboss(Actor* arg0) {
	((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk1A = 0;
}

//Hag-1
void func_808047A8_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* temp_v0;
	s32 sp30;
	f32 sp2C;
	s32 sp28;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	switch (temp_v0->unk18)
	{
	case 0:
		temp_v0->unk20 = func_800F15F8(temp_v0->unk20, 0.0f, time_getDelta() * 0.4f);
		func_80804AC8_chdiggerboss(arg0, 0);
		break;
	case 1:
		temp_v0->unk20 = func_800F15F8(temp_v0->unk20, 0.2f, time_getDelta() * 0.4f);
		func_80804AC8_chdiggerboss(arg0, 1);
		break;
	case 2:
		temp_v0->unk20 = func_800F15F8(temp_v0->unk20, 1.0f, time_getDelta() * 0.4f);
		func_80804AC8_chdiggerboss(arg0, 1);
		break;
	}
	sp30 = temp_v0->unk20 > 0.0f;
	func_808049DC_chdiggerboss(arg0);
	sp2C = ml_map_f(temp_v0->unk20, 0.0f, 1.0f, 0.7f, 1.1f);
	sp28 = ml_map_f(temp_v0->unk20, 0.0f, 1.0f, 22000.0f, 32000.0f);
	if (temp_v0->unk1A == 0)
	{
		func_800C4B64(sp2C);
		func_800C4B70(sp28);
	}
	temp_v0->unk1A = _subaddieaudioloop_entrypoint_7(temp_v0->unk1A, arg0->position, sp30, &D_8080A028_chdiggerboss, arg0->unk70_0);
	if (temp_v0->unk1A != 0) {
		func_800C31DC(temp_v0->unk1A, sp2C);
		func_800C3058(temp_v0->unk1A, sp28);
	}
}

void func_808049A8_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unk1A = _subaddieaudioloop_entrypoint_3(sp1C->unk1A);
}

void func_808049DC_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* temp_v0;
	f32 sp28;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	sp28 = ml_map_f(temp_v0->unk20, 0.0f, 1.0f, 0.0f, 300.0f);
	temp_v0->unk1C += sp28 * time_getDelta();
	temp_v0->unk1C = ml_normalizeAngle_f(temp_v0->unk1C);
}

void func_80804A50_chdiggerboss(Actor* arg0, s32 arg1) {
	((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk18 = arg1;
}

void func_80804A7C_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	func_800E0AFC((Unkfunc_800E0960_1*)arg1, 0x2AU, 1.0f, 0.0f, 0.0f, ((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk1C);
}

//Hag-1
void func_80804AC8_chdiggerboss(Actor* arg0, s32 arg1)
{
	f32 sp84[3];
	f32 sp78[3];
	f32 sp6C[3];
	u32 charIndex;
	f32 sp5C[3];

	if (arg1 != 0)
	{
		for (charIndex = 0; charIndex < 8; charIndex++)
		{
			if (!func_800F6438(charIndex))
				continue;
			if (func_800F6478(charIndex) && func_800F581C(charIndex) & 0x10000000)
			{
				ml_vec3f_copy(sp5C, arg0->position);
				ml_translateAngleDist(sp5C, arg0->rotation[1], 1300.0f);
				sp5C[1] += 275.0f;
				character_getCoords(charIndex, sp6C);
				ml_vec3f_copy(sp84, arg0->position);
				sp84[1] += 275.0f;
				func_800F018C(sp78, sp84, sp5C, sp6C);
				func_800F7A2C(charIndex, 6, sp78);
				func_808062B8_chdiggerboss(func_808026F8_chdiggerboss(arg0));
			}
		}
	}
}

//Hag-1
void func_80804C28_chdiggerboss(Actor* arg0)
{
	s32 var_s1;
	u8 temp_v0_2;
	s32 temp_v0_3;
	Hag1AdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0);
	temp_v0->unk24 = 0;
	for (var_s1 = 0; var_s1 < 4; var_s1++)
	{
		func_80805448_chdiggerboss(arg0, var_s1, 0);
		temp_v0_3 = func_800C8A98();
		temp_v0->unk30[var_s1].unk0 = temp_v0_3;
		func_800C8F64(temp_v0_3, 9);
		func_800C8D4C(temp_v0_3, &D_8080A038_chdiggerboss);
		ml_vec3f_copy(temp_v0->unk30[var_s1].unkC, arg0->position);
		temp_v0_2 = func_800E8714(1);
		temp_v0->unk30[var_s1].unk18 = temp_v0_2;
		func_800E8830(temp_v0_2, arg0->position);
		func_800E8870(temp_v0_2, 20.0f);
	}
	func_808057D0_chdiggerboss(arg0);
	func_808056B8_chdiggerboss(arg0);
}

//Hag-1
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804D44_chdiggerboss.s")

//Hag-1
void func_80804EFC_chdiggerboss(Actor* arg0, GraphicsBuffers* arg1)
{
	Hag1AdditionalMem0* temp_v0;
	s32 var_s2;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	for (var_s2 = 0; var_s2 < 4; var_s2++)
	{
		func_800DF744(D_8080A060_chdiggerboss[var_s2], temp_v0->unk30[var_s2].unk6);
	}
	func_800DF830(1);
	func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, asset_load(0x955));
	for (var_s2 = 0; var_s2 < 4; var_s2++)
	{
		if (temp_v0->unk30[var_s2].unk4 != 0)
		{
			func_80804FE4_chdiggerboss(arg0, var_s2, arg1);
		}
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804FE4_chdiggerboss.s")

//Hag-1
void func_808053BC_chdiggerboss(Actor* arg0)
{
	s32 index;
	Hag1AdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unk24 = _subaddieaudioloop_entrypoint_3(temp_v0->unk24);
	for (index = 0; index < 4; index++)
	{
		if (temp_v0->unk30[index].unk0 != 0)
		{
			func_800C8B84(temp_v0->unk30[index].unk0);
			temp_v0->unk30[index].unk0 = 0;
		}
		if (temp_v0->unk30[index].unk18 != 0)
		{
			func_800E87E0(temp_v0->unk30[index].unk18);
			temp_v0->unk30[index].unk18 = 0U;
		}
	}
}

//Hag-1
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805448_chdiggerboss.s")

void func_808056B8_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	actor_disableCollision(arg0);
	sp1C->unk2C = 1.0f;
}

void func_808056F8_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp24;
	s32 sp20;
	s32 charIndex;
	s32 temp_v0_2;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	sp20 = 0;
	if (sp24->unk25 != 0)
	{
		charIndex = func_80802248_chdiggerboss(func_808026F8_chdiggerboss(arg0));
		if ((func_800F6478(charIndex) != 0) && (func_800F8004(charIndex) == 0))
		{
			if (timer_reachedZero_dupe(&sp24->unk2C) != 0)
			{
				sp20 = 1;
			}
		}
		else
		{
			sp24->unk2C = 1.0f;
		}
	}
	actor_setCollision(arg0, sp20);
}

s32 func_80805798_chdiggerboss(Actor* arg0, s32 arg1) {
	return ((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk30[arg1].unk4;
}

void func_808057D0_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* var_s2;
	s32 var_s3;
	s32 var_s0;
	s32 temp_s1;

	var_s2 = actor_getAdditionalMem(arg0, 0U);
	for (var_s3 = 0; var_s3 < 4; var_s3++)
	{
		if (var_s2->unk30[var_s3].unk4 == 1)
		{
			var_s0 = 1;
		}
		else
		{
			var_s0 = 0;
		}
		temp_s1 = var_s2->unk30[var_s3].unk0;
		if (temp_s1 == 0)
		{
			continue;
		}
		func_800C8FE0(temp_s1, var_s0);
		if (var_s0 != 0)
		{
			func_800C8CB8(temp_s1, var_s2->unk30[var_s3].unkC);
			func_800C8E84(temp_s1, D_8080A06C_chdiggerboss[func_8001210C(1)]);
		}
	}
}

void func_808058B0_chdiggerboss(Actor* arg0, Unk80132ED0* arg1)
{
	Hag1AdditionalMem0* sp24;
	f32 sp18[3];

	sp24 = actor_getAdditionalMem(arg0, 0U);
	func_800F79DC(arg1->unk18_5, 6, arg0->unk0);
	if (sp24->unk28 == 0.0f)
	{
		if (_subaddiecustomhits_entrypoint_4(arg0, sp18, 0) == 0) {
			func_800F5BF0(arg1->unk18_5, sp18);
		}
		_chelectricfence_entrypoint_1(arg0, sp18);
		sp24->unk28 = 0.6f;
	}
}

void func_80805960_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk30[arg1].unk6 = (s16)arg2;
}

void func_808059A4_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unk24 = 0;
	temp_v0->unk25 = 0;
}

void func_808059CC_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unk24 = _subaddieaudioloop_entrypoint_3(sp1C->unk24);
}

//Grunty
void func_80805A00_chdiggerboss(Actor* arg0, s32 arg1)
{
	DiggerBossAdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	func_808027F4_chdiggerboss(arg0);
	func_80803BE8_chdiggerboss(arg0, arg1, 1);
	func_80802C0C_chdiggerboss(arg0);
	sp1C->unk25 = 1;
	sp1C->unk18 = 1.5f;
}

//Grunty
s32 func_80805A64_chdiggerboss(Actor* arg0) {
	Actor* temp_s2;
	s32 var_s0;
	s32 sp2C;
	DiggerBossAdditionalMem0* temp_s0;

	temp_s0 = actor_getAdditionalMem(arg0, 0U);
	temp_s2 = func_80802228_chdiggerboss(arg0);
	sp2C = 0;
	func_80802C40_chdiggerboss(arg0);
	if (func_800F6D24(character_getActiveIndex()) != 0)
	{
		return 0;
	}
	switch (temp_s0->unk25)
	{
	case 1:
		if (timer_reachedZero(&temp_s0->unk18) != 0)
		{
			temp_s0->unk25 = 2U;
		}
		break;
	case 2:
		sp2C = timer_reachedZero(&temp_s0->unk1C);
		temp_s2->rotation[1] += temp_s0->unk20 * time_getDelta();
		func_808064CC_chdiggerboss(arg0, !sp2C);
		func_80805B8C_chdiggerboss(arg0, temp_s0->unk20);
		if (sp2C != 0)
		{
			for (var_s0 = 0; var_s0 < 4; var_s0++)
			{
				func_80805448_chdiggerboss(temp_s2, var_s0, 0);
			}
			func_80802CB4_chdiggerboss(arg0);
		}
		break;
	}
	return sp2C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805B8C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805C1C_chdiggerboss.s")

//Grunty
void func_80805D64_chdiggerboss(Actor* arg0, s32 arg1) {
	DiggerBossAdditionalMem0* sp24;
	Actor* sp20;
	Actor* temp_v0;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	temp_v0 = func_80802228_chdiggerboss(arg0);
	sp20 = temp_v0;
	sp24->unk14 = 0.0f;
	sp24->unk18 = 1.5f;
	((f32*)temp_v0->actorData)[3] = 0.0f;
	sp24->unk28 = 1;
	func_808027F4_chdiggerboss(arg0);
	func_80802C0C_chdiggerboss(arg0);
	func_80803BE8_chdiggerboss(arg0, arg1, 1);
	func_80804A50_chdiggerboss(sp20, 2);
}

//Grunty
s32 func_80805DF4_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* temp_s0;
	f32 temp_f0;
	s32 sp2C;
	s32 sp78;
	s32 sp74;
	s32 sp70;
	f32 sp6C;
	s32 sp68;
	f32 sp64;
	f32 sp58[3];
	f32 sp4C[3];
	f32 sp40[3];
	f32 sp3C;
	Actor* temp_s1;
	f32 sp34;
	s32 pad;

	temp_s0 = actor_getAdditionalMem(arg0, 0U);
	temp_s1 = func_80802228_chdiggerboss(arg0);
	sp78 = 0;
	sp74 = 0;
	func_80802C40_chdiggerboss(arg0);
	if (func_800F6D24(character_getActiveIndex()) != 0)
	{
		return 0;
	}
	sp2C = timer_reachedZero_dupe(&temp_s0->unk14) != 0 && func_808042D8_chdiggerboss(temp_s1) == 2;
	switch (temp_s0->unk28) {
	case 1:
		if (timer_reachedZero(&temp_s0->unk18) != 0) {
			temp_s0->unk28 = 2;
		}
		break;
	case 2:
		sp70 = timer_reachedZero(&temp_s0->unk34);
		if (sp2C != 0)
		{
			((f32*)temp_s1->actorData)[3] = func_800F15F8(((f32*)temp_s1->actorData)[3], temp_s0->unk38, time_getDelta() * 300.0f);
			func_808063C8_chdiggerboss(arg0, 0, temp_s0->unk3C);
			func_8010B990(temp_s1, 5);
		}
		if (sp70 != 0)
		{
			temp_s0->unk28 = 3;
		}
		break;
	case 3:
		((f32*)temp_s1->actorData)[3] = func_800F15F8(((f32*)temp_s1->actorData)[3], 0.0f, time_getDelta() * 300.0f);
		func_808063C8_chdiggerboss(arg0, 0, temp_s0->unk3C);
		func_8010B990(temp_s1, 5);
		if (((f32*)temp_s1->actorData)[3] == 0.0f) {
			temp_s0->unk28 = 4;
			temp_s0->unk2C = 360.0f;
		}
		break;
	case 4:
		sp6C = time_getDelta() * temp_s0->unk20;
		temp_s0->unk2C -= mlAbsF(sp6C);
		temp_s1->rotation[1] += sp6C;
		func_80805B8C_chdiggerboss(arg0, temp_s0->unk20);
		if (temp_s0->unk2C < 0.0f)
		{
			temp_s0->unk28 = 5;
			temp_s0->unk34 = temp_s0->unk30;
		}
		else
		{
			sp74 = 1;
		}
		break;
	case 5:
		sp68 = timer_reachedZero(&temp_s0->unk34);
		if (sp2C != 0)
		{
			((f32*)temp_s1->actorData)[3] = func_800F15F8(((f32*)temp_s1->actorData)[3], temp_s0->unk38, time_getDelta() * 300.0f);
			func_808063C8_chdiggerboss(arg0, 0, temp_s0->unk3C);
			func_8010B990(temp_s1, 5);
		}
		if (sp68 != 0)
		{
			temp_s0->unk28 = 6;
		}
		break;
	case 6:
		((f32*)temp_s1->actorData)[3] = func_800F15F8(((f32*)temp_s1->actorData)[3], 0.0f, time_getDelta() * 300.0f);
		func_808063C8_chdiggerboss(arg0, 0, temp_s0->unk3C);
		func_8010B990(temp_s1, 5);
		if (((f32*)temp_s1->actorData)[3] == 0.0f)
		{
			temp_s0->unk28 = 7;
			temp_s0->unk2C = 360.0f;
		}
		break;
	case 7:
		sp64 = time_getDelta() * temp_s0->unk20;
		temp_s0->unk2C -= mlAbsF(sp64);
		temp_s1->rotation[1] += sp64;
		func_80805B8C_chdiggerboss(arg0, temp_s0->unk20);
		if (temp_s0->unk2C < 0.0f)
		{
			temp_s0->unk28 = 0;
			func_80802CB4_chdiggerboss(arg0);
			((f32*)temp_s1->actorData)[3] = 0;
			func_80804A50_chdiggerboss(temp_s1, 1);
			sp78 = 1;
		}
		else
		{
			sp74 = 1;
		}
		break;
	}
	func_808064CC_chdiggerboss(arg0, sp74);
	ml_vec3f_clear(sp58);
	sp58[1] = temp_s1->position[1];
	ml_vec3f_getVecFromYaw(sp4C, temp_s1->rotation[1], 1.0f);
	ml_vec3f_getVecFromYaw(sp40, func_800F1DF4(sp58, temp_s1->position), 1.0f);
	temp_f0 = ml_vec3f_dot_product(sp4C, sp40);
	if (temp_f0 > 0.0f)
	{
		sp3C = 1800.0f - (temp_f0 * 650.0f);
	}
	else
	{
		sp3C = 1800.0f - (temp_f0 * 250.0f);
	}
	if ((sp3C * sp3C) < func_800EFC7C(sp58, temp_s1->position))
	{
		sp34 = temp_s1->position[1];
		ml_vec3f_getVecFromYaw(temp_s1->position, func_800F1DF4(sp58, temp_s1->position), sp3C);
		temp_s1->position[1] = sp34;
	}
	return sp78;
}

void func_808062B8_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* sp1C;
	Actor* hag1;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	hag1 = func_80802228_chdiggerboss(arg0);
	sp1C->unk14 = 2.0f;
	((f32*)hag1->actorData)[3] = 0;
}

//Grunty
s32 func_80806300_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* sp2C;
	f32 sp28;
	f32 sp24;

	sp2C = actor_getAdditionalMem(arg0, 0U);
	sp24 = time_getDelta();
	if (sp2C->unk8 == 2)
	{
		return -1;
	}
	sp28 = ml_normalizeAngle_f(func_8010CD50(arg0, func_80802248_chdiggerboss(arg0)) - arg0->rotation[1]);
	sp2C->unk10 = func_800F1FF0(sp2C->unk10, sp28, 0.1f, sp24 * 4.0f, sp24 * 100.0f);
	return func_800F20BC(sp2C->unk10, sp28, 10.0f);
}

s32 func_808063C8_chdiggerboss(Actor* arg0, s32 arg1, f32 arg2) {
	f32 sp34;
	f32 sp30;
	f32 sp2C;
	f32 sp28;
	Actor* sp24;
	s32 sp20;
	sp28 = time_getDelta();
	sp24 = func_80802228_chdiggerboss(arg0);
	sp34 = func_8010CD50(arg0, func_80802248_chdiggerboss(arg0));
	sp30 = sp24->rotation[1];
	sp24->rotation[1] = func_800F1F38(sp30, sp34, sp28 * arg2);
	sp2C = func_800F1DCC(sp24->rotation[1], sp30);
	if (mlAbsF(func_800F1DCC(sp30, sp34)) > 20.0f)
	{
		func_80805B8C_chdiggerboss(arg0, sp2C);
	}
	sp20 = func_800F20BC(sp24->rotation[1], sp34, 10.0f);
	if (arg1 != 0)
	{
		func_808064CC_chdiggerboss(arg0, sp20 == 0);
	}
	return sp20;
}

void func_808064CC_chdiggerboss(Actor* arg0, s32 arg1)
{
	DiggerBossAdditionalMem0* sp24;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	sp24->unk24 = _subaddieaudioloop_entrypoint_7((s32)sp24->unk24, arg0->position, arg1, &D_8080A0EC_chdiggerboss, arg0->unk70_0);
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806528_chdiggerboss.s")

void func_80806648_chdiggerboss(Actor* arg0) {
	((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk78 = 0;
}

void func_8080666C_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unk78 = _subaddieaudioloop_entrypoint_3(sp1C->unk78);
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808066A0_chdiggerboss.s")

//Grunty
void func_80806A78_chdiggerboss(Actor* arg0, s32 arg1, u8* arg2) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	rare_memcpy(&temp_v0->unk68, arg2, 0x10);
	temp_v0->unk5E = 3;
	temp_v0->unk60 = 1.75f;
	temp_v0->unk5D = *arg2;
	func_80803BE8_chdiggerboss(arg0, arg1, 8);
	func_808027F4_chdiggerboss(arg0);
	if (character_getTransform(character_getActiveIndex()) == TRANSFORM_11_CLOCKWORK)
	{
		temp_v0->unk5C = 1;
		func_800F7B9C(character_getActiveIndex(), 0x8EU);
		return;
	}
	func_80806B38_chdiggerboss(arg0);
}

void func_80806B38_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* sp3C;
	f32 sp30[3];
	f32 sp24[3];
	s32 sp20;

	sp3C = actor_getAdditionalMem(arg0, 0U);
	if ((sp3C->unk5F != 0) || (sp3C->unk4 != 0))
	{
		sp3C->unk5C = 3;
		sp3C->unk60 = 0.15f;
		return;
	}
	sp20 = func_80802248_chdiggerboss(arg0);
	sp3C->unk5C = 3;
	sp3C->unk60 = 1.75f;
	character_getCoords(sp20, sp30);
	ml_vec3f_assign_value(sp24, 0.0f, func_800F1DF4(sp30, arg0->position), 0.0f);
	func_800F8444(sp20, sp24);
	func_800F7C58(sp20, 0x61, 1);
}

void func_80806C08_chdiggerboss(Actor* arg0) {
	s32 pad;
	s32 temp_a0;
	DiggerBossAdditionalMem0* temp_s0;

	temp_s0 = actor_getAdditionalMem(arg0, 0U);
	temp_a0 = func_80802248_chdiggerboss(arg0);
	if (temp_s0->unk4 != 0) {
		temp_s0->unk5C = 0xB;
		temp_s0->unk60 = 0.15f;
		return;
	}
	func_800F7B9C(temp_a0, 0x63U);
	func_800F7C58(temp_a0, 0x61, 2);
	func_80802878_chdiggerboss(arg0, 5, 1);
	temp_s0->unk5C = 0xB;
	temp_s0->unk60 = 1.0f;
}

void func_80806CA4_chdiggerboss(Actor* arg0, s32 arg1)
{
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	switch (temp_v0->unk5C)
	{
	case 1:
		temp_v0->unk5C = 2U;
		return;
	case 9:
		temp_v0->unk5C = 0xAU;
		return;
	}
}

//Grunty
void func_80806CF8_chdiggerboss(Actor* arg0, s32 arg1) {
	DiggerBossAdditionalMem0* sp1C;
	Actor* sp18;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	if (arg1 == 0)
	{
		sp18 = func_801084B0(0x4F2, &arg0);
		_subaddieskeleton_entrypoint_0(arg0, 0x1E, sp18->position);
		sp1C->unk64 = sp18->unk0;
		sp1C->unk5C = 5;
		if (sp1C->unk5E > 0)
		{
			sp1C->unk5E--;
		}
		func_80800180_chdiggerboss(arg0, 7);
	}
}

Actor* func_80806D84_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	if (temp_v0->unk64 != NULL) {
		return func_80106790(temp_v0->unk64);
	}
	return NULL;
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806DC4_chdiggerboss.s")

void func_80806EE4_chdiggerboss(Actor* arg0, s32 arg1) {
	((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk5F = (s8)arg1;
}

u8 func_80806F10_chdiggerboss(Actor* arg0, u8 arg1)
{

	if (arg1 == 0)
	{
		arg1 = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
	}
	func_800C4B7C(D_8080A11C_chdiggerboss[rand_iBounded(0, 2)]);
	func_800C4350(arg1, arg0->position, &D_8080A104_chdiggerboss);
	return arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806F8C_chdiggerboss.s")

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808070B0_chdiggerboss.s")

//Grunty
void func_80807280_chdiggerboss(Actor* arg0, s32 arg1, s16* arg2) {
	DiggerBossAdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	rare_memcpy(&sp1C->unk88, arg2, 0x10);
	func_808027F4_chdiggerboss(arg0);
	func_80802C0C_chdiggerboss(arg0);
	func_80803BE8_chdiggerboss(arg0, arg1, 1);
	sp1C->unk7C = 1;
	sp1C->unk84 = 1.5f;
	sp1C->unk7E = arg2[0];
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807304_chdiggerboss.s")

s32 func_8080761C_chdiggerboss(Actor* arg0) {
	return ((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unk80;
}

void func_80807640_chdiggerboss(Actor* arg0) {
	((Hag1AdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unkA0 = 0;
}

void func_80807664_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* sp1C;
	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unkA0 = _subaddieaudioloop_entrypoint_3(sp1C->unkA0);
}

//Grunty
void func_80807698_chdiggerboss(Actor* arg0, s32 arg1)
{
	Actor* temp_s4;
	s32 var_s0;
	s32 var_v0;
	s32 temp;
	DiggerBossAdditionalMem0* temp_s3;

	temp_s3 = actor_getAdditionalMem(arg0, 0U);
	temp_s4 = func_80802228_chdiggerboss(arg0);
	if (arg1 != 0)
	{
		temp = 1;
	}
	else
	{
		if (temp_s3->unkA3 != 0)
		{
			var_v0 = 1;
		}
		else
		{
			var_v0 = 0;
		}
		temp = var_v0;
	}
	for (var_s0 = 0; var_s0 < 4; var_s0++)
	{
		if (temp_s3->unkA2 & (1 << var_s0))
		{
			func_80805448_chdiggerboss(temp_s4, var_s0, temp);
		}
	}
}

//Grunty
void func_80807754_chdiggerboss(Actor* arg0, s32 arg1, f32 arg2) {
	Actor* temp_s2;
	s32 var_s0;
	DiggerBossAdditionalMem0* temp_s1;

	temp_s1 = actor_getAdditionalMem(arg0, 0U);
	temp_s2 = func_80802228_chdiggerboss(arg0);
	var_s0 = 0;
	temp_s1->unk98 = arg2;
	temp_s1->unk9C = 2.0f;
	temp_s1->unkA3 = 1;
	temp_s1->unkA2 = 0U;
	for (var_s0 = 0; var_s0 < 4; var_s0++)
	{
		if (func_80805798_chdiggerboss(temp_s2, var_s0) != 0)
		{
			temp_s1->unkA2 |= (1 << var_s0);
		}
	}
	func_808027F4_chdiggerboss(arg0);
	func_80803BE8_chdiggerboss(arg0, arg1, 1);
	func_808041E4_chdiggerboss(func_80802228_chdiggerboss(arg0), 3);
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080783C_chdiggerboss.s")

void func_80807B18_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unkA4 = 0;
	temp_v0->unkC8 = 0;
	temp_v0->unkA6 = 0;
	temp_v0->unkA7 = 4;
}

void func_80807B4C_chdiggerboss(Actor* arg0) 
{
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807B54_chdiggerboss.s")

//grunty
void func_80807DC0_chdiggerboss(Actor* arg0, s32 arg1) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unkA5 = 1;
	temp_v0->unkA6 = (s8)arg1;
}

void func_80807DF4_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* temp_v0;
	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unkA5 = 0;
	if ((temp_v0->unkA4 != 1) && (temp_v0->unkA4 != 2) && (temp_v0->unkA4 != 3)) {
		temp_v0->unkA4 = 4U;
	}
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807E3C_chdiggerboss.s")

void func_80807FD8_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unkA8 = 0;
	temp_v0->unkA6 = 0;
}

void func_80808000_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unkA6 = _subaddieaudioloop_entrypoint_3(sp1C->unkA6);
}

//Hag-1
void func_80808034_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* sp24;
	s32 sp20;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	sp20 = 0;
	if (sp24->unkA4 == 1) {
		sp20 = 1;
		if (func_8001210C(1) != 0) {
			func_808081AC_chdiggerboss(arg0);
		}
	}
	sp24->unkA6 = _subaddieaudioloop_entrypoint_7((s32)sp24->unkA6, arg0->position, sp20, &D_8080A160_chdiggerboss, arg0->unk70_0);
}
//Hag-1
void func_808080C0_chdiggerboss(Actor* arg0, s32 arg1)
{
	Hag1AdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unkA4 = arg1;
	switch (arg1)
	{
		case 0:
			if (sp1C->unkA8 != NULL)
			{
				sp1C = sp1C;
				func_8010114C(sp1C->unkA8, 0x4F, 0);
				sp1C->unkA8 = NULL;
				return;
			}
		case 1:
			return;
		case 2:
			if (sp1C->unkA8 == NULL)
			{
				func_80108B04(arg0, 3U);
			}
			break;
	}
}
void func_8080815C_chdiggerboss(Actor* arg0, s32 arg1) {
	Hag1AdditionalMem0* sp1C;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	if (arg1 == 3) {
		sp1C->unkA8 = (s32)func_801084B0(0x178, &arg0)->unk0;
	}
}

void func_808081AC_chdiggerboss(Actor* arg0) {
	f32 sp34[3];
	f32 sp28[3];

	ml_vec3f_copy(sp28, arg0->position);
	ml_translateAngleDist(sp28, arg0->rotation[1], -80.0f);
	sp28[1] += 80.0f;
	ml_vec3f_copy(sp34, sp28);
	ml_translateAngleDist(sp34, arg0->rotation[1] + 90.0f, 200.0f);
	func_800BBCB8(sp34, arg0->position, 1.0f, 1, &D_8080A16C_chdiggerboss);
}
//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808258_chdiggerboss.s")

void func_8080843C_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* sp1C;
	sp1C = actor_getAdditionalMem(arg0, 0U);
	sp1C->unk78 = _subaddieaudioloop_entrypoint_3(sp1C->unk78);
}

//Grunty
void func_80808470_chdiggerboss(Actor* arg0, s32 arg1) {
	DiggerBossAdditionalMem0* temp_s1;
	s32 sp40;
	f32 sp34[3];
	f32 sp28[3];

	temp_s1 = actor_getAdditionalMem(arg0, 0U);
	sp40 = func_80802248_chdiggerboss(arg0);
	temp_s1->unk3 = 1;
	temp_s1->unkD8 = 0;
	func_80803BE8_chdiggerboss(arg0, arg1, 8);
	character_getCoords(sp40, sp34);
	ml_vec3f_assign_value(sp28, 0.0f, func_800F1DF4(sp34, arg0->position), 0.0f);
	func_800F8444(sp40, sp28);
	if (func_808021E8_chdiggerboss(arg0, 0xB) == 0)
	{
		func_80802878_chdiggerboss(arg0, 3, 1);
		func_80803660_chdiggerboss(arg0, 0x172D, 0x10E);
		temp_s1->unkCC = 1;
		return;
	}
	func_80109FE8(arg0, 1);
	temp_s1->unkCC = 1;
}

//Grunty
void func_80808560_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* sp24;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	func_80102FDC(func_808086A8_chdiggerboss(arg0), 0.8f);
	func_80800180_chdiggerboss(arg0, 0xB);
	func_808027F4_chdiggerboss(arg0);
	func_80109FE8(arg0, 1);
	sp24->unkCC = 4;
	sp24->unkD0 = 0.5f;
}

//Grunty
void func_808085E0_chdiggerboss(Actor* arg0, s32 arg1)
{
	DiggerBossAdditionalMem0* temp_s0;
	Actor* sp20;

	temp_s0 = actor_getAdditionalMem(arg0, 0U);
	if (arg1 == 5) 
	{
		sp20 = func_801084B0(0x4F6, &arg0);
		temp_s0->unkD4 = sp20->unk0;
		func_808087F0_chdiggerboss(arg0);
		if (func_80802170_chdiggerboss(arg0, 0xB) == 0) 
		{
			func_80102FDC(sp20, 0.1f);
			func_80800180_chdiggerboss(arg0, 0xA);
			temp_s0->unkCC = 2;
			return;
		}
		func_80102FDC(sp20, 0.8f);
		func_80800180_chdiggerboss(arg0, 0xB);
		temp_s0->unkCC = 4;
		temp_s0->unkD0 = 0.5f;
	}
}

Actor* func_808086A8_chdiggerboss(Actor* arg0) {
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	if (temp_v0->unkD4 != NULL) {
		return func_80106790(temp_v0->unkD4);
	}
	return NULL;
}

//Grunty
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808086E8_chdiggerboss.s")

void func_808087F0_chdiggerboss(Actor* arg0) 
{
	DiggerBossAdditionalMem0* sp44;
	Actor* sp40;
	f32 sp34[3];
	f32 sp28[3];
	f32 sp24;

	sp44 = actor_getAdditionalMem(arg0, 0U);
	sp40 = func_808086A8_chdiggerboss(arg0);
	if (sp40 != NULL) 
	{
		if (_subaddieskeleton_entrypoint_0(arg0, 0x10, &sp34) != 0)
		{
			sp24 = arg0->rotation[1] + sp44->unk10;
			_subaddieskeleton_entrypoint_0(arg0, 0x1E, &sp28);
			func_800EFE50(sp40->position, sp34, sp28, 0.5f);
			ml_translateAngleDist(sp40->position, sp24, 80.0f);
			sp40->position[1] += 80.0f;
		}
	}
}

void func_808088AC_chdiggerboss(Actor* arg0)
{
    func_80808B40_chdiggerboss(arg0,1);
}

//Hag-1
void func_808088CC_chdiggerboss(Actor* arg0)
{
	s32 var_s0;
	Hag1AdditionalMem0* hag1Mem;

	var_s0 = 0;
	hag1Mem = actor_getAdditionalMem(arg0, 0U);
	for (var_s0 = 0; var_s0 < 4; var_s0++)
	{
		if (hag1Mem->unkB0[var_s0] != NULL)
		{
			func_80808BE4_chdiggerboss(arg0, func_80106790(hag1Mem->unkB0[var_s0]), var_s0);
		}
	}
}

//Hag-1
void func_80808948_chdiggerboss(Actor* arg0) {
	Unk80132ED0* temp_a0;
	s32 var_s0;
	Hag1AdditionalMem0* hag1Mem;

	hag1Mem = actor_getAdditionalMem(arg0, 0U);
	for (var_s0 = 0; var_s0 < 4; var_s0++)
	{
		if (hag1Mem->unkB0[var_s0] != NULL)
		{
			if (func_801069A4(hag1Mem->unkB0[var_s0]) != 0)
			{
				func_800FFA88(hag1Mem->unkB0[var_s0]);
			}
			hag1Mem->unkB0[var_s0] = NULL;
		}
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808089BC_chdiggerboss.s")

void func_80808B40_chdiggerboss(Actor* arg0, s32 arg1)
{
	Unk80132ED0* temp_a0;
	s32 var_s1;
	Hag1AdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	if (arg1 != temp_v0->unkAC)
	{
		temp_v0->unkAC = arg1;
		if (temp_v0->unkAC != 0)
		{
			if (temp_v0->unkB0[0] == 0)
			{
				func_80108B04(arg0, 6U);
			}
		}
		else
		{
			for (var_s1 = 0; var_s1 < 4; var_s1++)
			{
				temp_a0 = temp_v0->unkB0[var_s1];
				if (temp_a0 != NULL)
				{
					func_800FFA88(temp_a0);
					temp_v0->unkB0[var_s1] = NULL;
				}
			}
		}
	}
}

void func_80808BE4_chdiggerboss(Actor* arg0, Actor* arg1, s32 arg2)
{
	func_800EEC30(arg1->position, D_8080A1BC_chdiggerboss[arg2], arg0->rotation[1] + D_8080A1AC_chdiggerboss[arg2], D_8080A1CC_chdiggerboss[arg2]);
	ml_vec3f_add(arg1->position, arg0->position);
	func_80103014(arg1);
}

//Hag-1
void func_80808C64_chdiggerboss(Actor* arg0)
{
	Hag1AdditionalMem0* sp1C;
	s32 var_v1;

	sp1C = actor_getAdditionalMem(arg0, 0U);
	for (var_v1 = 0; var_v1 < 2; var_v1++)
	{
		sp1C->unkC0[var_v1] = 0.0f;
	}
	ml_vec3f_copy(sp1C->unkD4, arg0->position);
	sp1C->unkE0 = (f32)arg0->rotation[1];
}

//Hag-1
void func_80808CD0_chdiggerboss(Actor* arg0) {
	Hag1AdditionalMem0* sp24;

	sp24 = actor_getAdditionalMem(arg0, 0U);
	func_80808D54_chdiggerboss(arg0, 0, -1.0f, &D_8080A1E8_chdiggerboss);
	func_80808D54_chdiggerboss(arg0, 1, 1.0f, &D_8080A1DC_chdiggerboss);
	func_80808F44_chdiggerboss(arg0);
	ml_vec3f_copy(sp24->unkD4, arg0->position);
	sp24->unkE0 = (f32)arg0->rotation[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808D54_chdiggerboss.s")

void func_80808F44_chdiggerboss(Actor* arg0) {
	s32 temp_v0;

	temp_v0 = func_801065A4();
	if (temp_v0 != 0)
	{
		_glid_entrypoint_0(temp_v0, 1, _chdiggerboss_entrypoint_3, arg0->unk0);
		_glid_entrypoint_0(temp_v0, 2, _chdiggerboss_entrypoint_3, arg0->unk0);
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/chdiggerboss_entrypoint_3.s")

void func_80809078_chdiggerboss(Actor* arg0, s32 arg1, s32 arg2)
{
	DiggerBossAdditionalMem0* temp_s1;
	s32 index = 0;
	temp_s1 = actor_getAdditionalMem(arg0, 0U);
	for (index = 0; index < 3; index++)
	{
		func_800E0AFC((Unkfunc_800E0960_1*)arg1, D_8080A1F4_chdiggerboss[index], 1.0f, temp_s1->unkC0, 0.0f, 0.0f);
	}
	for (index = 0; index < 3; index++)
	{
		func_800E0AFC((Unkfunc_800E0960_1*)arg1, D_8080A1FC_chdiggerboss[index], 1.0f, temp_s1->unkC4, 0.0f, 0.0f);
	}
}

void func_80809150_chdiggerboss(Actor* arg0)
{
	Actor* sp24;
	DiggerBossAdditionalMem0* temp_s0;

	sp24 = func_80802228_chdiggerboss(arg0);
	temp_s0 = actor_getAdditionalMem(arg0, 0U);
	func_80808B40_chdiggerboss(sp24, 0);
	func_80803BE8_chdiggerboss(arg0, 0x43, 1);
	flag_setValueTrue(FLAG_043_PROGRESS_DEFEATED_HAG_1);
	_gcfrontend_entrypoint_9(0x83);
	func_800FDC28(0x16U);
	temp_s0->unkDC = -1;
	temp_s0->unkE4 = 0;
	temp_s0->unkE8 = 0;
	temp_s0->unkEC = 0;
	temp_s0->unkF0 = 0;
	temp_s0->unkF4 = 0;
	func_80809234_chdiggerboss(arg0);
}

s32 func_808091E4_chdiggerboss(Actor* arg0)
{
	if ((timer_reachedZero(&((DiggerBossAdditionalMem0*)actor_getAdditionalMem(arg0, 0U))->unkE0) != 0) && (func_80809234_chdiggerboss(arg0) == 0))
	{
		return 0;
	}
	return 1;
}

s32 func_80809234_chdiggerboss(Actor* arg0)
{
	DiggerBossAdditionalMem0* temp_v0;

	temp_v0 = actor_getAdditionalMem(arg0, 0U);
	temp_v0->unkDC++;
	if (temp_v0->unkDC >= 5U)
	{
		func_800FC74C(D_8080A1FE_chdiggerboss[temp_v0->unkDC][0]);
		temp_v0->unkE4 = 0;
		return 0;
	}
	temp_v0->unkE0 = D_8080A208_chdiggerboss[temp_v0->unkDC][0];
	_chexploder_entrypoint_5(arg0, 0x91C, arg0->position, arg0->rotation[1], 1.0f, 7);
	if (temp_v0->unkDC != 0)
	{
		func_800FC74C(D_8080A1FE_chdiggerboss[temp_v0->unkDC][0]);
	}
	func_800FC6B0(D_8080A206_chdiggerboss[temp_v0->unkDC][0]);
	return 1;
}

void func_80809310_chdiggerboss(Actor* arg0)
{
	Actor* temp_s0;
	DiggerBossAdditionalMem0* sp20;
	Actor* temp_v0_2;
	Unk80132ED0* temp_a0;

	temp_s0 = func_80106790(func_80101080());
	sp20 = actor_getAdditionalMem(arg0, 0U);
	func_80802938_chdiggerboss(arg0, (s32)temp_s0->unk0, D_8080A204_chdiggerboss[sp20->unkDC][0], 0x28);
	_chexploder_entrypoint_6(temp_s0, 1000.0f, 1200.0f);
	_chexploder_entrypoint_12(temp_s0, 0xFA);
	_chexploder_entrypoint_11(temp_s0, &D_8080A240_chdiggerboss);
	func_808093F8_chdiggerboss(arg0);
	temp_a0 = sp20->unkE4;
	if (temp_a0 != NULL) {
		func_800FFA88(temp_a0);
	}
	sp20->unkE4 = temp_s0->unk0;
	if (arg0->unk3C != NULL) {
		temp_v0_2 = func_80802228_chdiggerboss(arg0);
		temp_v0_2->unk3C = NULL;
		arg0->unk3C = NULL;
		actor_mark_delete(temp_v0_2);
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808093F8_chdiggerboss.s")
