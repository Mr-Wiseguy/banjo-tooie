#include "overlays/bs/kaz/fly.h"

void func_80800000_bskazfly(PlayerState *self) {
    f32 sp24[3];

    func_8009C128(self, sp24);
    sp24[0] += func_800DC178(-30, 30);
    sp24[1] += 50.0f + func_800DC178(0, 30);
    sp24[2] += func_800DC178(-30, 30);
    func_800BBCB8(sp24, 0, 1, 1, D_80801C10_bskazfly);
}

void func_808000AC_bskazfly(PlayerState *self) {
    func_80093360(self, 60);
    yaw_setUpdateType(self, 3);
    yaw_setVelocityBounded(self, 500, 2);
    baroll_setAngularVelocity(self, 500, 2);
    _bafly_entrypoint_20(self);
    func_800959C8(self, 65, 50);
    func_800961AC(self, 4);
}

void func_80800128_bskazfly(PlayerState *self) {
    if (func_8009E77C(self, 9) == 0) {
        _bastatemem_entrypoint_0(self, 0x20);
        _bafly_entrypoint_5(self);
        func_808000AC_bskazfly(self);
        _baboost_entrypoint_3(self);
        _baboost_entrypoint_4(self, 1);
    }
}

void func_80800188_bskazfly(PlayerState *self) {
    if (func_8009E74C(self, 9) == 0) {
        _bafly_entrypoint_4(self);
        _bastatemem_entrypoint_1(self);
        baphysics_reset_gravity(self);
        baphysics_reset_terminal_velocity(self);
        func_800A0CF4(self, 0);
        func_80093360(self, 0);
        func_800A042C(self);
        yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
        func_800A4E30(self);
        func_80095A40(self);
        func_800961AC(self, 1);
        _baboost_entrypoint_4(self, 0);
        baflag_clear(self, BA_FLAG_2F);
        baflag_clear(self, BA_FLAG_30);
    }
}

void func_80800248_bskazfly(PlayerState *self) {
    baanim_playForDuration_once(self, ASSET_AB_ANIM_BZKAZFLY_UNKNOWN, 1.4);
    func_8009FFD8(self, 1, 1, 3, 6);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }

    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_8009BA9C(self, 0);
    baphysics_set_target_horizontal_velocity(self, 0);
    baphysics_set_gravity(self, -1200);
    func_800A0CF4(self, 1);
    func_8009D874(self);
    self->unk160.word = 0;
    self->unk15C.word = 0;
}

void func_80800320_bskazfly(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *animCtrl;
    s32 sp20;
    s32 temp_v0;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    if (self->unk160.word == 0) {
        if (anctrl_isAt(animCtrl, 0.39) != 0) {
            anctrl_setDuration(animCtrl, 2.4);
            baphysics_set_vertical_velocity(self, 1600);
            func_8009DE38(self, 0x406, 0.7);
            self->unk160.word = 1;
        }
    } else {
        func_80800000_bskazfly(self);
        if (baphysics_get_vertical_velocity(self) < 0.0f) {
            next_state = BS_STATE_162;
        }
    }
    bs_setState(self, next_state);
}

void func_808003E0_bskazfly(PlayerState *self) {
    func_800C6DA0(0x44);
    func_800A0CF4(self, 0);
    func_800A4E30(self);
}

s32 bskazfly_entrypoint_0(s32 idx) {
    return D_80801C38_bskazfly[idx];
}

void func_8080042C_bskazfly(PlayerState *self) {
    f32 sp2C;
    f32 sp28;

    baanim_playForDuration_loopSmooth(self, ASSET_AA_ANIM_BZKAZFLY_UNKNOWN, 0.62);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_3_LOCKED_ROTATION);
    if (baflag_isTrue(self, BA_FLAG_9) != 0) {
        baphysics_set_target_horizontal_velocity(self, 0);
    } else {
        baphysics_set_target_horizontal_velocity(self, 800);
    }
    sp28 = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp28, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_800A0CF4(self, 1);
    baphysics_set_gravity(self, -300);
    baphysics_set_terminal_velocity(self, -50);
    func_800A4DA4(self, 3);
    func_80800128_bskazfly(self);
    self->kazfly->unk0 = 1.0f;
    self->unk160.word = 0;
    self->kazfly->unk1C = 0;
    _bafly_entrypoint_19(self);
}


