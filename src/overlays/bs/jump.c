#include "bs/jump.h"

extern s32 D_80801110_bsjump[];
extern s32 D_80801120_bsjump[];
extern s32 D_80801130_bsjump[];
extern s32 D_80801140_bsjump[];
extern s32 D_80801150_bsjump[];

void func_80800000_bsjump(PlayerState* self)
{
	func_8009D7A4(self, 0.91f, 1.09f);
}

void bsjump_entrypoint_0(PlayerState* self)
{
	AnimCtrl* sp3C;
	s32 sp38;
	f32 sp2C[3];
	s32 temp_v0;

	sp3C = baanim_getAnimCtrlPtr(self);
	self->unk164.word = (baflag_isTrue(self, BA_FLAG_2_ON_SPRING_PAD) && player_isSplitUp(self) == 0);
	temp_v0 = bs_getPreviousState(self);
	sp38 = temp_v0;
	if (func_8009CBDC(self, temp_v0) == 0xA)
	{
		func_80098840(self);
	}
	if (sp38 == BS_STATE_11_RATATAP)
	{
		anctrl_setSubrange(sp3C, 0.0f, 0.6667f);
		anctrl_setStart(sp3C, 0.5042f);
		anctrl_setDuration(sp3C, 8.0f);
		anctrl_setPlaybackType(sp3C, 1);
		self->unk15C.word = 1;
		return;
	}
	self->unk160.word = func_8009CA70(self, sp38, 1);
	anctrl_reset(sp3C);
	anctrl_setIndex(sp3C, 8);
	anctrl_setDuration(sp3C, 1.9f);
	func_8008B1C8(sp3C, 0.134f);
	anctrl_setStart(sp3C, 0.3f);
	anctrl_setSubrange(sp3C, 0.0f, 0.5042f);
	anctrl_setPlaybackType(sp3C, 1);
	anctrl_start(sp3C);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
	if (bastick_distance(self) != 0.0f) {
		yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
	}
	baphysics_set_target_yaw(self, yaw_getIdeal(self));
	_bswalk_entrypoint_1(self);
	sp2C[0] = yaw_getIdeal(self);
	baphysics_set_horizontal_velocity(self, sp2C[0], baphysics_get_target_horizontal_velocity(self));
	if (self->unk160.word != 0)
	{
		baphysics_set_vertical_velocity(self, 610.0f);
	}
	else
	{
		baphysics_set_vertical_velocity(self, 710.0f);
	}
	baphysics_set_gravity(self, -1350.0f);
	self->unk15C.word = 0;
	if (self->unk164.word != 0)
	{
		func_8009DE38(self, 0x422, 1.0f);
		return;
	}
	func_80800000_bsjump(self);
}

