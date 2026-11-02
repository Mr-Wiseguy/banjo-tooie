#include "bs/beefly.h"

extern s32 D_80800DC0_bsbeefly;
extern s32 D_80800DE8_bsbeefly;
extern s32 D_80800E18_bsbeefly[];
extern s32 D_80800E50_bsbeefly[];
extern s32 D_80800E60_bsbeefly[];
extern s32 D_80800E70_bsbeefly[];
extern s32 D_80800E80_bsbeefly[];
extern f32 D_80800E28_bsbeefly[5];
extern f32 D_80800E3C_bsbeefly[5];

/* .code */

void func_80800000_bsbeefly(PlayerState* self) {
    f32 sp24[3];

    player_getCoords(self, sp24);
    sp24[0] += rand_fBounded(-30.0f, 30.0f);
    sp24[1] += 30.0f + rand_fBounded(0, 30.0f);
    sp24[2] += rand_fBounded(-30.0f, 30.0f);
    func_800BBCB8(sp24, 0, 1.0f, 1, &D_80800DC0_bsbeefly);
}

void func_808000A4_bsbeefly(PlayerState* self) {
    f32 sp24[3];
    s32 sp20;

    sp20 = func_800B5BE4(0x22);
    player_getCoords(self, sp24);
    sp24[1] += 45.0f;
    func_800BABB8(sp20, sp24, 0, 1.0f, &D_80800DE8_bsbeefly);
}

void func_8080010C_bsbeefly(PlayerState* self) {
    _bsbee_entrypoint_1(self);
    baanim_playForDuration_once(self, 0x1DF, 1.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    baphysics_set_gravity(self, -1200.0f);
    self->unk15C.word = 0;
}

void func_808001C4_bsbeefly(PlayerState* self) 
{
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bsbee_entrypoint_2(self);
    switch (self->unk15C.word) 
    {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.266f)) 
            {
                baphysics_set_vertical_velocity(self, 1600.0f);
                func_8009DE38(self, 0x406, 0.7f);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            func_80800000_bsbeefly(self);
            if (anctrl_isStopped(anim_ctrl)) {
                baanim_playForDuration_loopSmooth(self, 0x1DC, 0.38f);
            }
            if (baphysics_get_vertical_velocity(self) < 0.0f) {
                next_state = 0x8C;
            }
            break;
    }
    bs_setState(self, next_state);
}

void func_808002B0_bsbeefly(PlayerState* self)
{
    _bsbee_entrypoint_0(self);
}

s32 bsbeefly_entrypoint_0(s32 arg0) {
    return D_80800E18_bsbeefly[arg0];
}

