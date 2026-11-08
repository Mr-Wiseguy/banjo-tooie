#ifndef __BA_DUST_H__
#define __BA_DUST_H__

#include "common.h"

#include "ba/playerstate.h"
#include "ba/physics.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "core1/1E2B200.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E7BFA0.h"
#include "core2/1E93440.h"
#include "core2/1EB5980.h"
#include "core2/1EC8070.h"
#include "fx/dlsmoke.h"

void _badust_entrypoint_1(PlayerState *self);
void _badust_entrypoint_2(PlayerState*, s32*, f32*, f32, f32, f32);
void _badust_entrypoint_3(PlayerState *self, f32, f32);
void _badust_entrypoint_5(PlayerState *self, f32, f32);
void _badust_entrypoint_8(PlayerState*);
void _badust_entrypoint_9(PlayerState *self);
void _badust_entrypoint_10(PlayerState *, f32);
void _badust_entrypoint_11(PlayerState*);
void _badust_entrypoint_13(PlayerState*);

#endif
