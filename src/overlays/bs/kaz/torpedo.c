#include "common.h"

#include "overlays/bs/kaz/torpedo.h"

extern s32 D_80801730_bskaztorpedo[];
extern s32 D_80801740_bskaztorpedo[];
extern s32 D_80801750_bskaztorpedo[];
extern s32 D_80801760_bskaztorpedo[];
extern s32 D_80801770_bskaztorpedo[];
extern s32 D_808017E4_bskaztorpedo[];
extern s32 D_808017F4_bskaztorpedo[];
extern s32 D_80801824_bskaztorpedo[];
extern s32 D_80801854_bskaztorpedo[];
extern s32 D_80801884_bskaztorpedo[];
extern s32 D_80801894_bskaztorpedo[];
extern s32 D_808018A4_bskaztorpedo[];

f32 func_80800000_bskaztorpedo(PlayerState *self) {
    return (func_8009BB94(self) * 100.0f) / 1500.0f;
}

void func_80800034_bskaztorpedo(PlayerState *self) {
    if ((self->unk15C.word != 0) || (bakey_pressed(self, BUTTON_B) != 0) || (_bakaztorpedo_entrypoint_1(self) == 0.0f)) {
        self->unk15C.word = 1;
        func_800F9BC4();
    }
}

void func_8080009C_bskaztorpedo(PlayerState *self) {
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, 0xF);
}

void func_808000CC_bskaztorpedo(PlayerState *self) {
    if (player_inWater(self) != 0) {
        func_8009BFE4(self, 220.0f, 3.5f);
        baroll_setAngularVelocity(self, 120.0f, 1.8f);
        yaw_setVelocityBounded(self, 290.0f, 5.0f);
        return;
    }
    func_8009BFE4(self, 250.0f, 2.8f);
    baroll_setAngularVelocity(self, 250.0f, 2.8f);
    yaw_setVelocityBounded(self, 350.0f, 3.5f);
}

void func_8080016C_bskaztorpedo(PlayerState *self) {
    f32 var_f2;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 pad0;
    f32 sp28;

    sp30 = bastick_getX(self);
    sp34 = func_800D8FF8();
    baroll_setIdeal(self, func_800F10B4(sp30, -1.0f, 1.0f, -45.0f, 45.0f));
    if (player_inWater(self) != 0) {
        sp38 = 260.0f;
    } else {
        sp38 = 350.0f;
    }
    // Following \ is required for comp to match
    sp28 = yaw_getIdeal(self); \
    yaw_setIdeal(self, (func_800F10B4(sp30, -1.0f, 1.0f, sp38, -sp38) * sp34) + sp28);
}

void func_8080024C_bskaztorpedo(PlayerState *self) {
    f32 temp_f0;

    temp_f0 = bastick_getY(self);
    if (temp_f0 < 0.0f) {
        func_8009BF5C(self, func_800F10B4(temp_f0, -1.0f, 0.0f, 275.0f, 360.0f));
        return;
    }
    func_8009BF5C(self, func_800F10B4(temp_f0, 0.0f, 1.0f, 0.0f, 85.0f));
}

