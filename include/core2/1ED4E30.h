#ifndef __CORE2_1ED4E30_H__
#define __CORE2_1ED4E30_H__

#include "common.h"
#include "core2/1ED68A0.h"
#include "core2/1ED68A0.h"

typedef struct {
    u8 pad0[0x28];
    s16 unk28;
    u8 pad2A[0x33 - 0x2A];
    u8 unk33;
} unkStruct800FB540;

s32 func_800FB650(s32, s32, s32);
void func_800FB968();
void func_800FC124(u32);
void func_800FC1A8(void);
void func_800FC348(u32, u32, u32);
void func_800FC63C(u32, u32);
void func_800FC660(s32);
void func_800FC6B0(u32);
void func_800FC74C(u32);
void func_800FC7C4();
void func_800FC81C();
void func_800FC9B4(s32, f32);
void func_800FCA90(u32);
void func_800FCAE0(u32, u32, u32);
s32 func_800FCCD4(s32);

#endif // __CORE2_1ED4E30_H__
