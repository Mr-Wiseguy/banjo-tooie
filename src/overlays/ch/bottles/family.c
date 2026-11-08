#include "ch/bottles/family.h"

void func_80800520_chbottlesfamily(Actor*);
void func_80800BC0_chbottlesfamily(Actor*);

extern ActorData D_80800DE0_chbottlesfamily;
ActorData* chbottlesfamily_entrypoint_0()
{
    return &D_80800DE0_chbottlesfamily;
}
extern ActorData D_80800E28_chbottlesfamily;
ActorData* chbottlesfamily_entrypoint_1()
{
    return &D_80800E28_chbottlesfamily;
}
extern ActorData D_80800E70_chbottlesfamily;
ActorData* chbottlesfamily_entrypoint_2()
{
    return &D_80800E70_chbottlesfamily;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800024_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800080_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800124_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_808001B0_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_8080046C_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_808004B4_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800520_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_808005D0_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800600_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800630_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800720_chbottlesfamily.s")

void func_8080086C_chbottlesfamily(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_8080088C_chbottlesfamily(Actor* arg0, s32 arg1, s32 arg2)
{
	switch (arg1)
	{
	case 0x1503:
		func_80800BC0_chbottlesfamily(arg0);
		func_8009032C(ABILITY_2B_AMAZE_O_GAZE_GOGGLES); //Give Amaze O Gaze
		func_800FC6B0(0xEU);
		break;

	case 0x1501:
		func_80800BC0_chbottlesfamily(arg0);
		_glcutDll_entrypoint_6(0x142U, 0x66U);
		break;

	default:
		if (arg0->unk6C_0)
		{
			func_80800BC0_chbottlesfamily(arg0);
		}
		break;
	}
	if ((u32)(arg0->unk6C_9) == 0x43C)
	{
		if (rand_percentChance(0.5f) != 0)
		{
			func_80800520_chbottlesfamily(arg0);
			return;
		}
		func_80101FDC(arg0, 1U);
		arg0->unk58 = rand_fBounded(5.0f, 10.0f) * 0.5f;
		return;
	}
	func_80101FDC(arg0, 1U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_8080099C_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_808009F0_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800A44_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800A84_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800B64_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800BC0_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800C08_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800CA4_chbottlesfamily.s")
