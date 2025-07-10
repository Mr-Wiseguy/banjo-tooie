#include "overlays/bs/mum.h"

void bsmum_entrypoint_13(PlayerState *self);

void func_80800000_bsmum(PlayerState *self) {
    func_8009DE38(self, 0x511, func_800DC178(0.8f, 1.1f));
}

void func_80800040_bsmum(PlayerState *self) {
    if (func_800DC0C0() < 0.5f) {
        func_8009DE38(self, 0x50F, 1.0f);
        return;
    }

    func_8009DE38(self, 0x510, 1.0f);
}

void bsmum_entrypoint_0(PlayerState *self) {
    s32 temp_v0;

    if (func_8009E6EC(self) == 0x43) {
        temp_v0 = bs_getCurrentState(self);
        if ((temp_v0 == 0xE5) || (temp_v0 == 0xE6) || (temp_v0 == 0xE7) || (temp_v0 == 0xF7)) {
            bs_setState(self, BS_STATE_11E);
            func_8009E830(self, 2);
            return;
        }

        func_8009E830(self, 1);
        return;
    }

    func_80099B94(self);
}

void func_80800130_bsmum(PlayerState *self) {
    if (func_8009E6EC(self) == 0x3F) {
        func_80099B94(self);
    }

    _bsdrone_entrypoint_3(self);
}

void bsmum_entrypoint_1(PlayerState *self) {
    if (func_8009E74C(self, 6) != 0) {
        return;
    }
    
    func_800947EC(self, 1, 0);
    func_8009E474(self);
    bastick_resetZones(self);
    func_80093230(self, 1.0f);
    _bamum_entrypoint_4(self, 0);
    func_80092864(self, 1.0f);
}

void bsmum_entrypoint_2(PlayerState *self) {
    if (func_8009E77C(self, 6) != 0) {
        return;
    }

    func_8009E4AC(self);
    func_8009E55C(self, 0, 38.0f);
    func_8009E53C(self, 0, 15.0f);
    func_8009E55C(self, 1, 32.0f);
    func_8009E53C(self, 1, 5.0f);
    func_8009E5A4(self, 2, 0xA);
    bastick_func_8009F2A4(self);
    func_800A0DAC(self, 1);
    func_80093230(self, 0.5f);
    _bamum_entrypoint_4(self, 1);
    func_800947EC(self, 1, 1);
    func_80092864(self, 2.399994f);
}

void func_808002B8_bsmum(PlayerState *self, s32 arg1) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    self->unk15C.word = arg1;
    switch (self->unk15C.word) {                                 
        case 0:
            _basudie_entrypoint_6(self, arg1);
            return;
        case 1:
            self->unk16C = 250.0f;
            _basudie_entrypoint_2(self, 250.0f, 520.0f, -1200.0f);
            anctrl_reset(anim_ctrl);
            anctrl_setSmoothTransition(anim_ctrl, 0);
            anctrl_setIndex(anim_ctrl, ASSET_B8_ANIM_BSMUM_UNKNOWN);
            anctrl_setSubrange(anim_ctrl, 0.0f, 0.4359f);
            anctrl_setDuration(anim_ctrl, 1.9f);
            anctrl_setPlaybackType(anim_ctrl, 1);
            anctrl_start(anim_ctrl);
            func_8009DE38(self, 0x50E, 1.0f);
            return;
        case 2:
            baanim_setEnd(self, 0.812f);
            func_8009DF94(self, 0x417, 0.8f, 18000);
            func_80800040_bsmum(self);
            baphysics_set_vertical_velocity(self, 400.0f);
            return;
        case 3:
            baanim_setEnd(self, 1.0f);
            func_8009DF94(self, 0x417, 0.8f, 18000);
            func_80800040_bsmum(self);
            return;
    }
}

void func_80800428_bsmum(PlayerState *self) {
    func_808002B8_bsmum(self, 0);
    bsmum_entrypoint_1(self);
}

void func_80800454_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    self->unk15C.word = 0;
    func_808002B8_bsmum(self, 1);
}

