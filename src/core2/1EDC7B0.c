#include "core2/1EDC7B0.h"

void func_80102EC0(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80102EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80102F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80102F44.s")

s32 func_80102F74(Actor* arg0, s32 arg1)
{
	return func_80102FA0(actor_getActorData(arg0), arg1);
}

s32 func_80102FA0(ActorData* arg0, s32 arg1)
{
	s32 var_v0;
	s32 returnValue;

	if (arg1 & 0x80000000)
	{
		var_v0 = arg0->unk3Cw;
	}
	else
	{
		var_v0 = arg0->unk24w;
	}
	if (var_v0 & 0x7FFFFFFF & arg1)
	{
		returnValue = 1;
	}
	else
	{
		returnValue = 0;
	}
	return returnValue;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80102FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80102FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80103014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80103040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80103110.s")
