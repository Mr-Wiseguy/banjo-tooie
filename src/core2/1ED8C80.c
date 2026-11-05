#include "core2/1ED8C80.h"

extern s32 D_80135A50;

void func_800FF390(void)
{
	D_80135A50 = 0;
	//Create New Actor Vector
	actorList_new();
	//Create new freelist (func_8008B4F4(), 0x20)
	func_80104170();
	//Create new freelist (0x2C,8)
	func_80104350();
	//Create new freelist (0x48,8)
	func_80105410();
	//Create new freelist (0x8,0)
	func_80105C20();
	//Nothing
	func_80106A20();
	//Create new freelist (0x18,0xC)
	func_80106DF0();
	func_80107BB0();
}

void func_800FF3EC(Actor* actor)
{
	ActorData* temp_v0;

	if (!(actor->unk64_26))
	{
		temp_v0 = actor_getActorData(actor);
		if (temp_v0->unk28_func != NULL)
		{
			temp_v0->unk28_func(actor);
		}
		actor->unk64_26 = 1;
	}
}

void func_800FF44C(void)
{
	s32 actorIterator;
	Actor* actor;

	func_80101238(0x93, 0);
	actor = actorList_getLast(&actorIterator);
	while (actor != NULL)
	{
		func_800FF3EC(actor);
		actor = actorList_getNext(&actorIterator);
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF564.s")

void func_800FF62C(void)
{
	Actor* actor;
	ActorData* temp_v0;
	s32 actorIterator;
	f32 sp40[3];
	s32 pad;
	Unk80132ED0* temp_s1;
	s32 var_s3;

	if (func_800BEC1C() != 0)
	{
		var_s3 = 1;
	}
	else
	{
		var_s3 = 0;
		if (1) {}
	}
	func_8010D1E8();
	if (func_800DB9B0() != 0)
	{
		func_800E3980(sp40);
	}
	else
	{
		func_8010D254(sp40);
	}

	actor = actorList_getLast(&actorIterator);
	//Loop through all actors
	while (actor != NULL)
	{
		temp_s1 = actor->unk0;
		if (!(actor->unk64_17))
		{
			if (actor->unk74_4)
			{
				if (func_8010038C(actor, sp40) != 0)
				{
					actor_getActorData(actor)->unk10_func(actor);
				}
			}
			else
			{
				func_80100120(actor);
				if (func_8010038C(actor, sp40) != 0)
				{
					temp_v0 = actor_getActorData(actor);
					//If there is an update function for the actor call it
					if (temp_v0->update_func != NULL)
					{
						temp_v0->update_func(actor);
					}
				}
			}
			if ((actor->unk8C != 0) && (actor->unk74_27))
			{
				//Animate Actors
				func_8008ADE4(func_80104248(actor));
			}
			if (actor->unk90 != 0)
			{
				func_801061D8(actor);
			}
			if (actor->unk79_0)
			{
				_subaddiefade_entrypoint_7(actor);
			}
			if (actor->unk94_20 != 0)
			{
				func_80106F70(actor);
			}
			if (actor->unk8E != 0)
			{
				func_80104780(actor);
			}
			if (actor->unk7A_3)
			{
				_chbounce_entrypoint_8(actor);
				func_80103014(actor);
				if (var_s3 != 0)
				{
					_subaddiezone_entrypoint_0(actor);
				}
			}
			else if (!(actor->unk74_5))
			{
				func_80103014(actor);
				if (var_s3 != 0)
				{
					_subaddiezone_entrypoint_0(actor);
				}
			}
			else
			{
				temp_s1->unk28_23 = ml_normalizeAngle_f(actor->rotation[1]);
				temp_s1->unk24_7 = ml_normalizeAngle_f(actor->rotation[0]);
				temp_s1->unk28_14 = ml_normalizeAngle_f(actor->rotation[2]);
			}
			func_80103040(actor);
		}
		actor = actorList_getNext(&actorIterator);

	}
	func_8010DF3C();
}

void func_800FFA3C(Actor* actor)
{
	Unk80132ED0* sp1C;

	sp1C = actor->unk0;
	func_800FF3EC(actor);
	func_800FF4A4(actor);
	actorList_erase(sp1C->unk18_5);
	func_800EBFF4(sp1C);
}


void func_800FFA88(Unk80132ED0* a0)
{
    actor_mark_delete(func_80106790(a0));
}

void actor_mark_delete(Actor* actor)
{
	Actor* temp_v0;
	Unk80132ED0* temp_a2;
	actor->unk64_17 = 1;
	D_80135A50++;
	temp_a2 = actor->unk40;
	if (temp_a2 != 0 && actor->unk6C_9 != 0x243)
	{
		temp_v0 = func_80106790((Unk80132ED0*)actor->unk40);
		temp_v0->unk64_17 = 1;
		actor->unk40 = 0;
		temp_v0->unk40 = 0;
		D_80135A50++;
	}
	actor->unk7A_2 = 0;
	actor->unk74_24 = actor->unk7A_2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFB74.s")

void func_800FFBE4(void) {
}

void func_800FFBEC()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC14()
{
    func_800FFC3C();
    func_8010DEFC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFDBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFECC.s")

u32* func_80100074(Actor* a0, u32 a1, u32 a2)
{
    return func_800FFECC(a0,a1,a2);
}

void* actor_getAdditionalMem(Actor* actor, u32 arg1)
{

    if (actor->unk82[arg1] != 0)
    {
        return func_8001B798(actor->unk82[arg1]);
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801000D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_80100120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801001D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_80100230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801002C0.s")

ActorData* actor_getActorData(Actor* arg0)
{
    return (*arg0->pointerToSyscallEntry)();
}

int func_8010038C(Actor* actor, f32* arg1)
{

	if (!actor->unk7C_15)
	{
		actor->unk7C_15 = 1;
		event_sendToActor(actor, EVENT_95_ACTOR_SPAWNED, 0);
		if (actor->unk64_17)
		{
			return 0;
		}
		if (actor->unk7A_5)
		{
			func_80081D34(actor->pointerToSyscallEntry);
		}
	}
	if (!(actor->unk7C_14))
	{
		return 0;
	}
	if (!actor->unk7C)
	{
		return 1;
	}
	if ((actor->unk7C_13) && (actor->unk7C_12))
	{
		return 1;
	}
	return position_isWithinRangeOf(actor->position, (s32)actor->unk7C, arg1);
}
