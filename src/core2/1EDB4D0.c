#include "core2/1EDB4D0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101F64.s")

void func_80101FDC(Actor* arg0, u32 arg1)
{
    s32 sp1C;
    AnimCtrl* temp_v0;

    sp1C = func_80101F64();
    if (func_80101BE0(arg0, arg1) != 0)
    {
        temp_v0 = func_80104248(arg0);
        if ((temp_v0 != NULL) && (sp1C != 0))
        {
            anctrl_start(temp_v0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_8010203C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801020A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801020DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801021BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801022E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102320.s")

Unk80132ED0* func_80102394(Actor* arg0)
{
    if (arg0->unk79_3)
    {
        event_sendToActor(arg0, 0x99, 0);
        return func_80101080();
    }
    return actor_getActorData(arg0)->unk8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801023E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_8010262C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801026CC.s")
