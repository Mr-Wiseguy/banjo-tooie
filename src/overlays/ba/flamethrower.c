#include "ba/flamethrower.h"

s32 baflamethrower_entrypoint_0(void) 
{
    return 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/func_80800008_baflamethrower.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/func_80800088_baflamethrower.s")

void baflamethrower_entrypoint_1(PlayerState* self)
{
    func_80800088_baflamethrower(self, 0);
    _baflameline_entrypoint_2(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/baflamethrower_entrypoint_2.s")

void baflamethrower_entrypoint_3(PlayerState* self)
{
    func_80800088_baflamethrower(self, 0x2);
}

void baflamethrower_entrypoint_4(PlayerState* self)
{
    func_80800088_baflamethrower(self, 0x3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/baflamethrower_entrypoint_5.s")
