#include "ch/inflatablebossdoor.h"

extern s32 D_80800140_chinflatablebossdoor;

s32* chinflatablebossdoor_entrypoint_0(void)
{
    return &D_80800140_chinflatablebossdoor;
}

void func_8080000C_chinflatablebossdoor(Actor* arg0)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = func_800DA298(FLAG_17F_RETRY_BOSS_MR_PATCH);
    sp30 = func_800F64A4(func_800F54E4(), 1);
    sp2C = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_80101FDC(arg0, 1U);
    }
    else if ((sp34 == 0) && (sp2C != 0))
    {
        func_80101FDC(arg0, 4U);
    }
    else if ((sp34 != 0) && (sp30 != 0))
    {
        func_80101FDC(arg0, 1U);
    }
    func_80102FDC(arg0, arg0->scale * 1.4f);
    func_8010A800(arg0, 0);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 600.0f, 0x822, 0x9C) != 0)
    {
        _chdoormake_entrypoint_5(arg0, 4.0f);
        _chdoormake_entrypoint_6(arg0, 0x3F4CCCCD);
    }
}