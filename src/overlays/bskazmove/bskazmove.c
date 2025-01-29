#include "common.h"

#include "bs/kazmove.h"

extern s32 D_80800C70_bskazmove[];
extern s32 D_80800C80_bskazmove[];


void func_80800000_bskazmove(PlayerState *self, f32 *arg1, f32 *arg2) {
    switch ( _bashoes_entrypoint_1(self)) {
        case 3:
            *arg1 = 250.0f;
            *arg2 = 1200.0f;
            return;
        case 4:
            *arg1 = 250.0f;
            *arg2 = 800.0f;
            return;
        case 5:
            *arg1 = 250.0f;
            *arg2 = 800.0f;
            return;
    }
}

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bskazmove/bskazmove/bskazmove_entrypoint_0.s")
#else
void bskazmove_entrypoint_0(PlayerState *self) {
    s32 temp_v0;
    f32 value;
    f32 max;
    f32 min;
    s32 zone;

    // &self should not be a reference as it adds "addiu a0, sp, 0x38" to the assembly
    // however if it's not a reference it's not calling "sw a0,0x38(sp)" but instead calls "move a0,s0"
    value = bastick_getZonePosition(self); 
    zone = bastick_getZone(self);
    temp_v0 = func_8008E39C(self);
    switch (zone) {
        case 0:
            value = 0;
            max = 0;
            min = 0;
            break;

        case 1:
            if (temp_v0 != 0) {
                func_80800000_bskazmove(self, &min, &max);
                value = value * 0.5f;
            } else {
                min = 80;
                max = 250;
            }
            break;

        case 2:
            if (temp_v0 != 0) {
                func_80800000_bskazmove(self, &min, &max);
                value = (value * 0.5f) + 0.5f;
            } else {
                min = 250;
                max = 800;
            }
            break;
    }

    baphysics_set_target_horizontal_velocity(self, func_800F1214(value, min, max));
}
#endif

s32 func_808001C4_bskazmove(PlayerState *self, s32 arg1) {
    if (func_8008E39C(self) != 0) {
        return arg1;
    } 

    if (baphysics_get_target_horizontal_velocity(self) > 80.0f) {
        if (bainput_func_80097FB8(self) != 0) {
            arg1 = 0xC4;
        }
    } else if (bainput_func_80097FB8(self) != 0) {
        arg1 = _bskaz_entrypoint_4(self);
    }
    return arg1;
}

void func_8080025C_bskazmove(PlayerState *self) {
    if (bakey_pressed(self, BUTTON_B) != 0) {
        _bashoes_entrypoint_6(self, 2);
    }
}

void bskazmove_entrypoint_1(PlayerState *self) {
    _bskaz_entrypoint_2(self);
}

void bskazmove_entrypoint_2(PlayerState *self) {
    AnimCtrl *animCtrl;
    f32 animTimer;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    if (func_8009E710(self) == 0xC7) {
        animTimer = baanim_getTimer(self);
    } else {
        animTimer = 0.0f;
    }
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_A7_ANIM_BSKAZMOVE_UNKNOWN);
    anctrl_setDuration(animCtrl, 0.43);
    anctrl_setStart(animCtrl, animTimer);
    anctrl_setPlaybackType(animCtrl, 2);
    anctrl_start(animCtrl);
    func_8009FFD8(self, 2, 1, 1, 2);
    baanim_setDurationRange(self, 0.3, 1.5);
    func_8008C9F0(self, 80, 250, 1.3, 0.45f);
    func_8008CA30(self, 1);
}

void bskazmove_entrypoint_3(PlayerState *self) {
    s32 sp24;
    s32 temp_v0;

    sp24 = 0;
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.47, 4);
    func_800A2CE8(self, 0.97, 3);
    bskazmove_entrypoint_0(self);
    switch (bastick_getZone(self)) {
        case 0:
            if (func_8009BCD4(self, 3) != 0) {
                sp24 = 0xBB;
            }
            break;
        case 2:
            sp24 = 0xC7;
            break;
    }

    if (func_8008E39C(self) != 0) {
        sp24 = 0xC7;
    }

    if (func_8008DD04(self) != 0) {
        sp24 = 0xDF;
    }

    if ((bakey_held(self, 1) != 0) && (func_8008E39C(self) == 0)) {
        sp24 = 0xDD;
    }

    if (func_8008E39C(self) != 0) {
        func_8080025C_bskazmove(self);
    } else {
        sp24 = func_808001C4_bskazmove(self, sp24);
    }

    if (bakey_pressed(self, 8) != 0) {
        sp24 = _bskaz_entrypoint_3(self);
        if ((baphysics_get_target_horizontal_velocity(self) == 0.0f) && (func_8008D790(self) != 0)) {
            _baduo_entrypoint_12(self);
            return;
        }
    }

    if (func_8008DF18(self) != 0) {
        sp24 = _badrone_entrypoint_25(self);
    }

    if (player_inWater(self) != 0) {
        sp24 = 0x15D;
    }

    bs_setState(self, func_800A02DC(self, sp24));
}

s32 bskazmove_entrypoint_4(s32 idx) {
    return D_80800C70_bskazmove[idx];
}

