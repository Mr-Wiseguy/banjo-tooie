#ifndef __BS_BBUSTER__
#define __BS_BBUSTER__


#include <ultra64.h>
#include "common.h"
#include "player.h"
#include "bs.h"
#include "buttons.h"

#include "ba/anim.h"
#include "ba/assets.h"
#include "ba/dust.h"
#include "ba/flag.h"
#include "ba/motor.h"
#include "ba/physics.h"

#include "bs/state.h"

#include "core2/anctrl.h"
#include "core2/1E66990.h"
#include "core2/1E68670.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EB2840.h"
#include "core2/1ECB9F0.h"

void bsbbuster_setSubstate(PlayerState *self, int substate);
void bsbbuster_end(PlayerState *self);
void bsbbuster_init(PlayerState *self);
void bsbbuster_update(PlayerState *self);
BsScript bsbbuster_entrypoint_0(BsScriptType type);

#endif // __BS_BBUSTER__
