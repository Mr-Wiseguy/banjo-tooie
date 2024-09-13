#ifndef __BA_PHYSICS_H__
#define __BA_PHYSICS_H__

#include "playerstate.h"
#include "anim.h"

typedef enum ba_physics_type_e {
    BA_PHYSICS_NONE,
    BA_PHYSICS_UNK1,
    BA_PHYSICS_NORMAL,
    BA_PHYSICS_LOCKED_ROTATION,
    BA_PHYSICS_UNK4, 
    BA_PHYSICS_INVERTED_YAW,
    BA_PHYSICS_AIRBORN,
    BA_PHYSICS_FREEZE,
    BA_PHYSICS_UNK8,
    BA_PHYSICS_NO_GRAVITY,
    BA_PHYSICS_CLIMB,
    BA_PHYSICS_TRANSFORM,
    BA_PHYSICS_GOTO,
    BA_PHYSICS_END
} BaPhysicsType;

typedef enum yaw_state_e {
    YAW_STATE_0_NONE,
    YAW_STATE_1_DEFAULT,
    YAW_STATE_2_UNBOUNDED,
    YAW_STATE_3_BOUNDED
} YawState;

// TODO rename these symbols
#define baphysics_set_target_horizontal_velocity func_8009B9B0
#define baphysics_reset_gravity func_8009BC6C
#define yaw_setVelocityBounded func_8009C99C

void baphysics_set_target_horizontal_velocity(PlayerState* thisx, f32 vel);
void baphysics_reset_gravity(PlayerState* thisx);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawState yaw_state, s32 arg2, BaPhysicsType arg3);
void yaw_setVelocityBounded(PlayerState* thisx, f32 arg0, f32 arg1);


#endif
