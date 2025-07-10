#include "overlays/bs/mum/still.h"

enum bs_state_e func_80800000_bsmumstill(PlayerState *self, enum bs_state_e next_state) {
    switch (bastick_getZone(self)) {
        case BS_STICK_ZONE_ID_0:
            break;
        case BS_STICK_ZONE_ID_1:
            next_state = BS_STATE_E6;
            break;
        case BS_STICK_ZONE_ID_2:
            next_state = BS_STATE_E7;
            break;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        next_state = BS_STATE_E8;
    }
    if (bainput_should_enter_first_person(self) != 0) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008E148(self) != 0) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (bakey_pressed(self, BUTTON_B) != 0) {
        next_state = BS_STATE_F7;
    }
    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_E9;
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_F0;
    }

    return next_state;
}

u8 func_808000EC_bsmumstill(PlayerState *self) {
    if (self->unk160.word >= 2U) {
        self->unk160.word = 0;
    }
    return D_80800400_bsmumstill[self->unk160.word++];
}

void func_8080011C_bsmumstill(PlayerState *self, s32 arg1) {
    if (self->unk15C.word == 0) {
        self->unk160.word = 0;
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        func_800909CC(self);
    }
    self->unk15C.word = arg1;
    switch (self->unk15C.word) {
        case 1:
            baanim_playForDuration_onceSmooth(self, 0xB5, 6.03f);
            return;
        case 2:
            baanim_playForDuration_onceSmooth(self, 0xB6, 2.05f);
            return;
        case 0:
            func_80090A2C(self);
            func_800951B4(self);
            return;
    }
}

void func_808001F0_bsmumstill(PlayerState *self) {
    _bsmum_entrypoint_1(self);
}

void func_80800210_bsmumstill(PlayerState *self) {
    _bsmum_entrypoint_2(self);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
}

void func_8080024C_bsmumstill(PlayerState *self) {
    enum bs_state_e current_state;

    current_state = BS_STATE_0_INVALID;
    if (baanim_isStopped(self) != 0) {
        current_state = BS_STATE_E5;
    }
    bs_setState(self, func_80800000_bsmumstill(self, current_state));
}

s32 bsmumstill_entrypoint_0(s32 idx) {
    return D_80800404_bsmumstill[idx];
}

void func_808002A4_bsmumstill(PlayerState *self) {
    _bsmum_entrypoint_1(self);
    func_8080011C_bsmumstill(self, 0);
}

void func_808002D0_bsmumstill(PlayerState *self) {
    _bsmum_entrypoint_2(self);
    self->unk15C.word = 0;
    func_8080011C_bsmumstill(self, 1);
}

void func_80800300_bsmumstill(PlayerState *self) {
    if (self->unk15C.word == 2) {
        if (baanim_isAt(self, 0.1257f) != 0) {
            func_8009DF18(self, 0x3FF, 1.0f, 32000);
        }
        if (baanim_isAt(self, 0.3957f) != 0) {
            func_8009DF18(self, 0x3FF, 1.1f, 28000);
        }
        if (baanim_isAt(self, 0.572f) != 0) {
            func_8009DF18(self, 0x4BA, 1.2f, 25000);
        }
    }
    if (baanim_isStopped(self) != 0) {
        func_8080011C_bsmumstill(self, func_808000EC_bsmumstill(self));
    }
    bs_setState(self, func_80800000_bsmumstill(self, BS_STATE_0_INVALID));
}

s32 bsmumstill_entrypoint_1(s32 idx) {
    return D_80800414_bsmumstill[idx];
}
