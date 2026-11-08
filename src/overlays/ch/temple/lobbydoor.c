#include "common.h"

extern ActorData D_808003A0_chtemplelobbydoor;
ActorData* chtemplelobbydoor_entrypoint_0()
{
    return &D_808003A0_chtemplelobbydoor;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/lobbydoor/func_8080000C_chtemplelobbydoor.s")

void func_808000B4_chtemplelobbydoor(s32 arg0) 
{
}
void func_808000BC_chtemplelobbydoor(s32 arg0)
{
    func_808000E4_chtemplelobbydoor();
    _chdoor_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/lobbydoor/func_808000E4_chtemplelobbydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/lobbydoor/func_80800134_chtemplelobbydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/lobbydoor/func_80800248_chtemplelobbydoor.s")
