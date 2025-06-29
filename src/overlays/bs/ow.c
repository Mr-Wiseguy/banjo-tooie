#include "overlays/bs/ow.h"

void bsow_entrypoint_0(PlayerState *self) {
    _babounce_entrypoint_4(self, 1);
    _babounce_entrypoint_5(self, ASSET_4D_ANIM_BSOW_UNKNOWN, 0.5344f);
}

void bsow_entrypoint_1(PlayerState *self) {
    enum bs_state_e next_State;

    next_State = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.3f) != 0) {
        func_800951B4(self);
    }
    if (_babounce_entrypoint_2(self) != 0) {
        _bswalk_entrypoint_1(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        next_State = BS_STATE_1_IDLE;
    }
    if (_babounce_entrypoint_1(self) == 2) {
        if (func_8008E260(self) != 0) {
            next_State = BS_STATE_3D_FALL_TUMBLING;
        }
        if ((player_inWater(self) != 0) && (baphysics_get_vertical_velocity(self) <= 0.0f)) {
            next_State = BS_STATE_4C_LANDING_IN_WATER;
        }
    }
    bs_setState(self, next_State);
}

void bsow_entrypoint_2(PlayerState *self) {
    _babounce_entrypoint_3(self);
}

s32 bsow_entrypoint_3(s32 idx) {
    return D_80800150_bsow[idx];
}
