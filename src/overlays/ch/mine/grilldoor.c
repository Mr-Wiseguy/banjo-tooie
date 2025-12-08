#include "ch/minegrilldoor.h"

extern ActorData D_80800190_chminegrilldoor;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800000_chminegrilldoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800068_chminegrilldoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800144_chminegrilldoor.s")

ActorData* chminegrilldoor_entrypoint_0(void) {
    return &D_80800190_chminegrilldoor;
}

