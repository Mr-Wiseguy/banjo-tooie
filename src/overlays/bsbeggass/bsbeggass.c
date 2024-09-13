#include <ultra64.h>
#include "common.h"
#include "ba/physics.h"
#include "ba/yaw.h"
#include "ba/playerstate.h"
#include "ba/animctrl.h"
#include "ba/anim.h"
#include "ba/buttons.h"

// TODO rename these symbols
#define yaw_setVelocityBounded func_8009C99C
#define bs_setState func_8009E5C8

void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawState yaw_state, s32 arg2, BaPhysicsType arg3);
void yaw_setVelocityBounded(PlayerState* thisx, f32 arg0, f32 arg1);
void func_800A0CDC(PlayerState* thisx, s32 arg1);
s32 func_80094510(PlayerState* thisx);
void func_80098140(PlayerState* thisx, s32, s32);
void func_800A0CDC(PlayerState* thisx, s32 arg1);
void func_8009AB78();
void bs_setState(PlayerState*, s32);
void _baeggsetup_entrypoint_2(PlayerState*, s32, f32, f32);
void _baeggsetup_entrypoint_9(PlayerState*);
s32 _bscrouch_entrypoint_4(PlayerState*, s32);
void func_800C6DA0(s32);
s32 func_8008B324(AnimCtrl*);
s32 func_8008DD04(PlayerState*);
s32 func_800944E0(PlayerState*, s32);
s32 func_80094B14(PlayerState*);
s32 func_80094BC0(PlayerState*);
s32 func_80097BFC(PlayerState*);
s32 func_800F1418(s32, s32);

void bsbeggass_entrypoint_0(PlayerState* arg0);
void bsbeggass_entrypoint_1(PlayerState* arg0);
void bsbeggass_entrypoint_2(PlayerState* arg0);

// syscall trampolines for this module's functions, which just jump here.
void _bsbeggass_entrypoint_0(PlayerState* arg0);
void _bsbeggass_entrypoint_1();
void _bsbeggass_entrypoint_2();

// bseggass_init
void bsbeggass_entrypoint_0(PlayerState* arg0){
    baanim_playForDuration_onceSmooth(arg0, ASSET_2B_ANIM_BSEGGASS, 1.0f);
    func_8009FFD8(arg0, BAANIM_UPDATE_1_NORMAL, YAW_STATE_3_BOUNDED, 1, BA_PHYSICS_LOCKED_ROTATION);
    yaw_setVelocityBounded(arg0, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A0CDC(arg0, 1);
    arg0->unk15C = arg0->unk160 = 1;
    arg0->unk164 = func_80094510(arg0);
    func_80098140(arg0,5,0);
}

// bseggass_update
void bsbeggass_entrypoint_1(PlayerState* arg0) {
    s32 next_state;
    AnimCtrl* plyr_mvmt;
    s32 has_eggs;

    next_state = 0;
    plyr_mvmt = baanim_getAnimCtrlPtr(arg0);
    has_eggs = func_80094BC0(arg0) != 0;
    if (func_80097BFC(arg0) && func_80094B14(arg0)) {
        arg0->unk15C = func_800F1418(arg0->unk15C + 1, func_800944E0(arg0, arg0->unk164));
    }
    if (has_eggs) {
        if (animctrl_isAt(plyr_mvmt, 0.3837f)) {
            _baeggsetup_entrypoint_9(arg0);
            _baeggsetup_entrypoint_2(arg0, arg0->unk164, 60.0f, -18.0f);
            func_800C6DA0(0x43);
        }
        if (animctrl_isAt(plyr_mvmt, 0.4885f) && (arg0->unk160 < arg0->unk15C)) {
            animctrl_setStart(plyr_mvmt, 0.349f);
            animctrl_start(plyr_mvmt);
            arg0->unk160++;
        }
    }
    if (func_8008DD04(arg0)) {
        next_state = BS_2F_FALL;
    }
    if (button_held(arg0, BUTTON_Z)) {
        if (func_8008B324(plyr_mvmt)) {
            next_state = BS_CROUCH;
        }
        if (0.6f < animctrl_getAnimTimer(plyr_mvmt)) {
            next_state = _bscrouch_entrypoint_4(arg0, next_state);
        }
    } else if (func_8008B324(plyr_mvmt)) {
        next_state = BS_1_IDLE;
    }
    bs_setState(arg0, next_state);
}

// bseggass_end
void bsbeggass_entrypoint_2(PlayerState* arg0){
    func_80098140(arg0, 5, 1);
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
