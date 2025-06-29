#include "common.h"

#include "overlays/bs/kaz/ow.h"

extern s32 D_808002D0_bskazow[];
extern s32 D_808002E0_bskazow[];

void func_80800000_bskazow(PlayerState *self) {
    _babounce_entrypoint_3(self);
    _bskaz_entrypoint_2(self);
}

void func_80800028_bskazow(PlayerState *self) {
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    _babounce_entrypoint_4(self, 1);
    _babounce_entrypoint_6(self, 0xC9, 0.4692, 2.1, 1.2f);
    func_8008B10C(animCtrl, 0.1792);
}

void func_80800098_bskazow(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.3) != 0) {
        func_800951B4(self);
    }
    if (_babounce_entrypoint_2(self) != 0) {
        _bskazmove_entrypoint_0(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        next_state = BS_STATE_BB;
    }
    if ((player_inWater(self) != 0) && (baphysics_get_vertical_velocity(self) <= 0.0f)) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

s32 bskazow_entrypoint_0(s32 idx) {
    return D_808002D0_bskazow[idx];
}

void func_8080015C_bskazow(PlayerState *self) {
    _babounce_entrypoint_3(self);
    _bskaz_entrypoint_2(self);
}

void func_80800184_bskazow(PlayerState *self) {
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_6(self, 0xC9, 0.4692, 2.5, 1.8f);
    func_8008B10C(animCtrl, 0.1792);
}

void func_808001F0_bskazow(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.3) != 0) {
        func_800951B4(self);
    }
    if (_babounce_entrypoint_2(self) != 0) {
        _bskazmove_entrypoint_0(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        next_state = BS_STATE_BB;
    }
    if ((player_inWater(self) != 0) && (baphysics_get_vertical_velocity(self) <= 0.0f)) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

s32 bskazow_entrypoint_1(s32 idx) {
    return D_808002E0_bskazow[idx];
}

