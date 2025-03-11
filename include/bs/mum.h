#ifndef __BS_MUM_H__
#define __BS_MUM_H__

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/bounce.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/mum.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/sudie.h"
#include "bs/drone.h"
#include "bs/mummove.h"
#include "bs/rest.h"
#include "bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6E870.h"
#include "core2/1E75710.h"
#include "core2/1ECA640.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

extern s32 func_8008D544(PlayerState *self);
extern s32 func_8008E260(PlayerState *self);
extern void func_80093360(PlayerState *self, f32);
extern void func_800947EC(PlayerState *self, s32, s32);
void func_80099B94(PlayerState *self);
extern void func_8009B7C0(PlayerState *self);
extern void func_8009BB24(PlayerState *self, f32 *);
extern f32 func_8009BFD8(PlayerState *self);
void func_8009DE38(PlayerState *self, s32, f32);
void func_8009DF18(PlayerState *self, s32, f32, s32);
void func_8009DF94(PlayerState *self, s32, f32, s32);
extern void func_8009E0DC(PlayerState *self);
extern void func_8009E474(PlayerState *self);
extern void func_8009E4AC(PlayerState *self);
extern void func_8009E53C(PlayerState *self, s32, f32);
void func_8009E55C(PlayerState *self, s32, f32);
extern void func_8009E5A4(PlayerState *self, s32, s32);
extern s32 func_8009E6EC(PlayerState *self);
extern s32 func_8009E6F8(PlayerState *self);
extern s32 func_8009E704();
extern s32 func_8009E74C(PlayerState *self, s32);
extern s32 func_8009E77C(PlayerState *self, s32);
extern void func_8009E830(PlayerState *self, s32);
extern void func_8009FE58(PlayerState *self);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
extern void func_800A042C(PlayerState *self);
extern void func_800A046C(PlayerState *self);
f32 func_800DC0C0(void);
f32 func_800DC178(f32, f32);
f32 func_800F1214(f32 value, f32 min, f32 max); // ml_interpolate_f
s32 func_8008DE24(PlayerState *self);
void func_80093230(PlayerState *self, f32);
void func_800A0DAC(PlayerState *self, s32);

extern s32 D_80801140_bsmum[];
extern s32 D_80801150_bsmum[];
extern s32 D_80801160_bsmum[];
extern s32 D_80801170_bsmum[];
extern s32 D_80801180_bsmum[];
extern s32 D_80801190_bsmum[];
extern s32 D_808011A0_bsmum[];
extern s32 D_808011B0_bsmum[];

void bsmum_entrypoint_13(PlayerState *self);
void _bsmum_entrypoint_13(PlayerState *self);
void _bsmum_entrypoint_1(PlayerState *self);
void _bsmum_entrypoint_2(PlayerState *self);
void _bamum_entrypoint_5(PlayerState *self, f32);

#endif // __BS_MUM_H__
