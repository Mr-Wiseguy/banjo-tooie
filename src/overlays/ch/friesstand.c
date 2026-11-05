#include "ch/friesstand.h"

extern ActorData D_80800EC8_chfriesstand;
ActorData* chfriesstand_entrypoint_0()
{
    return &D_80800EC8_chfriesstand;
}
extern ActorData D_80800F10_chfriesstand;
ActorData* chfriesstand_entrypoint_1()
{
    return &D_80800F10_chfriesstand;
}
extern ActorData D_80800F58_chfriesstand;
ActorData* chfriesstand_entrypoint_2()
{
    return &D_80800F58_chfriesstand;
}
extern ActorData D_80800FA0_chfriesstand;
ActorData* chfriesstand_entrypoint_3()
{
    return &D_80800FA0_chfriesstand;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800030_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808000C4_chfriesstand.s")

void func_80800398_chfriesstand(Actor* arg0)
{
    func_80800970_chfriesstand(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808003B8_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808005F0_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800620_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808006D4_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800904_chfriesstand.s")

void func_80800970_chfriesstand(Actor* arg0) 
{
    if (actor_getAdditionalMem(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808009A4_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808009F0_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800AEC_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800BB0_chfriesstand.s")

void func_80800C34_chfriesstand(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800C3C_chfriesstand.s")

void func_80800CF0_chfriesstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_0A0_UNK);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800D1C_chfriesstand.s")
