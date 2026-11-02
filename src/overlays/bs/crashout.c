#include "bs/crashout.h"

extern s32 D_808003D0_bscrashout[];

void func_80800000_bscrashout(PlayerState* self)
{
    if (baanim_isAt(self, 0.3659f) != 0)
    {
        func_8009DB04(self, 0x417, 1.0f, 0x36B0);
    }
    if (baanim_isAt(self, 0.6862f) != 0)
    {
        func_8009DB04(self, 0x417, 0.8f, 0x4650);
        func_8009DB04(self, 0x427, 1.0f, 0x55F0);
    }
    if (baanim_getTimer(self) < 0.8f)
    {
        _badust_entrypoint_9(self);
    }
}

void func_808000B0_bscrashout(PlayerState* self, s32 arg1)
{
    self->unk15C.word = arg1;
    switch (arg1)
    {
        case 1:
            baanim_playForDuration_onceSmooth(self, 0x3E, 1.4f);
            func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_3_LOCKED_ROTATION);
            baphysics_set_target_yaw(self, yaw_getIdeal(self));
            baphysics_set_target_horizontal_velocity(self, self->unk16C);
            baphysics_set_horizontal_velocity(self, 100.0f, self->unk16C);
            return;
        case 2:
            func_800951B4(self);
            baanim_playForDuration_onceSmooth(self, 0xD2, 2.25f);
            return;
        case 3:
            func_800A0180(self);
            func_800A4DFC(self, 0xA);
            _ncbadie_entrypoint_3(func_800A4CA8(self), 30.0f);
            _basudie_entrypoint_1(self);
            _batimer_set(self, 0, 3.2f);
            return;
    }
}

void bscrashout_entrypoint_0(PlayerState* self)
{
    func_8009BD88(self);
    func_8008E95C(self);
    func_800951B4(self);
}

void bscrashout_entrypoint_1(PlayerState* self) {
    yaw_setIdeal(self, func_80099A34(self));
    yaw_applyIdeal(self);
    func_8009D89C(self, 1.0f);
    _bamotor_entrypoint_1(self, 1.0f, 0.5f, 0.5f);
    func_8008E944(self);
    func_8009514C(self);
    self->unk15C.word = 0;
    self->unk16C = 600.0f;
    func_808000B0_bscrashout(self, 1);
}

void bscrashout_entrypoint_2(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    ml_timer_update(&self->unk16C, time_getDelta() * 300.0f);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);

    switch (self->unk15C.word)
    {
        case 1:
            func_80800000_bscrashout(self);
            if ((baanim_isAt(self, 0.2f) != 0) && (player_getCurrentHealth(self) == 0))
            {
                func_808000B0_bscrashout(self, 3);
            }
            if (baanim_isStopped(self) != 0)
            {
                func_808000B0_bscrashout(self, 2);
            }
            break;
        case 2:
            if (baanim_isStopped(self) != 0)
            {
                nextState = BS_STATE_1_IDLE;
            }
            break;
        case 3:
            func_80800000_bscrashout(self);
            if (_batimer_decrement(self, 0) != 0)
            {
                _basudie_entrypoint_0(self);
            }
            break;
    }
    bs_setState(self, nextState);
}

s32 bscrashout_entrypoint_3(s32 arg0)
{
    return D_808003D0_bscrashout[arg0];
}