#include "bs/climb.h"


typedef struct UNKD_808008C0_2 {
	s32 unk0;
	f32 unk4;
}UNKD_808008C0_2_bsclimb;
typedef struct UNKD_808008C0 {
	UNKD_808008C0_2_bsclimb unk0[2];
	s16 unk10;
	s16 unk12;
}UNKD_808008C0_bsclimb;
extern UNKD_808008C0_bsclimb D_808008C0_bsclimb[];
extern s32 D_808008FC_bsclimb[];
extern s32 D_8080090C_bsclimb[];
extern s32 D_8080091C_bsclimb[];

void func_80800000_bsclimb(PlayerState* arg0, s32 arg1) {
	s32 temp = func_80098634() - 1;
	UNKD_808008C0_bsclimb* temp_v1;
	temp_v1 = &D_808008C0_bsclimb[temp];
	func_8009DF94(arg0, temp_v1->unk0[0].unk0, temp_v1->unk0[arg1].unk4, temp_v1->unk0[arg1 + 1].unk0);
}

void func_8080005C_bsclimb(PlayerState* self)
{
	f32 sp2C[3];
	f32 sp28;
	f32 temp;
	sp28 = bastick_getY(self);

	temp = mlAbsF(sp28) < 0.03f ? 0.0f : func_800F1344(sp28, 0.03f, 1.0f, 100.0f, 300.0f);
	sp2C[0] = 0.0f;
	sp2C[1] = temp;
	sp2C[2] = 0.0f;
	func_8009B94C(self, sp2C);
}

void func_808000E8_bsclimb(PlayerState* self)
{
	if (func_8009861C(self) == 2)
	{
		func_8009D2D8(self, 3);
	}
	else
	{
		func_8009D2D8(self, 6);
	}
	yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
	yaw_setVelocityBounded(self, 500.0f, 15.0f);
	bastick_setZoneMax(self, 0, 0.03f);
	bastick_setZoneMax(self, 1, 1.0f);
	baphysics_set_type(self, BA_PHYSICS_A_CLIMB);
	func_8009BC5C(self, 10.0f);
	func_800961AC(self, 5);
	func_800959C8(self, 80.0f, 10.0f);
	func_800A4DA4(self, 0xC);
	if (func_8008E0E8(self) != 0)
	{
		_bapackctrl_entrypoint_5(self, 4);
	}
}

void func_808001D0_bsclimb(PlayerState* self)
{
	if (func_8009E74C(self, 0xA) == 0) {
		func_800A4E30(self);
		bastick_resetZones(self);
		func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
		baphysics_set_type(self, BA_PHYSICS_2_NORMAL);
		func_800961AC(self, 1);
		func_80095A40(self);
		if (func_8008E0E8(self) != 0) {
			_bapackctrl_entrypoint_5(self, 3);
		}
	}
}

void func_80800258_bsclimb(PlayerState* self, f32 arg1, f32 arg2) {
	self->unk16C = (rand_f() * arg2) + arg1;
}

int func_80800298_bsclimb(PlayerState* self)
{
	return mlAbsF(func_8009BB0C(self)) > 0.0f || (yaw_get(self) != yaw_getIdeal(self));
}

void bsclimb_entrypoint_0(PlayerState* self) {
	f32 sp3C;
	f32 sp30[3];
	f32 sp24[3];

	activePlayer_getCoords(sp30);
	func_80098590(self, sp24);
	if (func_8009E77C(self, 0xA) == 0) {
		func_800F1E6C(sp30, sp24, &sp3C);
		yaw_setIdeal(self, sp3C);
		yaw_applyIdeal(self);
	}
	func_800C6DA0(0x40);
	baanim_playForDuration_loopSmooth(self, 0xB2, 2.64f);
	func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
	func_808000E8_bsclimb(self);
	self->unk160.word = 1;
	func_80800258_bsclimb(self, 1.0f, 0.5f);
	self->unk15C.word = 0;
}

void bsclimb_entrypoint_1(PlayerState* self) {
	BanjoStateId nextState;
	AnimCtrl* sp20;

	nextState = BS_STATE_0_INVALID;
	sp20 = baanim_getAnimCtrlPtr(self);
	func_800956B8(self);
	switch (self->unk15C.word)
	{
	case 0:
		self->unk16C -= time_getDelta();
		if (self->unk16C <= 0.0f) {
			baanim_playForDuration_onceSmooth(self, 0xB1, 2.96f);
			self->unk15C.word = 1;
		}
		break;
	case 1:
		if (anctrl_isStopped(sp20) != 0) {
			baanim_playForDuration_loopSmooth(self, 0xB2, 2.64f);
			func_80800258_bsclimb(self, 3.0f, 4.0f);
			self->unk15C.word = 0;
		}
		break;
	}
	func_8080005C_bsclimb(self);
	if (func_80800298_bsclimb(self) != 0) {
		nextState = 0x50;
	}
	if (bakey_pressed(self, BUTTON_A) != 0) {
		nextState = BS_STATE_5_JUMP;
	}
	if (self->unk160.word == 0) {
		nextState = BS_STATE_1_IDLE;
	}
	self->unk160.word = 0;
	bs_setState(self, nextState);
}

void bsclimb_entrypoint_2(PlayerState* self)
{
    func_808001D0_bsclimb(self);
}

s32 bsclimb_entrypoint_3(s32 arg0) {
	return D_808008FC_bsclimb[arg0];
}

void bsclimb_entrypoint_4(PlayerState* self) {
	baanim_playForDuration_loopSmooth(self, 0xA, 0.9f);
	func_8008CA4C(self, BAANIM_UPDATE_3_SCALE_VERT);
	baanim_setDurationRange(self, 0.3f, 1.5f);
	func_8008C9F0(self, 100.0f, 300.0f, 0.6f, 0.4f);
	func_808000E8_bsclimb(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_5.s")

void bsclimb_entrypoint_6(PlayerState* self)
{
    func_808001D0_bsclimb(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_9.s")

void bsclimb_entrypoint_10(PlayerState* self)
{
    func_808001D0_bsclimb(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_12.s")
