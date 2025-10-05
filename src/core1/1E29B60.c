#include "core1/1E29B60.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012030.s")

void func_8001207C(void) 
{
    func_800D5E74();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001209C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001210C.s")

s32 func_8001211C(void) 
{
    return D_800459C8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800121AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800121D0.s")

// Needs migration
#if 0
void func_80012214(void) {
    D_800459D0 = osGetMemSize();
    func_8001DDF0(); // start_cic_thread
    init_crc_check();
    func_80014FE8(); // start_vi_thread
    func_8001E7E8();
    func_8001C1C0();
    func_80019EC0(0, core2_VRAM, core2_VRAM_END, core2_ROM_START, core2_ROM_END, core2_TEXT_START, core2_TEXT_END, core2_RODATA_START, core2_DATA_END, core2_BSS_START, core2_BSS_END);
    heap_setup(TRUE);
    func_80014E6C();
    D_80043388.unk400 = 0x01020304;
    D_80043388.unk404 = 0x05060708;
    D_800459D8 = 0x0102030405060708ULL;
    func_801168F0();
    func_800815CC();
    func_8001A080();
    func_8001A2D0();
    func_800121D0();
    func_80016734();
    func_800184E8();
    func_800125B0();
    func_8001A3A0();
    func_800D66AC();
    func_800D5D70();
    func_800E692C();
    _gcstatusDll_entrypoint_0();
    func_800C929C();
    D_80043380 = 0;
    D_800459C8 = 0;
    func_800A5BE0();
    _cosection_entrypoint_1();
    func_8001253C(func_80087890());
    func_8001209C(1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012214.s")
#endif

s32 func_800123B0()
{
    return D_800459D0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800123BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800123F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800124EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012520.s")

s32 func_80012530()
{
    return D_80043380;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001253C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012598.s")
