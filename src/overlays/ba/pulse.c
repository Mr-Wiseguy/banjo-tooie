#include "ba/pulse.h"

s32 bapulse_entrypoint_0() 
{
	return sizeof(ba_unknown_E8_s);
}

f32 bapulse_entrypoint_1(PlayerState* self)
{
	return ml_map_f(self->unkE8->unk8, 0.0f, self->unkE8->unk4, 0.0f, 1.0f);
}

void bapulse_entrypoint_2(PlayerState* self) {}

void bapulse_entrypoint_3(PlayerState* self, f32 arg1, f32 arg2) {
	self->unkE8->unk0 = 0;
	self->unkE8->unk8 = arg1;
	self->unkE8->unk4 = arg2;
}

void bapulse_entrypoint_4(PlayerState* self) {
	f32 temp_f0;

	temp_f0 = time_getDelta();
	if (self->unkE8->unk0 == 0)
	{
		self->unkE8->unk8 = (f32)(self->unkE8->unk8 + temp_f0);
		if (self->unkE8->unk4 <= self->unkE8->unk8)
		{
			self->unkE8->unk8 = (f32)(self->unkE8->unk4 - ml_remainder_f(self->unkE8->unk8, self->unkE8->unk4));
			self->unkE8->unk0 = 1;
		}
	}
	else
	{
		self->unkE8->unk8 = (f32)(self->unkE8->unk8 - temp_f0);
		if (self->unkE8->unk8 < 0.0f)
		{
			self->unkE8->unk8 = ml_remainder_f(-self->unkE8->unk8, self->unkE8->unk4);
			self->unkE8->unk0 = 0;
		}
	}
}
