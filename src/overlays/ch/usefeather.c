#include "ch/usefeather.h"

extern ActorData D_80800364_chusefeather;
extern ActorData D_808003AC_chusefeather;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/func_80800000_chusefeather.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/chusefeather_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/chusefeather_entrypoint_1.s")

ActorData* chusefeather_entrypoint_2()
{
    return &D_80800364_chusefeather;
}

ActorData* chusefeather_entrypoint_3()
{
    return &D_808003AC_chusefeather;
}
