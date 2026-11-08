#include "common.h"

#include "bs/kaz/crouch.h"

extern s32 D_808007C0_bskazcrouch[];

void func_80800000_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_loopSmooth(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f);
    self->unk15C.word = 4;
}

void func_80800034_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_onceSmooth(self, ASSET_141_ANIM_BSKAZCROUCH_UNKNOWN, 3.5f);
    self->unk15C.word = 2;
}

void func_80800068_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_onceSmoothStartingAt(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f, 0.9999f);
    _batimer_set(self, 2, 2.0f);
    self->unk15C.word = 1;
}

void func_808000B4_bskazcrouch(AnimCtrl *anim_ctrl, f32 arg1) {
    anctrl_setDuration(anim_ctrl, ml_map_f(arg1, 0, 180, 0.5, 0.2));
}

void func_808000FC_bskazcrouch(PlayerState *self, s32 arg1) {
    func_800A2CE8(self, 0.41f, 4);
    func_800A2CE8(self, 0.91f, 3);
}

BanjoStateId bskazcrouch_entrypoint_0(PlayerState* self, BanjoStateId arg1) {
    if (bakey_released(self, BUTTON_Z) != 0) {
        arg1 = BS_STATE_BB;
        if (bakey_pressed(self, BUTTON_A) != 0) {
            arg1 = _bskaz_entrypoint_3(self);
        }
    } else {
        if ((bakey_pressed(self, BUTTON_B) != 0) && (ability_getValue(ABILITY_28_HATCH_EGGS) != 0)) {
            arg1 = BS_STATE_C5;
        }
        if (bakey_pressed(self, BUTTON_A) != 0) {
            arg1 = _bskaz_entrypoint_3(self);
        }
        if ((bainput_should_poop_egg(self) != 0) && (func_80094B14(self) != 0)) {
            arg1 = BS_STATE_68;
        }
        if ((bainput_should_shoot_egg(self) != 0) && (func_80094B14(self) != 0)) {
            arg1 = BS_STATE_67;
        }
    }

    return arg1;
}

void bskazcrouch_entrypoint_1(PlayerState *self) {
    AnimCtrl* animCtrl;
    f32 unk0;
    f32 pad0;
    f32 unk1;
    f32 animStart;
    f32 targetYaw;
    s32 unk2;
    f32 unk3;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    unk2 = bs_getPreviousState(self);
    if ((unk2 != 0x67) && (unk2 != 0x68)) {
        animStart = 0;
    } else {
        animStart = 0.8;
    }
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_A8_ANIM_BSKAZCROUCH_UNKNOWN);
    anctrl_setDuration(animCtrl, 0.5);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_setStart(animCtrl, animStart);
    anctrl_start(animCtrl);
    func_8008CA4C(self, 1);
    yaw_setUpdateType(self, 3);
    yaw_setVelocityBounded(self, 350.0f , 14.0f );
    func_8009D2D8(self, 7);
    func_8009CFD8(self, 8.0f);
    baphysics_set_type(self, 3);
    _batimer_set(self, 0, 0.7f);
    _batimer_set(self, 1, 0.2f);
    func_8009BB24(self, &unk1);
    unk3 = sqrtf((unk0 * unk0) + (unk1 * unk1));
    self->unk16C = unk3;
    if (unk3 > 140.0f) {
        func_8009D658(self);
    }
    if (func_800F1EA4(&unk1, &targetYaw) != 0) {
        baphysics_set_target_yaw(self, targetYaw);
    }
    self->unk15C.word = NULL;
}


void bskazcrouch_entrypoint_2(PlayerState* self)
{
	BanjoStateId nextState;
	f32 sp38;
	AnimCtrl* sp34;
	f32 temp_f0;
	s32 pad;
	f32 sp28;
	nextState = BS_STATE_0_INVALID;
	sp34 = baanim_getAnimCtrlPtr(self);
	_batimer_decrement(self, 0);
	_batimer_decrement(self, 1);
	sp38 = ml_map_f(_batimer_get(self, 0), 0.0f, 0.3f, 0.0f, self->unk16C);
	baphysics_set_target_horizontal_velocity(self, sp38);
	if (sp38 > 220.0f)
	{
		_badust_entrypoint_9(self);
	}
	if (sp38 > 160.0f)
	{
		func_8009D658(self);
	}
	if (bastick_distance(self) == 0.0f)
	{
		yaw_setIdeal(self, yaw_get(self));
	}
	sp28 = yaw_getIdeal(self);
	temp_f0 = mlAbsF(func_800F1DCC(sp28, yaw_get(self)));
	switch (self->unk15C.word)
	{
	case 0:
		if (sp38 == 0.0f)
		{
			_batimer_set(self, 2, 2.0f);
			self->unk15C.word = 1;
		}
		break;
	case 1:
		if (temp_f0 != 0.0f)
		{
			func_80800000_bskazcrouch(self);
		}
		else
		{
			_batimer_decrement(self, 2);
			if (_batimer_isZero(self, 2) != 0)
			{
				func_80800034_bskazcrouch(self);
			}
		}
		break;
	case 2:
		if (temp_f0 != 0.0f)
		{
			func_80800000_bskazcrouch(self);
		}
		else if (anctrl_isStopped(sp34) != 0)
		{
			func_80800068_bskazcrouch(self);
		}
		break;
	case 4:
		func_808000B4_bskazcrouch(sp34, temp_f0);
		func_808000FC_bskazcrouch(self, (s32)sp34);
		if (temp_f0 == 0.0f)
		{
			if (anctrl_getAnimTimer(sp34) <= 0.5f)
			{
				anctrl_setSubrange(sp34, 0.0f, 0.5f);
			}
			else
			{
				anctrl_setSubrange(sp34, 0.0f, 1.0f);
			}
			anctrl_setPlaybackType(sp34, 1);
			self->unk15C.word = 3;
		}
		break;
	case 3:
		func_808000B4_bskazcrouch(sp34, temp_f0);
		func_808000FC_bskazcrouch(self, (s32)sp34);
		if (temp_f0 != 0.0f)
		{
			anctrl_setSubrange(sp34, 0.0f, 1.0f);
			anctrl_setPlaybackType(sp34, 2);
			self->unk15C.word = 4;
		}
		else if (anctrl_isStopped(sp34) != 0)
		{
			yaw_setIdeal(self, yaw_get(self));
			func_80800068_bskazcrouch(self);
		}
		break;
	}
	if (func_8008DF18(self) != 0)
	{
		nextState = _badrone_entrypoint_25(self);
	}
	nextState = bskazcrouch_entrypoint_0(self, nextState);
	if ((nextState == BS_STATE_BB) && (_batimer_isNonzero(self, 1) != 0))
	{
		nextState = BS_STATE_0_INVALID;
	}
	if (player_inWater(self) != 0)
	{
		nextState = BS_STATE_15D;
	}
	bs_setState(self, nextState);
}

void bskazcrouch_entrypoint_3(PlayerState *self) {
    _bskaz_entrypoint_2(self);
}


s32 bskazcrouch_entrypoint_4(s32 idx) {
    return D_808007C0_bskazcrouch[idx];
}
