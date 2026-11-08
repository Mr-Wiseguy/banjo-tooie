#include "bs/blongleg.h"

extern s32 D_80801470_bsblongleg[];
extern s32 D_80801480_bsblongleg[];
extern s32 D_80801490_bsblongleg[];
extern s32 D_808014A0_bsblongleg[];
extern s32 D_808014B0_bsblongleg[];
extern s32 D_808014C0_bsblongleg[];
extern s32 D_808014D0_bsblongleg[];
extern s32 D_808014E0_bsblongleg[];

/* .code */
s32 func_80800000_bsblongleg(PlayerState* self)
{
    return player_inWater(self);
}

void func_80800020_bsblongleg(PlayerState* self, s32 arg1)
{
    if (arg1 != 0) {
        func_8009DE38(self, 0x4433, 0.88f);
        return;
    }
    func_8009DE38(self, 0x4433, 0.96f);
}

void func_80800064_bsblongleg(PlayerState* self)
{
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 80.0f, 500.0f));
}

void func_808000C8_bsblongleg(PlayerState* self)
{
    _baalarm_entrypoint_3(self, bastatetimer_getPrevious(self, 2), bastatetimer_get(self, 2));
    if (bastatetimer_isAt(self, 2, 0.01) != 0) {
        func_8009DE38(self, 0x3EB, 1.0f);
    }
}

void func_8080013C_bsblongleg(PlayerState* self)
{
    if (func_8009E77C(self, 8) == 0) {
        func_8009E53C(self, 1, -50.0f);
        bastick_setZoneMax(self, 0, 0.03f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800A0CF4(self, 1);
        func_800A0CE8(self, 1);
        func_800A0DD0(self, 1);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        baflag_set(self, BA_FLAG_3);
        func_800931AC(self, 2);
        _baalarm_new(self);
    }
}

void func_80800204_bsblongleg(PlayerState* self)
{
    if (func_8009E74C(self, 8) == 0) {
        _baalarm_free(self);
        func_8009E53C(self, 1, 0.0f);
        bastick_resetZones(self);
        func_800A0CF4(self, 0);
        func_800A0CE8(self, 0);
        func_800A0DD0(self, 0);
        func_800931AC(self, 1);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        bastatetimer_clear(self, 2);
        func_800C77DC(1);
        baflag_clear(self, BA_FLAG_3);
        _batimer_incrementBy(self, 4, 0.5f);
        func_808000C8_bsblongleg(self);
    }
}

void func_808002D8_bsblongleg(PlayerState* self)
{
    AnimCtrl* anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x40);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    bastatetimer_set(self, BA_STATE_TIMER_ID_2_LONGLEG, func_800A3394(self));
    func_800C77DC(2);
    func_800C3BDC(self->unk160.bytes[0]);
    self->unk15C.word = 1;
}

void func_80800378_bsblongleg(PlayerState* self)
{
    AnimCtrl* anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x16);
    anctrl_setDuration(anim_ctrl, 0.5f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    self->unk15C.word = 0;
}

void bsblongleg_entrypoint_0(PlayerState* self)
{
    u8 temp_v0;

    temp_v0 = func_800C2E04();
    self->unk160.bytes[0] = temp_v0;
    func_800C301C(temp_v0, 0x41D);
    func_800C330C(self->unk160.bytes[0], 3);
    func_800C3730(self->unk160.bytes[0], 0.8f, 1.9f, 1.2f);
    baflag_clear(self, BA_FLAG_E_TOUCHING_WADING_BOOTS);
    if (func_8009CA70(self, bs_getPreviousState(self), 0x40)) {
        func_808002D8_bsblongleg(self);
    } else {
        func_80800378_bsblongleg(self);
    }
    func_8009FFD8(self, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8080013C_bsblongleg(self);
    func_8009D874(self);
}

void bsblongleg_entrypoint_1(PlayerState* self)
{
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_808000C8_bsblongleg(self);
    func_8009D2F0(self, 1, 0.5f);
    switch (self->unk15C.word)
    {
        case 0:
            if (anctrl_isStopped(anim_ctrl))
            {
                func_808002D8_bsblongleg(self);
            }
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl))
            {
                next_state = 0x26;
            }
            break;
    }
    bs_setState(self, next_state);
}

void bsblongleg_entrypoint_2(PlayerState* self)
{
    func_80800204_bsblongleg(self);
    func_800C2FDC(self->unk160.bytes[0]);
}

s32 bsblongleg_entrypoint_3(s32 arg0)
{
    return D_80801470_bsblongleg[arg0];
}

