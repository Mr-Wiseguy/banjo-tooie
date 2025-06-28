#include "common.h"

#include "overlays/ba/bounce.h"

#include "overlays/ba/physics.h"
#include "overlays/ba/react.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/timer.h"
#include "core2/1E2B200.h"
#include "core2/1E67DA0.h"
#include "core2/1E6E870.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1ECB0F0.h"
#include "core2/1EDA900.h"

s32 babounce_entrypoint_0(void) {
    return sizeof(BaBounce);
}

void func_80800008_babounce(PlayerState *self, s32 arg1) {
    self->bounce->unkC = arg1;
    if (arg1 == 1) {
        func_8008E95C(self);
    }
}

s32 babounce_entrypoint_1(PlayerState *self) {
    return self->bounce->unkC;
}

int babounce_entrypoint_2(PlayerState *self) {
    return (_bareact_entrypoint_2(self) == 2);
}

void babounce_entrypoint_3(PlayerState *self) {
    if (self->bounce->unkC == 3) {
        func_8009BA9C(self, 0);
    }

    if (self->bounce->unkD == 1) {
        func_800951B4(self);
        func_8009BD88(self);
    }

    baphysics_set_gravity(self, self->bounce->unk14);
    baphysics_set_terminal_velocity(self, self->bounce->unk18);
    func_8008E95C(self);
    if (self->bounce->unk10 != 0) {
        func_8010114C(self->bounce->unk10, 0xA1, 0);
        self->bounce->unk10 = 0;
    }
}

void babounce_entrypoint_4(PlayerState *self, s32 arg1) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp3C[2];
    f32 sp38;
    s32 sp34;

    self->bounce->unk14 = func_8009BADC(self);
    self->bounce->unk18 = func_8009BAE8(self);
    self->bounce->unk10 = 0;
    self->bounce->unkD = arg1;
    switch (arg1) {
        case 1:
            if (func_800A32EC(self) != 3) {
                func_8009D9D4(self);
            }
            func_8009514C(self);
            break;

        case 2:
            func_8009DA40(self);
            break;
    }
    sp34 = func_80099A58(self);
    _bareact_entrypoint_1(self, sp34);
    self->bounce->unk0 = 1.2f;
    self->bounce->unk4 = 1.4f;
    func_800A32C4(self, sp50);
    func_8009C128(self, sp44);
    func_800F1E6C(sp50, sp44, sp3C);
    if ((sp34 == 0xE) || (sp34 == 0x10)) {
        func_80800008_babounce(self, 3);
        func_8009FFD8(self, 1, 1, 2, 1);
        yaw_setIdeal(self, func_800136E4(sp3C[0]));
        self->bounce->unk1C = func_80099A40(self);
        sp38 = func_8009F3BC(self, sp44[1], sp50[1], (sp3C[1] = func_80099A34(self)), self->bounce->unk1C);
        func_800EFB24(sp5C, sp50, sp44);
        sp5C[0] = sp5C[0] / sp38;
        sp5C[2] = sp5C[2] / sp38;
        sp5C[1] = sp3C[1];
        self->bounce->unk8 = sp38;
        func_8009BA9C(self, sp5C);
        _batimer_set(self, 6, sp38);
    } else {
        func_80800008_babounce(self, 2);
        yaw_setIdeal(self, func_800136E4(sp3C[0] + 180.0f));
        baphysics_set_target_horizontal_velocity(self, _bareact_entrypoint_4(self));
        baphysics_set_target_yaw(self, sp3C[0]);
        baphysics_set_horizontal_velocity(self, sp3C[0], baphysics_get_target_horizontal_velocity(self));
        baphysics_set_vertical_velocity(self, _bareact_entrypoint_3(self));
        self->bounce->unk1C = _bareact_entrypoint_5(self);
        func_8009FFD8(self, 1, 1, 2, 3);
        if (_bareact_entrypoint_2(self) == 2) {
            baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
        }
    }
    baphysics_set_gravity(self, self->bounce->unk1C);
    baphysics_reset_terminal_velocity(self);
    yaw_applyIdeal(self);
    func_8008E944(self);
}

void babounce_entrypoint_5(PlayerState *self, AssetId asset_id, f32 arg2) {
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anctrl);
    anctrl_setIndex(anctrl, asset_id);
    if (self->bounce->unkC == 3) {
        anctrl_setDuration(anctrl, self->bounce->unk8 * (1.0f / arg2));
    } else {
        anctrl_setDuration(anctrl, self->bounce->unk0);
    }
    anctrl_setSubrange(anctrl, 0.0f, arg2);
    anctrl_setPlaybackType(anctrl, 1);
    anctrl_start(anctrl);
}

void babounce_entrypoint_6(PlayerState *self, AssetId asset_id, f32 arg2, f32 arg3, f32 arg4) {
    self->bounce->unk0 = arg3;
    self->bounce->unk4 = arg4;
    babounce_entrypoint_5(self, asset_id, arg2);
}

void babounce_entrypoint_7(PlayerState *self, s32 arg1) {
    self->bounce->unk10 =  arg1;
}

s32 babounce_entrypoint_8(PlayerState *self) {
    f32 sp24[3];

    switch (self->bounce->unkC) {
        case 3:
            if (_batimer_decrement(self, 6)){
                func_8009BB24(self, sp24);
                sp24[0] = 0.0f;
                sp24[2] = 0.0f;
                func_8009BA9C(self, sp24);
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                func_80800008_babounce(self, 1);
                return 1;
            }
            return 0;

        case 2:
            if (player_isStable(self)) {
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                func_80800008_babounce(self, 1);
                return 1;
            }
            return 0;

        case 1:
            return 2;
        
    }
    return 0;
}

s32 babounce_entrypoint_9(PlayerState *self) {
    switch (babounce_entrypoint_8(self)) {
        case 1:
            baanim_setEndAndDuration(self, 1.0f, self->bounce->unk4);
            return 0;

        case 2:
            if (baanim_isStopped(self) || (bastick_distance(self) != 0.0f)){ 
                return 1;
            }
            break;
    }
    return 0;
}

s32 babounce_entrypoint_10(PlayerState *self) {
    if(babounce_entrypoint_8(self) == 1) {
        return 1;
    }
    return 0;
}

