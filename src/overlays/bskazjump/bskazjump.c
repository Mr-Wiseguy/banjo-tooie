#include "common.h"

#include "overlays/bs/kaz/jump.h"

extern s32 D_80800C40_bskazjump[];
extern s32 D_80800C50_bskazjump[];
extern s32 D_80800C60_bskazjump[];
extern s32 D_80800C70_bskazjump[];

void bskazjump_entrypoint_0(PlayerState *self) {
    AnimCtrl *animCtrl;
    f32 unk0[2];
    f32 pad0;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    self->unk164.word = baflag_isTrue(self, BA_FLAG_2_ON_SPRING_PAD);
    self->unk160.word = 0;
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_A9_ANIM_BSKAZJUMP_UNKNOWN);
    anctrl_setDuration(animCtrl, 1.9);
    func_8008B1C8(animCtrl, 0.134);
    anctrl_setStart(animCtrl, 0.3);
    anctrl_setSubrange(animCtrl, 0, 0.5042);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_start(animCtrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bskazmove_entrypoint_0(self);
    unk0[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, unk0[0], baphysics_get_target_horizontal_velocity(self));
    if (self->unk160.word != 0) {
        baphysics_set_vertical_velocity(self, 610);
    } else {
        baphysics_set_vertical_velocity(self, 610);
    }
    baphysics_set_gravity(self, -1000);
    if (self->unk164.word != 0) {
        func_8009DE38(self, 0x4432, 1);
    } else {
        func_8009DE38(self, 0x4432, 1);
    }
    baflag_clear(self, BA_FLAG_12_HAS_FLAPPED);
    baflag_clear(self, BA_FLAG_5_HAS_PECKED);
    self->unk15C.word = 0;
}

void bskazjump_entrypoint_1(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *animCtrl;
    s32 pad0;
    f32 sp28;
    f32 sp24;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    if (self->unk164.word != 0) {
        _bskazshock_entrypoint_0(self);
    }
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        func_8009B7C0(self);
    } else {
        _bskazmove_entrypoint_0(self);
    }
    func_8009BB24(self, &sp24);
    if (((bakey_released(self, BUTTON_A) != 0) && (sp28 > 0.0f) && (self->unk164.word == 0)) || (func_8008D544(self) == 0)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word) {
        case 2:
            break;
        case 0:
            if (anctrl_isStopped(animCtrl) != 0) {
                baanim_setEndAndDuration(self, 0.6667, 4);
                self->unk15C.word = 1;
            }
            if (func_8008DF8C(self, 0x82) != 0) {
                baanim_setEndAndDuration(self, 1, 1.4);
                self->unk15C.word = 2;
            }
            break;
        case 1:
            if (baanim_isStopped(self) != 0) {
                next_state = BS_STATE_DF;
            }
            if (self->unk164.word != 0) {
                self->unk164.word = 0;
                next_state = BS_STATE_C3;
            }
            if (func_8008DF8C(self, 0x5A) != 0) {
                baanim_setEndAndDuration(self, 1, 2);
                self->unk15C.word = 2;
            }
            break;
    }
    if (bakey_released(self, BUTTON_A) != 0) {
        self->unk164.word = 0;
    }
    if (bainput_should_feathery_flap(self) != 0) {
        next_state = BS_STATE_15C;
    }
    if (bainput_func_80097FB8(self) != 0) {
        next_state = BS_STATE_C4;
    }
    if ((bainput_func_80097E74(self) != 0) && (baphysics_get_vertical_velocity(self) < 0.0f)) {
        next_state = BS_STATE_BE;
    }
    if (player_isStable(self) != 0) {
        func_8009FE58(self);
        if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
            next_state = BS_STATE_DE;
        } else if (func_8008E39C(self) != 0) {
            next_state = BS_STATE_C7;
        } else {
            next_state = BS_STATE_BC;
        }
    }
    if ((sp28 < 0.0f) && (player_inWater(self) != 0)) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazjump_entrypoint_2(PlayerState *self) {
    if (func_800C6E38(0xA) != 0) {
        func_800C6DA0(0x3C);
    }
    baphysics_reset_gravity(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazjump_entrypoint_3(s32 idx) {
    return D_80800C40_bskazjump[idx];
}

void func_808004C4_bskazjump(PlayerState *self, s32 arg1) {
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    switch (arg1) {
        case 1:
            baanim_playForDuration_loopSmooth(self, 0x13B, 0.4);
            break;
        case 2:
            anctrl_reset(animCtrl);
            anctrl_setIndex(animCtrl, ASSET_A9_ANIM_BSKAZJUMP_UNKNOWN);
            anctrl_setStart(animCtrl, 0.6922);
            anctrl_setDuration(animCtrl, 2);
            anctrl_setPlaybackType(animCtrl, 1);
            anctrl_start(animCtrl);
            break;
    }
    self->unk15C.word = arg1;
}

void bskazjump_entrypoint_4(PlayerState *self) {
    _bskaz_entrypoint_2(self);
}

void bskazjump_entrypoint_5(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    self->unk168.word = bs_getPreviousState(self) == 0xC6;
    if ((baflag_isTrue(self, BA_FLAG_7) != 0) && (baphysics_get_vertical_velocity(self) > 700.0f)) {
        baphysics_set_vertical_velocity(self, 700.0f);
    }
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    self->unk15C.word = 0;
    if (func_8008DF8C(self, 0x64) != 0) {
        func_808004C4_bskazjump(self, 2);
        return;
    }
    func_808004C4_bskazjump(self, 1);
}

void bskazjump_entrypoint_6(PlayerState *self) {
    BanjoStateId next_state;
    f32 sp28[3];
    s32 temp_v0;

    next_state = BS_STATE_0_INVALID;
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        func_8009B7C0(self);
    } else {
        _bskazmove_entrypoint_0(self);
    }
    func_8009BB24(self, sp28);
    switch (self->unk15C.word) {
    case 2:
        break;
    case 1:
        if (func_8008E260(self) != 0) {
            next_state = BS_STATE_E0;
        }
        if (bainput_func_80097E74(self) != 0) {
            if (self->unk168.word == 0) {
                next_state = BS_STATE_BE;
            } else if (bakey_pressed(self, BUTTON_Z) != 0) {
                next_state = BS_STATE_BE;
            }
        }
        if (bainput_should_feathery_flap(self) != 0) {
            next_state = BS_STATE_15C;
        }
        if (func_8008DF8C(self, 0x64) != 0) {
            func_808004C4_bskazjump(self, 2);
        }
        break;
    }
    if (baflag_isFalse(self, BA_FLAG_F) != 0) {
        if ((player_isStable(self) == 0) && (bainput_func_80097FB8(self) != 0)) {
            next_state = BS_STATE_C4;
        }
        if (player_inWater(self) != 0) {
            next_state = BS_STATE_160;
        }
    } else if (player_inWater(self) != 0) {
        func_800A046C(self);
    }
    if (player_isStable(self) != 0) {
        func_8009FE58(self);
        if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
            next_state = BS_STATE_DE;
        } else if (func_8008E39C(self) != 0) {
            next_state = BS_STATE_C7;
        } else {
            next_state = BS_STATE_BC;
        }
    }
    bs_setState(self, next_state);
}