void bskazmove_entrypoint_5(PlayerState *self, s32 arg1) {
    s32 animIndex;
    s32 pad0;
    f32 animTimer;
    s32 pad1;
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    animTimer = baanim_getTimer(self);
    switch (arg1) {
        case 3:
            animIndex = ASSET_A6_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 1200.0f, 0.54, 0.35f);
            break;
        case 4:
            animIndex = ASSET_24F_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 800.0f, 0.8, 0.4f);
            break;
        case 5:
            animIndex = ASSET_24D_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 800.0f, 1.1, 0.7f);
            break;
        default:
            animIndex = ASSET_A6_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 800.0f, 0.54, 0.35f);
            break;
    }

    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, animIndex);
    anctrl_setDuration(animCtrl, 1);
    func_8008B1C8(animCtrl, 0.1);
    anctrl_setStart(animCtrl, animTimer);
    anctrl_setPlaybackType(animCtrl, 2);
    anctrl_start(animCtrl);
    func_8008CA30(self, 1);
    baanim_setDurationRange(self, 0.3, 1.5);
}

void func_80800754_bskazmove(PlayerState *self) {
    s32 temp_v0;

    temp_v0 = _bashoes_entrypoint_1(self);
    if (temp_v0 != self->unk15C.word) {
        self->unk15C.word = temp_v0;
        bskazmove_entrypoint_5(self, temp_v0);
    }
}

void bskazmove_entrypoint_6(PlayerState *self) {
    AnimCtrl *animCtrl;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    s32 temp_v0;

    animCtrl = baanim_getAnimCtrlPtr(self);
    sp20 = 1;
    sp28 = 0.7781f;
    sp24 = 0.2781f;
    switch (_bashoes_entrypoint_1(self)) {
        case 3:
            _bashoes_entrypoint_20(self);
            break;
        case 4:
            sp20 = 0;
            break;
        case 5:
            sp28 = 0.1;
            sp24 = 0.58;
            if (anctrl_isAt(animCtrl, sp24) != 0) {
                _bashoes_entrypoint_19(self);
            }
            if (anctrl_isAt(animCtrl, sp28) != 0) {
                _bashoes_entrypoint_18(self);
            }
            break;
        default:
            if ((anctrl_isAt(animCtrl, 0.2115f) != 0) || (anctrl_isAt(animCtrl, 0.7115f) != 0)) {
                _badust_entrypoint_1(self);
            }
            break;
    }

    if (sp20 != 0) {
        func_800A2CE8(self, sp24, 4);
        func_800A2CE8(self, sp28, 3);
        return;
    }

    func_800A2D2C(self, sp24, 4);
    func_800A2D2C(self, sp28, 3);
}

void bskazmove_entrypoint_7(PlayerState *self) {
    func_8009BF5C(self, 0);
    baroll_setIdeal(self, 0);
    _bskaz_entrypoint_2(self);
}

void bskazmove_entrypoint_8(PlayerState *self) {
    _bskaz_entrypoint_1();
    if ((func_8009E710(self) == 0xBC) && (func_8009BB5C(self) < 200.0f)) {
        _badust_entrypoint_3(self, 0.0f, 0.0f);
    }
    self->unk15C.word = 0;
    func_80800754_bskazmove(self);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8009BFE4(self, 1000, 12);
    baroll_setAngularVelocity(self, 1000, 12);
}

void bskazmove_entrypoint_9(PlayerState *self) {
    s32 state;
    s32 sp20;

    state = 0;
    sp20 = func_8008E39C(self);
    func_80800754_bskazmove(self);
    bskazmove_entrypoint_6(self);
    func_8009D2F0(self, 0, 0.5);
    bskazmove_entrypoint_0(self);
    switch (bastick_getZone(self)) {
        case 0:
            if (func_8009BCD4(self, 18) != 0) {
                state = 0xBB;
            }
            break;
        case 1:
            if ((sp20 == 0) && (func_8009BCD4(self, 250) != 0)) {
                state = 0xBC;
            }
            break;
    }

    if (func_8008DD04(self) != 0) {
        state = 0xDF;
    }

    if ((bakey_held(self, 1) != 0) && (func_8008E39C(self) == 0)) {
        state = 0xDD;
    }

    if (sp20 != 0) {
        func_8080025C_bskazmove(self);
    } else {
        state = func_808001C4_bskazmove(self, state);
    }

    if (bakey_pressed(self, BUTTON_A) != 0) {
        state = _bskaz_entrypoint_3(self);
        if ((baphysics_get_target_horizontal_velocity(self) == 0.0f) && (func_8008D790(self) != 0)) {
            _baduo_entrypoint_12(self);
            return;
        }
    }

    if (func_8008DF18(self) != 0) {
        state = _badrone_entrypoint_25(self);
    }

    if (player_inWater(self) != 0) {
        state = 0x15D;
    }

    bs_setState(self, func_800A02DC(self, state));
}

s32 bskazmove_entrypoint_10(s32 idx) {
    return D_80800C80_bskazmove[idx];
}

void bskazmove_entrypoint_11(PlayerState *self, s32 arg1) {
    if ((arg1 == 3) && (bastick_getZone(self) == 2) && (bastick_getZonePosition(self) > 0.8f)) {
        func_800962B0(self, 1);
        return;
    }
    func_800962B0(self, 0);
}
