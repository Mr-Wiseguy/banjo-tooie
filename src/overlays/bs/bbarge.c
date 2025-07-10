#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/assets.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/timer.h"
#include "overlays/bs/state.h"
#include "core2/1E72EA0.h"
#include "core2/1E68670.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "buttons.h"
#include "bs.h"

void bsbbarge_end(PlayerState *self);
void bsbbarge_init(PlayerState *self);
void bsbbarge_update(PlayerState *self);

extern BsScript D_80800630_bsbbarge[4]; //= {bsbbarge_end, bsbbarge_init, bsbbarge_update, func_8009AB78};


void bsbbarge_setSubstate(PlayerState *self, int substate) {
    switch (substate) {
        case 1:
            break;
        case 2:
            if (baflag_isFalse(self, 0xA)) {
                baflag_set(self, 0xC);
                self->unk16C = 850.0f;
            } else {
                self->unk16C = 500.0f;
            }
            _batimer_set(self, 1, 0.01f);
            break;

        case 3:
            func_8009D2D8(self, 1);
            baanim_setEndAndDuration(self, 0.565f, 1.0f);
            baphysics_set_target_horizontal_velocity(self, self->unk16C);
            baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), baphysics_get_target_horizontal_velocity(self));
            func_8009DF18(self, 0x3FF, 0.558f, 0x55F0);
            _badust_entrypoint_12(self, 2);
            baflag_set(self, 0x20);
            break;

        case 4:
            baanim_setEndAndDuration(self, 0.6f, 2.0f);
            _batimer_set(self, 0, 0.1f);
            break;

        case 5:
            baanim_setEndAndDuration(self, 1.0f, 1.5f);
            _badust_entrypoint_12(self, 1);
            break;
    }
    self->unk160.word = substate;
}

void bsbbarge_end(PlayerState *self) {
    func_8009E474(self);
    func_800C6DA0(0x41);
    func_800A0CF4(self, 0);
    baflag_clear(self, 0x20);
    _badust_entrypoint_12(self, 0x1);
}

void bsbbarge_init(PlayerState *self) {
    AnimCtrl *anctrl =  baanim_getAnimCtrlPtr(self);
    anctrl_reset(anctrl);
    anctrl_setSmoothTransition(anctrl, 0);
    anctrl_setIndex(anctrl, ASSET_1C_ANIM_BSBBARGE);
    anctrl_setDuration(anctrl, 1.0f);
    anctrl_setSubrange(anctrl, 0.0f, 0.375f);
    anctrl_setPlaybackType(anctrl, 1);
    anctrl_start(anctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, 14);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self)*0.3f);
    baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), baphysics_get_target_horizontal_velocity(self));
    func_800A0CF4(self, 1);
    baflag_clear(self, 0x20);
    baflag_clear(self, 0xA);
    baflag_clear(self, 0xB);
    baflag_clear(self, 0xC);
    func_8009E4AC(self);
    func_8009E5A4(self, 2, 3);
    func_8009E55C(self, 2, 40.f);
    self->unk160.word = 0;
    bsbbarge_setSubstate(self, 1);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbarge/bsbbarge_update.s")
#else
void bsbbarge_update(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *anctrl =  baanim_getAnimCtrlPtr(self);
    if (bakey_released(self, BUTTON_B)) {
        baflag_set(self, 0xA); //miscFlag_set
    }
    switch(self->unk160.word) {
        case 1:
            if(anctrl_isAt(anctrl, 0.1392f)) {
                func_8009D874(self); // BK:func_80299BD4();
            }
            
            if(anctrl_isStopped(anctrl)) {
                bsbbarge_setSubstate(self, 2);
            }
            break;

        case 2:
            _batimer_decrement(self, 1);
            if (baflag_isFalse(self, 0xB) && _batimer_isLessThan(self, 1, 0.1f)) {
                if (baflag_isTrue(self, 0xC)) {
                    func_8009DF94(self, 0x4400, 1.0f, 0x7530);
                } else {
                    func_8009DF94(self, 0x442D, 1.0f, 0x7530);
                }
                baflag_set(self, 0xB);
            }

            if (_batimer_isZero(self, 1)){
                bsbbarge_setSubstate(self, 3);
            } 

            break;

        case 3:
            baphysics_set_target_horizontal_velocity(self, self->unk16C);
            if (anctrl_isStopped(anctrl)) {
                bsbbarge_setSubstate(self, 4);
            }
            break;

        case 4:
            _batimer_decrement(self, 0);
            if (baflag_isFalse(self, 0xC) || _batimer_isZero(self, 0)) {
                self->unk16C -= 80.0f;
            }
            baphysics_set_target_horizontal_velocity(self, self->unk16C);
            if (self->unk16C < 200.0f) {
                bsbbarge_setSubstate(self, 5);
            }
            break;

        case 5:
            if (!player_isStable(self)) {
                next_state = BS_STATE_2F_FALL;
            }

            if (anctrl_isAt(anctrl, 0.7f)) {
                self->unk16C = 0.0f;
                baflag_clear(self, 0x20);
            }

            baphysics_set_target_horizontal_velocity(self, self->unk16C);

            if (anctrl_isAt(anctrl, 0.9193f)) {
                next_state = BS_STATE_20_LANDING;
            }
            break;
    }

    if (baflag_isTrue(self, 0x20)) {
        func_8008EE88(self, 50.0f);
    }

    if (player_inWater(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }

    bs_setState(self, next_state);
}
#endif

BsScript bsbbarge_entrypoint_0(BsScriptType type) {
    return D_80800630_bsbbarge[type];
}