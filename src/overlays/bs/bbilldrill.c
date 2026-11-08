#include "bs/bbilldrill.h"


extern s32 D_80800AC8_bsbbilldrill;
extern u32 D_80800AB0_bsbbilldrill[3];
extern s32 D_80800B68_bsbbilldrill[];
extern s32 D_80800B10_bsbbilldrill;
extern s32 D_80800B30_bsbbilldrill;
extern s32 D_80800B50_bsbbilldrill;

/* .code */

void func_80800000_bsbbilldrill(PlayerState* self) {
    self->unk168.word = 0;
}

void func_80800008_bsbbilldrill(PlayerState* self) {
    f32 sp24[3];

    if (func_800BF8E4() > 0) {
        if (self->unk168.word == 0) {
            self->unk168.word = func_800C8A98();
            func_800C8E54(self->unk168.word, 80.0f, 350.0f);
            func_800C8F64(self->unk168.word, 0xB);
        }
        player_getCoords(self, sp24);
        sp24[1] -= 10.0f;
        func_800C8CB8(self->unk168.word, sp24);
        func_800C8E84(self->unk168.word, func_8001210C(1) + &D_80800AB0_bsbbilldrill);
    }
}

void func_808000C0_bsbbilldrill(PlayerState* self) {

    if (self->unk168.word) {
        self->unk168.word = _chlightfader_entrypoint_1(self->unk168.word, 0.6f, 2);
    }
}

void func_80800100_bsbbilldrill(PlayerState* self)
{
    f32 var_f2 = func_80092BF4(self);
    if (var_f2 == 0)
        var_f2 = 8;

    var_f2 = -var_f2;
    func_80093300(self, var_f2);
}

s32 func_80800158_bsbbilldrill(f32 arg0[3]) {
    func_800BABB8(func_800B5BE4(9), arg0, 0, 1.0f, &D_80800AC8_bsbbilldrill);
}

void func_8080019C_bsbbilldrill(PlayerState* self) {
    f32 sp24[3];
    f32 sp20;
    s32 sp1C;

    if (rand_f() <= 0.2f) {
        sp20 = 0.15f;
    } else {
        sp20 = 0.09f;
    }
    player_getCoords(self, sp24);
    sp24[1] -= 80.0f;
    sp1C = func_80800158_bsbbilldrill(sp24);
    func_800BA7C4(sp1C, sp20, sp20);
    func_800BA7FC(sp1C, sp20, sp20);
    func_800BA22C(sp1C, 2);
}

void func_80800250_bsbbilldrill(PlayerState* arg0) {
    f32 sp1C[3];

    player_getCoords(arg0, sp1C);
    sp1C[1] -= 80.0f;
    func_800BA22C(_fxdlsmoke_entrypoint_0(sp1C), 1);
}

void func_80800298_bsbbilldrill(PlayerState* self) {
    _bswalk_entrypoint_1(self);
    baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self) * 0.1f);
}

void func_808002DC_bsbbilldrill(PlayerState* self, s32 arg1) {
    f32 sp34[3];

    self->unk15C.bytes[0] = arg1;
    switch (arg1) {
        case 1:
            self->unk16C = yaw_get(self);
            self->unk170 = 0;
            func_80098520(self, 0);
            _batimer_set(self, 0, 0.3f);
            
            self->unk164.bytes[0] = (bs_getDragonKazooieState() != 0) ? func_8009D454(self, 0, &D_80800B30_bsbbilldrill) : func_8009D454(self, 0, &D_80800B10_bsbbilldrill);
            self->unk15C.bytes[1] = 0;
            return;
        case 2:
            self->unk170 = 1500.0f;
            func_80098520(self, 1.0f);
            _batimer_set(self, 0, 0.15f);
            return;
        case 3:
            func_8009DF18(self, 0x442F, 1.2f, 0x7530);
            baphysics_set_terminal_velocity(self, -5000.0f);
            baphysics_set_gravity(self, -20000.0f);
            baphysics_set_vertical_velocity(self, 2300.0f);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            func_8009E53C(self, 1, -100.0f);
            return;
        case 4:
            ml_vec3f_assign_value(sp34, 0, 80.0f - func_800962D4(self), 0);
            func_8009C1F8(self, sp34);
            _badust_entrypoint_10(self, -func_800962D4(self));
            baflag_set(self, 0x26);
            baphysics_set_gravity(self, 0.0f);
            func_8009BA9C(self, NULL);
            _batimer_set(self, 0, 0.8f);
            _bamotor_entrypoint_3(self, 1.0f, 0.7f, 0.01f, 0.1f, 0.70f, 0.4f);
            _bashake_entrypoint_1(self, 3, 2);
            self->unk160.bytes[0] = func_8009D454(self, 0, &D_80800B50_bsbbilldrill);
            func_8009DE38(self, 0x40D, 1.0f);
            return;
        case 5:
            func_8009E53C(self, 1, 0.0f);
            baflag_clear(self, 0x22);
            func_8009328C(self, yaw_get(self));
            baphysics_set_vertical_velocity(self, 730.0f);
            baphysics_set_gravity(self, -2400.0f);
            baanim_setEndAndDuration(self, 0.7299f, 2.1f);
            func_808000C0_bsbbilldrill(self);
            /* fallthrough */
        default:
            return;
    }
}

