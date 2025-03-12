#ifndef __BS_LEDGE_H__
#define __BS_LEDGE_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/key.h"
#include "ba/motor.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/rest.h"
#include "bs/state.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E79FD0.h"
#include "core2/1E7D460.h"
#include "common.h"
#include "funcs.h"

void func_800EFD24(f32 [3]);
f32 func_800F1214(f32 value, f32 min, f32 max); // ml_interpolate_f
extern void func_80092880(PlayerState *self, s32);
extern void func_800961AC(PlayerState *self, s32);
extern void func_8009E474(PlayerState *self);
extern s32 func_8009E74C(PlayerState *self, s32);
extern void func_800A2018(PlayerState *self, s32);
extern void func_8009E4AC(PlayerState *self);
extern void func_8009E53C(PlayerState *self, s32, f32);
void func_8009E55C(PlayerState *, s32, f32);
extern s32 func_8009E77C(PlayerState *self, s32);
f32 func_800DC178(f32, f32);
extern f32 func_8009BB5C(PlayerState *self);
extern void func_8009BA9C(PlayerState *self, f32[3]);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
void func_8009DF94(PlayerState *, s32, f32, s32);
extern void func_8009DEC0(PlayerState *self, s32, f32, f32, s32, s32);
extern void func_8009D874(PlayerState *self);
extern void func_8009DF58(PlayerState *self, s32, f32);

void _bapackctrl_entrypoint_5(PlayerState *self, s32);
void _batranslate_entrypoint_3(PlayerState *self, s32);
void _bsrest_entrypoint_15(PlayerState *self, s32);
s32 _bsrest_entrypoint_19(PlayerState *self, s32);
s32 func_8008E0E8(PlayerState *self);
s32 func_8008E23C(PlayerState *self);
s32 func_80096388(PlayerState *self);
f32 func_800974FC();
s32 func_80097524(PlayerState *self);
s32 func_80097530(PlayerState *self);
s32 func_800A3274();
u8 func_800DC128(s32, s32);
s32 func_800EEF24(f32[3]);
void func_800EFCD8(f32[3], f32, f32);
f32 func_800F1DCC(f32, f32);
void func_801124D0(s32, s32);


extern s16 D_80801340_bsledge[];
extern s32 D_80801348_bsledge[];
extern s32 D_80801358_bsledge[];
extern s32 D_80801368_bsledge[];
extern s32 D_80801378_bsledge[];
extern u8 D_80801388_bsledge[];
extern u8 D_80801390_bsledge[];
extern s32 D_80801398_bsledge[];
extern s32 D_808013A8_bsledge[];

void func_80800324_bsledge(PlayerState *self);
s32 func_80800000_bsledge(PlayerState *self);
s32 func_808003D0_bsledge(PlayerState *self);
s32 func_80800410_bsledge(PlayerState *self);
void func_80800D78_bsledge(PlayerState *self, s32);

#endif // __BS_LEDGE_H__
