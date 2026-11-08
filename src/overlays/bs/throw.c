#include "bs/throw.h"

s32 D_808002F0_bsthrow[];

void bsthrow_entrypoint_0(PlayerState* self) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x11B);
    anctrl_setDuration(temp_v0, 1.0f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
    func_8009D2D8(self, 3);
    baphysics_set_type(self, BA_PHYSICS_3_LOCKED_ROTATION);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009BA9C(self, NULL);
    self->unk15C.word = 0;
}

void bsthrow_entrypoint_1(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp48;
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    s32 temp_v0;
    Actor* temp_v0_2;

    nextState = BS_STATE_0_INVALID;
    sp48 = baanim_getAnimCtrlPtr(self);
    temp_v0 = _bahold_entrypoint_5(self);
    if ((self->unk15C.word == 0) && (temp_v0 != 0))
    {
        _bahold_entrypoint_6(self, temp_v0);
    }
    player_getCoords(self, sp30);
    func_800A33CC(self, sp3C);
    func_800F1E6C(sp30, sp3C, &sp2C);
    yaw_setIdeal(self, sp2C);
    if ((anctrl_isAt(sp48, 0.35f) != 0) && (temp_v0 != 0))
    {
        self->unk15C.word = 1;
        temp_v0_2 = func_80106790((Unk80132ED0*)temp_v0);
        temp_v0_2->unk64_22 = 1;
    }
    if (anctrl_isStopped(sp48) != 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

void bsthrow_entrypoint_2(PlayerState* self)
{
    self->unk15C.word = 0;
    if (bs_getNextState(self) == BS_STATE_1_IDLE) 
    {
        bastatetimer_set(self, BA_STATE_TIMER_ID_0_UNKNOWN, 0.14f);
        bastatetimer_set(self, BA_STATE_TIMER_ID_1_THROW, 0.28f);
    }
}

s32 bsthrow_entrypoint_3(s32 arg0) {
    return D_808002F0_bsthrow[arg0];
}

void bsthrow_entrypoint_4(PlayerState* self)
{
    switch (func_8009E6EC(self))
    {
    case 18:
        if (self->unk15C.word == 0) 
        {
            func_8008F6B8(self, func_8008E9AC(self));
            return;
        }
        func_8009E830(self, 1);
        return;
    case 21:
    case 28:
    case 29:
    case 30:
    case 37:
        func_8009E830(self, 1);
        return;
    default:
        func_80099B94(self);
        return;
    }
}