void func_80800540_bskazfly(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *animCtrl;
    f32 sp40;
    s32 sp38;
    s32 sp34;
    f32 sp30;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    _bafly_entrypoint_9(self);
    _bafly_entrypoint_10(self, 300, 80);
    _bafly_entrypoint_11(self);
    sp34 = 0;
    if (bakey_pressed(self, BUTTON_A) != 0) {
        self->kazfly->unk1C = 1U;
    }
    if ((self->kazfly->unk1C != 0) && ((func_8001211C() % 3) == 0)) {
        self->kazfly->unk1C = 0U;
        sp34 = _bafly_entrypoint_12(self);
    }
    if ((sp34 != 0) || (self->unk15C.word != 0)) {
        if (sp34 != 0) {
            anctrl_setDuration(animCtrl, 0.3);
            _chusefeather_entrypoint_1(self->unk184, 0);
        }
        if (self->unk15C.word != 0) {
            self->unk15C.word = 0;
            _baboost_entrypoint_2(self, 0.35);
        } else {
            _baboost_entrypoint_2(self, 1);
        }
    }
    sp38 = _baboost_entrypoint_1(self);
    _bafly_entrypoint_7(self, 0);
    switch (self->unk160.word) {
        case 0:
            if (sp38 != 0) {
                self->unk160.word = 1;
            }
            break;
        case 1:
            _bafly_entrypoint_7(self, 1);
            sp30 = func_800136E4(func_8009BFD8(self) - 30.0f);
            if (sp30 > 80 && sp30 < 300) {
                sp30 = 300.0f;
            }
            func_8009BF5C(self, sp30);
            _bafly_entrypoint_21(self);
            if (sp38 != 0) {
                baphysics_set_vertical_velocity(self, (f32) sp38 * 600.0f);
            }
            if (sp38 == 0) {
                anctrl_setDuration(animCtrl, 0.62);
                _bafly_entrypoint_20(self);
                self->unk160.word = 0;
            }
            break;
    }
    if (anctrl_isAt(animCtrl, 0.1358) != 0) {
        func_8009DFD4(self, 1023, 0.6, 0.7, 10000, 12000);
    }
    _bafly_entrypoint_8(self, 300, 80, 800, -300.0f, -50.0f, -700.0f, -1000.0f);
    self->kazfly->unk0 = func_800F0E00(self->kazfly->unk0 - func_800D8FF8(), 0);
    if ((self->kazfly->unk0 == 0.0f) && (bakey_pressed(self, BUTTON_B) != 0) && (func_8008D0E0(self) != 0) && (_bafly_entrypoint_12(self) != 0)) {
        next_state = BS_STATE_174;
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_15D;
    }
    if (_bafly_entrypoint_2(self) != 0) {
        next_state = BS_STATE_BB;
    }
    _baboost_entrypoint_5(self);
    bs_setState(self, next_state);
}

void func_808008A8_bskazfly(PlayerState *self) {
    s32 temp_v0;

    baflag_clear(self, BA_FLAG_2F);
    baflag_clear(self, BA_FLAG_30);
    temp_v0 = bs_getNextState(self);
    if (((temp_v0 == 0x173) || (temp_v0 == 0x174) || (temp_v0 == 0x179)) && (_bafpctrl_entrypoint_4(self) == 3)) {
        baflag_set(self, 0x2F);
        if (_bafpctrl_entrypoint_5(self) != 0) {
            baflag_set(self, 0x30);
        }
    }
    _bafpctrl_entrypoint_17(self);
    _bafly_entrypoint_6(self, 0);
    _bafly_entrypoint_7(self, 0);
    func_80800188_bskazfly(self);
}

s32 bskazfly_entrypoint_1(s32 idx) {
    return D_80801C48_bskazfly[idx];
}

void func_80800974_bskazfly(PlayerState *self) {
    f32 sp1C[3];

    func_8009C128(self, sp1C);
    func_800EF04C(sp1C, self->kazfly->unk10);
    func_800A34AC(self, sp1C);
    func_8009DF58(self, 0x40D, 1);
}

