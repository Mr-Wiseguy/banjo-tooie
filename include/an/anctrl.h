#ifndef __ANIM_CTRL_H__
#define __ANIM_CTRL_H__

#include <ultra64.h>

#include "../ba/assets.h"

typedef struct anctrl_s {
    // TODO populate this struct
    u8 unk0;
} AnimCtrl;

AnimCtrl *func_8008AD80(s32);
void anctrl_setIndex(AnimCtrl *, AssetId);
void anctrl_reset(AnimCtrl *);
void anctrl_setSmoothTransition(AnimCtrl *, s32);
void anctrl_setDuration(AnimCtrl *, f32);
void anctrl_setSubrange(AnimCtrl *, f32, f32);
void func_8008B10C(AnimCtrl *, f32);
int anctrl_isAt(AnimCtrl*, f32);
void anctrl_setStart(AnimCtrl*, f32);
f32 anctrl_getAnimTimer(AnimCtrl*);
void anctrl_start(AnimCtrl*);
s32 anctrl_isStopped(AnimCtrl*);

#endif
