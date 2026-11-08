#ifndef __CORE2_1E66990_H__
#define __CORE2_1E66990_H__

#include <ultra64.h>

#include "common.h"

#include "core2/1E691A0.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1E77A20.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1EA0690.h"
#include "core2/1EA1DA0.h"
#include "core2/1EB3750.h"
#include "core2/1EB45C0.h"
#include "core2/1EC3810.h"
#include "core2/1EC9740.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECE0B0.h"
#include "ba/duo.h"
#include "ba/fpctrl.h"
#include "nc/ba/1p.h"

#include "ba/flag.h"
#include "ba/physics.h"

#include "ba/playerstate.h"
#include "ba/drone.h"
#include "gc/mapsects.h"

int player_canBeakBarge(PlayerState*);
int player_canBeakBomb(PlayerState *);
int player_canBeakBust(PlayerState*);
int func_8008D18C(PlayerState*);
int player_canPeck(PlayerState*);
int player_canClimb(PlayerState*);
int player_canDive(PlayerState*);
s32 player_canEggShoot(PlayerState*);
int player_canFeatheryFlap(PlayerState*);
int player_canFlapFlip(s32);
int player_canFly(PlayerState *);
int player_shouldRejoin(PlayerState* self);
s32 player_canFullJump(PlayerState *);
int player_canPackWhack(PlayerState*);
int player_canRataTatRap(PlayerState*);
s32 func_8008D630(PlayerState*);
int player_canRoll(s32);
int player_canShockSpring(PlayerState*);
int player_canSplitUp(PlayerState*);
int player_canWadingBoots(PlayerState*);
int player_canSwap(PlayerState *);
s32 player_canTalonTorpedo(PlayerState*);
int player_canTalonTrot(PlayerState*);
int player_canTalonTrot_dupe(PlayerState*);
int player_canWonderwing(PlayerState*);
s32 func_8008D9A4(PlayerState*);
int player_canGripGrab(PlayerState*);
s32 func_8008DAA8(PlayerState*);
s32 func_8008DAC8(s32);
s32 func_8008DAE8(PlayerState*, f32*, f32); 
int func_8008DC90(PlayerState*, f32*, f32);
int func_8008DD04(PlayerState *);
s32 func_8008DD70(PlayerState*);
s32 func_8008DD90(PlayerState*);
s32 func_8008DDEC(PlayerState*, f32*, f32);
s32 func_8008DE24(PlayerState *);
s32 func_8008DE44(s32);
s32 func_8008DE74(PlayerState*);
int func_8008DEA4(PlayerState*, f32*, f32);
int func_8008DF18(PlayerState *);
int func_8008DF8C(PlayerState *, s32);
int player_isStable(PlayerState*);
s32 func_8008E0C8(PlayerState*);
int func_8008E0E8(PlayerState*);
s32 func_8008E124(PlayerState*);
int func_8008E148(PlayerState*);
s32 func_8008E1A0(PlayerState*);
int func_8008E1C4(PlayerState*);
//Are we Solo Banjo
s32 player_isSplitUp(PlayerState *);
s32 func_8008E260(PlayerState*);
// func_8008E2AC
int func_8008E300(PlayerState*); 
int player_inWater(PlayerState*);
s32 func_8008E37C(PlayerState*);
int func_8008E39C(PlayerState*);
s32 player_wearingTurboTrainers(PlayerState*);
s32 player_wearingClawClambers(PlayerState*);
s32 player_wearingSpringyStep(PlayerState*);
s32 func_8008E454(PlayerState*);

#endif // __CORE2_1E66990_H__
