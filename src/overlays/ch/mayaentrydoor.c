#include "ch/mayaentrydoor.h"

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayaentrydoor/func_80800000_chmayaentrydoor.s")
#else
void func_80800000_chmayaentrydoor(unkArg0* arg0) 
{
    s32 sp2C;
    /*
    if (func_800DA298(0x3D8) == 1 && func_800D035C(1) >= _sujiggy_entrypoint_2(0))
    {
        sp2C = -1;
        func_80101FDC(arg0, 4U);
        func_800DA544(0x392);
    }
    */
    
    if ((_glcutDll_entrypoint_19(0x67) == 0) && (_sujiggy_entrypoint_20(0) != 0))
    {
        func_800DA544(0x392);
    }
    //Check Cheat Active
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7A) == 0))
    {
        sp2C = -1;
        func_80101FDC(arg0, 4U);
    }
    else
    {
        sp2C = 0x392;
    }
    _chdoormake_entrypoint_3(arg0, 0, 0x42B40000, arg0->unk38 * 220.0f, 1, sp2C);
    _chdoormake_entrypoint_8(arg0, 0xD);
    _chdoormake_entrypoint_5(arg0, 0);
}
#endif

void* chmayaentrydoor_entrypoint_0(void) {
    return &D_808000E0_chmayaentrydoor;
}