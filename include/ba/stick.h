#ifndef __BA_STICK_H__
#define __BA_STICK_H__

#include <ultra64.h>

#include "playerstate.h"

f32 bastick_getAngle(PlayerState *self);
f32 bastick_getAngleRelativeToBanjo(PlayerState *self);
s32 bastick_func_8009EEF8(PlayerState *self);
f32 bastick_distance(PlayerState *);
s32 bastick_getZone(PlayerState *self);
f32 bastick_getZonePosition(PlayerState *self);
f32 bastick_getX(PlayerState *self);
f32 bastick_getY(PlayerState *self);
void bastick_popZone(PlayerState *self);
void bastick_pushZone(PlayerState *self);
void bastick_update(PlayerState *self);
void bastick_reset(PlayerState *self);
void bastick_func_8009F18C(PlayerState *self, s32 arg1);
void bastick_func_8009F198(PlayerState *self, s32 arg1);
s32 bastick_func_8009F1A4(PlayerState *self);
void bastick_setZoneMax(PlayerState *self, s32 zone_id , f32 value);
void bastick_resetZones(PlayerState *self);

#endif // __BA_STICK_H__
