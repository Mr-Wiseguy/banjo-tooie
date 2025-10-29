#ifndef __BA_DRONE_H__
#define __BA_DRONE_H__

#include "overlays/ba/playerstate.h"
#include "overlays/bs/state.h"

extern s32 _badrone_entrypoint_3(PlayerState *self);
extern void _badrone_entrypoint_11(PlayerState*, void*, s32);
extern BanjoStateId _badrone_entrypoint_23(PlayerState *self, f32[3]);
extern BanjoStateId _badrone_entrypoint_24(PlayerState *self);
extern BanjoStateId _badrone_entrypoint_25(PlayerState *self);
s32 _badrone_entrypoint_30(PlayerState *self);

#endif // __BA_DRONE_H__
