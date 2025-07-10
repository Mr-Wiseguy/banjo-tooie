#include "common.h"

#include "overlays/bs/kaz/still.h"

extern u8 D_808008A0_bskazstill[];
extern s32 D_808008A4_bskazstill[];
extern s32 D_808008B4_bskazstill[];
extern s32 D_808008C4_bskazstill[];
extern s32 D_808008D4_bskazstill[];

u8 func_80800000_bskazstill(PlayerState *self) {
    if (self->unk160.word >= 4U) {
        self->unk160.word = 0;
    }
    return D_808008A0_bskazstill[self->unk160.word++];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/kaz/still/func_80800030_bskazstill.s")

BanjoStateId func_808001A4_bskazstill(PlayerState *self, BanjoStateId nextState) {
    s32 sp24;
    s32 temp_v0;

    sp24 = func_8008E39C(self);
    temp_v0 = bastick_getZone(self);
    switch (temp_v0) {
        case BS_STICK_ZONE_ID_0:
            break;
        case BS_STICK_ZONE_ID_1:
            if (sp24 != 0) {
                nextState = BS_STATE_C7;
            } else {
                nextState = BS_STATE_BC;
            }
            break;
        case BS_STICK_ZONE_ID_2:
            nextState = BS_STATE_C7;
            break;
    }
    if (sp24 != 0) {
        if (func_8008E3E8(self) != 0) {
            _bashoes_entrypoint_20(self);
        }
        if (bakey_pressed(self, 9) != 0) {
            _bashoes_entrypoint_6(self, 2);
        }
    } else {
        if (bakey_held(self, 1) != 0) {
            nextState = BS_STATE_DD;
        }
        if (bainput_func_80097FB8(self) != 0) {
            nextState = _bskaz_entrypoint_4(self);
        }
    }
    if (bakey_pressed(self, 8) != 0) {
        if (func_8008D790(self) != 0) {
            _baduo_entrypoint_12(self);
        } else {
            nextState = _bskaz_entrypoint_3(self);
        }
    }
    if (bainput_should_enter_first_person(self) != 0) {
        nextState = _badrone_entrypoint_24(self);
    }
    if (func_8008DF18(self) != 0) {
        nextState = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0) {
        nextState = BS_STATE_15D;
    }
    if (func_8008DD04(self) != 0) {
        nextState = BS_STATE_DF;
    }
    return func_800A02DC(self, nextState);
}

void bskazstill_entrypoint_0(PlayerState *self) {
    func_80800030_bskazstill(self, 0);
    func_80090A2C(self);
    func_800951B4(self);
    _bskaz_entrypoint_2(self);
}

void bskazstill_entrypoint_1(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    self->unk15C.word = 0;
    if (func_8008E39C(self) != 0) {
        func_80800030_bskazstill(self, 5U);
        return;
    }
    func_80800030_bskazstill(self, 1U);
}

void bskazstill_entrypoint_2(PlayerState *self) {
    s32 var_v1;
    AnimCtrl *animCtrl;
    s32 sp24;

    animCtrl = baanim_getAnimCtrlPtr(self);
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (bastick_distance(self) > 0.0f)) {
        self->unk164.word = 1;
        yaw_setUpdateType(self, 3);
        yaw_setVelocityBounded(self, 200, 14);
    } else {
        if (self->unk164.word != 0) {
            yaw_setIdeal(self, yaw_get(self));
        }
        self->unk164.word = 0;
        yaw_setUpdateType(self, 1);
    }
    sp24 = func_8008E39C(self);
    var_v1 = self->unk15C.word;
    switch (var_v1) {
        case 2:
            if (anctrl_isAt(animCtrl, 0.3587) != 0) {
                func_8009DF18(self, 0x418, 1.8, 16000);
            }
            if (anctrl_isAt(animCtrl, 0.3859) != 0) {
                func_8009DF18(self, 0x418, 1.8, 16000);
            }
            if (anctrl_isAt(animCtrl, 0.5109) != 0) {
                func_8009DF18(self, 0x418, 1.8, 16000);
            }
            if (anctrl_isAt(animCtrl, 0.5598) != 0) {
                func_8009DF18(self, 0x418, 1.8, 16000);
            }
            if (anctrl_isAt(animCtrl, 0.8587) != 0) {
                func_8009DF18(self, 0x418, 1.8, 16000);
            }
            if (anctrl_isAt(animCtrl, 0.8913) != 0) {
                func_8009DF18(self, 0x418, 1.8, 16000);
            }
            if (sp24 != 0) {
                func_80800030_bskazstill(self, 5U);
            }
            break;
        case 5:
            if (sp24 != 0) {
                if (_bashoes_entrypoint_1(self) != self->unk168.word) {
                    func_80800030_bskazstill(self, 5U);
                }
            } else {
                func_80800030_bskazstill(self, 1U);
            }
            break;
        default:
        case 1:
            if (sp24 != 0) {
                func_80800030_bskazstill(self, 5U);
            }
            break;
    }
    if (anctrl_isStopped(animCtrl) != 0) {
        func_80800030_bskazstill(self, func_80800000_bskazstill(self));
    }
    bs_setState(self, func_808001A4_bskazstill(self, BS_STATE_0_INVALID));
}

s32 bskazstill_entrypoint_3(s32 idx) {
    return D_808008A4_bskazstill[idx];
}

BanjoStateId bskazstill_entrypoint_4(PlayerState *self, BanjoStateId arg1) {
    func_808001A4_bskazstill(self, arg1);
}

void bskazstill_entrypoint_5(PlayerState *self) {
    _bskaz_entrypoint_2(self);
}

void bskazstill_entrypoint_6(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0);
}

void bskazstill_entrypoint_7(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_BB;
    }
    bs_setState(self, func_808001A4_bskazstill(self, next_state));
}

s32 bskazstill_entrypoint_8(s32 idx) {
    return D_808008B4_bskazstill[idx];
}

void func_80800758_bskazstill(PlayerState *self) {
    _bskaz_entrypoint_2(self);
    _bsdrone_entrypoint_2(self);
}

void func_80800780_bskazstill(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    _bsdrone_entrypoint_0(self);
}

void func_808007A8_bskazstill(PlayerState *self) {
    _bsdrone_entrypoint_1(self);
}

s32 bskazstill_entrypoint_9(s32 idx) {
    return D_808008C4_bskazstill[idx];
}

void func_808007DC_bskazstill(PlayerState *self) {
    _bsrest_entrypoint_14(self);
    _bskaz_entrypoint_2(self);
}

void func_80800804_bskazstill(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    _bsrest_entrypoint_16(self);
}

void func_8080082C_bskazstill(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        next_state = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, next_state);
}

s32 bskazstill_entrypoint_10(s32 idx) {
    return D_808008D4_bskazstill[idx];
}
