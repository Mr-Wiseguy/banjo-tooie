#include <ultra64.h>
#include "common.h"

void func_8001209C(s32);
void func_800121D0();
void func_8001253C(s32);
void func_800125B0();
void func_80014E6C();
void func_80014FE8();
void func_80016734();
void func_800184E8();
void func_8001A080();
void func_8001A2D0();
void func_8001A3A0();
void heap_setup(s32);
void func_8001C1C0();
void func_8001DDF0();
void func_8001E7E8();
void init_crc_check();
void func_800815CC();
s32 _cosection_entrypoint_1();
void _gcstatusDll_entrypoint_0();
void func_800A5BE0();
void func_800C929C();
void func_800D5D70();
void func_800D66AC();
void func_800D740C();
void func_800E692C();
void func_801168F0();

extern s32 D_80043380;
extern struct {
    u8 pad[0x400];
    s32 unk400;
    s32 unk404;
} D_80043388;
extern s32 D_800459C8;
extern s32 D_800459D0;
extern u64 D_800459D8;
extern u8 core2_VRAM[]; // core2 start
extern u8 core2_VRAM_END[]; // core2 end
extern u8 core2_ROM_START[]; // core2 decompressed rom start
extern u8 core2_ROM_END[]; // core2 decompressed rom end
extern u8 core2_TEXT_START[]; // core2 text start
extern u8 core2_TEXT_END[]; // core2 text end
extern u8 core2_RODATA_START[]; // core2 rodata start
extern u8 core2_DATA_END[]; // core2 data end
extern u8 core2_BSS_START[]; // core2 bss start
extern u8 core2_BSS_END[]; // core2 bss end

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001207C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001209C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001210C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001211C.s")

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
    func_8001DDF0();
    init_crc_check();
    func_80014FE8();
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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800123B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800123BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800123F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800124EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_8001253C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012598.s")
