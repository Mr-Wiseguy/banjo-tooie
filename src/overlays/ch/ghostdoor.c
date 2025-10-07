#include "ch/ghostdoor.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/chghostdoor_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/chghostdoor_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/func_80800018_chghostdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/func_808000F4_chghostdoor.s")

void func_80800190_chghostdoor(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_096_STATION_UNLOCKED_WW);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/func_808001BC_chghostdoor.s")
