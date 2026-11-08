#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_80800000_chwallsnakebaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_8080027C_chwallsnakebaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_808004FC_chwallsnakebaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_808005D8_chwallsnakebaddy.s")

void func_80800650_chwallsnakebaddy()
{
    func_80105010();
}

extern ActorData D_808007B4_chwallsnakebaddy;
ActorData* chwallsnakebaddy_entrypoint_0()
{
    return &D_808007B4_chwallsnakebaddy;
}
