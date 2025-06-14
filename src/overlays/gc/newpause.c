#include "gc/newpause.h"
#include "gc/newoption.h"
#include "gl/dbstring.h"
#include "fx/kern.h"
#include "core2/1E91790.h"

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80800E10_gcnewpause.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801C3C_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801CCC_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801CDC_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801DA0_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801E08_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801E80_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801EF0_gcnewpause.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newpause/func_80801F18_gcnewpause.s")
