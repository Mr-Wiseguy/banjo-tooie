#include "bs/talk.h"

extern s32 D_80800170_bstalk[];

void bstalk_entrypoint_0(PlayerState* self)
{
    AnimCtrl* sp3C;
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    sp3C = baanim_getAnimCtrlPtr(self);
    anctrl_reset(sp3C);
    func_800A0110(self, sp3C);
    anctrl_setPlaybackType(sp3C, 2);
    anctrl_start(sp3C);
    player_getCoords(self, sp2C);
    func_800A33A0(self, sp20);
    func_800F1E6C(sp2C, sp20, &sp38);
    yaw_setIdeal(self, sp38);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
    func_8009D2D8(self, 3);
    baphysics_set_type(self, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    self->unk15C.word = 1;
}

void bstalk_entrypoint_1(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (self->unk15C.word == 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    self->unk15C.word = 0;
    bs_setState(self, nextState);
}

void bstalk_entrypoint_2(s32 arg0) {}

s32 bstalk_entrypoint_3(s32 arg0) 
{
    return D_80800170_bstalk[arg0];
}

void bstalk_entrypoint_4(PlayerState* self)
{
    if (func_8009E6EC(self) == 8)
    {
        self->unk15C.word = 1;
        func_8009E830(self, 2);
        return;
    }
    func_80099B94(self);
}