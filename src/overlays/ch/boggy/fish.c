#include "ch/boggy/fish.h"

#define BOGGYFISH_DATA(arg0) ((BoggyFishActorData*)(arg0->actorData))

typedef struct {
	u16 pad0[0x12];
	u32 unk24;
} unkStructBoggyFish;

void func_8080018C_chboggyfish(Actor*);
s32 func_80800064_chboggyfish(Actor*, s32, s32);
void func_80800000_chboggyfish(Actor*, unkStructBoggyFish*);
s32 D_80800210_chboggyfish[4] = { 0,0,0x3F99999A,0x04440049 };
ActorData D_80800220_chboggyfish =
{
	/*0x0*/ 0x037A,
	/*0x2*/ PROP_4BA_BOGGYFISH,
	/*0x4*/ 0x08FA,
	/*0x6*/ 0x0001,
	/*0x8*/ D_80800210_chboggyfish,
	/*0xC*/ func_8080018C_chboggyfish,
	/*0x10*/ func_80105834,
	/*0x14*/ func_801018A4,
	/*0x18*/ 0x0000,
	/*0x1A*/ 0x0000,
	/*0x1C*/ 0.0f,
	/*0x20*/ 0x0000,
	/*0x22*/ 0x0000,
	/*0x24*/ 0x0000,
	/*0x26*/ 0x0000,
	/*0x28*/ 0x00000000,
	/*0x2C*/ func_80108ED0,
	/*0x30*/ 0x0000,
	/*0x32*/ 0x0014,
	/*0x34*/ 0x00000000,
	/*0x38*/ func_80107C2C,
	/*0x3C*/ 0x8040,
	/*0x3E*/ 0x5404,
	/*0x40*/ func_80800064_chboggyfish,
	/*0x44*/ 0x0000,
	/*0x46*/ 0x0000
};



void func_80800000_chboggyfish(Actor* arg0, unkStructBoggyFish* arg1)
{
	if ((arg1->unk24 >> 0x16) == 0)
	{
		func_800F6388(character_getActiveIndex(), 0x4BA);
		inventory_incrementValue(0x51);
		func_800FC6B0(0xEU);
		flag_setValueTrue(FLAG_438_UNK);
		func_800FFA88(arg0->unk0);
	}
}

s32 func_80800064_chboggyfish(Actor* arg0, s32 arg1, s32 arg2)
{
	u8 temp_v0;
	s32 temp_f6;

	switch (arg1)
	{
		case EVENT_3E_ACTOR_TOUCHED:
			func_80800000_chboggyfish(arg0, (unkStructBoggyFish*)arg2);
			break;
			//On Screen
		case EVENT_1F_ACTOR_ONSCREEN:
			func_801015D0(arg0);
			temp_v0 = func_800D731C(arg0->unk0->unk14);
			if (temp_v0 != 0)
			{
				temp_f6 = BOGGYFISH_DATA(arg0)->unk10;
				func_800DBE60(temp_v0, 0, temp_f6);
				func_800DBE60(temp_v0, 1, temp_f6);
				func_800DBE60(temp_v0, 2, temp_f6);
				func_800DBE60(temp_v0, 3, temp_f6);
			}
			break;
			//Start
		case EVENT_95_ACTOR_SPAWNED:
			if ((flag_getValue(FLAG_438_UNK) != 0) && (_glcutDll_entrypoint_20() == 0))
			{
				actor_mark_delete(arg0);
				return 0;
			}
			BOGGYFISH_DATA(arg0)->unk10 = 0;
			BOGGYFISH_DATA(arg0)->unk14 = 0.5f;
			break;
		default:
			return 0;
	}
	if (arg2)
	{
	}
	return 1;
}

void func_8080018C_chboggyfish(Actor* arg0)
{
	BOGGYFISH_DATA(arg0)->unk10 = (BOGGYFISH_DATA(arg0)->unk10 + BOGGYFISH_DATA(arg0)->unk14);
	if (BOGGYFISH_DATA(arg0)->unk10 <= 0.0f)
	{
		BOGGYFISH_DATA(arg0)->unk10 = 0.0f;
		BOGGYFISH_DATA(arg0)->unk14 = (0.0f - BOGGYFISH_DATA(arg0)->unk14);
	}
	if (BOGGYFISH_DATA(arg0)->unk10 >= 4.0f)
	{
		BOGGYFISH_DATA(arg0)->unk10 = 4.0f;
		BOGGYFISH_DATA(arg0)->unk14 = (f32)(0.0f - BOGGYFISH_DATA(arg0)->unk14);
	}
}

ActorData* chboggyfish_entrypoint_0()
{
    return &D_80800220_chboggyfish;
}