void bsjump_entrypoint_1(PlayerState* self)
{
	BanjoStateId nextState;
	f32 playerVelocity[3];
	s32 temp;
	f32 waterHeight;
	f32 playerHeight;

	nextState = BS_STATE_0_INVALID;
	if (self->unk164.word != 0)
	{
		func_8009FC80(self);
	}
	if (baflag_isTrue(self, BA_FLAG_F) != 0)
	{
		func_8009B7C0(self);
	}
	else
	{
		_bswalk_entrypoint_1(self);
	}
	func_8009BB24(self, playerVelocity);
	if (((bakey_released(self, BUTTON_A) != 0) && (playerVelocity[1] > 0.0f) && (self->unk164.word == 0)) || (player_canFullJump(self) == 0))
	{
		baphysics_reset_gravity(self);
	}
	switch (self->unk15C.word)
	{
	case 2:
		break;
	case 0:
		if (baanim_isStopped(self) != 0)
		{
			baanim_setEndAndDuration(self, 0.6667f, 4.0f);
			self->unk15C.word = 1;
		}
		if (func_8008DF8C(self, 0x82) != 0)
		{
			baanim_setEndAndDuration(self, 1.0f, 1.4f);
			self->unk15C.word = 2;
		}
		break;
	case 1:
		if (baanim_isStopped(self) != 0)
		{
			nextState = BS_STATE_2F_FALL;
		}
		if (self->unk164.word != 0)
		{
			self->unk164.word = 0;
			nextState = BS_STATE_21_SHOCK_SPRING_READY;
		}
		if (func_8008DF8C(self, 0x5A) != 0)
		{
			baanim_setEndAndDuration(self, 1.0f, 2.0f);
			self->unk15C.word = 2;
		}
		break;
	}
	if (func_8008E260(self) != 0)
	{
		nextState = BS_STATE_3D_FALL_TUMBLING;
	}
	if (bakey_released(self, BUTTON_A) != 0)
	{
		self->unk164.word = 0;
	}
	switch (player_getTransformation(self))
	{
	case TRANSFORM_1_BK:
		//If A is pressed and we can feathery flap
		if (bainput_func_80097DF4(self) != 0)
		{
			nextState = BS_STATE_10_FFLAP;
		}
		//If B is pressed and we can rat a tat rap
		if (bainput_func_80097F08(self) != 0)
		{
			playerHeight = player_getCoordVertical(self);
			waterHeight = player_getWaterHeight(self);
			//self->unk160.word seems to make it so you can't ratatat rap twice in one jump
			//self->unk160.word is 1 when you are jumping out of water
			temp = self->unk160.word;
			if ((temp != 0 && ((playerHeight - waterHeight) > 2.0f) != 0) || temp == 0)
			{
				nextState = BS_STATE_11_RATATAP;
			}

		}
		if (bainput_should_beak_bust(self) != 0)
		{
			nextState = BS_STATE_F_BBUSTER;
		}
		break;
	case TRANSFORM_A_BANJO:
		if (bainput_func_80097EC8(self) != 0)
		{
			nextState = BS_STATE_E4_PACK_WHACK;
		}
		break;
	default:
		break;
	}
	if (player_canGripGrab(self) != 0)
	{
		nextState = BS_STATE_A8_GRIP_GRAB_START;
	}
	if (player_isStable(self) != 0)
	{
		func_8009FE58(self);
		if (baphysics_get_target_horizontal_velocity(self) != 0.0f)
		{
			nextState = BS_STATE_4_RUN;
		}
		else
		{
			nextState = BS_STATE_20_LANDING;
		}
	}
	if ((playerVelocity[1] < 0.0f) && (player_inWater(self) != 0))
	{
		nextState = BS_STATE_4C_LANDING_IN_WATER;
	}
	bs_setState(self, nextState);
}

void bsjump_entrypoint_2(PlayerState* self)
{
	if (ability_getValue(ABILITY_0A_BK_FULL_JUMP_HEIGHT) != 0)
	{
		func_800C6DA0(0x3C);
	}
	if (bs_getNextState(self) != BS_STATE_11_RATATAP)
	{
		baphysics_reset_gravity(self);
	}
}

s32 bsjump_entrypoint_3(s32 self)
{
	return D_80801110_bsjump[self];
}

void bsjump_entrypoint_4(PlayerState* self)
{
	AnimCtrl* temp_s0;

	temp_s0 = baanim_getAnimCtrlPtr(self);
	if ((baflag_isTrue(self, BA_FLAG_7) != 0) && (baphysics_get_vertical_velocity(self) > 700.0f))
	{
		baphysics_set_vertical_velocity(self, 700.0f);
	}
	anctrl_reset(temp_s0);
	anctrl_setIndex(temp_s0, 0xB0);
	func_8008B1C8(temp_s0, 0.3f);
	anctrl_setDuration(temp_s0, 0.38f);
	anctrl_start(temp_s0);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
	self->unk15C.word = 0;
}

