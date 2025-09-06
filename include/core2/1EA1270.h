#ifndef __CORE2_1EA1270_H__
#define __CORE2_1EA1270_H__

#include "common.h"

typedef struct Unk800C7A68 {
    s16 unk0;
    u8 unk2;
    u8 pad3[0x14 - 0x3];
    s32 unk14;
} Unk800C7A68;

void (*func_800C79EC(Unk800C7A68 *))(f32, u8, s32*, s32);
void func_800C7A68(Unk800C7A68*, f32, s32);
f32 func_800C7B7C(Unk800C7A68 *, f32, f32, f32);

#endif
