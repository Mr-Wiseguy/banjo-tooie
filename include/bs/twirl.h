#ifndef __BS_TWIRL__
#define __BS_TWIRL__


#include <ultra64.h>
#include "common.h"
#include "player.h"
#include "bs.h"
#include "buttons.h"

#include "ba/anim.h"
#include "ba/assets.h"
#include "ba/physics.h"

#include "bs/state.h"

#include "core2/anctrl.h"
#include "core2/1E72EA0.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EB5980.h"

void func_80800000_bstwirl(PlayerState *self);
void bstwirl_init(PlayerState *self);
void bstwirl_update(PlayerState *self);
BsScript bstwirl_entrypoint_0(BsScriptType type);

#endif // __BS_TWIRL__