void bsjump_entrypoint_5(PlayerState* self)
{
	BanjoStateId nextState;
	AnimCtrl* sp30;
	f32 sp24[3];

	nextState = BS_STATE_0_INVALID;
	sp30 = baanim_getAnimCtrlPtr(self);
	if (baflag_isTrue(self, BA_FLAG_F) != 0)
	{
		func_8009B7C0(self);
	}
	else
	{
		_bswalk_entrypoint_1(self);
	}
	func_8009BB24(self, sp24);
	switch (self->unk15C.word)
	{
	case 1:
		break;
	case 0:
		if (func_8008DF8C(self, 0x5A) != 0)
		{
			anctrl_reset(sp30);
			anctrl_setIndex(sp30, 8);
			anctrl_setStart(sp30, 0.6667f);
			anctrl_setDuration(sp30, 2.0f);
			anctrl_setPlaybackType(sp30, 1);
			anctrl_start(sp30);
			self->unk15C.word = 1;
		}
		break;
	}
	if (baflag_isFalse(self, BA_FLAG_F) != 0)
	{
		if (func_8008E260(self) != 0)
		{
			nextState = BS_STATE_3D_FALL_TUMBLING;
		}
		switch (player_getTransformation(self))
		{
		case TRANSFORM_1_BK:
			if ((bainput_func_80097DF4(self) != 0) && (baflag_isFalse(self, BA_FLAG_5_HAS_PECKED) != 0))
			{
				nextState = BS_STATE_10_FFLAP;
			}
			if (bainput_func_80097F08(self) != 0)
			{
				nextState = BS_STATE_11_RATATAP;
			}
			if (bainput_should_beak_bust(self) != 0)
			{
				nextState = BS_STATE_F_BBUSTER;
			}
			break;
		case TRANSFORM_A_BANJO:
			if (bainput_func_80097EC8(self) != 0)
			{
				nextState = BS_STATE_E4_PACK_WHACK;
			}
			break;
		}
		if (player_canGripGrab(self) != 0)
		{
			nextState = BS_STATE_A8_GRIP_GRAB_START;
		}
		if (player_inWater(self) != 0)
		{
			nextState = BS_STATE_4C_LANDING_IN_WATER;
		}
	}
	else if ((player_inWater(self) != 0) && ((func_800A046C(self), (baflag_isTrue(self, BA_FLAG_6) != 0)) || (baflag_isTrue(self, BA_FLAG_14_LOSE_BOGGY_RACE) != 0)))
	{
		nextState = 0xD;
	}
	if (player_isStable(self) != 0)
	{
		func_8009FE58(self);
		nextState = BS_STATE_20_LANDING;
	}
	bs_setState(self, nextState);
}

void bsjump_entrypoint_6(PlayerState* arg0) {}

s32 bsjump_entrypoint_7(s32 arg0)
{
	return D_80801120_bsjump[arg0];
}

void bsjump_entrypoint_8(PlayerState* arg0)
{
	f32 sp24[3];
	AnimCtrl* temp_s0;

	temp_s0 = baanim_getAnimCtrlPtr(arg0);
	func_80098840(arg0);
	anctrl_reset(temp_s0);
	anctrl_setIndex(temp_s0, 8);
	anctrl_setDuration(temp_s0, 1.9f);
	func_8008B1C8(temp_s0, 0.134f);
	anctrl_setStart(temp_s0, 0.3f);
	anctrl_setSubrange(temp_s0, 0.0f, 0.5042f);
	anctrl_setPlaybackType(temp_s0, 1);
	anctrl_start(temp_s0);
	func_8008CA4C(arg0, BAANIM_UPDATE_1_NORMAL);
	yaw_setUpdateType(arg0, YAW_TYPE_1_DEFAULT);
	func_8009D2D8(arg0, 3);
	baphysics_set_type(arg0, BA_PHYSICS_3_LOCKED_ROTATION);
	baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
	baphysics_set_target_horizontal_velocity(arg0, 120.0f);
	sp24[0] = yaw_getIdeal(arg0);
	baphysics_set_horizontal_velocity(arg0, sp24[0], baphysics_get_target_horizontal_velocity(arg0));
	baphysics_set_vertical_velocity(arg0, 710.0f);
	baphysics_set_gravity(arg0, -1350.0f);
	func_800961AC(arg0, 6);
	arg0->unk15C.word = 0;
	func_80800000_bsjump(arg0);
}

