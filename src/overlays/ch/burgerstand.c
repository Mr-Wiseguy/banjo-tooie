#include "ch/burgerstand.h"

extern ActorData D_80800C28_chburgerstand;
ActorData* chburgerstand_entrypoint_0()
{
    return &D_80800C28_chburgerstand;
}
extern ActorData D_80800C70_chburgerstand;
ActorData* chburgerstand_entrypoint_1()
{
    return &D_80800C70_chburgerstand;
}
extern ActorData D_80800CB8_chburgerstand;
ActorData* chburgerstand_entrypoint_2()
{
    return &D_80800CB8_chburgerstand;
}
extern ActorData D_80800D00_chburgerstand;
ActorData* chburgerstand_entrypoint_3()
{
    return &D_80800D00_chburgerstand;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_80800030_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808000C4_chburgerstand.s")

void func_80800284_chburgerstand(Actor* arg0)
{
    func_80800720_chburgerstand(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808002A4_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808004DC_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808005AC_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808006B4_chburgerstand.s")

void func_80800720_chburgerstand(Actor* arg0) 
{
    if (actor_getAdditionalMem(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_80800754_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808007A0_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_8080087C_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_80800940_chburgerstand.s")

void func_808009C4_chburgerstand(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808009CC_chburgerstand.s")

void func_80800A8C_chburgerstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_09F_UNK);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_80800AB8_chburgerstand.s")
