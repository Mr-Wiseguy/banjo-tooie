#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/physics.h"

#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"
#include "core2/1ECE0B0.h"
#include "core2/1EB5E70.h"

extern f32 func_80013970(f32);

#define BAANIM_BIGHEAD 0x4
#define BAANIM_SMALLHEAD 0x8
#define BAANIM_LONGBODY 0x10
#define BAANIM_BIGKAZOOIEHEAD 0x20
#define BAANIM_BIGWINGS 0x40
#define BAANIM_WISHYWASHY 0x80

f32 D_80117C70[3] = {0.0f, 5.0f, 0.0f};
s32 D_80117C7C[7] = { //bottles bonus modification
    BAANIM_BIGHEAD, 
    0x2 | 0x1, 
    BAANIM_BIGWINGS | BAANIM_BIGKAZOOIEHEAD, 
    BAANIM_LONGBODY | BAANIM_SMALLHEAD, 
    BAANIM_LONGBODY | BAANIM_SMALLHEAD | 0x2 | 0x1,
    BAANIM_BIGWINGS | BAANIM_BIGKAZOOIEHEAD | BAANIM_BIGHEAD | 0x2 | 0x1, 
    BAANIM_WISHYWASHY
};

s32 baanim_get_size(void) {
    return sizeof(BaAnim);
}

void __baanim_update_scaleToHorizontalVelocity(PlayerState * self) {
    f32 velocity[3];
    f32 speed;
    f32 scale;
    f32 sp30;
    f32 sp2C;
    
    scale = (self->anim->scalable_duration) ?  self->anim->duration_scale : 1.0f;
    func_8009BB24(self, velocity);
    speed = sqrtf(velocity[0]*velocity[0] + velocity[2]*velocity[2]);
    sp30 = func_800F1198(speed, 
        self->anim->speed_min, self->anim->speed_max,
        self->anim->duration_relative_min * scale, self->anim->duration_relative_max * scale
    );
    sp2C = func_800F0D50(sp30, self->anim->duration_min, self->anim->duration_max);
    anctrl_setDuration(self->anim->anctrl, sp2C);
    func_8008ADE4(self->anim->anctrl);
}

void __baanim_update_scaleToVerticalVelocity(PlayerState *self) {
    f32 speed;
    f32 sp20;
    f32 sp1C;

    speed = mlAbsF(baphysics_get_vertical_velocity(self));
    sp20 = func_800F1198(speed, 
        self->anim->speed_min, self->anim->speed_max,
        self->anim->duration_relative_min, self->anim->duration_relative_max
    );
    sp1C = func_800F0D50(sp20, self->anim->duration_min, self->anim->duration_max);
    anctrl_setDuration(self->anim->anctrl, sp1C);
    func_8008ADE4(self->anim->anctrl);
}

