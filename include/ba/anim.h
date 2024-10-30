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

int  baanim_isAt(PlayerState *, f32);
AnimCtrl* baanim_getAnimCtrlPtr(PlayerState* arg0);
void baanim_playForDuration_onceSmooth(PlayerState* thisx, AssetId anim_id, f32 duration);
void func_8008CF1C(PlayerState *, f32, f32); // baanim_setend

#endif
