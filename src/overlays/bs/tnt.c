#include "bs/tnt.h"


extern s32 D_80802230_bstnt;
extern s32 D_8080223C_bstnt;
extern s32 D_80802284_bstnt;
extern s32 D_808022CC_bstnt;
extern s32 D_808022FC_bstnt;
extern s32 D_80802328_bstnt;
extern s32 D_808023C8_bstnt;
extern s32 D_808023F8_bstnt[];
extern s32 D_80802408_bstnt[];
extern s32 D_80802418_bstnt;
extern s32 D_8080246C_bstnt;
extern s32 D_808024B8_bstnt;
extern s32 D_80802504_bstnt;
extern s32 D_8080254C_bstnt[];
extern s32 D_8080255C_bstnt[];
extern s32 D_8080256C_bstnt[];
extern s32 D_8080257C_bstnt[];
extern s32 D_8080258C_bstnt[];
extern s32 D_8080259C_bstnt[];
extern s32 D_808025AC_bstnt[];
extern s32 D_808025BC_bstnt[];
extern s32 D_808025CC_bstnt[];

void bstnt_entrypoint_4(PlayerState*);
s32 bstnt_entrypoint_8(PlayerState*);

void func_80800000_bstnt(PlayerState* self) {
	func_8009DF94(self, 0x504, 1.0f, 0x7FFF);
}

void func_80800028_bstnt(PlayerState* self)
{
	if (self->unk160.bytes[0] != 0) {
		func_800C2FDC(self->unk160.bytes[0]);
	}
	self->unk160.bytes[0] = 0U;
}

void func_80800060_bstnt(PlayerState* self) {}

void func_80800068_bstnt(PlayerState* self) {
	self->unk160.bytes[0] = func_8009D454(self, 0, &D_80802230_bstnt);
}

void func_8080009C_bstnt(PlayerState* self)
{
	if (self->unk160.bytes[0] != 0) {
		func_800C2FDC(self->unk160.bytes[0]);
	}
	self->unk160.bytes[0] = 0U;
}

void func_808000D4_bstnt(PlayerState* self, f32 arg1) {
	if (_batimer_get(self, 2) == 0.0f) {
		_bapulse_entrypoint_3(self, 0.0f, 0.15f);
		func_80092744(self, 1);
		func_80092750(self, 0xFF, 0xFF, 0xFF, 0xFF);
	}
	_batimer_set(self, 2, arg1);
}

void func_80800164_bstnt(PlayerState* self) {
	f32 sp1C;

	sp1C = bastick_getZonePosition(self);
	if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
		baphysics_set_target_horizontal_velocity(self, 0.0f);
		return;
	}
	baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 600.0f));
}

s32 func_808001C8_bstnt(PlayerState* self, s32 arg1)
{
	if (bakey_pressed(self, BUTTON_A) != 0)
	{
		arg1 = 0x107;
	}
	arg1 = arg1;
	arg1 = arg1;
	if (bstnt_entrypoint_8(self) != 0)
	{
		arg1 = 0x10E;
	}
	return arg1;
}

BanjoStateId func_80800218_bstnt(PlayerState* self, BanjoStateId arg1) {

	if (bainput_should_enter_first_person(self) != 0)
	{
		arg1 = _badrone_entrypoint_24(self);
	}
	if (bakey_pressed(self, BUTTON_A) != 0) {
		arg1 = 0x107;
	}
	if (bstnt_entrypoint_8(self) != 0) {
		arg1 = 0x10E;
	}
	if ((self->unk168.bytes[0] != 0) && (player_isStable(self) != 0)) {
		arg1 = 0x10D;
	}
	return arg1;
}

void func_808002AC_bstnt(PlayerState* self, f32* arg1) {
	func_800BBCB8(arg1, NULL, 1.0f, 8, &D_8080223C_bstnt);
	func_800BBCB8(arg1, NULL, 1.0f, 0xC, &D_80802284_bstnt);
}

