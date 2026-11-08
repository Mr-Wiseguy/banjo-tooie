#include "core2/1E96E60.h"

extern s32 D_80128410[];
extern s32 D_80128434;
extern f32 D_80128450;

void func_800BD570()
{
    _gccubeDll_entrypoint_1(&D_80128410);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD594.s")

void func_800BD5DC()
{
    _gccubeDll_entrypoint_2(&D_80128410);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD948.s")

s32 func_800BD97C(s32* arg0)
{
	s32 sp3C[3];
	s32 sp30[3];
	s32 i;
	for (i = 0; i < 3; i++) 
	{
		if (arg0[i] >= 0)
		{
			sp3C[i] = (s32)(arg0[i] * D_80128450);
		}
		else
		{
			sp3C[i] = (s32)((arg0[i] * D_80128450) + -1.0f);
		}
	}
	if ((sp3C[0] < D_80128410[1]) || (sp3C[1] < D_80128410[2]) || (sp3C[2] < D_80128410[3]) || (D_80128410[4] < sp3C[0]) || (D_80128410[5] < sp3C[1]) || (D_80128410[6] < sp3C[2]))
	{
		return -1;
	}
	ml_getdiff_vec3i(sp30, sp3C, &D_80128410[1]);
	return sp30[0] + (sp30[1] * D_80128410[7]) + (sp30[2] * D_80128410[8]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDAD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDB9C.s")

void func_800BDBC4(s32* arg0)
{
    func_800BDB9C(func_800BD97C(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDC44.s")

s32 func_800BDC50()
{
    return D_80128434;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDC90.s")

void func_800BDCB8()
{
    _gccubeDll_entrypoint_0(&D_80128410);
}

void func_800BDCDC()
{
    _gccubeDll_entrypoint_5(&D_80128410);
}

void func_800BDD00()
{
    _gccubeDll_entrypoint_6(&D_80128410);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDD24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE52C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE58C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE5C4.s")
