#include "core2/1E67DA0.h"

extern s32 D_80117CAC;
extern s32 D_80126CE0[][3];
extern f32 D_80126D08[];

s32 func_8008E4B0(void) {
    return sizeof(BaUnknownC);
}

s32 *func_8008E4B8(PlayerState *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        self->unkC->unkC[i] = (s32)func_8009E138(self, i);
    }
    return self->unkC->unkC;
}

void func_8008E530(PlayerState* self, Unk80132ED0* arg1)
{
	Actor* temp_v0;
	s32 sp18;

	if ((!(arg1->unk18_16) ||
		((temp_v0 = func_80106790(arg1), !(temp_v0->unk64_17)) && (!(temp_v0->unk7A_3) ||
			(_chbounce_entrypoint_10(temp_v0) == 0))))
		&& ((sp18 = _glhittableDll_entrypoint_4(self->unkC->unk0, arg1), (func_800F424C(self) != 0)) ||
			(_glhittableDll_entrypoint_2(sp18) == 0) ||
			(_glhittableDll_entrypoint_8(sp18) == 0))
		&& (_glhittableDll_entrypoint_3(self->unkC->unk0, arg1, sp18) == 0))
	{
		func_800EB210(arg1, self->unkC->unk0, 0);
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E6BC.s")

void func_8008E6F0(PlayerState* self)
{
	f32 sp4C[3];
	f32 temp_f0;
	s32 temp_a1;
	s32 temp_s0;
	s32 sp3C;
	s32 temp_v0_3;
	s32 temp_v0_4;
	s32 charIndex;

	s32 sp2C;

	s32 i;
	s32 i2;

	player_getCoords(self, sp4C);
	func_800EC0EC(sp4C, self->unkC->unk0);
	baflag_clear(self, BA_FLAG_8);
	if (!self->unkC->unk0->unk28_9 || func_80091E80(self, 8) == 0)
	{
		return;
	}

	if (func_800EA068(0x20) == 0)
	{
		if (func_8008DAA8(self) == 0)
		{
			charIndex = character_getActiveIndex();
			switch (character_getTransform(charIndex))
			{
			case TRANSFORM_9_FIRSTPERSON:
			{
				break;
			}
			case TRANSFORM_11_CLOCKWORK:
			{
				if (func_800F6D24(charIndex) != 0)
				{
					return;
				}
				break;
			}
			case TRANSFORM_B_KAZOOIE:
			{
				if (bs_getSplitStatus() == SPLIT_STATE_TALON_TORPEDO)
				{
					if (func_800F6D24(charIndex) != 0)
					{
						return;
					}
				}
				else
				{
					return;
				}
				break;
			}
			default:
				return;
			}
		}
	}
	else
	{
		temp_s0 = func_800EA068(8);
		sp3C = func_800EA068(0x4000);
		temp_v0_3 = baflag_isTrue(self, 0x3B);
		if ((temp_s0 != 0) && (sp3C != 0) && (temp_v0_3 != 0))
		{
			_bsfirstp_entrypoint_14(self);
		}
	}
	func_800CB840(1, self->unk184);
	for (i = 0; i < 3; i++)
	{
		temp_f0 = func_8009E138(self, i);
		if (temp_f0 != 0.0f)
		{
			D_80126D08[i] = temp_f0;
			func_8009E154(self, i, D_80126CE0[i]);
		}
		else
		{
			break;
		}
	}
	//Get Number of actors being touched
	temp_v0_4 = func_800CDBA8(self->unkC->unk0, D_80126CE0, D_80126D08, i);
	for (i2 = 0; i2 < temp_v0_4; i2++)
	{
		temp_a1 = func_800CDFA8(i2, &sp2C);
		self->unkC->unk18 = sp2C;
		//This has the Player touching stuff
		func_8008E530(self, temp_a1);
	}
	func_800CB870();
	self->unkC->unk18 = -1;
}

s32 func_8008E92C(PlayerState* arg0) {
	return arg0->unkC->unk18;
}
Unk80132ED0* func_8008E938(PlayerState* arg0)
{
	return arg0->unkC->unk0;
}

void func_8008E944(PlayerState* arg0)
{
	arg0->unkC->unk0->unk28_9 = 0;
}

void func_8008E95C(PlayerState* arg0)
{
	arg0->unkC->unk0->unk28_9 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E974.s")

void func_8008E9A0(PlayerState* arg0, s32 arg1)
{
	arg0->unkC->unk4 = arg1;
}

s32 func_8008E9AC(PlayerState* arg0) {
	return arg0->unkC->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9E4.s")

s32* func_8008ED70(void) {
	return &D_80117CAC;
}