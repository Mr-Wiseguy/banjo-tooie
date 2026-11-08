#include "bs/bpeck.h"

extern s32 D_808004A0_bsbpeck[];

/* .code */
void bsbpeck_entrypoint_0(PlayerState* self)
{
    s32 previous_state;

    self->unk164.word = 0;
    previous_state = bs_getPreviousState(self);
    if ((previous_state != BS_STATE_5_JUMP)
        && ((previous_state == BS_STATE_8_TTROT_JUMP) ||
            ((previous_state != BS_STATE_2F_FALL)
            && (previous_state != BS_STATE_3D_FALL_TUMBLING)
            && (previous_state != BS_STATE_57)
            && (previous_state == BS_STATE_95))))
    {
        self->unk164.word += 1;
    }
    if (func_8009557C(self) == 1)
    {
        func_80095588(self, 2);
    }
    baanim_playForDuration_once(self, 0x1A, 0.2f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_6_AIRBORN);
    yaw_setVelocityBounded(self, 1200.0f, 10.0f);
    func_800A0CF4(self, 1);
    baphysics_set_gravity(self, -1400.0f);
    baphysics_set_vertical_velocity(self, 120.0f);
    func_8009E4AC(self);
    func_8009E55C(self, 0, 35.0f);
    func_8009E55C(self, 1, 42.0f);
    func_8009E4FC(self, 1, -38.0f, 0.0f, 105.0f);
    func_8009E4FC(self, 0, -38.0f, 0.0f, -7.0f);
    self->unk160.word = 0;
    self->unk15C.word = 0;
    baflag_set(self, 0x2A);
}

void func_80800168_bsbpeck(PlayerState* self)
{
    f32 sp24;

    sp24 = 1.0f;
    switch (self->unk160.word)
    {
        case 0:
            sp24 = 1.13f;
            break;
        case 1:
            sp24 = 1.1f;
            break;
        case 2:
            sp24 = 1.32f;
            break;
    }
    baflag_set(self, BA_FLAG_5_HAS_PECKED);
    func_8009DE38(self, 0x442C, sp24);
    baphysics_set_vertical_velocity(self, 120.0f);
    self->unk160.word += 1;
}

void bsbpeck_entrypoint_1(PlayerState* self)
{
    BanjoStateId next_state;
    AnimCtrl* anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bswalk_entrypoint_1(self);
    if (self->unk164.word != 0)
    {
        baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self) * 0.1f);
    }
    switch (self->unk15C.word) {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.9126f))
            {
                anctrl_setIndex(anim_ctrl, 0x19);
                anctrl_setStart(anim_ctrl, 0.0f);
                anctrl_setDuration(anim_ctrl, 0.35f);
                anctrl_setPlaybackType(anim_ctrl, 2);
                anctrl_start(anim_ctrl);
                self->unk15C.word = 1;
                self->unk16C = 0.5f;
            }
            break;
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.1621f))
            {
                func_80800168_bsbpeck(self);
            }
            if (anctrl_isAt(anim_ctrl, 0.7f))
            {
                func_80800168_bsbpeck(self);
            }
            self->unk16C -= time_getDelta();
            if (self->unk16C < 0.0f)
            {
                anctrl_reset(anim_ctrl);
                anctrl_setSmoothTransition(anim_ctrl, 0);
                anctrl_setIndex(anim_ctrl, 0x1A);
                func_8008B188(anim_ctrl, 0);
                anctrl_setDuration(anim_ctrl, 0.2f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                anctrl_start(anim_ctrl);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            if (anctrl_isStopped(anim_ctrl))
            {
                next_state = BS_STATE_2F_FALL;
            }
            break;
    }
    if (player_isStable(self))
    {
        func_8009FE58(self);
        next_state = BS_STATE_1_IDLE;
    }
    if (player_inWater(self))
    {
        next_state = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, next_state);
}

void bsbpeck_entrypoint_2(PlayerState* arg0) {
    baflag_clear(arg0, 0x2A);
    func_800C6DA0(0x46);
    func_8009E474(arg0);
    func_800A0CF4(arg0, 0);
    baphysics_reset_gravity(arg0);
}

s32 bsbpeck_entrypoint_3(s32 arg0) {
    return D_808004A0_bsbpeck[arg0];
}