void func_808005C0_bsbbilldrill(PlayerState* self) {
    self->unk16C += (self->unk170 * time_getDelta());
    func_8009328C(self, self->unk16C);
}

void bsbbilldrill_entrypoint_0(PlayerState* self) {
    func_800931AC(self, 1);
    func_80093300(self, 0);
    func_80098520(self, 1.0f);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    func_800A0CF4(self, 0);
    baflag_clear(self, 0x22);
    baflag_clear(self, 0x26);
    func_8009E474(self);
    func_808000C0_bsbbilldrill(self);
}

void bsbbilldrill_entrypoint_1(PlayerState* arg0) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x61);
    anctrl_setDuration(temp_v0, 1.02f);
    anctrl_setStart(temp_v0, 0.3637f);
    anctrl_setSubrange(temp_v0, 0.0f, 0.4546f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8009FFD8(arg0, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    baphysics_set_gravity(arg0, 0.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A0CF4(arg0, 1);
    baflag_clear(arg0, 0x22);
    baflag_clear(arg0, 0x26);
    func_800931AC(arg0, 3);
    func_8009E4AC(arg0);
    arg0->unk164.bytes[0] = 0;
    arg0->unk160.bytes[0] = 0;
    arg0->unk15C.bytes[0] = 0;
    func_808002DC_bsbbilldrill(arg0, 1);
    func_80800000_bsbbilldrill(arg0);
}

void bsbbilldrill_entrypoint_2(PlayerState* self) {
    BanjoStateId sp44;
    f32 sp40;
    f32 sp34[3];
    s32 sp30;
    f32 temp_f0;

    sp44 = BS_STATE_0_INVALID;
    switch (self->unk15C.bytes[0]) {
        case 1:
            func_80800298_bsbbilldrill(self);
            temp_f0 = _batimer_get(self, 0);
            sp40 = temp_f0;
            self->unk170 = ml_map_f(temp_f0, 0, 0.3f, 1500.0f, 50.0f);
            func_808005C0_bsbbilldrill(self);
            func_80098520(self, ml_map_f(sp40, 0.0f, 0.3f, 1.0f, 0.0f));
            if (_batimer_decrement(self, 0) != 0) {
                func_808002DC_bsbbilldrill(self, 2);
            }
            break;
        case 2:
            func_80800298_bsbbilldrill(self);
            func_808005C0_bsbbilldrill(self);
            if (_batimer_decrement(self, 0) != 0) {
                func_808002DC_bsbbilldrill(self, 3);
            }
            break;
        case 3:
            func_80096394(self, sp34);
            if (mlAbsF(sp34[1]) < 1.0f) {
                self->unk15C.bytes[1] += 1;
            } else {
                self->unk15C.bytes[1] = 0;
            }
            func_808005C0_bsbbilldrill(self);
            if (baphysics_get_vertical_velocity(self) < 0) {
                baflag_set(self, 0x22);
            }
            if (player_inWater(self) != 0) {
                sp44 = BS_STATE_4C_LANDING_IN_WATER;
            } else if ((func_8008DF8C(self, 0x50) != 0) || ((s32) self->unk15C.bytes[1] >= 4)) {
                if (func_800954E8(self, &sp30) != 0) {
                    sp44 = BS_STATE_72_HARD_LANDING;
                } else {
                    func_808002DC_bsbbilldrill(self, 4);
                }
            }
            break;
        case 4:
            baflag_clear(self, 0x26);
            func_808005C0_bsbbilldrill(self);
            func_80800250_bsbbilldrill(self);
            func_80800100_bsbbilldrill(self);
            func_8080019C_bsbbilldrill(self);
            func_80800008_bsbbilldrill(self);
            if (_batimer_decrement(self, 0) != 0) {
                func_808002DC_bsbbilldrill(self, 5);
            }
            break;
        case 5:
            _bswalk_entrypoint_1(self);
            if (player_inWater(self) != 0) {
                sp44 = BS_STATE_4C_LANDING_IN_WATER;
            }
            if (player_isStable(self) != 0) {
                baanim_setEndAndDuration(self, 1.0f, 1.9f);
                sp44 = BS_STATE_20_LANDING;
            }
            break;
    }
    bs_setState(self, sp44);
}

s32 bsbbilldrill_entrypoint_3(s32 arg0) {
    return D_80800B68_bsbbilldrill[arg0];
}
