#include "overlays/bs/mum/move.h"

f32 bsmummove_entrypoint_0(PlayerState *self) {
    return 600.0f;
}

f32 bsmummove_entrypoint_1(PlayerState *self) {
    return 120.0f;
}

f32 bsmummove_entrypoint_2(PlayerState *self) {
    return 80.0f;
}

void func_80800030_bsmummove(PlayerState *self) {
    _bsmum_entrypoint_1(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

void func_80800068_bsmummove(PlayerState *self) {
    AnimCtrl *anim_ctrl;
    f32 anim_start;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bsmum_entrypoint_2(self);
    anim_start = 0.0f;
    if (bs_getPreviousState(self) == 0xE6) {
        anim_start = baanim_getTimer(self);
        if (func_8009BB5C(self) < 200.0f) {
            _badust_entrypoint_3(self, 0.0f, 0.0f);
        }
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_B4_ANIM_BSMUMMOVE_UNKNOWN);
    anctrl_setDuration(anim_ctrl, 0.66f);
    func_8008B1C8(anim_ctrl, 0.1f);
    anctrl_setStart(anim_ctrl, anim_start);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 120.0f, 600.0f, 0.65f, 0.4f);
    func_8008CA30(self, 1.0f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
}

void func_808001D8_bsmummove(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    func_8009D2F0(self, 0, 0.5f);
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    _bsmum_entrypoint_13(self);
    switch (bastick_getZone(self)) {
        case BS_STICK_ZONE_ID_0:
            if (func_8009BCD4(self, 18.0f) != 0) {
                next_state = BS_STATE_E5;
            }
            break;
        case BS_STICK_ZONE_ID_1:
            if (func_8009BCD4(self, 120.0f) != 0) {
                next_state = BS_STATE_E6;
            }
            break;
    }
    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_E9;
    }
    if (bakey_pressed(self, BUTTON_B) != 0) {
        next_state = BS_STATE_F7;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        next_state = BS_STATE_E8;
    }
    if (func_8008E148(self) != 0) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_F0;
    }
    bs_setState(self, next_state);
}

s32 bsmummove_entrypoint_3(s32 idx) {
    return D_808005B0_bsmummove[idx];
}

void func_80800318_bsmummove(PlayerState *self) {
    _bsmum_entrypoint_1(self);
}

void func_80800338_bsmummove(PlayerState *self) {
    AnimCtrl *anim_ctrl;
    f32 anim_start;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bsmum_entrypoint_2(self);
    if (bs_getPreviousState(self) == 0xE7) {
        anim_start = baanim_getTimer(self);
    } else {
        anim_start = 0.0f;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_B3_ANIM_BSMUMMOVE_UNKNOWN);
    anctrl_setDuration(anim_ctrl, 0.43f);
    anctrl_setStart(anim_ctrl, anim_start);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.1f, 5.0f);
    func_8008C9F0(self, 80.0f, 120.0f, 0.9f, 0.5f);
    func_8008CA30(self, 1.0f);
}

void func_80800444_bsmummove(PlayerState *self) {
    enum bs_state_e next_state;
    s32 temp_v0;

    next_state = BS_STATE_0_INVALID;
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    _bsmum_entrypoint_13(self);
    switch (bastick_getZone(self)) {
        case BS_STICK_ZONE_ID_0:
            if (func_8009BCD4(self, 3.0f) != 0) {
                next_state = BS_STATE_E5;
            }
            break;
        case BS_STICK_ZONE_ID_2:
            next_state = BS_STATE_E7;
            break;
    }
    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_E9;
    }
    if (bakey_pressed(self, BUTTON_B) != 0) {
        next_state = BS_STATE_F7;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        next_state = BS_STATE_E8;
    }
    if (func_8008E148(self) != 0) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_F0;
    }
    bs_setState(self, next_state);
}

s32 bsmummove_entrypoint_4(s32 idx) {
    return D_808005C0_bsmummove[idx];
}