void __baanim_oscillateScale(f32 dst[3], f32 x, f32 min, f32 osc_size) {
    s32 phi_s0;

    for(phi_s0 = 0; phi_s0 < 3; phi_s0++){
        dst[phi_s0] = min + osc_size*(0.5f + 0.5f * func_80013970((360.0f)*func_800F0F9C(x + (2.0f * ((f32) phi_s0 / 3.0f)), 2.0f)));
    };
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/baanim/__baanim_applyBottlesBonus.s")
#else
void __baanim_applyBottlesBonus(s32 arg0, s32 arg1) {
    PlayerState *self = func_800F53D0(arg1);
    f32 sp2C[3];
    f32 sp28;
    static s32 D_80126CD0;
    
    func_80098218(self, arg0);
    func_800DFC20(arg0, self->anim->unkE, self->anim->unk10);
    if (self->anim->unkC) {
        func_800EFD24(sp2C);
        func_800DFFA0(arg0, self->anim->unkE, sp2C);
    }
    sp28 = func_800A8258();

    if (D_80126CD0 & 1) {
        __baanim_oscillateScale(sp2C, sp28, 2.0f, 1.0f);
        func_800DFF64(arg0, 0x6, sp2C);
        func_800DFF64(arg0, 0x14, sp2C);
    }
    if (D_80126CD0 & 2) {
        __baanim_oscillateScale(sp2C, sp28, 2.0f, 1.0f);
        func_800DFF64(arg0, 0x10, sp2C);
        func_800DFF64(arg0, 0x1E, sp2C);
    }
    if (D_80126CD0 & BAANIM_BIGHEAD) {
        __baanim_oscillateScale(sp2C, sp28, 2.0f, 1.0f);
        func_800DFF64(arg0, 0x12, sp2C);
    }
    if (D_80126CD0 & BAANIM_SMALLHEAD) {
        __baanim_oscillateScale(sp2C, sp28, 0.2f, 0.5f);
        func_800DFF64(arg0, 0x12, sp2C);
    }
    if (D_80126CD0 & BAANIM_LONGBODY) {
        func_800DFFA0(arg0, 1, D_80117C70);
    }
    if (D_80126CD0 & BAANIM_BIGKAZOOIEHEAD) {
        __baanim_oscillateScale(sp2C, sp28, 2.0f, 1.0f);
        func_800DFF64(arg0, 0x6C, sp2C);
    }
    if (D_80126CD0 & BAANIM_BIGWINGS) {
        __baanim_oscillateScale(sp2C, sp28, 2.0f, 1.0f);
        func_800DFF64(arg0, 0x64, sp2C);
        func_800DFF64(arg0, 0x67, sp2C);
    }
    if (func_8010FFD8(func_800A4C88(self))) {
        __baanim_oscillateScale(sp2C, sp28, 0.9f, 0.2f);
        func_800DFF64(arg0, self->anim->unkE, sp2C);
    }
    if (self->anim->unk4 != NULL) {
        self->anim->unk4(arg0, arg1);
    }

}
#endif

void baanim_init(PlayerState *self) {
    self->anim->unk3C = NULL;
    self->anim->anctrl = func_8008AD80(1);
    anctrl_setSmoothTransition(self->anim->anctrl, 0);
    self->anim->unk4 = NULL;
    func_8008B304(self->anim->anctrl);
    func_8008AEE4(self->anim->anctrl, __baanim_applyBottlesBonus);
    func_8008AF04(self->anim->anctrl, self->unk184);
    self->anim->state = 0;
    func_8008CA4C(self, 1);
    baanim_setDurationRange(self, 0.01f, 100.0f);
    func_8008C9F0(self, 0.0f, 1000.0f, 0.1f, 10.0f);
    func_8008C9E4(self, 0);
    func_8008C984(self, 3);
    self->anim->scalable_duration = 0;
    self->anim->duration_scale = 1.0f;

}

void baanim_free(PlayerState *self) {
    func_8008ADBC(self->anim->anctrl);
    func_8008CFF0(self);
}

void baanim_update(PlayerState *self) {
    switch(self->anim->state){
        case BAANIM_UPDATE_2_SCALE_HORZ:
            __baanim_update_scaleToHorizontalVelocity(self);
            break;
        
        case BAANIM_UPDATE_3_SCALE_VERT:
            __baanim_update_scaleToVerticalVelocity(self);
            break;

        case BAANIM_UPDATE_1_NORMAL:
            func_8008ADE4(self->anim->anctrl);
            break;

        case BAANIM_UPDATE_4_UNKOWN:
            func_8008ADE4(self->anim->anctrl);
            func_8008ADE4(self->anim->unk3C);
            break;

        case BAANIM_UPDATE_0_NONE:
            break;
    }
}

void baanim_defrag(PlayerState *self) {
    self->anim->anctrl = func_8008AEB4(self->anim->anctrl);
}

void func_8008C958(PlayerState *self, f32 arg1[3]) {
    func_800EE7F8(arg1, self->anim->unk10);
}

void func_8008C984(PlayerState *self, s32 arg1) {
    self->anim->unkE = arg1;
}

void func_8008C990(PlayerState *self, f32 arg1) {
    func_8008B10C(self->anim->anctrl, arg1);
}

void baanim_setDurationRange(PlayerState *self, f32 min, f32 max) {
    self->anim->duration_min = min;
    self->anim->duration_max = max;
}

void func_8008C9D8(PlayerState *self, void (*arg1)(s32, s32)) {
    self->anim->unk4 = arg1;
}

void func_8008C9E4(PlayerState *self, s32 arg1) {
    self->anim->unkC = arg1;
}

void func_8008C9F0(PlayerState *self, f32 speed_min, f32 speed_max, f32 duration_min, f32 duration_max) {
    self->anim->speed_min = speed_min;
    self->anim->speed_max = speed_max;
    self->anim->duration_relative_min = duration_min;
    self->anim->duration_relative_max = duration_max;
    self->anim->scalable_duration = 0;
}

void func_8008CA30(PlayerState *self, f32 scale) {
    self->anim->duration_scale = scale;
    self->anim->scalable_duration = 1;
}

void func_8008CA4C(PlayerState *self, BaAnimUpdateType arg1) {
    if ((self->anim->unk3C != NULL) && (arg1 == 1)) {
        arg1 = BAANIM_UPDATE_4_UNKOWN;
    }
    self->anim->state = arg1;
}

s32 func_8008CA74(PlayerState *self) {
    return func_8008B4D4(self->anim->anctrl);
}

void func_8008CA98(PlayerState *self) {
    func_8008B304(self->anim->anctrl);
}

AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *self) {
    return self->anim->anctrl;
}

