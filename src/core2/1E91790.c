#include "core2/1E91790.h"


extern s8 D_8011A668;
extern s8 D_801282C5;

void func_800B7EA0(s32 arg0, s32 arg1)
{
	s32 sp3C;
	s32 sp38;
	s32 sp34;

	func_800AF614(arg0, asset_load(arg1), 0, 0x100, 1, 2, 2, &sp38, &sp34);
	D_801282C0.unkA = sp38;
	D_801282C0.unkB = sp34;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B7F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B80D0.s")

void func_800B811C(GraphicsBuffers* arg0) {
	Gfx* temp_v1;

	temp_v1 = arg0->gfx;
	arg0->gfx++;
	temp_v1->words.w0 = 0xDE000000; temp_v1->words.w1 = (u32)(&D_8011A668 - 0x80000000);

	D_801282C0.unk5 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B81CC.s")

void graphics_resetTextParams(void)
{
	D_801282C0.alpha = D_801282C0.red = D_801282C0.green = D_801282C0.blue = 255;
	D_801282C0.pattern = 0;
	D_801282C0.unk7 = 0;
	D_801282C0.shaky = 0; //Shakiness
	D_801282C0.font = 0; //Font
	D_801282C0.size = 1.0f; //Size
}

//Set Text Transparency
void graphics_setTextAlpha(s32 Transparency)
{
	D_801282C0.alpha = Transparency;
}

//Set Text Font
void graphics_setTextFont(s32 Font)
{
	D_801282C0.font = Font;
}

//Set Text Shakiness
void graphics_setTextShaky(s32 shakiness)
{
	D_801282C0.shaky = shakiness;
}

void func_800B8CB0(s32 unk)
{
	D_801282C0.unk7 = unk;
}

void graphics_setTextColors(s8 arg0, s8 arg1, s8 arg2)
{
	D_801282C0.red = arg0;
	D_801282C0.green = arg1;
	D_801282C0.blue = arg2;
}

//Set Text Pattern
void graphics_setTextPattern(s32 pattern)
{
	D_801282C0.pattern = pattern -0xC24;
}

//Set Text Size
void graphics_setTextScale(f32 size)
{
	D_801282C0.size = size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8CFC.s")

void graphics_drawChar(GraphicsBuffers* arg0, s32 coordX, s32 coordY, char charToPrint)
{
	if (D_801282C0.unkC != 0)
	{
		D_801282C0.unk8 = 0;
		func_800B81CC(arg0, coordX, coordY, charToPrint);
	}

}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B9038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B90C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B90E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B9108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B9170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B956C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B97A4.s")
