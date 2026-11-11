#include "bs/snowball.h"

extern s32 D_80800F30_bssnowball[];
extern s32 D_80800F84_bssnowball[];
extern s32 D_80801028_bssnowball[];
extern s32 D_80801054_bssnowball[];
extern s32 D_80801064_bssnowball[];
extern s32 D_80801074_bssnowball[];
extern s32 D_80801084_bssnowball[];
extern s32 D_80801094_bssnowball[];
extern s32 D_808010A4_bssnowball[];
extern s32 D_808010B4_bssnowball[];
extern s32 D_808010C4_bssnowball[];
extern s32 D_808010D4_bssnowball[];

f32 func_80800000_bssnowball(PlayerState* self) {
    f32 sp20;
    f32 temp_f0;

    temp_f0 = ml_remainder_f(ml_map_f(_basnowball_entrypoint_3(self), 0.0f, 360.0f, 0.0f, 1.0f), 1.0f);
    sp20 = temp_f0;
    func_8008C990(self, temp_f0);
    return temp_f0;
}

void func_80800064_bssnowball(PlayerState* self, s32 arg1) {
    f32 sp24;

    sp24 = bastick_getZonePosition(self);
    if ((arg1 != 0) && (bakey_held(self, BUTTON_B) != 0)) {
        baphysics_set_target_horizontal_velocity(self, 1400.0f);
        _basnowball_entrypoint_7(self);
        return;
    }
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 30.0f, 700.0f));
}

BanjoStateId func_8080010C_bssnowball(PlayerState* self, BanjoStateId arg1)
{

    if (bainput_should_enter_first_person(self) != 0)
    {
        arg1 = _badrone_entrypoint_24(self);
    }

    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = 0x17F;
    }
    return arg1;
}

void func_80800164_bssnowball(PlayerState* self) {
    yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
    yaw_setVelocityBounded(self, 300.0f, 6.0f);
}

void bssnowball_entrypoint_0(PlayerState* self) {
    if (func_8009E74C(self, 0x16) == 0) {
        func_800947EC(self, 1, 0);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009C000(self);
        baroll_resetAngularVelocity(self);
        bastick_popZone(self);
        baflag_clear(self, BA_FLAG_3);
        baflag_clear(self, BA_FLAG_4);
        _basnowball_entrypoint_1(self);
        func_80092864(self, 1.0f);
    }
}

void bssnowball_entrypoint_1(PlayerState* self) {
    if (func_8009E77C(self, 0x16) == 0) {
        _basnowball_entrypoint_2(self);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        baflag_set(self, BA_FLAG_3);
        baflag_set(self, BA_FLAG_4);
        func_800947EC(self, 1, 1);
        self->unk164.bytes[1] = 0;
        func_80092864(self, 1.0999908f);
    }
}

void bssnowball_entrypoint_2(PlayerState* self) {
    if (player_getTransformation(self) == TRANSFORM_2_SNOWBALL) {
        if (self->unk164.bytes[1] != 0) {
            _basnowball_entrypoint_9(self, 0.0f);
        }
        else {
            _basnowball_entrypoint_9(self, baphysics_get_horizontal_velocity(self));
        }
        if ((self->unk164.bytes[1] != 0) || (baphysics_get_target_horizontal_velocity(self) == 0.0f)) {
            _basnowball_entrypoint_8(self, 1);
        }
        else {
            _basnowball_entrypoint_8(self, 0);
        }
        _basnowball_entrypoint_12(self);
    }
}

void func_808003B0_bssnowball(PlayerState* self)
{
    _basudie_entrypoint_8(self);
    bssnowball_entrypoint_0(self);
}

