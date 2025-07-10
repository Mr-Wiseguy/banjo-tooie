#include "common.h"

#include "overlays/bs/kaz/egghead.h"

s32 D_808002F0_bskazegghead[];

void bskazegghead_entrypoint_0(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_once(self, 0x28D, 0.75f);
    func_8009FFD8(self, 1, 3, 1, 3);
    yaw_setVelocityBounded(self, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800A0CF4(self, 1);
    self->unk160.word = 1;
    self->unk15C.word = 1;
    self->unk164.word = func_80094510(self);
    bainput_enable(self, 2, 0);
}


void bskazegghead_entrypoint_1(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl* sp28;
    s32 sp24;

    next_state = BS_STATE_0_INVALID;
    sp28 = (AnimCtrl*) baanim_getAnimCtrlPtr(self);
    sp24 = func_80094BC0(self) != 0;
    if ((bainput_should_shoot_egg(self) != 0) && (func_80094B14(self) != 0)) {
        self->unk15C.word = func_800F1418(self->unk15C.word + 1, func_800944E0(self, self->unk164.word));
    }
    if (sp24 != 0) {
        if (anctrl_isAt(sp28, 0.1f) != 0) {
            _baeggsetup_entrypoint_10(self);
        }
        if (anctrl_isAt(sp28, 0.4f) != 0) {
            _baeggsetup_entrypoint_8(self, self->unk164.word);
        }
        if (anctrl_isAt(sp28, 0.43f) != 0) {
            _baeggsetup_entrypoint_5(self, self->unk164.word, 33.0f, 80.0f);
            func_800C6DA0(0x43);
        }
        if ((anctrl_isAt(sp28, 0.55f) != 0) && (self->unk160.word < self->unk15C.word)) {
            anctrl_setStart(sp28, 0.32f);
            anctrl_start(sp28);
            self->unk160.word += 1;
        }
    }
    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bakey_held(self, BUTTON_Z) != 0) {
        if (anctrl_isStopped(sp28) != 0) {
            next_state = BS_STATE_DD;
        }
        if (anctrl_getAnimTimer(sp28) > 0.65f) {
            next_state = _bskazcrouch_entrypoint_0(self, next_state);
        }
    } else if (anctrl_isStopped(sp28) != 0) {
        next_state = BS_STATE_BB;
    }
    bs_setState(self, next_state);
}

void bskazegghead_entrypoint_2(PlayerState *self) {
    bainput_enable(self, 2, 1);
    baphysics_reset_gravity(self);
    func_800A0CF4(self, 0);
    _bskaz_entrypoint_2(self);
}

s32 bskazegghead_entrypoint_3(s32 idx) {
    return D_808002F0_bskazegghead[idx];
}
