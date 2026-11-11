#ifndef __CORE2_1EAD6C0_H__
#define __CORE2_1EAD6C0_H__

#include "common.h"
#include "cheats.h"
#include "core2/1EB3750.h"
#include "core2/1EA0690.h"
#include "core2/1EAAD80.h"
#include "core2/1ECE0B0.h"

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} unkStructD_8011B5B8;

typedef struct {
    s16 unk0;
    s16 unk2;
} unkStructD_8011B620;



s32 func_800D3DD0(s32);
s32 func_800D3E14(s32);
//Is Cheat Active
s32 cheat_isActive(u32);
s32 func_800D3E6C(s32);
s32 func_800D3EC8(s32);
void func_800D3EF4(s32);
void func_800D3F2C(s32);
void func_800D3F58(s32, s32);
u16 func_800D3FC0(s32);
void func_800D3FD4(u32);
s32 func_800D41D8(s32);
void func_800D4298(s32, s32);
void func_800D42E8(s32, s32);
void func_800D433C(s32, s32);
void func_800D4398(s32, s32);

#endif
