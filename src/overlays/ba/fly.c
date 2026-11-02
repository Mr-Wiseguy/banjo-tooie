#include "ba/fly.h"

/* .code */
s32 bafly_entrypoint_0(void)
{
    return 0x10;
}

void bafly_entrypoint_1(PlayerState* self, f32* arg1, s32* arg2, f32 arg3) {
    f32 sp24[3];

    if (baflag_isTrue(self, BA_FLAG_30))
    {
        _baeggfire_entrypoint_3(self, &sp24, arg1);
        ml_vec3f_apply_scale(arg1, arg3);
        func_800CA9D8(func_800A4C48(self), arg2);
        return;
    }
    func_800CA740(func_800A4C48(self), arg1);
    ml_vec3f_apply_scale(arg1, arg3);
    func_800CA9D8(func_800A4C48(self), arg2);
}

s32 bafly_entrypoint_2(PlayerState *self)
{
    if (!player_isStable(self)) {
        return 0;
    }
    if (func_80096628(self) & 0x100000) {
        return 0;
    }
    return 1;
}

u8 bafly_entrypoint_3(PlayerState* self)
{
    return self->unk8C->unk8;
}

void bafly_entrypoint_4(PlayerState* self)
{
    if (self->unk8C->unk9 != 0) {
        func_800C2FDC(self->unk8C->unk9);
        self->unk8C->unk9 = 0;
    }
}

void bafly_entrypoint_5(PlayerState* self) {
    s32 temp_v0;

    if (_gcstatusDll_entrypoint_11() >= 2) {
        self->unk8C->unk9 = 0U;
    } else {
        self->unk8C->unk9 = func_800C2E04();
        func_800C3418(self->unk8C->unk9, 0);
    }
    self->unk8C->unk4 = 1.0f;
    self->unk8C->unk0 = 0.0f;
    self->unk8C->unk8 = 0;
    temp_v0 = map_getCurrent();
    if ((temp_v0 != 0xE4) && (temp_v0 != 0x17B)) {
        self->unk8C->unkE = 0;
        return;
    }
    self->unk8C->unkE = 1;
}

void bafly_entrypoint_6(PlayerState* self, f32 arg1) {
    self->unk8C->unk0 = arg1;
}

void bafly_entrypoint_7(PlayerState* self, s32 arg1)
{
    self->unk8C->unk8 = (u8) arg1;
}

void bafly_entrypoint_8(PlayerState* self, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp44[3];
    f32 temp_f20;
    f32 sp3C;

    temp_f20 = func_8009BFCC(self);
    baphysics_set_gravity(self, arg4);
    bafly_entrypoint_6(self, 0.0f);
    if (baflag_isTrue(self, BA_FLAG_9) != 0) {
        baphysics_set_terminal_velocity(self, 0.0f);
        func_8009BA9C(self, NULL);
        sp3C = 0.0f;
    } else if (temp_f20 <= arg2) {
        baphysics_set_terminal_velocity(self, ml_map_f(temp_f20, arg2 - 20.0f, arg2, arg5, arg7));
        baphysics_set_gravity(self, ml_map_f(temp_f20, arg2 - 20.0f, arg2, arg4, arg6));
        sp3C = ml_map_f(temp_f20, arg2 - 20.0f, arg2, arg3, arg3 / 10.0f);
        bafly_entrypoint_6(self, ml_map_f(temp_f20, arg2 - 20.0f, arg2, 0.0f, 0.35f));
    } else {
        baphysics_set_terminal_velocity(self, ml_map_f(temp_f20, arg1, arg1 + 10.0f, -399.99f, arg5));
        sp3C = ml_map_f(temp_f20, arg1, arg1 + 40.0f, 0.0f, arg3);
        bafly_entrypoint_6(self, ml_map_f(temp_f20, arg1, arg1 + 40.0f, -0.25f, 0.0f));
    }
    func_80096394(self, sp44);
    if ((func_8009650C(self) != 0) && (sp44[1] > -1.0f)) {
        sp3C = 0.0f;
    }
    baphysics_set_target_yaw(self, yaw_get(self));
    baphysics_set_target_horizontal_velocity(self, sp3C);
}

