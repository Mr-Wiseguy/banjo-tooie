#include "ch/jadestatue.h"

extern ActorData D_80800310_chjadestatue;
extern ActorData D_80800358_chjadestatue;

void func_808001C0_chjadestatue(Actor*);

ActorData* chjadestatue_entrypoint_0()
{
    return &D_80800310_chjadestatue;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_8080000C_chjadestatue.s")

void func_80800098_chjadestatue(Actor* arg0) {
	arg0->rotation[1] -= time_getDelta() * 120.0f;
	func_80103110(arg0, 0U);
	if (arg0->unk64_20)
	{
		func_808001C0_chjadestatue(arg0);
		func_800FFA88(arg0->unk0);
	}
}

void func_80800104_chjadestatue(Actor* arg0, void* arg1)
{
	func_80101870(arg0, arg1);
	if (arg0->unk7C_12) {
		func_80103110(arg0, 1U);
	}
}

s32 func_80800140_chjadestatue(Actor* arg0, s32 arg1, s32 arg2)
{
	switch (arg1)
	{

		case EVENT_95_ACTOR_SPAWNED:
			func_80109EEC(arg0, 0x44);
			break;
		case EVENT_3E_ACTOR_TOUCHED:
			arg0->unk64_20 = 1;
			_subaddieDll_entrypoint_4(arg0, 1U);
			break;

		case 0x2C:
			actor_mark_delete(arg0);
			return 1;
		default:
			return 0;
	}
	return 1;
}

void func_808001C0_chjadestatue(Actor* arg0)
{
	s32 temp_v0;
	_fxsparkle_entrypoint_1(arg0->position, 0xCU);
	collectable_collectItem((arg0->unk74_7) - 0x32, 5U);
	temp_v0 = func_800D035C(5);
	func_800D24E8(0xEE, temp_v0, 0);
	func_800FC63C(0xEU, 0x3E80U);
	switch (temp_v0)
	{
	case 10:
		event_sendToActorsOfType(0x2B4, 7, 0);
		return;
	case 20:
		event_sendToActorsOfType(0x2B4, 7, 1);
		return;
	}
}

void func_8080026C_chjadestatue(Actor* arg0)
{
	if (func_800D035C(5) >= 0x14)
	{
		actor_mark_delete(arg0);
	}
}

void func_808002A4_chjadestatue(Actor* arg0)
{
	s32 sp1C;
	s32 temp_v0;

	temp_v0 = func_800D035C(5);
	sp1C = temp_v0;
	func_800D24E8(0xEE, temp_v0, 0);
	if (sp1C >= 0x14)
	{
		event_sendToActorsOfType(PROP_2B3_JADETOTEM, 0x2C, 0);
		actor_mark_delete(arg0);
	}
}

ActorData* chjadestatue_entrypoint_1()
{
    return &D_80800358_chjadestatue;
}
