#include "ch/honeycarrier.h"

extern u32 D_808003F4_chhoneycarrier;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeycarrier/func_80800000_chhoneycarrier.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeycarrier/func_808000C4_chhoneycarrier.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeycarrier/func_80800210_chhoneycarrier.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeycarrier/func_80800260_chhoneycarrier.s")

void func_80800380_chhoneycarrier(Actor* arg0,void* arg1)
{
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12)
    {
        func_80103110(arg0, 1);
    }
}

u32* chhoneycarrier_entrypoint_0(void)
{
    return &D_808003F4_chhoneycarrier;
}