void func_80800484_bsmum(PlayerState *self) {
    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.word) {
        case 1:
            if (player_isStable(self) != 0) {
                func_808002B8_bsmum(self, 2);
            }
            return;
        case 2:
            if (player_isStable(self) != 0) {
                func_808002B8_bsmum(self, 3);
            }
            break;
        case 3:
            if (self->unk16C > 0.0f) {
                self->unk16C = func_800F0E00(0.0f, self->unk16C - 10.0f);
            }
            break;
    }
}

s32 bsmum_entrypoint_3(s32 idx) {
    return D_80801140_bsmum[idx];
}

void func_80800560_bsmum(PlayerState *self) {
    _bsdrone_entrypoint_2(self);
    bsmum_entrypoint_1(self);
}

void func_80800588_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    _bsdrone_entrypoint_0(self);
}

void func_808005B0_bsmum(PlayerState *self) {
    _bsdrone_entrypoint_1(self);
}

s32 bsmum_entrypoint_4(s32 idx) {
    return D_80801150_bsmum[idx];
}

void func_808005E4_bsmum(PlayerState *self) {
    bsmum_entrypoint_1(self);
}

void func_80800604_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    baanim_playForDuration_loopSmooth(self, ASSET_BB_ANIM_BSMUM_UNKNOWN, 0.6f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    self->unk15C.word = 0;
}

void func_8080065C_bsmum(PlayerState *self) {
    enum bs_state_e next_state;
    f32 sp28[3];

    next_state = BS_STATE_0_INVALID;
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        func_8009B7C0(self);
    } else {
        bsmum_entrypoint_13(self);
    }
    func_8009BB24(self, sp28);
    switch (self->unk15C.word) {
        case 1:
            break;
        case 0:
            if (func_8008DF8C(self, 0x5A) != 0) {
                self->unk15C.word = 1;
            }
            break;
    }
    if (baflag_isFalse(self, BA_FLAG_F) != 0) {
        if (func_8008E260(self) != 0) {
            next_state = BS_STATE_EE;
        }
        if (player_inWater(self) != 0) {
            next_state = BS_STATE_F4;
        }
    } else if (player_inWater(self) != 0) {
        func_800A046C(self);
    }
    if (player_isStable(self) != 0) {
        func_8009FE58(self);
        baanim_playForDuration_onceSmoothStartingAt(self, ASSET_BD_BSMUM_ANIM_UNKNOWN, 0.5f, 0.65f);
        next_state = BS_STATE_EF;
    }
    bs_setState(self, next_state);
}

s32 bsmum_entrypoint_5(s32 idx) {
    return D_80801160_bsmum[idx];
}

#ifndef NONMATCHINGS
void func_808007A0_bsmum(PlayerState *self, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/mum/func_808007A0_bsmum.s")
#else
// Decomp failure
#endif

void func_80800980_bsmum(PlayerState *self) {
    bsmum_entrypoint_1(self);
    func_808007A0_bsmum(self, 0);
    if (bs_getNextState(self) == 0xEF) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
    }
}

void func_808009C8_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    self->unk15C.word = 0;
    func_808007A0_bsmum(self, 1);
}

void func_808009F8_bsmum(PlayerState *self) {
    enum bs_state_e next_state;
    AnimCtrl *anim_ctrl;
    f32 sp24[3];

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (baflag_isTrue(self, BA_FLAG_F) != 0) {
        func_8009B7C0(self);
    } else {
        bsmum_entrypoint_13(self);
    }
    func_8009BB24(self, sp24);
    if (((bakey_released(self, BUTTON_A) != 0) && (sp24[1] > 0.0f)) || (func_8008D544(self) == 0)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word) {
        case 3:
        case 4:
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_808007A0_bsmum(self, 2);
            }
            if (func_8008DF8C(self, 0x82) != 0) {
                func_808007A0_bsmum(self, 4);
            }
            break;
        case 2:
            if (baanim_isStopped(self) != 0) {
                next_state = BS_STATE_E9;
            }
            if (func_8008DF8C(self, 0x5A) != 0) {
                func_808007A0_bsmum(self, 3);
            }
            break;
    }
    if (func_8008E260(self) != 0) {
        next_state = BS_STATE_EE;
    }
    if (player_isStable(self) != 0) {
        func_8009FE58(self);
        next_state = BS_STATE_EF;
    }
    if ((sp24[1] < 0.0f) && (player_inWater(self) != 0)) {
        next_state = BS_STATE_F4;
    }
    bs_setState(self, next_state);
}

