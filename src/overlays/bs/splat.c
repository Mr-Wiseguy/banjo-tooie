#include "bs/splat.h"

extern s32 D_808002B0_bssplat[];

void bssplat_entrypoint_0(PlayerState* self)
{
    s32 sp24;

    func_800954E8(self, &sp24);
    player_affectCurrentHealth(self, -sp24);
    if (func_80096694(self) == 3)
    {
        func_8009DB04(self, 0x417, 0.8f, 0x7FFF);
    }
    else
    {
        func_8009DB04(self, 0x417, 0.8f, 0x7FFF);
    }
    _badust_entrypoint_8(self);
    _bashake_entrypoint_0(self, 3, 2);
}

void func_8080009C_bssplat(PlayerState* self)
{
    baanim_playForDuration_once(self, 0x46, 1.1f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_3_LOCKED_ROTATION);
    bssplat_entrypoint_0(self);
    func_8009DF18(self, 0x427, 1.0f, 0x6D60);
    self->unk15C.word = 0;
    func_8008E944(self);
}

void func_80800114_bssplat(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp20;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    baphysics_set_target_horizontal_velocity(self, ml_max_f(0.0f, baphysics_get_target_horizontal_velocity(self) - 15.0f));
    switch (self->unk15C.word) 
    {
    case 0:
        if (baphysics_get_target_horizontal_velocity(self) > 140.0f) {
            _badust_entrypoint_9(self);
        }
        if (func_8008DD04(self) != 0) {
            nextState = BS_STATE_2F_FALL;
        }
        if (anctrl_isStopped(sp20) != 0) {
            baanim_playForDuration_onceSmooth(self, 0xD2, 2.25f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(sp20, 0.63f) != 0) {
            nextState = BS_STATE_20_LANDING;
        }
        if (anctrl_isStopped(sp20) != 0) {
            nextState = BS_STATE_1_IDLE;
        }
        if (func_8008DD04(self) != 0) {
            nextState = BS_STATE_2F_FALL;
        }
        break;
    }
    if ((player_isStable(self) == 0) && (player_inWater(self) != 0)) {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (player_getCurrentHealth(self) == 0) {
        nextState = BS_STATE_41_FALL_DEATH;
    }
    bs_setState(self, nextState);
}


void func_80800274_bssplat(PlayerState* self)
{
    func_8008E95C(self);
    func_8009BD88(self);
}
s32 bssplat_entrypoint_1(s32 arg0) {
    return D_808002B0_bssplat[arg0];
}