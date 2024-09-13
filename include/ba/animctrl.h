#ifndef __ANIM_CTRL_H__
#define __ANIM_CTRL_H__

#include <ultra64.h>

typedef struct animctrl_s {
    // TODO populate this struct
    u8 unk0;
} AnimCtrl;

int animctrl_isAt(AnimCtrl*, f32);
void animctrl_setStart(AnimCtrl*, f32);
f32 animctrl_getAnimTimer(AnimCtrl*);
void animctrl_start(AnimCtrl*);

#endif
