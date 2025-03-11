#ifndef __BS_MUMSWIM_H__
#define __BS_MUMSWIM_H__

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/mum.h"
#include "bs/rest.h"
#include "bs/state.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E7D460.h"
#include "core2/1ECA640.h"
#include "common.h"
#include "funcs.h"
#include "player.h"
#include <ultra64.h>

extern s32 func_8001210C(s32);
extern void func_8008B1C8(AnimCtrl *, f32);
void func_8008C9F0(PlayerState *self, f32, f32, f32, f32);
void func_8008CA4C(PlayerState *self, BaAnimUpdateType arg1);
extern void func_80092C00(PlayerState *self, f32[3]);
extern void func_80092C24(PlayerState *self, f32[3]);
extern void func_800961AC(PlayerState *self, s32);
extern s32 func_80096500(PlayerState *self);
extern void func_8009BC34();
extern void func_8009BC5C(PlayerState *self, f32);
extern void func_8009DE74(PlayerState *self, s32, f32, f32);
extern void func_8009DEC0(PlayerState *self, s32, f32, f32, s32, s32);
extern s32 func_8009E69C(PlayerState *self, s32);
extern s32 func_8009E6C4(PlayerState *self, s32);
extern s32 func_8009FBB0(PlayerState *self, f32[3], f32);
extern void func_8009FC34(PlayerState *self, s32);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
extern void func_800A046C(PlayerState *self);
extern f32 func_800A3298(PlayerState *self);
extern void func_800A4DA4(PlayerState *self, s32);
extern void func_800BA22C(s32, s32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
f32 func_800DC0C0(void);
f32 func_800F1214(f32 value, f32 min, f32 max); // ml_interpolate_f
s32 func_80096544(PlayerState *self);
void func_8009FD24(PlayerState *self, s32);

extern s32 D_80800B30_bsmumswim[];
extern s32 D_80800B40_bsmumswim[];
extern s32 D_80800B50_bsmumswim[];
extern s32 D_80800B60_bsmumswim[];
extern s32 D_80800B70_bsmumswim[];

#endif // __BS_MUMSWIM_H__