void bafly_entrypoint_9(PlayerState* self) {
    f32 sp34;
    f32 sp30;
    f32 var_f0;
    f32 sp28;

    sp28 = bastick_getX(self);
    if (bakey_held(self, BUTTON_R) != 0) {
        yaw_setVelocityBounded(self, 500.0f, 30.0f);
        sp30 = 6.0f;
        var_f0 = 85.0f;
    } else {
        yaw_setVelocityBounded(self, 500.0f, 2.0f);
        sp30 = 3.0f;
        var_f0 = 75.0f;
    }
    baroll_setIdeal(self, ml_map_f(sp28, -1.0f, 1.0f, -var_f0, var_f0));
    sp34 = ml_map_f(sp28, -1.0f, 1.0f, sp30, -sp30);
    sp34 *= _bafpctrl_entrypoint_3(self);
    yaw_setIdeal(self, yaw_getIdeal(self) + sp34);
}

void bafly_entrypoint_10(PlayerState* self, f32 arg1, f32 arg2) {
    f32 temp_f0;

    temp_f0 = bastick_getY(self);
    if (temp_f0 < 0.0f) {
        func_8009BF5C(self, ml_map_f(temp_f0, -1.0f, 0.0f, arg1, 360.0f));
    } else {
        func_8009BF5C(self, ml_map_f(temp_f0, 0.0f, 1.0f, 0.0f, arg2));
    }
}

void bafly_entrypoint_11(PlayerState* self) {
    u8 temp_s0;
    f32 sp48;
    f32 sp44;
    Vec3f sp38;
    f32 temp_f0;

    sp44 = 1.2f;
    if (self->unk8C->unk8 != 0) {
        sp44 += 0.4f;
    }
    func_80110818(func_800A4CA8(self), &sp38);
    temp_f0 = func_800F1DCC(sp38.pos.y + 180.0f, yaw_get(self));
    temp_f0 = mlAbsF(temp_f0);
    sp44 -= ml_map_f(temp_f0, 0.0f, 50.0f, 0.0f, 0.4f);
    sp44 += self->unk8C->unk0;
    sp48 = sp44 - self->unk8C->unk4;
    if (mlAbsF(sp48) > 0.01f) {
        if (sp48 > 0.0f) {
            sp48 = 0.01f;
        } else {
            sp48 = -0.01f;
        }
    }
    self->unk8C->unk4 += sp48;
    temp_s0 = self->unk8C->unk9;
    if (temp_s0 != 0) {
        func_800C31DC(temp_s0, self->unk8C->unk4); // huh? This should load a f32
        func_800C31DC(temp_s0, self->unk8C->unk4);
        func_800C3058(temp_s0, 0x1770);
        if (func_800C3D78(temp_s0) == 0) {
            func_800C301C(temp_s0, 0x4A3);
            func_800C330C(temp_s0, 3);
            func_800C3BDC(temp_s0);
        }
    }
}

s32 bafly_entrypoint_12(PlayerState* self) 
{
    s32 sp24;

    if (self->unk8C->unkE != 0) {
        return 1;
    }
    _suinv_entrypoint_0(&sp24, 0, 1, 0x46, 1);
    return sp24;
}