void func_808002E0_bskaztorpedo(PlayerState *self) {
    s32 sp44;
    f32 sp38[3];
    f32 sp34;
    s32 temp_v0;
    f32 sp2C[3];

    temp_v0 = player_inWater(self);
    sp44 = temp_v0;
    if (temp_v0 != 0) {
        baphysics_set_gravity(self, 0.0f);
        baphysics_set_terminal_velocity(self, -4000.0f);
        _bamovethrust_entrypoint_4(self, 0.85f);
        _bamovethrust_entrypoint_3(self, self->unk16C);
    } else {
        baphysics_set_gravity(self, -1800.0f);
        baphysics_set_terminal_velocity(self, -4000.0f);
        _bamovethrust_entrypoint_4(self, 0.93f);
        _bamovethrust_entrypoint_3(self, self->unk16C * 0.05f);
    }
    if (bakey_held(self, BUTTON_A) != 0) {
        _bakaztorpedo_entrypoint_6(self, 3);
        self->unk16C = 225.0f;
        if (func_8009650C(self) != 0) {
            self->unk16C *= 0.5f;
        }
    } else {
        _bakaztorpedo_entrypoint_6(self, 2);
        self->unk16C = 22.5f;
    }
    func_808000CC_bskaztorpedo(self);
    _bakaztorpedo_entrypoint_7(self, func_800F10B4(func_8009BB94(self), 0.0f, 1500.0f, 300.0f, 1200.0f));
    sp2C[2] = func_8009BFD8(self);
    sp34 = func_80013728(sp2C[2] - func_8009BFCC(self));
    sp38[0] = yaw_getIdeal(self);
    _bakaztorpedo_entrypoint_5(self, sp34 * 0.75f, func_80013728(sp38[0] - yaw_get(self)) * 0.75f);
    if (sp44 != 0) {
        func_80091290(self, func_800F10B4(self->unk16C, 0.0f, 225.0f, func_800DC178(5.0f, 10.0f), 60.0f), 0, 0xD);
    }
}

void func_80800508_bskaztorpedo(PlayerState *self) {
    if (func_8009E69C(self, 2) == 0) {
        func_800A0DC4(self, 0);
        func_8008C984(self, 3);
        func_800961AC(self, 1);
        func_8009BC34(self);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009C000(self);
        baroll_resetAngularVelocity(self);
        bastick_popZone(self);
        func_80095A40(self);
        func_80093360(self, 0.0f);
        _bakaztorpedo_entrypoint_2(self);
        func_800910BC(self, 1);
        func_800947EC(self, 1, 0);
        _bafpctrl_entrypoint_11(self, 4, 0);
        _bafpctrl_entrypoint_14(self, 1);
        func_8009E474(self);
    }
}

void func_808005F0_bskaztorpedo(PlayerState *self) {
    if (func_8009E6C4(self, 2) == 0) {
        func_800A0DC4(self, 1);
        _bakaztorpedo_entrypoint_4(self);
        self->unk16C = 0.0f;
        func_8008C984(self, 0x6A);
        baphysics_set_gravity(self, 0.0f);
        baphysics_set_terminal_velocity(self, -399.99f);
        func_800961AC(self, 9);
        func_8009BC5C(self, 2.0f);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800959C8(self, 70.0f, 40.0f);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 70.0f);
        func_8009E55C(self, 1, 0.0f);
        func_8009E55C(self, 2, 0.0f);
        func_80093360(self, 50);
        func_800910BC(self, 4);
        func_808000CC_bskaztorpedo(self);
        _bafpctrl_entrypoint_14(self, 2);
        _bafpctrl_entrypoint_9(self, 1);
        _bafpctrl_entrypoint_10(self, 1);
        _bafpctrl_entrypoint_11(self, 4, 1);
        func_800A38F0(self, 0, 0);
        func_800947EC(self, 1, 1);
        self->unk15C.word = 0;
        self->unk160.word = 0;
    }
}

void func_8080076C_bskaztorpedo(PlayerState *self) {
    _bakaztorpedo_entrypoint_8(self);
}

void func_8080078C_bskaztorpedo(PlayerState *self) {
    s32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 temp_f0;
    s32 temp_v0;

    sp44 = _plsu_entrypoint_1(0xA);
    if ((player_isStable(self) != 0) && (player_inWater(self) == 0)) {
        self->unk15C.word = 1;
    }
    if (sp44 != -1) {
        func_800F5A00(sp44, sp38);
        func_8009C128(self, sp2C);
        sp38[1] += 50.0f;
        sp2C[1] += 50.0f;
        temp_f0 = func_800EEB40(sp38, sp2C);
        temp_v0 = self->unk160.word;
        if (temp_v0 != 0) {
            if (temp_f0 < 14400.0f) {
                if (temp_v0 != 0) {
                    self->unk15C.word = 1;
                }
                self->unk160.word = 0;
            }
        } else if (temp_f0 > 22500.0f) {
            self->unk160.word = 1;
        }
    }
}

