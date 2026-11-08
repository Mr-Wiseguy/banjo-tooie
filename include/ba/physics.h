#ifndef __BA_PHYSICS_H__
#define __BA_PHYSICS_H__

#include "physicstypes.h"
#include "ba/anim.h"
#include "ba/playerstate.h"
#include "ba/yaw.h" // for YawType
#include "ba/move/goto.h"
#include "ba/move/ledge.h"
#include "ba/move/hover.h"
#include "ba/move/spline.h"
#include "ba/move/thrust.h"
#include "bs/firstp.h"
#include "ba/stick.h"
#include "core2/1E66990.h"
#include "core2/1E6E760.h"
#include "core2/1E6F080.h"
#include "core2/1E71B00.h"
#include "core2/1E75920.h"
#include "core2/1E7BFA0.h"
#include "core2/1EB2840.h"
#include "core2/1EC8070.h"
#include "core2/1ECB9F0.h"

void baphysics_set_type(PlayerState *, BaPhysicsType);
void baphysics_set_vertical_velocity(PlayerState *, f32);
void baphysics_set_target_horizontal_velocity(PlayerState* , f32 vel);
void baphysics_set_target_yaw(PlayerState *, f32 target_yaw);
f32 baphysics_get_target_horizontal_velocity(PlayerState *);
void baphysics_set_horizontal_velocity(PlayerState *, f32 yaw, f32 vel);
f32  baphysics_get_vertical_velocity(PlayerState *);
void baphysics_reset_gravity(PlayerState* );
void baphysics_reset_terminal_velocity(PlayerState *);
void baphysics_set_gravity(PlayerState *, f32);
void baphysics_set_terminal_velocity(PlayerState *, f32);

s32 func_8009AD70();
s32 func_8009AD78(PlayerState*, s32);
void func_8009AD88(s32);
void func_8009AD90(PlayerState*);
void func_8009ADF0(PlayerState*, s32, s32);
s32 func_8009AE00();
void func_8009AE08(PlayerState*);
void func_8009B08C(PlayerState*);
void func_8009B170(PlayerState*);
void func_8009B1FC(PlayerState*);
void func_8009B27C(PlayerState*);
void func_8009B3B8(PlayerState*);
void func_8009B414(PlayerState*);
void func_8009B450(PlayerState*);
void func_8009B4D0(PlayerState*, f32[3]);
void func_8009B4FC(PlayerState*);
void func_8009B590(PlayerState*);
void func_8009B7C0(PlayerState *);
void func_8009B94C(PlayerState*, f32[3]);
void func_8009B98C(PlayerState*, f32[3]);
void func_8009B9F0(PlayerState *, f32);
void func_8009BA9C(PlayerState *, f32[3]);
f32 func_8009BADC(PlayerState *);
f32 func_8009BAE8(PlayerState *);
BaPhysicsType func_8009BAF4(PlayerState*);
f32 func_8009BB0C(PlayerState*);
f32 func_8009BB18(PlayerState*);
void func_8009BB24(PlayerState *, f32[3]);
f32 baphysics_get_horizontal_velocity(PlayerState *);
f32 baphysics_get_velocity(PlayerState *);
f32 func_8009BBB8(PlayerState*);
void func_8009BC08(PlayerState*, f32[3]);
void func_8009BC34(PlayerState *);
void func_8009BC5C(PlayerState *, f32);
s32 func_8009BCD4(PlayerState *, f32);
void func_8009BD18(PlayerState*, f32);

#endif
