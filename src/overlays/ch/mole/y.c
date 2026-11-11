#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800000_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_808000AC_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800190_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800274_chmoley.s")

void func_8080088C_chmoley(Actor* arg0) 
{
    if (actor_getAdditionalMem(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_808008C0_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/chmoley_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/chmoley_entrypoint_1.s")

extern ActorData D_80800C10_chmoley;
ActorData* chmoley_entrypoint_2()
{
    return &D_80800C10_chmoley;
}