void func_8080030C_bstnt(PlayerState* self, f32* arg1)
{
	s32 pad;

	f32 sp78[3];
	f32 temp_f0;
	s32 temp_v0;
	s32 var_s0;
	f32 temp;
	temp_v0 = func_800B5BE4(8);
	func_800BABB8(temp_v0, arg1, NULL, 1.0f, &D_808022CC_bstnt);
	temp = 0.43f;
	func_800BA8F8((unkStruct800BA198*)temp_v0, temp, temp);
	temp_f0 = 19.0f / temp;
	func_800BA5BC((unkStruct800BA198*)temp_v0, temp_f0, temp_f0);

	for (var_s0 = 0; var_s0 != 0x168; var_s0 += 0x2D)
	{
		ml_vec3f_assign_value(sp78, 0.0f, var_s0, 480.0f);
		func_800BA994((unkStruct800BA198*)temp_v0, sp78[0], sp78[1], sp78[2], sp78[0], sp78[1], sp78[2]);
		func_800BA22C(temp_v0, 1);
		ml_vec3f_assign_value(sp78, -45.0f, var_s0, 430.0f);
		func_800BA994((unkStruct800BA198*)temp_v0, sp78[0], sp78[1], sp78[2], sp78[0], sp78[1], sp78[2]);
		func_800BA22C(temp_v0, 1);
	}
}

void func_808004F8_bstnt(PlayerState* self, f32* arg1) {
	f32 sp24[3];

	ml_vec3f_copy(sp24, arg1);
	func_800CA3F4(func_800A4C48(self), sp24, 80.0f);
	func_800BBCB8(sp24, NULL, 1.0f, 1, &D_808022FC_bstnt);
}

void func_80800554_bstnt(PlayerState* self) {
	f32 sp2C[3];
	s32 sp28;
	s32 temp_v0;

	player_getCoords(self, &sp2C);
	func_800CA3F4(func_800A4C48(self), sp2C, 20.0f);
	temp_v0 = func_800B5BE4(8);
	sp28 = temp_v0;
	func_800BABB8(temp_v0, sp2C, NULL, 1.0f, &D_80802328_bstnt);
	func_800CA3F4(func_800A4C48(self), sp2C, 45.0f);
	func_800BABB8(sp28, sp2C, NULL, 1.0f, &D_808023C8_bstnt);
}

void func_808005F4_bstnt(PlayerState* self) {
	f32 sp24[3];

	player_getCoords(self, sp24);
	_bashake_entrypoint_0(self, 3, 2);
	func_8009DB04(self, 0x413, 1.0f, 0x7FFF);
	func_808004F8_bstnt(self, sp24);
	func_8080030C_bstnt(self, sp24);
	func_808002AC_bstnt(self, sp24);
}

void func_80800668_bstnt(PlayerState* self) {
	func_8009E474(self);
	baflag_clear(self, 0x32);
}

void func_80800694_bstnt(PlayerState* self)
{
	func_8009E4AC(self);
}

void func_808006B4_bstnt(PlayerState* self, s32 arg1)
{
	self->unk168.bytes[1] = arg1;
	baflag_set(self, 0x32);
	func_8009E55C(self, 1, 200.0f);
}

void func_808006EC_bstnt(PlayerState* self)
{
	func_8009E55C(self, 1, 28.0f);
	baflag_clear(self, 0x32);
}

void func_80800720_bstnt(PlayerState* self)
{
	u32 temp_t9;

	temp_t9 = (u32)ml_max_f((f32)(self->unk168.bytes[1] - 1), 0.0f);
	self->unk168.bytes[1] = (u8)temp_t9;
	if (!(self->unk168.bytes[1])) {
		func_808006EC_bstnt(self);
	}
}

