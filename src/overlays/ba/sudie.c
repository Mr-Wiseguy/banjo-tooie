#include "ba/sudie.h"

void basudie_entrypoint_4(PlayerState*, f32, f32, f32, f32, f32);

void basudie_entrypoint_0(PlayerState* self)
{
    func_80091EF0(self);
}

void basudie_entrypoint_1(PlayerState* self)
{
	if (func_800F8B64() == 0)
	{
		func_80101238(0x9F, self->unk184);
		func_800F90F8(1);
		func_800C0658();
	}
}

void basudie_entrypoint_2(PlayerState* self, f32 arg1, f32 arg2, f32 arg3)
{
	basudie_entrypoint_4(self, arg1, arg2, arg3, 30.0f, 3.5f);
}

void basudie_entrypoint_3(PlayerState* self, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
	basudie_entrypoint_4(self, arg1, arg2, arg3, arg4, 3.5f);
}

void basudie_entrypoint_4(PlayerState* self, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
	f32 sp4C;
	f32 sp40[3];
	f32 sp34[3];

	basudie_entrypoint_1(self);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
	player_getCoords(self, sp40);
	func_800A32C4(self, sp34);
	func_800F1E6C(sp34, sp40, &sp4C);
	yaw_setIdeal(self, func_800136E4(sp4C + 180.0f));
	yaw_applyIdeal(self);
	baphysics_set_target_horizontal_velocity(self, arg1);
	baphysics_set_target_yaw(self, sp4C);
	baphysics_set_horizontal_velocity(self, sp4C, baphysics_get_target_horizontal_velocity(self));
	baphysics_set_vertical_velocity(self, arg2);
	baphysics_set_gravity(self, arg3);
	func_8008E944(self);
	func_8009514C(self);
	func_800A4DFC(self, 0xA);
	func_800C52F4(func_800A4C68(self), 2);
	_ncbadie_entrypoint_3(func_800A4CA8(self), arg4);
	func_800A0180(self);
	_batimer_set(self, 9, arg5);
}

void basudie_entrypoint_5(PlayerState* self)
{
	func_8009D3A8(self, 0);
	if (_batimer_decrement(self, 9) != 0)
	{
		basudie_entrypoint_0(self);
	}
}

void basudie_entrypoint_6(PlayerState* self)
{
	baphysics_reset_gravity(self);
	func_800A4E30(self);
	func_800C53EC(func_800A4C68(self), 2);
	func_800951B4(self);
}

int basudie_entrypoint_7(PlayerState* self)
{
	f32 sp24;
	f32 sp20;

	sp24 = player_getWaterHeight(self);
	sp20 = player_getGroundHeight(self);

	return _batimer_get(self, 9) != 0.0f && func_80096544(self) && player_inWater(self) && player_getCoordVertical(self) < sp24 - 150.0f && sp24 - sp20 > 100.0f;
}

void basudie_entrypoint_8(PlayerState* self) {
	func_80091E6C(self);
	func_800A4E30(self);
	func_800C53EC(func_800A4C68(self), 2);
}

void basudie_entrypoint_9(PlayerState* self, f32 arg1) {
	func_80091E48(self, 0x20);
	basudie_entrypoint_1(self);
	func_8008E944(self);
	func_800A4DFC(self, 0xA);
	func_800C52F4(func_800A4C68(self), 2);
	_ncbadie_entrypoint_3(func_800A4CA8(self), arg1);
	func_800A0180(self);
	_batimer_set(self, 9, 3.6f);
	_bashake_entrypoint_0(self, 3, 2);
}

void basudie_entrypoint_10(PlayerState* self) {
	if (_batimer_decrement(self, 9) != 0) {
		basudie_entrypoint_0(self);
	}
}

void basudie_entrypoint_11(PlayerState* self)
{
    func_8009E6EC(self);
    func_80099AA8(self);
}
void basudie_entrypoint_12(PlayerState* self) {
	if (player_inWater(self) != 0) {
		baphysics_set_terminal_velocity(self, -250.0f);
		return;
	}
	baphysics_reset_terminal_velocity(self);
}