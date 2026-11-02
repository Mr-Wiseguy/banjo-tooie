#include "bs/ban/snooze.h"

extern s32 D_80800A40_bsbansnooze[];
extern s32 D_80800A50_bsbansnooze[];
extern s32 D_80800A60_bsbansnooze[];
extern s32 D_80800A78_bsbansnooze[];
extern s32 D_80800A88_bsbansnooze[];
extern s32 D_80800A98_bsbansnooze[];
extern s32 D_80800AA8_bsbansnooze[];

void func_80800000_bsbansnooze(PlayerState* self)
{
    if (func_8009E74C(self, 0x14) != 0)
    {
        if (_babackpack_get_state(self) != 6)
        {
            _babackpack_set_state(self, 6);
        }
    }
    else
    {
        if (_babackpack_get_state(self) != 1)
        {
            _babackpack_set_state(self, 1);
        }
        func_800A0CD0(self, 1);
        func_80095A40(self);
        bastick_popZone(self);
        func_800A4E30(self);
    }
}

void func_80800098_bsbansnooze(PlayerState* self)
{
    if (func_8009E77C(self, 0x14) == 0)
    {
        func_800A0CD0(self, 0);
        _babackpack_set_state(self, 6);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800959C8(self, 60.0f, 30.0f);
        func_800A4DA4(self, 8);
    }
}

void func_80800128_bsbansnooze(PlayerState* self, f32 arg1) {
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 50.0f, 100.0f) * arg1);
}

void func_8080019C_bsbansnooze(PlayerState* self) {
    if (self->unk15C.bytes[1] != 0) {
        func_80800000_bsbansnooze(self);
        return;
    }
    if (_babackpack_get_state(self) != 1) {
        func_800A0CD0(self, 1);
        _babackpack_set_state(self, 1);
    }
}

