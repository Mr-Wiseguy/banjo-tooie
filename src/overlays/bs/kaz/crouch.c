#include "common.h"

#include "overlays/bs/kaz/crouch.h"

extern s32 D_808007C0_bskazcrouch[];

void func_80800000_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_loopSmooth(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f);
    self->unk15C.word = 4;
}

void func_80800034_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_onceSmooth(self, ASSET_141_ANIM_BSKAZCROUCH_UNKNOWN, 3.5f);
    self->unk15C.word = 2;
}

void func_80800068_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_onceSmoothStartingAt(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f, 0.9999f);
    _batimer_set(self, 2, 2.0f);
    self->unk15C.word = 1;
}

void func_808000B4_bskazcrouch(AnimCtrl *anim_ctrl, f32 arg1) {
    anctrl_setDuration(anim_ctrl, func_800F10B4(arg1, 0, 180, 0.5, 0.2));
}

void func_808000FC_bskazcrouch(PlayerState *self, s32 arg1) {
    func_800A2CE8(self, 0.41f, 4);
    func_800A2CE8(self, 0.91f, 3);
}

BanjoStateId bskazcrouch_entrypoint_0(PlayerState* self, BanjoStateId arg1) {
    if (bakey_released(self, BUTTON_Z) != 0) {
        arg1 = BS_STATE_BB;
        if (bakey_pressed(self, BUTTON_A) != 0) {
            arg1 = _bskaz_entrypoint_3(self);
        }
    } else {
        if ((bakey_pressed(self, BUTTON_B) != 0) && (func_800C6E38(0x28) != 0)) {
            arg1 = BS_STATE_C5;
        }
        if (bakey_pressed(self, BUTTON_A) != 0) {
            arg1 = _bskaz_entrypoint_3(self);
        }
        if ((bainput_should_poop_egg(self) != 0) && (func_80094B14(self) != 0)) {
            arg1 = BS_STATE_68;
        }
        if ((bainput_should_shoot_egg(self) != 0) && (func_80094B14(self) != 0)) {
            arg1 = BS_STATE_67;
        }
    }

    return arg1;
}

void bskazcrouch_entrypoint_1(PlayerState *self) {
    AnimCtrl* animCtrl;
    f32 unk0;
    f32 pad0;
    f32 unk1;
    f32 animStart;
    f32 targetYaw;
    s32 unk2;
    f32 unk3;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    unk2 = bs_getPreviousState(self);
    if ((unk2 != 0x67) && (unk2 != 0x68)) {
        animStart = 0;
    } else {
        animStart = 0.8;
    }
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_A8_ANIM_BSKAZCROUCH_UNKNOWN);
    anctrl_setDuration(animCtrl, 0.5);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_setStart(animCtrl, animStart);
    anctrl_start(animCtrl);
    func_8008CA4C(self, 1);
    yaw_setUpdateType(self, 3);
    yaw_setVelocityBounded(self, 350.0f , 14.0f );
    func_8009D2D8(self, 7);
    func_8009CFD8(self, 8.0f);
    baphysics_set_type(self, 3);
    _batimer_set(self, 0, 0.7f);
    _batimer_set(self, 1, 0.2f);
    func_8009BB24(self, &unk1);
    unk3 = sqrtf((unk0 * unk0) + (unk1 * unk1));
    self->unk16C = unk3;
    if (unk3 > 140.0f) {
        func_8009D658(self);
    }
    if (func_800F1EA4(&unk1, &targetYaw) != 0) {
        baphysics_set_target_yaw(self, targetYaw);
    }
    self->unk15C.word = NULL;
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/kaz/crouch/bskazcrouch_entrypoint_2.s")

void bskazcrouch_entrypoint_3(PlayerState *self) {
    _bskaz_entrypoint_2(self);
}


s32 bskazcrouch_entrypoint_4(s32 idx) {
    return D_808007C0_bskazcrouch[idx];
}
