#include "ch/shockjump.h"

extern ActorData D_808002B0_chshockjump;
extern s32 D_80800340_chshockjump;

ActorData* chshockjump_entrypoint_0() //Shock Spring Pad
{
    return &D_808002B0_chshockjump;
}
extern ActorData D_808002F8_chshockjump;
ActorData* chshockjump_entrypoint_1() //Flight Pad
{
    return &D_808002F8_chshockjump;
}
s32 func_80800018_chshockjump(s32 arg0, s32 arg1, s32 arg2)
{
	Actor* temp_v0;

	switch (arg1)
	{
	case 0x90:
		temp_v0 = func_80106790(func_80101080());
		_chexploder_entrypoint_6(temp_v0, 400.0f, 600.0f);
		_chexploder_entrypoint_7(temp_v0, -600.0f, -400.0f);
		break;
	case EVENT_91_ACTOR_STOOD_ON:
		func_800F7B9C(arg2, 0x49U);
		break;
	default:
		return 0;
	}
	return 1;
}

s32 func_808000AC_chshockjump(s32 arg0, s32 arg1, s32 arg2)
{
	switch (arg1)
	{
	case EVENT_91_ACTOR_STOOD_ON:
		func_800F7B9C(arg2, 0x4AU);
		break;
	default:
		return 0;
	}
	return 1;
}

void chshockjump_entrypoint_2(Unk80132ED0* arg0)
{
	Actor* temp_v0;

	temp_v0 = func_80106790(arg0);
	_chexploder_entrypoint_5(temp_v0, 0x756, temp_v0->position, temp_v0->rotation[1], temp_v0->scale, 0xC);
	_subaddieaudioquick_entrypoint_2(temp_v0, temp_v0->position, &D_80800340_chshockjump);
}

void func_80800148_chshockjump(Actor* arg0, void* arg1)
{
	AbilityId var_a0;
	s32 sp18;
	s32 var_a1;

	sp18 = _subaddiefade_entrypoint_0(arg0);
	if (arg0->unk6C_9 == PROP_210_SHOCK_SPRING_PAD)
	{
		var_a0 = ABILITY_0D_BK_SHOCK_SPRING_JUMP;
	}
	else
	{
		var_a0 = ABILITY_09_BK_FLYING;
	}
	if ((ability_getValue(var_a0) != 0) && (character_includedInTransformMask(character_getActiveIndex(), ALLOW_BK | ALLOW_KAZOOIE) != 0))
	{
		var_a1 = (s32)func_800F15F8((f32)sp18, 255.0f, 5.0f);
	}
	else
	{
		var_a1 = (s32)func_800F15F8((f32)sp18, 90.0f, 5.0f);
	}
	_subaddiefade_entrypoint_8(arg0, var_a1);
	func_80101870(arg0, arg1);
}

void func_80800228_chshockjump(Actor* arg0)
{
	u32 temp_v0;
	temp_v0 = _subaddiesect_entrypoint_1(arg0);
	arg0->actorData[4] = temp_v0;
	if (temp_v0 == -1U)
	{
		if (arg0->unk74_7 != 0x33)
		{
			func_80102E08(arg0);
		}
	}
	else
	{
		_subaddiesect_entrypoint_2(arg0, (s32)arg0->actorData[4], arg0->unk74_7 != 0x33);
	}
	func_8010A654(arg0, flag_getValue(FLAG2_661_UNK));
}
