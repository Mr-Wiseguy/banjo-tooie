#include "overlays/bs/mum/swim.h"

void func_80800000_bsmumswim(PlayerState *self) {
    f32 sp2C[3];
    s32 sp28;

    if (func_80096544(self) != 0) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(self, sp2C);
        } else {
            func_80092C24(self, sp2C);
        }
        sp28 = func_8009FBB0(self, sp2C, 0.0f);
        func_800BA930(sp28, -60, -100, -60, 60, 0, 60);
        func_800BA22C(sp28, 1);
    }
}

void func_808000B0_bsmumswim(PlayerState *self) {
    f32 zone_position;

    zone_position = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, func_800F1214(zone_position, 30.0f, 350.0f));
}

void func_80800114_bsmumswim(PlayerState *self) {
    _bsmum_entrypoint_2(self);
    if (func_8009E6C4(self, 1) == 0) {
        baphysics_set_gravity(self, 100.0f);
        baphysics_set_terminal_velocity(self, 133.33f);
        bastick_setZoneMax(self, 0, 0.03f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800961AC(self, 3);
    }
}

void func_80800198_bsmumswim(PlayerState *self) {
    if (func_8009E69C(self, 1) == 0) {
        baphysics_reset_terminal_velocity(self);
        baphysics_reset_gravity(self);
        func_800961AC(self, 1);
        bastick_func_8009F2A4(self);
    }
    _bsmum_entrypoint_1(self);
}

void bsmumswim_entrypoint_0(PlayerState *self) {
    func_8009BC34(self);
    func_800961AC(self, 1);
    _bsmum_entrypoint_1(self);
}

void bsmumswim_entrypoint_1(PlayerState *self) {
    AnimCtrl *anim_ctrl;
    f32 sp28;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bsmum_entrypoint_2(self);
    baphysics_set_gravity(self, 0.0f);
    baphysics_set_terminal_velocity(self, -399.99f);
    func_800961AC(self, 3);
    func_8009BC5C(self, 2.0f);
    func_800A046C(self);
    sp28 = func_800A3298(self);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_9D_ANIM_BSMUMSWIM_UNKNOWN);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_setDuration(anim_ctrl, 1.2f);
    anctrl_setStart(anim_ctrl, 0.6412f);
    anctrl_start(anim_ctrl);
    self->unk16C = func_800F10B4(sp28, 40.0f, 1000.0f, -300.0f, -1200.0f);
    baphysics_set_vertical_velocity(self, self->unk16C);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_6_AIRBORN);
}

void bsmumswim_entrypoint_2(PlayerState *self) {
    enum bs_state_e next_state;
    f32 sp40[3];
    s32 sp3C;

    next_state = BS_STATE_0_INVALID;
    func_8009C128(self, sp40);
    sp40[1] += 60.0f;
    sp3C = func_8009FBB0(self, sp40, 20.0f);
    func_800BA930(sp3C, -30, -30, -30, 30, 30, 30);
    func_800BA22C(sp3C, 1);
    if (self->unk16C < 0.0f) {
        self->unk16C += func_800F0E00(mlAbsF( self->unk16C) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(self, self->unk16C);
    }
    if (player_isStable(self) != 0) {
        next_state = BS_STATE_F0;
    }
    if (player_inWater(self) == 0) {
        next_state = BS_STATE_E5;
    }
    if (baphysics_get_vertical_velocity(self) >= 0.0f) {
        next_state = BS_STATE_F0;
    }
    bs_setState(self, next_state);
}

s32 bsmumswim_entrypoint_3(s32 idx) {
    return D_80800B30_bsmumswim[idx];
}

void func_80800498_bsmumswim(PlayerState *self) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_80800114_bsmumswim(self);
    anctrl_reset(anim_ctrl);
    if (bs_getPreviousState(self) == 0xF1) {
        func_8008B1C8(anim_ctrl, 0.8f);
    }
    anctrl_setIndex(anim_ctrl, ASSET_9D_ANIM_BSMUMSWIM_UNKNOWN);
    anctrl_setDuration(anim_ctrl, 2.8f);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800A4DA4(self, 8);
}