void func_808007EC_bstnt(PlayerState* self, s32 arg1) {
	f32 temp_f0;

	self->unk15C.word = arg1;
	switch (arg1) {                                 /* irregular */
	case 1:
		baanim_playForDuration_onceSmooth(self, 0xE6, 1.5f);
		func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
		baphysics_set_target_horizontal_velocity(self, 0.0f);
		func_808000D4_bstnt(self, 10.0f);
		return;
	case 2:
		func_808006B4_bstnt(self, 0xAU);
		func_808005F4_bstnt(self);
		player_affectCurrentHealth(self, -1);
		func_800931AC(self, 3);
		self->unk16C = 800.0f;
		temp_f0 = yaw_get(self);
		self->unk170 = temp_f0;
		func_8009328C(self, temp_f0);
		return;
	case 0:
		yaw_setIdeal(self, func_80092BE8(self));
		yaw_applyIdeal(self);
		func_800931AC(self, 1);
		func_808000D4_bstnt(self, 0.1f);
		func_8009BC34(self);
		func_8009BF5C(self, 0.0f);
		baroll_setIdeal(self, 0.0f);
		return;
	}
}

void func_8080092C_bstnt(PlayerState* self) {
	func_80800668_bstnt(self);
	func_80800028_bstnt(self);
	func_808007EC_bstnt(self, 0);
}

void func_80800960_bstnt(PlayerState* self) {
	func_80800694_bstnt(self);
	func_80800060_bstnt(self);
	self->unk15C.word = 0;
	func_808007EC_bstnt(self, 1);
}

void func_80800998_bstnt(PlayerState* self) {
	BanjoStateId nextState;
	f32 sp20;
	f32 temp_f0;

	nextState = BS_STATE_0_INVALID;
	sp20 = time_getDelta();
	func_8009D3A8(self, 0);
	if (player_inWater(self) != 0) {
		baphysics_set_gravity(self, -10.0f);
		baphysics_set_terminal_velocity(self, -20.0f);
	}
	switch (self->unk15C.word) {
	case 1:
		if (baanim_isAt(self, 0.1587f) != 0) {
			func_80800068_bstnt(self);
		}
		if (baanim_isAt(self, 0.277f) != 0) {
			func_80800000_bstnt(self);
		}
		if (baanim_isAt(self, 0.434f) != 0) {
			func_808007EC_bstnt(self, 2);
		}
		break;
	case 2:
		func_8080009C_bstnt(self);
		temp_f0 = ml_normalizeAngle_f(self->unk170 + (self->unk16C * sp20));
		self->unk170 = temp_f0;
		func_8009328C(self, temp_f0);
		if (baanim_getTimer(self) > 0.78f) {
			self->unk16C = ml_max_f(0.0f, self->unk16C - (750.0f * sp20));
		}
		if (baanim_isAt(self, 0.5f) != 0) {
			func_80800554_bstnt(self);
		}
		if (self->unk16C == 0.0f) {
			nextState = 0x10C;
		}
		break;
	}
	func_80800720_bstnt(self);
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

s32 bstnt_entrypoint_0(s32 arg0) {
	return D_808023F8_bstnt[arg0];
}

void func_80800B60_bstnt(PlayerState* self, s32 arg1) {
	f32 sp44;
	f32 sp38[3];
	f32 sp2C[3];

	self->unk15C.word = arg1;
	switch (arg1) {
	case 1:
		baanim_playForDuration_onceSmooth(self, 0xE2, 0.7f);
		func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_0_NONE);
		func_8010114C(self->unk164.word, 6, 0);
		func_80101038(sp2C);
		player_getCoords(self, sp38);
		func_800F1E6C(sp38, sp2C, &sp44);
		yaw_setIdeal(self, sp44);
		_bamovegoto_entrypoint_0(self);
		_bamovegoto_entrypoint_12(self, sp2C);
		_bamovegoto_entrypoint_7(self, 0.7f);
		_bamovegoto_entrypoint_13(self);
		return;
	case 2:
		baanim_playForDuration_onceSmooth(self, 0xE3, 3.4f);
		func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
		baphysics_set_target_horizontal_velocity(self, 0.0f);
		func_8008F880(self->unk164.object, sp2C);
		player_getCoords(self, sp38);
		func_800F1E6C(sp2C, sp38, &sp44);
		yaw_setIdeal(self, sp44);
		return;
	}
}

