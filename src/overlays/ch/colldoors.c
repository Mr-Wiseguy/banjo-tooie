#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/colldoors/func_80800000_chcolldoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/colldoors/func_808000B8_chcolldoors.s")

extern ActorData D_80800280_chcolldoors;
ActorData* chcolldoors_entrypoint_0()
{
    return &D_80800280_chcolldoors;
}
