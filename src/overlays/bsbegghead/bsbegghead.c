#include "ba/physics.h"
#include "ba/playerstate.h"
#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/eggs.h"
#include "funcs.h"

#include "core2/1E72EA0.h"

// bsegghead_init
void bsbegghead_entrypoint_0(PlayerState* player){
    baanim_playForDuration_onceSmooth(player, ASSET_2A_ANIM_BSEGGHEAD, 1.0f);
    func_8009FFD8(player, 1,3,1, BA_PHYSICS_LOCKED_ROTATION);
    yaw_setVelocityBounded(player, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800A0CF4(player, 1);
    player->unk15C = player->unk160 = 1;
    player->unk164 = func_80094510(player);
    func_80098140(player, 2, 0);
}

// bsegghead_update
void bsbegghead_entrypoint_1(PlayerState* player) {
    s32 next_state;
    AnimCtrl* aCtrl;
    s32 has_eggs;

    next_state = 0;
    aCtrl = baanim_getAnimCtrlPtr(player);
    has_eggs = func_80094BC0(player) != 0;
    if (func_80097C3C(player) && func_80094B14(player)) {
        player->unk15C = func_800F1418(player->unk15C + 1, func_800944E0(player, player->unk164));
    }
    if (has_eggs) {
        if (anctrl_isAt(aCtrl, 0.1f)) {
            _baeggsetup_entrypoint_10(player);
        }
        if (anctrl_isAt(aCtrl, 0.4f)) {
            _baeggsetup_entrypoint_8(player, player->unk164);
        }
        if (anctrl_isAt(aCtrl, 0.4704f)) {
            _baeggsetup_entrypoint_5(player, player->unk164, 80.0f, 120.0f);
            func_800C6DA0(0x43);
        }
        if (anctrl_isAt(aCtrl, 0.5919f) && player->unk160 < player->unk15C) {
            anctrl_setStart(aCtrl, 0.3878f);
            anctrl_start(aCtrl);
            player->unk160++;
        }
    }
    if (func_8008DD04(player)) {
        next_state = BS_2F_FALL;
    }
    if (button_held(player, BUTTON_Z)) {
        if (anctrl_isStopped(aCtrl)) {
            next_state = BS_CROUCH;
        }
        if (0.65f < anctrl_getAnimTimer(aCtrl)) {
            next_state = _bscrouch_entrypoint_4(player, next_state);
        }
    } else if (anctrl_isStopped(aCtrl)) {
        next_state = BS_1_IDLE;
    }
    bs_setState(player, next_state);
}

// bsegghead_end
void bsbegghead_entrypoint_2(PlayerState* player){
    func_80098140(player, 2, 1);
    baphysics_reset_gravity(player);
    func_800A0CF4(player, 0);
}

void* D_808002E0_bsbegghead[] = {
    _bsbegghead_entrypoint_2,
    _bsbegghead_entrypoint_0,
    _bsbegghead_entrypoint_1,
    func_8009AB78
};

void* bsbegghead_entrypoint_3(s32 arg0) {
    return D_808002E0_bsbegghead[arg0];
}
