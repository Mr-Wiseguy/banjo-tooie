#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/eggs.h"
#include "core2/1E72EA0.h"
#include "overlays/bs/state.h"
#include "overlays/bs/crouch.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1ECA640.h"


// bseggass_init
void bsbeggass_entrypoint_0(PlayerState* arg0){
    baanim_playForDuration_once(arg0, ASSET_2B_ANIM_BSEGGASS, 1.0f);
    func_8009FFD8(arg0, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_3_LOCKED_ROTATION);
    yaw_setVelocityBounded(arg0, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A0CDC(arg0, 1);
    arg0->unk15C.word = arg0->unk160.word = 1;
    arg0->unk164.word = func_80094510(arg0);
    bainput_enable(arg0, 5, 0);
}

// bseggass_update
void bsbeggass_entrypoint_1(PlayerState* arg0) {
    BanjoStateId next_state;
    AnimCtrl* plyr_mvmt;
    s32 has_eggs;

    next_state = BS_STATE_0_INVALID;
    plyr_mvmt = baanim_getAnimCtrlPtr(arg0);
    has_eggs = func_80094BC0(arg0) != 0;
    if (bainput_should_poop_egg(arg0) && func_80094B14(arg0)) {
        arg0->unk15C.word = func_800F1418(arg0->unk15C.word + 1, func_800944E0(arg0, arg0->unk164.word));
    }
    if (has_eggs) {
        if (anctrl_isAt(plyr_mvmt, 0.3837f)) {
            _baeggsetup_entrypoint_9(arg0);
            _baeggsetup_entrypoint_2(arg0, arg0->unk164.word, 60.0f, -18.0f);
            func_800C6DA0(0x43);
        }
        if (anctrl_isAt(plyr_mvmt, 0.4885f) && (arg0->unk160.word < arg0->unk15C.word)) {
            anctrl_setStart(plyr_mvmt, 0.349f);
            anctrl_start(plyr_mvmt);
            arg0->unk160.word++;
        }
    }
    if (func_8008DD04(arg0)) {
        next_state = BS_STATE_2F_FALL;
    }
    if (bakey_held(arg0, BUTTON_Z)) {
        if (anctrl_isStopped(plyr_mvmt)) {
            next_state = BS_STATE_7_CROUCH;
        }
        if (0.6f < anctrl_getAnimTimer(plyr_mvmt)) {
            next_state = _bscrouch_entrypoint_4(arg0, next_state);
        }
    } else if (anctrl_isStopped(plyr_mvmt)) {
        next_state = BS_STATE_1_IDLE;
    }
    bs_setState(arg0, next_state);
}

// bseggass_end
void bsbeggass_entrypoint_2(PlayerState* arg0){
    bainput_enable(arg0, 5, 1);
    baphysics_reset_gravity(arg0);
    func_800A0CDC(arg0, 0);
}

void* D_808002A0_bsbeggass[4] = {
    _bsbeggass_entrypoint_2,
    _bsbeggass_entrypoint_0,
    _bsbeggass_entrypoint_1,
    func_8009AB78
};

void* bsbeggass_entrypoint_3(s32 arg0) {
    return D_808002A0_bsbeggass[arg0];
}