void bsjump_entrypoint_9(PlayerState* self)
{
	BanjoStateId nextState;
	AnimCtrl* temp_s0;
	f32 sp24[3];

	nextState = BS_STATE_0_INVALID;
	temp_s0 = baanim_getAnimCtrlPtr(self);
	func_8009BB24(self, sp24);
	if (sp24[1] < 0.0f)
	{
		func_800961AC(self, 1);
	}
	switch (self->unk15C.word)
	{
	case 2:
		break;
	case 0:
		if (anctrl_isStopped(temp_s0) != 0)
		{
			anctrl_setSubrange(temp_s0, 0.0f, 0.6667f);
			anctrl_setDuration(temp_s0, 4.0f);
			anctrl_setPlaybackType(temp_s0, 1);
			self->unk15C.word = 1;
		}
		if (func_8008DF8C(self, 0x82) != 0)
		{
			anctrl_setSubrange(temp_s0, 0.0f, 1.0f);
			anctrl_setDuration(temp_s0, 1.4f);
			anctrl_setPlaybackType(temp_s0, 1);
			self->unk15C.word = 2;
		}
		break;
	case 1:
		if (func_8008DF8C(self, 0x5A) != 0)
		{
			anctrl_setSubrange(temp_s0, 0.0f, 1.0f);
			anctrl_setDuration(temp_s0, 2.0f);
			anctrl_setPlaybackType(temp_s0, 1);
			self->unk15C.word = 2;
		}
		break;
	}
	if (player_canGripGrab(self) != 0)
	{
		nextState = BS_STATE_A8_GRIP_GRAB_START;
	}
	if (player_isStable(self) != 0)
	{
		func_8009FE58(self);
		nextState = BS_STATE_20_LANDING;
	}
	bs_setState(self, nextState);
}

void bsjump_entrypoint_10(PlayerState* self)
{
    func_800961AC(self,0x1);
    baphysics_reset_gravity(self);
}

s32 bsjump_entrypoint_11(s32 arg0) {
	return D_80801130_bsjump[arg0];
}

void bsjump_entrypoint_12(PlayerState* arg0)
{
	AnimCtrl* temp_s0;
	s32 sp20;

	temp_s0 = baanim_getAnimCtrlPtr(arg0);
	sp20 = 1;
	if (bs_getPreviousState(arg0) == BS_STATE_12_FLAP_FLIP)
	{
		sp20 = 0;
	}
	anctrl_reset(temp_s0);
	anctrl_setSmoothTransition(temp_s0, sp20);
	anctrl_setIndex(temp_s0, 8);
	func_8008B1C8(temp_s0, 0.3f);
	anctrl_setDuration(temp_s0, 1.9f);
	anctrl_setStart(temp_s0, 0.6667f);
	anctrl_setPlaybackType(temp_s0, 3);
	anctrl_start(temp_s0);
	yaw_setIdeal(arg0, func_8009F308(arg0));
	func_8008CA4C(arg0, BAANIM_UPDATE_1_NORMAL);
	yaw_setUpdateType(arg0, YAW_TYPE_1_DEFAULT);
	func_8009D2D8(arg0, 3);
	baphysics_set_type(arg0, BA_PHYSICS_6_AIRBORN);
	baphysics_set_target_horizontal_velocity(arg0, 0.0f);
	func_8009BA9C(arg0, NULL);
	arg0->unk15C.word = 0;
	func_8008E944(arg0);
}

