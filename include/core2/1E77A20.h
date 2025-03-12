#ifndef __CORE2_1E77A20_H__
#define __CORE2_1E77A20_H__

#include "common.h"

#include <ultra64.h>

#include "ba/playerstate.h"
#include "bs/state.h"

void func_8009E55C(PlayerState *, s32, f32);
s16 func_8009E6EC(PlayerState *);
s32 bs_getCurrentState(PlayerState *);
s32 bs_getNextState(PlayerState *);
s32 bs_getPreviousState(PlayerState *);
s32 func_8009E74C(PlayerState *, s32);
s32 func_8009E77C(PlayerState *, s32);
void func_8009E830(PlayerState *, s32);

#endif // __CORE2_1E77A20_H__
