#include "ba/physics.h"

extern f32 D_80117EF0;
extern f32 D_80117EF4;

s32 func_8009AD70() 
{
    return 0xF;
}

s32 func_8009AD78(PlayerState* self, s32 arg1) {
    return self->unkC4[arg1];
}

void func_8009AD88(s32 arg0) 
{
}

void func_8009AD90(PlayerState* self)
{
	s32 var_v0;
	for (var_v0 = 0; var_v0 != 0xF; var_v0++)
	{
		self->unkC4[var_v0] = 0;
	}
}

void func_8009ADF0(PlayerState* self, s32 arg1, s32 arg2) {
    self->unkC4[arg1] = arg2;
}

s32 func_8009AE00() 
{
    return sizeof(ba_unknown_C8_s);
}

void func_8009AE08(PlayerState* self) {
	f32 sp7C[3];
	f32 sp70[3];
	f32 sp64[3];
	f32 sp58[3];
	f32 sp4C[3];
	f32 sp40[3];
	f32 sp3C;
	f32 sp38;
	f32 var_f12;

	func_800EEB9C(self->unkC8->unk1C, self->unkC8->unk40[0], self->unkC8->unk4C[1] * self->unkC8->unk34[2]);
	sp64[0] = self->unkC8->unk10[0];
	sp64[1] = 0.0f;
	sp64[2] = self->unkC8->unk10[2];
	ml_vec3f_copy(sp58, self->unkC8->unk1C);
	sp58[1] = 0.0f;
	if (func_80096518(self) != 0)
	{
		func_800963C0(self, sp4C);
		func_800EF410(sp40, sp58);
		sp3C = ml_vec3f_dot_product(sp40, sp4C);
		sp38 = func_800A3378(self);
		if (sp3C != 0.0f)
		{
			if (sp3C < 0.0f)
			{
				if (func_8008E1C4(self) != 0)
				{
					sp38 = ml_map_f(sp38, 0.0f, 1.0f, sp3C * 0.5f, -1.0f);
				}
				else
				{
					sp38 = sp3C * 0.5f;
				}
				ml_vec3f_apply_scale(sp58, 1.0f + sp38);
			}
			else
			{
				ml_vec3f_apply_scale(sp58, (0, 1.0f) + sp3C * 0.2f);
			}
		}
	}
	func_800EFA20(sp7C, sp58, func_80094E98(self));
	func_800EFA20(sp70, sp64, func_80094E98(self));
	ml_vec3f_subtract(sp7C, sp70);
	ml_vec3f_apply_scale(sp7C, time_getDelta() * 30.0f);
	ml_vec3f_add(self->unkC8->unk10, sp7C);
	self->unkC8->unk10[1] += (self->unkC8->unk34[0] * time_getDelta());
	if (self->unkC8->unk10[1] < self->unkC8->unk34[1])
	{
		self->unkC8->unk10[1] = self->unkC8->unk34[1];
	}
	func_800EFA20(self->unkC8->unk28, self->unkC8->unk10, time_getDelta());
	ml_vec3f_add(self->unkC8->unk4, self->unkC8->unk28);
	func_800F2168(self->unkC8->unk10, 0.0001f);
}

void func_8009B08C(PlayerState* self) {
	f32 sp2C[3];
	f32 sp28;

	sp28 = time_getDelta();
	ml_getdiff_vec3f(sp2C, self->unkC8->unk1C, self->unkC8->unk10);
	ml_vec3f_apply_scale(sp2C, self->unkC8->unk40[1] * sp28);
	if (((SQ(sp2C[0]) + SQ(sp2C[1]) + SQ(sp2C[2]))) < 0.02f)
	{
		ml_vec3f_copy(self->unkC8->unk10, self->unkC8->unk1C);
	}
	else
	{
		ml_vec3f_add(self->unkC8->unk10, sp2C);
	}
	func_800EFA20(self->unkC8->unk28, self->unkC8->unk10, sp28);
	ml_vec3f_add(self->unkC8->unk4, self->unkC8->unk28);
}