void func_808003D8_bssnowball(PlayerState* self) {
    f32 sp2C[3];
    s32 sp28;

    sp28 = func_800B53A4(0x32);
    bssnowball_entrypoint_1(self);
    _basudie_entrypoint_9(self, 90.0f);
    player_getCoords(self, sp2C);
    func_8009DB04(self, 0x694, 1.0f, 0x7FFF);
    func_8009D9D4(self);
    func_800BBCB8(&sp2C, NULL, 1.0f, 1, D_80801028_bssnowball);
    func_800BBCB8(&sp2C, NULL, 1.0f, 1, D_80800F30_bssnowball);
    func_800BABB8(sp28, sp2C, sp2C, 1.0f, D_80800F84_bssnowball);
    _basnowball_entrypoint_10(self);
}

void func_808004AC_bssnowball(PlayerState* self)
{
    _basudie_entrypoint_10(self);
}

s32 bssnowball_entrypoint_3(s32 arg0) {
    return D_80801054_bssnowball[arg0];
}

void func_808004E0_bssnowball(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    bssnowball_entrypoint_0(self);
}

void func_80800508_bssnowball(PlayerState* self)
{
    bssnowball_entrypoint_1(self);
    _bsdrone_entrypoint_0(self);
}

void func_80800530_bssnowball(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
    bssnowball_entrypoint_2(self);
}

s32 bssnowball_entrypoint_4(s32 arg0) {
    return D_80801064_bssnowball[arg0];
}

void func_8080056C_bssnowball(PlayerState* self) {
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    bssnowball_entrypoint_0(self);
}

void func_808005A4_bssnowball(PlayerState* self) {
    bssnowball_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x5F, 10.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(self), 3);
    func_80800164_bssnowball(self);
}

void func_80800614_bssnowball(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800064_bssnowball(self, 1);
    func_80800000_bssnowball(self);
    if (func_8008DF8C(self, 0xC8) != 0) {
        func_8009D3A8(self, 0);
    }
    if (player_isStable(self) != 0) {
        func_800A2EAC(self);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        nextState = 0x17E;
    }
    bssnowball_entrypoint_2(self);
    bs_setState(self, nextState);
}

s32 bssnowball_entrypoint_5(s32 arg0) {
    return D_80801074_bssnowball[arg0];
}

void func_808006BC_bssnowball(PlayerState* self) {
    s32 pad[2];
    f32 sp2C;

    bssnowball_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x5F, 10.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(self), 3);
    func_80800164_bssnowball(self);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800064_bssnowball(self, 1);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 693.5f);
    baphysics_set_gravity(self, -2400.0f);
    func_8009D7A4(self, 1.35f, 1.45f);
}

