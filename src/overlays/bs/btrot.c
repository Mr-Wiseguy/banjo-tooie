#include "bs/btrot.h"



extern s32 D_80802E50_bsbtrot[];
extern s32 D_80802E60_bsbtrot[];
extern s32 D_80802E70_bsbtrot[];
extern s32 D_80802E80_bsbtrot[];
extern s32 D_80802E90_bsbtrot[];
extern s32 D_80802EA0_bsbtrot[];
extern s32 D_80802EB0_bsbtrot[];
extern s32 D_80802EC0_bsbtrot[];
extern s32 D_80802ED0_bsbtrot[];
extern s32 D_80802EE0_bsbtrot[];
extern s32 D_80802EF0_bsbtrot[];
extern s32 D_80802F00_bsbtrot[];
extern s32 D_80802F10_bsbtrot[];
extern s32 D_80802F20_bsbtrot[];

void func_808008D0_bsbtrot(PlayerState*);

s32 func_80800000_bsbtrot(PlayerState* self, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (player_wearingClawClambers(self) != 0) {
        return arg4;
    }
    if (player_wearingTurboTrainers(self) != 0) {
        return arg2;
    }
    if (player_wearingSpringyStep(self) != 0) {
        return arg3;
    }
    return arg1;
}

f32 func_80800070_bsbtrot(PlayerState* self, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    if (player_wearingClawClambers(self) != 0) {
        return arg4;
    }
    if (player_wearingTurboTrainers(self) != 0) {
        return arg2;
    }
    if (player_wearingSpringyStep(self) != 0) {
        return arg3;
    }
    return arg1;
}

void func_808000DC_bsbtrot(PlayerState* self, s32 arg1) {
    if (arg1 != 0) {
        func_8009DE38(self, 0x4433, 0.96f);
        return;
    }
    func_8009DE38(self, 0x4433, 1.04f);
}

void func_80800120_bsbtrot(PlayerState* self) {
    if ((bakey_pressed(self, BUTTON_B) != 0) && (func_8008E39C(self) != 0)) {
        _bashoes_entrypoint_6(self, 2);
    }
}

f32 func_80800164_bsbtrot(PlayerState* self) {
    if (func_8008DE24(self) != 0) {
        return 300.0f;
    }
    return func_80800070_bsbtrot(self, 700.0f, 1000.0f, 700.0f, 700.0f);
}

f32 func_808001B8_bsbtrot(PlayerState* self) {
    return func_80800070_bsbtrot(self, 30.0f, 80.0f, 30.0f, 30.0f);
}

f32 func_808001EC_bsbtrot(PlayerState* self) {
    if (func_8008DE24(self) != 0) {
        return 0.7f;
    }
    return func_80800070_bsbtrot(self, 0.34f, 0.29f, 0.7f, 0.53f);
}

f32 func_80800248_bsbtrot(PlayerState* self) {
    if (func_8008DE24(self) != 0) {
        return 0.8f;
    }
    return func_80800070_bsbtrot(self, 0.56f, 0.51f, 1.2f, 1.4f);
}

void func_808002A4_bsbtrot(PlayerState* self, BanjoStateId arg1) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    if (anctrl_getIndex(temp_v0) != arg1) {
        anctrl_setIndex(temp_v0, arg1);
        anctrl_setStart(temp_v0, anctrl_getAnimTimer(temp_v0));
        anctrl_start(temp_v0);
    }
}

void func_80800308_bsbtrot(PlayerState* self)
{
    f32 sp24[3];

    switch (func_8009E6EC(self))
    {
        case 0x12:
            self->unk164.word = 1;
            return;
        case 0x8D:
            self->unk164.word = 1;
            func_8009E830(self, 2);
            return;
        case 0x58:
            if ((self->unk160.word == 0) && (player_wearingClawClambers(self) != 0))
            {
                switch (bs_getCurrentState(self))
                {
                    case 0x16:
                    case 0x95:
                        func_80099A7C(self, sp24);
                        if (_bashoessuck_entrypoint_5(self, sp24) != 0)
                        {
                            self->unk160.word = 1;
                            bs_setState(self, 0x17C);
                            return;
                        }
                        break;
                }
            }
            return;
        default:
            func_80099B94(self);
            break;
    }
}

void func_808003F0_bsbtrot(PlayerState* self) {
    if (func_8009E6EC(self) == 0x8D) {
        self->unk164.word = 1;
        func_80800308_bsbtrot(self);
        return;
    }
    func_80099B94(self);
}

