#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/assets.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/timer.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/stick.h"
#include "core2/1E72EA0.h"
#include "overlays/bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "bs.h"

void bsbflap_init(PlayerState *self) {
    baanim_playForDuration_once(self, ASSET_18_ANIM_BSBFLAP_ENTER, 0.3f);
    func_8009FFD8(self, 1, 1, 1, 2);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bswalk_entrypoint_1(self);
    baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 0.0f);
    baphysics_set_gravity(self, -1100.0f);
    func_800A0CF4(self, 1);
    baflag_set(self, BA_FLAG_12_HAS_FLAPPED);
    _batimer_set(self, 0, 2.5f);
    func_8009D874(self);
    self->unk160.word = 0;
    self->unk15C.word = 0;
    self->unk170 = 0.0f;
}

void func_80800120_bsbflap(PlayerState *self) {
    AnimCtrl *anctrl;
    anctrl = baanim_getAnimCtrlPtr(self);
    if (anctrl_isAt(anctrl, 0.9f)) {
        self->unk160.word++;
    }
}

f32 func_80800168_bsbflap(PlayerState *self) {
    switch (self->unk160.word) {
        case 0:
            return 0.15f;
        case 1:
            return 0.2f;
        case 2:
            return 0.27f;
        case 3:
            return 0.38f;
        case 4:
            return 0.4f;
        default:
            return 0.7f;
    }
}
void func_808001D8_bsbflap(PlayerState *self) {
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    anctrl_setDuration(anctrl, func_80800168_bsbflap(self));
}

void func_80800210_bsbflap(PlayerState *self) {
    self->unk16C = self->unk170;
    self->unk170 += func_800D8FF8();
}

int func_80800248_bsbflap(PlayerState *self, f32 value) {
    return ((self->unk16C <= value) && (value < self->unk170));
}


void func_80800294_bsbflap(PlayerState *self) {
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    if (func_80800248_bsbflap(self, 0.08f)) {
        func_8009DB04(self, 0x4435, 1.24f, 0x4e20);
    }

    if ((0.7f < self->unk170) && anctrl_isAt(anctrl, 0.5698f)) {
        func_8009DF18(self, 0x4431, 1.0f, 22000);
    }
    if ((anctrl_getIndex(anctrl) == 0x17) && anctrl_isAt(anctrl, 0.02f)) {
        func_8009DF94(self, 0x3FF, func_800DC178(0.92f, 1.02f), 16000);
    }
}

void bsbflap_update(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    _bswalk_entrypoint_1(self);
    switch (self->unk15C.word) {
        case 0:
            func_800956B8(self); //bafalldamage_start
            func_80800210_bsbflap(self);
            func_80800294_bsbflap(self);
            if(anctrl_isAt(anctrl, 0.9f)){
                anctrl_setSmoothTransition(anctrl, 0);
                anctrl_setIndex(anctrl, ASSET_17_ANIM_BSBFLAP);
                anctrl_setDuration(anctrl, func_80800168_bsbflap(self));
                anctrl_setPlaybackType(anctrl, 2); //anctrl_setPlaybackType;
                anctrl_setStart(anctrl, 0);
                anctrl_start(anctrl);
                baphysics_set_vertical_velocity(self, 280.0f);
                baphysics_set_gravity(self, -1100.0f);
                baphysics_set_terminal_velocity(self, -399.9f);
                self->unk15C.word = 1;
            }
            break;

        case 1:
            func_800956B8(self);
            func_80800210_bsbflap(self);
            func_80800120_bsbflap(self);
            func_808001D8_bsbflap(self);
            func_80800294_bsbflap(self);
            if (0.67f <= self->unk170){
                self->unk15C.word = 2;
            }
            break;

        case 2:
            func_800956B8(self);
            func_80800210_bsbflap(self);
            func_80800120_bsbflap(self);
            func_808001D8_bsbflap(self);
            func_80800294_bsbflap(self);
            if (self->unk160.word == 4) {
                self->unk15C.word = 3;
            }
            if (bakey_released(self, BUTTON_A)) {
                baphysics_reset_gravity(self);
                baphysics_reset_terminal_velocity(self);
                anctrl_setDuration(anctrl, 1.0f);
                self->unk15C.word = 4;
            }
            break;

        case 3:
            func_800956B8(self);
            func_80800210_bsbflap(self);
            func_80800120_bsbflap(self);
            func_808001D8_bsbflap(self);
            func_80800294_bsbflap(self);
            if (bakey_released(self, BUTTON_A)) {
                baphysics_reset_gravity(self);
                baphysics_reset_terminal_velocity(self);
                anctrl_setDuration(anctrl, 1.0f);
                func_80095588(self, 2);
                self->unk15C.word = 4;
            } else {
                baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self) * 0.35f);

            }
            break;

        case 4:
            if (func_8008E260(self)) {
                next_state = BS_STATE_3D_FALL_TUMBLING;
            }
            break;
    }
    _batimer_decrement(self, 0);
    if (_batimer_isZero(self, 0)) {
        next_state = BS_STATE_2F_FALL;
    }

    if (bainput_should_beak_bust(self)) {
        next_state = BS_STATE_F_BBUSTER;
    }
    
    if (func_8008DA24(self)) {
        next_state = BS_STATE_A8;
    }

    if (player_isStable(self)) {
        func_8009FE58(self);
        next_state = BS_STATE_1_SLOW_WALK;
    }

    if (player_inWater(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }

    bs_setState(self, next_state);
}

void bsbflap_end(PlayerState *self) {
    func_800C6DA0(0x3D);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    func_800A0D14(self, 0, 0.2f);
}

extern void _bsbflap_init(PlayerState *self);
extern void _bsbflap_update(PlayerState *self);
extern void _bsbflap_end(PlayerState *self);

BsScript D_80800750_bsbflap[4] = {_bsbflap_end, _bsbflap_init, _bsbflap_update, func_80099B94};

BsScript bsbflap_entrypoint_3(BsScriptType type) {
    return D_80800750_bsbflap[type];
}
