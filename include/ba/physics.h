#ifndef __BA_PHYSICS_H__
#define __BA_PHYSICS_H__

#include "anim.h"
#include "playerstate.h"
#include "yaw.h" // for YawType

typedef enum ba_physics_type_e {
    BA_PHYSICS_0_NONE,
    BA_PHYSICS_1_UNKNOWN,
    BA_PHYSICS_2_NORMAL,
    BA_PHYSICS_3_LOCKED_ROTATION,
    BA_PHYSICS_4_UNKNOWN, 
    BA_PHYSICS_5_INVERTED_YAW,
    BA_PHYSICS_6_AIRBORN,
    BA_PHYSICS_7_FREEZE,
    BA_PHYSICS_8_UNKNOWN,
    BA_PHYSICS_9_NO_GRAVITY,
    BA_PHYSICS_A_CLIMB,
    BA_PHYSICS_B_TRANSFORM,
    BA_PHYSICS_C_GOTO,
    BA_PHYSICS_D_END,
    BA_PHYSICS_E_UNKNOWN
} BaPhysicsType;

void baphysics_set_type(PlayerState *, BaPhysicsType);
void baphysics_set_vertical_velocity(PlayerState *, f32);
void baphysics_set_target_horizontal_velocity(PlayerState* , f32 vel);
void baphysics_set_target_yaw(PlayerState *, f32 target_yaw);
f32 baphysics_get_target_horizontal_velocity(PlayerState *);
void baphysics_set_horizontal_velocity(PlayerState *, f32 yaw, f32 vel);
f32  baphysics_get_vertical_velocity(PlayerState *);
void baphysics_reset_gravity(PlayerState* );
void baphysics_reset_terminal_velocity(PlayerState *);
void baphysics_set_gravity(PlayerState *, f32);
void baphysics_set_terminal_velocity(PlayerState *, f32);

void func_8009B94(PlayerState *);
void func_8009BA9C(PlayerState *, f32 *);
f32 func_8009BADC(PlayerState *);
f32 func_8009BAE8(PlayerState *);
void func_8009BB24(PlayerState *, f32[3]);
f32 func_8009BB5C(PlayerState *);
void func_8009BC34(PlayerState *);
s32 func_8009BCD4(PlayerState *, f32);
void func_8009FFD8(PlayerState *, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);

#endif
