#include "common.h"

#include "overlays/bs/kaz/spring.h"

extern s32 D_80800430_bskazspring[];

void func_80800000_bskazspring(PlayerState *self) {
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) != BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, func_800F1214(sp1C, 80, 200));
        return;
    }
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void func_80800064_bskazspring(PlayerState *self, s32 arg1) {
    f32 sp2C[3];

    switch (arg1) {
        case 0:
            bastick_popZone(self);
            baphysics_reset_gravity(self);
            baphysics_reset_terminal_velocity(self);
            break;
        case 1:
            baanim_playForDuration_onceSmooth(self, ASSET_142_ANIM_BSKAZSPRING_UNKNOWN, 1.4);
            func_8009FFD8(self, 1, 1, 1, 2);
            baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self) * 0.7f);
            baphysics_set_gravity(self, -1200);
            baphysics_set_terminal_velocity(self, -533.3);
            bastick_pushZone(self);
            bastick_setZoneMax(self, 0, 0.03);
            bastick_setZoneMax(self, 1, 1);
            self->unk160.word = 0;
            break;
        case 2:
            yaw_setUpdateType(self, 2);
            func_8009D2D8(self, 3);
            yaw_rotateTimed(self, 1);
            if (bastick_distance) {
            // if (bastick_distance(self) != 0) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
            }
            baphysics_set_target_yaw(self, yaw_getIdeal(self));
            sp2C[0] = yaw_getIdeal(self);
            baphysics_set_horizontal_velocity(self, sp2C[0], baphysics_get_target_horizontal_velocity(self));
            func_80800000_bskazspring(self);
            baphysics_set_vertical_velocity(self, 1293);
            func_8009DF18(self, 0x45A5, 1, 22000);
            break;
        case 3:
            baanim_playForDuration_loopSmooth(self, ASSET_288_ANIM_BSKAZFLY_UNKNOWN, 00.18);
            break;
    }

    self->unk15C.bytes[0] = (s8) arg1;
}

void func_80800244_bskazspring(s32 self) {
    func_80800064_bskazspring(self,(s8) 0);
    _bskaz_entrypoint_2(self);
}

void func_80800270_bskazspring(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    self->unk15C.bytes[0] = 0;
    func_80800064_bskazspring(self, 1);
}

void func_808002A0_bskazspring(PlayerState *self) {
    BanjoStateId next_state;

    next_state = 0;
    switch (self->unk15C.bytes[0]) {
        case 1:
            if (baanim_isAt(self, 0.22) != 0) {
                func_8009DF94(self, 0x3FF, 0.558, 22000);
            }
            if (baanim_isAt(self, 0.3) != 0) {
                func_80800064_bskazspring(self, 2);
            }
            break;
        case 2:
            func_80800000_bskazspring(self);
            if (baanim_isStopped(self) != 0) {
                func_80800064_bskazspring(self, 3);
            }
            break;
        case 3:
            func_80800000_bskazspring(self);
            if (bakey_released(self, BUTTON_A) != 0) {
                next_state = BS_STATE_DF;
            }
            if (player_isStable(self) != 0) {
                next_state = BS_STATE_DF;
            }
            break;
    }
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        self->unk160.word = 1;
    }
    if ((self->unk160.word != 0) && (baphysics_get_vertical_velocity(self) < 0.0f) && (bainput_func_80097E74(self) != 0)) {
        next_state = BS_STATE_BE;
    }
    bs_setState(self, next_state);
}

s32 bskazspring_entrypoint_0(s32 idx) {
    return D_80800430_bskazspring[idx];
}
