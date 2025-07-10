#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/assets.h"
#include "overlays/ba/dust.h"
#include "overlays/ba/motor.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "bs.h"
#include "buttons.h"
#include "overlays/bs/state.h"
#include "overlays/ba/flag.h"

#include "core2/1E66990.h"
#include "core2/1E68670.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EB2840.h"
#include "core2/1ECB9F0.h"

void bsbbuster_setSubstate(PlayerState *self, int substate) {
    AnimCtrl *anctrl =  baanim_getAnimCtrlPtr(self);
    self->unk160.bytes[1] = substate;
    switch(substate) {
        case 1:
            break;

        case 2:
            anctrl_setDuration(anctrl, 0.4f);
            break;

        case 3:
            baphysics_reset_gravity(self);
            baphysics_set_terminal_velocity(self, -5000.0f);
            baphysics_set_gravity(self, -20000.0f);
            baphysics_set_vertical_velocity(self, 2300.0f);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            self->unk15C.bytes[2] = 1;
            break;

        case 4:
            baflag_set(self, BA_FLAG_27);
            _bashake_entrypoint_1(self, 0x3, 0x2);
            func_800A2EEC(self, 0);
            _badust_entrypoint_10(self, 0.0f);
            func_8009BA9C(self, 0);
            baphysics_set_gravity(self, 0.0f);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            func_8008EE88(self, 150.0f);
            self->unk15C.bytes[2] = 2;
            self->unk16C = 0.09f;
            break;

        case 5:
            if (baflag_isTrue(self, BA_FLAG_23)) {
                baphysics_set_vertical_velocity(self, 400.0f);
                baphysics_set_gravity(self, -800.0f);
            } else {
                baphysics_set_vertical_velocity(self, 730.0f);
                baphysics_set_gravity(self, -2110.0f);
            }
            baanim_setEndAndDuration(self, 0.7299f, 1.9f);
            break;
    }
}

void bsbbuster_end(PlayerState *self) {
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    func_800A0CF4(self, 0);
    baflag_clear(self, BA_FLAG_21);
    baflag_clear(self, BA_FLAG_27);
}

void bsbbuster_init(PlayerState *self) {
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anctrl);
    anctrl_setSmoothTransition(anctrl, 0);
    anctrl_setIndex(anctrl, ASSET_1D_ANIM_BSBBUSTER);
    anctrl_setDuration(anctrl, 1.02f);
    anctrl_setSubrange(anctrl, 0.0f, 0.455f);
    anctrl_setPlaybackType(anctrl, 1);
    anctrl_start(anctrl);
    func_8009FFD8(self, 1, 1, 3, 6);
    baphysics_set_gravity(self, 0.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009BA9C(self, 0);
    func_800A0CF4(self, 1);
    baflag_clear(self, BA_FLAG_23);
    baflag_clear(self, BA_FLAG_21);
    baflag_clear(self, BA_FLAG_27);
    self->unk15C.bytes[1] = 0;
    self->unk15C.bytes[2] = 0;
    self->unk16C = 9.999999747e-05f;
    self->unk160.bytes[2] = 0;
    self->unk15C.bytes[0] = 0;
    self->unk15C.bytes[3] = 0;
    self->unk160.bytes[0] = 0;
    self->unk160.bytes[1] = 0;
    bsbbuster_setSubstate(self, 1);
}

void bsbbuster_update(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    s32 sp34;
    f32 sp28[3];

    if (baanim_isAt(self, 0.24f)) {
        self->unk160.bytes[1];
        func_8009D874(self);
    }

    switch (self->unk160.bytes[1]) {
        case 1:
            _bswalk_entrypoint_1(self);
            if (baanim_isStopped(self)) {
                bsbbuster_setSubstate(self, 2);
            }

            if (baanim_isAt(self, 0.3637f) && bakey_held(self, BUTTON_Z) && func_800C6E38(0x19)) {
                next_state = BS_STATE_B6_BILL_DRILL;
            }
            break;
        
        case 2:
            _bswalk_entrypoint_1(self);
            self->unk16C -= func_800D8FF8();
            if (self->unk16C <= 0.0f) {
                bsbbuster_setSubstate(self, 3);
            }
            break;

        case 3:
            if ((self->unk15C.bytes[0] == 0) && (baphysics_get_vertical_velocity(self) < 0.0f)) {
                    func_8009DF94(self, 0x442F, 1.2f, 0x7530);
                    self->unk15C.bytes[0]++;
            }

            if ((self->unk160.bytes[2] == 0 ) && func_8008DF8C(self, 0x8C)) {
                func_8009DE38(self, 0x40D, 1.0f);
                self->unk160.bytes[2]++;
            }

            if ((self->unk15C.bytes[3] == 0 ) && func_8008DF8C(self, 0x4B)) {
                _bamotor_entrypoint_1(self, 1.0f, 0.7f, 0.2f);
                self->unk15C.bytes[3]++;
            }
            self->unk15C.bytes[1] = baflag_isTrue(self, BA_FLAG_8);
            func_80096394(self, sp28);
            if (mlAbsF(sp28[1]) < 1.0f) {
                self->unk160.bytes[0]++;
            } else {
                self->unk160.bytes[0] = 0;
            }

            if (self->unk15C.bytes[2] == 2) {
                self->unk15C.bytes[2] = 0;
            }

            if (player_isStable(self) || self->unk15C.bytes[1] || !(self->unk160.bytes[0] < 4)){
                bsbbuster_setSubstate(self, 4);
                if (func_800954E8(self, &sp34)) {
                    next_state = BS_STATE_72;
                }
            }
            break;

        case 4:
            baflag_clear(self, BA_FLAG_27);
            self->unk15C.bytes[2] = 0;
            if (func_8009BD44(self) == 1) {
                func_8009BDAC(self, 0.9f);
            }
            self->unk16C -= func_800D8FF8();
            if (self->unk16C <= 0.0f) {
                bsbbuster_setSubstate(self, 5);
            }
            break;

        case 5:
            _bswalk_entrypoint_1(self);
            if (baanim_isStopped(self)) {
                baanim_setEndAndDuration(self, 0.74f, 15.0f);
            }

            if (player_isStable(self)){
                anctrl_setSubrange(anctrl, 0.0f, 1.0f);
                anctrl_setDuration(anctrl, 1.9f);
                anctrl_setPlaybackType(anctrl, 1);
                next_state = BS_STATE_20_LANDING;
            }
            break;
    }

    if (player_inWater(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    
    if (self->unk15C.bytes[2]) {
        baflag_set(self, BA_FLAG_21);
    } else {
        baflag_clear(self, BA_FLAG_21);
    }
    bs_setState(self, next_state);

}

BsScript D_80800730_bsbbuster[4] = {bsbbuster_end, bsbbuster_init, bsbbuster_update, func_80099B94};

BsScript bsbbuster_entrypoint_0(BsScriptType type) {
    return D_80800730_bsbbuster[type];
}

