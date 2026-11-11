#include "ba/drone.h"

extern u8 D_80800630_badrone[];

s32 badrone_entrypoint_0() 
{
    return sizeof(BaUnknown54);
}

s32 badrone_entrypoint_1(PlayerState* self)
{
	return D_80800630_badrone[self->unk54->unk0];
}

void badrone_entrypoint_2(PlayerState* self, f32* arg1) {
	ml_vec3f_copy(arg1, self->unk54->unk24);
}

s32 badrone_entrypoint_3(PlayerState* self) {
	return self->unk54->unk0;
}

void badrone_entrypoint_4(PlayerState* self)
{
	self->unk54->unk0 = self->unk54->unk1;
}

void badrone_entrypoint_5(PlayerState* self) {
	self->unk54->unk4 = 0;
	self->unk54->unk5 = 1;
	self->unk54->unk8 = 1.0f;
	ml_vec3f_clear(self->unk54->unk10);
	self->unk54->unkC = 1.0f;
	self->unk54->unk1C = 0;
}

s32 badrone_entrypoint_6(PlayerState* self)
{
	if (self->unk54->unk1C != NULL)
	{
		return self->unk54->unk1C(self->unk54->unk20, self->unk184, self);
	}
}

s32 badrone_entrypoint_7(PlayerState* self) {
	return self->unk54->unk4;
}

void badrone_entrypoint_8(PlayerState* self, f32* arg1, f32* arg2, f32* arg3) {
	ml_vec3f_copy(arg1, self->unk54->unk10);
	*arg2 = self->unk54->unk8;
	*arg3 = self->unk54->unkC;
}

s32 badrone_entrypoint_9(PlayerState* self) {
	return self->unk54->unk5;
}

void badrone_entrypoint_10(PlayerState* self, s32 arg1) {
	self->unk54->unk4 = arg1;
}

void badrone_entrypoint_11(PlayerState* self, s32 arg1, s32 arg2) {
	self->unk54->unk1C = arg1;
	self->unk54->unk20 = arg2;
}

void badrone_entrypoint_12(PlayerState* self, s32 arg1) {
	self->unk54->unk5 = arg1;
}

void badrone_entrypoint_13(PlayerState* self, f32* arg1) {
	ml_vec3f_copy(self->unk54->unk10, arg1);
	if ((self->unk54->unk0 == 1) && (func_8009BAF4(self) == 0xC)) {
		_bamovegoto_entrypoint_12(self, arg1);
	}
}

void badrone_entrypoint_14(PlayerState* self, f32* arg1, f32 arg2) {
	ml_vec3f_copy(self->unk54->unk10, arg1);
	self->unk54->unkC = arg2;
	self->unk54->unk8 = 0.0f;
	self->unk54->unk1 = 1;
	bs_setState(self, _badata_entrypoint_21(self));
}

void badrone_entrypoint_15(PlayerState* self, f32* arg1, f32 arg2) {
	ml_vec3f_copy(self->unk54->unk10, arg1);
	self->unk54->unk8 = arg2;
	self->unk54->unkC = 0.0f;
	self->unk54->unk1 = 1;
	bs_setState(self, _badata_entrypoint_21(self));
}

void badrone_entrypoint_16(PlayerState* self, f32* arg1, f32 arg2) {
	f32 sp2C[3];
	f32 sp20[3];

	player_getCoords(self, sp2C);
	ml_getdiff_vec3f(sp20, arg1, sp2C);
	badrone_entrypoint_15(self, arg1, ml_vec2f_magnitude(sp20) / arg2);
}

BanjoStateId func_80800348_badrone(PlayerState* self, s32 arg1) {
	self->unk54->unk1 = arg1;
	return _badata_entrypoint_21(self);
}

void badrone_entrypoint_17(PlayerState* self) {
	self->unk54->unk1 = 7;
	_badata_entrypoint_23(self);
}

BanjoStateId badrone_entrypoint_18(PlayerState* self, s32 arg1) {
	self->unk54->unk48 = arg1;
	return func_80800348_badrone(self, 0xC);
}

BanjoStateId badrone_entrypoint_19(PlayerState* self)
{
	return func_80800348_badrone(self,0xD);
}

BanjoStateId badrone_entrypoint_20(PlayerState* self, f32* arg1, s32 arg2) {
	self->unk54->unk30 = arg2;
	ml_vec3f_copy(self->unk54->unk34, arg1);
	return func_80800348_badrone(self, 8U);
}

void badrone_entrypoint_21(PlayerState* self) {
	self->unk54->unk1 = 0xF;
	_badata_entrypoint_22(self);
}

BanjoStateId badrone_entrypoint_22(PlayerState* self, f32* arg1) {
	ml_vec3f_copy(self->unk54->unk34, arg1);
	return func_80800348_badrone(self, 0xBU);
}

BanjoStateId badrone_entrypoint_23(PlayerState* self, f32* arg1) {
	ml_vec3f_copy(self->unk54->unk34, arg1);
	return func_80800348_badrone(self, 0xAU);
}

BanjoStateId badrone_entrypoint_24(PlayerState* self)
{
	return func_80800348_badrone(self,0x2);
}

BanjoStateId badrone_entrypoint_25(PlayerState* self)
{
	return func_80800348_badrone(self,0x9);
}

void badrone_entrypoint_26(PlayerState* self) {
	self->unk54->unk1 = 3;
	_badata_entrypoint_23(self);
}

BanjoStateId badrone_entrypoint_27(PlayerState* self)
{
    return func_80800348_badrone(self,0x6);
}

BanjoStateId badrone_entrypoint_28(PlayerState* self) {
	baflag_clear(self, BA_FLAG_19);
	return func_80800348_badrone(self, 4U);
}

BanjoStateId badrone_entrypoint_29(PlayerState* self)
{
    return func_80800348_badrone(self,0xE);
}

int badrone_entrypoint_30(PlayerState* self)
{
	return badrone_entrypoint_3(self) == 2 && !player_inWater(self);
}

s32 badrone_entrypoint_31(PlayerState* self) {
	if (self->unk54->unk0 == 1) {
		return 1;
	}
	return 0;
}

void badrone_entrypoint_32(PlayerState* self)
{
	self->unk54->unk1 = 0U;
	self->unk54->unk0 = self->unk54->unk1;
}

void badrone_entrypoint_33(PlayerState* self, f32* arg1) {
	ml_vec3f_copy(self->unk54->unk24, arg1);
}
