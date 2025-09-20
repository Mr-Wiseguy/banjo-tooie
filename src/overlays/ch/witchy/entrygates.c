#include "ch/witchyentrygates.h"

extern u32 D_808001F0_chwitchyentrygates;

void func_80800000_chwitchyentrygates(Actor* arg0)
{
    f32 var_f0;
    s32 var_a3;
    if (_sujiggy_entrypoint_20(2U) != 0)
    {
        func_800DA544(FLAG_394_PROGRESS_OPENED_WORLD_WW);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7CU) == 0))
    {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    }
    else
    {
        var_a3 = 0x394;
    }
    if (arg0->unk74_7 == 0x33)
    {
        var_f0 = 75.0f;
    }
    else
    {
        var_f0 = -75.0f;
    }
    _chdoormake_entrypoint_0(arg0, var_f0, 0, var_a3);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/witchy/entrygates/func_808000B8_chwitchyentrygates.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/witchy/entrygates/func_80800168_chwitchyentrygates.s")

void* chwitchyentrygates_entrypoint_0(void) {
    return &D_808001F0_chwitchyentrygates;
}
