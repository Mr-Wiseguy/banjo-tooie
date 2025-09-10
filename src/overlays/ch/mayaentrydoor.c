#include "ch/mayaentrydoor.h"

extern u32 D_808000E0_chmayaentrydoor;

void func_80800000_chmayaentrydoor(Unk80800000MayaEntryDoor* arg0)
{
    s32 sp2C;
    if ((_glcutDll_entrypoint_19(0x67) == 0) && (_sujiggy_entrypoint_20(0) != 0))
    {
        func_800DA544(FLAG_392_PROGRESS_OPENED_WORLD_MT);
    }
    
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7A) == 0))
    {
        sp2C = -1;
        func_80101FDC(arg0, 4U);
    }
    else
    {
        sp2C = 0x392;
    }
    _chdoormake_entrypoint_3(arg0, 0, 90.0f, arg0->unk38 * 220.0f, 1, sp2C);
    _chdoormake_entrypoint_8(arg0, 0xD);
    _chdoormake_entrypoint_5(arg0, 0);
}

void* chmayaentrydoor_entrypoint_0(void) {
    return &D_808000E0_chmayaentrydoor;
}