#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/stick.h"
#include "core2/1E72EA0.h"
#include "overlays/bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "bs.h"


void func_80800000_bsbflip(PlayerState *self) {
    f32 sp1C = bastick_getZonePosition(self);
    if (!bastick_getZone(self)) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(self, func_800F1214(sp1C, 80.0f, 200.0f));
    }
}

void func_80800064_bsbflip(PlayerState *self, s32 substate) {
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    f32 sp30[3];

    switch(substate){
        case 0:
            func_800C6DA0(0x3E);
            baphysics_reset_gravity(self);
            baphysics_reset_terminal_velocity(self);
            func_800A0D44(self, 0);
            bastick_resetZones(self);
            break;

        case 1:
            anctrl_reset(anctrl);
            anctrl_setSmoothTransition(anctrl, 0);
            anctrl_setIndex(anctrl, ASSET_4B_ANIM_BSBFLIP_ENTER);
            anctrl_setDuration(anctrl, 2.3f);
            anctrl_setSubrange(anctrl, 0.0f, 0.7866f);
            anctrl_setStart(anctrl, 0);
            anctrl_setPlaybackType(anctrl, 1);
            anctrl_start(anctrl);
            func_8009FFD8(self, 1, 1, 2, 3);
            bastick_setZoneMax(self, 0, 0.03f);
            bastick_setZoneMax(self, 1, 1.0f);
            func_800A0CF4(self, 1);
            func_8009D874(self);
            break;

        case 2:
            if (bastick_distance(self) != 0.0f) {
                yaw_setUpdateType(self, YAW_TYPE_2_UNBOUNDED);
                func_8009D2D8(self, 3);
                if (bastick_distance){
                    yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
                }
                yaw_rotateTimed(self, 1.0f);
                baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
                baphysics_set_target_yaw(self, yaw_getIdeal(self));
                baphysics_set_target_horizontal_velocity(self, 200.0f);
                baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), baphysics_get_target_horizontal_velocity(self));

            } else {
                baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
                baphysics_set_target_horizontal_velocity(self, 0.0f);
            }
            baphysics_set_vertical_velocity(self, 920.0f);
            baphysics_set_gravity(self, -1200.0f);
            baphysics_set_terminal_velocity(self, -533.3f);
            anctrl_setDuration(anctrl, 1.9f);
            func_8009DE38(self, 0x5A6, 1.0f);
            break;

        case 3:
            anctrl_reset(anctrl);
            anctrl_setSmoothTransition(anctrl, 0.0f);
            anctrl_setIndex(anctrl, ASSET_4C_ANIM_BSBFLIP_HOLD);
            anctrl_setDuration(anctrl, 0.13f);
            anctrl_setPlaybackType(anctrl, 2);
            anctrl_start(anctrl);
            break;

        case 4:
            anctrl_reset(anctrl);
            anctrl_setIndex(anctrl, ASSET_4B_ANIM_BSBFLIP_ENTER);
            anctrl_setDuration(anctrl, 2.2f);
            anctrl_setStart(anctrl, 0.8566f);
            anctrl_setPlaybackType(anctrl, 1);
            anctrl_start(anctrl);
            baphysics_set_type(self, 3);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            func_800EFD24(sp30);
            func_8009BA9C(self, sp30);
            func_8009FE58(self);
            func_800A0CF4(self, 0);
            break;
            
    }
    self->unk15C.word = substate;
}

void bsbflip_end(PlayerState *self) {
    func_80800064_bsbflip(self, 0);
}

void bsbflip_init(PlayerState *self) {
    self->unk15C.word = 0;
    func_80800064_bsbflip(self, 1);
}

void bsbflip_update(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    if ( anctrl_isAt(anctrl, 0.2394f)
        && (anctrl_getPlaybackType(anctrl) != 2)
        && (anctrl_getIndex(anctrl) == ASSET_4B_ANIM_BSBFLIP_ENTER)
    ){
        func_8009DF94(self, 0x3FF, 0.558f, 22000);
    }
    switch(self->unk15C.word) {
        case 1:
            if (anctrl_isAt(anctrl, 0.1837f)){
                func_80800064_bsbflip(self, 2);
            }
            break;

        case 2:
            func_80800000_bsbflip(self);
            if (anctrl_isStopped(anctrl)) {
               func_80800064_bsbflip(self, 3); 
            }
            if (bainput_should_beak_bust(self)) {
                next_state = BS_STATE_F_BBUSTER;
            }
            if (func_8008DA24(self)) {
                next_state = BS_STATE_A8;
            }
            break;

        case 3:
            if (func_8008E260(self)) {
                next_state = BS_STATE_3D_FALL_TUMBLING;
            }
            if (bakey_released(self, BUTTON_A)) {
                next_state = BS_STATE_2F_FALL;
            }
            if (player_isStable(self)) {
                next_state = func_800A01F8(self, next_state);
                func_80800064_bsbflip(self, 4);
                break;
            } 

            if (bainput_should_beak_bust(self)) {
                next_state = BS_STATE_F_BBUSTER;
            }
            if (func_8008DA24(self)) {
                next_state = BS_STATE_A8;
            }
            
            break;

        case 4:
            if (anctrl_isStopped(anctrl)) {
                next_state = BS_STATE_1_SLOW_WALK;
            }
            next_state = func_800A01F8(self, next_state);
            break;

    }
    if (player_inWater(self)) {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

extern void _bsbflip_init(PlayerState *self);
extern void _bsbflip_update(PlayerState *self);
extern void _bsbflip_end(PlayerState *self);
BsScript D_80800620_bsbflip[4] = {_bsbflip_end, _bsbflip_init, _bsbflip_update, func_80099B94};


BsScript bsbflip_entrypoint_3(BsScriptType type) {
    return D_80800620_bsbflip[type];
}
