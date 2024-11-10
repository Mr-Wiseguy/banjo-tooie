#ifndef __BA_KEY_H__
#define __BA_KEY_H__

#include <ultra64.h>

#include "ba/playerstate.h"

typedef struct ba_input_s {
    u32 enabled;
    u32 __enabled;
    f32 dive_cooldown;
} BaInput;

typedef enum {
    BA_INPUT_0_ROTATE_CAMERA_LEFT,
    BA_INPUT_1_ROTATE_CAMERA_RIGHT,
    BA_INPUT_2_ENTER_FIRST_PERSON,

    BA_INPUT_5_EXIT_FIRST_PERSON = 5
} BaInputId;

s32 bainput_getStructSize(void);
int bainput_should_beak_barge(PlayerState *self);
int bainput_should_beak_bust(PlayerState *self);
int bainput_should_enter_first_person(PlayerState *self);
int baintput_func_80097B28(PlayerState *self);
int baintput_func_80097B4C(PlayerState *self);
int bainput_should_rotate_camera_left(PlayerState *self);
int bainput_should_rotate_camera_right(PlayerState *self);
int bainput_should_exit_first_person(PlayerState *self);
int bainput_should_poop_egg(PlayerState *self);
int baintput_should_shoot_egg(PlayerState *self);
int bainput_func_80097C7C(PlayerState *self);
int bainput_func_80097D28(PlayerState *self);
int baintput_should_feathery_flap(PlayerState *self);
int bainput_func_80097DF4(PlayerState *self);
int bainput_should_flap_flip(PlayerState *self);
int bainput_func_80097E74(PlayerState *self);
int bainput_func_80097EC8(PlayerState *self);
int bainput_func_80097F08(PlayerState *self);
int bainput_should_dive(PlayerState *self);
int bainput_func_80097FB8(PlayerState *self);
s32 bainput_isEnabled(PlayerState *self, BaInputId arg1);
int bainput_func_8009803C(PlayerState *self);
int bainput_should_trot(PlayerState *self);
int bainput_should_wonderwing(PlayerState *self);
void bainput_init(PlayerState *self);
void bainput_enable(PlayerState *self, BaInputId id, s32 value);
void bainput_setDiveCooldown(PlayerState *self, s32 arg1, f32 cooldown);
void bainput_update(PlayerState *self);

#endif // __BA_KEY_H__