void func_8080088C_bskaztorpedo(PlayerState *self, s32 arg1) {
    func_800995B8(self, arg1);
    if (bs_getCurrentState(self) != BS_STATE_15A) {
        bs_setState(self, BS_STATE_15A);
        func_8009E830(self, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/kaz/torpedo/func_808008D4_bskaztorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/kaz/torpedo/func_80800A34_bskaztorpedo.s")

void func_80800AF0_bskaztorpedo(PlayerState *self) {
    _batranslate_entrypoint_3(self, 1);
    func_80800508_bskaztorpedo(self);
    self->unk16C = 225.0f;
    _bamovethrust_entrypoint_2(self, 225.0f);
}

void func_80800B34_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    baanim_playForDuration_onceSmoothStartingAt(self, 0x133, 1.5f, 0.2308f);
    func_8080009C_bskaztorpedo(self);
    func_8009B94C(self, 0);
    func_8009BA9C(self, 0);
    _batranslate_entrypoint_3(self, 2);
}

void func_80800BA0_bskaztorpedo(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.9424f) != 0) {
        next_state = BS_STATE_154;
    }
    bs_setState(self, next_state);
}

s32 bskaztorpedo_entrypoint_0(s32 idx) {
    return D_80801730_bskaztorpedo[idx];
}

void func_80800BF8_bskaztorpedo(PlayerState *self) {
    func_80090A2C(self);
    func_80800508_bskaztorpedo(self);
}

void func_80800C20_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    func_8080009C_bskaztorpedo(self);
    baanim_playForDuration_loopSmooth(self, 0x132, 1.0f);
    baanim_setDurationRange(self, 0.3f, 10.0f);
    func_8008C9F0(self, 150.0f, 1500.0f, 1.0f, 0.3f);
    func_8008CA4C(self, BAANIM_UPDATE_2_SCALE_HORZ);
    func_800909CC(self);
}

void func_80800CAC_bskaztorpedo(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_8080076C_bskaztorpedo(self);
    func_8080078C_bskaztorpedo(self);
    func_8080016C_bskaztorpedo(self);
    func_8080024C_bskaztorpedo(self);
    func_808002E0_bskaztorpedo(self);
    func_80800034_bskaztorpedo(self);
    if (func_80800000_bskaztorpedo(self) > 48.0f) {
        next_state = BS_STATE_159;
    }
    bs_setState(self, next_state);
}

s32 bskaztorpedo_entrypoint_1(s32 idx) {
    return D_80801740_bskaztorpedo[idx];
}

void func_80800D48_bskaztorpedo(PlayerState *self) {
    _bsrest_entrypoint_14(self);
    func_80800508_bskaztorpedo(self);
}

void func_80800D70_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    _bsrest_entrypoint_16(self);
    func_8009BA9C(self, 0);
}

void func_80800DA4_bskaztorpedo(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        next_state = BS_STATE_154;
    }
    func_8080076C_bskaztorpedo(self);
    func_8080078C_bskaztorpedo(self);
    bs_setState(self, next_state);
}

s32 bskaztorpedo_entrypoint_2(s32 idx) {
    return D_80801750_bskaztorpedo[idx];
}

void func_80800E04_bskaztorpedo(PlayerState *self) {
    _bsdrone_entrypoint_2(self);
    func_80800508_bskaztorpedo(self);
}

void func_80800E2C_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    _bsdrone_entrypoint_0(self);
}

void func_80800E54_bskaztorpedo(PlayerState *self) {
    func_8080076C_bskaztorpedo(self);
    func_808002E0_bskaztorpedo(self);
    _bsdrone_entrypoint_1(self);
}

