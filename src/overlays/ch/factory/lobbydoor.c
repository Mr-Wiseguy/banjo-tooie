#include "common.h"

extern ActorData D_80800160_chfactorylobbydoor;
ActorData* chfactorylobbydoor_entrypoint_0()
{
    return &D_80800160_chfactorylobbydoor;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/lobbydoor/func_8080000C_chfactorylobbydoor.s")

void func_808000A8_chfactorylobbydoor(s32 arg0)
{
    func_808000D0_chfactorylobbydoor();
    _chdoor_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/lobbydoor/func_808000D0_chfactorylobbydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/lobbydoor/func_80800108_chfactorylobbydoor.s")
