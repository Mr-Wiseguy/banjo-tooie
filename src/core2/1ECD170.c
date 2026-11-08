#include "core2/1ECD170.h"

void player_destroy(PlayerState* self)
{
    func_80098E64(self);
    heap_free(self);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F38A8.s")

s32 func_800F3930(PlayerState* arg0, s32 arg1, s32 arg2)
{
    s32 sp24;

    sp24 = func_800F38A8(arg0, arg2);
    if (func_800F9184() != 0)
    {
        return 0;
    }
    if (func_800F6774(arg0->unk184) == 0)
    {
        return 0;
    }
    if (func_800F6CC8(arg0->unk184) != 0)
    {
        return 0;
    }
    if (func_8008EF3C(arg0, 0) == 0x13)
    {
        return 0;
    }
    if ((player_isStable(arg0) == 0) && (sp24 == 0))
    {
        return 0;
    }
    if (character_includedInTransformMask(arg0->unk184, ALLOW_CLOCKWORK | ALLOW_GOLDENGOLIATH) != 0)
    {
        return 0;
    }
    if (character_includedInTransformMask(arg0->unk184, arg1) == 0)
    {
        return 0;
    }
    if (baflag_isTrue(arg0, 0x3F) != 0) {
        return 0;
    }
    if (func_8009CA70(arg0, bs_getCurrentState(arg0), 0x20) != 0)
    {
        return 0;
    }
    if (func_800A9C98() != 0)
    {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3B90.s")

void player_getCoords_Dupe(PlayerState* self, f32* arg1)
{
    player_getCoords(self,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F40EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F424C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F43A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F44DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F452C.s")

void func_800F457C(PlayerState* arg0, s32 arg1)
{
	if (arg1 == 0) {
		func_8009CCA4(arg0);
		return;
	}
	func_8009CCFC(arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F45B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F45E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4648.s")

void func_800F468C(PlayerState* self)
{
    if ((self->unk17C != 0) && (self->unk180 == 0) && (func_800EA09C() == 2))
    {
        func_800991B0(self);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F46D8.s")
