#ifndef __CORE2_1E6B900_H__
#define __CORE2_1E6B900_H__

#include <ultra64.h>

#include "ba/playerstate.h"

void func_80092864(PlayerState *, f32);
void func_80092BF4(PlayerState *);
void func_80092C00(PlayerState *, f32[3]);
void func_80092C24(PlayerState *, f32[3]);
void func_80093360(PlayerState *, f32);
s32 func_800944E0(PlayerState *, s32);
s32 func_80094510(PlayerState *);
s32 func_80094B14(PlayerState *);
s32 func_80094BC0(PlayerState *);
// This might return a s32 instead of a PlayerState pointer
PlayerState *func_80092B04(PlayerState *, s32);
// This might take a s32 instead of a PlayerState pointer
// This might return a s32 instead of a PlayerState pointer
PlayerState *func_800B27E0(PlayerState *);


#endif // __CORE2_1E6B900_H__
