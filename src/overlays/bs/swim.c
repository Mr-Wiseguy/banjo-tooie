#include "bs/swim.h"

extern s16 D_80800B90_bsswim[];
extern s32 D_80800BA4_bsswim[];
extern s32 D_80800BB4_bsswim[];
extern s32 D_80800BC4_bsswim[];
extern s32 D_80800BD4_bsswim[];

BanjoStateId func_80800000_bsswim(PlayerState* self) {
	BanjoStateId var_v1;

	if (player_isSplitUp(self) != 0) {
		var_v1 = 0x6D;
	}
	else {
		var_v1 = BS_STATE_30_DIVE;
	}
	return var_v1;
}

void func_80800030_bsswim(PlayerState* self) {
	f32 sp2C[3];
	s32 sp28;

	if (func_80096544(self) != 0)
	{
		if (rand_f() > 0.5f)
		{
			func_80092C00(self, sp2C);
		}
		else
		{
			func_80092C24(self, sp2C);
		}
		sp28 = func_8009FBB0(self, sp2C, 0.0f);
		func_800BA930((unkStruct800BA198*)sp28, -0x3C, -0x64, -0x3C, 0x3C, 0, 0x3C);
		func_800BA22C(sp28, 1);
	}
}

void func_808000E0_bsswim(PlayerState* self, AnimCtrl* arg1) {
	AssetId sp24;

	sp24 = (AssetId)D_80800B90_bsswim[self->unk15C.word];
	if (anctrl_getIndex(arg1) != sp24)
	{
		anctrl_setStart(arg1, anctrl_getAnimTimer(arg1));
		anctrl_setIndex(arg1, sp24);
		anctrl_start(arg1);
	}
	self->unk15C.word++;
	if (self->unk15C.word >= 0xAU)
	{
		self->unk15C.word = 0;
	}
}

void func_80800178_bsswim(PlayerState* self)
{
	f32 sp1C;

	sp1C = bastick_getZonePosition(self);
	if (bastick_getZone(self) == BS_STICK_ZONE_ID_0)
	{
		baphysics_set_target_horizontal_velocity(self, 0.0f);
		return;
	}
	baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 300.0f));
}

void func_808001DC_bsswim(PlayerState* self)
{
	if (func_8009E6C4(self, 1) == 0)
	{
		baphysics_set_gravity(self, 100.0f);
		baphysics_set_terminal_velocity(self, 133.33f);
		bastick_setZoneMax(self, 0, 0.03f);
		bastick_setZoneMax(self, 1, 1.0f);
		func_800961AC(self, 3);
		if (func_8008E0E8(self) != 0)
		{
			_bapackctrl_entrypoint_5(self, 4);
		}
	}
}

void func_80800270_bsswim(PlayerState* self)
{
	if (func_8009E69C(self, 1) == 0)
	{
		baphysics_reset_terminal_velocity(self);
		baphysics_reset_gravity(self);
		bastick_resetZones(self);
		func_800961AC(self, 1);
		if (func_8008E0E8(self) != 0)
		{
			_bapackctrl_entrypoint_5(self, 3);
		}
	}
}

