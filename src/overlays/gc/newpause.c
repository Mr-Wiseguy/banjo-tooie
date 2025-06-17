#include "gc/newpause.h"
#include "gl/dbstring.h"
#include "fx/kern.h"
#include "core2/1E91790.h"
#include "core2/1EC2350.h"
#include "core2/1E99980.h"
#include "core2/1EABAC0.h"
#include "core2/1E2D890.h"
#include "core2/1E691A0.h"
#include "core2/1EA78C0.h"
#include "core2/1EA0690.h"
#include "core2/1EA9160.h"
#include "core2/1EAAD80.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/gcnewpause_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/gcnewpause_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/gcnewpause_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/gcnewpause_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800534_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/gcnewpause_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800A08_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800C54_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800CE4_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800DE0_gcnewpause.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gcnewpause/gcnewpause/func_80800E10_gcnewpause.s")
void func_80800E10_gcnewpause(PauseState* a0, u32 a1)
{
	func_8080105C_gcnewpause(0xC,0x7,a1,0x0);
	func_8008FBE0(a1);
	func_800CF7F4(a1);
	if (a1 != 0)
	{
		//Display the Jiggy Value
		func_800D2498(0xD6, func_800D035C(0x1),0);
		//Display Note Value
		func_800D2498(0xD0, func_800D035C(0x6),0);
	}
	else
	{
		func_800D284C(0xD6);
		func_800D284C(0xD0);
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800EA8_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800F2C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800FA8_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080105C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808011BC_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801248_gcnewpause.s")

//Draw Page Titles
void func_808012CC_gcnewpause(PauseState* a0, u32* a1)
{
	if (a0->unk1B != 0)
	{
		_fxkern_entrypoint_2();
		func_800B8CE0(0xC28);
		_fxkern_entrypoint_1(a1,a0->pageTitleOffset+0x20, _gldbstring_entrypoint_1(a0->textPointer, a0->data[1]));
	}
	return;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gcnewpause/gcnewpause/func_80801330_gcnewpause.s")
u8 func_80801330_gcnewpause(PauseState* a0, u32 a1,u32 a2)
{
	a0->unk1B = func_80801248_gcnewpause((&(a0->pageTitleOffset)), &(a0->unk1A), a2, a0);
	return a0->unk1B;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080136C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801410_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080152C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801580_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808015F8_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080162C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801660_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808016A4_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808016F0_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801718_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808017C8_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801844_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080190C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808019A4_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801AF8_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801BF0_gcnewpause.s")

//Get The Collected Moves for the Jamjars Fraction in the totals page
u32 func_80801C3C_gcnewpause(u32 a0)
{
	u32 MoveCount = 0;
	u32 index = 0;
	while (D_8080215C_gcnewpause[index].SubPageToShow != -1)
	{
		if (a0 == 0x0||D_8080215C_gcnewpause[index].SubPageToShow == a0)
		{
			if (func_800C6E38(D_8080215C_gcnewpause[index].AbilityId))
			{
				MoveCount++;
			}
		}
		index++;
	}
	return MoveCount;
}

void func_80801CCC_gcnewpause(PauseState* a0)
{
	a0->unk2A = 0;
	a0->unk2C = 0x1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801CDC_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801DA0_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801E08_gcnewpause.s")

//Is there any inventory items between a0 and a1
s32 func_80801E80_gcnewpause(s32 a0, s32 a1)
{
	s32 s0 = 0;
	for (s0 = a0; s0 < a0 + a1;s0++)
	{
		if (func_800D1A04(D_808020D8_gcnewpause[s0].ItemID) != 0)
		{
			return 0x1;
		}

	}
	return 0x0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gcnewpause/gcnewpause/func_80801EF0_gcnewpause.s")
void func_80801EF0_gcnewpause(u32 a0)
{
	func_80801E80_gcnewpause(0,0xC);
}

//Check if any Jinjo is collected
u32 func_80801F18_gcnewpause(u32 a0)
{
	u32 s0;
	for (s0 = 0; s0 < 9; s0++)
	{
		if (func_800D1338(s0) != 0)
		{
			return 0x1;
		}
	}
	return 0x0;
}
