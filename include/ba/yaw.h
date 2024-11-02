#ifndef __BA_YAW_H__
#define __BA_YAW_H__

#include <ultra64.h>
#include "playerstate.h" // for PlayerState

typedef enum yaw_type_e{
    YAW_TYPE_0_NONE,
    YAW_TYPE_1_DEFAULT,
    YAW_TYPE_2_UNBOUNDED,
    YAW_TYPE_3_BOUNDED
} YawType;

typedef struct ba_yaw_s {
    f32 value;
    f32 ideal;
    f32 unk8;
    s32 update_type;
    f32 velocity_degPerSec;
    f32 limit_degPerSec;
    f32 step_percent;
} BaYaw;

s32 yaw_size(void);
void yaw_init(PlayerState *self);
void yaw_update(PlayerState *self);
void yaw_setUpdateType(PlayerState *self, YawType type);
void yaw_setIdeal(PlayerState *self, f32 arg1);
void yaw_set(PlayerState *self, f32 arg1);
void yaw_applyIdeal(PlayerState *self);
f32 yaw_get(PlayerState *self);
f32 yaw_getIdeal(PlayerState *self);
void yaw_setVelocityBounded(PlayerState *self, f32 limit_degPerSec, f32 step_percent);
void yaw_setVelocityUnbounded(PlayerState *self, f32 velocity_degPerSec);
void yaw_rotateTimed(PlayerState *self, f32 time_sec);

#endif // __BA_YAW_H__