void func_808001FC_bsbansnooze(PlayerState* self) {
    self->unk15C.bytes[1] = 0;
    baanim_playForDuration_onceSmooth(self, 0x276, 1.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009DE38(self, 0x583, 1.0f);
    bainput_enable(self, BA_INPUT_1_ROTATE_CAMERA_RIGHT, 0);
}

void func_80800278_bsbansnooze(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bainput_enable(self, BA_INPUT_1_ROTATE_CAMERA_RIGHT, 1);
    if (baanim_isAt(self, 0.18f) != 0) {
        func_8009DF58(self, 0x58C, 1.0f);
    }
    if (baanim_isAt(self, 0.22f) != 0) {
        func_8009DB04(self, 0x3FF, 1.0f, 0x55F0);
    }
    if (baanim_isAt(self, 0.1184f) != 0) {
        func_800A0CD0(self, 0);
        _babackpack_set_state(self, 2);
    }
    if (baanim_isAt(self, 0.3703f) != 0) {
        self->unk15C.bytes[1] = 1;
        func_80800098_bsbansnooze(self);
    }
    if (baanim_isStopped(self) != 0) {
        nextState = BS_STATE_16F_SNOOZE_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbansnooze_entrypoint_0(s32 arg0) {
    return D_80800A40_bsbansnooze[arg0];
}

void func_8080037C_bsbansnooze(PlayerState* self)
{
    func_80800000_bsbansnooze(self);
}

void func_8080039C_bsbansnooze(PlayerState* self) {
    func_80800098_bsbansnooze(self);
    baanim_playForDuration_onceSmooth(self, 0x279, 1.6f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009DF94(self, 0x58D, 1.0f, 0x7530);
}

void func_80800414_bsbansnooze(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.77f) != 0) {
        func_8009DE38(self, 0x584, 1.1f);
    }
    if (baanim_isAt(self, 0.6556f) != 0) {
        _babackpack_set_state(self, 1);
        func_800A0CD0(self, 1);
    }
    if (baanim_isStopped(self) != 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbansnooze_entrypoint_1(s32 arg0) {
    return D_80800A50_bsbansnooze[arg0];
}

void func_808004C0_bsbansnooze(PlayerState* self)
{
    func_80800000_bsbansnooze(self);
}

void func_808004E0_bsbansnooze(PlayerState* self) {
    func_80800098_bsbansnooze(self);
    baanim_playForDuration_loopSmooth(self, 0x278, 0.7f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 8, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 100.0f, 3.5f);
    baanim_setDurationRange(self, 0.1f, 5.0f);
    func_8008C9F0(self, 50.0f, 100.0f, 0.7f, 0.7f);
    func_8008CA30(self, 1.0f);
}

void func_80800588_bsbansnooze(PlayerState* self)
{
	BanjoStateId nextState;
	AnimCtrl* animCtrl;

	animCtrl = baanim_getAnimCtrlPtr(self);
	nextState = BS_STATE_0_INVALID;

	func_80800128_bsbansnooze(self, func_800F3780(anctrl_getAnimTimer(animCtrl), D_80800A60_bsbansnooze, 3));

	if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (func_8009BCD4(self, 3.0f) != 0))
	{
		nextState = BS_STATE_16F_SNOOZE_IDLE;
	}
	if (bakey_released(self, BUTTON_Z) != 0)
	{
		nextState = BS_STATE_172_SNOOZE_EXIT;
	}
	if (player_inWater(self) != 0)
	{
		nextState = BS_STATE_4C_LANDING_IN_WATER;
	}
	bs_setState(self, nextState);
}

s32 bsbansnooze_entrypoint_2(s32 arg0) {
    return D_80800A78_bsbansnooze[arg0];
}

void func_8080064C_bsbansnooze(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_80800000_bsbansnooze(self);
}
void func_80800674_bsbansnooze(PlayerState* self)
{
    func_80800098_bsbansnooze(self);
    _bsdrone_entrypoint_0(self);
}
void func_8080069C_bsbansnooze(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}

s32 bsbansnooze_entrypoint_3(s32 arg0) {
    return D_80800A88_bsbansnooze[arg0];
}

void func_808006D0_bsbansnooze(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_80800000_bsbansnooze(self);
}
void func_808006F8_bsbansnooze(PlayerState* self)
{
    func_80800098_bsbansnooze(self);
    _bsrest_entrypoint_16(self);
}

void func_80800720_bsbansnooze(PlayerState* self)
{
    BanjoStateId var_a1;

    var_a1 = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0)
    {
        var_a1 = BS_STATE_16F_SNOOZE_IDLE;
    }
    bs_setState(self, var_a1);
}

s32 bsbansnooze_entrypoint_4(s32 arg0) {
    return D_80800A98_bsbansnooze[arg0];
}

void func_8080076C_bsbansnooze(PlayerState* self)
{
    func_800951B4(self);
    func_80800000_bsbansnooze(self);
}
void func_80800794_bsbansnooze(PlayerState* self) {
    AnimCtrl* temp_s0;
    s32 temp_s0_2;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    func_80800098_bsbansnooze(self);
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, 0x277);
    anctrl_setDuration(temp_s0, 2.0f);
    func_8008B1C8(temp_s0, 0.6f);
    anctrl_setPlaybackType(temp_s0, 2);
    anctrl_start(temp_s0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 8, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 100.0f, 3.5f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009514C(self);
    _batimer_set(self, 0, 1.0f);
    temp_s0_2 = player_getCurrentHealth(self);
    if (player_getMaxHealth(self) == temp_s0_2) {
        player_affectCurrentHealth(self, 0);
    }
    if (bs_getPreviousState(self) == BS_STATE_170_SNOOZE_IDLE_2) {
        self->unk15C.bytes[0] = 0;
        return;
    }
    self->unk15C.bytes[0] = 1;
}

void func_808008A4_bsbansnooze(PlayerState* self)
{
    BanjoStateId nextState;
    s32 sp28;
    f32 var_f0;
    u8 temp_v0;

    nextState = BS_STATE_0_INVALID;
    if (_batimer_decrement(self, 0) != 0)
    {
        _batimer_set(self, 0, 1.0f);
        sp28 = player_getCurrentHealth(self);
        if (sp28 < player_getMaxHealth(self))
        {
            func_800FC660(8);
            player_affectCurrentHealth(self, 1);
        }
    }
    temp_v0 = self->unk15C.bytes[0];
    if (temp_v0 != 0)
    {
        if (temp_v0 == 1)
        {
            var_f0 = 0.1f;
        }
        else
        {
            var_f0 = 0.01f;
        }
        if (baanim_isAt(self, var_f0) != 0)
        {
            func_8009DEC0(self, 0x441, 0.93f, 1.08f, 0x4E20, 0x55F0);
        }
        if (baanim_isAt(self, 0.5f) != 0)
        {
            func_8009DFD4(self, 0x442, 0.93f, 1.08f, 0x4E20, 0x55F0);
        }
    }
    if (baanim_isAt(self, 0.99f) != 0)
    {
        self->unk15C.bytes[0] = 2;
    }
    if (bakey_released(self, BUTTON_Z) != 0)
    {
        nextState = BS_STATE_172_SNOOZE_EXIT;
    }
    if (player_inWater(self) != 0) {
        nextState = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, nextState);
}

s32 bsbansnooze_entrypoint_5(s32 arg0)
{
    return D_80800AA8_bsbansnooze[arg0];
}
