#ifndef __BS_KAZGLIDE_H__
#define __BS_KAZGLIDE_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/fly.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/kaz.h"
#include "bs/kazmove.h"
#include "funcs.h"
#include "player.h"

extern f32 func_800136E4(f32);
extern s32 func_8008DF8C(PlayerState *self, s32);
extern s32 func_8008E124();
extern void func_8008E944(PlayerState *self);
extern void func_8008E95C(PlayerState *self);
extern void func_80093360(PlayerState *self, f32);
extern void func_800959C8(PlayerState *self, f32, f32);
extern void func_80095A40(PlayerState *self);
extern void func_800961AC(PlayerState *self, s32);
extern f32 func_8009630C(PlayerState *self);
extern void func_800995B8(PlayerState *self, s32);
extern void func_80099B94(PlayerState *self);
extern void func_8009BC34();
extern void func_8009BD88(PlayerState *self);
extern void func_8009BFE4(PlayerState *self, f32, f32);
extern void func_8009C128(PlayerState *self, f32[3]);
extern void func_8009D9D4(PlayerState *self);
extern void func_8009DF18(PlayerState *self, s32, f32, s32);
extern void func_8009DF94(PlayerState *self, s32, f32, s32);
extern s32 func_8009E69C(PlayerState *self, s32);
extern s32 func_8009E6C4(PlayerState *self, s32);
extern s32 func_8009E6EC(PlayerState *self);
extern void func_8009E830(PlayerState *self, s32);
extern void func_800A042C(PlayerState *self);
extern void func_800A32C4(PlayerState *self, f32[3]);
extern void func_800A4DA4(PlayerState *self, s32);
extern void func_800A4E30(PlayerState *self);
extern f32 func_800DC178(f32, f32);
extern f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
extern void func_800F1E6C(f32[3], f32[3], f32 *target_yaw);

#endif // __BS_KAZGLIDE_H__
