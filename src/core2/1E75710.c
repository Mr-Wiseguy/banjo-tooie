#include "core2/1E75710.h"

s32 func_8009BE20() 
{
    return sizeof(ba_unknown_DC_s);
}

void func_8009BE28(PlayerState* self, f32 arg1, f32 arg2)
{
	ba_unknown_DC_s* temp2;
	f32 temp_f2;
	f32 sp2C;
	f32 gameSpeed;


	gameSpeed = time_getDelta();
	temp2 = self->unkDC;
	sp2C = func_80013728(temp2->unk4 - temp2->unk0);
	temp_f2 = sp2C * arg2;
	if (temp_f2 != 0.0f)
	{
		temp_f2 = temp_f2 < 0.0f ? ml_clamp_f(temp_f2, -arg1, -3.0f) : ml_clamp_f(temp_f2, 3.0f, arg1);
	}
	temp2->unk0 += func_800F212C(temp_f2 * gameSpeed, sp2C);
	temp2->unk0 = func_800136E4(temp2->unk0);
}

void func_8009BF04(PlayerState* self)
{
    self->unkDC->unk0 = 0.0f;
    self->unkDC->unk4 = 0.0f;
    func_8009C000(self);
}

void func_8009BF34(PlayerState* self)
{
    func_8009BE28(self, self->unkDC->unk8, self->unkDC->unkC);
}

void func_8009BF5C(PlayerState* self, f32 arg1) {
    self->unkDC->unk4 = func_800136E4(arg1);
}

void func_8009BF8C(PlayerState* self, f32 arg1) {
    self->unkDC->unk0 = func_800136E4(arg1);
}

void func_8009BFBC(PlayerState* self) {
    self->unkDC->unk0 = self->unkDC->unk4;
}

f32 func_8009BFCC(PlayerState* self) {
    return self->unkDC->unk0;
}

f32 func_8009BFD8(PlayerState* self)
{
    return self->unkDC->unk4;
}

void func_8009BFE4(PlayerState* self, f32 arg1, f32 arg2)
{
    self->unkDC->unk8 = arg1;
    self->unkDC->unkC = arg2;
}

void func_8009C000(PlayerState* self) {
    func_8009BFE4(self, 500.0f, 0.8f);
}