#ifndef __CORE2_1E76360_H__
#define __CORE2_1E76360_H__

#include <ultra64.h>

#include "common.h"
#include "ba/playerstate.h"
#include "bs/state.h"
s32 func_8009CA70(PlayerState *, BanjoStateId, s32);
void (*func_8009CAAC(PlayerState*, BanjoStateId))(PlayerState*);
void (*func_8009CAF8(PlayerState*, BanjoStateId))(PlayerState*);
void (*func_8009CB44(PlayerState*, BanjoStateId))(PlayerState*);
void (*func_8009CB90(PlayerState*, BanjoStateId))(PlayerState*);
s32 func_8009CBDC(PlayerState*, s32);
void func_8009CBFC(PlayerState*);

#endif // __CORE2_1E76360_H__
