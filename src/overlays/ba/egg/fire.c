#include "ba/egg/fire.h"

s32 baeggfire_entrypoint_0() 
{
    return 0x14;
}

void func_80800008_baeggfire(PlayerState* arg0, s32 arg1)
{
	if (arg1 == 1) {
		arg0->unk6C->unk12 = (u8)(arg0->unk6C->unk12 + 1);
		return;
	}
	arg0->unk6C->unk11 = (u8)(arg0->unk6C->unk11 + 1);
}

void func_80800040_baeggfire(PlayerState* arg0) 
{
	arg0->unk6C->unk12 = 0;
	arg0->unk6C->unk11 = 0;
	arg0->unk6C->unk13 = 0;
}

void baeggfire_entrypoint_1(s32 arg0)
{
	PlayerState* temp_v0;

	temp_v0 = character_getPlayerState(arg0);
	temp_v0->unk6C->unk13 = 0;
	func_80800008_baeggfire(temp_v0, 0);
}

void baeggfire_entrypoint_2(s32 arg0)
{
	character_getPlayerState(arg0)->unk6C->unk13 = 0;
}

void func_808000B8_baeggfire(PlayerState* arg0)
{
	if (arg0->unk6C->unk13 == 0)
	{
		if (arg0->unk6C->unk12 != 0)
		{
			func_800C9DE4(0.25f, &_baeggfire_entrypoint_1, arg0->unk184);
			arg0->unk6C->unk13 = 1;
			_baeggsetup_entrypoint_10(arg0);
			arg0->unk6C->unk12 = (arg0->unk6C->unk12 - 1);
			return;
		}
		if (arg0->unk6C->unk11 != 0)
		{
			func_800C9DE4(0.17f, &_baeggfire_entrypoint_2, arg0->unk184);
			arg0->unk6C->unk13 = 1;
			_baeggsetup_entrypoint_8(arg0, arg0->unk6C->unk10);
			arg0->unk6C->unk11 = (u8)(arg0->unk6C->unk11 - 1);
		}
	}
}

void func_80800180_baeggfire(PlayerState* arg0, s32 arg1)
{
	arg0->unk6C->unk8 = arg1;
	switch (arg1)
	{
	case 1:
		arg0->unk6C->unk0 = 0.0f;
		arg0->unk6C->unk4 = 0;
		arg0->unk6C->unkC = 0;
		return;
	case 2:
		if (func_800944F8(arg0, arg0->unk6C->unk10) != 0)
		{
			arg0->unk6C->unk0 = 0.15f;
			return;
		}
		arg0->unk6C->unk0 = 0.28f;
		return;
	case 3:
		arg0->unk6C->unk0 = 0.2f;
		return;
	case 4:
		arg0->unk6C->unk0 = 0.5f;
		return;
	}
}

void func_80800250_baeggfire(PlayerState* arg0) {

	s32 pad;
	f32 sp50[3];
	f32 sp44[3];
	f32 sp38[3];
	s32 temp_v0;
	s32 sp30;

	sp30 = func_800944F8(arg0, (s32)arg0->unk6C->unk10);
	if (arg0->unk6C->unk4 == 0)
	{
		arg0->unk6C->unk10 = func_80094510(arg0);
	}
	temp_v0 = func_800944E0(arg0, (s32)arg0->unk6C->unk10);
	if (arg0->unk6C->unk4 == 0)
	{
		func_80800008_baeggfire(arg0, 1);
		if (temp_v0 == 1)
		{
			func_80800180_baeggfire(arg0, 4);
		}
		else
		{
			func_80800180_baeggfire(arg0, 2);
		}
	}
	else if ((sp30 != 0) || (arg0->unk6C->unk4 < (temp_v0 - 1)))
	{
		func_80800008_baeggfire(arg0, 0);
		func_80800180_baeggfire(arg0, 2);
	}
	else
	{
		func_80800008_baeggfire(arg0, 0);
		func_80800180_baeggfire(arg0, 4);
	}
	if (sp30 != 0)
	{
		arg0->unk6C->unk4 = 1;
	}
	else
	{
		arg0->unk6C->unk4 += 1;
	}
	arg0->unk6C->unkC = 0;
	baeggfire_entrypoint_3(arg0, sp50, sp44);
	ml_vec3f_set_length(sp44, 100.0f);
	ml_vec3f_sum(sp38, sp50, sp44);

	ml_vec3f_set_length(sp44, arg0->unk6C->unk10 == 7 ? 5000.0f : 3000.0f);
	_baeggsetup_entrypoint_6(arg0, arg0->unk6C->unk10, sp50, sp38, sp44);
	_baeggcursor_entrypoint_8(arg0);
	func_800C6DA0(0x43);
}

void baeggfire_entrypoint_3(PlayerState* arg0, f32* arg1, f32* arg2)
{
	f32 sp48[2];
	f32 sp40[2];
	f32 sp34[3];
	f32 sp28[3];

	if (_baeggcursor_entrypoint_2(arg0) != 1)
	{
		_baeggcursor_entrypoint_3(arg0, sp48, &sp48[1]);
	}
	else
	{
		sp48[0] = 152.0f;
		sp48[1] = 114.0f;
	}
	func_800C5008(func_800A4C68(arg0), sp48, sp40);
	ml_vec3f_assign_value(&sp28, sp40[0], sp40[1], 100.0f);
	func_800C4E58(func_800A4C68(arg0), sp28, sp34);
	func_800A4CE8(arg0, arg1);
	ml_getdiff_vec3f(arg2, sp34, arg1);
	ml_vec3f_set_length(arg2, 1.0f);
}

void baeggfire_entrypoint_4(s32 arg0)
{
    func_8009E0AC(arg0, 1);
}

void baeggfire_entrypoint_5(PlayerState* arg0)
{
	arg0->unk6C->unk0 = 0.0f;
	arg0->unk6C->unkC = 0;
	arg0->unk6C->unk8 = 0;
	func_80800180_baeggfire(arg0, 1);
	func_8009E0AC(arg0, 0);
	func_80800040_baeggfire(arg0);
}

void baeggfire_entrypoint_6(PlayerState* arg0)
{
	f32* temp_a0;
	s32 temp_v0;

	func_808000B8_baeggfire(arg0);
	switch (arg0->unk6C->unk8)
	{
	case 1:
		if (arg0->unk6C->unkC != 0)
		{
			func_80800250_baeggfire(arg0);
			return;
		}
		return;
	case 2:
		if (timer_reachedZero(arg0->unk6C) != 0)
		{
			func_80800180_baeggfire(arg0, 3);
			return;
		}
		break;
	case 3:
		if (timer_reachedZero(arg0->unk6C) != 0)
		{
			func_80800180_baeggfire(arg0, 1);
		}
		if (arg0->unk6C->unkC != 0)
		{
			func_80800250_baeggfire(arg0);
			return;
		}
		break;
	case 4:
		if (timer_reachedZero(arg0->unk6C) != 0)
		{
			func_80800180_baeggfire(arg0, 1);
		}
		break;
	}
}

void baeggfire_entrypoint_7(PlayerState* arg0) 
{
	arg0->unk6C->unkC = 1;
}

s32 baeggfire_entrypoint_8(PlayerState* arg0) {
	return arg0->unk6C->unk8 >= 2;
}