#ifndef __ANIM_H__
#define __ANIM_H__

#include "overlays/ba/playerstate.h"
#include "overlays/ba/assets.h"
#include "core2/anctrl.h"

typedef enum baanim_update_type_e {
    BAANIM_UPDATE_0_NONE,
    BAANIM_UPDATE_1_NORMAL,
    BAANIM_UPDATE_2_SCALE_HORZ,
    BAANIM_UPDATE_3_SCALE_VERT,
    BAANIM_UPDATE_4_UNKOWN
} BaAnimUpdateType;

typedef struct ba_anim_s {
    AnimCtrl *anctrl;
    void (*unk4)(s32, s32);
    s32 state;
    u8 unkC;
    // u8 padD;
    s16 unkE;
    f32 unk10[3];
    f32 duration_min;
    f32 duration_max;
    f32 speed_min;
    f32 speed_max;
    f32 duration_relative_min;
    f32 duration_relative_max;
    f32 duration_scale;
    u8 scalable_duration;
    AnimCtrl *unk3C;
} BaAnim;

s32 baanim_get_size(void);
void __baanim_applyBottlesBonus(s32 arg0, s32 arg1);
void baanim_init(PlayerState *self);
void baanim_free(PlayerState *self);
void baanim_update(PlayerState *self);
void baanim_defrag(PlayerState *self);
void func_8008C958(PlayerState *self, f32 arg1[3]);
void func_8008C984(PlayerState *self, s32 arg1);
void func_8008C990(PlayerState *self, f32 arg1);
void baanim_setDurationRange(PlayerState *self, f32 min, f32 max);
void func_8008C9D8(PlayerState *self, void (*arg1)(s32, s32));
void func_8008C9E4(PlayerState *self, s32 arg1);
void func_8008C9F0(PlayerState *self, f32, f32, f32, f32);
void func_8008CA30(PlayerState *self, f32 scale);
void func_8008CA4C(PlayerState *self, BaAnimUpdateType arg1);
s32 func_8008CA74(PlayerState *self);
void func_8008CA98(PlayerState *self);
AnimCtrl* baanim_getAnimCtrlPtr(PlayerState* self);
f32 baanim_getTimer(PlayerState *self);
int baanim_isStopped(PlayerState *self);
int  baanim_isAt(PlayerState *self, f32 timer);
void baanim_playForDuration_loopSmooth(PlayerState *self, AssetId anim_id, f32 duration);
void baanim_playForDuration_loop(PlayerState *self, AssetId anim_id, f32 duration);
void baanim_playForDuration_loopStartingAt(PlayerState *self, AssetId anim_id, f32 duration, f32 start);
void baanim_playForDuration_onceSmooth(PlayerState *self, AssetId anim_id, f32 duration);
void baanim_playForDuration_onceSmoothStartingAt(PlayerState *self, AssetId anim_id, f32 duration, f32 start);
void baanim_playForDuration_once(PlayerState* self, AssetId anim_id, f32 duration);
void baanim_playForDuration_onceStartingAt(PlayerState *self, AssetId anim_id, f32 duration, f32 start);
void baanim_setEnd(PlayerState *self, f32 end_position);
void baanim_setEndAndDuration(PlayerState *self, f32 end_position, f32 duration);
void func_8008CF7C(PlayerState *self);
void func_8008CFF0(PlayerState *self);
AnimCtrl *func_8008D04C(PlayerState *self);
void func_8008D058(PlayerState *self);

#endif
