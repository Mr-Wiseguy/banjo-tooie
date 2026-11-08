#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800000_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_8080003C_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800128_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800224_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800314_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_808003C0_chblackeye.s")

void func_80800444_chblackeye(Actor* arg0) 
{
    if (actor_getAdditionalMem(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800478_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_8080061C_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800774_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800838_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800BC4_chblackeye.s")

extern ActorData D_8080104C_chblackeye;
ActorData* chblackeye_entrypoint_0()
{
    return &D_8080104C_chblackeye;
}
