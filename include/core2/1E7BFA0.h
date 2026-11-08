#ifndef __CORE2_1E7BFA0_H__
#define __CORE2_1E7BFA0_H__

#include "common.h"
#include "transformations.h"
#include "ba/playerstate.h"
#include "core2/1E6F080.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/physics.h"
#include "ba/shake.h"
#include "ba/shoes.h"
#include "ba/snowball.h"
#include "ba/snowll.h"
#include "ba/statetimer.h"
#include "core2/1E66990.h"
#include "core2/1E691A0.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78170.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E93440.h"
#include "core2/1E99980.h"
#include "core2/1EAD060.h"
#include "core2/1EAD6C0.h"
#include "core2/1EB2840.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECD170.h"
#include "core2/1ECE0B0.h"
#include "core2/anctrl.h"
#include "fx/splash.h"
#include "player.h"

void func_800A2CE8(PlayerState *, f32, s32);
void func_800A2D2C(PlayerState *, f32, s32);
void func_800A2D70(PlayerState*);
void func_800A2D94(PlayerState*);
void func_800A2E18(PlayerState*);
void func_800A2EAC(PlayerState*);
void func_800A2EDC(PlayerState*, f32);
void func_800A2EEC(PlayerState*, s32);
void func_800A2FCC(PlayerState*, s32);
void func_800A300C(PlayerState*);
f32 player_getSpeedModifier(PlayerState*);
void func_800A3148(PlayerState*, f32*, f32*, f32*);
TransformationId player_getTransformation(PlayerState *);
s32 func_800A3280();
f32 func_800A3298(PlayerState *);
void func_800A32C4(PlayerState *, f32[3]);
Unk80132ED0* func_800A32F8(PlayerState*);
s32 bs_isBKTogether(PlayerState*);
f32 func_800A3378(PlayerState*);
f32 func_800A3394(PlayerState *);
void func_800A33A0(PlayerState*, f32*);
void func_800A33CC(PlayerState*, f32*);
void player_setTransformation(PlayerState *, TransformationId);
void func_800A34AC(PlayerState *, f32[3]);
void func_800A34D8(PlayerState*, s32);
void func_800A3538(PlayerState*,s32);
void func_800A3820(PlayerState*);
void func_800A38F0(PlayerState *, s32, s32);
void func_800A3904(PlayerState *, s32);
void func_800A3A80(PlayerState*);
s32 func_8009FA20(PlayerState*, f32*, f32, f32, f32);

#endif // __CORE2_1E7BFA0_H__
