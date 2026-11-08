#ifndef __BA_SPIN_H__
#define __BA_SPIN_H__

#include <ultra64.h>
#include "ba/playerstate.h"

void _baspin_entrypoint_1(PlayerState* self);
void _baspin_entrypoint_2(PlayerState *self, s32, f32, s32, s32);
s32 _baspin_entrypoint_3(PlayerState *self);

#endif // __BA_SPIN_H__
