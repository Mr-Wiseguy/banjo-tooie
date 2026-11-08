#ifndef __CORE2_1E75920_H__
#define __CORE2_1E75920_H__

#include <ultra64.h>

#include "ba/playerstate.h"
#include "core2/1EC8070.h"


s32 func_8009C030();

//Clear Position History
void func_8009C038(PlayerState*);

void func_8009C08C(PlayerState*);
void func_8009C0BC(PlayerState*, f32*);

//Set Player Coordinates
void player_setCoords(PlayerState*, f32[3]);

//Set Player Vertical
void player_setCoordVertical(PlayerState*, f32);

//Get_Player_Coordinates
void player_getCoords(PlayerState *, f32[3]);

//Get Player Vertical Coordinate
f32 player_getCoordVertical(PlayerState*);

void func_8009C15C(PlayerState*, f32[3]);

//Get Older Player Coordinates
void func_8009C188(PlayerState*, f32*);

//Add Vertical to Player
void func_8009C1B4(PlayerState*, f32);
void func_8009C1CC(PlayerState*, f32*);
void func_8009C1F8(PlayerState *, f32[3]);

//Decay Position To Storage
void func_8009C21C(PlayerState*);
void func_8009C25C(PlayerState*);

#endif // __CORE2_1E75920_H__