void func_8080056C_bsmumswim(PlayerState *self) {
    enum bs_state_e next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_8009FC34(self, 1);
    }
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_80800000_bsmumswim(self);
    }
    if ((anctrl_isAt(anim_ctrl, 0.01f) != 0) || (anctrl_isAt(anim_ctrl, 0.2f) != 0) || (anctrl_isAt(anim_ctrl, 0.4f) != 0) || (anctrl_isAt(anim_ctrl, 0.6f) != 0) || (anctrl_isAt(anim_ctrl, 0.8f) != 0)) {
        func_8009DEC0(self, 0x678, 0.85f, 1.15f, 18000, 18000);
    }
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_1) {
        next_state = BS_STATE_F1;
    }
    if (player_inWater(self) == 0) {
        next_state = BS_STATE_E5;
    }
    if (bainput_should_enter_first_person(self) != 0) {
        next_state = _badrone_entrypoint_24(self);
    }
    if ((func_80096500(self) != 0) && (bakey_pressed(self, 8) != 0)) {
        next_state = BS_STATE_E8;
    }
    bs_setState(self, next_state);
}

void func_80800714_bsmumswim(PlayerState *self) {
    func_80800198_bsmumswim(self);
    func_800A4E30(self);
}

s32 bsmumswim_entrypoint_4(s32 idx) {
    return D_80800B40_bsmumswim[idx];
}

void func_80800750_bsmumswim(PlayerState *self) {
    AnimCtrl *anim_ctrl;
    f32 sp28;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == 0xF0) {
        sp28 = 0.8f;
    } else {
        sp28 = 0.2f;
    }
    func_80800114_bsmumswim(self);
    anctrl_reset(anim_ctrl);
    func_8008B1C8(anim_ctrl, sp28);
    anctrl_setIndex(anim_ctrl, ASSET_9C_ANIM_BSMUMSWIM_UNKNOWN);
    anctrl_setStart(anim_ctrl, 0.8f);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8008CA4C(self, BAANIM_UPDATE_2_SCALE_HORZ);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 30.0f, 350.0f, 1.0f, 0.5f);
    yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
    yaw_setVelocityBounded(self, 500.0f, 5.0f);
    func_8009D2D8(self, 1);
    baphysics_set_type(self, BA_PHYSICS_2_NORMAL);
}

void func_80800870_bsmumswim(PlayerState *self) {
    enum bs_state_e next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (anctrl_isAt(anim_ctrl, 0.38f) != 0) {
        func_8009FD24(self, 1);
    }
    if (anctrl_isAt(anim_ctrl, 0.88f) != 0) {
        func_8009FD24(self, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f) != 0) {
        func_8009DE74(self, 0x40C, 0.9f, 1.1f);
    }
    if (anctrl_isAt(anim_ctrl, 0.7f) != 0) {
        func_8009DE74(self, 0x40C, 0.9f, 1.1f);
    }
    func_808000B0_bsmumswim(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        next_state = BS_STATE_F0;
    }
    if (player_inWater(self) == 0) {
        next_state = BS_STATE_E5;
    }
    if ((func_80096500(self) != 0) && (bakey_pressed(self, 8) != 0)) {
        next_state = BS_STATE_E8;
    }
    bs_setState(self, next_state);
}

void func_808009A0_bsmumswim(PlayerState *self) {
    func_80800198_bsmumswim(self);
}

s32 bsmumswim_entrypoint_5(s32 idx) {
    return D_80800B50_bsmumswim[idx];
}

void func_808009D4_bsmumswim(PlayerState *self) {
    _bsrest_entrypoint_14(self);
    func_80800198_bsmumswim(self);
}

void func_808009FC_bsmumswim(PlayerState *self) {
    func_80800114_bsmumswim(self);
    _bsrest_entrypoint_16(self);
}

void func_80800A24_bsmumswim(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        next_state = BS_STATE_F0;
    }
    bs_setState(self, next_state);
}

s32 bsmumswim_entrypoint_6(s32 idx) {
    return D_80800B60_bsmumswim[idx];
}

void func_80800A70_bsmumswim(PlayerState *self) {
    func_80800114_bsmumswim(self);
    _bsdrone_entrypoint_0(self);
}

void func_80800A98_bsmumswim(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (_badrone_entrypoint_30(self) != 0) {
        next_state = BS_STATE_E5;
    }
    _bsdrone_entrypoint_1(self);
    bs_setState(self, next_state);
}

void func_80800ADC_bsmumswim(PlayerState *self) {
    _bsdrone_entrypoint_2(self);
    func_80800198_bsmumswim(self);
}

s32 bsmumswim_entrypoint_7(s32 idx) {
    return D_80800B70_bsmumswim[idx];
}
