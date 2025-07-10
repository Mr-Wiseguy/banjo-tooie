#include "overlays/bs/ledge.h"

#ifndef NONMATCHINGS
// Unmatched as the compiler wants to use a0 and then move a0 into v0 instead of using t registers
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ledge/func_80800000_bsledge.s")
#else
// Probably a check whether kazooie should (or can?) attack
s32 func_80800000_bsledge(PlayerState *self) {
    s32 temp_t6;

    temp_t6 = (func_8008E23C(self) == 0);
    if (temp_t6 ) {
        temp_t6 = bakey_pressed(self, BUTTON_B) != 0;
    }

    return temp_t6;
}
#endif

void func_80800040_bsledge(PlayerState *self, f32 arg1[3]) {
    f32 sp34;
    f32 sp30;
    s32 sp2C; // pad
    s32 sp28; // pad
    f32 stick_distance;
    f32 angle;
    f32 sp1C;
    f32 sp18;

    stick_distance = bastick_distance(self);
    if (stick_distance == 0.0f) {
        func_800EFD24(arg1);
        return;
    }
    angle = bastick_getAngleRelativeToBanjo(self);
    sp34 = func_800974FC(self);
    sp30 = func_800F1DCC(angle, sp34);
    sp18 = mlAbsF(sp30);
    if (sp18 > 90.0f) {
        sp18 = 180.0f - sp18;
    }
    if (mlAbsF(sp18) < 10.0f) {
        func_800EFD24(arg1);
        return;
    }
    self->unk15C.word = sp30 < 0.0f ? 1 : -1;
    sp30 = -self->unk15C.word * 90.0f;
    sp1C = func_800F1214(stick_distance, 40.0f, 200.0f);
    arg1[1] = 0.0f;
    func_800EFCD8(arg1, sp34 + sp30, sp1C);
}

void func_808001A8_bsledge(PlayerState *self) {
    if (func_8009E74C(self, 2) == 0) {
        func_8009E474(self);
        if (func_80096388(self) == 7) {
            func_800961AC(self, 1);
        }
        if (func_8008E0E8(self) != 0) {
            _bapackctrl_entrypoint_5(self, 3);
        }
        func_800A4E30(self);
        func_800A2018(self, -1);
        func_80092880(self, 1);
    }
}


static void func_80800324_bsledge(PlayerState *self);
void func_80800238_bsledge(PlayerState *self) {
    if (func_8009E77C(self, 2) == 0) {
        func_8009E4AC(self);
        func_8009E55C(self, 0, 32.0f);
        func_8009E53C(self, 0, 30.0f);
        func_8009E55C(self, 1, 28.0f);
        func_8009E53C(self, 1, 30.0f);
        func_800961AC(self, 7);
        yaw_setIdeal(self, func_800974FC(self));
        yaw_applyIdeal(self);
        self->unk15C.word = 0;
        func_80800324_bsledge(self);
        if (func_8008E0E8(self) != 0) {
            _bapackctrl_entrypoint_5(self, 4);
        }
        func_800A4DFC(self, 0x15);
        func_800A2018(self, 3);
        func_80092880(self, 0);
    }
}

static void func_80800324_bsledge(PlayerState *self) {
    self->unk168.bytes[0] = 2;
    self->unk168.bytes[1] = 0;
}

void func_80800334_bsledge(PlayerState *self) {
    s32 temp_a1;

    temp_a1 = self->unk168.bytes[0];
    self->unk168.bytes[0]--;
    if (temp_a1 == 0) {
        self->unk168.bytes[0] = func_800DC128(1, 3);
        temp_a1 =  D_80801340_bsledge[ (self->unk168.bytes[1])];
        self->unk168.bytes[1]++;
        if (self->unk168.bytes[1] >= 3U) {
            self->unk168.bytes[1] = 0U;
        }
        func_8009DF18(self, temp_a1, func_800DC178(0.8f, 1.0f), 10000);
    }
}

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ledge/func_808003D0_bsledge.s")
#else
// Probably a check whether banjo can pull himself up a ledge
s32 func_808003D0_bsledge(PlayerState *self) {
    if ((bakey_pressed(self, BUTTON_A) != 0) != 0) {
        return (func_80097530(self) != 0);
    }
}
#endif

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ledge/func_80800410_bsledge.s")
#else
s32 func_80800410_bsledge(PlayerState *self) {
    if (((func_80096388(self) ^ 7) == 0) != 0) {
        return func_80097524(self) != 4;
    }
}
#endif