void bafly_entrypoint_13(PlayerState* self, s32 arg1, enum asset_e arg2, f32 arg3) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp40;
    s32 pad;
    f32 sp38;
    s32 pad2;

    if (arg1 == 0) {
        sp44 = -2200.0f;
        sp38 = 800.0f;
    } else {
        sp44 = -1200.0f;
        sp38 = 400.0f;
    }
    player_getCoords(self, &sp54);
    func_800E1610(2, 100.0f, 0.85f, &sp54);
    baanim_playForDuration_once(self, arg2, arg3);
    func_8009D9D4(self);
    _bamotor_entrypoint_1(self, 1.0f, 0.5f, 0.5f);
    func_800A32C4(self, &sp48);
    func_800F1E6C(&sp48, &sp54, &sp40);
    yaw_setIdeal(self, func_800136E4(sp40 + 180.0f));
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, sp38);
    baphysics_set_target_yaw(self, sp40);
    baphysics_set_horizontal_velocity(self, sp40, baphysics_get_target_horizontal_velocity(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(self, 800.0f);
    baphysics_set_gravity(self, sp44);
    baphysics_set_terminal_velocity(self, -4000.0f);
    func_800A4DA4(self, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(self), 12.0f, 10000.0f, 800.0f);
    func_8008E944(self);
}

void bafly_entrypoint_14(PlayerState* self, BanjoStateId arg1, BanjoStateId arg2) 
{
    BanjoStateId sp1C;

    sp1C = BS_STATE_0_INVALID;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0) {
        sp1C = arg1;
    }
    if (player_isStable(self) != 0) {
        sp1C = arg2;
    }
    bs_setState(self, sp1C);
}

void bafly_entrypoint_15(PlayerState* self) {
    func_8009BC34(self);
    func_8008E95C(self);
    func_8009BD88(self);
    func_800A4E30(self);
}

void bafly_entrypoint_16(PlayerState* self, enum asset_e arg1, f32 arg2) {
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];

    player_getCoords(self, &sp40);
    func_800E1610(2, 100.0f, 0.85f, &sp40);
    baanim_playForDuration_once(self, arg1, arg2);
    func_8009DA40(self);
    func_800A32C4(self, &sp34);
    func_800F1E6C(&sp34, &sp40, &sp4C);
    yaw_setIdeal(self, func_800136E4(sp4C + 180.0f));
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, 1300.0f);
    baphysics_set_target_yaw(self, sp4C);
    baphysics_set_horizontal_velocity(self, sp4C, baphysics_get_target_horizontal_velocity(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(self, 400.0f);
    baphysics_set_gravity(self, -1800.0f);
    func_8008E944(self);
    func_800A4DA4(self, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(self), 12.0f, 10000.0f, 800.0f);
}

void bafly_entrypoint_17(PlayerState* self, BanjoStateId arg1, BanjoStateId arg2, s32* arg3) {
    BanjoStateId sp24;
    AnimCtrl* sp20;

    sp24 = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    if (player_isStable(self) != 0) {
        sp24 = arg2;
    }
    if ((anctrl_isStopped(sp20) != 0) && ((func_8008DD04(self) != 0) || (func_8009650C(self) != 0))) {
        *arg3 = 1;
        sp24 = arg1;
    }
    bs_setState(self, sp24);
}

void bafly_entrypoint_18(PlayerState* self)
{
    baphysics_reset_gravity(self);
    func_8008E95C(self);
}

void bafly_entrypoint_19(PlayerState* arg0) {
    if (_bafpctrl_entrypoint_4(arg0) != 3) {
        if (baflag_isTrue(arg0, BA_FLAG_2F) != 0) {
            _bafpctrl_entrypoint_14(arg0, 3);
        } else {
            _bafpctrl_entrypoint_14(arg0, 2);
        }
        _bafpctrl_entrypoint_9(arg0, 1);
        if (ability_getValue(0x1B) == 0) {
            _bafpctrl_entrypoint_11(arg0, 4, 1);
        }
    }
}

void bafly_entrypoint_20(PlayerState* self) 
{
    f32 temp_f0;

    temp_f0 = _bafpctrl_entrypoint_3(self);
    temp_f0 = ml_map_f(temp_f0, 0.1f, 1.0f, temp_f0 * temp_f0, 1.0f);
    func_8009BFE4(self, 500.0f * temp_f0, 1.2f);
}

void bafly_entrypoint_21(PlayerState* self) 
{
    f32 temp_f0;

    temp_f0 = _bafpctrl_entrypoint_3(self);
    temp_f0 = ml_map_f(temp_f0, 0.1f, 1.0f, temp_f0 * temp_f0, 1.0f);
    func_8009BFE4(self, 1000.0f*temp_f0, 2.2f);
}
