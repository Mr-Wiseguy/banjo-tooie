#include "common.h"

s32 baeggaim_entrypoint_0() 
{
    return 0x4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/func_80800008_baeggaim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/func_808000B4_baeggaim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/func_80800170_baeggaim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/func_80800264_baeggaim.s")

void baeggaim_entrypoint_1(s32 arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x4);
    _baeggfire_entrypoint_4(arg0);
}

void baeggaim_entrypoint_2(s32 arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x3);
    _baeggfire_entrypoint_5(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/baeggaim_entrypoint_3.s")
