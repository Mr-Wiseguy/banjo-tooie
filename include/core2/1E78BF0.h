#ifndef __CORE2_1E78BF0_H__
#define __CORE2_1E78BF0_H__

#include "physicstypes.h"
#include "ba/playerstate.h"
#include "ba/anim.h"
#include "ba/data.h"
#include "ba/drone.h"
#include "ba/flag.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/yaw.h"
#include "bs/beemain.h"
#include "bs/mum/move.h"
#include "bs/mum/still.h"
#include "ba/physics.h"
#include "bs/state.h"

#include "core1/mlmtx.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76500.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78170.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E831D0.h"
#include "core2/1E93440.h"
#include "core2/1EA3AA0.h"
#include "core2/1EAD060.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECD170.h"
#include "core2/1ED4E30.h"
#include "core2/1ED68A0.h"
#include "core2/anctrl.h"
#include "fx/airbub.h"
#include "fx/ripple.h"
#include "fx/splash.h"
#include "player.h"

s32 func_8009F300(void);
f32 func_8009F308(PlayerState *);
// func_8009F354
f32 func_8009F3BC(PlayerState *, f32, f32, f32, f32);
s32 func_8009F440(PlayerState*, s32, s32, s32, s32, f32);
s32 func_8009F678(PlayerState*, s32, s32, f32);
s32 func_8009F860(PlayerState*, s32, s32, s32, f32, f32);
// func_8009FA20
s32 func_8009FBB0(PlayerState *, f32[3], f32);
// func_8009FBE8
void func_8009FC34(PlayerState *, s32);
void func_8009FC80(PlayerState*);
void func_8009FD24(PlayerState *, s32);
void func_8009FE58(PlayerState*);
void func_8009FE78(PlayerState*);
// bs_getTypeOfJump
// func_8009FF00
void func_8009FF44(PlayerState*, s32, f32, f32, f32, f32); 
void func_8009FFD8(PlayerState *, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
void func_800A0024(PlayerState*);
// func_800A0064
s32 func_800A00CC(PlayerState *, f32[3]);
void func_800A0110(PlayerState*, AnimCtrl*);
// func_800A0150
void func_800A0180(PlayerState *);
BanjoStateId func_800A01F8(PlayerState *, BanjoStateId arg1);
BanjoStateId func_800A02DC(PlayerState *, BanjoStateId arg1);
void func_800A042C(PlayerState *);
void func_800A046C(PlayerState *);
BanjoStateId func_800A04F4(PlayerState*, BanjoStateId);
BanjoStateId bs_getTypeOfGroundedAttack(PlayerState*, BanjoStateId);
void func_800A05DC(PlayerState*);

#endif // __CORE2_1E78BF0_H__
