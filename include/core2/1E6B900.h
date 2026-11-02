#ifndef __CORE2_1E6B900_H__
#define __CORE2_1E6B900_H__

#include <ultra64.h>

#include "ba/playerstate.h"
#include "ba/physics.h"
#include "core2/anctrl.h"

#include "core2/1E64F00.h"
#include "core2/1E75B90.h"
#include "core2/1E79FD0.h"
#include "core2/1E7BAB0.h"
#include "core2/1E7D460.h"
#include "core2/1E7F6A0.h"
#include "core2/1E80A70.h"
#include "core2/1E875C0.h"
#include "core2/1E8A670.h"
#include "core2/1E8BFE0.h"
#include "core2/1EAAD80.h"
#include "core2/1EABAC0.h"
#include "core2/1EAF950.h"
#include "core2/1EB57A0.h"
#include "core2/1EB5E70.h"
#include "core2/1EBA250.h"
#include "core2/1ECBCC0.h"
#include "core2/1ECE0B0.h"
#include "core2/1ED9D70.h"
#include "core2/1EE1510.h"
#include "ba/preload.h"
#include "gc/egg.h"
#include "ba/egg/fire.h"
#include "core1/mlmtx.h"
#include "ba/backpack.h"
#include "ba/roll.h"
#include "ba/input.h"
#include "ba/invisible.h"
#include "ch/baddiesetup.h"

s32 func_80092258(PlayerState*);
void func_80092444(PlayerState*, s32);
void func_8009272C(PlayerState*, s32);
void func_80092744(PlayerState*, s32);
void func_80092750(PlayerState*, s32, s32, s32, s32);
void func_80092778(PlayerState*);
void func_80092864(PlayerState *, f32);
void func_80092880(PlayerState *, s32);
void func_80092898(PlayerState*);
void func_80092A1C(PlayerState*);
void func_80092AA4(PlayerState*);
void func_80092AB0(PlayerState*);
Unkfunc_800E0960_1 *func_80092AD8(PlayerState *);
void *func_80092B04(PlayerState *, s32);
s32 func_80092B80(PlayerState*);
// This might take a s32 instead of a PlayerState pointer
// This might return a s32 instead of a PlayerState pointer
f32 func_80092B8C(PlayerState*, f32*);
f32 func_80092BE8(PlayerState *);
f32 func_80092BF4(PlayerState *);

void func_80092C00(PlayerState*, f32[3]);
void func_80092C24(PlayerState*, f32[3]);
void func_80092C48(PlayerState*, f32[3]);
void func_80092C90(PlayerState*, f32*, s32);
s32 func_80092CDC(PlayerState*, f32*, s32);
void func_80092D18(PlayerState*, f32*);
void func_80092D44(PlayerState*, f32[3]);
s32 func_80092EA4(PlayerState*);
s32 func_80092EB0(PlayerState*);
void func_80092EC8(PlayerState*, s32);
void func_8009312C(PlayerState*, s32);
void func_800931AC(PlayerState*, s32);
void func_80093230(PlayerState*, f32);
void func_8009328C(PlayerState*, f32);
void func_80093300(PlayerState*, f32);
void func_8009332C(PlayerState*, f32);
void func_80093360(PlayerState*, f32);
void func_80093370(PlayerState*, s32);
void func_8009337C(PlayerState*, s32);
void func_80093388(PlayerState*);
void func_80093448(PlayerState*);
void func_800934C4(PlayerState*);
void func_80093504(PlayerState*, s32, s32);
void func_80093528(PlayerState*);
void func_80093584(PlayerState*); 
void func_800936E8(PlayerState*, s32);
void func_80093700(PlayerState*, s32);
s32 func_80093DF4(PlayerState*, s32);
PlayerState* func_80093F7C(PlayerState*);
s32 func_80094348(PlayerState*, s32);
void func_80094390(PlayerState*);
s32 func_800944E0(PlayerState *, s32);
s32 func_800944F8(PlayerState*, s32);
//Get Current Egg Type

s32 func_80094510(PlayerState *);
void func_80094538(PlayerState*);
void func_80094644(PlayerState*);
void func_800946C4(PlayerState*, s32);
void func_800947EC(PlayerState *, s32, s32);
void func_80094824(PlayerState*);
void func_80094864(PlayerState*);
int func_800949BC(PlayerState*);
s32 func_80094A10(PlayerState*);

//Show amount of eggs for currently selected egg type

void func_80094AB4(PlayerState*);
s32 func_80094B14(PlayerState *);
//Do we have eggs for current type
s32 func_80094BC0(PlayerState *);
s32 func_80094C64(PlayerState*, s32);
void func_80094C88(PlayerState*);
s32 func_80094DA8(PlayerState*);
void func_80094E40(s32);
// This might return a s32 instead of a PlayerState pointer

void *func_800B27E0(void *);

#endif // __CORE2_1E6B900_H__
