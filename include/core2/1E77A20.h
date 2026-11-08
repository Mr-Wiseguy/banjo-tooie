#ifndef __CORE2_1E77A20_H__
#define __CORE2_1E77A20_H__

#include "common.h"

#include <ultra64.h>
#include "ba/yaw.h"
#include "core1/1E2B200.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1EC8070.h"
#include "core2/1ECD170.h"
#include "memory.h"
#include "ba/playerstate.h"
#include "bs/state.h"

f32 func_8009E138(PlayerState *, s32);
void func_8009E154(PlayerState *, s32, f32 *);
void func_8009E388(s32);
void func_8009E390(PlayerState*);
void func_8009E474(PlayerState *);
void func_8009E4AC(PlayerState *);
void func_8009E4E0(PlayerState*, s32, void (*)(PlayerState*, s32, s32));
void func_8009E4FC(PlayerState*, s32, f32, f32, f32);
void func_8009E53C(PlayerState *, s32, f32);
void func_8009E55C(PlayerState *, s32, f32);
void func_8009E5A4(PlayerState *, s32, s32);
s32 func_8009E5C0(void);
void bs_setState(PlayerState*, BanjoStateId);
s32 func_8009E674(PlayerState*, s32);
s32 func_8009E69C(PlayerState *, s32);
s32 func_8009E6C4(PlayerState *, s32);
s16 func_8009E6EC(PlayerState *);
BanjoStateId bs_getCurrentState(PlayerState*);
BanjoStateId bs_getNextState(PlayerState*);
BanjoStateId bs_getPreviousState(PlayerState*);
s32 func_8009E71C(PlayerState*, s32);
s32 func_8009E74C(PlayerState *, s32);
s32 func_8009E77C(PlayerState *, s32);
void func_8009E7AC(PlayerState*);
s32 func_8009E7C8(PlayerState*, s32);
void func_8009E830(PlayerState *, s32);
void func_8009E83C(PlayerState*);

#endif // __CORE2_1E77A20_H__
