#include "bs/hock.h"

extern s32 D_80800870_bsbshock[];
extern s32 D_80800880_bsbshock[];

void bsbshock_entrypoint_0(PlayerState* self) {
    AnimCtrl* sp34;
    s32 pad;
    f32 sp2C;
    s32 pad2;

    sp34 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(sp34);
    anctrl_setIndex(sp34, 0x48);
    func_8008B1C8(sp34, 0.4f);
    anctrl_setDuration(sp34, 4.2f);
    anctrl_setSubrange(sp34, 0.0f, 0.1061f);
    anctrl_setPlaybackType(sp34, 1);
    anctrl_start(sp34);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f)
    {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bswalk_entrypoint_1(self);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    func_800A0CE8(self, 1);
    func_800A0CF4(self, 1);
    func_8009D874(self);
    self->unk164.bytes[0] = func_800C2E04();
    func_800C3418(self->unk164.bytes[0], 0);
    func_800C2E40(self->unk164.bytes[0]);
    func_800C330C(self->unk164.bytes[0], 3);
    func_800C301C(self->unk164.bytes[0], 0x41D);
    func_800C3730(self->unk164.bytes[0], 1.4f, 0.4f, -1.2f);
    func_80093300(self, -87.0f);
    func_8009C1B4(self, -87.0f);
    self->unk15C.word = 1;
    self->unk160.word = 0;
}

void bsbshock_entrypoint_1(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    if (player_isStable(self) != 0)
    {
        if ((func_8001211C() % 2))
        {
            func_8009FC80(self);
        }
    }
    else
    {
        func_8009FC80(self);
    }
    _bswalk_entrypoint_1(self);
    func_8009BB24(self, &sp24);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp24[1] > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    switch (self->unk160.word)
    {
    case 0:
        if (func_8008E260(self) != 0)
        {
            nextState = BS_STATE_3D_FALL_TUMBLING;
        }
        if (func_8008DF8C(self, 0x82) != 0)
        {
            anctrl_setSubrange(sp30, 0.0f, 1.0f);
            anctrl_setDuration(sp30, 2.8f);
            anctrl_setPlaybackType(sp30, 1);
            self->unk160.word = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(sp30, 0.11f) != 0)
        {
            func_800C3BDC(self->unk164.bytes[0]);
        }
        if (anctrl_isAt(sp30, 0.4036f) != 0)
        {
            anctrl_setDuration(sp30, 1.4f);
        }
        if (anctrl_isStopped(sp30) != 0)
        {
            nextState = BS_STATE_1_IDLE;
        }
        break;
    }
    if (func_8008DF8C(self, 0x3C) != 0)
    {
        if ((anctrl_getAnimTimer(sp30) < 0.3637f) && (bakey_released(self, BUTTON_A) != 0))
        {
            self->unk15C.word = 0;
        }
        if (player_isStable(self) != 0)
        {
            baphysics_set_target_horizontal_velocity(self, 0.0f);
        }
    }
    else {
        if (bainput_func_80097DF4(self) != 0)
        {
            nextState = BS_STATE_10_FFLAP;
        }
        if (bainput_should_beak_bust(self) != 0)
        {
            nextState = BS_STATE_F_BBUSTER;
        }
    }
    if ((anctrl_isAt(sp30, 0.3637f) != 0) && (self->unk15C.word != 0))
    {
        nextState = 0x22;
    }
    if (anctrl_isAt(sp30, 0.4653f) != 0)
    {
        baphysics_set_vertical_velocity(self, 180.0f);
        func_80093300(self, 0.0f);
        func_8009C1B4(self, 87.0f);
    }
    if ((sp24[1] < 0.0f) && (player_inWater(self) != 0))
    {
        nextState = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, nextState);
}

void bsbshock_entrypoint_2(PlayerState* self)
{
    func_800C2FDC(self->unk164.bytes[0]);
    func_800A0CE8(self, 0);
    func_800A0CF4(self, 0);
    if (func_80092BF4(self) != 0.0f)
    {
        func_80093300(self, 0.0f);
        func_8009C1B4(self, 87.0f);
    }
}

s32 bsbshock_entrypoint_3(s32 arg0)
{
    return D_80800870_bsbshock[arg0];
}

void bsbshock_entrypoint_4(PlayerState* self)
{
    AnimCtrl* sp34;
    s32 pad;
    f32 sp2C;

    sp34 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(sp34);
    anctrl_setSmoothTransition(sp34, 0);
    anctrl_setIndex(sp34, 0x49);
    anctrl_setDuration(sp34, 0.8f);
    anctrl_setStart(sp34, 0.6739f);
    anctrl_setSubrange(sp34, 0.0f, 1.0f);
    anctrl_setPlaybackType(sp34, 1);
    anctrl_start(sp34);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f)
    {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bswalk_entrypoint_1(self);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 1250.0f);
    baphysics_set_gravity(self, -1200.0f);
    func_8009DBF0(self, 0x408, 1.0f);
    func_800A0CE8(self, 1);
    func_800A0CF4(self, 1);
    func_800C6DA0(0x45);
    func_80093300(self, -87.0f);
    func_8009C1B4(self, -87.0f);
    func_8009DF58(self, 0x43A, 1.0f);
    self->unk160.word = 0;
}

void bsbshock_entrypoint_5(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp28[3];
    AnimCtrl* sp24;

    nextState = BS_STATE_0_INVALID;
    sp24 = baanim_getAnimCtrlPtr(self);
    _bswalk_entrypoint_1(self);
    func_8009BB24(self, &sp28);
    if (anctrl_isAt(sp24, 0.7618f) != 0)
    {
        anctrl_setDuration(sp24, 3.0f);
    }
    if ((bakey_released(self, BUTTON_A) != 0) && (sp28[1] > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    if (self->unk160.word == 0)
    {
        func_8009FC80(self);
        if (sp28[1] < 0.0f)
        {
            nextState = BS_STATE_2F_FALL;
        }
    }
    if (player_isStable(self) == 0)
    {
        if (func_8008E260(self) != 0)
        {
            nextState = BS_STATE_3D_FALL_TUMBLING;
        }
        if (bainput_func_80097DF4(self) != 0)
        {
            nextState = BS_STATE_10_FFLAP;
        }
        if (bainput_should_beak_bust(self) != 0)
        {
            nextState = BS_STATE_F_BBUSTER;
        }
        if (player_canGripGrab(self) != 0)
        {
            nextState = BS_STATE_A8_GRIP_GRAB_START;
        }
    }
    bs_setState(self, nextState);
}

void bsbshock_entrypoint_6(PlayerState* self)
{
    if (bs_getNextState(self) != BS_STATE_11_RATATAP)
    {
        baphysics_reset_gravity(self);
    }
    func_800A0CE8(self, 0);
    func_800A0CF4(self, 0);
    func_80093300(self, 0.0f);
    func_8009C1B4(self, 87.0f);
}

s32 bsbshock_entrypoint_7(s32 arg0) {
    return D_80800880_bsbshock[arg0];
}
