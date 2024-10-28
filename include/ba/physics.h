#ifndef __BA_PHYSICS_H__
#define __BA_PHYSICS_H__

#include "anim.h"
#include "playerstate.h"
#include "yaw.h" // for YawType

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



void func_8009B94(PlayerState *);
void baphysics_set_vertical_velocity(PlayerState *, f32);
void baphysics_set_target_horizontal_velocity(PlayerState* thisx, f32 vel);
void baphysics_set_target_yaw(PlayerState *this_x, f32 target_yaw);
f32 baphysics_get_target_horizontal_velocity(PlayerState *self);
void baphysics_set_horizontal_velocity(PlayerState *thisx, f32 yaw, f32 vel);
f32  baphysics_get_vertical_velocity(PlayerState *);
void baphysics_reset_gravity(PlayerState* thisx);
void baphysics_reset_terminal_velocity(PlayerState *);
void baphysics_set_gravity(PlayerState *, f32);
void baphysics_set_terminal_velocity(PlayerState *, f32);

void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);

#endif