s32 bskaztorpedo_entrypoint_3(s32 idx) {
    return D_80801760_bskaztorpedo[idx];
}

void func_80800E98_bskaztorpedo(PlayerState *self) {
    f32 sp1C[3];

    func_800F5A00(_plsu_entrypoint_1(0xA), sp1C);
    sp1C[1] += 50.0f;
    _bamovegoto_entrypoint_12(self, sp1C);
}

void func_80800EE8_bskaztorpedo(PlayerState *self) {
    func_80800508_bskaztorpedo(self);
}

void func_80800F08_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    baanim_playForDuration_loopSmooth(self, 0x135, 0.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_0_NONE);
    func_800961AC(self, 6);
    _bamovegoto_entrypoint_0(self);
    _bamovegoto_entrypoint_7(self, 0.6f);
    func_80800E98_bskaztorpedo(self);
    _bamovegoto_entrypoint_13(self);
    func_800A38F0(self, 0, 0);
    _bafpctrl_entrypoint_14(self, 1);
    self->unk174 = 0.0f;
}

void func_80800FB4_bskaztorpedo(PlayerState *self) {
    Unkfunc_800E0960_1 *sp54;
    f32 sp48[3];
    f32 sp3C[3];
    s32 pad0;
    PlayerState *sp34;
    Unkfunc_800E0960_1 * temp_v0;

    func_80800E98_bskaztorpedo(self);
    sp54 = func_80092AD8(self);
    func_800E0AF0(sp54, 1.0f);
    func_800E0AFC(sp54, 0x6AU, 1.0f, 0.0f, 0.0f, self->unk174);
    if ((baanim_isAt(self, 0.0001f) != 0) || (baanim_isAt(self, 0.5f) != 0)) {
        func_8009DF18(self, 0x3FF, 1.0f, 0x3E80);
    }
    self->unk174 += 1200.0f * func_800D8FF8();
    func_80091290(self, 40.0f, 0, 0xD);
    if (_bamovegoto_entrypoint_4(self) != 0) {
        func_8009C128(self, sp3C);
        func_800EFA4C(sp48, sp3C[0], sp3C[1] - 50.0f, sp3C[2]);
        func_800BABB8(func_8009FBB0(self, sp3C, 80.0f), sp3C, sp48, 1.0f, D_80801770_bskaztorpedo);
        func_800F82C0(self->unk184);
        func_800F911C(1);
        sp34 = func_800F53D0(_plsu_entrypoint_1(0xA));
        _baduo_entrypoint_7(sp34, 1);
        func_800A3410(sp34, 1);
        func_800A3904(sp34, 1);
        func_800D5234(0);
        func_800A16BC(0);
        func_8009DB04(self, 0x45A5, 1.0f, 0x55F0);
        if (bs_getCurrentState(sp34) == 0xED) {
            bs_setState(sp34, BS_STATE_84);
            return;
        }
        func_800A0CF4(sp34, 1);
    }
}

s32 bskaztorpedo_entrypoint_4(s32 idx) {
    return D_808017E4_bskaztorpedo[idx];
}

void func_808011A4_bskaztorpedo(PlayerState *self) {
    s32 result;
    f32 sp2C[2]; // should be of size 3 but can't get it to match that way    

    func_8009E154(self, NULL, sp2C);
    result = func_800BABB8(func_800B5BE4(0x24), sp2C, sp2C, 1.0f, D_808017F4_bskaztorpedo);
    result = func_800BABB8(result, sp2C, sp2C, 1.0f, D_80801824_bskaztorpedo);
    result = func_800BABB8(result, sp2C, sp2C, 1.0f, D_80801854_bskaztorpedo);
}

void func_8080123C_bskaztorpedo(PlayerState *self) {
    baflag_clear(self, 0x35);
    func_80800508_bskaztorpedo(self);
}

