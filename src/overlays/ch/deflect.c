#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/deflect/func_80800000_chdeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/deflect/func_80800034_chdeflect.s")

extern ActorData D_80800090_chdeflect;
ActorData* chdeflect_entrypoint_0()
{
    return &D_80800090_chdeflect;
}
