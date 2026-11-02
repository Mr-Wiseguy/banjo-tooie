#include "bs/beemain.h"

extern s32 D_80801260_bsbeemain[];
extern s32 D_80801270_bsbeemain[];
extern s32 D_80801280_bsbeemain[];
extern s32 D_80801290_bsbeemain[];
extern s32 D_808012A0_bsbeemain[];
extern s32 D_808012B0_bsbeemain[];
extern s32 D_808012C0_bsbeemain[];
extern s32 D_808012D0_bsbeemain[];
extern s32 D_808012E0_bsbeemain[];

/* .code */

void func_80800000_bsbeemain(PlayerState* self) {
    func_8009DF18(self, 0x41F, 1.4f, 0x1F40);
}

void func_8080002C_bsbeemain(PlayerState* self) {
    func_8009D7A4(self, 1.35f, 1.45f);
}

void func_80800058_bsbeemain(PlayerState* self) {
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == 0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 375.0f));
}

void func_808000C0_bsbeemain(PlayerState* self) {
    _bsbee_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x1DE, 3.0f); // ASSET_1DE_ANIM_BEE_IDLE
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_80800128_bsbeemain(PlayerState* self) {
    BanjoStateId var_s1;

    var_s1 = BS_STATE_0_INVALID;
    _bsbee_entrypoint_2(self);
    func_8009D3A8(self, 0);
    if (func_8008DD04(self) != 0) {
        var_s1 = 0x88;
    }
    if (bakey_held(self, BUTTON_Z) != 0) {
        _babee_entrypoint_2(self);
    }
    if (bainput_should_enter_first_person(self) != 0) {
        var_s1 = _badrone_entrypoint_24(self);
    }
    if (bastick_getZone(self) > 0) {
        var_s1 = 0x86;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        var_s1 = 0x87;
    }
    if (player_inWater(self) != 0) {
        var_s1 = 0x8C;
    }
    bs_setState(self, func_800A02DC(self, var_s1));
}

void func_808001FC_bsbeemain(PlayerState* self)
{
    func_80090A2C(self);
    _bsbee_entrypoint_0(self);
}

s32 bsbeemain_entrypoint_0(s32 arg0) {
    return D_80801260_bsbeemain[arg0];
}

void func_80800238_bsbeemain(PlayerState* self) {
    _bsbee_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x1DD, 0.38f); // ASSET_1DD_ANIM_BEE_WALK
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8008C9F0(self, 30.0f, 375.0f, 0.6f, 0.4f);
    func_800909CC(self);
}

void func_808002C0_bsbeemain(PlayerState* self) {
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    _bsbee_entrypoint_2(self);
    func_8009D3A8(self, 0);
    func_80800058_bsbeemain(self);
    func_800A2CE8(self, 0.94f, 4);
    func_800A2CE8(self, 0.44f, 3);
    if (bakey_held(self, BUTTON_Z) != 0) {
        _babee_entrypoint_2(self);
    }
    if ((bastick_getZone(self) == 0) && (func_8009BCD4(self, 1.0f) != 0)) {
        sp24 = 0x85;
    }
    if (func_8008DD04(self) != 0) {
        sp24 = 0x88;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        sp24 = 0x87;
    }
    if (player_inWater(self) != 0) {
        sp24 = 0x8C;
    }
    bs_setState(self, sp24);
}

void func_808003B4_bsbeemain(PlayerState* self)
{
    func_80090A2C(self);
    _bsbee_entrypoint_0(self);
}

s32 bsbeemain_entrypoint_1(s32 arg0) {
    return D_80801270_bsbeemain[arg0];
}

void func_808003F0_bsbeemain(PlayerState* self) {
    AnimCtrl* anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bsbee_entrypoint_1(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x1E2);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.34f);
    anctrl_setStart(anim_ctrl, 0.1f);
    anctrl_setDuration(anim_ctrl, 1.2f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800058_bsbeemain(self);
    baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 693.5f);
    baphysics_set_gravity(self, -1200.0f);
    func_8080002C_bsbeemain(self);
    self->unk15C.word = 0;
}

