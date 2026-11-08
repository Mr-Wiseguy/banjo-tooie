#include "bs/drone/jump.h"

extern s32 _bsdronejump_entrypoint_0;

void bsdronejump_entrypoint_0(PlayerState* self, f32* arg1, f32 arg2) {
	s32 pad;
	f32 sp20;

	func_8008C990(self, ml_map_f(arg2, 0.0f, 1.0f, self->unk190.word, self->unk194.word));
	sp20 = _bamovegoto_entrypoint_3(self);
	arg1[1] += func_80013970(arg2 * 180.0f) * sp20 * 0.5f;
}

void bsdronejump_entrypoint_1(PlayerState* self)
{
    func_800961A0(self,0);
}

void bsdronejump_entrypoint_2(PlayerState* self) {
	f32 sp44;
	s32 pad;
	f32 sp34[3];
	AssetId sp30;

	_badata_entrypoint_8(self, &sp30, &self->unk190.word, &self->unk194.word);
	baanim_playForDuration_loopStartingAt(self, sp30, 1000.0f, self->unk190.word);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
	player_getCoords(self, sp34);
	sp44 = ml_vec3f_distance(sp34, self->unk54->unk34);
	yaw_setIdeal(self, func_800F1DF4(sp34, self->unk54->unk34));
	_bamovegoto_entrypoint_0(self);
	_bamovegoto_entrypoint_7(self, ml_map_f(sp44, 100.0f, 5000.0f, 0.4f, 4.5f));
	_bamovegoto_entrypoint_12(self, self->unk54->unk34);
	_bamovegoto_entrypoint_11(self, NULL, &_bsdronejump_entrypoint_0);
	_bamovegoto_entrypoint_13(self);
	func_800961A0(self, 1);
}

void bsdronejump_entrypoint_3(PlayerState* self)
{
    func_80099AA8(self);
}

void bsdronejump_entrypoint_4(PlayerState* self) {
	BanjoStateId nextState;

	nextState = BS_STATE_0_INVALID;
	if (_bamovegoto_entrypoint_4(self) != 0) {
		nextState = _badata_entrypoint_34(self);
	}
	bs_setState(self, nextState);
}