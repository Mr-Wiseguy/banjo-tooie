#ifndef __CORE1_1E29B60_H__
#define __CORE1_1E29B60_H__

#include "common.h"
#include "threads.h"
#include "overlays.h"
#include "core1/crc.h"
#include "core1/heap.h"
#include "core1/1E2A0E0.h"
#include "core1/1E2C940.h"
#include "core1/1E2D890.h"
#include "core1/1E2F380.h"
#include "core1/1E31B40.h"
#include "core1/1E33CF0.h"
#include "core1/1E35920.h"
#include "core1/1E36310.h"
#include "core2/1E7F4D0.h"
#include "core2/1E80A70.h"
#include "core2/1EA1DA0.h"
#include "core2/1EAED30.h"
#include "core2/1EAF950.h"
#include "core2/1EB2840.h"
#include "core2/1EBE020.h"
#include "core2/1EF01E0.h"
#include "co/section.h"
#include "gc/statusDll.h"

void func_80012030(s32); 
void func_8001207C();
void func_8001209C(s32);
s32 func_8001210C(s32);
s32 func_8001211C(void);
void func_80012128();
void func_800121D0();
void func_800123BC();
void func_800123F4(void);
s32 func_80012530();
void func_8001253C(s32);


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


#endif // __CORE1_1E29B60_H__
