#include "core1/1E29B60.h"
#include "core1/1E36310.h"

extern s32 core1_BSS_END;
extern s32 core1_BSS_START;
extern s32 D_800459CC;
extern s32 D_8007E994;
extern f32 D_800416A0;
extern s32 D_80043384;
extern s32 D_80045788;

void func_80012030(s32 arg0) {
    bzero(&core1_BSS_START, (s32)&core1_BSS_END - (s32)&core1_BSS_START);
    osWritebackDCacheAll();
    osInitialize();
    func_80013620();
}

void func_8001207C(void) 
{
    func_800D5E74();
}

void func_8001209C(s32 arg0)
{
    func_8001A2B0();
    func_800155BC();
    if (D_80043380 == 1)
    {
        func_800A7B24();
    }
    func_8001207C();
    D_80043380 = arg0;
    if (D_80043380 == 1)
    {
        func_800A7BB8(D_800459CC);
    }
}

s32 func_8001210C(s32 arg0) {
    return D_800459C8 & arg0;
}

s32 func_8001211C(void) 
{
    return D_800459C8;
}

void func_80012128(void) {
    D_800459C8 = 0;
}

void func_80012134(void)
{
    func_8001253C(_cosection_entrypoint_1());
    func_80012520(1);
}

void func_80012164(void) {
    func_8001253C(_cosection_entrypoint_0());
    func_80012520(1);
}

s32 func_80012194(void)
{
    return D_8007E994 - (s32)&core2_VRAM_END;
}

s32 func_800121AC(void) {
    return (core2_VRAM_END - (s32)&func_80012030) + 0xFFF21DD0;
}

void func_800121D0(void)
{
    s32 sp1C;
    s32 var_v1;
    sp1C = func_80012194();
    if (0) {}
    var_v1 = func_8001E830() + sp1C;
    while (var_v1 & 0xF)
    {
        var_v1 -= 1;
    }

}

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

void func_800123BC(void) 
{
    if (func_800A7D84() != 0)
    {
        func_800A7840(0);
    }
    func_800A5D1C();
}

//Main Loop Contents
void func_800123F4()
{
    func_8001207C();
    if ((D_80043380 != 1) || (func_800A8184() != 4))
    {
        D_800459C8 += 1;
    }
    if (func_80012530() == 1)
    {
        func_800A7D30();
    }
    func_8001608C();
    func_80018444();
    
    if (D_80043380 == 1)
    {
        //
        func_800123BC();
    }
    func_8008160C(1);
    func_8001E010();
    if (func_800D9004() <= D_800416A0)
    {
        do_crc_check();
    }
    if (D_80043384 != 0)
    {
        func_8001209C(D_80043384 - 1);
        D_80043384 = 0;
    }
}

void func_800124EC(s32 param_0)
{
    func_80012214();
    while (1)
    {
        //Main Loop
        func_800123F4();
    }

}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012520.s")

s32 func_80012530()
{
    return D_80043380;
}

void func_8001253C(s32 arg0) {
    D_800459CC = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012548.s")

s32* func_80012598(void) { //matched by Zenpock
    return &D_80045788;
}

