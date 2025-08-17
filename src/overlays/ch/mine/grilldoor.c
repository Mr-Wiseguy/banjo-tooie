#include "ch/minegrilldoor.h"

extern u32 D_80800190_chminegrilldoor;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800000_chminegrilldoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800068_chminegrilldoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800144_chminegrilldoor.s")

void* chminegrilldoor_entrypoint_0(void) {
    return &D_80800190_chminegrilldoor;
}