void func_80800438_bsbtrot(PlayerState* self)
{
    f32 sp2C;

    sp2C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp2C, func_808001B8_bsbtrot(self), func_80800164_bsbtrot(self)));
}

void func_808004B4_bsbtrot(PlayerState* self) {
    if ((player_wearingTurboTrainers(self) != 0) && (bastick_getZone(self) == BS_STICK_ZONE_ID_1) && (bastick_getZonePosition(self) > 0.8f)) {
        func_800962B0(self, 1);
        return;
    }
    func_800962B0(self, 0);
}

void func_80800538_bsbtrot(PlayerState* self)
{
    if (func_8009CA70(self, bs_getPreviousState(self), 0x40) == 0)
    {
        _bashoes_entrypoint_15(self);
        bastick_setZoneMax(self, 0, 0.03f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800A0CF4(self, 1);
        func_800A0CE8(self, 1);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        baflag_set(self, BA_FLAG_3);
        func_80094F14(self, 4, 1, 0.24f);
        func_800931AC(self, 2);
        func_8009E4AC(self);
        self->unk160.word = 0;
        self->unk164.word = 0;
    }
}

void func_8080061C_bsbtrot(PlayerState* self)
{
    BanjoStateId sp24;

    sp24 = bs_getNextState(self);
    if (func_8009CA70(self, sp24, 0x40) == 0)
    {
        func_8009E474(self);
        func_800931AC(self, 1);
        bastick_resetZones(self);
        func_800A0CF4(self, 0);
        func_800A0CE8(self, 0);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        baflag_clear(self, BA_FLAG_3);
        if (sp24 != 0x5A) {
            bastatetimer_set(self, BA_STATE_TIMER_ID_3_TURBO_TALON, 0.0f);
        }
        func_808004B4_bsbtrot(self);
        func_800962B0(self, 0);
        func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
        func_80094F14(self, 4, 0, 0.0f);
        _bashoes_entrypoint_14(self);
    }
}

s32 func_80800710_bsbtrot(PlayerState* self) {
    if (self->unk164.word != 0) {
        return 1;
    }
    if (func_8008E39C(self) != 0) {
        return 0;
    }
    return bakey_released(self, BUTTON_Z);
}

BanjoStateId func_8080075C_bsbtrot(PlayerState* self, BanjoStateId arg1) {
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        return arg1;
    }
    if (player_canFly(self) != 0) {
        return BS_STATE_23_FLIGHT_LAUNCH;
    }
    if (player_wearingSpringyStep(self) != 0) {
        return 0x9C;
    }
    if (player_wearingClawClambers(self) != 0) {
        return BS_STATE_95;
    }
    return 8;
}

BanjoStateId func_808007E0_bsbtrot(PlayerState* self, BanjoStateId arg1)
{
    if (bastick_getZone(self) > 0)
    {

        if (self->unk160.word != 0)
        {
            arg1 = 0x17C;
        }
        else
        {
            arg1 = BS_STATE_16_TTROT_WALK;
        }
    }
    if (bainput_should_enter_first_person(self) != 0)
    {
        arg1 = _badrone_entrypoint_24(self);
    }
    if ((self->unk160.word == 0) && (func_8008DD04(self) != 0))
    {
        arg1 = 0x71;
    }
    if (func_80800710_bsbtrot(self) != 0)
    {
        arg1 = BS_STATE_17_TTROT_EXIT;
    }
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = func_8080075C_bsbtrot(self, arg1);
    }
    if ((self->unk160.word == 0) && (func_8008DF18(self) != 0))
    {
        arg1 = 0x45;
    }
    if (player_inWater(self) != 0)
    {
        arg1 = BS_STATE_2D_SWIM_IDLE;
    }
    return arg1;
}

