#include "bs/claw.h"

extern s32 D_80800400_bsclaw[];

void bsclaw_entrypoint_0(PlayerState* self)
{
	func_8009E474(self);
	func_800C6DA0(0x47);
	baflag_clear(self, 0x1F);
	func_800A0CF4(self, 0);
}

void bsclaw_entrypoint_1(PlayerState* self)
{
	f32 var_f0;

	baanim_playForDuration_onceSmooth(self, 5, 1.4f);
	func_8009FFD8(self, 1, 1, 1, 2);
	baphysics_set_target_yaw(self, yaw_getIdeal(self));
	baphysics_set_target_horizontal_velocity(self, 80.0f);
	baflag_clear(self, 0x1F);
	func_800A0CF4(self, 1);
	if (ability_getValue(ABILITY_32_BREEGULL_BASH) != 0)
	{
		var_f0 = 0.24f;
	}
	else
	{
		var_f0 = 0.0f;
	}
	_batimer_set(self, 0, var_f0);
	func_8009E4AC(self);
	func_8009E5A4(self, 2, 3);
	func_8009E55C(self, 2, 40.0f);
}

void bsclaw_entrypoint_2(PlayerState* self)
{
	AnimCtrl* sp24;
	BanjoStateId nextState;
	f32 sp1C;
	AnimCtrl* temp_v0;

	temp_v0 = baanim_getAnimCtrlPtr(self);
	sp24 = temp_v0;
	nextState = 0;
	sp1C = anctrl_getAnimTimer(temp_v0);
	if ((_batimer_get(self, 0) != 0.0f) && (bakey_pressed(self, BUTTON_B) != 0)) {
		nextState = BS_STATE_189_BREEGULL_BASH;
	}
	_batimer_decrement(self, 0);
	if (anctrl_isAt(sp24, 0.5129f) != 0) {
		baphysics_set_horizontal_velocity(self, yaw_get(self), 360.0f);
	}
	if (anctrl_isAt(sp24, 0.6539f) != 0) {
		baphysics_set_target_horizontal_velocity(self, 0.0f);
	}
	if (
		(anctrl_isAt(sp24, 0.1488000005f) != 0) || ((sp1C > 0.0488f) && (sp1C < 0.24880001f))
		|| (anctrl_isAt(sp24, 0.32879999f) != 0) || ((sp1C > 0.2288f) && (sp1C < 0.4288f))
		|| (anctrl_isAt(sp24, 0.5788f) != 0) || ((sp1C > 0.47880003f) && (sp1C < 0.67880005f))
		)
	{
		baflag_set(self, 0x1F);
	}
	else {
		baflag_clear(self, 0x1F);
	}
	if (anctrl_isAt(sp24, 0.5788f) != 0) {
		baphysics_set_target_horizontal_velocity(self, 0.0f);
	}
	if (anctrl_isAt(sp24, 0.118799999f) != 0) {
		func_8009DE38(self, 0x442C, 1.13f);
	}
	if (anctrl_isAt(sp24, 0.288800001f) != 0) {
		func_8009DE38(self, 0x442C, 1.1f);
	}
	if (anctrl_isAt(sp24, 0.5f) != 0) {
		func_8009DE38(self, 0x442C, 1.32f);
	}
	if (anctrl_isStopped(sp24) != 0) {
		nextState = BS_STATE_1_IDLE;
	}
	if (player_inWater(self) != 0) {
		nextState = BS_STATE_4C_LANDING_IN_WATER;
	}
	if (bakey_pressed(self, BUTTON_A) != 0) {
		nextState = bs_getTypeOfJump(self);
	}
	bs_setState(self, nextState);
}

s32 bsclaw_entrypoint_3(s32 arg0) {
	return D_80800400_bsclaw[arg0];
}