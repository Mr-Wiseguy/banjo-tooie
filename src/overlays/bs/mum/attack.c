#include "overlays/bs/mum/attack.h"

void func_80800000_bsmumattack(PlayerState *self) {
    if (self->unk160.bytes[0] != 0) {
        func_800C2FDC(self->unk160.bytes[0]);
        self->unk160.bytes[0] = 0;
    }

    if (self->unk164.word != 0) {
        func_800C8B84(self->unk164.word);
        self->unk164.word = 0;
    }
}

void func_80800054_bsmumattack(PlayerState *self) {
    self->unk160.bytes[0] = 0;
    self->unk164.word = 0;
}

void func_80800060_bsmumattack(PlayerState *self) {
    self->unk160.bytes[0] = func_8009D454(self, 0, D_808006F0_bsmumattack);
    self->unk164.word = func_800C8A98();
    self->unk16C = 1.0f;
}

void func_808000AC_bsmumattack(PlayerState *self, f32 arg1) {
    if (self->unk160.bytes[0] != 0) {
        func_800C31DC(self->unk160.bytes[0], arg1);
    }
}

void func_808000E0_bsmumattack(PlayerState *self) {
    f32 sp3C[3];
    s32 sp30[3];
    f32 sp28[3];
    s32 temp_f10;

    if (self->unk164.word == 0) {
        return;
    }
    
    func_80092C48(self, sp3C);
    func_800C8CB8(self->unk164.word, sp3C);
    if (func_8001210C(1) != 0) {
        temp_f10 = (s32) (self->unk16C * 255);
        sp30[0] = temp_f10;
        sp30[1] = temp_f10;
        sp30[2] = temp_f10;
    } else {
        temp_f10 = (s32)(self->unk16C * 100);
        sp30[0] = temp_f10;
        sp30[2] = 0;
        sp30[1] = temp_f10 * 0; // temp_f10 * 0 is required to match
    }
    sp28[1] = 120;
    sp28[2] = 500;
    func_800C8D4C(self->unk164.word, &sp28[1]);
    func_800C8E84(self->unk164.word, sp30);
}

void func_808001B4_bsmumattack(PlayerState *self, s32 arg1) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    self->unk15C.word = arg1;
    switch (self->unk15C.word) {
        case 0:
            func_8008B2E8(anim_ctrl, 0);
            return;
        case 1:
            _bawandglow_entrypoint_4(self, arg1);
            return;
        case 2:
            if (anctrl_getAnimTimer(anim_ctrl) >= 0.6333f) {
                func_8008B10C(anim_ctrl, 0.5666f);
            }
            anctrl_setSubrange(anim_ctrl, 0.5666f, 0.6333f);
            anctrl_setPlaybackType(anim_ctrl, 4);
            func_8008B2E8(anim_ctrl, 1);
            _batimer_set(self, 0, 3.0f);
            return;
        case 3:
            baflag_clear(self, BA_FLAG_2C);
            _bawandglow_entrypoint_7(self);
            func_8008B2E8(anim_ctrl, 0);
            anctrl_setPlaybackType(anim_ctrl, 1);
            baanim_setEnd(self, 1.0f);
            return;
    }
}

void func_808002E8_bsmumattack(PlayerState *self) {
    func_808001B4_bsmumattack(self, 0);
    _bamum_entrypoint_5(self, 0.0f);
    func_80800000_bsmumattack(self);
    baflag_clear(self, BA_FLAG_2C);
    _bawandglow_entrypoint_5(self);
    _bsmum_entrypoint_1(self);
}

void func_80800344_bsmumattack(PlayerState *self) {
    _bsmum_entrypoint_2(self);
    _bawandglow_entrypoint_6(self);
    self->unk168.word = 1;
    func_80800054_bsmumattack(self);
    baanim_playForDuration_onceSmooth(self, 0x9F, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 8, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 300.0f, 3.5f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    self->unk15C.word = 0;
    func_808001B4_bsmumattack(self, 1);
}

void func_808003DC_bsmumattack(PlayerState *self) {
    AnimCtrl *anim_ctrl;
    enum bs_state_e next_state;
    f32 timer_value;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    next_state = BS_STATE_0_INVALID;
    switch (self->unk15C.word) {
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.15f) != 0) {
                baflag_set(self, BA_FLAG_2C);
            }
            if (anctrl_isAt(anim_ctrl, 0.1815f) != 0) {
                func_8009DE38(self, 0x50D, 1.0f);
                func_8009DBF0(self, 0x3FF, 1.13f);
            }
            if (anctrl_isAt(anim_ctrl, 0.335f) != 0) {
                _bamum_entrypoint_5(self, 1.0f);
                func_80800060_bsmumattack(self);
            }
            if (anctrl_isAt(anim_ctrl, 0.5666f) != 0) {
                if (bakey_held(self, BUTTON_B) != 0) {
                    func_808001B4_bsmumattack(self, 2);
                } else {
                    func_808001B4_bsmumattack(self, 3);
                }
            }
            break;
        case 2:
            _batimer_decrement(self, 0);
            timer_value = _batimer_get(self, 0);
            _bamum_entrypoint_5(self, func_800F10B4(timer_value, 0.0f, 0.7f, 0.0f, 1.0f));
            func_808000AC_bsmumattack(self, func_800F10B4(timer_value, 0.0f, 0.7f, 0.5f, 1.0f));
            self->unk16C = func_800F10B4(timer_value, 0.0f, 0.7f, 0.0f, 1.0f);
            if (_batimer_isAt_falling(self, 0, 0.4f) != 0) {
                _bawandglow_entrypoint_7(self);
            }
            if (_batimer_isAt_falling(self, 0, 0.2f) != 0) {
                baflag_clear(self, BA_FLAG_2C);
            }
            if (_batimer_isZero(self, 0) != 0) {
                if (func_800DC0C0() < 0.5f) {
                    func_8009DE38(self, 0x512, 1.0f);
                } else {
                    func_8009DE38(self, 0x513, 1.0f);
                }
            }
            if ((bakey_held(self, BUTTON_B) == 0) || (_batimer_isZero(self, 0) != 0)) {
                func_808001B4_bsmumattack(self, 3);
            }
            break;
        case 3:
            _bamum_entrypoint_5(self, 0.0f);
            if (anctrl_isAt(anim_ctrl, 0.9f) != 0) {
                next_state = BS_STATE_EF;
            }
            break;
    }
    if (baflag_isTrue(self, BA_FLAG_2C) != 0) {
        _bawandglow_entrypoint_3(self, 60.0f);
    }
    func_808000E0_bsmumattack(self);
    bs_setState(self, next_state);
}

s32 bsmumattack_entrypoint_0(s32 idx) {
    return D_80800700_bsmumattack[idx];
}
