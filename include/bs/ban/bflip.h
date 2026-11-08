#ifndef __BS_BAN_BFLIP__
#define __BS_BAN_BFLIP__


#include <ultra64.h>
#include "common.h"
#include "player.h"
#include "bs.h"

#include "ba/anim.h"
#include "ba/stick.h"
#include "ba/physics.h"

#include "bs/state.h"

#include "core2/1E72EA0.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"

void func_80800000_bsbanbflip(PlayerState *self);
void __bsbanbflip_set_substate(PlayerState *self, BanjoStateId next_state);
void bsbanbflip_end(PlayerState *self);
void bsbanbflip_init(PlayerState *self);
void bsbanbflip_update(PlayerState *self);
BsScript bsbanbflip_entrypoint_3(BsScriptType type);

#endif // __BS_BAN_BFLIP__
