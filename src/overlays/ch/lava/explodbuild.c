#include "ch/lavaexplodbuild.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/explodbuild/func_80800000_chlavaexplodbuild.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/explodbuild/func_80800048_chlavaexplodbuild.s")

void func_80800084_chlavaexplodbuild(s32 arg0)
{
    flag_setValueFalse(FLAG3_A24_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/explodbuild/func_808000A8_chlavaexplodbuild.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/explodbuild/func_80800138_chlavaexplodbuild.s")

extern ActorData D_808002E0_chlavaexplodbuild;
ActorData* chlavaexplodbuild_entrypoint_0()
{
    return &D_808002E0_chlavaexplodbuild;
}
