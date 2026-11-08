#ifndef __BS_BEEFLY_H__
#define __BS_BEEFLY_H__

#include <ultra64.h>

#include "common.h"
#include "player.h"

#include "ba/anim.h"
#include "ba/bee.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/playerstate.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/stick.h"

#include "bs/rest.h"
#include "bs/state.h"

#include "ba/boost.h"
#include "ba/buzz.h"
#include "ba/fly.h"
#include "ba/fpctrl.h"

#include "bs/bee.h"

#include "nc/ba/fly.h"

#include "core1/1E2B200.h"

#include "core2/anctrl.h"

#include "core2/1E6B900.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1E76CC0.h"
#include "core2/1E8F430.h"
#include "core2/1E93440.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "core2/1EB5980.h"

// Code
void func_80800000_bsbeefly(PlayerState*);
void func_808000A4_bsbeefly(PlayerState*);
void func_8080010C_bsbeefly(PlayerState*);
void func_808001C4_bsbeefly(PlayerState*);
void func_808002B0_bsbeefly(PlayerState*);
s32 bsbeefly_entrypoint_0(s32);
void func_808002E4_bsbeefly(PlayerState*);
void func_8080039C_bsbeefly(PlayerState*);
void func_80800480_bsbeefly(PlayerState*);
void func_808005B0_bsbeefly(PlayerState*);
void func_80800600_bsbeefly(PlayerState*);
void func_80800708_bsbeefly(PlayerState*);
void func_80800B18_bsbeefly(PlayerState*);
s32 bsbeefly_entrypoint_1(s32);
void func_80800B54_bsbeefly(PlayerState*);
void func_80800BA4_bsbeefly(PlayerState*);
void func_80800BE8_bsbeefly(PlayerState*);
s32 bsbeefly_entrypoint_2(s32);
void func_80800C2C_bsbeefly(PlayerState*);
void func_80800C5C_bsbeefly(PlayerState*);
void func_80800C94_bsbeefly(PlayerState*);
s32 bsbeefly_entrypoint_3(s32);
void func_80800CE0_bsbeefly(PlayerState*);
void func_80800D10_bsbeefly(PlayerState*);
void func_80800D50_bsbeefly(PlayerState*);
s32 bsbeefly_entrypoint_4(s32);

#endif // __BS_BEEFLY_H__
