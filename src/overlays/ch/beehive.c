#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800000_chbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800078_chbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_808000CC_chbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800180_chbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800268_chbeehive.s")

extern ActorData D_80800374_chbeehive;
ActorData* chbeehive_entrypoint_0()
{
    return &D_80800374_chbeehive;
}
