#ifndef __CORE2_1EB3750_H__
#define __CORE2_1EB3750_H__

#include "common.h"
#include "gameflags.h"

s32 flag_getValue(GameFlag index);
void flag_setValue(GameFlag index, s32 set);
void flag_setValueFalse(GameFlag);
void flag_setValueTrue(GameFlag);
s32 flag_getMultipleValue(GameFlag, s32);
void flag_setMultipleValue(GameFlag startIndex, s32 set, s32 length);
void func_800DA0B4();
void func_800DA0D8();
void func_800DA104();
void func_800DA188();
s32 func_800DA944(GameFlag startIndex, s32 length);
s32 func_800DA980(GameFlag, s32);
s32 func_800DA9E4(GameFlag, s32);
s32 func_800DAA1C();
s32 func_800DAC78(u8*, s32);
#endif
