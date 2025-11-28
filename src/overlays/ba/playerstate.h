#ifndef __BANJOSTATE_H__
#define __BANJOSTATE_H__

#include <ultra64.h>

#include "buttons.h"

typedef struct ba_unknown_c_s {
    u8 pad0[0xC];
    s32 unkC[3];
    u8 pad18[4];
} BaUnknownC;

typedef struct ba_unknown_2C_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC[3];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} BaUnknown2C;

typedef struct player_state_s {
    /* 0x00 */ struct ba_alarm_s *alarm;
    /* 0x04 */ struct ba_anim_s *anim;
    /* 0x08 */ struct ba_attach_s *attach;
    /* 0x0C */ struct ba_unknown_c_s *unkC; // baavatar? from BK XBox debug strings?
    /* 0x10 */ struct ba_babykaz_s *babykaz;
    /* 0x14 */ struct ba_backpack_s *backpack;
    u8 pad18[0x4];
    /* 0x1C */ struct ba_bee_s *bee;
    /* 0x20 */ struct ba_unknown_20_s *unk20;
    /* 0x24 */ struct ba_boost_s *boost;
    /* 0x28 */ struct ba_bounce_s *bounce;
    /* 0x2C */ struct ba_unknown_2C_s *unk2C; //something with camera
    u8 pad30[0x4];
    /* 0x34 */ struct ba_buzz_s *buzz;
    u8 pad38[0x4];
    /* 0x3C */ struct ba_state_timer_list_s *state_timer; // clock?
    /* 0x40 */ struct ba_key_s *key; // controller?
    /* 0x44 */ struct ba_cough_s *cough;
    u8 pad48[0x38];
    /* 0x80 */ struct ba_flag_s *flag;
    u8 pad84[0x18];
    /* 0x9C */ struct ba_unk_9C* unk9C;
    u8 padA0[0x4];
    /* 0xA4 */ struct ba_input_s *input;
    u8 padA8[0x18];
    /* 0xC0 */ struct ba_unknown_C0_s *unkC0; // 1E72EA0
    u8 padC4[0x30];
    /* 0xF4 */ struct ba_roll_s *roll;
    /* 0xF8 */ struct ba_yaw_s *yaw;
    u8 padFC[0x24];
    /* 0x120 */ struct bs_state_s *state;
    u8 pad124[4];
    /* 0x128 */ struct ba_stick_s *stick;
    u8 pad12C[0x10];
    /* 0x13C */ struct ba_timer_s *timer;
    /* 0x140 */ struct ba_translate_s *translate;
    /* 0x144 */ struct ba_van_s *van;
    /* 0x148 */ struct ba_wandglow_s *wandglow;
    /* 0x14C */ struct ba_washer_s *washer;
    u8 pad150[0x4];
    /* 0x154 */ struct ba_wobble_s *wobble;
    u8 pad158[0x4];
    union {
        s32 word;
        u8 bytes[4];
    } unk15C; // Some sort of state
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    union {
        s32 word;
        u8 bytes[4];
    } unk164;
    union {
        s32 word;
        u8 bytes[4];
    } unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0xC];
    s32 unk184;
    /* 0x188 */ struct bs_kazfly_s *kazfly;
} PlayerState;

#endif
