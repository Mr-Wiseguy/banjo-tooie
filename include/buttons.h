#ifndef __BUTTONS_H__
#define __BUTTONS_H__

// These button IDs are an enum, rather than a bitmask like the libultra ones.
typedef enum button_e {
    /* 0x00 */ BUTTON_START,
    /* 0x01 */ BUTTON_Z,
    /* 0x02 */ BUTTON_L,
    /* 0x03 */ BUTTON_R,
    /* 0x04 */ BUTTON_D_UP, 
    /* 0x05 */ BUTTON_D_DOWN, 
    /* 0x06 */ BUTTON_D_LEFT,
    /* 0x07 */ BUTTON_D_RIGHT,
    /* 0x08 */ BUTTON_A,
    /* 0x09 */ BUTTON_B,
    /* 0x0A */ BUTTON_C_LEFT,
    /* 0x0B */ BUTTON_C_DOWN,
    /* 0x0C */ BUTTON_C_UP,
    /* 0x0D */ BUTTON_C_RIGHT,
    /* 0x0E */ BUTTON_COUNT
} ButtonId;

#endif
