#ifndef __BS_CROUCH__
#define __BS_CROUCH__


#include <ultra64.h>
#include "common.h"
#include "ba/playerstate.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/dust.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/packctrl.h"
#include "ba/stick.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "bs/crouch.h"
#include "bs/mum/move.h"
#include "bs/mum/still.h"
#include "bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1EA0690.h"
#include "core2/1EA4CD0.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECB9F0.h"
#include "core2/anctrl.h"
#include "player.h"
#include "su/inv.h"

void _bscrouch_entrypoint_0(PlayerState*);
void _bscrouch_entrypoint_1(PlayerState*);
void _bscrouch_entrypoint_2(PlayerState*);
s32 _bscrouch_entrypoint_3(s32);
BanjoStateId _bscrouch_entrypoint_4(PlayerState*, BanjoStateId);

#endif // __BS_CROUCH__