void func_80800548_bsbeemain(PlayerState* self) {
    BanjoStateId sp34;
    AnimCtrl* sp30;
    f32 sp24[3];

    sp34 = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    _bsbee_entrypoint_2(self);
    func_80800058_bsbeemain(self);
    func_8009BB24(self, sp24);
    if ((bakey_released(self, BUTTON_A)) && (sp24[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word) {
        case 0:
            if (func_8008DF8C(self, 0x82)) {
                baanim_setEndAndDuration(self, 0.715f, 0.7f);
                self->unk15C.word = 2;
            } else if (anctrl_isStopped(sp30)) {
                baanim_setEndAndDuration(self, 0.51f, 4.0f);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            if (func_8008DF8C(self, 0x82)) {
                baanim_setEndAndDuration(self, 0.715f, 1.2f);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            func_8009D3A8(self, 0);
            if (player_isStable(self)) {
                func_80800000_bsbeemain(self);
                baanim_setEndAndDuration(self, 1.0f, 0.7f);
                self->unk15C.word = 3;
            }
            break;
        case 3:
            func_8009D3A8(self, 0);
            if (anctrl_isStopped(sp30)) {
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                sp34 = 0x85;
            }
            break;
    }
    if (bakey_held(self, BUTTON_Z)) {
        _babee_entrypoint_2(self);
    }
    if (player_isStable(self)) {
        if (bastick_getZone(self) > 0) {
            sp34 = 0x86;
        }
        if (bakey_pressed(self, BUTTON_A)) {
            sp34 = 0x87;
        }
    } else if (bakey_pressed(self, BUTTON_A)) {
        sp34 = 0x8C;
    }
    if (player_inWater(self)) {
        sp34 = 0x8C;
    }
    bs_setState(self, sp34);
}

void func_80800788_bsbeemain(PlayerState* self)
{
    _bsbee_entrypoint_0(self);
    baphysics_reset_gravity(self);
}

s32 bsbeemain_entrypoint_2(s32 arg0) {
    return D_80801280_bsbeemain[arg0];
}

void func_808007C4_bsbeemain(PlayerState* self) {
    AnimCtrl* temp_s0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    _bsbee_entrypoint_1(self);
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, 0x1E2);
    anctrl_setStart(temp_s0, 0.34f);
    anctrl_setDuration(temp_s0, 8.0f);
    anctrl_setSubrange(temp_s0, 0.0f, 0.51f);
    anctrl_setPlaybackType(temp_s0, 1);
    anctrl_start(temp_s0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    self->unk15C.word = 0;
}

void func_80800874_bsbeemain(PlayerState* self) {
    BanjoStateId sp34;
    AnimCtrl* sp30;
    f32 sp24[3];

    sp34 = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    _bsbee_entrypoint_2(self);
    func_8009D3A8(self, 0);
    func_80800058_bsbeemain(self);
    func_8009BB24(self, sp24);
    switch (self->unk15C.word) {
        case 0:
            if (func_8008DF8C(self, 0x82)) {
                baanim_setEndAndDuration(self, 0.715f, 0.7f);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            func_8009D3A8(self, 0);
            if (player_isStable(self)) {
                func_80800000_bsbeemain(self);
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                baanim_setEndAndDuration(self, 1.0f, 0.7f);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            func_8009D3A8(self, 0);
            if (anctrl_isStopped(sp30)) {
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                sp34 = 0x85;
            }
            break;
    }
    if (bakey_held(self, BUTTON_Z)) {
        _babee_entrypoint_2(self);
    }
    if (player_isStable(self)) {
        if (baflag_isTrue(self, BA_FLAG_19)) {
            sp34 = _badrone_entrypoint_28(self);
        } else {
            if (bastick_getZone(self) > 0) {
                sp34 = 0x86;
            }
            if (bakey_pressed(self, BUTTON_A)) {
                sp34 = 0x87;
            }
            sp34 = func_800A02DC(self, sp34);
        }
    } else if ((baflag_isFalse(self, BA_FLAG_F)) && (bakey_pressed(self, BUTTON_A))) {
        sp34 = 0x8C;
    }
    if (player_inWater(self)) {
        sp34 = 0x8C;
    }
    bs_setState(self, sp34);
}

void func_80800A74_bsbeemain(PlayerState* self)
{
    _bsbee_entrypoint_0(self);
}

s32 bsbeemain_entrypoint_3(s32 arg0) {
    return D_80801290_bsbeemain[arg0];
}

void bsbeemain_entrypoint_4(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    _bsbee_entrypoint_0(self);
}

void bsbeemain_entrypoint_5(PlayerState* self)
{
    _bsbee_entrypoint_1(self);
    _babounce_entrypoint_4(self, 1);
    _babounce_entrypoint_5(self, 0x1E0, 0.7518f);
}

void bsbeemain_entrypoint_6(PlayerState* self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    _bsbee_entrypoint_2(self);
    if (_babounce_entrypoint_9(self) != 0) {
        next_state = 0x85;
    }
    bs_setState(self, next_state);
}

s32 bsbeemain_entrypoint_7(s32 arg0)
{
    return D_808012A0_bsbeemain[arg0];
}

void func_80800B68_bsbeemain(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    _bsbee_entrypoint_0(self);
}

void func_80800B90_bsbeemain(PlayerState* self)
{
    _bsbee_entrypoint_1(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0x1E0, 0.7518f);
}

void func_80800BD0_bsbeemain(PlayerState* self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    _bsbee_entrypoint_2(self);
    if (_babounce_entrypoint_9(self) != 0) {
        next_state = 0x85;
    }
    bs_setState(self, next_state);
}

s32 bsbeemain_entrypoint_8(s32 arg0)
{
    return D_808012B0_bsbeemain[arg0];
}

void func_80800C28_bsbeemain(PlayerState* self)
{
    AnimCtrl* anim_ctrl;
    f32 sp48;
    f32 sp3C[3];
    f32 sp30[3];

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    self->unk160.word = func_800EA068(0x40);
    if (self->unk160.word) {
        func_800FC660(0x19);
    } else {
        _basudie_entrypoint_1(self);
        func_8008E944(self);
        func_8009514C(self);
        func_800A4DA4(self, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(self), 30.0f);
        func_800A0180(self);
    }
    _bsbee_entrypoint_1(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x1E1); // ASSET_1E1_ANIM_BEE_DIE
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.3966f);
    anctrl_setDuration(anim_ctrl, 1.7f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    player_getCoords(self, sp3C);
    func_800A32C4(self, sp30);
    func_800F1E6C(sp30, sp3C, &sp48);
    yaw_setIdeal(self, func_800136E4(sp48 + 180.0f));
    yaw_applyIdeal(self);
    self->unk16C = 250.0f;
    baphysics_set_target_horizontal_velocity(self, 250.0f);
    baphysics_set_target_yaw(self, sp48);
    baphysics_set_horizontal_velocity(self, sp48, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 420.0f);
    baphysics_set_gravity(self, -1200.0f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    func_8009D820(self, 1.8f);
    _batimer_set(self, 0, 2.9f);
    self->unk15C.word = 0;
}

void func_80800E0C_bsbeemain(PlayerState* self) {

    _bsbee_entrypoint_2(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    func_8009D3A8(self, 0);
    switch (self->unk15C.word) {
        case 0:
            if (player_isStable(self)) {
                baanim_setEnd(self, 0.7453f);
                func_8009DF18(self, 0x417, 0.8f, 0x4650);
                func_8009DF18(self, 0x428, 1.8f, 0x4650);
                baphysics_set_vertical_velocity(self, 400.0f);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(self)) {
                baanim_setEnd(self, 1.0f);
                func_8009DF18(self, 0x417, 0.8f, 0x4650);
                func_8009DF18(self, 0x428, 1.8f, 0x4650);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            self->unk15C.word = 3;
            break;
        case 3:
            if (self->unk16C > 0.0f) {
                self->unk16C = ml_max_f(0.0f, self->unk16C - 10.0f);
            }
            break;
    }
    if (_batimer_decrement(self, 0)) {
        if (self->unk160.word) {
            event_sendToActorsOfType(0x2C4, 0x71, self->unk184);
        } else {
            _basudie_entrypoint_0(self);
        }
    }
    bs_setState(self, BS_STATE_0_INVALID);
}

void func_80800FB8_bsbeemain(PlayerState* self) {
    baphysics_reset_gravity(self);
    func_800A4E30(self);
    func_800951B4(self);
    _bsbee_entrypoint_0(self);
}

void func_80800FF0_bsbeemain(PlayerState* self) {
    if (func_8009E6EC(self) == 0x83) {
        func_8009BDAC(self, func_80099A34(self));
        func_80093370(self, 1);
        bs_setState(self, 0x85);
        func_8009E830(self, 2);
        return;
    }
    _basudie_entrypoint_11(self);
}

s32 bsbeemain_entrypoint_9(s32 arg0) {
    return D_808012C0_bsbeemain[arg0];
}

void func_80801080_bsbeemain(PlayerState* self)
{
    _bsbee_entrypoint_1(self);
    _bsrest_entrypoint_16(self);
}

void func_808010A8_bsbeemain(PlayerState* self) {
    BanjoStateId sp1C;

    sp1C = BS_STATE_0_INVALID;
    _bsbee_entrypoint_2(self);
    if (_bsrest_entrypoint_20(self) != 0) {
        sp1C = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, sp1C);
}

void func_808010F4_bsbeemain(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    _bsbee_entrypoint_0(self);
}

s32 bsbeemain_entrypoint_10(s32 arg0) {
    return D_808012D0_bsbeemain[arg0];
}

void func_80801130_bsbeemain(PlayerState* self) {
    _bsbee_entrypoint_1(self);
    _bsdrone_entrypoint_0(self);
    if (_badrone_entrypoint_3(self) == 2) {
        _bafpctrl_entrypoint_10(self, 1);
        func_800947EC(self, 2, 1);
    }
}

void func_8080118C_bsbeemain(PlayerState* self) {
    _bsbee_entrypoint_2(self);
    _bsdrone_entrypoint_1(self);
    if ((_badrone_entrypoint_3(self) == 2) && bakey_held(self, BUTTON_Z)) {
        _babee_entrypoint_2(self);
    }
}

void func_808011E8_bsbeemain(PlayerState* self) {
    if (_badrone_entrypoint_3(self) == 2) {
        func_800947EC(self, 2, 0);
    }
    _bsdrone_entrypoint_2(self);
    _bsbee_entrypoint_0(self);
}

s32 bsbeemain_entrypoint_11(s32 arg0) {
    return D_808012E0_bsbeemain[arg0];
}