f32 baanim_getTimer(PlayerState *self) {
    return anctrl_getAnimTimer(self->anim->anctrl);
}

int baanim_isStopped(PlayerState *self) {
    return anctrl_isStopped(self->anim->anctrl);
}

int baanim_isAt(PlayerState *self, f32 time) {
    return anctrl_isAt(self->anim->anctrl, time);
}

void baanim_playForDuration_loopSmooth(PlayerState *self, AssetId anim_id, f32 duration) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setPlaybackType(self->anim->anctrl, 2);
    anctrl_start(self->anim->anctrl);
}

void baanim_playForDuration_loop(PlayerState *self, AssetId anim_id, f32 duration) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setSmoothTransition(self->anim->anctrl, 0);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setPlaybackType(self->anim->anctrl, 2);
    anctrl_start(self->anim->anctrl);
}

void baanim_playForDuration_loopStartingAt(PlayerState *self, AssetId anim_id, f32 duration, f32 start) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setStart(self->anim->anctrl, start);
    anctrl_setPlaybackType(self->anim->anctrl, 2);
    anctrl_start(self->anim->anctrl);
}

void baanim_playForDuration_onceSmooth(PlayerState *self, AssetId anim_id, f32 duration) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setPlaybackType(self->anim->anctrl, 1);
    anctrl_start(self->anim->anctrl);
}

void baanim_playForDuration_onceSmoothStartingAt(PlayerState *self, AssetId anim_id, f32 duration, f32 start) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setStart(self->anim->anctrl, start);
    anctrl_setPlaybackType(self->anim->anctrl, 1);
    anctrl_start(self->anim->anctrl);
}

void baanim_playForDuration_once(PlayerState* self, AssetId anim_id, f32 duration) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setSmoothTransition(self->anim->anctrl, 0);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setPlaybackType(self->anim->anctrl, 1);
    anctrl_start(self->anim->anctrl);
}

void baanim_playForDuration_onceStartingAt(PlayerState *self, AssetId anim_id, f32 duration, f32 start) {
    anctrl_reset(self->anim->anctrl);
    anctrl_setSmoothTransition(self->anim->anctrl, 0);
    anctrl_setIndex(self->anim->anctrl, anim_id);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setStart(self->anim->anctrl, start);
    anctrl_setPlaybackType(self->anim->anctrl, 1);
    anctrl_start(self->anim->anctrl);
}

void baanim_setEnd(PlayerState *self, f32 end_position) {
    anctrl_setSubrange(self->anim->anctrl, 0.0f, end_position);
    anctrl_setPlaybackType(self->anim->anctrl, 1);
}

void baanim_setEndAndDuration(PlayerState *self, f32 end_position, f32 duration) {
    anctrl_setSubrange(self->anim->anctrl, 0.0f, end_position);
    anctrl_setDuration(self->anim->anctrl, duration);
    anctrl_setPlaybackType(self->anim->anctrl, 1);
}

void func_8008CF7C(PlayerState *self) {
    if (self->anim->unk3C != NULL) {
        return;
    }
    self->anim->unk3C = func_8008AD80(1);
    anctrl_setSmoothTransition(self->anim->unk3C, 0);
    if (self->anim->state == BAANIM_UPDATE_1_NORMAL) {
        self->anim->state = BAANIM_UPDATE_4_UNKOWN;
    }
}

void func_8008CFF0(PlayerState *self) {
    if (self->anim->unk3C != NULL) {
        func_8008ADBC(self->anim->unk3C);
    }
    self->anim->unk3C = NULL;
    if (self->anim->state == BAANIM_UPDATE_4_UNKOWN) {
        self->anim->state = BAANIM_UPDATE_1_NORMAL;
    }
}

AnimCtrl *func_8008D04C(PlayerState *self) {
    return self->anim->unk3C;
}

void func_8008D058(PlayerState *self) {
    func_8008B304(self->anim->unk3C);
    func_800DF41C(func_8008B4D4(self->anim->unk3C));
}