void func_808008D0_bsbtrot(PlayerState* arg0)
{
	AnimCtrl* sp24;
	f32 sp20;
	f32 sp1C;
	s32 sp18;
	sp24 = baanim_getAnimCtrlPtr(arg0);
	sp18 = 1;
	sp20 = 0.7781f;
	sp1C = 0.2781f;
	switch (_bashoes_entrypoint_1(arg0))
	{
	case 3:
		_bashoes_entrypoint_20(arg0);
		break;
	case 4:
		sp18 = 0;
		break;
	case 5:
		sp1C = 0.6583f;
		sp20 = 0.1783f;
		if (anctrl_isAt(sp24, 0.6583f) != 0)
		{
			_bashoes_entrypoint_19(arg0);
		}
		if (anctrl_isAt(sp24, 0.1783f) != 0)
		{
			_bashoes_entrypoint_18(arg0);
		}
		break;
	default:
		if ((anctrl_isAt(sp24, 0.2115f) != 0) || (anctrl_isAt(sp24, 0.7115f) != 0))
		{
			_badust_entrypoint_1(arg0);
		}
		break;
	}
	if (anctrl_isAt(sp24, ml_remainder_f(sp1C + 0.2f, 1.0f)) != 0)
	{
		func_808000DC_bsbtrot(arg0, 1);
	}
	if (anctrl_isAt(sp24, ml_remainder_f(sp20 + 0.2f, 1.0f)) != 0)
	{
		func_808000DC_bsbtrot(arg0, 0);
	}
	if (sp18 != 0)
	{
		func_800A2CE8(arg0, sp1C, 4);
		func_800A2CE8(arg0, sp20, 3);
	}
	else
	{
		func_800A2D2C(arg0, sp1C, 4);
		func_800A2D2C(arg0, sp20, 3);
	}
}

