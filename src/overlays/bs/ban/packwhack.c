#include "common.h"

#include "overlays/ba/anim.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/key.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
#include "bs.h"
#include "overlays/bs/state.h"

#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E8F430.h"
#include "core2/1E93440.h"
#include "core2/1ECA640.h"

extern s32 D_808004D0_bsbanpackwhack;
extern BsScript D_8080050C_bsbanpackwhack[4];

extern void _babackpack_entrypoint_5(PlayerState *);
extern void func_800F1574(f32 *, f32);


s32 func_80800000_bsbanpackwhack(s32 arg0, f32 arg1) {
    s32 sp24 = func_800B5BE4(0xA);
    func_800BA77C(sp24, 0, (s16)arg1, 0);
    return func_800BABB8(sp24, arg0, 0, 1.0f, &D_808004D0_bsbanpackwhack);
}

void func_80800074_bsbanpackwhack(PlayerState * self, s32 arg1) {
    s32 tmp_v0 = func_80800000_bsbanpackwhack(arg1, yaw_get(self));
    func_800BA22C(tmp_v0, 1);
}

void bsbanpackwhack_entrypoint_0(PlayerState *self) {
    baflag_clear(self, BA_FLAG_28);
    _babackpack_set_state(self, 1);
    func_800A0CD0(self, 1);
    baphysics_reset_terminal_velocity(self);
    func_8009E474(self);
}

void bsbanpackwhack_entrypoint_1(PlayerState *self) {
    baanim_playForDuration_onceSmooth(self, 0xAF, 1.7f);
    func_8009FFD8(self, 1, 1, 3, 6);
    self->unk16C = baphysics_get_target_horizontal_velocity(self);
    if (player_isStable(self)) {
        self->unk16C = self->unk16C * 0.7f;
    }
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    baphysics_set_terminal_velocity(self, -100.0f);
    baflag_set(self, BA_FLAG_5_HAS_PECKED);
    func_8009E4AC(self);
    self->unk170 = 0.0f;
}

void bsbanpackwhack_entrypoint_2(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    f32 tmp_f0;
    f32 sp28[3];

    if (player_isStable(self)) {
        func_800F1574(&self->unk16C, func_800F0E00(self->unk16C * 0.08f, 3.0f));
    } else {
        func_800F1574(&self->unk16C, func_800F0E00(self->unk16C * 0.04f, 3.0f));
    }
    baphysics_set_target_horizontal_velocity(self, self->unk16C);

    if (anctrl_isAt(anctrl, 0.23f)) {
        func_8009DE38(self, 0x587, 1.0f);
    }

    if (anctrl_isAt(anctrl, 0.25f)) {
        func_8009DF94(self, 0x3FF, 1.0f, 22000);
    }

    if (anctrl_isAt(anctrl, 0.5f)) {
        func_8009DF94(self, 0x3FF, 0.8f, 22000);
    }

    if (_babackpack_get_state(self) == 2) {
        tmp_f0 = anctrl_getAnimTimer(anctrl);
        if ((0.23f < tmp_f0) && (tmp_f0 < 0.695f)){
            _babackpack_entrypoint_6(self, sp28, 0);
            func_80800074_bsbanpackwhack(self, sp28);
        }
    }

    if (self->unk170 != 0.0f) {
        self->unk170 = 0.0f;
        func_8009E55C(self, 2, 50.0f);
        func_8009E4E0(self, 2, _babackpack_entrypoint_5);
        func_8009E5A4(self, 2, 4);
    }

    if (anctrl_isAt(anctrl, 0.1649f)) {
        baflag_set(self, BA_FLAG_28);
        _babackpack_set_state(self, 2);
        func_800A0CD0(self, 0);
        self->unk170 = 1.0f;
    }

    if (anctrl_isAt(anctrl, 0.8247f)) {
        baflag_clear(self, BA_FLAG_28);
        func_8009E4E0(self, 2, NULL);
        _babackpack_set_state(self, 1);
        func_800A0CD0(self, 1);
    }

    if (anctrl_isAt(anctrl, 0.695f)) {
        baphysics_reset_terminal_velocity(self);
    }

    if (anctrl_isStopped(anctrl)) {
        next_state = BS_STATE_1_IDLE;
    }

    if (player_inWater(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }

    if (bakey_pressed(self, BUTTON_A)) {
        next_state = bs_getTypeOfJump(self);
    }
    bs_setState(self, next_state);
}

BsScript bsbanpackwhack_entrypoint_3(BsScriptType type) {
    return D_8080050C_bsbanpackwhack[type];
}
