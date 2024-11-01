#ifndef __BANJOSTATE_H__
#define __BANJOSTATE_H__

#include <ultra64.h>

#include "buttons.h"

// TODO validate that the rest of these state
typedef enum bs_e {
    BS_1_IDLE = 0x1,
    BS_2_SLOW_WALK = 0x2,

    BS_CROUCH = 0x7,
    
    BS_F_BBUSTER = 0xF,

    BS_20_LANDING = 0x20,

    BS_2F_FALL = 0x2F,

    BS_3D_FALL_TUMBLING = 0x3D,

    BS_4C_LANDING_IN_WATER = 0x4C,

    BS_B6_BILL_DRILL = 0xB6
} BanjoStateId;

typedef struct player_yaw_s {
    f32 value;
    f32 ideal;
    f32 unk8;
    s32 update_type;
    f32 velocity_degPerSec;
    f32 limit_degPerSec;
    f32 step_percent;
} PlayerYaw;

typedef struct ba_stick_0_s {
    f32 position;
    s32 id;
    f32 markers[5];
} BaStickZone;

typedef struct ba_stick_s {
    BaStickZone stored_zones[2];
    BaStickZone zone;
    f32 value[2];
    f32 angle;
    f32 distance;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
} BaStick;

typedef struct player_state_s {
    u8 pad0[0xF8];
    PlayerYaw *yaw; // 0xF8
    u8 padFC[0x2C];
    BaStick *stick; // 0x128
    u8 pad12C[0x30];
    union {
        s32 word;
        u8 bytes[4];
    } unk15C;
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    s32 unk164;
    u8 pad168[4];
    f32 unk16C;
    f32 unk170;
} PlayerState;

void func_80098140(PlayerState* thisx, s32, s32);
s32 func_80094510(PlayerState* thisx);
s32 button_held(PlayerState*, ButtonId);

#endif
