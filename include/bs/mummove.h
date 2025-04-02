#ifndef __BS_MUMMOVE_H__
#define __BS_MUMMOVE_H__

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/dust.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/mum.h"
#include "bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

void func_8008C9F0(PlayerState *self, f32, f32, f32, f32);
void func_8008CA30(PlayerState *self, f32 scale);
extern void func_8009D2F0(PlayerState *self, s32, f32);
s32 func_8008E148(PlayerState *self);

extern s32 D_808005B0_bsmummove[];
extern s32 D_808005C0_bsmummove[];

f32 _bsmummove_entrypoint_0(PlayerState *self);
f32 _bsmummove_entrypoint_1(PlayerState *self);
f32 _bsmummove_entrypoint_2(PlayerState *self);

#endif // __BS_MUMMOVE_H__
