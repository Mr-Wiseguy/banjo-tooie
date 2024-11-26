#ifndef __BA_TIMER_H__
#define __BA_TIMER_H__

#include <ultra64.h>

#include "playerstate.h"

f32 _batimer_entrypoint_4(PlayerState *, s32 id);

s32 _batimer_isLessThan(PlayerState *self, s32 id, f32 inc_value_sec);
int _batimer_decrement(PlayerState *self, s32 id);
void batimer_increment(PlayerState *self,  s32 id);
f32 batimer_get(PlayerState *self, s32 id);
int batimer_isAt(PlayerState *self, s32 id, f32 value_sec);
int batimer_isLessThan(PlayerState *self, s32 id, f32 value_sec);
int batimer_isGreaterThan(PlayerState *self, s32 id, f32 value_sec);
int batimer_isNonzero(PlayerState *self, s32 id);
s32 _batimer_isZero(PlayerState *self, s32 id);
void _batimer_set(PlayerState *self , s32 id, f32 value_sec);

#endif 