void func_808002E4_bsbeefly(PlayerState* self) {
    if (func_8009CA70(self, bs_getNextState(self), 0x4000) == 0) {
        func_80093360(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009BF5C(self, 0.0f);
        func_800A4E30(self);
        baphysics_reset_gravity(self);
        baphysics_reset_terminal_velocity(self);
        _baboost_entrypoint_4(self, 0);
        _babuzz_entrypoint_1(self);
        _babee_entrypoint_5(self);
        _bafly_entrypoint_4(self);
        _bafpctrl_entrypoint_18(self, 0);
        func_800947EC(self, 1, 1);
    }
}

void func_8080039C_bsbeefly(PlayerState* self) {
    if (func_8009CA70(self, bs_getPreviousState(self), 0x4000) == 0) {
        _bafly_entrypoint_5(self);
        _babee_entrypoint_6(self);
        _babee_entrypoint_7(self, 6000.0f, 0.2f, 12000.0f);
        func_80093360(self, 65.0f);
        yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
        baroll_setAngularVelocity(self, 500.0f, 2.0f);
        _bafly_entrypoint_20(self);
        baphysics_set_gravity(self, -300.0f);
        baphysics_set_terminal_velocity(self, -99.9f);
        _baboost_entrypoint_3(self);
        _baboost_entrypoint_4(self, 1);
        _babuzz_entrypoint_2(self);
        _bafpctrl_entrypoint_18(self, 1);
    }
}

void func_80800480_bsbeefly(PlayerState* self) {
    f32 sp34;
    f32 sp30;
    f32 sp28[3];
    f32 var_f0;

    sp28[1] = bastick_getX(self);
    _ncbafly_entrypoint_4(func_800A4CA8(self), 2.0f, 2000.0f, 350.0f);
    if (bakey_held(self, BUTTON_R)) {
        yaw_setVelocityBounded(self, 500.0f, 30.0f);
        sp30 = 6.0f;
        var_f0 = 85.0f;
    } else {
        yaw_setVelocityBounded(self, 500.0f, 2.0f);
        sp30 = 3.0f;
        var_f0 = 65.0f;
    }
    baroll_setIdeal(self, ml_map_f(sp28[1], -1.0f, 1.0f, -var_f0, var_f0));
    sp34 = ml_map_f(sp28[1], -1.0f, 1.0f, sp30, -sp30);
    sp34 *= _bafpctrl_entrypoint_3(self);
    yaw_setIdeal(self, yaw_getIdeal(self) + sp34);
}

void func_808005B0_bsbeefly(PlayerState* self) {
    if (func_8009E6EC(self) == 0x18) {
        _baboost_entrypoint_2(self, 1.0f);
        func_8009E830(self, 2);
        return;
    }
    func_80099B94(self);
}

void func_80800600_bsbeefly(PlayerState* self) {
    s32 sp34;
    f32 sp2C[2];

    _bsbee_entrypoint_1(self);
    sp34 = bs_getPreviousState(self);
    baanim_playForDuration_loopSmooth(self, 0x1DC, 0.38f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_3_LOCKED_ROTATION);
    if (baflag_isTrue(self, BA_FLAG_9) != 0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(self, 600.0f);
    }
    sp2C[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C[0], baphysics_get_target_horizontal_velocity(self));
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_800A4DA4(self, 0x16);
    func_8080039C_bsbeefly(self);
    if (sp34 != 0x8B) {
        _baboost_entrypoint_2(self, 1.0f);
        self->unk15C.word = 0;
        return;
    }
    self->unk15C.word = 1;
}

void func_80800708_bsbeefly(PlayerState* self) {
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;
    s32 flap_count;
    f32 volume;
    f32 pitch;
    f32 var_f0;
    f32 var_f2_3;
    f32 angle_degrees;
    f32 *sp30; // used

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bsbee_entrypoint_2(self);
    _bafly_entrypoint_20(self);
    func_80800480_bsbeefly(self);
    _bafly_entrypoint_10(self, 300.0f, 80.0f);
    _bafly_entrypoint_11(self);
    func_8009BFCC(self);
    if (bakey_pressed(self, BUTTON_A)
        && (player_getCoordVertical(self) < 27500.0f)) // playerPosition_getY
    {
        _baboost_entrypoint_2(self, 1.0f); // baflap_add()
    }
    if ((_baboost_entrypoint_1(self) == 0) && player_inWater(self)) {
        _baboost_entrypoint_2(self, 1.0f); // baflap_add()
    }
    flap_count = _baboost_entrypoint_1(self); // baflap_getCount()
    anctrl_setDuration(anim_ctrl, D_80800E28_bsbeefly[flap_count]);
    sp30 = &D_80800E3C_bsbeefly[flap_count];
    volume = 0.9f;
    volume += *sp30;
    pitch = func_8009BFCC(self); // pitch_get
    var_f2_3 = 0.0f;
    if (baphysics_get_vertical_velocity(self) < 0/*.0f*/) {
        if (pitch < 300.0f) {
            // ml_map_f
            var_f2_3 = ml_map_f(pitch, 0/*.0f*/, 80.0f, 0.0f, 0.23f);
        }
        if (pitch > 80.0f) {
            // ml_map_f
            var_f2_3 = ml_map_f(pitch, 300.0f, 360.0f, -0.2f, 0.0f);
        }
    }
    volume += var_f2_3;
    if ((flap_count == 0) && bakey_held(self, BUTTON_B)) {
        volume += 0.12f;
    }
    _babuzz_entrypoint_4(self, volume);
    _babuzz_entrypoint_3(self);
    switch (self->unk15C.word) {                            /* irregular */
        case 0:
            if ((s32)sp30 != (s32)&D_80800E3C_bsbeefly)
            {
                self->unk15C.word = 1;
            }
            break;
        case 1:
            // func_8009BFD8 -> pitch_getIdeal()
            // func_800136E4 -> mlNormalizeAngle
            angle_degrees = func_800136E4(func_8009BFD8(self) - 30.0f);
            if ((angle_degrees > 80.0f) && (angle_degrees < 300.0f)) {
                angle_degrees = 300.0f;
            }
            func_8009BF5C(self, angle_degrees);
            _bafly_entrypoint_21(self);
            if (flap_count != 0) {
                baphysics_set_vertical_velocity(self, (f32) flap_count * 400.0f);
                func_80800000_bsbeefly(self);
            }
            if ((s32)sp30 == (s32)&D_80800E3C_bsbeefly) {
                _bafly_entrypoint_20(self);
                self->unk15C.word = 0;
            }
            break;
    }
    if (bakey_held(self, BUTTON_B)) {
        var_f0 = -1500.0f;
        var_f2_3 = -1800.0f;
    } else {
        var_f0 = -700.0f;
        var_f2_3 = -1000.0f;
    }
    _bafly_entrypoint_8(self, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, var_f0, var_f2_3);
    if (bakey_held(self, BUTTON_B)) {
        func_808000A4_bsbeefly(self);
        baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self) * 3.5f);
    }
    if (bakey_held(self, BUTTON_Z)) {
        _babee_entrypoint_2(self);
    }
    if (_bafly_entrypoint_2(self) && !player_inWater(self)) {
        next_state = 0x85; // Bee Idle?
    }
    _baboost_entrypoint_5(self);
    bs_setState(self, next_state);
}

