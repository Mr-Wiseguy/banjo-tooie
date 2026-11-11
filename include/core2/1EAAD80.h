#ifndef __CORE2_1EAAD80_H__
#define __CORE2_1EAAD80_H__

#include "common.h"
#include "memory.h"
#include "core1/1E29B60.h"
#include "core2/1EABAC0.h"

void inventory_setup();
void inventory_free();
void inventory_defrag(void);
void func_800D162C();
void inventory_addValue(s32, s32);
void inventory_decrementValue(s32);
//Inventory Item by 0 to show item value
void inventory_showValue(s32);
//Increment Inventory Value
void inventory_incrementValue(s32);
void func_800D1864(u32, u32, u32);
//Get Inventory Value
s32 inventory_getValue(s32 a0);
void func_800D192C(s32, u32);
void func_800D1960(s32, s32, s32);
u32 func_800D1A6C(u32);
s32 func_800D1B34(s32);
s32 inventory_hasZeroItems(s32);
s32 func_800D1ACC(s32);
s32 func_800D1C5C(u32);

#endif
