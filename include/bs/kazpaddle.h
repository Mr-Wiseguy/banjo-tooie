#ifndef __BS_KAZPADDLE_H__
#define __BS_KAZPADDLE_H__

#include <ultra64.h>

#include "bs/drone.h"
#include "ba/playerstate.h"
#include "bs/kaz.h"
#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/rest.h"
#include "funcs.h"
#include "player.h"

extern s32 func_8001210C(s32);
extern void func_80092C00(PlayerState *self, f32[3]);
extern void func_80092C24(PlayerState *self, f32[3]);
extern void func_800961AC(PlayerState *self, s32);
extern s32 func_80096500(PlayerState *self);
extern void func_8009BC34();
extern void func_8009BC5C(PlayerState *self, f32);
extern void func_8009C128(PlayerState *self, f32[3]);
extern void func_8009D2D8(PlayerState *self, s32);
extern void func_8009DE74(PlayerState *self, s32, f32, f32);
extern s32 func_8009E69C(PlayerState *self, s32);
extern s32 func_8009E6C4(PlayerState *self, s32);
extern s32 func_8009FBB0(PlayerState *self, f32[3], f32);
extern void func_8009FC34(PlayerState *self, s32);
extern void func_800A046C(PlayerState *self);
extern void func_800A1040(PlayerState *self);
extern void func_800A106C(PlayerState *self, f32, f32);
extern f32 func_800A3298(PlayerState *self);
extern void func_800A4DA4(PlayerState *self, s32);
extern void func_800A4E30(PlayerState *self);
extern void func_800BA22C(s32, s32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_800DC0C0();
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
extern f32 func_800F1214(f32 value, f32 min, f32 max); // ml_interpolate_f

#endif // __BS_KAZPADDLE_H__