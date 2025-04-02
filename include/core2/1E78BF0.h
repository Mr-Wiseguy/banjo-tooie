#ifndef __CORE2_1E78BF0_H__
#define __CORE2_1E78BF0_H__

#include "ba/playerstate.h"
#include "ba/anim.h"
#include "ba/yaw.h"
#include "ba/physics.h"
#include "bs/state.h"

f32 func_8009F308(PlayerState *);
f32 func_8009F3BC(PlayerState *, f32, f32, f32, f32);
s32 func_8009FBB0(PlayerState *, f32[3], f32);
void func_8009FC34(PlayerState *, s32);
void func_8009FE58(PlayerState *);
void func_8009FFD8(PlayerState *, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
void func_800A0180(PlayerState *);
BanjoStateId func_800A01F8(PlayerState *, BanjoStateId arg1);
BanjoStateId func_800A02DC(PlayerState *, BanjoStateId arg1);
void func_800A042C(PlayerState *);
void func_800A046C(PlayerState *);

#endif // __CORE2_1E78BF0_H__