void func_80800CB0_bstnt(PlayerState* self)
{
    func_80800028_bstnt(self);
    func_800951B4(self);
}

void func_80800CD8_bstnt(PlayerState* self) {
	func_80800060_bstnt(self);
	self->unk15C.word = 0;
	func_80800B60_bstnt(self, 1);
}

void func_80800D08_bstnt(PlayerState* self) {
	BanjoStateId nextState;
	s32 temp_v0;

	nextState = BS_STATE_0_INVALID;
	switch (self->unk15C.word)
	{
	case 1:
		if (_bamovegoto_entrypoint_4(self) != 0) {
			func_80800B60_bstnt(self, 2);
		}
		break;
	case 2:
		if (baanim_isAt(self, 0.1183f) != 0) {
			func_80800068_bstnt(self);
		}
		if (baanim_isAt(self, 0.592f) != 0) {
			func_80800000_bstnt(self);
		}
		if (baanim_isAt(self, 0.65f) != 0) {
			func_8009514C(self);
		}
		if (baanim_isAt(self, 0.665f) != 0) {
			func_8010114C(self->unk164.word, 5, self->unk184);
			func_8080009C_bstnt(self);
		}
		if (baanim_isAt(self, 0.85f) != 0) {
			func_800951B4(self);
		}
		if (baanim_isStopped(self) != 0) {
			nextState = 0x10C;
		}
		break;
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

s32 bstnt_entrypoint_1(s32 arg0) {
	return D_80802408_bstnt[arg0];
}

void bstnt_entrypoint_2(PlayerState* self) {
	if (func_8009E74C(self, 0xC) == 0) {
		func_800947EC(self, 1, 0);
		func_80092864(self, 1.0f);
		func_8009C000(self);
		baroll_resetAngularVelocity(self);
		bastick_popZone(self);
		func_80095A40(self);
		func_80092744(self, 0);
	}
}

void bstnt_entrypoint_3(PlayerState* self) {
	if (func_8009E77C(self, 0xC) == 0) {
		self->unk164.word = 0;
		self->unk168.bytes[0] = 0;
		self->unk168.bytes[2] = 0;
		_batimer_set(self, 2, 0.0f);
		func_80092864(self, 0.8999939f);
		func_8009BFE4(self, 1000.0f, 12.0f);
		baroll_setAngularVelocity(self, 1000.0f, 12.0f);
		bastick_pushZone(self);
		bastick_setZoneMax(self, 0, 0.12f);
		bastick_setZoneMax(self, 1, 1.0f);
		func_800959C8(self, 85.0f, 38.0f);
		func_800947EC(self, 1, 1);
	}
}

void bstnt_entrypoint_4(PlayerState* self) {
	s32 temp_f8;

	if (_batimer_decrement(self, 2) != 0) {
		func_80092744(self, 0);
		_bapulse_entrypoint_2(self);
	}
	else if (_batimer_get(self, 2) > 0.0f) {
		_bapulse_entrypoint_4(self);
		temp_f8 = (s32)func_800F12D4(_bapulse_entrypoint_1(self), 0.0f, 1.0f, 0.0f, 255.0f);
		func_80092750(self, 0xFF, temp_f8, temp_f8, 0xFF);
	}
	self->unk168.bytes[0] = 0;
}

void func_80801058_bstnt(PlayerState* self)
{
    _basudie_entrypoint_8(self);
    bstnt_entrypoint_2(self);
}

void func_80801080_bstnt(PlayerState* self) {
	f32 sp2C[3];

	bstnt_entrypoint_3(self);
	_basudie_entrypoint_9(self, 50.0f);
	func_80800554_bstnt(self);
	player_getCoords(self, sp2C);
	func_808004F8_bstnt(self, sp2C);
	func_8080030C_bstnt(self, sp2C);
	func_808002AC_bstnt(self, sp2C);
	func_8009DB04(self, 0x693, 1.0f, 0x7FFF);
	func_8009D9D4(self);
	func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_80802418_bstnt);
	func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_8080246C_bstnt);
	func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_808024B8_bstnt);
	func_800BBCB8(sp2C, NULL, 1.0f, 9, &D_80802504_bstnt);
}

