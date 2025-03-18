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
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E79FD0.h"
#include "core2/1E7B250.h"
#include "core2/1E7D460.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "common.h"
#include "funcs.h"

void func_800EFD24(f32 [3]);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);

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