void func_8009B170(PlayerState* self)
{
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = time_getDelta();
    self->unkC8->unk10[1] += self->unkC8->unk34[0] * temp_f0;
    temp_f2 = self->unkC8->unk34[1];
    if (self->unkC8->unk10[1] < temp_f2)
    {
        self->unkC8->unk10[1] = temp_f2;
    }
    func_800EFA20(self->unkC8->unk28, self->unkC8->unk10, temp_f0);
    ml_vec3f_add(self->unkC8->unk4, self->unkC8->unk28);
}

void func_8009B1FC(PlayerState* self) {
    f32 temp_f0;
    f32 temp_f12;
    f32 var_f2;

    temp_f0 = time_getDelta();

    self->unkC8->unk10[1] += self->unkC8->unk34[0] * temp_f0;

    var_f2 = self->unkC8->unk10[1];
    temp_f12 = self->unkC8->unk34[1];

    if (var_f2 < temp_f12) {
        self->unkC8->unk10[1] = temp_f12;
        var_f2 = self->unkC8->unk10[1];
    }

    self->unkC8->unk28[1] = var_f2 * temp_f0;
    self->unkC8->unk4[1] += self->unkC8->unk28[1];
}

void func_8009B27C(PlayerState* self)
{
	f32 sp3C[3];
	f32 sp30[3];
	func_80098590(self, sp30);
	self->unkC8->unk4[0] = sp30[0];
	self->unkC8->unk4[2] = sp30[2];
	if (func_8009861C(self) == 2)
	{
		func_800EEB9C(sp3C, func_800136E4(func_80098610(self) + 180.0f), -func_80098628(self));
	}
	else
	{
		func_800EEB9C(sp3C, yaw_get(self), -func_80098628(self));
	}

	self->unkC8->unk4[0] += sp3C[0];
	self->unkC8->unk4[1] += sp3C[1];
	self->unkC8->unk4[2] += sp3C[2];
	self->unkC8->unk1C[0] = self->unkC8->unk1C[2] =
	self->unkC8->unk10[0] = self->unkC8->unk10[2] = 0.0f;
	func_8009B08C(self);
}

void func_8009B3B8(PlayerState* self)
{
    ml_vec3f_copy(self->unkC8->unk28, self->unkC8->unk10);
    ml_vec3f_apply_scale(self->unkC8->unk28, time_getDelta());
    ml_vec3f_add(self->unkC8->unk4, self->unkC8->unk28);
}

void func_8009B414(PlayerState* self)
{
    f32 sp1C[3];

    player_getCoords(self, sp1C);
    ml_getdiff_vec3f(self->unkC8->unk28, self->unkC8->unk4, sp1C);
}

void func_8009B450(PlayerState* self)
{
    self->unkC8->unk4C[0] += time_getDelta();
    self->unkC8->unk4[1] = self->unkC8->unk40[2] + (func_80013970(func_800F0F9C(self->unkC8->unk4C[0], 1.2f) * 360.0f) * 5.0f);
}

void func_8009B4D0(PlayerState* self, f32 arg1[3]) 
{
    ml_vec3f_copy(arg1, self->unkC8->unk28);
}

