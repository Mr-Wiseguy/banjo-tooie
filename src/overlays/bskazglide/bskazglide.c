#include "common.h"

#include "overlays/bs/kaz/glide.h"

void func_80800000_bskazglide(PlayerState *self) {
    if (func_8009E69C(self, 0x200) == 0) {
        baphysics_reset_gravity(self);
        baphysics_reset_terminal_velocity(self);
        func_80093360(self, 0);
        func_800A042C(self);
        yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
        func_80095A40(self);
        func_800961AC(self, 1);
        func_800A4E30(self);
        _bafly_entrypoint_4(self);
        _bskaz_entrypoint_2(self);
    }
}

void func_80800090_bskazglide(PlayerState *self) {
    if (func_8009E6C4(self, 0x200) == 0) {
        _bskaz_entrypoint_1(self);
        _bafly_entrypoint_5(self);
        _bafly_entrypoint_7(self, 0);
        func_80093360(self, 60);
        yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
        yaw_setVelocityBounded(self, 500, 2);
        baroll_setAngularVelocity(self, 500, 2);
        func_8009BFE4(self, 500, 1.2);
        baphysics_set_gravity(self, -300);
        baphysics_set_terminal_velocity(self, -50.0f);
        func_800959C8(self, 60, 45);
        func_800961AC(self, 4);
        func_800A4DA4(self, 0x17);
        baflag_clear(self, BA_FLAG_12_HAS_FLAPPED);
        baflag_clear(self, BA_FLAG_5_HAS_PECKED);
    }
}

void func_80800184_bskazglide(PlayerState *self) {
    if (func_8009E6EC(self) == 0x23) {
        func_800995B8(self, 1);
        bs_setState(self, BS_STATE_15B);
        func_8009E830(self, 2);
        return;
    }
    func_80099B94(self);
}

void func_808001E8_bskazglide(PlayerState *self) {
    if (func_8009E6EC(self) == 0x23) {
        func_8009E830(self, 2);
        return;
    }
    func_80099B94(self);
}

void func_8080022C_bskazglide(PlayerState *self) {
    func_80800000_bskazglide(self);
}

void func_8080024C_bskazglide(PlayerState *self) {
    s32 sp2C;
    s32 isAboveMaximumVelocity;

    func_80800090_bskazglide(self);
    baanim_playForDuration_loopSmooth(self, ASSET_13D_ANIM_KAZGLIDE_UNKNOWN, 0.8f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_3_LOCKED_ROTATION);
    if (baflag_isTrue(self, BA_FLAG_9) != 0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(self, 600.0f);
    }

    sp2C = func_8009630C(self) < 100.0f;
    isAboveMaximumVelocity = baphysics_get_vertical_velocity(self) > 150;
    if (sp2C || isAboveMaximumVelocity) {
        baphysics_set_vertical_velocity(self, 150);
    }

    _batimer_set(self, 0, 0.38);
    self->unk15C.bytes[1] = 0;
    self->unk15C.bytes[0] = 0;
}

void func_80800364_bskazglide(PlayerState *self) {
    BanjoStateId next_state;
    s32 sp30;

    next_state = BS_STATE_0_INVALID;
    _batimer_decrement(self, 0);
    if (_batimer_get(self, 0) == 0.0f) {
        sp30 = 1;
    } else {
        sp30 = 0;
    }
    _bafly_entrypoint_9(self);
    _bafly_entrypoint_10(self, 300, 80);
    _bafly_entrypoint_11(self);
    _bafly_entrypoint_8(self, 300, 80, 600, -300.0f, -50.0f, -700.0f, -1000.0f);
    if ((func_8008DF8C(self, 0x28) != 0) || ((bakey_released(self, BUTTON_Z) != 0) && (sp30 != 0))) {
        next_state = BS_STATE_DF;
    }
    if (sp30 != 0) {
        if ((bainput_should_feathery_flap(self) != 0) || (self->unk15C.bytes[0] != 0)) {
            next_state = BS_STATE_15C;
        }
        if ((bainput_func_80097FB8(self) != 0) || (self->unk15C.bytes[1] != 0)) {
            next_state = BS_STATE_C4;
        }
    } else {
        if (bainput_should_feathery_flap(self) != 0) {
            self->unk15C.bytes[0] = 1U;
            self->unk15C.bytes[1] = 0U;
        }
        if (bainput_func_80097FB8(self) != 0) {
            self->unk15C.bytes[0] = 0U;
            self->unk15C.bytes[1] = 1U;
        }
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

s32 bskazglide_entrypoint_0(s32 idx) {
    return D_80800AB0_bskazglide[idx];
}

void func_8080050C_bskazglide(PlayerState *self) {
    func_8009BC34(self);
    func_8008E95C(self);
    func_8009BD88(self);
    func_80800000_bskazglide(self);
}

void func_80800544_bskazglide(PlayerState *self) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;

    func_80800090_bskazglide(self);
    baanim_playForDuration_once(self, 0x11C, 1.1);
    func_8009D9D4(self);
    func_8009C128(self, sp3C);
    func_800A32C4(self, sp30);
    func_800F1E6C(sp30, sp3C, &sp2C);
    yaw_setIdeal(self, func_800136E4(sp2C + 180.0f));
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, 400);
    baphysics_set_target_yaw(self, sp2C);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    func_8009FFD8(self, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(self, 800);
    baphysics_set_gravity(self, -1200);
    baphysics_set_terminal_velocity(self, -4000.0f);
    func_8008E944(self);
}

void func_80800650_bskazglide(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0) {
        next_state = BS_STATE_BE;
    }
    if (player_isStable(self) != 0) {
        next_state = BS_STATE_BB;
    }
    bs_setState(self, next_state);
}

