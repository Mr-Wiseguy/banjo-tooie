#ifndef __ANIM_H__
#define __ANIM_H__

#include "playerstate.h"
#include "assets.h"
#include "../an/anctrl.h"

typedef enum baanim_update_type_e {
    BAANIM_UPDATE_0_NONE,
    BAANIM_UPDATE_1_NORMAL,
    BAANIM_UPDATE_2_SCALE_HORZ,
    BAANIM_UPDATE_3_SCALE_VERT
} BaAnimUpdateType;

AnimCtrl *func_8008AD80(s32);
f32 func_8008CAC8(PlayerState *self);
AnimCtrl* baanim_getAnimCtrlPtr(PlayerState* arg0);
int  baanim_isAt(PlayerState *, f32);
extern void func_8008CCBC(PlayerState * self, s32 index, f32 duration);
void baanim_playForDuration_onceSmooth(PlayerState* thisx, AssetId anim_id, f32 duration);
void func_8008CF1C(PlayerState *, f32, f32); // baanim_setend

#endif