void bsjump_entrypoint_13(PlayerState* arg0)
{
	BanjoStateId nextState;
	AnimCtrl* sp30;
	f32 sp24[3];

	nextState = BS_STATE_0_INVALID;
	sp30 = baanim_getAnimCtrlPtr(arg0);
	func_8009BB24(arg0, sp24);
	switch (arg0->unk15C.word)
	{
	case 1:
		break;
	case 0:
		if (func_8008DF8C(arg0, 0x5A) != 0)
		{
			anctrl_setSubrange(sp30, 0.0f, 1.0f);
			anctrl_setDuration(sp30, 2.0f);
			anctrl_setPlaybackType(sp30, 1);
			arg0->unk15C.word = 1;
		}
		break;
	}
	if (player_isStable(arg0) != 0)
	{
		nextState = BS_STATE_1_IDLE;
	}
	bs_setState(arg0, nextState);
}

void bsjump_entrypoint_14(PlayerState* self)
{
    func_8008E95C(self);
}

s32 bsjump_entrypoint_15(s32 arg0) {
	return D_80801140_bsjump[arg0];
}

s32 bsjump_entrypoint_16(PlayerState* self)
{
	return self->unk160.word;
}

void bsjump_entrypoint_17(PlayerState* self)
{
	baanim_playForDuration_loop(self, 0x68, 0.35f);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
	func_80093360(self, 60.0f);
	if (func_8009557C(self) == 1)
	{
		_batimer_set(self, 0, 0.5f);
		_batimer_set(self, 1, 0.41f);
		func_8009DF18(self, 0x439, 1.0f, 0x55F0);
	}
	else
	{
		_batimer_set(self, 0, 0.0f);
		_batimer_set(self, 1, 0.01f);
	}
	self->unk15C.word = 0;
}

void bsjump_entrypoint_18(PlayerState* self)
{
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (_batimer_decrement(self, 1) != 0)
	{
		func_8009DF18(self, 0x446, 1.0f, 0x7D00);
	}
	_batimer_decrement(self, 0);
	_bswalk_entrypoint_1(self);
	if (_batimer_isZero(self, 1) != 0)
	{
		func_8009BF5C(self, func_8009BFD8(self) + 20.0f);
	}
	if (_batimer_isNonzero(self, 0) != 0)
	{
		switch (player_getTransformation(self))
		{
		case TRANSFORM_1_BK:
			if (bainput_func_80097DF4(self) != 0)
			{
				nextState = BS_STATE_10_FFLAP;
			}
			if (bainput_func_80097F08(self) != 0)
			{
				nextState = BS_STATE_11_RATATAP;
			}
			if (bainput_should_beak_bust(self) != 0)
			{
				nextState = BS_STATE_F_BBUSTER;
			}
			break;
		case TRANSFORM_A_BANJO:
			if (bainput_func_80097EC8(self) != 0)
			{
				nextState = BS_STATE_E4_PACK_WHACK;
			}
			break;
		}
	}
	if (player_inWater(self) != 0)
	{
		nextState = BS_STATE_4C_LANDING_IN_WATER;
	}
	if (player_isStable(self) != 0)
	{
		nextState = BS_STATE_72_HARD_LANDING;
	}
	bs_setState(self, nextState);
}

void bsjump_entrypoint_19(PlayerState* self)
{
	BanjoStateId temp_v0;

	temp_v0 = bs_getNextState(self);
	if ((temp_v0 == BS_STATE_F_BBUSTER) || (temp_v0 == BS_STATE_10_FFLAP) || (temp_v0 == BS_STATE_11_RATATAP))
	{
		func_80095588(self, 3);
	}
	func_800A042C(self);
	func_80093360(self, 0.0f);
	func_8009E0DC(self);
}

s32 bsjump_entrypoint_20(s32 arg0)
{
	return D_80801150_bsjump[arg0];
}