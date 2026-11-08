#ifndef __BS_BBARGE__
#define __BS_BBARGE__


#include <ultra64.h>
#include "common.h"
#include "player.h"
#include "bs.h"
#include "buttons.h"

#include "ba/anim.h"
#include "ba/assets.h"
#include "ba/physics.h"
#include "bs/state.h"
#include "ba/timer.h"

#include "core2/anctrl.h"
#include "core2/1E68670.h"
#include "core2/1E72EA0.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"

void bsbbarge_setSubstate(PlayerState *self, int substate);
void bsbbarge_end(PlayerState *self);
void bsbbarge_init(PlayerState *self);
void bsbbarge_update(PlayerState *self);
BsScript bsbbarge_entrypoint_0(BsScriptType type);

#endif // __BS_BBARGE__
