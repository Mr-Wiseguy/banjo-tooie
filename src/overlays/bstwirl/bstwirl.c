#include "common.h"

#include "overlays/ba/anim.h"
#include "core2/anctrl.h"
#include "overlays/ba/assets.h"
#include "overlays/ba/physics.h"
#include "bs.h"
#include "buttons.h"
#include "overlays/bs/state.h"

#include "core2/1E72EA0.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EB5980.h"

void func_80800000_bstwirl(PlayerState *);
void bstwirl_init(PlayerState *);
void bstwirl_update(PlayerState *);

/* .data */
BsScript D_808002C0_bstwirl[4] = {func_80800000_bstwirl, bstwirl_init, bstwirl_update, func_8009AB78};

/* .text */
void func_80800000_bstwirl(PlayerState *self) {
    func_800A0CF4(self, 0);
    func_800C6DA0(0x48);
    baflag_clear(self, 0x29);
    _badust_entrypoint_12(self, 1);
}

void bstwirl_init(PlayerState *self){
    baanim_playForDuration_once(self, ASSET_4F_ANIM_BSTWIRL, 1.3f);
    func_8009FFD8(self, 1, 3, 1, 0xE);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), baphysics_get_target_horizontal_velocity(self));
    baphysics_set_target_horizontal_velocity(self, 600.0f);
    func_800A0CF4(self, 1);
    baflag_set(self, 0x29);
    if (func_800DC0C0() < 0.5f) {
        func_8009DE38(self, 0x57C, 1.0f);
    } else {
        func_8009DE38(self, 0x57E, 1.0f);
    }
}

void bstwirl_update(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr(self);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    if (anctrl_isAt(aCtrl, 0.18f)) {
        func_8009DF18(self, 0x5A7, 1.0f, 26000);
    }
    if (anctrl_isAt(aCtrl, 0.3f)) {
        _badust_entrypoint_12(self, 2);
    }
    if (anctrl_isAt(aCtrl, 0.75f)) {
        _badust_entrypoint_12(self, 1);
    }

    if (anctrl_isAt(aCtrl, 0.8011f)) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        next_state = BS_STATE_20_LANDING;
    }

    if (bakey_pressed(self, BUTTON_A)) {
        next_state = bs_getTypeOfJump(self);
    }

    if ( 0.6f < anctrl_getAnimTimer(aCtrl) && !player_isStable(self)) {
        next_state = BS_STATE_2F_FALL;
    }

    if (player_inWater(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }

    next_state = func_800A02DC(self, next_state);
    bs_setState(self, next_state);
}

BsScript bstwirl_entrypoint_0(BsScriptType type) {
    return D_808002C0_bstwirl[type];
}
