#include "ch/mole.h"

extern MoveData D_808001E0_chmole_maya[];
extern D_808000D0 D_80800210_chmole_maya;

void func_80800000_chmole_maya(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808001E0_chmole_maya);
}

void func_80800024_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808001E0_chmole_maya);
}

void* chmole_maya_entrypoint_0()
{
	return &D_80800210_chmole_maya;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_maya/func_808000C0_chmole_maya.s")

void func_80800144_chmole_maya(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_maya/func_8080014C_chmole_maya.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_maya/func_80800180_chmole_maya.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_maya/chmole_maya_entrypoint_1.s")