void func_808007D8_bssnowball(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800064_bssnowball(self, 1);
    func_80800000_bssnowball(self);
    if ((bakey_released(self, BUTTON_A) != 0) && (baphysics_get_vertical_velocity(self) > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    if (func_8008DF8C(self, 0xC8) != 0) {
        func_8009D3A8(self, 0);
    }
    if (player_isStable(self) != 0) {
        func_800A2EAC(self);
        nextState = 0x17E;
    }
    bssnowball_entrypoint_2(self);
    bs_setState(self, nextState);
}

void func_8080089C_bssnowball(PlayerState* self) {
    baphysics_reset_gravity(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    bssnowball_entrypoint_0(self);
}

s32 bssnowball_entrypoint_6(s32 arg0) {
    return D_80801084_bssnowball[arg0];
}

void func_808008F0_bssnowball(PlayerState* self)
{
    func_80099B94(self);
}

void func_80800910_bssnowball(PlayerState* self)
{
    bssnowball_entrypoint_0(self);
}

void func_80800930_bssnowball(PlayerState* self) {
    bssnowball_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x5F, 10.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(self), 3);
    func_80800164_bssnowball(self);
    self->unk164.bytes[0] = 0;
    self->unk174 = 1.0f;
}

void func_808009B0_bssnowball(PlayerState* self) {
    BanjoStateId sp2C;
    f32 sp28;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f2;

    sp2C = BS_STATE_0_INVALID;
    func_8009D3A8(self, 0);
    func_80800064_bssnowball(self, 1);
    temp_f0 = func_80800000_bssnowball(self);
    sp28 = temp_f0;
    if ((temp_f0 > 0.67f) && (self->unk174 < 0.67f)) {
        temp_f0_2 = ml_map_f(baphysics_get_horizontal_velocity(self), 0.0f, 700.0f, 0.9f, 1.1f);
        if (self->unk164.bytes[0] != 0) {
            var_f2 = temp_f0_2 - 0.1f;
        }
        else {
            var_f2 = temp_f0_2 + 0.1f;
        }
        func_8009DBB0(self, 0x5F2, var_f2 - 0.03f, var_f2 + 0.03f, 0x6D60);
        self->unk164.bytes[0] ^= 1;
    }
    self->unk174 = sp28;
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (_basnowball_entrypoint_3(self) == 0.0f)) {
        sp2C = 0x17D;
    }
    if (func_8008DD04(self) != 0) {
        sp2C = 0x180;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        sp2C = 0x17F;
    }
    bssnowball_entrypoint_2(self);
    bs_setState(self, sp2C);
}

s32 bssnowball_entrypoint_7(s32 arg0) {
    return D_80801094_bssnowball[arg0];
}

void func_80800B44_bssnowball(PlayerState* self) {
    _baspin_entrypoint_1(self);
    self->unk164.bytes[1] = 0;
    bssnowball_entrypoint_0(self);
}

void func_80800B70_bssnowball(PlayerState* self) {
    bssnowball_entrypoint_1(self);
    self->unk164.bytes[1] = 1;
    _basnowball_entrypoint_10(self);
    _baspin_entrypoint_2(self, 0x5E, 1.8f, 3, 0);
}

void func_80800BBC_bssnowball(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bssnowball_entrypoint_2(self);
    if (_baspin_entrypoint_3(self) == 2) {
        nextState = 0x17D;
    }
    bs_setState(self, nextState);
}

s32 bssnowball_entrypoint_8(s32 arg0) {
    return D_808010A4_bssnowball[arg0];
}

void func_80800C18_bssnowball(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bssnowball_entrypoint_0(self);
}

void func_80800C40_bssnowball(PlayerState* self) {
    bssnowball_entrypoint_1(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0x5E, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(self), 0.1026f);
}

void func_80800C98_bssnowball(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_2(self) != 0) {
        func_80800064_bssnowball(self, 0);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x17D;
    }
    bs_setState(self, nextState);
}

s32 bssnowball_entrypoint_9(s32 arg0) {
    return D_808010B4_bssnowball[arg0];
}

void func_80800D00_bssnowball(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    bssnowball_entrypoint_0(self);
}

void func_80800D28_bssnowball(PlayerState* self)
{
    bssnowball_entrypoint_1(self);
    _bsrest_entrypoint_16(self);
}

void func_80800D50_bssnowball(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _bsrest_entrypoint_13(self);
    }
    bssnowball_entrypoint_2(self);
    bs_setState(self, nextState);
}

s32 bssnowball_entrypoint_10(s32 arg0) {
    return D_808010C4_bssnowball[arg0];
}

void func_80800DB0_bssnowball(PlayerState* self)
{
    func_80090A2C(self);
    bssnowball_entrypoint_0(self);
}

void func_80800DD8_bssnowball(PlayerState* self) {
    bssnowball_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x5E, 1.2f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_2_NORMAL);
    func_80800164_bssnowball(self);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_80800E4C_bssnowball(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800064_bssnowball(self, 1);
    func_8009D3A8(self, 0);
    if (func_8008DD04(self) != 0) {
        nextState = 0x180;
    }
    if (baphysics_get_target_horizontal_velocity(self) > 0.0f) {
        nextState = 0x17E;
    }
    nextState = func_800A02DC(self, func_8080010C_bssnowball(self, nextState));
    bssnowball_entrypoint_2(self);
    bs_setState(self, nextState);
}

s32 bssnowball_entrypoint_11(s32 arg0) {
    return D_808010D4_bssnowball[arg0];
}
