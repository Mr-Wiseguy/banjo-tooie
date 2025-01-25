#include "common.h"

#include "bs/kazeggass.h"

s32 D_808002C0_bskazeggass[];

void bskazeggass_entrypoint_0(PlayerState *self) {
    _bskaz_entrypoint_1();
    baanim_playForDuration_once(self, ASSET_28E_BZKAZEGGASS_UNKNOWN, 0.75);
    func_8009FFD8(self, 1, 3, 1, 3);
    yaw_setVelocityBounded(self, 350, 14);
    baphysics_set_target_horizontal_velocity(self, 0);
    func_800A0CDC(self, 1);
    self->unk160.word = 1;
    self->unk15C.word = 1;
    self->unk164 = func_80094510(self);
    bainput_enable(self, 5, 0);
}

void bskazeggass_entrypoint_1(PlayerState *self) {
    s32 sp2C;
    AnimCtrl *sp28;
    s32 sp24;

    sp2C = 0;
    sp28 = baanim_getAnimCtrlPtr(self);
    sp24 = func_80094BC0(self) != 0;
    if ((bainput_should_poop_egg(self) != 0) && (func_80094B14(self) != 0)) {
        self->unk15C.word = func_800F1418(self->unk15C.word + 1, func_800944E0(self, self->unk164));
    }
    if (sp24 != 0) {
        if (anctrl_isAt(sp28, 0.38) != 0) {
            _baeggsetup_entrypoint_9(self);
            _baeggsetup_entrypoint_2(self, self->unk164, 45, 25);
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
        sp2C = 0xDF;
    }
    if (bakey_held(self, 1) != 0) {
        if (anctrl_isStopped(sp28) != 0) {
            sp2C = 0xDD;
        }
        if (anctrl_getAnimTimer(sp28) > 0.6f) {
            sp2C = _bskazcrouch_entrypoint_0(self, sp2C);
        }
    } else if (anctrl_isStopped(sp28) != 0) {
        sp2C = 0xBB;
    }
    bs_setState(self, sp2C);
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