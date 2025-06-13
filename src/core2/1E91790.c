#include "core2/1E91790.h"
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B7EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B7F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B80D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B811C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B81CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8C50.s")

/* Wasn't matching only diff was Registers being used were different
//Reset Text Parameters
void func_800B8C50(void)
{
	D_801282C0.data[2] = 0xFF;
	D_801282C0.data[1] = 0xFF;
	D_801282C0.data[0] = 0xFF;
	D_801282C0.data[3] = 0xFF;
	D_801282C0.data[9] = 0; //Color
	D_801282C0.data[7] = 0; 
	D_801282C0.data[4] = 0; //Shakiness
	D_801282C0.data[6] = 0; //Font
	D_801282C0.value = 1.0f; //Size
}
*/

//Set Text Transparency
void func_800B8C8C(s32 Transparency)
{
	D_801282C0.data[3] = Transparency;
}

//Set Text Font
void func_800B8C98(s32 Font)
{
	D_801282C0.data[6] = Font;
}

//Set Text Shakiness
void func_800B8CA4(s32 shakiness)
{
	D_801282C0.data[4] = shakiness;
}

void func_800B8CB0(s32 unk)
{
	D_801282C0.data[7] = unk;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8CBC.s")

void func_800B8CBC(s8 arg0, s8 arg1, s8 arg2)
{
	D_801282C0.data[0] = arg0;
	D_801282C0.data[1] = arg1;
	D_801282C0.data[2] = arg2;
}

//Set Text Color
void func_800B8CE0(s32 color)
{
	D_801282C0.data[9] = color-0xC24;
}

//Set Text Size
void func_800B8CF0(f32 size)
{
	D_801282D4 = size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8DEC.s")

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
