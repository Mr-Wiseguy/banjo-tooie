#include "bs/crouch.h"

extern s32 D_80800990_bscrouch[];

BanjoStateId bscrouch_entrypoint_4(PlayerState* self, BanjoStateId arg1);

void func_80800000_bscrouch(PlayerState* self) {
    baanim_playForDuration_loopSmooth(self, 0x10C, 0.5f);
    self->unk15C.word = 4;
}

void func_80800034_bscrouch(PlayerState* self) {
    baanim_playForDuration_onceSmooth(self, 0x116, 2.0f);
    self->unk15C.word = 2;
}

void func_80800068_bscrouch(PlayerState* self) {
    baanim_playForDuration_onceSmoothStartingAt(self, 0x10C, 0.5f, 0.9999f);
    _batimer_set(self, 2, 2.0f);
    self->unk15C.word = 1;
}

void func_808000B4_bscrouch(AnimCtrl* self, f32 arg1) {
    anctrl_setDuration(self, ml_map_f(arg1, 0.0f, 180.0f, 0.5f, 0.2f));
}

void func_808000FC_bscrouch(PlayerState* self, AnimCtrl* arg1) {
    func_800A2CE8(self, 0.41f, 4);
    func_800A2CE8(self, 0.91f, 3);
}

void bscrouch_entrypoint_0(PlayerState* self) {
    AnimCtrl* sp3C;
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    sp3C = baanim_getAnimCtrlPtr(self);
    switch (bs_getPreviousState(self))
    {
    default:
        sp2C = 0.0f;
        break;
    case BS_STATE_9_EGG_SHOOT_FORWARD:
    case BS_STATE_A_EGG_SHOOT_BACKWARD:
    case BS_STATE_1A_WONDERWING_START:
        sp2C = 0.5357f;
    }

    anctrl_reset(sp3C);
    anctrl_setIndex(sp3C, 1);
    anctrl_setDuration(sp3C, 0.5f);
    anctrl_setPlaybackType(sp3C, 1);
    anctrl_setStart(sp3C, sp2C);
    anctrl_start(sp3C);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
    yaw_setVelocityBounded(self, 350.0f, 14.0f);
    func_8009D2D8(self, 7);
    func_8009CFD8(self, 8.0f);
    baphysics_set_type(self, BA_PHYSICS_3_LOCKED_ROTATION);
    _batimer_set(self, 0, 0.7f);
    _batimer_set(self, 1, 0.2f);
    func_8009BB24(self, sp30);
    self->unk16C = sqrtf((sp30[0] * sp30[0] + (sp30[2] * sp30[2])));
    if (self->unk16C > 140.0f)
    {
        func_8009D658(self);
    }
    if (func_800F1EA4(sp30, &sp28) != 0)
    {
        baphysics_set_target_yaw(self, sp28);
    }
    self->unk15C.word = 0;
}

