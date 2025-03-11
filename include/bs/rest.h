#ifndef __BS_REST_H__
#define __BS_REST_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/data.h"
#include "ba/drone.h"
#include "ba/flag.h"
#include "ba/fpctrl.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/yaw.h"
#include "bs/state.h"
#include "nc/ba1p.h"
#include "common.h"
#include "player.h"

extern s32 D_80800910_bsrest[];
extern s32 D_80800920_bsrest[];
extern s32 D_80800930_bsrest[];

extern void func_8009BA9C(PlayerState *self, f32[3]);
extern void func_8009BF5C(PlayerState *self, f32);
extern void func_8009C128(PlayerState *self, f32[3]);
extern void func_8009D3A8(PlayerState *self, s32);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
void func_800A0CF4(PlayerState* player, s32);
void func_800A0D14(PlayerState *, s32, f32);
extern PlayerState *func_800A4CA8(PlayerState *self);
extern s32 func_800F1E6C(f32[3], f32[3], f32 *target_yaw);
extern void func_800F3BD0(PlayerState *self, s32, f32[3]);
extern s32 func_8008B28C(AnimCtrl *);
extern s32 func_8009CC18(PlayerState *self, f32[3]);
extern s32 func_8009CC68(PlayerState *self);
extern s32 func_800A0C20(PlayerState *self);
extern void func_800A516C(f32[3], f32[3], f32[3]);
extern void func_80110BF0(PlayerState *self);
extern void func_80110C2C(PlayerState *self);
extern void func_801160DC(PlayerState *self, f32);

extern void _bsrest_entrypoint_0(PlayerState *self);
extern void _bsrest_entrypoint_1(PlayerState *self);
extern void _bsrest_entrypoint_2(PlayerState *self);
extern void _bsrest_entrypoint_3(PlayerState *self);
extern s32 _bsrest_entrypoint_4(s32 idx);
extern void _bsrest_entrypoint_5(PlayerState *self);
extern void _bsrest_entrypoint_6(PlayerState *self);
extern void _bsrest_entrypoint_7(PlayerState *self);
extern s32 _bsrest_entrypoint_8(s32 idx);
extern void _bsrest_entrypoint_9(PlayerState *self);
extern void _bsrest_entrypoint_10(PlayerState *self);
extern void _bsrest_entrypoint_11(PlayerState *self);
extern s32 _bsrest_entrypoint_12(s32 idx);
extern AssetId _bsrest_entrypoint_13(PlayerState *self);
extern void _bsrest_entrypoint_14(PlayerState *self);
extern void _bsrest_entrypoint_15(PlayerState *self, s32 arg1);
extern void _bsrest_entrypoint_16(PlayerState *self);
extern void _bsrest_entrypoint_17(PlayerState *self, s32 arg1);
extern void _bsrest_entrypoint_18(PlayerState *self);
extern s32 _bsrest_entrypoint_19(PlayerState *self, s32 arg1);
extern s32 _bsrest_entrypoint_20(PlayerState *self);

#endif // __BS_REST_H__