s32 func_80800450_bsledge(PlayerState *self) {
    return func_8009BB5C(self) > 0.0f;
}

void func_80800488_bsledge(PlayerState *self, f32 arg1[3]) {
    func_8009BA9C(self, arg1);
}

void func_808004A8_bsledge(PlayerState *self) {
    f32 sp1C[3];

    func_80800040_bsledge(self, sp1C);
    func_8009BA9C(self, sp1C);
}

void func_808004D8_bsledge(PlayerState *self) {
    yaw_setIdeal(self, func_800974FC(self));
}

void func_80800504_bsledge(PlayerState *self) {
    func_808001A8_bsledge(self);
    func_800A0CF4(self, 0);
    func_8009E55C(self, 2, 0.0f);
}

void func_80800540_bsledge(PlayerState *self) {
    enum asset_e var_a1;

    func_80800238_bsledge(self);
    var_a1 = self->unk15C.word < 0 ? ASSET_1E_ANIM_BSLEDGE_UNKNOWN : ASSET_D_ANIM_BSLEDGE_UNKNOWN;
    baanim_playForDuration_onceSmooth(self, var_a1, 1.3f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_D_END);
    func_80800488_bsledge(self, 0);
    func_800A0CF4(self, 1);
    func_8009E55C(self, 2, 30.0f);
    func_8009E53C(self, 2, 10.0f);
}

void func_808005E0_bsledge(PlayerState *self) {
    enum bs_state_e sp2C;
    f32 sp20[3];

    sp2C = BS_STATE_0_INVALID;
    func_808004D8_bsledge(self);
    if (baanim_isStopped(self) != 0) {
        sp2C = BS_STATE_A6;
    }
    if (baanim_isAt(self, 0.1233f) != 0) {
        func_8009DF94(self, 0x442C, 1.15f, 22000);
    }
    if (baanim_isAt(self, 0.3f) != 0) {
        func_8009DF94(self, 0x442C, 1.1f, 22000);
    }
    if (baanim_getTimer(self) > 0.6329f) {
        func_80800040_bsledge(self, sp20);
        if (func_800EEF24(sp20) != 0) {
            sp2C = BS_STATE_A7;
        }
        if (func_808003D0_bsledge(self) != 0) {
            sp2C = BS_STATE_AA;
        }
        if (func_80800000_bsledge(self) != 0) {
            sp2C = BS_STATE_A9;
        }
        if (bakey_pressed(self, BUTTON_Z) != 0) {
            sp2C = BS_STATE_2F_FALL;
        }
    }
    if (func_80800410_bsledge(self) == 0) {
        sp2C = BS_STATE_2F_FALL;
    }
    bs_setState(self, sp2C);
}

s32 bsledge_entrypoint_0(s32 idx) {
    return D_80801348_bsledge[idx];
}

void func_8080072C_bsledge(PlayerState *self) {
    func_808001A8_bsledge(self);
    func_800961AC(self, 1);
    _batranslate_entrypoint_3(self, 1);
}

void func_80800764_bsledge(PlayerState *self) {
    func_80800238_bsledge(self);
    baanim_playForDuration_onceSmooth(self, ASSET_12_ANIM_BSLEDGE_UNKNOWN, 1.7f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_7_FREEZE);
    func_800961AC(self, 8);
    _batranslate_entrypoint_3(self, 2);
    func_80800488_bsledge(self, 0);
    func_801124D0(func_800A4CA8(self), 6);
}

void func_808007F4_bsledge(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.2f) != 0) {
        func_8009DEC0(self, 0x583, 0.95f, 1.05f, 20000, 20000);
    }
    if (baanim_isAt(self, 0.7f) != 0) {
        func_8009DEC0(self, 0x584, 0.95f, 1.05f, 12000, 12000);
    }
    func_808004D8_bsledge(self);
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_1_IDLE;
    }
    bs_setState(self, next_state);
}

