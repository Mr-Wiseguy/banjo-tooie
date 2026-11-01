#include "core2/1EADCF0.h"

void func_800D4400(ba_unknown_94_s* arg0, f32* arg1, f32* arg2)
{
	f32 sp2C[3];
	f32 sp28;
	f32 temp_f0;
	u8 temp_v0;

	func_800D4D5C(arg1, arg0);
	sp28 = func_800C6784(arg0->unk0);
	func_800C675C(arg0->unk0, sp2C);
	temp_v0 = arg0->unk56;
	arg0->unk56 = 0;
	if (!(sp2C[1] < 0.432f))
	{
		temp_f0 = arg1[1];
		if (temp_f0 <= sp28)
		{
			arg1[1] = sp28;
			arg0->unk56 = 1;
			return;
		}
		if ((temp_v0 != 0) && (arg2[1] < 0.0f))
		{
			if (sp2C[1] < 0.9f)
			{
				if (temp_f0 < (sp28 + 30.0f))
				{
					arg1[1] = sp28;
					arg0->unk56 = 1;
				}
			}
			else if (temp_f0 < (sp28 + 5.0f))
			{
				arg1[1] = sp28;
				arg0->unk56 = 1;
			}
		}
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4534.s")

void func_800D4564()
{
    func_800AAD28();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4D5C.s")
