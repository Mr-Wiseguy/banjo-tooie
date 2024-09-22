#include <ultra64.h>
#include "ba/playerstate.h"
#include "memory.h"

typedef struct {
    u32 timestamp : 31;
    u32 pressed : 1;
} ButtonState;

typedef struct {
    ButtonState data[BUTTON_COUNT];
} ButtonData;

typedef struct {
    // Counts up every frame.
    u32 counter;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7;
    u8 unk8[BUTTON_COUNT];
    u8 unk16[BUTTON_COUNT];
} unkfunc_800BCE84;

// This array holds the timestamps for each button. The first
// array holds the timestamp that each button was last released and the
// second array holds the timestamp that each button was last pressed.
// The timestamps are encoded as the value of counter when the button's state changed,
// left shifted by 1, and the lowest bit is used to encode whether the button is released (0) or pressed (1).
#define GET_BUTTON_DATA(x) ((ButtonData*)&(x)[1])

// This holds the current analog stick values for the two joystick axes.
#define GET_ANALOG_STICK_VALUES(x) ((f32*)&GET_BUTTON_DATA(x)[(x)->unk4])

void func_800BD138(unkfunc_800BCE84* arg0);
void func_800BD28C(unkfunc_800BCE84* arg0, s32 arg1);

ButtonData* func_800BCCC0(unkfunc_800BCE84* arg0, s32 arg1) {
    return &GET_BUTTON_DATA(arg0)[arg1];
}

f32* func_800BCCD8(unkfunc_800BCE84* arg0) {
    return GET_ANALOG_STICK_VALUES(arg0);
}

u8 func_800BCCF4(unkfunc_800BCE84* arg0) {
    return arg0->unk6;
}

s32 func_800BCCFC(unkfunc_800BCE84* arg0, ButtonId button, s32 arg2) {
    arg2 = arg0->unk4 - arg2;
    arg2 += arg0->unk8[button];
    arg2 %= arg0->unk4;
    
    return func_800BCCC0(arg0, arg2)->data[button].pressed;
}

u32 func_800BCD78(unkfunc_800BCE84* arg0, ButtonId button, s32 arg2) {
    s32 temp_a3;
    u32 start_time;
    u32 end_time;

    temp_a3 = arg2;

    // Needed for matching.
    do {} while (0);

    arg2 = arg0->unk4 - arg2;
    arg2 += arg0->unk8[button];
    arg2 %= arg0->unk4;
    
    start_time = func_800BCCC0(arg0, arg2)->data[button].timestamp;
    if (temp_a3 == 0) {
        end_time = arg0->counter;
    } else {
        end_time = func_800BCCC0(arg0, (arg2 + 1) % arg0->unk4)->data[button].timestamp;
    }
    
    return end_time - start_time;
}

s32 func_800BCE84(unkfunc_800BCE84* arg0, ButtonId button) {
    return func_800BCCC0(arg0, arg0->unk8[button])->data[button].pressed;
}

// Time since released
s32 func_800BCEC0(unkfunc_800BCE84* arg0, ButtonId button) {
    ButtonData* temp_v0;

    temp_v0 = func_800BCCC0(arg0, arg0->unk8[button]);
    if (temp_v0->data[button].pressed) {
        return 0;
    }
    return arg0->counter - temp_v0->data[button].timestamp;
}

// Time since pressed
s32 func_800BCF28(unkfunc_800BCE84* arg0, ButtonId button) {
    ButtonData* temp_v0;

    temp_v0 = func_800BCCC0(arg0, arg0->unk8[button]);
    if (!temp_v0->data[button].pressed) {
        return 0;
    }
    return arg0->counter - temp_v0->data[button].timestamp;
}

// Get joystick values
void func_800BCF90(unkfunc_800BCE84* arg0, f32* joystick_values_out) {
    f32* joystick_values;

    joystick_values = func_800BCCD8(arg0);
    joystick_values_out[0] = joystick_values[0];
    joystick_values_out[1] = joystick_values[1];
}

int func_800BCFC4(unkfunc_800BCE84* arg0, ButtonId button) {
    ButtonData* temp_v0;

    temp_v0 = func_800BCCC0(arg0, arg0->unk8[button]);
    return !temp_v0->data[button].pressed && (arg0->counter - temp_v0->data[button].timestamp) == 1;
}

