#ifndef __BS_BFLAP__
#define __BS_BFLAP__


#include <ultra64.h>
#include "common.h"
#include "player.h"
#include "bs.h"

#include "ba/anim.h"
#include "ba/assets.h"
#include "ba/flag.h"
#include "ba/timer.h"
#include "ba/physics.h"
#include "ba/stick.h"

#include "bs/state.h"

#include "core2/anctrl.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E72EA0.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"

void bsbflap_init(PlayerState *self);
void func_80800120_bsbflap(PlayerState *self);
f32 func_80800168_bsbflap(PlayerState *self);
void func_808001D8_bsbflap(PlayerState *self);
void func_80800210_bsbflap(PlayerState *self);
int func_80800248_bsbflap(PlayerState *self, f32 value);
void func_80800294_bsbflap(PlayerState *self);
void bsbflap_update(PlayerState *self);
void bsbflap_end(PlayerState *self);
BsScript bsbflap_entrypoint_3(BsScriptType type);

#endif // __BS_BFLAP__
