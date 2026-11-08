#ifndef __BS_BFLIP__
#define __BS_BFLIP__


#include <ultra64.h>
#include "common.h"
#include "player.h"
#include "bs.h"

#include "ba/anim.h"
#include "ba/physics.h"
#include "ba/stick.h"

#include "bs/state.h"

#include "core2/anctrl.h"
#include "core2/1E66990.h"
#include "core2/1E72EA0.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"

void func_80800000_bsbflip(PlayerState *self);
void func_80800064_bsbflip(PlayerState *self, s32 substate);
void bsbflip_end(PlayerState *self);
void bsbflip_init(PlayerState *self);
void bsbflip_update(PlayerState *self);
BsScript bsbflip_entrypoint_3(BsScriptType type);

#endif // __BS_BFLIP__