void func_80801268_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    baanim_playForDuration_onceSmoothStartingAt(self, 0x132, 0.3f, 0.5f);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(self), 3);
    func_8080009C_bskaztorpedo(self);
    baflag_set(self, 0x35);
    self->unk170 = 0.0f;
}

void func_808012DC_bskaztorpedo(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_8080076C_bskaztorpedo(self);
    func_8080078C_bskaztorpedo(self);
    func_8080016C_bskaztorpedo(self);
    func_8080024C_bskaztorpedo(self);
    func_808002E0_bskaztorpedo(self);
    func_808011A4_bskaztorpedo(self);
    func_80800034_bskaztorpedo(self);
    if (func_80800000_bskaztorpedo(self) < 43.0f) {
        next_state = BS_STATE_154;
    }
    bs_setState(self, next_state);
}

s32 bskaztorpedo_entrypoint_5(s32 idx) {
    return D_80801884_bskaztorpedo[idx];
}

void func_80801380_bskaztorpedo(PlayerState *self) {
    _baspin_entrypoint_1();
    _bakaztorpedo_entrypoint_6(self, 2);
    func_80800508_bskaztorpedo(self);
}

void func_808013B4_bskaztorpedo(PlayerState *self) {
    func_808005F0_bskaztorpedo(self);
    _bakaztorpedo_entrypoint_6(self, 4);
    _baspin_entrypoint_2(self, 0x134, 1.8f, 0, 1);
}

void func_80801400_bskaztorpedo(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_80091290(self, 80.0f, 1, 0xD);
    if (_baspin_entrypoint_3(self) == 2) {
        if (func_8008E124(self) != 0) {
            next_state = BS_STATE_155;
        } else {
            next_state = BS_STATE_154;
        }
    }
    bs_setState(self, next_state);
}

s32 bskaztorpedo_entrypoint_6(s32 idx) {
    return D_80801894_bskaztorpedo[idx];
}

void func_80801484_bskaztorpedo(PlayerState *self) {
    func_8009BD88(self);
    func_8008E95C(self);
    func_800951B4(self);
    yaw_setIdeal(self, func_80092BE8(self));
    yaw_applyIdeal(self);
    func_800931AC(self, 1);
    _bakaztorpedo_entrypoint_6(self, 2);
    func_80800508_bskaztorpedo(self);
}

void func_808014F8_bskaztorpedo(PlayerState *self) {
    f32 sp4C;
    s32 pad0;
    s32 pad1;
    f32 sp40;
    s32 pad2;
    s32 pad3;
    f32 sp34;
    s32 pad4;

    func_808005F0_bskaztorpedo(self);
    _bakaztorpedo_entrypoint_6(self, 4);
    _bareact_entrypoint_1(self, func_80099A58(self));
    baanim_playForDuration_once(self, 0x134, 1.1f);
    func_8009DA40(self);
    func_8009C128(self, &sp40);
    func_800A32C4(self, &sp34);
    func_800F1E6C(&sp34, &sp40, &sp4C);
    yaw_setIdeal(self, sp4C);
    yaw_applyIdeal(self);
    baroll_setIdeal(self, 0.0f);
    func_8009BF5C(self, 0.0f);
    baphysics_set_target_horizontal_velocity(self, _bareact_entrypoint_4(self));
    baphysics_set_target_yaw(self, sp4C);
    baphysics_set_horizontal_velocity(self, sp4C, baphysics_get_target_horizontal_velocity(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    func_8008E944(self);
    func_8009514C(self);
}

void func_80801614_bskaztorpedo(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_80091290(self, 80.0f, 1, 0xD);
    if (baanim_isAt(self, 0.5f) != 0) {
        func_800951B4(self);
    }
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_154;
    }
    bs_setState(self, next_state);
}

s32 bskaztorpedo_entrypoint_7(s32 idx) {
    return D_808018A4_bskaztorpedo[idx];
}