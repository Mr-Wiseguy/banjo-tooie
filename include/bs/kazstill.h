#ifndef __BS_KAZSTLL_H__
#define __BS_KAZSTLL_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/duo.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/shoes.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "bs/rest.h"
#include "core2/1E6E870.h"
#include "core2/1E76CC0.h"
#include "funcs.h"
#include "player.h"

extern s32 func_8008D790(PlayerState *self);
extern s32 func_8008DF18(PlayerState *self);
extern s32 func_8008E39C(PlayerState *self);
extern s32 func_8008E3E8(PlayerState *self);
extern void func_80090A2C(PlayerState *self);
extern BanjoStateId func_800A02DC(PlayerState *self, BanjoStateId);

extern BanjoStateId _bskazstill_entrypoint_4(PlayerState *self, BanjoStateId);

#endif // __BS_KAZSTLL_H__