void bscrouch_entrypoint_1(PlayerState* self)
{
    BanjoStateId nextState;
    f32 temp_f0;
    AnimCtrl* sp34;
    f32 temp_f0_2;
    s32 pad;
    f32 sp28;

    nextState = BS_STATE_0_INVALID;
    sp34 = baanim_getAnimCtrlPtr(self);
    _batimer_decrement(self, 0);
    _batimer_decrement(self, 1);
    temp_f0 = ml_map_f(_batimer_get(self, 0), 0.0f, 0.3f, 0.0f, self->unk16C);
    baphysics_set_target_horizontal_velocity(self, temp_f0);
    if (temp_f0 > 220.0f) {
        _badust_entrypoint_9(self);
    }
    if (temp_f0 > 160.0f) {
        func_8009D658(self);
    }
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    sp28 = yaw_getIdeal(self);
    temp_f0_2 = mlAbsF(func_800F1DCC(sp28, yaw_get(self)));
    switch (self->unk15C.word)
    {
    case 0:
        if (temp_f0 == 0.0f)
        {
            _batimer_set(self, 2, 2.0f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (temp_f0_2 != 0.0f)
        {
            func_80800000_bscrouch(self);
        }
        else
        {
            _batimer_decrement(self, 2);
            if (_batimer_isZero(self, 2) != 0) {
                func_80800034_bscrouch(self);
            }
        }
        break;
    case 2:
        if (temp_f0_2 != 0.0f) {
            func_80800000_bscrouch(self);
        }
        else if (anctrl_isStopped(sp34) != 0)
        {
            func_80800068_bscrouch(self);
        }
        break;
    case 4:
        func_808000B4_bscrouch(sp34, temp_f0_2);
        func_808000FC_bscrouch(self, sp34);
        if (temp_f0_2 == 0.0f)
        {
            if (anctrl_getAnimTimer(sp34) <= 0.5f)
            {
                anctrl_setSubrange(sp34, 0.0f, 0.5f);
            }
            else
            {
                anctrl_setSubrange(sp34, 0.0f, 1.0f);
            }
            anctrl_setPlaybackType(sp34, 1);
            self->unk15C.word = 3;
        }
        break;
    case 3:
        func_808000B4_bscrouch(sp34, temp_f0_2);
        func_808000FC_bscrouch(self, sp34);
        if (temp_f0_2 != 0.0f)
        {
            anctrl_setSubrange(sp34, 0.0f, 1.0f);
            anctrl_setPlaybackType(sp34, 2);
            self->unk15C.word = 4;
        }
        else if (anctrl_isStopped(sp34) != 0)
        {
            yaw_setIdeal(self, yaw_get(self));
            func_80800068_bscrouch(self);
        }
        break;
    }
    if (func_8008E148(self) != 0)
    {
        nextState = _badrone_entrypoint_25(self);
    }
    if (func_8008DD04(self) != 0)
    {
        nextState = BS_STATE_2F_FALL;
    }
    nextState = bscrouch_entrypoint_4(self, nextState);
    if ((nextState == BS_STATE_1_IDLE) && (_batimer_isNonzero(self, 1) != 0))
    {
        nextState = BS_STATE_0_INVALID;
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, nextState);
}

void bscrouch_entrypoint_2(PlayerState* self)
{
}
s32 bscrouch_entrypoint_3(s32 arg0) {
    return D_80800990_bscrouch[arg0];
}

s32 func_808006A4_bscrouch(PlayerState* self)
{
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;
    s32 temp_v0;

    sp24 = _bapackctrl_entrypoint_1(self);
    player_getCoords(self, sp34);
    temp_v0 = func_800CB7C4(sp24, sp34, sp28);
    if (temp_v0 == 2)
    {
        yaw_setIdeal(self, func_800F1DF4(sp34, sp28));
    }
    return temp_v0;
}
BanjoStateId bscrouch_entrypoint_4(PlayerState* self, BanjoStateId arg1)
{
    if (bakey_released(self, BUTTON_Z))
    {
        arg1 = BS_STATE_1_IDLE;
        if (bakey_pressed(self, BUTTON_B))
        {
            arg1 = bs_getTypeOfGroundedAttack(self, arg1);
        }
        if (bakey_pressed(self, BUTTON_A))
        {
            arg1 = bs_getTypeOfJump(self);
        }
        return arg1;
    }
    else if (player_isSplitUp(self) != 0)
    {
        if ((bakey_pressed(self, BUTTON_C_DOWN) != 0) && (ability_getValue(ABILITY_21_SHACK_PACK)))
        {
            arg1 = BS_STATE_16A_SHACK_PACK_ENTER;
        }
        else if ((bakey_pressed(self, BUTTON_C_UP) != 0) && (ability_getValue(ABILITY_2A_SACK_PACK)))
        {
            arg1 = BS_STATE_163_SACK_ENTER;
        }
        else if ((bakey_pressed(self, BUTTON_C_RIGHT) != 0) && (ability_getValue(ABILITY_23_SNOOZE_PACK)))
        {
            arg1 = BS_STATE_171_SNOOZE_ENTER;
        }
        else if ((bakey_pressed(self, BUTTON_C_LEFT) != 0) && (ability_getValue(ABILITY_27_TAXI_PACK)))
        {
            if (func_8008E0C8(self) == 0)
            {
                arg1 = 0x122;
            }
            else
            {
                switch (func_808006A4_bscrouch(self))
                {
                case 0:
                    break;
                case 1:
                    arg1 = 0x129;
                    break;
                case 2:
                    arg1 = 0x128;
                    break;
                }
            }
        }
        if (bakey_pressed(self, BUTTON_A) != 0)
        {
            arg1 = 0x6C;

        }
        return arg1;
    }
    else
    {
        if (bainput_should_wonderwing(self))
        {
            _suinv_entrypoint_0(&arg1, -1, 0x1A, 0x47, 1);
        }
        if (bainput_should_trot(self))
        {
            arg1 = BS_STATE_14_TTROT_ENTER;
        }
        if ((bainput_should_poop_egg(self)) && (func_80094B14(self)))
        {
            arg1 = BS_STATE_A_EGG_SHOOT_BACKWARD;
        }
        if ((bainput_should_shoot_egg(self)) && (func_80094B14(self)))
        {
            arg1 = BS_STATE_9_EGG_SHOOT_FORWARD;
        }
        if (bainput_should_flap_flip(self))
        {
            arg1 = BS_STATE_12_FLAP_FLIP;
        }
        if (bainput_should_beak_barge(self))
        {
            arg1 = 0x13;
        }
        return arg1;
    }

}