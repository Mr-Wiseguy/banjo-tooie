#ifndef __BA_TIMER_H__
#define __BA_TIMER_H__

#include <ultra64.h>

#include "overlays/ba/playerstate.h"

#define BA_TIMER_COUNT 15

typedef struct ba_timer_s {
    f32 unk0[BA_TIMER_COUNT];
    f32 unk3C[BA_TIMER_COUNT];
} BaTimer;


void batimer_increment(PlayerState *self,  s32 id);
f32 batimer_get(PlayerState *self, s32 id);

int batimer_isAt(PlayerState *self, s32 id, f32 value_sec);
int batimer_isLessThan(PlayerState *self, s32 id, f32 value_sec);
int batimer_isGreaterThan(PlayerState *self, s32 id, f32 value_sec);
int batimer_isNonzero(PlayerState *self, s32 id);

int _batimer_decrement(PlayerState *self, s32 id);
f32 _batimer_get(PlayerState *, s32 id);
void _batimer_set(PlayerState *self , s32 id, f32 value_sec);
int _batimer_isLessThan(PlayerState *self, s32 id, f32 value_sec);
int _batimer_isZero(PlayerState *self, s32 id);
int _batimer_isAt_falling(PlayerState *self, s32 id, f32 value_sec);

#endif 
