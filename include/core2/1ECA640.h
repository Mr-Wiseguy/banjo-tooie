#ifndef __CORE2_1ECA640_H__
#define __CORE2_1ECA640_H__

#include "common.h"
#include "core2/1ECB0F0.h"

#include <ultra64.h>

f32 ml_clamp_f(f32 value, f32 min, f32 max); // mlClamp()
s32 ml_clamp_i(s32, s32, s32);
f32 func_800F0DC0(f32, f32);
f32 ml_max_f(f32, f32);
s32 ml_max_i(s32, s32);
void func_800F0EF0(s32, f32*);
f32 func_800F0F9C(f32, f32);
f32 func_800F101C(f32, f32);
f32 ml_map_f(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
f32 ml_mapRange_f(f32, f32, f32, f32, f32);
f32 ml_mapNormal_f(f32 value, f32 min, f32 max); // ml_interpolate_f
f32 func_800F12D4(f32, f32, f32, f32, f32);
f32 func_800F1344(f32, f32 , f32, f32 , f32); //ml_mapAbsRange_f
f32 ml_remainder_f(f32, f32);
f32 ml_min_f(f32, f32);
s32 ml_min_i(s32, s32);
f32 func_800F1434(f32);
f32 func_800F14AC(f32);
int ml_timer_update(f32* timer, f32 delta);
f32 func_800F15F8(f32, f32, f32);
f32 func_800138D0(f32);
f32 func_8001395C(f32);

#endif // __CORE2_1ECA640_H__
