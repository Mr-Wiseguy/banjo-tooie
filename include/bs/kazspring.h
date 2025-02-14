#ifndef __BS_KAZSPRING_H__
#define __BS_KAZSPRING_H__

#include <ultra64.h>

#include "ba/anim.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "funcs.h"
#include "player.h"

extern void func_8009D2D8(PlayerState *self, s32);
extern void func_8009DF18(PlayerState *self, s32, f32, s32);
extern void func_8009DF94(PlayerState *self, s32, f32, s32);
extern f32 func_800F1214(f32 value, f32 min, f32 max); // ml_interpolate_f

#endif // __BS_KAZSPRING_H__