void func_808002E0_bsswim(PlayerState* self)
{
	s32 pad;
	BanjoStateId sp30;
	f32 sp2C;
	AnimCtrl* temp_s0;

	temp_s0 = baanim_getAnimCtrlPtr(self);
	func_808001DC_bsswim(self);
	sp30 = bs_getPreviousState(self);
	if (sp30 == BS_STATE_4C_LANDING_IN_WATER)
	{
		sp2C = 0.8f;
	}
	else
	{
		sp2C = 0.5f;
	}
	if (func_8009CA70(self, sp30, 2) != 0)
	{
		if (sp30 == 0x54)
		{
			func_8009DF18(self, 0x461, 1.0f, 0x7530);
		}
		else if (sp30 != BS_STATE_4C_LANDING_IN_WATER)
		{
			func_8009DF18(self, 0x461, 1.0f, (s32)ml_map_f(func_800CF67C(), 1.0f, 0.0f, 8000.0f, 30000.0f));
		}
		bainput_setDiveCooldown(self, 4, 0.7f);
	}
	if ((anctrl_getIndex(temp_s0) == 0x57) && (sp30 != BS_STATE_4C_LANDING_IN_WATER))
	{
		anctrl_setDuration(temp_s0, 1.2f);
	}
	else
	{
		anctrl_reset(temp_s0);
		func_8008B1C8(temp_s0, sp2C);
		anctrl_setIndex(temp_s0, 0x57);
		anctrl_setPlaybackType(temp_s0, 2);
		anctrl_setStart(temp_s0, 0.3f);
		anctrl_setDuration(temp_s0, 1.2f);
		anctrl_start(temp_s0);
	}
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_2_NORMAL);
	yaw_setVelocityBounded(self, 500.0f, 5.0f);
	baphysics_set_target_horizontal_velocity(self, 0.0f);
	self->unk15C.word = 0;
	func_800A4DA4(self, 8);
}

void func_808004C4_bsswim(PlayerState* self)
{
	BanjoStateId nextState;
	AnimCtrl* sp28;

	nextState = BS_STATE_0_INVALID;
	sp28 = baanim_getAnimCtrlPtr(self);
	if ((func_8001210C(7) == 0) && (rand_f() < 0.5f))
	{
		func_8009FC34(self, 1);
	}
	if ((func_8001210C(7) == 0) && (rand_f() < 0.5f))
	{
		func_80800030_bsswim(self);
	}
	if (anctrl_isAt(sp28, 0.01f) != 0)
	{
		func_8009DEC0(self, 0x46F, 0.85f, 1.15f, 0x3E80, 0x3E80);
	}
	if (anctrl_isAt(sp28, 0.4348f) != 0)
	{
		func_808000E0_bsswim(self, sp28);
	}
	if (bastick_getZone(self) == BS_STICK_ZONE_ID_1)
	{
		nextState = BS_STATE_2E_SWIM_PADDLE;
	}
	if (player_inWater(self) == 0) {
		nextState = BS_STATE_1_IDLE;
	}
	if (bainput_should_enter_first_person(self) != 0)
	{
		nextState = _badrone_entrypoint_24(self);
	}
	if (bainput_should_dive(self) != 0) {
		nextState = func_80800000_bsswim(self);
	}
	if ((player_atWaterSurface(self) != 0) && (bakey_pressed(self, BUTTON_A) != 0))
	{
		nextState = BS_STATE_5_JUMP;
	}
	if ((baflag_isTrue(self, BA_FLAG_6) != 0) || (baflag_isTrue(self, BA_FLAG_14_LOSE_BOGGY_RACE) != 0))
	{
		nextState = 0xD;
	}
	bs_setState(self, nextState);
}

void func_80800688_bsswim(PlayerState* self)
{
    func_80800270_bsswim(self);
    func_800A4E30(self);
}

s32 bsswim_entrypoint_0(s32 arg0) {
	return D_80800BA4_bsswim[arg0];
}

void func_808006C4_bsswim(PlayerState* self)
{
	AnimCtrl* temp_s0;
	f32 sp28;

	temp_s0 = baanim_getAnimCtrlPtr(self);
	func_808001DC_bsswim(self);
	if (bs_getPreviousState(self) == BS_STATE_4C_LANDING_IN_WATER)
	{
		sp28 = 0.8f;
	}
	else
	{
		sp28 = 0.4f;
	}
	if (anctrl_getIndex(temp_s0) != 0x39)
	{
		anctrl_reset(temp_s0);
		anctrl_setIndex(temp_s0, 0x39);
		func_8008B1C8(temp_s0, sp28);
		anctrl_setStart(temp_s0, 0.8f);
		anctrl_setPlaybackType(temp_s0, 2);
		anctrl_start(temp_s0);
	}
	func_8008CA4C(self, BAANIM_UPDATE_2_SCALE_HORZ);
	baanim_setDurationRange(self, 0.3f, 1.5f);
	func_8008C9F0(self, 30.0f, 300.0f, 1.2f, 0.7f);
	yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
	yaw_setVelocityBounded(self, 500.0f, 5.0f);
	func_8009D2D8(self, 1);
	baphysics_set_type(self, BA_PHYSICS_2_NORMAL);
}