void func_8009B4FC(PlayerState* self)
{
    self->unkC8->currentPhysicsType = 0;
    self->unkC8->unk4C[1] = 1.0f;
    ml_vec3f_assign_value(self->unkC8->unk10, 0.0f, -1.0f, 0.0f);
    ml_vec3f_clear(self->unkC8->unk1C);
    ml_vec3f_clear(self->unkC8->unk28);
    ml_vec3f_clear(self->unkC8->unk4);
    self->unkC8->unk40[1] = 2.0f;
    func_8009BC34(self);
}
void func_8009B590(PlayerState* self)
{
	f32 temp_t6;
	player_getCoords(self, self->unkC8->unk4);
	self->unkC8->unk4C[1] *= player_getSpeedModifier(self);
	switch (self->unkC8->currentPhysicsType)
	{
		case 0:
			break;
		case 12:
			_bamovegoto_entrypoint_14(self);
			break;
		case 11:
			func_8009B450(self);
			break;
		case 8:
			func_8009B3B8(self);
			break;
		case 1:
			func_8009B170(self);
			break;
		case 9:
			func_8009B08C(self);
			break;
		case 2:
			baphysics_set_target_yaw(self, yaw_getIdeal(self));
			func_8009AE08(self);
			break;
		case 5:
			baphysics_set_target_yaw(self, func_800136E4(yaw_getIdeal(self) + 180.0f));
			func_8009AE08(self);
			break;
		case 3:
			func_8009AE08(self);
			break;
		case 13:
			_bamoveledge_entrypoint_3(self);
			break;
		case 6:
			if (bastick_distance(self) > 0.0f)
			{
				baphysics_set_target_yaw(self, bastick_getAngleRelativeToBanjo(self));
			}
			func_8009AE08(self);
			break;
		case 10:
			func_8009B27C(self);
			break;
		case 16:
			_bsfirstp_entrypoint_27(self);
			func_8009AE08(self);
			func_8009B414(self);
			break;
		case 17:
			_bsfirstp_entrypoint_27(self);
			func_8009B1FC(self);
			break;
		case 14:
			baphysics_set_target_yaw(self, yaw_get(self));
			func_8009AE08(self);
			break;
		case 15:
			_bamovethrust_entrypoint_5(self);
			break;
		case 18:
			_bamovespline_entrypoint_10(self);
			break;
		case 19:
			_bamovehover_entrypoint_2(self);
			break;
	}
	player_setCoords(self, self->unkC8->unk4);
	self->unkC8->unk4C[1] = 1.0f;
}
void func_8009B7C0(PlayerState* self)
{
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    self->unkC8->unk10[2] = 0.0f;
    self->unkC8->unk10[0] = self->unkC8->unk10[2];
}

void baphysics_set_type(PlayerState* self, BaPhysicsType nextType)
{
	BaPhysicsType currentType;
	currentType = self->unkC8->currentPhysicsType;
	if (currentType == nextType)
	{
		return;
	}

	switch (currentType)
	{
		case BA_PHYSICS_D_END:
			_bamoveledge_entrypoint_1(self);
			break;
		case 15:
			_bamovethrust_entrypoint_0(self);
			break;
		case BA_PHYSICS_C_GOTO:
			_bamovegoto_entrypoint_5(self);
			break;
		case 18:
			_bamovespline_entrypoint_5(self);
			break;
		case 19:
			_bamovehover_entrypoint_0(self);
			break;
		default:
			break;
		}
	self->unkC8->currentPhysicsType = nextType;
	switch (nextType)
	{
		case BA_PHYSICS_C_GOTO:
			_bamovegoto_entrypoint_6(self);
			return;
		case BA_PHYSICS_D_END:
			_bamoveledge_entrypoint_2(self);
			return;
		case BA_PHYSICS_B_TRANSFORM:
			if (currentType != nextType)
			{
				self->unkC8->unk40[2] = self->unkC8->unk4[1];
				self->unkC8->unk4C[0] = 0.0f;
				return;
			}
			break;
		case 15:
			_bamovethrust_entrypoint_1(self);
			return;
		case 18:
			_bamovespline_entrypoint_6(self);
			return;
		case 19:
			_bamovehover_entrypoint_1(self);
			break;
		default:
			break;
	}
}

void func_8009B94C(PlayerState* self, f32* arg1)
{
    if (arg1 != NULL)
    {
        ml_vec3f_copy(self->unkC8->unk1C, arg1);
        return;
    }
    ml_vec3f_clear(self->unkC8->unk1C);
}

void func_8009B98C(PlayerState* self, f32* arg1) {
    ml_vec3f_copy(self->unkC8->unk4, arg1);
}

void baphysics_set_target_horizontal_velocity(PlayerState* self, f32 vel) {
    self->unkC8->unk34[2] = vel;
}

void baphysics_set_target_yaw(PlayerState* self, f32 target_yaw) {
    self->unkC8->unk40[0] = func_800136E4(target_yaw);
}

