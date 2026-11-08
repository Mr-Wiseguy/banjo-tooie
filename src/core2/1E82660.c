#include "core2/1E82660.h"



typedef struct {
	s16 unk0;
	s16 unk2;
	u8 unk4[4];
	s16 unk8[8];
	s32 unk18[8];
	f32* unk38[8];
	s32 unk58[8];
}UNKD_801276D0;
extern s16 D_80127750;
extern s16 D_80127752;
extern s32 D_80127754;
extern UNKD_801276D0 D_801276D0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8D70.s")

void func_800A8E9C(void)
{
	s32 i;
	s32 temp_a0;

	for (i = 0; i < 8; i++) {
		temp_a0 = D_801276D0.unk58[i];
		if (temp_a0 != 0) {
			func_8010FC38(temp_a0);
		}
	}
}
void func_800A8EF0(s32 arg0, s32 arg1)
{
	s32 var_s0;
	for (var_s0 = 0; var_s0 < 8; var_s0++)
	{
		if ((D_801276D0.unk58[var_s0] != 0) && (arg1 == D_801276D0.unk18[var_s0]))
		{
			func_8010FAEC(arg0, D_801276D0.unk58[var_s0]);
		}
	}
}

void func_800A8F68(void)
{
	s32 var_s0;
	for (var_s0 = 0; var_s0 < 8; var_s0++)
	{
		func_800A91F4(var_s0);
	}
	while (D_801276D0.unk2 != 0)
	{
		func_800A87FC(D_801276D0.unk2 - 1);
		D_801276D0.unk2 -= 1;
	}
}

s32 func_800A8FDC(void)
{
	func_800A877C(D_801276D0.unk2);
	return D_801276D0.unk2++;
}

s32 func_800A9010(void)
{
	s32 index;
	for (index = 0; index < 4; index++)
	{
		if (D_801276D0.unk4[index] == 0)
		{
			return index;
		}
	}
	return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A907C.s")

void func_800A91A8(s32 charIndex)
{
	s16 temp_a0;

	if (charIndex >= 0) {
		temp_a0 = D_801276D0.unk8[charIndex];
		if (temp_a0 != -1) {
			func_800A88C4(temp_a0, D_801276D0.unk38[charIndex], charIndex);
		}
	}
}

void func_800A91F4(s32 charIndex)
{
	if (charIndex >= 0)
	{
		if (D_801276D0.unk8[charIndex] != -1)
		{
			func_8010FBD4(D_801276D0.unk58[charIndex]);
			D_801276D0.unk58[charIndex] = 0;

			if (func_800A8984(D_801276D0.unk8[charIndex]) == D_801276D0.unk38[charIndex])
			{
				func_800A8948(D_801276D0.unk8[charIndex]);
			}
			func_800CA364(D_801276D0.unk38[charIndex]);
			D_801276D0.unk38[charIndex] = NULL;
			D_801276D0.unk4[D_801276D0.unk8[charIndex]]--;
			D_801276D0.unk8[charIndex] = -1;
			D_801276D0.unk0--;
		}
	}
}


void func_800A92A8(s32 arg0, s32 arg1)
{
	s32 i;
	s32 temp_a0;

	for (i = 0; i < 8; i++)
	{
		temp_a0 = D_801276D0.unk58[i];
		if (temp_a0 != 0)
		{
			func_8010FE00(temp_a0, arg0, arg1);
		}
	}
}

void func_800A9318(s32 arg0)
{
	s32 i;
	s32 temp_a0;

	for (i = 0; i < 8; i++)
	{
		temp_a0 = D_801276D0.unk58[i];
		if (temp_a0 != 0)
		{
			func_8010FE34(temp_a0, arg0);
		}
	}
}

void func_800A9378(void)
{
	s32 i;

	for (i = 0; i < 8; i++)
	{
		if (D_801276D0.unk58[i] != 0 && func_800A9420(i) != 0)
		{
			func_80110164(D_801276D0.unk58[i]);
		}
	}
}
s32 func_800A93E4(s32 arg0)
{
    return D_801276D0.unk58[arg0];
}

f32* func_800A93F8(s32 arg0)
{
	return D_801276D0.unk38[arg0];
}

s32 func_800A940C(s32 arg0)
{
	return D_801276D0.unk18[arg0];
}

s32 func_800A9420(s32 arg0)
{
	return D_801276D0.unk38[arg0] == func_800A8984(D_801276D0.unk18[arg0]);
}

s32 func_800A9460(void) {
	return D_801276D0.unk0;
}

s32 func_800A946C(void) {
	return D_801276D0.unk2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A95C4.s")

s32 func_800A965C(void) {
	return 4 - D_801276D0.unk2;
}

s32 func_800A9670(s32* arg0) {
	s32 index;
	s32 count = 0;
	for (index = 0; index < 4; index++)
	{
		if (D_801276D0.unk4[index] == 0)
		{
			arg0[count] = index;
			count++;
		}
	}
	return count;
}

s32 func_800A96F0(s32 arg0)
{
	s32 var_s0;
	for (var_s0 = 0; var_s0 < 8; var_s0++)
	{
		if (arg0 == D_801276D0.unk8[var_s0])
		{
			return var_s0;
		}
	}
	return -1;
}

s32 func_800A9768(s32 arg0)
{
	s32 index;
	for (index = 0; index < 8; index++)
	{
		if (arg0 == D_801276D0.unk8[index])
		{
			return D_801276D0.unk18[index];
		}
	}
	return -1;
}

void func_800A9800(void)
{
	func_800A9828(0, 0, 0);
}

void func_800A9828(s32 arg0, s32 arg1, s32 arg2) 
{
    D_80127754 = arg0;
    if (arg1 != 0) 
    {
        D_80127750 = (s16) arg1;
    } 
    else 
    {
        D_80127750 = 0x130;
    }
    if (arg2 != 0) 
    {
        D_80127752 = (s16) arg2;
    } 
    else 
    {
        D_80127752 = 0xE4;
    }
    func_800E7F60();
    func_800A8D00(D_80127750, D_80127752);
}

s32 func_800A989C(void)
{
	s32 var_v0;


	if (D_80127754 != 0)
	{
		var_v0 = D_80127754;
	}
	else
	{
		var_v0 = func_80014F00();

	}
	return var_v0;
}