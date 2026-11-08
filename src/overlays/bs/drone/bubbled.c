#include "bs/drone/bubbled.h"

void func_80800000_bsdronebubbled(PlayerState* self) {
	func_8010114C(self->unk54->unk48, 0x2C, self->unk184);
	self->unk54->unk48 = 0;
}

void bsdronebubbled_entrypoint_0(PlayerState* self) {
	if (self->unk54->unk48 != 0) {
		func_80800000_bsdronebubbled(self);
	}
}

void bsdronebubbled_entrypoint_1(PlayerState* self) {
	f32 sp2C;
	enum asset_e sp28;

	_badata_entrypoint_0(self, &sp28, &sp2C);
	baanim_playForDuration_loopSmooth(self, sp28, sp2C);
	self->unk54->unk44 = sp2C;
	self->unk54->unk40 = 0;
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_7_FREEZE);
	func_8009D9D4(self);
}

void bsdronebubbled_entrypoint_2(PlayerState* self) {

	switch (func_8009E6EC(self))
	{
	case 0x21:
		func_80099B94(self);
		return;
	case 0x6F:
		func_8009E830(self, 1);
		return;
	case 0x70:
		bs_setState(self, _badata_entrypoint_34(self));
		return;
	case 0x7B:
		self->unk54->unk40 = ml_min_f(1.0f, self->unk54->unk40 + 0.2f);
		return;
	default:
		func_80099B94(self);
		return;
	}
}

void bsdronebubbled_entrypoint_3(PlayerState* self) {
	f32 sp24;

	sp24 = self->unk54->unk44;
	ml_timer_update(&self->unk54->unk40, time_getDelta() * 0.8333333f);
	anctrl_setDuration(baanim_getAnimCtrlPtr(self), ml_mapNormal_f(self->unk54->unk40, sp24, sp24 * 0.33333334f));
}

void bsdronebubbled_entrypoint_4(PlayerState* self) {}

void bsdronebubbled_entrypoint_5(PlayerState* self) {
	f32 sp24;
	enum asset_e sp20;

	_badata_entrypoint_0(self, &sp20, &sp24);
	sp24 = 2.0f * sp24;
	baanim_playForDuration_loopSmooth(self, sp20, sp24);
	func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_7_FREEZE);
}

void bsdronebubbled_entrypoint_6(PlayerState* self)
{
    func_80099B94(self);
}

void bsdronebubbled_entrypoint_7(PlayerState* self) {

}