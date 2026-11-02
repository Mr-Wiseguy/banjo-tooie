#ifndef __CORE2_1EB2840_H__
#define __CORE2_1EB2840_H__

#include <ultra64.h>
#include "core2/1ECA640.h"

void func_800D8F50(f32);
s32 func_800D8FEC();
f32 time_getDelta(void); //time_getDelta()
f32 func_800D9004();
f32 func_800D902C(void);
s32 func_800D9058(f32);
s32 timer_reachedZero(f32*);
s32 timer_reachedZero_dupe(f32*);
s32 timer_reachedValueDec(f32*, f32);
s32 func_800D9154(f32*, f32);
f32 timer_countUp(f32*);
s32 timer_reachedValueInc(f32*, f32);

#endif // __CORE2_1EB2840_H__
