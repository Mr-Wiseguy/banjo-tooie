#include "common.h"

#include "overlays/bs/kaz/shock.h"

extern s32 D_80800770_bskazshock[];
extern s32 D_808007A4_bskazshock[];
extern s32 D_808007B4_bskazshock[];

void bskazshock_entrypoint_0(PlayerState *self) {
    f32 sp24[3];

    func_80092C24(self, sp24);
    func_800BBCB8(sp24, 0, 1, 1, D_80800770_bskazshock);
}

void bskazshock_entrypoint_1(PlayerState *self) {
    f32 sp2C[3];
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_27C_ANIM_BSKAZSHOCK_UNKNOWN);
    func_8008B1C8(animCtrl, 0.4);
    anctrl_setDuration(animCtrl, 3);
    anctrl_setSubrange(animCtrl, 0, 0.2);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_start(animCtrl);
    func_8009FFD8(self, 1, 1, 3, 6);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bskazmove_entrypoint_0(self);
    sp2C[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C[0], baphysics_get_target_horizontal_velocity(self));
    self->unk164.bytes[0] = func_800C2E04();
    func_800C3418(self->unk164.bytes[0], 0);
    func_800C2E40(self->unk164.bytes[0]);
    func_800C330C(self->unk164.bytes[0], 3);
    func_800C301C(self->unk164.bytes[0], 0x41D);
    func_800C3730(self->unk164.bytes[0], 1.4, 0.4, -1.2);
    self->unk15C.word = 1;
    self->unk160.word = 0;
}

void bskazshock_entrypoint_2(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *animCtrl;
    f32 sp24[3];

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    if (player_isStable(self) != 0) {
        if ((func_8001211C() % -2) != 0) {
            bskazshock_entrypoint_0(self);
        }
    } else {
        bskazshock_entrypoint_0(self);
    }
    _bskazmove_entrypoint_0(self);
    func_8009BB24(self, sp24);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp24[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk160.word) {
        case 0:
            if (func_8008E260(self) != 0) {
                next_state = BS_STATE_E0;
            }
            if (func_8008DF8C(self, 0x82) != 0) {
                anctrl_setSubrange(animCtrl, 0, 1);
                anctrl_setDuration(animCtrl, 2.8);
                anctrl_setPlaybackType(animCtrl, 1);
                self->unk160.word = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(animCtrl, 0.11) != 0) {
                func_800C3BDC(self->unk164.bytes[0]);
            }
            if (anctrl_isAt(animCtrl, 0.4036) != 0) {
                anctrl_setDuration(animCtrl, 1.4);
            }
            if (anctrl_isStopped(animCtrl) != 0) {
                next_state = BS_STATE_BB;
            }
            break;
    }
    if (func_8008DF8C(self, 0x3C) != 0) {
        if ((anctrl_getAnimTimer(animCtrl) < 0.5f) && (bakey_released(self, BUTTON_A) != 0)) {
            self->unk15C.word = 0;
        }
        if (player_isStable(self) != 0) {
            baphysics_set_target_horizontal_velocity(self, 0);
        }
    }
    if ((anctrl_isAt(animCtrl, 0.5) != 0) && (self->unk15C.word != 0)) {
        next_state = BS_STATE_C1;
    }
    if (anctrl_isAt(animCtrl, 0.5551) != 0) {
        baphysics_set_vertical_velocity(self, 180);
    }
    if ((sp24[1] < 0.0f) && (player_inWater(self) != 0)) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazshock_entrypoint_3(PlayerState *self) {
    func_800C2FDC(self->unk164.bytes[0]);
    func_80092BF4(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazshock_entrypoint_4(s32 idx) {
    return D_808007A4_bskazshock[idx];
}

void bskazshock_entrypoint_5(PlayerState *self) {
    f32 sp2C[3];
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    anctrl_reset(animCtrl);
    anctrl_setSmoothTransition(animCtrl, 0);
    anctrl_setIndex(animCtrl, ASSET_27A_ANIM_BSKAZSHOCK_UNKNOWN);
    anctrl_setDuration(animCtrl, 1.6);
    anctrl_setStart(animCtrl, 0.5814);
    anctrl_setSubrange(animCtrl, 0, 1);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_start(animCtrl);
    func_8009FFD8(self, 1, 1, 3, 6);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bskazmove_entrypoint_0(self);
    sp2C[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C[0], baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 1820);
    baphysics_set_gravity(self, -1200);
    func_8009DBF0(self, 0x408, 1);
    func_800C6DA0(0x45);
    self->unk160.word = 0;
}

void bskazshock_entrypoint_6(PlayerState *self) {
    BanjoStateId next_state;
    f32 sp28[3];
    AnimCtrl *animCtrl;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskazmove_entrypoint_0(self);
    func_8009BB24(self, sp28);
    if (anctrl_isAt(animCtrl, 0.61) != 0) {
        func_8009DF58(self, 0x4598, 1);
    }
    if ((bakey_released(self, BUTTON_A) != 0) && (sp28[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    if (self->unk160.word == 0) {
        bskazshock_entrypoint_0(self);
        if (sp28[1] < 0.0f) {
            next_state = BS_STATE_DF;
        }
    }
    if (player_isStable(self) == 0) {
        if (func_8008E260(self) != 0) {
            next_state = BS_STATE_E0;
        }
        if (bainput_should_feathery_flap(self) != 0) {
            next_state = BS_STATE_15C;
        }
        if ((baphysics_get_vertical_velocity(self) < 0.0f) && (bainput_func_80097E74(self) != 0)) {
            next_state = BS_STATE_BE;
        }
    }
    bs_setState(self, next_state);
}

void bskazshock_entrypoint_7(PlayerState *self) {
    baphysics_reset_gravity(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazshock_entrypoint_8(s32 idx) {
    return D_808007B4_bskazshock[idx];
}