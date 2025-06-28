#ifndef __BS_MUMMOVE_H__
#define __BS_MUMMOVE_H__

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/drone.h"
#include "overlays/ba/dust.h"
#include "overlays/ba/key.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/roll.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/yaw.h"
#include "overlays/bs/mum.h"
#include "overlays/bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

void func_8008CA30(PlayerState *self, f32 scale);
extern void func_8009D2F0(PlayerState *self, s32, f32);
s32 func_8008E148(PlayerState *self);

extern s32 D_808005B0_bsmummove[];
extern s32 D_808005C0_bsmummove[];

f32 _bsmummove_entrypoint_0(PlayerState *self);
f32 _bsmummove_entrypoint_1(PlayerState *self);
f32 _bsmummove_entrypoint_2(PlayerState *self);

#endif // __BS_MUMMOVE_H__
