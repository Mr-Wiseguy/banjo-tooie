#include "overlays/bs/kaz/eggass.h"

s32 D_808002C0_bskazeggass[];

void bskazeggass_entrypoint_0(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_once(self, ASSET_28E_ANIM_BZKAZEGGASS_UNKNOWN, 0.75);
    func_8009FFD8(self, 1, 3, 1, 3);
    yaw_setVelocityBounded(self, 350, 14);
    baphysics_set_target_horizontal_velocity(self, 0);
    func_800A0CDC(self, 1);
    self->unk160.word = 1;
    self->unk15C.word = 1;
    self->unk164.word = func_80094510(self);
    bainput_enable(self, 5, 0);
}

void bskazeggass_entrypoint_1(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *sp28;
    s32 sp24;

    next_state = BS_STATE_0_INVALID;
    sp28 = baanim_getAnimCtrlPtr(self);
    sp24 = func_80094BC0(self) != 0;
    if ((bainput_should_poop_egg(self) != 0) && (func_80094B14(self) != 0)) {
        self->unk15C.word = func_800F1418(self->unk15C.word + 1, func_800944E0(self, self->unk164.word));
    }
    if (sp24 != 0) {
        if (anctrl_isAt(sp28, 0.38) != 0) {
            _baeggsetup_entrypoint_9(self);
            _baeggsetup_entrypoint_2(self, self->unk164.word, 45, 25);
            func_800C6DA0(0x43);
        }
        if ((anctrl_isAt(sp28, 0.6) != 0) && (self->unk160.word < self->unk15C.word)) {
            anctrl_setDuration(sp28, 0.49821422);
            anctrl_setStart(sp28, 0.32);
            anctrl_start(sp28);
            self->unk160.word = (s32) (self->unk160.word + 1);
        }
    }
    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bakey_held(self, 1) != 0) {
        if (anctrl_isStopped(sp28) != 0) {
            next_state = BS_STATE_DD;
        }
        if (anctrl_getAnimTimer(sp28) > 0.6f) {
            next_state = _bskazcrouch_entrypoint_0(self, next_state);
        }
    } else if (anctrl_isStopped(sp28) != 0) {
        next_state = BS_STATE_BB;
    }
    bs_setState(self, next_state);
}

void bskazeggass_entrypoint_2(PlayerState *self) {
    bainput_enable(self, 5, 1);
    baphysics_reset_gravity(self);
    func_800A0CDC(self, 0);
    _bskaz_entrypoint_2(self);
}

s32 bskazeggass_entrypoint_3(s32 idx) {
    return D_808002C0_bskazeggass[idx];
}