void func_808009C8_bskazfly(PlayerState *self, s32 arg1) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    switch (arg1) {
        case 3:
            break;
        case 0:
            func_8009E0DC(self);
            baflag_clear(self, BA_FLAG_1C);
            break;
        case 1:
            baanim_playForDuration_onceSmooth(self, ASSET_29D_ANIM_BSKAZFLY_UNKNOWN, 1);
            func_8009FFD8(self, 1, 1, 3, 7);
            _bafly_entrypoint_1(self, self->kazfly->unk10, &sp34, 4200);
            yaw_setIdeal(self, sp38 + 180.0f);
            func_8009BF5C(self, sp34);
            baroll_setIdeal(self, 0);
            func_8009BA9C(self, self->kazfly->unk10);
            func_800A0CF4(self, 1);
            func_800A4DA4(self, 4);
            _ncbadive_entrypoint_4(func_800A4CA8(self), self->kazfly->unk10);
            _ncbafly_entrypoint_5(func_800A4CA8(self), 1);
            func_8009DF94(self, 0x442E, 1, 28000);
            baflag_clear(self, BA_FLAG_1C);
            func_8009C128(self, self->kazfly->unk4);
            _chusefeather_entrypoint_1(self->unk184, 0);
            break;
        case 2:
            baphysics_set_type(self, 8);
            func_800A4DA4(self, 4);
            _ncbadive_entrypoint_4(func_800A4CA8(self), self->kazfly->unk10);
            anctrl_setDuration(animCtrl, 0.05);
            func_8009DF94(self, 0x4437, 1.3, 0x7FFF);
            baflag_set(self, BA_FLAG_1C);
            _batimer_set(self, 1, 0.0001);
            break;
    }
    self->unk160.word = arg1;
}

void func_80800BDC_bskazfly(PlayerState *self) {
    f32 unk0[3];
    f32 unk1[3];
    s32 pad2;
    f32 unk2;
    s32 unk3;

    func_800EE7F8(unk1, self->kazfly->unk10);
    func_800CA9D8(func_800A4C48(self), &unk3);
    func_800EFA4C(unk0, bastick_getX(self) * 1000.0f, 0.0f, 0.0f);
    func_800EF8BC(unk0, unk0, unk3);
    func_800EF934(unk0, unk0, unk2);
    func_800EF04C(unk1, unk0);
    func_800EFA4C(unk0, 0.0f, -bastick_getY(self) * 1000.0f, 0.0f);
    func_800EF8BC(unk0, unk0, unk3);
    func_800EF934(unk0, unk0, unk2);
    func_800EF04C(unk1, unk0);
    func_8009BA9C(self, unk1);
}

void func_80800CF4_bskazfly(PlayerState *self) {
    func_80800128_bskazfly(self);
    self->unk160.word = 0;
    func_808009C8_bskazfly(self, 1);
}


BanjoStateId func_80800D24_bskazfly(PlayerState *self, BanjoStateId nextState) {
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    s32 sp28;
    s32 is_player_stable;

    if (player_inWater(self) != 0) {
        nextState = BS_STATE_160;
    }

    is_player_stable = player_isStable(self);
    if (func_8009650C(self) == 0 && is_player_stable == 0) {
        return nextState;
    } 

    if (is_player_stable != 0) {
        func_800963C0(self, sp38);
        sp28 = func_80096628(self);
    } else {
        func_80096440(self, sp38);
        sp28 = func_80096434(self);
    }

    func_800EE7F8(sp2C, self->kazfly->unk10);
    func_800EF2A0(sp2C);
    sp44 = mlAbsF(func_800EEAA4(sp38, sp2C));
    if ((baflag_isTrue(self, BA_FLAG_8) != 0) || (sp28 & 0x80)) {
        func_80800974_bskazfly(self);
        nextState = BS_STATE_173;
    } else if (sp44 > 0.4f) {
        if (sp38[1] < 0.65f) {
            func_80800974_bskazfly(self);
            func_800A17A8(self, -1);
            if (func_800A1718(self) != 0) {
                nextState = BS_STATE_177;
            } else {
                nextState = BS_STATE_101;
            }
        } else {
            nextState = BS_STATE_176;
        }
    } else if (is_player_stable != 0) {
        nextState = BS_STATE_176;
    }

    return nextState;
}

