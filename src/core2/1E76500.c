#include "core2/1E76500.h"

s32 func_8009CC10() 
{
    return sizeof(ba_unknown_F0_s);
}

s32 func_8009CC18(PlayerState* self, f32* arg1)
{

	if (self->unkF0->unk0[self->unkF0->unk80 - 1].unk1 == 0)
	{
		return 0;
	}
	ml_vec3f_copy(arg1, self->unkF0->unk0[self->unkF0->unk80 - 1].unk4);
	return 1;
}

s32 func_8009CC68(PlayerState* self)
{
	if (self->unkF0->unk80 == 0)
	{
		return 0;
	}
	return self->unkF0->unk0[self->unkF0->unk80 - 1].unk0;
}

void func_8009CC90(PlayerState* arg0) {
	arg0->unkF0->unk81 = 0;
	arg0->unkF0->unk80 = 0;
}

void func_8009CCA4(PlayerState* arg0)
{
	if (arg0->unkF0->unk80 != 0)
	{
		arg0->unkF0->unk80--;
		if (arg0->unkF0->unk80 == 0)
		{
			func_8009BDAC(arg0, 1.2f);
			arg0->unkF0->unk81 = 0;
		}
	}
}

void func_8009CCFC(PlayerState* self, s32 arg1) {

	self->unkF0->unk0[self->unkF0->unk80].unk0 = arg1;
	self->unkF0->unk0[self->unkF0->unk80].unk1 = 0;
	ml_vec3f_clear(self->unkF0->unk0[self->unkF0->unk80].unk4);
	self->unkF0->unk80++;
}

void func_8009CD70(PlayerState* self, f32* arg1)
{
	self->unkF0->unk0[self->unkF0->unk80 - 1].unk1 = 1;
	if (arg1 != NULL)
	{
		ml_vec3f_copy(self->unkF0->unk0[self->unkF0->unk80 - 1].unk4, arg1);
		return;
	}
	ml_vec3f_clear(self->unkF0->unk0[self->unkF0->unk80 - 1].unk4);
}

void func_8009CDE0(PlayerState* arg0, s32 arg1)
{
	s32 var_v1;
	var_v1 = 0;
	switch (arg1)
	{
	default:
		var_v1 = 1;
		break;
	case 1:

		if (func_8009E7C8(arg0, 0x1E) == 2)
		{
			var_v1 = 1;
		}
		break;
	case 2:
		if (func_8009E7C8(arg0, 0x1C) == 2)
		{
			var_v1 = 1;
		}
		break;
	case 3:
		if (func_8009E7C8(arg0, 0x1D) == 2)
		{
			var_v1 = 1;
		}
		break;
	case 4:
		if (func_8009E7C8(arg0, 0x25) == 2)
		{
			var_v1 = 1;
		}
		break;

	}
	if (var_v1)
	{
		arg0->unkF0->unk81 = arg1;
	}
}

void func_8009CEE8(PlayerState* arg0) {
	if (arg0->unkF0->unk80 != 0) {
		arg0->unkF0->unk81 = 0;
	}
}

void func_8009CF04(PlayerState* arg0)
{
	s32 index;
	s32 var_a2;
	s32 temp;
	if (arg0->unkF0->unk80)
	{
		var_a2 = arg0->unkF0->unk0[arg0->unkF0->unk80 - 1].unk0;

		for (index = 0; index < arg0->unkF0->unk80; index++)
		{
			if (arg0->unkF0->unk0[index].unk0 == 1)
			{
				var_a2 = 1;
			}
		}

		if (var_a2 != arg0->unkF0->unk81)
		{
			func_8009CDE0(arg0, var_a2);
		}
	}
}