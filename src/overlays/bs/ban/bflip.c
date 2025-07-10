#include "common.h"
#include "core2/1E72EA0.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/physics.h"
#include "overlays/bs/state.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1EA0690.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "bs.h"

extern void _bsbanbflip_end(PlayerState *);
extern void _bsbanbflip_init(PlayerState *);
extern void _bsbanbflip_update(PlayerState *);

void func_80800000_bsbanbflip(PlayerState *self) {
    f32 stick_position = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(self, func_800F1214(stick_position, 80.0f, 200.0f));
    }
}

void __bsbanbflip_set_substate(PlayerState *self, BanjoStateId next_state) {
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self); //sp44
    f32 sp38[3];
    switch (next_state) {
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
            anctrl_setIndex(anctrl, ASSET_27B_ANIM_BANBFLIP);
            anctrl_setDuration(anctrl, 2.3f);
            anctrl_setSubrange(anctrl, 0.0f, 0.7866f);
            anctrl_setStart(anctrl, 0.0f);
            anctrl_setPlaybackType(anctrl, 1);
            anctrl_start(anctrl);
            func_8009FFD8(self, 1, 1, 2, 3);
            bastick_setZoneMax(self, 0, 0.03f);
            bastick_setZoneMax(self, 1, 1.0f);
            func_800A0CF4(self, 1);
            break;

        case 2:
            if (bastick_distance(self) != 0.0f) {
                yaw_setUpdateType(self, YAW_TYPE_2_UNBOUNDED);
                func_8009D2D8(self, 3);
                if (bastick_distance) {
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
            baphysics_set_vertical_velocity(self, 800.0f);
            baphysics_set_gravity(self, -1200.0f);
            baphysics_set_terminal_velocity(self, -533.3f);
            anctrl_setDuration(anctrl, 1.9f);
            func_8009DE38(self, 0x5A6, 1.0f);
            break;

        case 3:
            anctrl_reset(anctrl);
            anctrl_setIndex(anctrl, ASSET_4B_ANIM_BSBFLIP_ENTER);
            anctrl_setDuration(anctrl, 2.2f);
            anctrl_setStart(anctrl, 0.8566);
            anctrl_setPlaybackType(anctrl, 1);
            anctrl_start(anctrl);
            baphysics_set_type(self, BA_PHYSICS_3_LOCKED_ROTATION);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            func_800EFD24(sp38);
            func_8009BA9C(self, sp38);
            func_8009FE58(self);
            func_800A0CF4(self, 0);
            break;
    }
    self->unk15C.word = next_state;
}

void bsbanbflip_end(PlayerState *self) {
    __bsbanbflip_set_substate(self, 0);
}

void bsbanbflip_init(PlayerState *self) {
    self->unk15C.word = 0;
    __bsbanbflip_set_substate(self, 1);
}

void bsbanbflip_update(PlayerState *self) {
    BanjoStateId next_state = BS_STATE_0_INVALID;
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    if (anctrl_isAt(anctrl, 0.2394f) 
        && anctrl_getPlaybackType(anctrl) != 2
        && anctrl_getIndex(anctrl) == ASSET_4B_ANIM_BSBFLIP_ENTER
    ) {
        func_8009DF94(self, 0x3FF, 0.558f, 22000);
    }

    switch (self->unk15C.word) {
        case 1:
            if(anctrl_isAt(anctrl, 0.1837f)){
                __bsbanbflip_set_substate(self, 2);
            }
            break;

        case 2:
            func_80800000_bsbanbflip(self);
            if(anctrl_isStopped(anctrl)) {
                next_state = BS_STATE_2F_FALL;
            }
            if (func_8008DA24(self)) {
                next_state = BS_STATE_A8;
            }
            break;

        case 3:
            if(anctrl_isStopped(anctrl)) {
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

BsScript D_80800510_bsbanbflip[4] = {_bsbanbflip_end, _bsbanbflip_init, _bsbanbflip_update, func_80099B94};

BsScript bsbanbflip_entrypoint_3(BsScriptType type) {
    return D_80800510_bsbanbflip[type];
}
