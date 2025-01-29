#ifndef __BS_KAZMOVE_H__
#define __BS_KAZMOVE_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/duo.h"
#include "ba/dust.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/shoes.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "funcs.h"
#include "player.h"

extern void func_8008B1C8(AnimCtrl *, f32);
extern s32 func_8008D790(PlayerState *self);
extern s32 func_8008DF18(PlayerState *self);
extern s32 func_8008E39C(PlayerState *self);
extern void func_800962B0(s32, s32);
extern f32 func_8009BB5C(PlayerState *self);
extern s32 func_8009BCD4(PlayerState *self, f32);
extern void func_8009BF5C(PlayerState *self, f32);
extern void func_8009BFE4(PlayerState *self, f32, f32);
extern void func_8009D2F0(PlayerState *self, s32, f32);
extern s32 func_8009E710(PlayerState *self);
extern s32 func_800A02DC(PlayerState *self, s32);
extern void func_800A2CE8(PlayerState *self, f32, s32);
extern void func_800A2D2C(PlayerState *self, f32, s32);
extern f32 func_800F1214(f32 value, f32 min, f32 max); // ml_interpolate_f

void _bskazmove_entrypoint_0(PlayerState *self);
void _bskazmove_entrypoint_11();

#endif // __BS_KAZMOVE_H__