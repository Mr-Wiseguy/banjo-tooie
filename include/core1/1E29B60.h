#ifndef __CORE1_1E29B60_H__
#define __CORE1_1E29B60_H__

#include "common.h"
#include <ultra64.h>

void func_8001209C(s32);
void func_80012128();
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

s32 func_8001210C(s32);
s32 func_8001211C(void);

#endif // __CORE1_1E29B60_H__
