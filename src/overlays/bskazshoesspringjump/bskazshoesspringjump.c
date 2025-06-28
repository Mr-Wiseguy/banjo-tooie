#include "common.h"

#include "overlays/bs/kaz/shoesspringjump.h"

extern s32 D_80800270_bskazshoesspringjump[];

void func_80800000_bskazshoesspringjump(PlayerState *self, s32 arg1) {
    switch (arg1) {
        case 0:
            baphysics_reset_gravity(self);
            break;
        case 1:
            baanim_playForDuration_onceSmooth(self, ASSET_24C_ANIM_BSKAZSHOESSPRINGJUMP_UNKNOWN, 1.9);
            func_8009FFD8(self, 1, 1, 3, 6);
            baphysics_set_target_horizontal_velocity(self, 0);
            baphysics_set_gravity(self, -2700);
            break;
        case 2:
            _bashoes_entrypoint_17(self);
            baphysics_set_type(self, 6);
            baphysics_set_vertical_velocity(self, 3207);
            func_8009DEC0(self, 0x4598, 0.95, 1.05, 0x7FFF, 0x7FFF);
            break;
    }
    self->unk15C.word = arg1;
}

void bskazshoesspringjump_entrypoint_0(PlayerState *self) {
    func_80800000_bskazshoesspringjump(self, 0);
    _bashoes_entrypoint_6(self, 2);
    _bashoes_entrypoint_5(self, 0);
    _bskaz_entrypoint_2(self);
}

void bskazshoesspringjump_entrypoint_1(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    _bashoes_entrypoint_5(self, 1);
    self->unk15C.word = 0;
    func_80800000_bskazshoesspringjump(self, 1);
}

void bskazshoesspringjump_entrypoint_2(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    switch (self->unk15C.word) {
        case 1:
            if (baanim_isAt(self, 0.4744) != 0) {
                func_80800000_bskazshoesspringjump(self, 2);
            }
            break;
        case 2:
            if (baanim_getTimer(self) < 0.87f) {
                _bashoes_entrypoint_16(self);
            }
            _bskazmove_entrypoint_0(self);
            if (baanim_isStopped(self) != 0) {
                next_state = BS_STATE_DF;
            }
            break;
    }
    bs_setState(self, next_state);
}

s32 bskazshoesspringjump_entrypoint_3(s32 idx) {
    return D_80800270_bskazshoesspringjump[idx];
}