void func_80800EB4_bskazfly(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *animCtrl;
    f32 unk0[3];
    s32 pad0;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
    _bafly_entrypoint_11(self);
    func_8009DDDC(self);
    switch (self->unk160.word) {                              
    case 1:
        if (anctrl_isAt(animCtrl, 0.6905) != 0) {
            func_808009C8_bskazfly(self, 2);
        }
        break;
    case 2:
        func_80800BDC_bskazfly(self);
        if (anctrl_isStopped(animCtrl) != 0) {
            anctrl_setIndex(animCtrl, ASSET_29E_ANIM_BSKAZFLY_UNKNOWN);
            anctrl_setDuration(animCtrl, 0.3);
            anctrl_setPlaybackType(animCtrl, 2);
            anctrl_start(animCtrl);
        }
        func_8009C128(self, unk0);
        func_800EF3DC(unk0, self->kazfly->unk4);
        _bafly_entrypoint_6(self, func_800F10B4(func_800EEFD4(unk0), 0, 16000000, 0.2, 0.7f));
        if (func_800EEFD4(unk0) > 1.6e7f) {
            if (bakey_held(self, 9) != 0) {
                func_808009C8_bskazfly(self, 3);
            } else {
                next_state = BS_STATE_175;
            }
        }
        func_80800000_bskazfly(self);
        next_state = func_80800D24_bskazfly(self, next_state);
        break;
    case 3:
        func_80800BDC_bskazfly(self);
        if (bakey_released(self, 9) != 0) {
            next_state = BS_STATE_175;
        } else if (_batimer_decrement(self, 1) != 0) {
            if (_bafly_entrypoint_12(self) != 0) {
                _chusefeather_entrypoint_1(self->unk184, 0);
                _batimer_set(self, 1, 1);
            } else {
                next_state = BS_STATE_175;
            }
        }
        func_80800000_bskazfly(self);
        next_state = func_80800D24_bskazfly(self, next_state);
    }

    bs_setState(self, next_state);
}

void func_808010DC_bskazfly(PlayerState *self) {
    func_808009C8_bskazfly(self, 0);
    func_80800188_bskazfly(self);
}


s32 bskazfly_entrypoint_2(s32 idx) {
    return D_80801C58_bskazfly[idx];
}

void func_8080111C_bskazfly(PlayerState *self) {
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(animCtrl);
    func_8008B1C8(animCtrl, 0.3);
    anctrl_setIndex(animCtrl, ASSET_288_ANIM_BSKAZFLY_UNKNOWN);
    anctrl_setDuration(animCtrl, 0.18);
    anctrl_setPlaybackType(animCtrl, 2);
    anctrl_start(animCtrl);
    func_8009FFD8(self, 1, 1, 3, 3);
    func_800A0CF4(self, 1);
    func_80800128_bskazfly(self);
    func_80095A40(self);
    func_800961AC(self, 1);
    baroll_setIdeal(self, 0);
    func_8009BF5C(self, 0);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    func_80093360(self, 0);
    func_8009DF94(self, 0x442F, 1, 0x7FFF);
    func_8009DB04(self, 0x444, 1, 0x7FFF);
    self->kazfly->unk0 = 0.35f;
    self->unk160.word = 0;
}

void func_80801248_bskazfly(PlayerState *self) {
    BanjoStateId next_state;
    f32 sp28[3];

    next_state = BS_STATE_0_INVALID;
    func_8009BB24(self, sp28);
    if (func_8008DF8C(self, 0x5A) != 0) {
        next_state = BS_STATE_DF;
    }

    self->kazfly->unk0 -= func_800D8FF8();
    if (self->kazfly->unk0 < 0.0f) {
        self->unk15C.word = 1;
        next_state = BS_STATE_162;
    }

    if (bainput_func_80097E74(self) != 0) {
        next_state = BS_STATE_BE;
    }

    if (player_isStable(self) != 0) {
        func_8009FE58(self);
        next_state = BS_STATE_BC;
    }

    if (player_inWater(self) != 0) {
        next_state = BS_STATE_15D;
    }
    bs_setState(self, next_state);
}

