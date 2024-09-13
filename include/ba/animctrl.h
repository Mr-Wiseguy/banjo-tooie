#ifndef __ANIM_CTRL_H__
#define __ANIM_CTRL_H__

#include <ultra64.h>

typedef struct animctrl_s {
    // TODO populate this struct
    u8 unk0;
} AnimCtrl;

// TODO rename these symbols
#define animctrl_isAt func_8008B348
#define animctrl_setStart func_8008B24C
#define animctrl_getAnimTimer func_8008B2B4
#define animctrl_start func_8008B064

int animctrl_isAt(AnimCtrl*, f32);
void animctrl_setStart(AnimCtrl*, f32);
f32 animctrl_getAnimTimer(AnimCtrl*);
void animctrl_start(AnimCtrl*);

#endif
