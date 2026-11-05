#include "ch/boggy/girl.h"

extern ActorData D_80800CF0_chboggygirl;
ActorData* chboggygirl_entrypoint_0()
{
    return &D_80800CF0_chboggygirl;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_8080000C_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_808000A8_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800508_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800708_chboggygirl.s")

void func_8080091C_chboggygirl(Actor* arg0)
{
    func_80800B28_chboggygirl(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_8080093C_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_8080097C_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800A4C_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800ABC_chboggygirl.s")

void func_80800B28_chboggygirl(Actor* arg0) 
{
    if (actor_getAdditionalMem(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800B5C_chboggygirl.s")