s32 bsledge_entrypoint_1(s32 idx) {
    return D_80801358_bsledge[idx];
}

void func_808008D4_bsledge(PlayerState *self) {
    func_808001A8_bsledge(self);
}

void func_808008F4_bsledge(PlayerState *self) {
    func_80800238_bsledge(self);
    baanim_playForDuration_onceSmooth(self, ASSET_13_ANIM_BSLEDGE_UNKNOWN, 0.8f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_D_END);
    func_80800488_bsledge(self, 0);
    if (bs_getPreviousState(self) == 0x2F) {
        func_8009DEC0(self, 0x58E, 0.95f, 1.05f, 26000, 26000);
        return;
    }
    func_8009DEC0(self, 0x584, 0.95f, 1.05f, 12000, 12000);
}

void func_808009C8_bsledge(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    func_808004A8_bsledge(self);
    func_808004D8_bsledge(self);
    if (baanim_getTimer(self) > 0.3f) {
        if (func_808003D0_bsledge(self) != 0) {
            next_state = BS_STATE_AA;
        }
        if (func_80800450_bsledge(self) != 0) {
            next_state = BS_STATE_A7;
        }
        if (func_80800000_bsledge(self) != 0) {
            next_state = BS_STATE_A9;
        }
        if (bakey_pressed(self, BUTTON_Z) != 0) {
            next_state = BS_STATE_2F_FALL;
        }
    }
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_A6;
    }
    bs_setState(self, next_state);
}

s32 bsledge_entrypoint_2(s32 idx) {
    return D_80801368_bsledge[idx];
}

AssetId func_80800AA0_bsledge(PlayerState *self) {
    return self->unk15C.word < 0 ? ASSET_51_ANIM_BSLEDGE_UNKNOWN: ASSET_6_ANIM_BSLEDGE_UNKNOWN;
}

void func_80800AC0_bsledge(PlayerState *self) {
    func_808001A8_bsledge(self);
}

void func_80800AE0_bsledge(PlayerState *self) {
    func_80800238_bsledge(self);
    baanim_playForDuration_loopSmooth(self, func_80800AA0_bsledge(self), 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_D_END);
    baanim_setDurationRange(self, 0.2f, 2.0f);
    func_8008C9F0(self, 40.0f, 200.0f, 1.5f, 0.65f);
}

void func_80800B70_bsledge(PlayerState *self) {
    enum bs_state_e next_state;
    enum asset_e sp20;

    next_state = BS_STATE_0_INVALID;
    func_808004A8_bsledge(self);
    func_808004D8_bsledge(self);
    sp20 = func_80800AA0_bsledge(self);
    if (anctrl_getIndex(baanim_getAnimCtrlPtr(self)) != sp20) {
        baanim_playForDuration_loopSmooth(self, sp20, 1.0f);
    }
    if (baanim_isAt(self, 0.15f) != 0) {
        func_8009DF94(self, 0x46E, 0.77f, 10000);
    }
    if (baanim_isAt(self, 0.22f) != 0) {
        func_80800334_bsledge(self);
    }
    if (baanim_isAt(self, 0.65f) != 0) {
        func_8009DF94(self, 0x46E, 0.87f, 10000);
    }
    if (baanim_isAt(self, 0.72f) != 0) {
        func_80800334_bsledge(self);
    }
    if (func_80800450_bsledge(self) == 0) {
        next_state = BS_STATE_A6;
    }
    if (func_808003D0_bsledge(self) != 0) {
        next_state = BS_STATE_AA;
    }
    if (func_80800000_bsledge(self) != 0) {
        next_state = BS_STATE_A9;
    }
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        next_state = BS_STATE_2F_FALL;
    }
    if (func_80800410_bsledge(self) == 0) {
        next_state = BS_STATE_2F_FALL;
    }
    bs_setState(self, next_state);
}

s32 bsledge_entrypoint_3(s32 idx) {
    return D_80801378_bsledge[idx];
}