void func_80801320_bskazfly(PlayerState *self) {
    s32 temp_v0;

    func_8009E0DC(self);
    func_8009E100(self);
    if (func_8009E74C(self, 9) != 0) {
        func_808000AC_bskazfly(self);
    }

    temp_v0 = bs_getNextState(self);
    if ((temp_v0 == 0x15D) || (temp_v0 == 0x162)) {
        func_8009DBF0(self, 0x4435, 1);
    }

    func_80800188_bskazfly(self);
    func_800A0CF4(self, 0);
}


s32 bskazfly_entrypoint_3(s32 idx) {
    return D_80801C68_bskazfly[idx];
}


void func_808013BC_bskazfly(PlayerState *self) {
    f32 var_f20;

    var_f20 = 0.0f;
    while (var_f20 < 360.0f) {
        _badust_entrypoint_5(self, var_f20, 230);
        var_f20 += 45.0f;
    } 
}

void func_80801448_bskazfly(PlayerState *self) {
    s32 sp2C;

    sp2C = bs_getPreviousState(self);
    baanim_playForDuration_onceSmooth(self, 0x11D, 1.3);
    func_8009FFD8(self, 1, 1, 3, 3);
    func_800A0CF4(self, 1);
    func_8009DF18(self, 0x417, 0.8, 0x7FFF);
    func_8009D820(self, 1.8);
    _bamotor_entrypoint_1(self, 1, 0.5, 0.5);
    if (sp2C == 0xE0) {
        _bssplat_entrypoint_0(self);
    } else {
        func_800A17A8(self, -1);
    }
    if (func_800A1718(self) == 0) {
        _basudie_entrypoint_1(self);
    }
    func_808013BC_bskazfly(self);
    func_8008E944(self);
    self->unk160.word = 0;
}

void func_80801550_bskazfly(PlayerState *self) {
    AnimCtrl *animCtrl;
    AnimCtrl *animCtrl2;

    animCtrl2 = baanim_getAnimCtrlPtr(self);
    animCtrl = animCtrl2;
    if (anctrl_isAt(animCtrl2, 0.3659) != 0) {
        func_8009DF18(self, 0x417, 1, 0x36B0);
        func_8009DF18(self, 0x4454, 1, 0x6D60);
    }
    if (anctrl_isAt(animCtrl, 0.6862) != 0) {
        func_8009DF18(self, 0x417, 0.8, 0x4650);
        func_8009DF18(self, 0x4454, 1, 0x55F0);
    }
    if (anctrl_isAt(animCtrl, 0.92) != 0) {
        baphysics_set_target_horizontal_velocity(self, 0);
    }
    if (anctrl_getAnimTimer(animCtrl) < 0.8f) {
        _badust_entrypoint_9(self);
    }
}

void func_80801640_bskazfly(PlayerState *self) {
    BanjoStateId next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_8009D3A8(self, 0);
    switch (self->unk160.word) {
        case 0:
            func_80801550_bskazfly(self);
            if (anctrl_isAt(anim_ctrl, 0.2) != 0) {
                if (func_800F8B64() != 0) {
                    func_800A0180(self);
                    func_800A4DFC(self, 0xA);
                    _ncbadie_entrypoint_3(func_800A4CA8(self), 30);
                    _basudie_entrypoint_1(self);
                    _batimer_set(self, 0, 3.2);
                    self->unk160.word = 2;
                }
            } else if (anctrl_isAt(anim_ctrl, 0.92) != 0) {
                baanim_playForDuration_onceSmooth(self, ASSET_11E_ANIM_BSKAZFLY_UNKNOWN, 1.6);
                self->unk160.word = 1;
            }
            break;

        case 1:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = BS_STATE_BB;
            }
            if (func_8008DD04(self) != 0) {
                next_state = BS_STATE_DF;
            }
            break;

        case 2:
            func_80801550_bskazfly(self);
            if (_batimer_decrement(self, 0) != 0) {
                _basudie_entrypoint_0(self);
            }
            break;
    }

    bs_setState(self, next_state);
}

