#include "bs/turn.h"

extern s32 D_80800360_bsturn[];

void bsturn_entrypoint_0(PlayerState* self)
{
    AnimCtrl* temp_v0;
    f32 sp28[3];

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0xE);
    anctrl_setDuration(temp_v0, 0.3f);
    func_8008B1C8(temp_v0, 0.1f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
    func_8009D2D8(self, 2);
    baphysics_set_type(self, BA_PHYSICS_3_LOCKED_ROTATION);
    func_8009BB24(self, &sp28);
    self->unk16C = sqrtf((sp28[0] * sp28[0]) + (sp28[2] * sp28[2]));
    func_8009DEC0(self, 0x411, 0.95f, 1.05f, 0x7530, 0x7D00);
    self->unk15C.word = 0;
}

void bsturn_entrypoint_1(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp2C[3];

    nextState = BS_STATE_0_INVALID;
    baphysics_set_target_horizontal_velocity(self, ml_map_f(anctrl_getAnimTimer(baanim_getAnimCtrlPtr(self)), 0.18f, 1.0f, self->unk16C, 0.0f));
    self->unk15C.word++;
    if (self->unk15C.word >= 6)
    {
        self->unk15C.word = -1;
    }
    switch (self->unk15C.word)
    {
        case -1:
            sp2C[1] = func_8009BB18(self);
            _badust_entrypoint_3(self, sp2C[1] - 10.0f, baphysics_get_horizontal_velocity(self) * 0.88f);
            break;
        case 0:
            sp2C[1] = func_8009BB18(self);
            _badust_entrypoint_3(self, sp2C[1], baphysics_get_horizontal_velocity(self));
            break;
        case 1:
            sp2C[1] = func_8009BB18(self);
            _badust_entrypoint_3(self, sp2C[1] + 10.0f, baphysics_get_horizontal_velocity(self) * 0.88f);
            break;
    }
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0)
    {
        nextState = BS_STATE_4_RUN;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        nextState = BS_STATE_7_CROUCH;
    }
    if (bakey_pressed(self, BUTTON_B) != 0)
    {
        nextState = bs_getTypeOfGroundedAttack(self, nextState);
    }
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        nextState = bs_getTypeOfJump(self);
    }
    bs_setState(self, nextState);
}

void bsturn_entrypoint_2(PlayerState* self)
{
    yaw_set(self, func_800136E4(yaw_get(self) - 180.0f));
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

s32 bsturn_entrypoint_3(s32 arg0)
{
    return D_80800360_bsturn[arg0];
}