int func_800BD030(unkfunc_800BCE84* arg0, ButtonId button) {
    ButtonData* temp_v0;

    temp_v0 = func_800BCCC0(arg0, arg0->unk8[button]);
    return temp_v0->data[button].pressed && (arg0->counter - temp_v0->data[button].timestamp) == 1;
}

void func_800BD09C(unkfunc_800BCE84* arg0) {
    heap_free(arg0);
}

unkfunc_800BCE84* func_800BD0BC(unkfunc_800BCE84* arg0) {
    return (unkfunc_800BCE84*)defrag(arg0);
}

unkfunc_800BCE84* func_800BD0DC(s32 arg0) {
    unkfunc_800BCE84* ret = (unkfunc_800BCE84*)heap_alloc(sizeof(unkfunc_800BCE84) + sizeof(ButtonData) * arg0 + sizeof(f32) * 2);
    ret->counter = 0x64;
    ret->unk6 = 0xFF;
    ret->unk5 = 0;
    ret->unk4 = arg0;
    func_800BD138(ret);
    return ret;
}

void func_800BD138(unkfunc_800BCE84* arg0) {
    s32 i;
    s32 j;
    ButtonData* cur_data;

    for (i = 0; i < BUTTON_COUNT; i++) {
        arg0->unk8[i] = 0;
        arg0->unk16[i] = 0;        
    }

    // Clear every button data buffer.
    cur_data = GET_BUTTON_DATA(arg0);
    for (i = 0; i < arg0->unk4; i++) {
        for (j = 0; j < BUTTON_COUNT; j++) {
            cur_data->data[j].pressed = 0;
            cur_data->data[j].timestamp = 0;
        }
        cur_data++;
    }

    // The analog stick values are directly after the button data, so 
    // cur_data points to them after the previous loop. Use this to clear the stick values.
    ((f32*)cur_data)[0] = ((f32*)cur_data)[1] = 0.0f;
}

void func_800BD268(unkfunc_800BCE84* arg0, s32 arg1) {
    arg0->unk6 = arg1;
    func_800BD28C(arg0, 2);
}

void func_800BD28C(unkfunc_800BCE84* arg0, s32 arg1) {
    s32 i;
    arg0->unk5 = arg1;
    if (arg1 == 1) {
        for (i = 0; i < BUTTON_COUNT; i++) {
            arg0->unk16[i] = 0;
        }
    }
}

void func_800BD2D0(unkfunc_800BCE84* arg0) {
    s32 i;
    s32 j;
    s32 sp8C;
    ButtonData* prev_data;
    s32 was_pressed;
    s32 is_pressed;
    s32 sp48[BUTTON_COUNT];

    if (arg0->unk5 == 2) {
        sp8C = arg0->unk6;
        sp48[0] = func_80015F84(arg0->unk6);
        func_80015F28(sp8C, &sp48[1]);
        func_80015FFC(sp8C, &sp48[4]);
        func_80015E80(sp8C, &sp48[8]);
        for (i = 0; i < BUTTON_COUNT; i++) {
            prev_data = func_800BCCC0(arg0, arg0->unk8[i]);
            is_pressed = sp48[i] ? 1 : 0;
            was_pressed = prev_data->data[i].pressed;
            if (is_pressed ^ was_pressed) {
                arg0->unk8[i]++;
                arg0->unk8[i] %= arg0->unk4;
                prev_data = func_800BCCC0(arg0, arg0->unk8[i]);
                prev_data->data[i].timestamp = arg0->counter;
                prev_data->data[i].pressed = is_pressed;
            }
        }
        func_80016068(sp8C, func_800BCCD8(arg0));
    } else if (arg0->unk5 == 1) {
        for (j = 0; j < BUTTON_COUNT; j++) {
            if (arg0->unk16[j] != 0) {
                s32 temp_s3 = func_800BCCC0(arg0, arg0->unk8[j])->data[j].pressed;
                arg0->unk16[j]--;
                if (!arg0->unk16[j]) {
                    arg0->unk8[j] = arg0->unk8[j] + 1;
                    arg0->unk8[j] %= arg0->unk4;
                    prev_data = func_800BCCC0(arg0, arg0->unk8[j]);
                    prev_data->data[j].timestamp = arg0->counter;
                    prev_data->data[j].pressed = temp_s3 ^ 1;
                }
            }
        }
    }
    arg0->counter++;
}
