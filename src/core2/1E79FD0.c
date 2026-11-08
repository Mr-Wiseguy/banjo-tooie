#include "core2/1E79FD0.h"

extern f32 D_80125490;

s32 func_800A06E0() 
{
    return sizeof(BaUnknown138);
}

void func_800A06E8(PlayerState* self) {
	func_800A0714(self, func_80092B80(self));
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E79FD0/func_800A0714.s")

s32 func_800A0C20(PlayerState* self) {
    return self->unk138->unk10;
}

f32 func_800A0C2C(PlayerState* self) {
    return self->unk138->unk0;
}

f32 func_800A0C38(PlayerState* self) {
    return self->unk138->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E79FD0/func_800A0C44.s")

void func_800A0CD0(PlayerState* self, s32 arg1) {
    self->unk138->unk12 = arg1;
}

void func_800A0CDC(PlayerState* self, s32 arg1) {
    self->unk138->unkD = arg1;
}

void func_800A0CE8(PlayerState* self, s32 arg1) {
    self->unk138->unkE = arg1;
}

void func_800A0CF4(PlayerState* self, s32 arg1) 
{
    func_800A0D14(self, arg1, 0.0f);
}

void func_800A0D14(PlayerState* self, s32 arg1, f32 arg2) {
    self->unk138->unk8 = arg2;
    self->unk138->unkC = arg1;
    if (arg2 == 0.0f) {
        self->unk138->unk10 = arg1;
    }
}

void func_800A0D44(PlayerState* self, s32 arg1) {
    func_800A0D14(self, arg1, 0.2f);
}

void func_800A0D68(PlayerState* self, s32 arg1) {
    self->unk138->unk17 = arg1;
}

void func_800A0D74(PlayerState* self, f32 arg1) {
    self->unk138->unk0 = arg1;
}

void func_800A0D84(PlayerState* self, f32 arg1) {
    self->unk138->unk4 = arg1;
}

void func_800A0D94(PlayerState* self, s32 arg1) {
    self->unk138->unk16 = arg1;
}

void func_800A0DA0(PlayerState* self, s32 arg1) {
    self->unk138->unk14 = arg1;
}

void func_800A0DAC(PlayerState* self, s32 arg1) {
    self->unk138->unk13 = arg1;
}

void func_800A0DB8(PlayerState* self, s32 arg1) {
    self->unk138->unkF = arg1;
}

void func_800A0DC4(PlayerState* self, s32 arg1) {
    self->unk138->unk15 = arg1;
}

void func_800A0DD0(PlayerState* self, s32 arg1) {
    self->unk138->unk11 = arg1;
}

void func_800A0DDC(PlayerState* self)
{
	if (self->unk138->unk8 != 0.0f)
	{
		self->unk138->unk8 -= time_getDelta();
		if (self->unk138->unk8 <= 0.0f)
		{
			self->unk138->unk10 = self->unk138->unkC;
		}
	}
}

s32 func_800A0E50(void) 
{
    return sizeof(BaUnknown150);
}

f32 func_800A0E58(PlayerState* self)
{
    return self->unk150->unk8;
}

void func_800A0E64(PlayerState* self)
{
	unkStruct800BA198* temp_v0;
	f32 sp3C[2]; //Should be f32[3] but I guess temp_v0 is just going to use the memory afterwards
	s32 temp_s0;
	f32 sp34;

	if (func_80096544(self) != 0)
	{
		func_8009DBF0(self, 0x409, rand_fBounded(D_80125490, 0.75f));
		player_getCoords(self, sp3C);
		sp34 = player_getWaterHeight(self);
		sp3C[1] = sp34;
		temp_s0 = _fxsplash_entrypoint_2(sp3C, 35.0f);
		_fxripple_entrypoint_0(3, sp3C);
		func_800BA930((unkStruct800BA198*)temp_s0, -0x15E, 0x12C, -0x15E, 0x15E, 0x1F4, 0x15E);
		func_800BA22C(temp_s0, 0xA);
		func_800BA930((unkStruct800BA198*)temp_s0, -0x96, 0x1F4, -0x96, 0x96, 0x320, 0x96);
		func_800BA22C(temp_s0, 0xA);
		_fxsplash25d_entrypoint_0(sp3C);
		sp3C[1] -= 30.0f;
		temp_v0 = _fxairbub_entrypoint_1(sp3C, 20.0f, sp34, 1.0f);
		func_800BA930(temp_v0, -0x3C, -0xFA, -0x3C, 0x3C, -0x96, 0x3C);
		func_800BA22C(temp_v0, 8);
	}
}

//Player_Is_Grounded
s32 player_isGrounded(PlayerState* self)
{
    return self->unk150->grounded;
}

s32 func_800A0FD8(PlayerState* self)
{
    return self->unk150->unk0;
}

s32 func_800A0FE4(PlayerState* self)
{
    return self->unk150->unk1;
}

void func_800A0FF0(PlayerState* self)
{
	self->unk150->grounded = 1;
	self->unk150->unk0 = 0;
	self->unk150->unk1 = 0;
	self->unk150->unk4 = 50.0f;
	self->unk150->unk8 = 70.0f;
	self->unk150->unkC = -1.0f;
}

void func_800A1040(PlayerState* self)
{
    self->unk150->unk4 = self->unk150->unkC;
    self->unk150->unk8 = self->unk150->unk10;
    self->unk150->unkC = -1.0f;
}

void func_800A106C(PlayerState* self, f32 arg1, f32 arg2)
{
    self->unk150->unkC = self->unk150->unk4;
    self->unk150->unk10 = self->unk150->unk8;
    self->unk150->unk4 = arg1;
    self->unk150->unk8 = arg2;
}

void func_800A10A0(PlayerState* self)
{
	f32 sp2C;
	s32 sp28;
	s32 sp24;

	sp28 = (s32)self->unk150->unk0;
	sp2C = player_getWaterHeight(self) - self->unk150->unk4;
	if (sp28 != 0)
	{
		self->unk150->unk0 = player_touchingWater(self) && player_getCoordVertical(self) < (sp2C + 2.0f);
	}
	else
	{
		self->unk150->unk0 = player_touchingWater(self) && player_getCoordVertical(self) < (sp2C - 2.0f);
	}
	if ((sp28 == 0) && (self->unk150->unk0 != 0) && (baphysics_get_vertical_velocity(self) < -40.0f))
	{
		func_800A0E64(self);
	}
	sp24 = func_800F3ED0(self);
	if (func_800A0FD8(self) != 0)
	{
		self->unk150->unk1 = 1;
	}
	else if ((player_isStable(self) != 0) || (sp24 == 0xA) || (sp24 == 5))
	{
		self->unk150->unk1 = 0;
	}
	self->unk150->grounded = func_80096518(self);
}