void bsbtrot_entrypoint_0(PlayerState* self) {
    func_80800538_bsbtrot(self);
    func_808004B4_bsbtrot(self);
    baanim_playForDuration_once(self, func_80800000_bsbtrot(self, 0x16, 0x16, 0x29F, 0xA0), 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009D874(self);
    bainput_enable(self, BA_INPUT_0_ROTATE_CAMERA_LEFT, 0);
}


void bsbtrot_entrypoint_1(PlayerState* self)
{
    BanjoStateId var_s0;
    AnimCtrl* sp20;

    var_s0 = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    bainput_enable(self, BA_INPUT_0_ROTATE_CAMERA_LEFT, 1);
    func_8009D3A8(self, 1);
    if (anctrl_isStopped(sp20) != 0) {
        var_s0 = 0x15;
    }
    if (anctrl_getAnimTimer(sp20) > 0.5f) {
        var_s0 = func_808007E0_bsbtrot(self, var_s0);
    }
    bs_setState(self, var_s0);
}

void bsbtrot_entrypoint_2(PlayerState* self) {
    bainput_enable(self, BA_INPUT_0_ROTATE_CAMERA_LEFT, 1);
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_3(s32 arg0) {
    return D_80802E50_bsbtrot[arg0];
}

s32 func_80800C20_bsbtrot(PlayerState* self) {
    return func_80800000_bsbtrot(self, 0x26, 0x26, 0x29B, 0x86);
}

void bsbtrot_entrypoint_4(PlayerState* self) {
    if (player_wearingSpringyStep(self) != 0) {
        baanim_playForDuration_loopSmooth(self, 0x29B, 1.3f);
    }
    else if (player_wearingClawClambers(self) != 0) {
        baanim_playForDuration_loopSmooth(self, 0x86, 1.3f);
    }
    else {
        baanim_playForDuration_loopSmooth(self, 0x26, 1.2f);
    }
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_80800538_bsbtrot(self);
}

void bsbtrot_entrypoint_5(PlayerState* self) {
    func_808002A4_bsbtrot(self, func_80800C20_bsbtrot(self));
    func_80800120_bsbtrot(self);
    func_808004B4_bsbtrot(self);
    if (player_wearingTurboTrainers(self) != 0) {
        _bashoes_entrypoint_20(self);
    }
    func_8009D3A8(self, 1);
    bs_setState(self, func_800A02DC(self, func_808007E0_bsbtrot(self, BS_STATE_0_INVALID)));
}

void bsbtrot_entrypoint_6(PlayerState* self)
{
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_7(s32 arg0) {
    return D_80802E60_bsbtrot[arg0];
}

s32 func_80800DC4_bsbtrot(PlayerState* self) {
    return func_80800000_bsbtrot(self, 0x15, 0x44, 0x29C, 0xA1);
}

void func_80800DF4_bsbtrot(PlayerState* self) {
    s32 pad[2];
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    sp2C = func_808001B8_bsbtrot(self);
    sp30 = func_80800164_bsbtrot(self);
    sp34 = func_80800248_bsbtrot(self);
    func_8008C9F0(self, sp2C, sp30, sp34, func_808001EC_bsbtrot(self));
    if (func_8008E1A0(self) != 0)
    {
        func_8008CA30(self, ml_map_f(func_8009BBB8(self), 0.0f, 1.0f, 0.6f, 0.9f));
        return;
    }
    func_8008CA30(self, 1.0f);
}

void bsbtrot_entrypoint_8(PlayerState* self) {
    baanim_playForDuration_loopSmooth(self, func_80800DC4_bsbtrot(self), 0.53f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_80800538_bsbtrot(self);
    func_80800DF4_bsbtrot(self);
}

void bsbtrot_entrypoint_9(PlayerState* self) {
    BanjoStateId var_s1;

    var_s1 = BS_STATE_0_INVALID;
    func_80800120_bsbtrot(self);
    func_80800DF4_bsbtrot(self);
    func_808004B4_bsbtrot(self);
    func_808002A4_bsbtrot(self, func_80800DC4_bsbtrot(self));
    func_8009D3A8(self, 1);
    func_80800438_bsbtrot(self);
    func_808008D0_bsbtrot(self);
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (func_8009BCD4(self, 1.0f) != 0)) {
        var_s1 = 0x15;
    }
    if (func_8008DD04(self) != 0) {
        var_s1 = 0x71;
    }
    if (func_80800710_bsbtrot(self) != 0) {
        var_s1 = BS_STATE_17_TTROT_EXIT;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        var_s1 = func_8080075C_bsbtrot(self, var_s1);
    }
    if (func_8008DF18(self) != 0) {
        var_s1 = 0x45;
    }
    if (player_inWater(self) != 0) {
        var_s1 = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, func_800A02DC(self, var_s1));
}

void bsbtrot_entrypoint_10(PlayerState* self)
{
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_11(s32 arg0) {
    return D_80802E70_bsbtrot[arg0];
}

void bsbtrot_entrypoint_12(PlayerState* self) {
    s32 pad[2];
    f32 sp24;
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x27);
    anctrl_setDuration(temp_v0, 1.4f);
    func_8008B1C8(temp_v0, 0.1f);
    anctrl_setStart(temp_v0, 0.2f);
    anctrl_setSubrange(temp_v0, 0.0f, 0.4002f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_80800538_bsbtrot(self);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
    func_8009D2D8(self, 3);
    baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800438_bsbtrot(self);
    sp24 = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp24, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 693.5f);
    baphysics_set_gravity(self, -1200.0f);
    func_8009DE38(self, 0x4432, 1.0f);
    self->unk15C.word = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_13.s")

void bsbtrot_entrypoint_14(PlayerState* self)
{
    baphysics_reset_gravity(self);
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_15(s32 arg0)
{
    return D_80802E80_bsbtrot[arg0];
}

void func_8080163C_bsbtrot(PlayerState* self)
{
    s16 temp_v0;

    temp_v0 = func_8009E6EC(self);
    if ((temp_v0 != 0x1A) && (temp_v0 != 0x1B) && (temp_v0 != 0x29) && (temp_v0 != 0x2B))
    {
        func_80099B94(self);
    }
}

void bsbtrot_entrypoint_16(PlayerState* self)
{
    baanim_playForDuration_once(self, 7, 0.6f);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800931AC(self, 1);
}

void bsbtrot_entrypoint_17(PlayerState* self)
{
    BanjoStateId var_s1;

    var_s1 = BS_STATE_0_INVALID;
    if (baanim_isStopped(self) != 0)
    {
        var_s1 = BS_STATE_1_IDLE;
    }
    if ((baanim_getTimer(self) > 0.3f) && (bastick_getZone(self) != BS_STICK_ZONE_ID_0)) {
        var_s1 = BS_STATE_2_SLOW_WALK;
    }
    if (func_8008DD04(self) != 0)
    {
        var_s1 = BS_STATE_2F_FALL;
    }
    if (func_8008E124(self) != 0)
    {
        var_s1 = _badata_entrypoint_30(self, func_8009CC68(self));
    }
    bs_setState(self, var_s1);
}

void bsbtrot_entrypoint_18(PlayerState* self)
{
    if (func_8009CA70(self, bs_getNextState(self), 0x40) != 0)
    {
        func_800931AC(self, 2);
    }
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_19(s32 arg0)
{
    return D_80802E90_bsbtrot[arg0];
}

void bsbtrot_entrypoint_20(PlayerState* self)
{
    AnimCtrl* sp34;
    s32 pad;
    f32 sp2C;

    sp34 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(sp34);
    anctrl_setIndex(sp34, 0x27);
    anctrl_setStart(sp34, 0.069f);
    anctrl_setPlaybackType(sp34, 3);
    anctrl_start(sp34);
    func_80800538_bsbtrot(self);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_3_LOCKED_ROTATION);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    func_800A0CF4(self, 1);
    func_800A0CE8(self, 1);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009D658(self);
    self->unk16C = 1.0f;
}

void bsbtrot_entrypoint_21(PlayerState* self) {
    BanjoStateId nextState;
    s32 pad[2];
    f32 sp38;
    f32 sp34;

    nextState = BS_STATE_0_INVALID;
    func_808004B4_bsbtrot(self);
    if (player_wearingTurboTrainers(self) != 0)
    {
        _bashoes_entrypoint_20(self);
    }
    func_8009D658(self);
    self->unk16C = ml_max_f(self->unk16C - time_getDelta(), 0.0f);
    if (func_8008DF18(self) != 0)
    {
        func_800963C0(self, &sp38);
        func_800F1EA4(&sp38, &sp34);
        func_8009D3A8(self, 1);
        baphysics_set_target_horizontal_velocity(self, ml_map_f(func_8009BFD8(self), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(self, sp34);
        _badust_entrypoint_1(self);
    }
    else
    {
        nextState = 0x15;
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if ((self->unk16C == 0.0f) && (bakey_pressed(self, BUTTON_A) != 0) && (player_isStable(self) != 0)) {
        nextState = func_8080075C_bsbtrot(self, nextState);
    }
    bs_setState(self, nextState);
}

void bsbtrot_entrypoint_22(PlayerState* self)
{
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_23(s32 arg0)
{
    return D_80802EA0_bsbtrot[arg0];
}

void bsbtrot_entrypoint_24(PlayerState* self) {
    s32 pad[2];
    f32 sp2C;
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x27);
    anctrl_setDuration(temp_v0, 1.4f);
    anctrl_setStart(temp_v0, 0.4653f);
    anctrl_setPlaybackType(temp_v0, 3);
    anctrl_start(temp_v0);
    func_80800538_bsbtrot(self);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800438_bsbtrot(self);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    self->unk15C.word = 0;
}

void bsbtrot_entrypoint_25(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_808004B4_bsbtrot(self);
    if (player_wearingTurboTrainers(self) != 0) {
        _bashoes_entrypoint_20(self);
    }
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        func_8009B7C0(self);
    }
    else {
        func_80800438_bsbtrot(self);
    }
    func_8009BB24(self, sp24);
    switch (self->unk15C.word) {
    case 0:
        if (func_8008DF8C(self, 0x8C) != 0) {
            anctrl_setSubrange(sp30, 0.0f, 0.7328f);
            anctrl_setDuration(sp30, 1.4f);
            anctrl_setPlaybackType(sp30, 1);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        func_8009D3A8(self, 1);
        if (player_isStable(self) != 0) {
            func_8009FE58(self);
            anctrl_setSubrange(sp30, 0.0f, 0.8798f);
            anctrl_setDuration(sp30, 0.9f);
            anctrl_setPlaybackType(sp30, 1);
            func_8009D2D8(self, 1);
            if (baphysics_get_target_horizontal_velocity(self) > 220.0f) {
                func_8009D658(self);
            }
            _badust_entrypoint_1(self);
            self->unk15C.word = 2;
        }
        break;
    case 2:
        if (baphysics_get_target_horizontal_velocity(self) > 220.0f) {
            func_8009D658(self);
        }
        func_8009D3A8(self, 1);
        if (anctrl_isStopped(sp30) != 0) {
            anctrl_setSubrange(sp30, 0.0f, 0.8898f);
            anctrl_setDuration(sp30, 2.0f);
            anctrl_setPlaybackType(sp30, 1);
            self->unk15C.word = 3;
        }
        _badust_entrypoint_1(self);
        break;
    case 3:
        if (baphysics_get_target_horizontal_velocity(self) > 220.0f) {
            func_8009D658(self);
        }
        func_8009D3A8(self, 1);
        if (anctrl_isStopped(sp30) != 0) {
            anctrl_setSubrange(sp30, 0.0f, 1.0f);
            anctrl_setDuration(sp30, 1.2f);
            anctrl_setPlaybackType(sp30, 1);
            self->unk15C.word = 4;
        }
        _badust_entrypoint_1(self);
        break;
    case 4:
        if (baphysics_get_target_horizontal_velocity(self) > 220.0f) {
            func_8009D658(self);
        }
        func_8009D3A8(self, 1);
        if (anctrl_isStopped(sp30) != 0) {
            nextState = 0x15;
        }
        break;
    }
    if (player_inWater(self) != 0) {
        nextState = BS_STATE_4C_LANDING_IN_WATER;
    }
    if (player_isStable(self) != 0) {
        if (bakey_pressed(self, BUTTON_A) != 0) {
            nextState = func_8080075C_bsbtrot(self, nextState);
        }
        if (func_8008DF18(self) != 0) {
            nextState = 0x45;
        }
    }
    if (func_8008E260(self) != 0) {
        nextState = BS_STATE_3D_FALL_TUMBLING;
    }
    bs_setState(self, nextState);
}

void bsbtrot_entrypoint_26(PlayerState* self)
{
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_27(s32 arg0) {
    return D_80802EB0_bsbtrot[arg0];
}

void bsbtrot_entrypoint_28(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_8080061C_bsbtrot(self);
}
void bsbtrot_entrypoint_29(PlayerState* self) {
    func_80800538_bsbtrot(self);
    _bsrest_entrypoint_18(self);
    if (player_wearingSpringyStep(self) != 0) {
        baanim_playForDuration_loopSmooth(self, 0x29B, 1.3f);
    }
    else if (player_wearingClawClambers(self) != 0) {
        baanim_playForDuration_loopSmooth(self, 0x86, 1.3f);
    }
    else {
        baanim_playForDuration_loopSmooth(self, 0x26, 1.2f);
    }
    func_800931AC(self, 2);
}

void bsbtrot_entrypoint_30(PlayerState* self) {
    BanjoStateId nextState;

    nextState = 0;
    func_808004B4_bsbtrot(self);
    func_8009D3A8(self, 1);
    if (self->unk164.word != 0) {
        nextState = ASSET_17_ANIM_BSBFLAP;
    }
    else if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, nextState);
}

s32 bsbtrot_entrypoint_31(s32 arg0) {
    return D_80802EC0_bsbtrot[arg0];
}

void bsbtrot_entrypoint_32(PlayerState* self) {
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];

    func_80800538_bsbtrot(self);
    _bareact_entrypoint_1(self, func_80099A58(self));
    baanim_playForDuration_once(self, 0x66, 1.1f);
    func_8009D89C(self, 1.0f);
    player_getCoords(self, sp40);
    func_800A32C4(self, sp34);
    func_800F1E6C(sp34, sp40, &sp4C);
    yaw_setIdeal(self, func_800136E4(sp4C + 180.0f));
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, _bareact_entrypoint_4(self));
    baphysics_set_target_yaw(self, sp4C);
    baphysics_set_horizontal_velocity(self, sp4C, baphysics_get_target_horizontal_velocity(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    if (_bareact_entrypoint_2(self) == 2) {
        baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
    }
    baphysics_set_vertical_velocity(self, _bareact_entrypoint_3(self));
    baphysics_set_gravity(self, _bareact_entrypoint_5(self));
    func_8008E944(self);
    func_8009514C(self);
}

void bsbtrot_entrypoint_33(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bareact_entrypoint_2(self) == 2)
    {
        func_80800438_bsbtrot(self);
    }
    if (baanim_isAt(self, 0.3f) != 0)
    {
        func_800951B4(self);
    }
    if (func_8008E260(self) != 0)
    {
        nextState = BS_STATE_3D_FALL_TUMBLING;
    }
    if ((player_isStable(self) != 0) && (baanim_isStopped(self) != 0))
    {
        nextState = 0x15;
    }
    if ((anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0) && (player_inWater(self) != 0))
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, nextState);
}

void bsbtrot_entrypoint_34(PlayerState* self) {
    func_8009BD88(self);
    baphysics_reset_gravity(self);
    func_8008E95C(self);
    func_800951B4(self);
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_35(s32 arg0) {
    return D_80802ED0_bsbtrot[arg0];
}

void bsbtrot_entrypoint_36(PlayerState* self)
{
    func_808004B4_bsbtrot(self);
    func_80800538_bsbtrot(self);
    _bsdrone_entrypoint_0(self);
}

void bsbtrot_entrypoint_37(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
    func_808004B4_bsbtrot(self);
}
void bsbtrot_entrypoint_38(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_8080061C_bsbtrot(self);
}
s32 bsbtrot_entrypoint_39(s32 arg0) {
    return D_80802EE0_bsbtrot[arg0];
}

void func_80802380_bsbtrot(PlayerState* self, s32 arg1)
{
    switch (arg1)
    {
    case 0:
        baphysics_reset_gravity(self);
        break;
    case 1:
        baanim_playForDuration_onceSmooth(self, 0x298, 1.9f);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        baphysics_set_gravity(self, -2700.0f);
        break;
    case 2:
        _bashoes_entrypoint_17(self);
        baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
        baphysics_set_vertical_velocity(self, 2383.0f);
        func_8009DEC0(self, 0x4598, 0.95f, 1.05f, 0x7FFF, 0x7FFF);
        break;
    }
    self->unk15C.word = arg1;
}

void bsbtrot_entrypoint_40(PlayerState* self) {
    func_80802380_bsbtrot(self, NULL);
    _bashoes_entrypoint_6(self, 2);
    _bashoes_entrypoint_5(self, 0);
    func_8080061C_bsbtrot(self);
}

void bsbtrot_entrypoint_41(PlayerState* self) {
    func_80800538_bsbtrot(self);
    _bashoes_entrypoint_5(self, 1);
    self->unk15C.word = 0;
    func_80802380_bsbtrot(self, 1);
}

void bsbtrot_entrypoint_42(PlayerState* self) {
    BanjoStateId sp24;
    s32 temp_v0;

    sp24 = BS_STATE_0_INVALID;
    temp_v0 = self->unk15C.word;
    switch (temp_v0) {                              /* irregular */
    case 1:
        if (baanim_isAt(self, 0.4744f) != 0) {
            func_80802380_bsbtrot(self, 2);
        }
        break;
    case 2:
        if (baanim_getTimer(self) < 0.87f) {
            _bashoes_entrypoint_16(self);
        }
        func_80800438_bsbtrot(self);
        if (baanim_isStopped(self) != 0) {
            sp24 = BS_STATE_2F_FALL;
        }
        break;
    }
    bs_setState(self, sp24);
}

s32 bsbtrot_entrypoint_43(s32 arg0) {
    return D_80802EF0_bsbtrot[arg0];
}

void func_808025D8_bsbtrot(PlayerState* self, s32 arg1) {
    AnimCtrl* temp_a0;
    s32 pad[2];
    f32 sp28;

    temp_a0 = baanim_getAnimCtrlPtr(self);
    switch (arg1)
    {
    case 1:
        anctrl_reset(temp_a0);
        anctrl_setIndex(temp_a0, 0x11F);
        anctrl_setDuration(temp_a0, 0.9f);
        func_8008B1C8(temp_a0, 0.1f);
        anctrl_setStart(temp_a0, 0.1734f);
        anctrl_setSubrange(temp_a0, 0.0f, 0.4f);
        anctrl_setPlaybackType(temp_a0, 1);
        anctrl_start(temp_a0);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
        if (bastick_distance(self) != 0.0f) {
            yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
        }
        baphysics_set_target_yaw(self, yaw_getIdeal(self));
        func_80800438_bsbtrot(self);
        sp28 = yaw_getIdeal(self);
        baphysics_set_horizontal_velocity(self, sp28, baphysics_get_target_horizontal_velocity(self));
        baphysics_set_vertical_velocity(self, 693.0f);
        baphysics_set_gravity(self, -1200.0f);
        func_8009DE38(self, 0x4432, 1.0f);
        break;
    case 2:
        baanim_setEndAndDuration(self, 0.6f, 4.0f);
        break;
    case 3:
        baanim_setEndAndDuration(self, 0.7734f, 0.9f);
        break;
    case 4:
        func_8009FE58(self);
        baanim_setEnd(self, 1.0f);
        break;
    }
    self->unk15C.word = arg1;
}

void bsbtrot_entrypoint_44(PlayerState* self)
{
    baphysics_reset_gravity(self);
    func_8080061C_bsbtrot(self);
}
void bsbtrot_entrypoint_45(PlayerState* self) {
    func_80800538_bsbtrot(self);
    self->unk15C.word = 0;
    func_808025D8_bsbtrot(self, 1);
}

void bsbtrot_entrypoint_46(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_808004B4_bsbtrot(self);
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        func_8009B7C0(self);
    }
    else {
        func_80800438_bsbtrot(self);
    }
    func_8009BB24(self, sp24);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp24[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word) {
    case 1:
        if (anctrl_isStopped(sp30) != 0) {
            func_808025D8_bsbtrot(self, 2);
        }
        break;
    case 2:
        if (func_8008DF8C(self, 0x82) != 0) {
            func_808025D8_bsbtrot(self, 3);
        }
        break;
    case 3:
        func_8009D3A8(self, 1);
        if (player_isStable(self) != 0) {
            func_808025D8_bsbtrot(self, 4);
        }
        break;
    case 4:
        if (anctrl_isStopped(sp30) != 0) {
            nextState = 0x15;
        }
        nextState = func_808007E0_bsbtrot(self, nextState);
        break;
    }
    if (player_isStable(self) == 0) {
        if (func_8008E260(self) != 0) {
            nextState = BS_STATE_3D_FALL_TUMBLING;
        }
        if (player_inWater(self) != 0) {
            nextState = BS_STATE_4C_LANDING_IN_WATER;
        }
    }
    bs_setState(self, nextState);
}

s32 bsbtrot_entrypoint_47(s32 arg0) {
    return D_80802F00_bsbtrot[arg0];
}

void func_808029D8_bsbtrot(PlayerState* self) {
    if (func_8009CA70(self, bs_getPreviousState(self), 0x800) == 0) {
        _bashoessuck_entrypoint_3((s32)self);
        self->unk160.word = 1;
        func_80092880(self, 0);
        func_800A2018(self, 3);
        func_800A4DA4(self, 0x19);
    }
}

void func_80802A4C_bsbtrot(PlayerState* self) {
    if (func_8009CA70(self, bs_getNextState(self), 0x800) == 0) {
        _bashoessuck_entrypoint_2(self);
        self->unk160.word = 0;
        func_80092880(self, 1);
        func_800A2018(self, -1);
        func_800A4E30(self);
    }
}

void bsbtrot_entrypoint_48(PlayerState* self) {
    func_80800538_bsbtrot(self);
    func_808029D8_bsbtrot(self);
    baanim_playForDuration_loopSmooth(self, func_80800DC4_bsbtrot(self), 0.53f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 9, 0x12);
    func_80800DF4_bsbtrot(self);
}

void bsbtrot_entrypoint_49(PlayerState* self) {
    BanjoStateId nextState;
    f32 sp28[3];

    nextState = BS_STATE_0_INVALID;
    func_800956B8(self);
    func_80800120_bsbtrot(self);
    func_80800DF4_bsbtrot(self);
    func_808004B4_bsbtrot(self);
    func_808002A4_bsbtrot(self, func_80800DC4_bsbtrot(self));
    _bashoessuck_entrypoint_4(self);
    func_80800438_bsbtrot(self);
    func_808008D0_bsbtrot(self);
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (func_8009BCD4(self, 1.0f) != 0))
    {
        nextState = 0x17B;
    }
    if ((func_80800710_bsbtrot(self) != 0) || (player_wearingClawClambers(self) == 0))
    {
        nextState = BS_STATE_17_TTROT_EXIT;
    }
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        nextState = func_8080075C_bsbtrot(self, nextState);
    }
    if (player_inWater(self) != 0) {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (_bamovespline_entrypoint_1(self, 100.0f) != 0)
    {
        nextState = 0x71;
    }
    if (_bamovespline_entrypoint_3(self) != 0)
    {
        nextState = BS_STATE_16_TTROT_WALK;
    }
    if (_bamovespline_entrypoint_2(self) != 0)
    {

        if (_bashoes_entrypoint_2(self) == 2)
        {
            _bashoessuck_entrypoint_1(self, sp28);
            nextState = _badrone_entrypoint_23(self, sp28);
        }
        else
        {
            nextState = BS_STATE_16_TTROT_WALK;
        }
    }
    bs_setState(self, nextState);
}

void bsbtrot_entrypoint_50(PlayerState* self)
{
    func_80802A4C_bsbtrot(self);
    func_8080061C_bsbtrot(self);
}
s32 bsbtrot_entrypoint_51(s32 arg0) {
    return D_80802F10_bsbtrot[arg0];
}

void bsbtrot_entrypoint_52(PlayerState* self) {
    func_80800538_bsbtrot(self);
    func_808029D8_bsbtrot(self);
    baanim_playForDuration_loopSmooth(self, 0x86, 1.3f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 9, 0x12);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void bsbtrot_entrypoint_53(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800120_bsbtrot(self);
    func_808004B4_bsbtrot(self);
    _bashoessuck_entrypoint_4(self);
    if (player_wearingClawClambers(self) == 0) {
        nextState = BS_STATE_17_TTROT_EXIT;
    }
    bs_setState(self, func_808007E0_bsbtrot(self, nextState));
}

void bsbtrot_entrypoint_54(PlayerState* self)
{
    func_80802A4C_bsbtrot(self);
    func_8080061C_bsbtrot(self);
}

s32 bsbtrot_entrypoint_55(s32 arg0) {
    return D_80802F20_bsbtrot[arg0];
}