#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <ultra64.h>
#include "overlays/ba/playerstate.h"

extern s32 player_inWater(PlayerState *self);
extern s32 player_isStable(PlayerState *self);

#endif // __PLAYER_H__
