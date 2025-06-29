#include "overlays/bs/rebound.h"

void func_80800000_bsrebound(PlayerState *self) {
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0xF, 0.5823f);
}

void func_80800038_bsrebound(PlayerState *self) {
    enum bs_state_e next_state;
    AnimCtrl *animCtrl;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    if (_babounce_entrypoint_2(self) != 0) {
        _bswalk_entrypoint_1(self);
    }

    if (_babounce_entrypoint_9(self) != 0) {
        next_state = BS_STATE_1_IDLE;
    }

    if (_babounce_entrypoint_1(self) == 2) {
        if (func_8008E260(self) != 0) {
            next_state = BS_STATE_3D_FALL_TUMBLING;
        }
        if ((anctrl_isStopped(animCtrl) != 0) && (func_8008DD04(self) != 0)) {
            next_state = BS_STATE_2F_FALL;
        }
    }

    bs_setState(self, next_state);
}

void func_808000EC_bsrebound(PlayerState *self) {
    _babounce_entrypoint_3(self);
}

s32 bsrebound_entrypoint_0(s32 idx) {
    return D_80800120_bsrebound[idx];
}