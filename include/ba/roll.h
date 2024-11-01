#ifndef __BA_ROLL_H__
#define __BA_ROLL_H__

#include <ultra64.h>

#include "ba/playerstate.h"

// Definitions
s32 baroll_getStructSize(void);
void baroll_reset(PlayerState *self);
void baroll_update(PlayerState *self);
void baroll_setIdeal(PlayerState *self, f32 arg1);
void baroll_set(PlayerState *self, f32 arg1);
void baroll_applyIdeal(PlayerState *self);
f32 baroll_get(PlayerState *self);
f32 baroll_getIdeal(PlayerState *self);
void baroll_setAngularVelocity(PlayerState *self, f32 limit, f32 rate);
void baroll_resetAngularVelocity(PlayerState *self);

#endif // __BA_ROLL_H__
