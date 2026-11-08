#include "bs/drone/bitten.h"

void func_80800000_bsdronebitten(PlayerState* self)
{
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 500.0f));
}


void bsdronebitten_entrypoint_0(PlayerState* self)
{
    func_8008E95C(self);
    bastick_popZone(self);
}

void bsdronebitten_entrypoint_1(PlayerState* self) {
    f32 sp2C;
    AssetId sp28;

    _badata_entrypoint_4(self, &sp28, &sp2C);
    baanim_playForDuration_loopSmooth(self, sp28, sp2C);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    baphysics_set_vertical_velocity(self, 900.0f);
    baphysics_set_gravity(self, -1200.0f);
    bastick_pushZone(self);
    bastick_setZoneMax(self, 0, 0.12f);
    bastick_setZoneMax(self, 1, 1.0f);
    func_8008E944(self);
    func_8009D9D4(self);
}

void bsdronebitten_entrypoint_2(PlayerState* self)
{
    func_80099AA8(self);
}

void bsdronebitten_entrypoint_3(PlayerState* self) {
    BanjoStateId nextState;
    s32 temp;
    s32 var_t7;
    nextState = BS_STATE_0_INVALID;
    func_80800000_bsdronebitten(self);
    if (character_includedInTransformMask(self->unk184, 0x201) && player_canGripGrab(self))
    {
        nextState = BS_STATE_A8_GRIP_GRAB_START;
    }

    var_t7 = baphysics_get_vertical_velocity(self) < 0.0f;

    if ((func_8008DF8C(self, 0x96) != 0) || (var_t7 && player_inWater(self)))
    {
        nextState = _badata_entrypoint_24(self);
    }
    bs_setState(self, nextState);
}

f32 bsdronebitten_entrypoint_4(PlayerState* self, f32 arg1) {
    f32 temp_f2;

    switch (self->unk190.bytes[1])
    {
    case 1:
        return arg1;
    case 2:
        temp_f2 = 1.0f - arg1;
        return 1.0f - SQ(temp_f2);
    default:
        return arg1;
    }
}

void bsdronebitten_entrypoint_5(PlayerState* self, f32* arg1, f32 arg2)
{
    switch (self->unk190.bytes[1])
    {
    case 1:
        break;
    case 2:
        arg1[1] += func_80013970(arg2 * 180.0f) * _bamovegoto_entrypoint_3(self) * 0.5f;
    }
}

void bsdronebitten_entrypoint_6(PlayerState* self)
{
    func_800961A0(self, NULL);
    func_8008E95C(self);
    _bafpctrl_entrypoint_19(self);
}

void bsdronebitten_entrypoint_7(PlayerState* self) {
    f32 sp3C;
    f32 sp38;
    AssetId sp34;
    f32 sp28[3];

    _badata_entrypoint_4(self, &sp34, &sp38);
    baanim_playForDuration_loopSmooth(self, sp34, sp38);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    player_getCoords(self, sp28);
    sp3C = ml_vec3f_distance(sp28, self->unk54->unk34);
    self->unk190.bytes[1] = self->unk54->unk30;
    _bamovegoto_entrypoint_0(self);
    if (self->unk190.bytes[1] == 1)
    {
        _bamovegoto_entrypoint_8(self, 2400.0f);
    }
    else
    {
        sp38 = ml_map_f(sp3C, 100.0f, 5000.0f, 0.4f, 4.5f);
        _bamovegoto_entrypoint_7(self, sp38);
    }
    _bamovegoto_entrypoint_12(self, self->unk54->unk34);
    _bamovegoto_entrypoint_11(self, &_bsdronebitten_entrypoint_4, &_bsdronebitten_entrypoint_5);
    _bamovegoto_entrypoint_13(self);
    func_800961A0(self, 1);
    func_8008E944(self);
    func_8009D9D4(self);
    self->unk190.bytes[0] = 0;
}

void bsdronebitten_entrypoint_8(PlayerState* self)
{
    func_80099AA8(self);
}

BanjoStateId func_80800478_bsdronebitten(PlayerState* self, s32 arg1) {
    BanjoStateId var_v0;

    if (func_8008E124(self) != 0) {
        var_v0 = _badata_entrypoint_32(self);
    }
    else {
        var_v0 = _badata_entrypoint_34(self);
    }
    return var_v0;
}

void func_808004C4_bsdronebitten(PlayerState* self, AssetId arg1, f32 arg2) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, arg1);
    anctrl_setDuration(temp_v0, arg2);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_start(temp_v0);
	self->unk190.bytes[0] = 1;
}

void bsdronebitten_entrypoint_9(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    switch (self->unk190.bytes[0])
    {
    case 0:
        if (_bamovegoto_entrypoint_4(self) != 0) {
            func_8009D9D4(self);
            func_8009DB04(self, 0x417, 0.8f, 0x4650);
            _bashake_entrypoint_0(self, 3, 1);
            _badust_entrypoint_8(self);
            if (player_getCurrentHealth(self) == 0)
            {
                nextState = _badata_entrypoint_20(self);
                break;
            }
            switch (player_getTransformation(self))
            {
            case TRANSFORM_1_BK:
            case TRANSFORM_A_BANJO:
                func_808004C4_bsdronebitten(self, 0xD2, 2.25f);
                break;
            case TRANSFORM_B_KAZOOIE:
                func_808004C4_bsdronebitten(self, ASSET_11E_ANIM_BSKAZFLY_UNKNOWN, 1.6f);
                break;
            default:
                nextState = func_80800478_bsdronebitten(self, 0);
            }
        }
        break;
    case 1:
        if (baanim_isStopped(self) != 0)
        {
            nextState = func_80800478_bsdronebitten(self, 0);
        }
        break;
    }
    bs_setState(self, nextState);
}