s32 func_80800CF4_bsledge(PlayerState *self, u8 *arg1, u32 arg2) {
    if (self->unk164.word >= arg2) {
        self->unk164.word = 0;
    }

    return arg1[self->unk164.word++];
}

s32 func_80800D24_bsledge(PlayerState *self) {
    if (func_800A3274(self) == 0xA) {
        return func_80800CF4_bsledge(self, D_80801390_bsledge, 5);
    }

    return func_80800CF4_bsledge(self, D_80801388_bsledge, 8);
}

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ledge/func_80800D78_bsledge.s")
#else
// decomp failure
#endif

void func_80800EE0_bsledge(PlayerState *self) {
    func_80800D78_bsledge(self, 0);
    func_808001A8_bsledge(self);
}

void func_80800F0C_bsledge(PlayerState *self) {
    func_80800238_bsledge(self);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_D_END);
    func_80800488_bsledge(self, 0);
    self->unk164.word = 0;
    self->unk160.word = 0;
    func_80800D78_bsledge(self, 1);
}

void func_80800F70_bsledge(PlayerState *self) {
    AnimCtrl *anim_ctrl;
    enum bs_state_e next_state;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    next_state = BS_STATE_0_INVALID;
    func_808004A8_bsledge(self);
    func_808004D8_bsledge(self);
    switch (self->unk160.word) {
        case 1:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_80800D78_bsledge(self, func_80800D24_bsledge(self));
            }
            break;
        case 2:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_80800D78_bsledge(self, func_80800D24_bsledge(self));
            }
            break;
        case 3:
            if (anctrl_isAt(anim_ctrl, 0.007f) != 0) {
                func_8009D874(self);
            }
            if ((anctrl_isAt(anim_ctrl, 0.1983f) != 0) || (anctrl_isAt(anim_ctrl, 0.2302f) != 0)) {
                func_8009DF94(self, 0x418, 1.8f, 16000);
                _bamotor_entrypoint_1(self, 0.5f, 0.25f, 0.4f);
            }
            if (anctrl_isAt(anim_ctrl, 0.2502f) != 0) {
                func_8009DF94(self, 0x445, 1.0f, 28000);
            }
            if (anctrl_isAt(anim_ctrl, 0.376f) != 0) {
                func_8009DF58(self, 0x43EF, 1.6f);
            }
            if (anctrl_isAt(anim_ctrl, 0.4095f) != 0) {
                func_8009DF58(self, 0x43EF, 1.45f);
            }
            if (anctrl_isAt(anim_ctrl, 0.4495f) != 0) {
                func_8009DF58(self, 0x43EF, 1.4f);
            }
            if (anctrl_isAt(anim_ctrl, 0.5395f) != 0) {
                func_8009DF94(self, 0x449, 1.0f, 14000);
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_80800D78_bsledge(self, func_80800D24_bsledge(self));
            }
            break;
        case 4:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_80800D78_bsledge(self, func_80800D24_bsledge(self));
            }
            break;
    }
    if (func_80800450_bsledge(self) != 0) {
        next_state = BS_STATE_A7;
    }
    if (func_808003D0_bsledge(self) != 0) {
        next_state = BS_STATE_AA;
    }
    if (func_80800000_bsledge(self) != 0) {
        next_state = BS_STATE_A9;
    }
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        next_state = BS_STATE_2F_FALL;
    }
    if (func_80800410_bsledge(self) == 0) {
        next_state = BS_STATE_2F_FALL;
    }
    bs_setState(self, next_state);
}

s32 bsledge_entrypoint_4(s32 idx) {
    return D_80801398_bsledge[idx];
}

void bsledge_entrypoint_5(PlayerState *self) {
    _bsrest_entrypoint_14(self);
    func_808001A8_bsledge(self);
}

void bsledge_entrypoint_6(PlayerState *self) {
    func_80800238_bsledge(self);
    func_80800488_bsledge(self, 0);
    _bsrest_entrypoint_15(self, 0);
}

void bsledge_entrypoint_7(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_19(self, NULL) != 0) {
        next_state = BS_STATE_A6;
    }
    bs_setState(self, next_state);
}

s32 bsledge_entrypoint_8(s32 idx) {
    return D_808013A8_bsledge[idx];
}
