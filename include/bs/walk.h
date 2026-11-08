#ifndef __BS_WALK_H__
#define __BS_WALK_H__

#include "common.h"
#include "ba/playerstate.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/duo.h"
#include "ba/dust.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/packctrl.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/mum/move.h"
#include "bs/mum/still.h"
#include "bs/state.h"
#include "core2/1E64F00.h"
#include "core2/1E66990.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1EB2840.h"
#include "core2/1ECA640.h"
#include "core2/anctrl.h"
#include "player.h"

void _bswalk_entrypoint_1(PlayerState *self);

#endif // __BS_WALK_H__
