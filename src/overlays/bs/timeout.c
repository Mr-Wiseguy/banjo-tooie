#include "bs/timeout.h"

extern s32 D_80800330_bstimeout[];
extern s32 D_80800340_bstimeout[];

void bstimeout_entrypoint_0(PlayerState* self) {
    baanim_playForDuration_onceSmooth(self, 0x77, 3.2f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800A4DA4(self, 0xA);
    yaw_setIdeal(self, func_8009F308(self) + 35.0f);
    _ncbadie_entrypoint_3(func_800A4CA8(self), 80.0f);
    func_800FC6B0(0x17U);
    func_800A0CF4(self, 1);
    func_8008E944(self);
}

void bstimeout_entrypoint_1(PlayerState* self) {
    AnimCtrl* sp24;

    sp24 = baanim_getAnimCtrlPtr(self);
    if (anctrl_isAt(sp24, 0.0625f) != 0) {
        func_8009514C(self);
    }
    if (anctrl_isAt(sp24, 0.18f) != 0) {
        func_8009DF18(self, 0x3EB, 1.0f, 0x4650);
    }
    if (anctrl_isAt(sp24, 0.8421f) != 0) {
        func_8009518C(self, 0, 0.3f);
        func_8009518C(self, 1, 0.3f);
    }
    if (anctrl_isAt(sp24, 0.84f) != 0) {
        func_800A05DC(self);
    }
}

void bstimeout_entrypoint_2(PlayerState* self)
{
    func_800951B4(self);
    func_800A4E30(self);
}

s32 bstimeout_entrypoint_3(s32 arg0) {
    return D_80800330_bstimeout[arg0];
}

void bstimeout_entrypoint_4(PlayerState* self) {
    AnimCtrl* sp2C;

    sp2C = baanim_getAnimCtrlPtr(self);
    anctrl_reset(sp2C);
    func_800A0110(self, sp2C);
    anctrl_setPlaybackType(sp2C, 2);
    anctrl_start(sp2C);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_7_FREEZE);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800A4DA4(self, 0xA);
    yaw_setIdeal(self, func_8009F308(self) + 35.0f);
    _ncbadie_entrypoint_3(func_800A4CA8(self), 80.0f);
    func_800FC6B0(0x17U);
    func_8008E944(self);
    _batimer_set(self, 0, 2.9f);
}

void bstimeout_entrypoint_5(PlayerState* self) {
    if (_batimer_decrement(self, 0) != 0) {
        func_800A05DC(self);
    }
}

void bstimeout_entrypoint_6(PlayerState* self) {
    func_800A0CF4(self, 0);
    func_800A4E30(self);
    func_800FC7C4();
}

s32 bstimeout_entrypoint_7(s32 arg0) {
    return D_80800340_bstimeout[arg0];
}
