#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "overlays/ba/playerstate.h"

extern s32 player_inWater(PlayerState *self);
extern s32 player_isStable(PlayerState *self);

#endif // __PLAYER_H__
