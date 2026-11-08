#include "ba/swim.h"

void baswim_entrypoint_7(PlayerState*, s32, s32);
void baswim_entrypoint_8(PlayerState*, f32);
void baswim_entrypoint_9(PlayerState*, f32);

s32 baswim_entrypoint_0() 
{
    return sizeof(BaUnknown134);
}

s32 baswim_entrypoint_1(PlayerState* self)
{
    return (player_getWaterHeight(self) - player_getCoordVertical(self)) < 100.0f;
}

int baswim_entrypoint_2(PlayerState* self)
{
    s32 temp = func_80096544(self);
    return temp && (player_getCoordVertical(self) > (player_getWaterHeight(self) - 130.0f));
}

int baswim_entrypoint_3(PlayerState* self)
{
    s32 sp1C;
    s32 sp18;

    sp1C = bakey_held(self, BUTTON_A);
    sp18 = bakey_held(self, BUTTON_B);
    if ((ability_getValue(ABILITY_30_FAST_SWIMMING) != 0) && (sp1C != 0) && (sp18 != 0))
    {
        return 3;
    }
    if (sp18 != 0)
    {
        return 2;
    }
    if (sp1C != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void baswim_entrypoint_4(PlayerState* self)
{
    bastick_resetZones(self);
}

void baswim_entrypoint_5(PlayerState* self)
{
    bastick_setZoneMax(self, 0, 0.03f);
    bastick_setZoneMax(self, 1, 1.0f);
    baswim_entrypoint_9(self, 0.0f);
    baswim_entrypoint_8(self, 0.0f);
}

void baswim_entrypoint_6(PlayerState* self, s32 arg1)
{
    baswim_entrypoint_7(self, arg1, 0);
}

void baswim_entrypoint_7(PlayerState* self, s32 arg1, s32 arg2)
{
    s32 sp24;

    if (arg1 != 0)
    {
        sp24 = 0;
        _bafpctrl_entrypoint_9(self, 1);
        if (_bafpctrl_entrypoint_4(self) != 3)
        {
            _bafpctrl_entrypoint_16(self, 2);
            if (ability_getValue(ABILITY_1F_SUB_AQUA_EGG_AIM) == 0)
            {
                sp24 = 1;
            }
            if ((arg2 == 0) && (player_getTransformation(self) == TRANSFORM_A_BANJO))
            {
                sp24 += 1;
            }
            if (sp24 != 0)
            {
                _bafpctrl_entrypoint_11(self, 4, 1);
            }
        }
    }
    else
    {
        _bafpctrl_entrypoint_17(self);
        _bafpctrl_entrypoint_9(self, 0);
    }
}

void baswim_entrypoint_8(PlayerState* self, f32 arg1) {
    self->swim->unk4 = arg1;
}

void baswim_entrypoint_9(PlayerState* self, f32 arg1) {
    self->swim->unk0 = arg1;
}

void baswim_entrypoint_10(PlayerState* self, f32 arg1)
{
    if (self->swim->unk0 < arg1)
    {
        self->swim->unk0 = arg1;
    }
}

void baswim_entrypoint_11(PlayerState* self)
{
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 var_f0;
    f32 var_f0_2;

    sp28 = bastick_getX(self);
    var_f0 = 45.0f;
    var_f0_2 = 4.3f;
    yaw_setVelocityBounded(self, 250.0f, 20.0f);
    baroll_setIdeal(self, ml_map_f(sp28, -1.0f, 1.0f, -var_f0, var_f0));
    sp34 = ml_map_f(sp28, -1.0f, 1.0f, var_f0_2, -var_f0_2);
    sp34 *= _bafpctrl_entrypoint_3(self);
    yaw_setIdeal(self, sp34 + yaw_getIdeal(self));
}

f32 func_808003B8_baswim(PlayerState* self)
{
    f32 sp24[3];
    func_8009BB24(self, sp24);
    return ml_map_f(ml_vec3f_magnitude(sp24), 50.0f, 200.0f, 0.0f, 1.0f);
}
void baswim_entrypoint_12(PlayerState* self)
{
    f32 sp2C;
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = func_808003B8_baswim(self);
    sp2C = ml_mapNormal_f(temp_f0, 140.0f, 90.0f);
    temp_f0 = _bafpctrl_entrypoint_3(self);
    temp_f0 = ml_map_f(temp_f0, 0.1f, 1.0f, temp_f0 * temp_f0, 1.0f);
    sp2C *= temp_f0;
    func_8009BFE4(self, sp2C, 1.6f);
    temp_f0_2 = bastick_getY(self);
    if (temp_f0_2 < 0.0f)
    {
        func_8009BF5C(self, ml_map_f(temp_f0_2, -1.0f, 0.0f, 275.0f, 360.0f));
        return;
    }
    func_8009BF5C(self, ml_map_f(temp_f0_2, 0.0f, 1.0f, 0.0f, 85.0f));
}

void baswim_entrypoint_13(PlayerState* self)
{
    f32 sp44;
    s32 sp40;
    f32 sp34[3];
    sp44 = func_8009BFCC(self);
    func_800EF4E4(sp34, sp44, yaw_get(self), 0.0f, 0.0f, self->swim->unk0);
    self->swim->unk0 = ml_max_f(self->swim->unk0 - (time_getDelta() * self->swim->unk4), 0.0f);
    func_8009B94C(self, sp34);
    func_8009BA9C(self, sp34);
}

f32 baswim_entrypoint_14(PlayerState* self) {
    return self->swim->unk0;
}