void func_8009B9F0(PlayerState* self, f32 arg1)
{
    baphysics_set_target_horizontal_velocity(self, arg1);
    func_800EEB9C(self->unkC8->unk1C, self->unkC8->unk40[0], self->unkC8->unk34[2]);
    self->unkC8->unk1C[1] = 0.0f;
    self->unkC8->unk10[0] = self->unkC8->unk1C[0];
    self->unkC8->unk10[2] = self->unkC8->unk1C[2];
}

void baphysics_set_vertical_velocity(PlayerState* self, f32 arg1) {
    self->unkC8->unk10[1] = arg1;
}

void baphysics_set_horizontal_velocity(PlayerState* self, f32 yaw, f32 vel) {
    func_800EEB9C(self->unkC8->unk10, yaw, vel);
}

void func_8009BA9C(PlayerState* self, f32* arg1)
{
    if (arg1 != NULL)
    {
        ml_vec3f_copy(self->unkC8->unk10, arg1);
        return;
    }
    ml_vec3f_clear(self->unkC8->unk10);
}

f32 func_8009BADC(PlayerState* self) {
    return self->unkC8->unk34[0];
}

f32 func_8009BAE8(PlayerState* self) {
    return self->unkC8->unk34[1];
}

BaPhysicsType func_8009BAF4(PlayerState* self) {
    return self->unkC8->currentPhysicsType;
}

f32 baphysics_get_target_horizontal_velocity(PlayerState* self) {
    return self->unkC8->unk34[2];
}
f32 func_8009BB0C(PlayerState* self) {
    return self->unkC8->unk1C[1];
}

f32 func_8009BB18(PlayerState* self) {
    return self->unkC8->unk40[0];
}

void func_8009BB24(PlayerState* self, f32* arg1) { ml_vec3f_copy(arg1, self->unkC8->unk10); }

f32 baphysics_get_vertical_velocity(PlayerState* self) {
    return self->unkC8->unk10[1];
}
f32 baphysics_get_horizontal_velocity(PlayerState* self)
{
    f32 temp_f0;
    f32 temp_f2;
    temp_f0 = self->unkC8->unk10[2];
    temp_f2 = self->unkC8->unk10[0];
    return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

f32 baphysics_get_velocity(PlayerState* self) {
    return ml_vec3f_magnitude(self->unkC8->unk10);
}

f32 func_8009BBB8(PlayerState* self) {
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = baphysics_get_horizontal_velocity(self);
    temp_f0 = baphysics_get_target_horizontal_velocity(self);
    if (sp1C < temp_f0) {
        var_f12 = sp1C / temp_f0;
    }
    else {
        var_f12 = 1.0f;
    }
    return var_f12;
}

void func_8009BC08(PlayerState* self, f32* arg1) {
    ml_vec3f_copy(arg1, self->unkC8->unk4);
}

void func_8009BC34(PlayerState* self)
{
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
}

void func_8009BC5C(PlayerState* self, f32 arg1) {
    self->unkC8->unk40[1] = arg1;
}

void baphysics_reset_gravity(PlayerState* self) {
    baphysics_set_gravity(self, D_80117EF0);
}

void baphysics_reset_terminal_velocity(PlayerState* self) {
    baphysics_set_terminal_velocity(self, D_80117EF4);
}

void baphysics_set_gravity(PlayerState* self, f32 arg1)
{
    self->unkC8->unk34[0] = arg1;
}

void baphysics_set_terminal_velocity(PlayerState* self, f32 arg1) {
    self->unkC8->unk34[1] = arg1;
}

s32 func_8009BCD4(PlayerState* self, f32 arg1)
{
    f32 temp_f0;
    f32 temp_f2;
    s32 var_v0;

    var_v0 = 0;
    temp_f0 = self->unkC8->unk10[2];
    temp_f2 = self->unkC8->unk10[0];
    return (((temp_f0 * temp_f0) + (temp_f2 * temp_f2)) <= (arg1 * arg1));
}

void func_8009BD18(PlayerState* self, f32 arg1) {
    self->unkC8->unk4C[1] = arg1;
}