void func_80801190_bstnt(PlayerState* self)
{
    _basudie_entrypoint_10(self);
    bstnt_entrypoint_4(self);
}

s32 bstnt_entrypoint_5(s32 arg0) {
	return D_8080254C_bstnt[arg0];
}

void func_808011CC_bstnt(PlayerState* self)
{
    bstnt_entrypoint_3(self);
    _bsdrone_entrypoint_0(self);
}

void func_808011F4_bstnt(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
    bstnt_entrypoint_4(self);
}

void func_8080121C_bstnt(PlayerState* self)
{
    bstnt_entrypoint_2(self);
    _bsdrone_entrypoint_2(self);
}

s32 bstnt_entrypoint_6(s32 arg0) {
	return D_8080255C_bstnt[arg0];
}

void func_80801258_bstnt(PlayerState* self) {
	AnimCtrl* temp_v0;

	bstnt_entrypoint_3(self);
	temp_v0 = baanim_getAnimCtrlPtr(self);
	anctrl_reset(temp_v0);
	anctrl_setIndex(temp_v0, 0xE5);
	anctrl_setStart(temp_v0, 0.5036f);
	anctrl_setDuration(temp_v0, 0.7f);
	anctrl_setPlaybackType(temp_v0, 3);
	anctrl_start(temp_v0);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
	self->unk15C.word = 0;
}