s32 bskazglide_entrypoint_1(s32 idx) {
    return D_80800AC0_bskazglide[idx];
}

void func_808006BC_bskazglide(PlayerState *self) {
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    _bskaz_entrypoint_2(self);
}

void func_808006EC_bskazglide(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x13E, 0.4);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_gravity(self, -1100);
    baphysics_set_vertical_velocity(self, 0);
    _batimer_set(self, 0, 1.7);
    baflag_set(self, 0x12);
}

void func_80800780_bskazglide(PlayerState *self) {
    s32 sp34;
    BanjoStateId next_state;
    f32 sp2C;
    f32 temp_f0;

    sp34 = baanim_getAnimCtrlPtr(self);
    next_state = BS_STATE_0_INVALID;
    _bskazmove_entrypoint_0(self);
    _batimer_decrement(self, 0);
    temp_f0 = _batimer_get(self, 0);
    sp2C = temp_f0;
    baphysics_set_terminal_velocity(self, func_800F10B4(temp_f0, 0, 1.2, -1000, -10.0f));
    anctrl_setDuration(sp34, func_800F10B4(sp2C, 0, 1.2, 0.7, 0.2f));
    if (anctrl_isAt(sp34, 0.65) != 0) {
        func_8009DF94(self, 0x3FF, func_800DC178(0.92f, 1.08f), 9000);
    }
    if (anctrl_isAt(sp34, 0.72) != 0) {
        func_8009DF18(self, 0x4431, func_800DC178(0.95f, 1.05f), 17000);
    }
    if ((sp2C < 1.2f) && (bakey_released(self, 8) != 0)) {
        next_state = BS_STATE_DF;
    }
    if (func_8008DF8C(self, 0x28) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bainput_func_80097FB8(self) != 0) {
        next_state = BS_STATE_C4;
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

s32 bskazglide_entrypoint_2(s32 idx) {
    return D_80800AD0_bskazglide[idx];
}

void func_80800944_bskazglide(PlayerState *self) {
    func_80800000_bskazglide(self);
}

void func_80800964_bskazglide(PlayerState *self) {
    func_80800090_bskazglide(self);
    baanim_playForDuration_loopSmooth(self, ASSET_13D_ANIM_KAZGLIDE_UNKNOWN, 0.8);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_7_FREEZE);
}

void func_808009B4_bskazglide(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (func_8008E124(self) == 0) {
        next_state = BS_STATE_BE;
    }
    bs_setState(self, next_state);
}

s32 bskazglide_entrypoint_3(s32 idx) {
    return D_80800AE0_bskazglide[idx];
}

void func_80800A00_bskazglide(PlayerState *self) {
    _bsdrone_entrypoint_2(self);
    func_80800000_bskazglide(self);
}

void func_80800A28_bskazglide(PlayerState *self) {
    func_80800090_bskazglide(self);
    _bsdrone_entrypoint_0(self);
}

void func_80800A50_bskazglide(PlayerState *self) {
    _bsdrone_entrypoint_1(self);
}

s32 bskazglide_entrypoint_4(s32 idx) {
    return D_80800AF0_bskazglide[idx];
}
