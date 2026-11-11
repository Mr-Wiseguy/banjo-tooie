#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <ultra64.h>
#include "ba/playerstate.h"

extern int player_inWater(PlayerState *self);
extern int player_isStable(PlayerState *self);

#endif // __PLAYER_H__