void func_808012F8_bstnt(PlayerState* self) {
	BanjoStateId nextState;
	AnimCtrl* sp30;
	f32 sp24[3];

	nextState = BS_STATE_0_INVALID;
	sp30 = baanim_getAnimCtrlPtr(self);
	func_8009D3A8(self, 0);
	func_80800164_bstnt(self);
	func_8009BB24(self, sp24);
	switch (self->unk15C.word) {
	case 2:
		break;
	case 0:
		if (func_8008DF8C(self, 0x82) != 0) {
			baanim_setEnd(self, 0.6538f);
			self->unk15C.word = 1;
		}
		break;
	case 1:
		if (player_isStable(self) != 0) {
			func_800A2EAC(self);
			baphysics_set_target_horizontal_velocity(self, 0.0f);
			baanim_setEndAndDuration(self, 1, 1.0f);
			self->unk15C.word = 2;
		}
		break;
	}
	if (player_inWater(self) != 0) {
		nextState = 0x111;
	}
	if ((player_isStable(self) != 0) && ((bastick_getZone(self) > 0) || ((self->unk15C.word == 2) && (anctrl_isStopped(sp30) != 0)))) {
		if (baflag_isTrue(self, BA_FLAG_19) != 0) {
			nextState = _badrone_entrypoint_28(self);
		}
		else {
			nextState = 0x10C;
		}
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

void func_80801464_bstnt(PlayerState* self)
{
	func_8009BF5C(self, 0.0f);
	baroll_setIdeal(self, 0.0f);
	bstnt_entrypoint_2(self);
}

s32 bstnt_entrypoint_7(s32 arg0)
{
	return D_8080256C_bstnt[arg0];
}

s32 bstnt_entrypoint_8(PlayerState* self)
{
	if (bakey_pressed(self, BUTTON_B) == 0)
	{
		return 0;;
	}
	if (player_getCurrentHealth(self) >= 2)
	{
		return 1;
	}
	func_800FC660(0xF);
	return 0;
}

void func_8080150C_bstnt(PlayerState* self) {
	AnimCtrl* sp34;
	s32 pad;
	f32 sp2C;

	bstnt_entrypoint_3(self);
	sp34 = baanim_getAnimCtrlPtr(self);
	anctrl_reset(sp34);
	anctrl_setSmoothTransition(sp34, 0);
	anctrl_setIndex(sp34, 0xE2);
	anctrl_setSubrange(sp34, 0.0f, 0.4008f);
	anctrl_setDuration(sp34, 1.0f);
	anctrl_setPlaybackType(sp34, 1);
	anctrl_start(sp34);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_6_AIRBORN);
	yaw_setVelocityBounded(self, 1200.0f, 10.0f);
	if (bastick_distance(self) != 0.0f) {
		yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
	}
	baphysics_set_target_yaw(self, yaw_getIdeal(self));
	func_80800164_bstnt(self);
	sp2C = yaw_getIdeal(self);
	baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
	baphysics_set_vertical_velocity(self, 693.5f);
	baphysics_set_gravity(self, -1200.0f);
	func_8009D7A4(self, 1.35f, 1.45f);
	self->unk15C.word = 0;
}

void func_8080166C_bstnt(PlayerState* self) {
	BanjoStateId sp24;
	AnimCtrl* sp20;

	sp24 = BS_STATE_0_INVALID;
	sp20 = baanim_getAnimCtrlPtr(self);
	func_80800164_bstnt(self);
	if ((bakey_released(self, BUTTON_A) != 0) && (baphysics_get_vertical_velocity(self) > 0.0f)) {
		baphysics_reset_gravity(self);
	}
	switch (self->unk15C.word)
	{
	case 0:
		if (func_8008DF8C(self, 0x82) != 0)
		{
			baanim_setEndAndDuration(self, 1, 0.7f);
			self->unk15C.word = 2;
		}
		else if (anctrl_isStopped(sp20) != 0)
		{
			baanim_setEndAndDuration(self, 0.651f, 3.0f);
			self->unk15C.word = 1;
		}
		break;
	case 1:
		if (func_8008DF8C(self, 0x82) != 0) {
			baanim_setEndAndDuration(self, 1, 1.0f);
			self->unk15C.word = 2;
		}
		break;
	case 2:
		func_8009D3A8(self, 0);
		if (player_isStable(self) != 0) {
			func_800A2EAC(self);
			baanim_setEndAndDuration(self, 1, 1.0f);
			self->unk15C.word = 3;
		}
		break;
	case 3:
		baphysics_set_target_horizontal_velocity(self, baphysics_get_horizontal_velocity(self) * 0.25f);
		func_8009D2D8(self, 3);
		func_8009D3A8(self, 0);
		if (anctrl_isStopped(sp20) != 0) {
			if (baphysics_get_horizontal_velocity(self) > 0.0f) {
				sp24 = 0x108;
			}
			else {
				sp24 = 0x10C;
			}
		}
		break;
	}
	if ((baphysics_get_vertical_velocity(self) < 0.0f) && (player_inWater(self) != 0)) {
		sp24 = 0x111;
	}
	if (bstnt_entrypoint_8(self) != 0) {
		sp24 = 0x10E;
	}
	if ((player_isStable(self) != 0) && (bakey_pressed(self, BUTTON_A) != 0)) {
		sp24 = 0x107;
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, sp24);
}

void func_808018D0_bstnt(PlayerState* self) {
	baphysics_reset_gravity(self);
	func_8009BF5C(self, 0.0f);
	baroll_setIdeal(self, 0.0f);
	bstnt_entrypoint_2(self);
}

s32 bstnt_entrypoint_9(s32 arg0) {
	return D_8080257C_bstnt[arg0];
}

void bstnt_entrypoint_10(PlayerState* self) {
	if (func_8009E6EC(self) == 0x42) {
		self->unk164.object = func_80099A4C(self);
		self->unk168.bytes[0] = 1;
		func_8009E830(self, 2);
		return;
	}
	func_80099B94(self);
}

void func_80801980_bstnt(PlayerState* self, u32 arg1) {
	AnimCtrl* sp3C;
	f32 sp38;
	f32 sp34;
	f32 sp30;
	s32 pad;
	f32 sp28;
	f32 temp_f0;

	sp3C = baanim_getAnimCtrlPtr(self);
	self->unk15C.word = (s32)arg1;
	switch (arg1) {
	case 1:
		func_8009DB04(self, 0x3F0, rand_fBounded(0.96f, 1.04f), 0x2710);
		func_800A2EEC(self, 4);
		func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
		if (bastick_distance(self) != 0.0f) {
			yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
		}
		baphysics_set_target_yaw(self, yaw_getIdeal(self));
		func_80800164_bstnt(self);
		sp28 = yaw_getIdeal(self);
		baphysics_set_horizontal_velocity(self, sp28, baphysics_get_target_horizontal_velocity(self));
		temp_f0 = baphysics_get_target_horizontal_velocity(self);
		sp38 = temp_f0;
		sp34 = ml_map_f(temp_f0, 30.0f, 600.0f, 0.35f, 0.7f);
		sp30 = ml_map_f(sp38, 30.0f, 600.0f, 346.75f, 693.5f);
		anctrl_reset(sp3C);
		anctrl_setIndex(sp3C, 0xE2);
		anctrl_setSubrange(sp3C, 0.0f, 0.4008f);
		anctrl_setDuration(sp3C, sp34);
		anctrl_setPlaybackType(sp3C, 1);
		anctrl_start(sp3C);
		baphysics_set_vertical_velocity(self, sp30);
		return;
	case 2:
		baanim_setEndAndDuration(self, 0.651f, 3.0f);
		return;
	case 3:
		baanim_setEndAndDuration(self, 0.93f, 0.7f);
		return;
	case 4:
		self->unk16C = baphysics_get_horizontal_velocity(self) * 0.25f;
		func_8009D2D8(self, 3);
		baphysics_set_target_horizontal_velocity(self, self->unk16C);
		func_800A2FCC(self, 0);
		baanim_setEndAndDuration(self, 0.93f, 0.7f);
		return;
	case 0:
		func_8009BF5C(self, 0.0f);
		baroll_setIdeal(self, 0.0f);

	default:
		return;
	}
}

void func_80801C0C_bstnt(PlayerState* self) {
	bstnt_entrypoint_3(self);
	self->unk15C.word = 0;
	func_80801980_bstnt(self, 1U);
}

void func_80801C3C_bstnt(PlayerState* self) {
	BanjoStateId nextState;
	AnimCtrl* sp30;
	f32 sp24[3];

	nextState = BS_STATE_0_INVALID;
	sp30 = baanim_getAnimCtrlPtr(self);
	func_80800164_bstnt(self);
	func_8009BB24(self, sp24);
	switch (self->unk15C.word)
	{
	case 1:
		if (func_8008DF8C(self, 0x82) != 0) {
			func_80801980_bstnt(self, 3U);
		}
		else if (anctrl_isStopped(sp30) != 0) {
			func_80801980_bstnt(self, 2U);
		}
		nextState = func_808001C8_bstnt(self, 0);
		break;
	case 2:
		if (func_8008DF8C(self, 0x82) != 0) {
			func_80801980_bstnt(self, 3U);
		}
		nextState = func_808001C8_bstnt(self, 0);
		break;
	case 3:
		func_8009D3A8(self, 0);
		if (player_isStable(self) != 0) {
			func_80801980_bstnt(self, 4U);
		}
		nextState = func_808001C8_bstnt(self, 0);
		break;
	case 4:
		if ((self->unk168.bytes[0] != 0) && (player_isStable(self) != 0)) {
			nextState = 0x10D;
		}
		func_8009D3A8(self, 0);
		if (anctrl_isStopped(sp30) != 0) {
			if (baphysics_get_target_horizontal_velocity(self) > 0.0f) {
				func_80801980_bstnt(self, 1U);
			}
			else {
				nextState = 0x10C;
			}
		}
		else {
			baphysics_set_target_horizontal_velocity(self, self->unk16C);
		}
		nextState = func_80800218_bstnt(self, nextState);
		break;
	}
	if (player_inWater(self) != 0) {
		nextState = 0x111;
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

void func_80801E20_bstnt(PlayerState* self)
{
    func_80801980_bstnt(self,0);
    bstnt_entrypoint_2(self);
}

s32 bstnt_entrypoint_11(s32 arg0) {
	return D_8080258C_bstnt[arg0];
}

void func_80801E60_bstnt(PlayerState* self) {
	bstnt_entrypoint_3(self);
	_babounce_entrypoint_4(self, 1);
	_babounce_entrypoint_5(self, 0xE9, 0.4082f);
}

void func_80801EA0_bstnt(PlayerState* self) {
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (baanim_isAt(self, 0.5f) != 0) {
		func_800951B4(self);
	}
	if (_babounce_entrypoint_2(self) != 0) {
		func_80800164_bstnt(self);
	}
	if (_babounce_entrypoint_9(self) != 0) {
		nextState = 0x10C;
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

void func_80801F20_bstnt(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bstnt_entrypoint_2(self);
}

s32 bstnt_entrypoint_12(s32 arg0) {
	return D_8080259C_bstnt[arg0];
}

void func_80801F5C_bstnt(PlayerState* self) {
	bstnt_entrypoint_3(self);
	_babounce_entrypoint_4(self, 2);
	_babounce_entrypoint_5(self, 0xE9, 0.4082f);
}

void func_80801F9C_bstnt(PlayerState* self) {
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (_babounce_entrypoint_2(self) != 0) {
		func_80800164_bstnt(self);
	}
	if (_babounce_entrypoint_9(self) != 0) {
		nextState = 0x10C;
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

void func_80802000_bstnt(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bstnt_entrypoint_2(self);
}

s32 bstnt_entrypoint_13(s32 self) {
	return D_808025AC_bstnt[self];
}

void func_8080203C_bstnt(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    bstnt_entrypoint_2(self);
}

void func_80802064_bstnt(PlayerState* self)
{
    bstnt_entrypoint_3(self);
    _bsrest_entrypoint_16(self);
}

void func_8080208C_bstnt(PlayerState* self) {
	BanjoStateId sp1C;

	sp1C = BS_STATE_0_INVALID;
	if (_bsrest_entrypoint_20(self) != 0) {
		sp1C = _bsrest_entrypoint_13(self);
	}
	bstnt_entrypoint_4(self);
	bs_setState(self, sp1C);
}

s32 bstnt_entrypoint_14(s32 arg0) {
	return D_808025BC_bstnt[arg0];
}

void func_808020EC_bstnt(PlayerState* self)
{
    bstnt_entrypoint_2(self);
    func_80090A2C(self);
}

void func_80802114_bstnt(PlayerState* self) {
	bstnt_entrypoint_3(self);
	baanim_playForDuration_loopSmooth(self, 0xE5, 6.5f);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
	baphysics_set_target_horizontal_velocity(self, 0.0f);
	func_800909CC(self);
}

void func_8080217C_bstnt(PlayerState* self) {
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (bastick_getZone(self) > 0) {
		nextState = 0x108;
	}
	if (player_inWater(self) != 0) {
		nextState = 0x111;
	}
	nextState = func_80800218_bstnt(self, nextState);
	bstnt_entrypoint_4(self);
	bs_setState(self, nextState);
}

s32 bstnt_entrypoint_15(s32 arg0) {
	return D_808025CC_bstnt[arg0];
}