void bsblongleg_entrypoint_4(PlayerState* self)
{
    baanim_playForDuration_loopSmooth(self, 0x41, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800931AC(self, 2);
    func_8080013C_bsblongleg(self);
}

void bsblongleg_entrypoint_5(PlayerState* self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_808000C8_bsblongleg(self);
    func_8009D2F0(self, 1, 0.5f);
    if (bainput_should_enter_first_person(self) != 0)
    {
        next_state = _badrone_entrypoint_24(self);
    }
    if (bakey_pressed(self, BUTTON_B) != 0)
    {
        bastatetimer_clear(self, BA_STATE_TIMER_ID_2_LONGLEG);
    }
    if (bastick_getZone(self) > 0)
    {
        next_state = 0x27;
    }
    if (func_8008DF18(self))
    {
        next_state = 0x55;
    }
    if (bakey_pressed(self, BUTTON_A) && player_isStable(self))
    {
        next_state = 0x28;
    }
    if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG))
    {
        next_state = 0x29;
    }
    if (func_80800000_bsblongleg(self))
    {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

void bsblongleg_entrypoint_6(PlayerState* self)
{
    func_80800204_bsblongleg(self);
}

s32 bsblongleg_entrypoint_7(s32 arg0)
{
    return D_80801480_bsblongleg[arg0];
}

void bsblongleg_entrypoint_8(PlayerState* self)
{
    AnimCtrl* sp24;
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    sp24 = temp_v0;
    anctrl_reset(temp_v0);
    anctrl_setIndex(sp24, 0x42);
    anctrl_setPlaybackType(sp24, 2);
    anctrl_start(sp24);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8008C9F0(self, 80.0f, 500.0f, 1.0f, 0.8f);
}

void bsblongleg_entrypoint_9(PlayerState* self) {
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_808000C8_bsblongleg(self);
    func_8009D2F0(self, 1, 0.5f);
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    if (anctrl_isAt(anim_ctrl, 0.7781f))
    {
        func_80800020_bsblongleg(self, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2781f))
    {
        func_80800020_bsblongleg(self, 1);
    }
    func_80800064_bsblongleg(self);
    if (bakey_pressed(self, BUTTON_B) && (baphysics_get_target_horizontal_velocity(self) == 0.0f))
    {
        bastatetimer_clear(self, BA_STATE_TIMER_ID_2_LONGLEG);
    }
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && func_8009BCD4(self, 1.0f)) {
        next_state = 0x26;
    }
    if (func_8008DF18(self)) {
        next_state = 0x55;
    }
    if (bakey_pressed(self, BUTTON_A) && player_isStable(self))
    {
        next_state = 0x28;
    }
    if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG))
    {
        next_state = 0x29;
    }
    if (func_80800000_bsblongleg(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

void bsblongleg_entrypoint_10(PlayerState* self)
{
    func_80800204_bsblongleg(self);
}

s32 bsblongleg_entrypoint_11(s32 arg0)
{
    return D_80801490_bsblongleg[arg0];
}

void func_80800994_bsblongleg(PlayerState* self)
{
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    func_8008B188(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x40);
    anctrl_setDuration(temp_v0, 0.4f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    self->unk15C.word = 0;
}

void func_80800A18_bsblongleg(PlayerState* self)
{
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 7);
    anctrl_setDuration(temp_v0, 0.3f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    self->unk15C.word = 1;
}

void bsblongleg_entrypoint_12(PlayerState* self)
{
    u8 temp_v0;

    func_80800994_bsblongleg(self);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    func_8009D2D8(self, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    temp_v0 = func_800C2E04();
    self->unk160.bytes[0] = temp_v0;
    func_800C301C(temp_v0, 0x41D);
    func_800C330C(self->unk160.bytes[0], 3);
    func_800C3730(self->unk160.bytes[0], 1.4f, 0.4f, -1.2f);
}

void bsblongleg_entrypoint_13(PlayerState* self) {
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_8009D3A8(self, 1);
    switch (self->unk15C.word)
    {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.68f) != 0) {
                func_800C3BDC(self->unk160.bytes[0]);
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_80800A18_bsblongleg(self);
            }
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = BS_STATE_1_IDLE;
            }
            break;
    }
    if (func_80800000_bsblongleg(self) != 0) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

void bsblongleg_entrypoint_14(PlayerState* self) {
    func_800C2FDC(self->unk160.bytes[0]);
    func_80800204_bsblongleg(self);
}

s32 bsblongleg_entrypoint_15(s32 arg0) {
    return D_808014A0_bsblongleg[arg0];
}

void bsblongleg_entrypoint_16(PlayerState* self)
{
    f32 rotation[3];
    AnimCtrl* anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    self->unk16C = 0.14f;
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x3D);
    func_8008B1C8(anim_ctrl, 0.134f);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setStart(anim_ctrl, self->unk16C);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.42f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800064_bsblongleg(self);
    rotation[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, rotation[0], baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 400.0f);
    baphysics_set_gravity(self, -800.0f);
    func_8009DE38(self, 0x4432, 0.9f);
    self->unk15C.word = 0;
}

void bsblongleg_entrypoint_17(PlayerState* self) {
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;
    f32 sp34[3];
    f32 temp_f2;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_808000C8_bsblongleg(self);
    func_80800064_bsblongleg(self);
    func_8009BB24(self, sp34);
    if ((bakey_released(self, 8) != 0) && (sp34[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    temp_f2 = player_getCoordVertical(self) - player_getGroundHeight(self);
    switch (self->unk15C.word)
    {
        case 0:
            if ((sp34[1] < 100.0f) || (temp_f2 < 10.0f)) {
                anctrl_setDuration(anim_ctrl, 0.4f);
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.5282f);
                anctrl_setDuration(anim_ctrl, 4.5f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            if ((anctrl_getAnimTimer(anim_ctrl) > 0.4f) && (temp_f2 < 70.0f)) {
                self->unk16C = anctrl_getAnimTimer(anim_ctrl);
                self->unk170 = temp_f2;
                anctrl_setPlaybackType(anim_ctrl, 3);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            func_8008B10C(anim_ctrl, ml_map_f(temp_f2, self->unk170, 1.0f, self->unk16C, 0.6703f));
            func_8009D2F0(self, 1, 0.5f);
            if (player_isStable(self) != 0) {
                func_8009FE58(self);
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 1.3f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                self->unk15C.word = 3;
            }
            break;
        case 3:
            func_8009D2F0(self, 1, 0.5f);
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = 0x26;
            }
            if (bakey_pressed(self, BUTTON_A) != 0) {
                next_state = 0x28;
            }
            if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0) {
                next_state = 0x29;
            }
            break;
    }
    if (func_80800000_bsblongleg(self) != 0) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

void bsblongleg_entrypoint_18(PlayerState* self)
{
    baphysics_reset_gravity(self);
    func_80800204_bsblongleg(self);
}

s32 bsblongleg_entrypoint_19(s32 arg0) {
    return D_808014B0_bsblongleg[arg0];
}

void bsblongleg_entrypoint_20(PlayerState* self)
{
    AnimCtrl* anim_ctrl;
    f32 rotation[2];

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x3D);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_setStart(anim_ctrl, 0.0865f);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_3_LOCKED_ROTATION);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    rotation[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, rotation[0], baphysics_get_target_horizontal_velocity(self));
    func_800A0CF4(self, 1);
    func_800A0CE8(self, 1);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009D658(self);
    _batimer_set(self, 0, 1.0f);
    func_8080013C_bsblongleg(self);
}

void bsblongleg_entrypoint_21(PlayerState* self)
{
    BanjoStateId next_state;
    f32 sp34[3];
    f32 sp44;

    next_state = BS_STATE_0_INVALID;
    func_808000C8_bsblongleg(self);
    func_8009D658(self);
    _batimer_decrement(self, 0);
    if (func_8008E148(self) != 0) {
        func_800963C0(self, sp34);
        func_800F1EA4(sp34, &sp44);
        func_8009D2F0(self, 1, 0.5f);
        baphysics_set_target_horizontal_velocity(self, ml_map_f(func_8009BFD8(self), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(self, sp44);
        _badust_entrypoint_1(self);
    } else {
        next_state = 0x26;
    }
    if (_batimer_isZero(self, 0) && bakey_pressed(self, BUTTON_A))
    {
        next_state = 0x28;
    }
    if (func_80800000_bsblongleg(self) != 0)
    {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

void bsblongleg_entrypoint_22(PlayerState* self)
{
    func_80800204_bsblongleg(self);
}

s32 bsblongleg_entrypoint_23(s32 arg0)
{
    return D_808014C0_bsblongleg[arg0];
}

void bsblongleg_entrypoint_24(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_80800204_bsblongleg(self);
}

void bsblongleg_entrypoint_25(PlayerState* self)
{
    func_8080013C_bsblongleg(self);
    _bsrest_entrypoint_16(self);
}

void bsblongleg_entrypoint_26(PlayerState* self)
{
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    func_808000C8_bsblongleg(self);
    func_8009D3A8(self, 1);
    if (_bsrest_entrypoint_20(self) != 0) {
        sp24 = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, sp24);
}

s32 bsblongleg_entrypoint_27(s32 arg0)
{
    return D_808014D0_bsblongleg[arg0];
}

void bsblongleg_entrypoint_28(PlayerState* self)
{
    func_8080013C_bsblongleg(self);
    _bsdrone_entrypoint_0(self);
}

void bsblongleg_entrypoint_29(PlayerState* self)
{
    func_808000C8_bsblongleg(self);
    _bsdrone_entrypoint_1(self);
    if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG)) {
        bs_setState(self, 0x29);
    }
}

void bsblongleg_entrypoint_30(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_80800204_bsblongleg(self);
}

s32 bsblongleg_entrypoint_31(s32 arg0)
{
    return D_808014E0_bsblongleg[arg0];
}