s32 bsmum_entrypoint_6(s32 idx) {
    return D_80801170_bsmum[idx];
}

void func_80800BC4_bsmum(PlayerState *self) {
    _babounce_entrypoint_3(self);
    bsmum_entrypoint_1(self);
}

void func_80800BEC_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    _babounce_entrypoint_4(self, 1);
    _babounce_entrypoint_5(self, 0xB7, 0.5569f);
}

void func_80800C2C_bsmum(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.5f) != 0) {
        func_800951B4(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        next_state = BS_STATE_E5;
    }
    if ((player_inWater(self) != 0) && (baphysics_get_vertical_velocity(self) <= 0.0f)) {
        next_state = BS_STATE_F4;
    }
    bs_setState(self, next_state);
}

s32 bsmum_entrypoint_7(s32 idx) {
    return D_80801180_bsmum[idx];
}

void bsmum_entrypoint_8(PlayerState *self) {
    _babounce_entrypoint_3(self);
    bsmum_entrypoint_1(self);
}

void bsmum_entrypoint_9(PlayerState *self) {
    bsmum_entrypoint_2(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0xB7, 0.5569f);
}

void bsmum_entrypoint_10(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_9(self) != 0) {
        next_state = BS_STATE_E5;
    }
    if ((player_inWater(self) != 0) && (baphysics_get_vertical_velocity(self) <= 0.0f)) {
        next_state = BS_STATE_F4;
    }
    bs_setState(self, next_state);
}

s32 bsmum_entrypoint_11(s32 idx) {
    return D_80801190_bsmum[idx];
}

void func_80800DC0_bsmum(PlayerState *self) {
    _bsrest_entrypoint_14(self);
    bsmum_entrypoint_1(self);
}

void func_80800DE8_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    _bsrest_entrypoint_16(self);
}

void func_80800E10_bsmum(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        next_state = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, next_state);
}

s32 bsmum_entrypoint_12(s32 idx) {
    return D_808011A0_bsmum[idx];
}

void bsmum_entrypoint_13(PlayerState *self) {
    f32 zone_position;
    s32 stick_zone;
    s32 pad0[3];
    f32 min_velocity;

    zone_position = bastick_getZonePosition(self);
    stick_zone = bastick_getZone(self);
    if ((func_8008DE24(self) != 0) && (player_isStable(self) != 0)) {
        if (stick_zone == BS_STICK_ZONE_ID_0) {
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            return;
        }
        baphysics_set_target_horizontal_velocity(self, func_800F1214(bastick_distance(self), 30.0f, 150.0f));
        return;
    }
    switch (stick_zone) {
        case BS_STICK_ZONE_ID_0:
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            return;
        case BS_STICK_ZONE_ID_1:
            min_velocity = _bsmummove_entrypoint_2(self);
            baphysics_set_target_horizontal_velocity(self, func_800F1214(zone_position, min_velocity, _bsmummove_entrypoint_1(self)));
            return;
        case BS_STICK_ZONE_ID_2:
            min_velocity = _bsmummove_entrypoint_1(self);
            baphysics_set_target_horizontal_velocity(self, func_800F1214(zone_position, min_velocity, _bsmummove_entrypoint_0(self)));
            return;
    }
}

void func_80800FA4_bsmum(PlayerState *self) {
    bsmum_entrypoint_1(self);
    func_800A042C(self);
    func_80093360(self, 0.0f);
    func_8009E0DC(self);
}

void func_80800FE0_bsmum(PlayerState *self) {
    bsmum_entrypoint_2(self);
    baanim_playForDuration_loop(self, 0xBC, 0.35f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    func_80093360(self, 60.0f);
    func_8009DF18(self, 0x5A3, 1.0f, 0x7FFF);
}

void func_80801058_bsmum(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    bsmum_entrypoint_13(self);
    if (func_8008DF8C(self, 0x190) != 0) {
        func_8009BF5C(self, 180.0f);
    } else {
        func_8009BF5C(self, func_8009BFD8(self) + 20.0f);
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_F4;
    }
    if (player_isStable(self) != 0) {
        next_state = BS_STATE_FF;
    }
    bs_setState(self, next_state);
}

s32 bsmum_entrypoint_14(s32 idx) {
    return D_808011B0_bsmum[idx];
}
