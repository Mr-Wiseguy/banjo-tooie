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
#include "core2/1EAF950.h"
#include "core2/1EB5E70.h"
#include "core2/1EB2840.h"
#include "core2/1EB45C0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/gcnewpause_entrypoint_0.s")

//Close and Free Pause Menu
void gcnewpause_entrypoint_1(PauseState* a0)
{
	func_80800534_gcnewpause(a0,0x4);
	heap_free(a0);
}

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
		_fxkern_entrypoint_1(a1,a0->pageTitleOffset+0x20, _gldbstring_entrypoint_1(a0->textPointer, a0->SubPage));
	}
	return;
}

u8 func_80801330_gcnewpause(PauseState* a0, u32 a1,u32 a2)
{
	a0->unk1B = func_80801248_gcnewpause((&(a0->pageTitleOffset)), &(a0->unk1A), a2, a0);
	return a0->unk1B;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080136C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801410_gcnewpause.s")

void func_8080152C_gcnewpause(PauseState* a0)
{
	if (a0->unk1C != 0)
	{
		func_800E8C08(a0->unk1C);
		a0->unk1C = 0;
	}
	if (a0->unk1D != 0)
	{
		func_800E8C08(a0->unk1D);
		a0->unk1D = 0;

	}
}

void func_80801580_gcnewpause(PauseState* a0)
{
	s32 a2; 
	if (a0->unk3 != 0 || a0->unk7 != 0)
    {
        a2 = 1;
    }
    else
    {
        a2 = 0;
    }
	func_80801248_gcnewpause(&(a0->unk28), &(a0->unk22), a2,a0);
	func_80801248_gcnewpause(&(a0->unk24), &(a0->unk20), a0->unk1E, a0);
	func_80801248_gcnewpause(&(a0->unk26), &(a0->unk21), a0->unk1F, a0);
}

void func_808015F8_gcnewpause(PauseState* a0, u32 a1)
{
	a0->unk4 = a1;
	a0->unk3 = -1;
	a0->unkF = 0x0;
	_gcaudiolist_entrypoint_1(0x3, 0x4650);
}

void func_8080162C_gcnewpause(PauseState* a0,u32 a1)
{
	a0->unk7 = a1;
	a0->unk3 = -1;
	a0->unkF = 0x0;
	_gcaudiolist_entrypoint_1(0x3, 0x4650);
}

//Setup the File for the Page titles
void func_80801660_gcnewpause(PauseState* a0)
{
	a0->textPointer=_gldbstring_entrypoint_0(a0->textPointer, 0x1864);
	a0->pageTitleOffset = -a0->unk6;
	a0->unk1A = 0;
}

//Get the level for the subpage
s32 func_808016A4_gcnewpause(s32 a0)
{
	u32 index;
	for (index=0;D_808020A8_gcnewpause[index].unk1 != 0; index++)
	{
		if (D_808020A8_gcnewpause[index].SubPage == a0)
		{
			break;
		}
	}
	return D_808020A8_gcnewpause[index].unk1;
}
//Can See Totals Page For a Given Level
s32 func_808016F0_gcnewpause(s32 a0)
{
	return _gclevel_entrypoint_3(func_808016A4_gcnewpause(a0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801718_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808017C8_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801844_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_8080190C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_808019A4_gcnewpause.s")

//Show Game Total Values
s32 func_80801AF8_gcnewpause(u32 arg0) 
{
	s16 var_a0;
	s32 temp_v0_2;
	s32 var_s3;
	u32 temp_v0;
	u32 index = 0;

	var_s3 = 0;
	var_a0 = D_80802130_gcnewpause[index].itemType;
	while (D_80802130_gcnewpause[index].itemType != -1)
	{
		temp_v0 = func_800D035C(D_80802130_gcnewpause[index].itemType);

		if (temp_v0 != 0 && (func_8080190C_gcnewpause(temp_v0, D_80802130_gcnewpause[index].uiPosition, D_80802130_gcnewpause[index].itemIcon, 5U, (s32)arg0) != 0))
		{
			var_s3 = 1;
		}
		var_a0 = D_80802130_gcnewpause[index].itemType;
		index++;
	}
	if (func_8080190C_gcnewpause(func_800DAD10(), 0x22, 0x1B, 4U, (s32)arg0) != 0)
	{
		var_s3 = 1;
	}
	temp_v0_2 = func_80801C3C_gcnewpause(0);
	if ((temp_v0_2 != 0) && (func_8080190C_gcnewpause((u32)temp_v0_2, 0x21, 0x1E, 5U, (s32)arg0) != 0))
	{
		var_s3 = 1;
	}
	return var_s3;
}

//Get The Max Amount of Moves for a page
u32 func_80801BF0_gcnewpause(u32 a0)
{
	u32 MoveCount = 0;
	u32 index = 0;
	while (D_8080215C_gcnewpause[index].SubPageToShow != -1)
	{
		if (a0 == 0x0 || D_8080215C_gcnewpause[index].SubPageToShow == a0)
		{
			MoveCount++;
		}
		index++;
	}
	return MoveCount;
}

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

//Handle the Fade in/out speed of the gameover text
void func_80801CDC_gcnewpause(PauseState* a0)
{
	f32 speed = func_800D8FF8();
	s16 temp_v0;
	if (a0->unk2C != 0) {
		temp_v0 = a0->unk2A;
		if (temp_v0 < 0xFF) {
			a0->unk2A = temp_v0 + (speed * 200.0f);
		}
		temp_v0 = a0->unk2A;
		if (temp_v0 >= 0x100) {
			a0->unk2A = 0xFF;
		}
	}
	else {
		temp_v0 = a0->unk2A;
		if (temp_v0 > 0) {
			a0->unk2A = temp_v0 - (speed * 200.0f);
		}
		temp_v0 = a0->unk2A;
		if (temp_v0 < 0) {
			a0->unk2A = 0;
		}
	}
}

//Draw Gameover Text
void func_80801DA0_gcnewpause(PauseState* a0,u32 a1)
{
	f32 coord[2];
	coord[0] = 152.0f;
	coord[1] = 171.0f;

	func_800DF410(a0->unk2A);
	func_800DF944(a1, coord, 0, 0.25f, 0,1, func_800D674C(0x640));
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gcnewpause/gcnewpause/func_80801E08_gcnewpause.s")
void func_80801E08_gcnewpause(PauseState* a0, OptionState* a1)
{
	a0->unkE = a0->unkE + 1;

	if (a0->unkE >= a0->unk12) {
		a0->unkE = a0->unk10;
	}

	_gcnewoption_entrypoint_12(a1, a0->unk5, a0->unkE, a0);
	a0->unk8 = 1.5f;
}

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
