#include "common.h"

#include "overlays/bs/kaz/wingwhack.h"

extern s32 D_80800920_bskazwingwhack[];
extern s32 D_80800A80_bskazwingwhack[];
extern s32 D_80800AB8_bskazwingwhack[];
extern s32 D_80800AC8_bskazwingwhack[];

void func_80800000_bskazwingwhack(PlayerState *self, f32 arg1[3], f32 arg2, f32 arg3) {
    s32 temp_s0;
    f32 sp30[3];

    temp_s0 = func_800B5BE4(0xA);
    func_8009C128(self, sp30);
    func_800BA77C(temp_s0, 0, func_800136E4(func_800F1DF4(sp30, arg1) + arg2), arg3);
    if (func_8009EA2C() != 0) {
        func_800BA670(temp_s0, 0x619);
    } else {
        func_800BA670(temp_s0, 0x618);
    }
    func_800BABB8(temp_s0, arg1, NULL, 1.0f, D_80800A80_bskazwingwhack);
}

void func_808000DC_bskazwingwhack(PlayerState *self) {
    func_8009E474(self);
    baflag_clear(self, BA_FLAG_36);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    yaw_set(self, func_80092BE8(self));
    func_800931AC(self, 1);
    _bskaz_entrypoint_2(self);
}

void func_80800148_bskazwingwhack(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_onceSmooth(self, 0x138, 1.25f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_3_LOCKED_ROTATION);
    yaw_setVelocityBounded(self, 400.0f, 7.5f);
    baflag_set(self, BA_FLAG_36);
    baflag_set(self, BA_FLAG_5_HAS_PECKED);
    self->unk16C = func_8009BB5C(self);
    self->unk16C = func_800F13F0(self->unk16C, 1200.0f);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    func_800931AC(self, 3);
    func_8009328C(self, yaw_get(self));
    baphysics_set_vertical_velocity(self, 0.0f);
    baphysics_set_gravity(self, -200.0f);
    baphysics_set_terminal_velocity(self, -60.0f);
    func_8009DEC0(self, 0x459E, 0.95f, 1.05f, 26000, 26000);
    func_8009E4AC(self);
    self->unk170 = func_8009E138(self, 1);
}

void func_80800278_bskazwingwhack(PlayerState *self) {
    BanjoStateId next_state;
    f32 sp38[3];
    f32 temp_f0;
    f32 sp34;
    f32 var_f0;

    next_state = BS_STATE_0_INVALID;
    baphysics_set_target_yaw(self, yaw_get(self));
    temp_f0 = baanim_getTimer(self);
    if (temp_f0 < 0.5f) {
        var_f0 = func_800F10B4(temp_f0, 0.0f, 0.15f, self->unk170, 80.0f);
    } else {
        var_f0 = func_800F10B4(temp_f0, 0.8f, 0.6f, self->unk170, 80.0f);
    }
    sp34 = temp_f0;
    func_8009E55C(self, 1, var_f0);
    if (baanim_isAt(self, 0.05f) != 0) {
        func_8009DF94(self, 0x3FF, 1.1f, 12000);
    }
    if (baanim_isAt(self, 0.24f) != 0) {
        func_8009DF94(self, 0x3FF, 1.0f, 12000);
    }
    if (baanim_isAt(self, 0.48f) != 0) {
        func_8009DF94(self, 0x3FF, 0.9f, 12000);
    }
    if ((sp34 > 0.16f) && (sp34 < 0.82f)) {
        func_800F3BD0(self, 7, sp38);
        func_80800000_bskazwingwhack(self, sp38, 45.0f, 0.0f);
        func_800F3BD0(self, 9, sp38);
        func_80800000_bskazwingwhack(self, sp38, 70.0f, 0.0f);
    }
    if ((baanim_isAt(self, 0.64f) != 0) && (func_8008DF8C(self, 0xA) == 0)) {
        next_state = BS_STATE_DF;
    }
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bainput_should_feathery_flap(self) != 0) {
        next_state = BS_STATE_15C;
    }
    bs_setState(self, next_state);
}

s32 bskazwingwhack_entrypoint_0(s32 idx) {
    return D_80800AB8_bskazwingwhack[idx];
}

void func_808004A8_bskazwingwhack(PlayerState *self) {
    func_8009E474(self);
    baflag_clear(self, BA_FLAG_36);
    _bskaz_entrypoint_2(self);
}

void func_808004DC_bskazwingwhack(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_onceSmooth(self, ASSET_137_ANIM_BSKAZWINGWHACK_UNKNOWN, 1.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    func_8009BA9C(self, NULL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009E4AC(self);
    func_8009E5A4(self, 2, 4);
    func_8009E55C(self, 2, 50.0f);
}

void func_80800580_bskazwingwhack(PlayerState *self) {
    AnimCtrl *animCtrl;
    BanjoStateId next_state;
    f32 animTimer;
    f32 sp28[3];
    AnimCtrl *otherAnimCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    next_state = BS_STATE_0_INVALID;
    animTimer = anctrl_getAnimTimer(animCtrl);
    if (anctrl_isAt(animCtrl, 0.27f) != 0) {
        func_8009E5A4(self, 2, 5);
    }
    if (anctrl_isAt(animCtrl, 0.442f) != 0) {
        func_8009E5A4(self, 2, 4);
    }
    if (anctrl_isAt(animCtrl, 0.71f) != 0) {
        func_8009E55C(self, 2, 0.0f);
    }
    baflag_clear(self, BA_FLAG_36);
    func_8009B9F0(self, func_800F3780(animTimer, D_80800920_bskazwingwhack, 0x2C));
    if (anctrl_isAt(animCtrl, 0.104f) != 0) {
        func_8009DF18(self, 0x459F, 1.0f, 26000);
    }
    if (anctrl_isAt(animCtrl, 0.154f) != 0) {
        func_8009DF94(self, 0x3FF, 1.0f, 15000);
    }
    if (anctrl_isAt(animCtrl, 0.317f) != 0) {
        func_8009DF18(self, 0x45A0, 1.05f, 26000);
    }
    if (anctrl_isAt(animCtrl, 0.367f) != 0) {
        func_8009DF94(self, 0x3FF, 1.1f, 15000);
    }
    if (anctrl_isAt(animCtrl, 0.58f) != 0) {
        func_8009DF18(self, 0x45A1, 0.95f, 26000);
    }
    if (anctrl_isAt(animCtrl, 0.63f) != 0) {
        func_8009DF94(self, 0x3FF, 0.9f, 15000);
    }
    if ((animTimer > 0.104f) && (animTimer < 0.222f)) {
        func_800F3BD0(self, 7, sp28);
        func_80800000_bskazwingwhack(self, sp28, 45.0f, 0.0f);
        baflag_set(self, BA_FLAG_36);
    } else if ((animTimer > 0.317f) && (animTimer < 0.4f)) {
        func_800F3BD0(self, 9, sp28);
        func_80800000_bskazwingwhack(self, sp28, func_800136E4(295.0f), 180.0f);
        baflag_set(self, BA_FLAG_36);
    } else if ((animTimer > 0.58f) && (animTimer < 0.7f)) {
        func_800F3BD0(self, 7, sp28);
        func_80800000_bskazwingwhack(self, sp28, 90.0f, -30.0f);
        baflag_set(self, BA_FLAG_36);
    }
    if (anctrl_isStopped(animCtrl) != 0) {
        next_state = BS_STATE_BB;
    }
    if (player_isStable(self) == 0) {
        next_state = BS_STATE_DF;
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

s32 bskazwingwhack_entrypoint_1(s32 idx) {
    return D_80800AC8_bskazwingwhack[idx];
}
