#ifndef __CORE2_1E7AB30_H__
#define __CORE2_1E7AB30_H__

#include "common.h"

#include <ultra64.h>

#include "ba/playerstate.h"
#include "ba/timer.h"
#include "gc/sectionDll.h"
#include "core2/1E691A0.h"
#include "core2/1E78170.h"
#include "core2/1E7AB30.h"
#include "core2/1E7BFA0.h"
#include "core2/1EA1DA0.h"
#include "core2/1EA78C0.h"
#include "core2/1EABAC0.h"
#include "core2/1EAD060.h"
#include "core2/1EAD6C0.h"
#include "core2/1EAE6C0.h"
#include "core2/1EB3750.h"
#include "core2/1ECE0B0.h"
#include "core2/1ED37B0.h"
#include "core2/1ED4E30.h"

void func_800A1294(s32);
void func_800A1364();
void func_800A13A0();
void func_800A13B0(s32);
void func_800A1658(s32);
void func_800A1694();
void func_800A16BC(s32);
void func_800A16F4(PlayerState*);
s32 player_getCurrentHealth(PlayerState *);
s32 player_getMaxHealth(PlayerState*);
void player_affectCurrentHealth(PlayerState *, s32);
void func_800A18E8(PlayerState*);
#endif // __CORE2_1E7AB30_H__