s32 bskazjump_entrypoint_7(s32 idx) {
    return D_80800C50_bskazjump[idx];
}

void bskazjump_entrypoint_8(PlayerState *self) {
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_A9_ANIM_BSKAZJUMP_UNKNOWN);
    func_8008B1C8(animCtrl, 0.3);
    anctrl_setDuration(animCtrl, 1.9);
    anctrl_setStart(animCtrl, 0.6667);
    anctrl_setPlaybackType(animCtrl, 3);
    anctrl_start(animCtrl);
    yaw_setIdeal(self, func_8009F308(self));
    func_8008CA4C(self, 1);
    yaw_setUpdateType(self, 1);
    func_8009D2D8(self, 3);
    baphysics_set_type(self, 6);
    baphysics_set_target_horizontal_velocity(self, 0);
    func_8009BA9C(self, 0);
    self->unk15C.word = 1;
    func_8008E944(self);
}

void bskazjump_entrypoint_9(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *animCtrl;
    s32 pad0[2];
    f32 sp24;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    func_8009BB24(self, &sp24);
    switch (self->unk15C.word) {
    case 2:
        break;
    case 1:
        if (func_8008DF8C(self, 0x5A) != 0) {
            anctrl_setSubrange(animCtrl, 0, 1);
            anctrl_setDuration(animCtrl, 2);
            anctrl_setPlaybackType(animCtrl, 1);
            self->unk15C.word = 2;
        }
        break;
    }
    if (player_isStable(self) != 0) {
        next_state = BS_STATE_BB;
    }
    bs_setState(self, next_state);
}

void bskazjump_entrypoint_10(PlayerState *self) {
    func_8008E95C(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazjump_entrypoint_11(s32 idx) {
    return D_80800C60_bskazjump[idx];
}

void bskazjump_entrypoint_12(PlayerState *self) {
    func_800A042C(self);
    func_80093360(self, 0);
    func_8009E0DC(self);
    _bskaz_entrypoint_2(self);
}

void bskazjump_entrypoint_13(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_loop(self, 0x13C, 0.4);
    func_8009FFD8(self, 1, 1, 3, 6);
    func_80093360(self, 60);
    if (func_8009557C(self) == 1) {
        _batimer_set(self, 0, 0.5);
        _batimer_set(self, 1, 0.41);
        func_8009DF18(self, 0x4668, 1, 22000);
    } else {
        _batimer_set(self, 0, 0);
        _batimer_set(self, 1, 0.01);
    }
    self->unk15C.word = 1;
}

void bskazjump_entrypoint_14(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (_batimer_decrement(self, 1) != 0) {
        func_8009DF18(self, 0x4667, 1, 32000);
    }
    _batimer_decrement(self, 0);
    _bskazmove_entrypoint_0(self);
    if (_batimer_isZero(self, 1) != 0) {
        func_8009BF5C(self, func_8009BFD8(self) + 20.0f);
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_160;
    }
    if (player_isStable(self) != 0) {
        next_state = BS_STATE_176;
    }
    bs_setState(self, next_state);
}

s32 bskazjump_entrypoint_15(s32 idx) {
    return D_80800C70_bskazjump[idx];
}