void func_808017B0_bskazfly(PlayerState *self) {
    func_800A4E30(self);
    func_800A042C(self);
    func_800A0CF4(self, 0);
    func_8008E95C(self);
}

s32 bskazfly_entrypoint_4(s32 idx) {
    return D_80801C78_bskazfly[idx];
}

void func_80801800_bskazfly(PlayerState *self) {
    func_80800128_bskazfly(self);
    _bafly_entrypoint_13(self, 0, 0x11C, 0.9);
}

void func_80801838_bskazfly(PlayerState *self) {
    _bafly_entrypoint_14(self, 0x162, 0xBB);
}

void func_8080185C_bskazfly(PlayerState *self) {
    _bafly_entrypoint_15();
    func_80800188_bskazfly(self);
}

s32 bskazfly_entrypoint_5(s32 idx) {
    return D_80801C88_bskazfly[idx];
}


void func_80801898_bskazfly(PlayerState *self) {
    func_80800128_bskazfly(self);
    _bafly_entrypoint_13(self, 1, 0x11C, 0.9);
}

void func_808018D0_bskazfly(PlayerState *self) {
    _bafly_entrypoint_14(self, 0x162, 0xBB);
}

void func_808018F4_bskazfly(PlayerState *self) {
    _bafly_entrypoint_15();
    func_80800188_bskazfly(self);
}


s32 bskazfly_entrypoint_6(s32 idx) {
    return D_80801C98_bskazfly[idx];
}

void func_80801930_bskazfly(PlayerState *self) {
    func_80800128_bskazfly(self);
    _bafly_entrypoint_16(self, 0x120, 0.9);
}

void func_80801964_bskazfly(PlayerState *self) {
    _bafly_entrypoint_17(self, 0x162,  0xBB, self->unk15C.bytes);
}

void func_8080198C_bskazfly(PlayerState *self) {
    _bafly_entrypoint_18();
    func_80800188_bskazfly(self);
}

s32 bskazfly_entrypoint_7(s32 idx) {
    return D_80801CA8_bskazfly[idx];
}

void func_808019C8_bskazfly(PlayerState *self) {
    baanim_playForDuration_loopSmooth(self, ASSET_AA_ANIM_BZKAZFLY_UNKNOWN, 0.62);
    func_8009FFD8(self, 1, 1, 3, 7);
    func_800A0CF4(self, 1);
    func_800A4DA4(self, 3);
    func_80800128_bskazfly(self);
}

void func_80801A38_bskazfly(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (anctrl_isAt(baanim_getAnimCtrlPtr(self), 0.1358) != 0) {
        func_8009DEC0(self, 0x3FF, 0.6, 0.7, 10000, 12000);
    }

    if (func_8008E124(self) == 0) {
        next_state = BS_STATE_162;
    }

    bs_setState(self, next_state);
}

void func_80801ABC_bskazfly(PlayerState *self) {
    func_80800188_bskazfly(self);
}

s32 bskazfly_entrypoint_8(s32 idx) {
    return D_80801CB8_bskazfly[idx];
}

void func_80801AF0_bskazfly(PlayerState *self) {
    if (func_8009E6EC(self) == 9) {
        func_8009E830(self, 2);
        baflag_set(self, 7);
        func_800A046C(self);
        return;
    }
    func_80099B94(self);
}

void func_80801B50_bskazfly(PlayerState *self) {
    func_80800128_bskazfly(self);
    _bsdrone_entrypoint_0(self);
    if (_badrone_entrypoint_3(self) == 0xE) {
        baphysics_set_type(self, 7);
    }
}

void func_80801B94_bskazfly(PlayerState *self) {
    _bsdrone_entrypoint_1(self);
}

void func_80801BB4_bskazfly(PlayerState *self) {
    _bsdrone_entrypoint_2(self);
    func_80800188_bskazfly(self);
}

s32 bskazfly_entrypoint_9(s32 idx) {
    return D_80801CC8_bskazfly[idx];
}