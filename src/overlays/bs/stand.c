#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800000_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800018_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800038_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800274_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_5.s")

void bsstand_entrypoint_6(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_7.s")

void bsstand_entrypoint_8()
{
    func_80800038_bsstand();
}

void bsstand_entrypoint_9()
{
    _bsdrone_entrypoint_0();
}

void bsstand_entrypoint_10(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstand_entrypoint_11(s32 arg0)
{
    _bafpctrl_entrypoint_10(arg0,0);
    _bsdrone_entrypoint_2(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_12.s")