void func_808007F8_bsswim(PlayerState* self) {
	BanjoStateId nextState;
	AnimCtrl* sp30;
	f32 sp24[3];
	f32 sp20;

	nextState = BS_STATE_0_INVALID;
	sp30 = baanim_getAnimCtrlPtr(self);
	if (anctrl_isAt(sp30, 0.38f) != 0) {
		func_8009FD24(self, 1);
	}
	if (anctrl_isAt(sp30, 0.88f) != 0) {
		func_8009FD24(self, 0);
	}
	if (anctrl_isAt(sp30, 0.2f) != 0) {
		func_8009DE74(self, 0x40C, 0.9f, 1.1f);
	}
	if (anctrl_isAt(sp30, 0.7f) != 0) {
		func_8009DE74(self, 0x40C, 0.9f, 1.1f);
	}
	func_80800178_bsswim(self);
	if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
		nextState = BS_STATE_2D_SWIM_IDLE;
	}
	if (player_inWater(self) == 0) {
		nextState = BS_STATE_1_IDLE;
	}
	if ((func_8009650C(self) != 0) && (player_canDive(self) != 0)) {
		func_80096440(self, sp24);
		if (sp24[1] < -0.7f) {
			sp20 = player_getWaterHeight(self);
			if ((sp20 - player_getCoordVertical(self)) > 90.0f) {
				nextState = func_80800000_bsswim(self);
			}
		}
	}
	if (bainput_should_dive(self) != 0) {
		nextState = func_80800000_bsswim(self);
	}
	if ((player_atWaterSurface(self) != 0) && (bakey_pressed(self, BUTTON_A) != 0)) {
		nextState = BS_STATE_5_JUMP;
	}
	if ((baflag_isTrue(self, BA_FLAG_6) != 0) || (baflag_isTrue(self, BA_FLAG_14_LOSE_BOGGY_RACE) != 0)) {
		nextState = 0xD;
	}
	bs_setState(self, nextState);
}

void func_808009F0_bsswim(PlayerState* self)
{
    func_80800270_bsswim(self);
}

s32 bsswim_entrypoint_1(s32 arg0) {
	return D_80800BB4_bsswim[arg0];
}

void func_80800A24_bsswim(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_80800270_bsswim(self);
}

void func_80800A4C_bsswim(PlayerState* self)
{
    func_808001DC_bsswim(self);
    _bsrest_entrypoint_16(self);
}

void func_80800A74_bsswim(PlayerState* self)
{
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (_bsrest_entrypoint_20(self) != 0) {
		nextState = _bsrest_entrypoint_13(self);
	}
	bs_setState(self, nextState);
}

s32 bsswim_entrypoint_2(s32 arg0) {
	return D_80800BC4_bsswim[arg0];
}

void func_80800AC8_bsswim(PlayerState* self)
{
    func_808001DC_bsswim(self);
    _bsdrone_entrypoint_0(self);
}

void func_80800AF0_bsswim(PlayerState* self) {
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (_badrone_entrypoint_30(self) != 0) {
		nextState = BS_STATE_1_IDLE;
	}
	_bsdrone_entrypoint_1(self);
	bs_setState(self, nextState);
}

void func_80800B34_bsswim(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_80800270_bsswim(self);
}

s32 bsswim_entrypoint_3(s32 arg0) {
	return D_80800BD4_bsswim[arg0];
}