void func_80800B18_bsbeefly(PlayerState* self)
{
    func_808002E4_bsbeefly(self);
    _bsbee_entrypoint_0(self);
}

s32 bsbeefly_entrypoint_1(s32 arg0) {
    return D_80800E50_bsbeefly[arg0];
}

void func_80800B54_bsbeefly(PlayerState* self)
{
    _bsbee_entrypoint_1(self);
    func_8080039C_bsbeefly(self);
    _bsrest_entrypoint_16(self);
    baphysics_set_gravity(self, 0.0f);
    func_8009BA9C(self, NULL);
}

void func_80800BA4_bsbeefly(PlayerState* self) {
    BanjoStateId sp1C;

    sp1C = BS_STATE_0_INVALID;
    _bsbee_entrypoint_2(self);
    if (_bsrest_entrypoint_20(self) != 0) {
        sp1C = 0x8C;
    }
    bs_setState(self, sp1C);
}

void func_80800BE8_bsbeefly(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_808002E4_bsbeefly(self);
    _bsbee_entrypoint_0(self);
}

s32 bsbeefly_entrypoint_2(s32 arg0) {
    return D_80800E60_bsbeefly[arg0];
}

void func_80800C2C_bsbeefly(PlayerState* self)
{
    _bafly_entrypoint_18(self);
    func_808002E4_bsbeefly(self);
    _bsbee_entrypoint_0(self);
}

void func_80800C5C_bsbeefly(PlayerState* self) {
    _bsbee_entrypoint_1(self);
    func_8080039C_bsbeefly(self);
    _bafly_entrypoint_16(self, 0x1E0, 1.0f);
}

void func_80800C94_bsbeefly(PlayerState* self) {
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2(self);
    _bafly_entrypoint_17(self, 0x8C, 0x85, &sp1C);
}

s32 bsbeefly_entrypoint_3(s32 arg0) {
    return D_80800E70_bsbeefly[arg0];
}

void func_80800CE0_bsbeefly(PlayerState* self)
{
    _bafly_entrypoint_15(self);
    func_808002E4_bsbeefly(self);
    _bsbee_entrypoint_0(self);
}

void func_80800D10_bsbeefly(PlayerState* self) {
    _bsbee_entrypoint_1(self);
    func_8080039C_bsbeefly(self);
    _bafly_entrypoint_13(self, 1, 0xD3, 1.2f);
}

void func_80800D50_bsbeefly(PlayerState* self) {
    _bsbee_entrypoint_2(self);
    _bafly_entrypoint_14(self, 0x8C, 0x85);
}

s32 bsbeefly_entrypoint_4(s32 arg0) {
    return D_80800E80_bsbeefly[arg0];
}
