#include "bs/stand.h"

extern u8* D_80800D90_bsstand[];
extern s32 D_80800D98_bsstand[];
extern s32 D_80800DA8_bsstand[];
extern s32 D_80800DB8_bsstand[];

u8* func_80800000_bsstand(PlayerState* self)
{
    return D_80800D90_bsstand[self->unk160.word];
}

s32 func_80800018_bsstand(PlayerState* self, s32 arg1)
{
    arg1 = arg1 + 1;
    if (arg1 >= self->unk164.word)
    {
        arg1 = 0;
    }
    return arg1;
}

BanjoStateId func_80800038_bsstand(PlayerState* self, BanjoStateId arg1)
{
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_1:
        arg1 = BS_STATE_1F_TIPTOE;
        break;
    case BS_STICK_ZONE_ID_2:
        arg1 = BS_STATE_2_SLOW_WALK;
        break;
    case 3:
        arg1 = BS_STATE_3_WALK;
        break;
    case 4:
        arg1 = BS_STATE_4_RUN;
        break;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        arg1 = BS_STATE_7_CROUCH;
    }
    if (bakey_pressed(self, BUTTON_B) != 0)
    {
        arg1 = bs_getTypeOfGroundedAttack(self, arg1);
    }
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = bs_getTypeOfJump(self);
        if (player_canSplitUp(self) != 0)
        {
            arg1 = 0xB8;
        }
        else if (player_canSwap(self) != 0)
        {
            _baduo_entrypoint_12(self);
            return BS_STATE_0_INVALID;
        }
    }
    if (bainput_should_enter_first_person(self) != 0)
    {
        arg1 = _badrone_entrypoint_24(self);
    }
    if (func_8008E148(self) != 0)
    {
        arg1 = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        arg1 = BS_STATE_2D_SWIM_IDLE;
    }
    return func_800A02DC(self, arg1);
}

void bsstand_entrypoint_0(PlayerState* self)
{
    BanjoStateId temp_v0;

    temp_v0 = bs_getPreviousState(self);
    if (func_8009CBDC(self, temp_v0) == 0xA)
    {
        func_80098840(self);
    }
    if (temp_v0 == 0x5B)
    {
        baanim_playForDuration_once(self, 0x6F, 5.5f);
    }
    else
    {
        baanim_playForDuration_onceSmooth(self, 0x6F, 5.5f);
    }
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
    if (player_isSplitUp(self) != 0)
    {
        self->unk160.word = 0;
        self->unk164.word = 6;
    }
    else {
        self->unk160.word = 1;
        self->unk164.word = 0x15;
    }
    self->unk15C.word = 0;
    self->unk168.word = 0;
}

void func_80800274_bsstand(PlayerState* self, AnimCtrl* arg1)
{
    if (anctrl_isAt(arg1, 0.2057f) != 0)
    {
        func_8009DF94(self, 0x418, 1.8f, 0x3E80);
        _bamotor_entrypoint_1(self, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(arg1, 0.2057f) != 0)
    {
        func_8009514C(self);
    }
    if (anctrl_isAt(arg1, 0.2555f) != 0)
    {
        func_8009DF94(self, 0x418, 1.8f, 0x3E80);
        _bamotor_entrypoint_1(self, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(arg1, 0.2896f) != 0)
    {
        func_8009DF94(self, 0x418, 1.8f, 0x3E80);
        _bamotor_entrypoint_1(self, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(arg1, 0.3f) != 0)
    {
        func_8009DF94(self, 0x445, 1.0f, 0x6D60);
    }
    if (anctrl_isAt(arg1, 0.3607f) != 0)
    {
        func_800951B4(self);
    }
    if (anctrl_isAt(arg1, 0.4183f) != 0)
    {
        func_8009DF58(self, 0x43EF, 1.6f);
    }
    if (anctrl_isAt(arg1, 0.455f) != 0)
    {
        func_8009DF58(self, 0x43EF, 1.45f);
    }
    if (anctrl_isAt(arg1, 0.49f) != 0)
    {
        func_8009DF58(self, 0x43EF, 1.4f);
    }
    if (anctrl_isAt(arg1, 0.5397f) != 0)
    {
        func_800909EC(self);
    }
    if (anctrl_isAt(arg1, 0.6619f) != 0)
    {
        func_8009DF94(self, 0x418, 1.8f, 0x3E80);
        _bamotor_entrypoint_1(self, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(arg1, 0.6688f) != 0)
    {
        func_8009514C(self);
    }
    if (anctrl_isAt(arg1, 0.6964f) != 0)
    {
        func_8009DF94(self, 0x418, 1.8f, 0x3E80);
        _bamotor_entrypoint_1(self, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(arg1, 0.7747f) != 0)
    {
        func_800951B4(self);
    }
    if (anctrl_isAt(arg1, 0.7822f) != 0)
    {
        func_8009DF94(self, 0x449, 1.0f, 0x36B0);
    }
    if (anctrl_isAt(arg1, 0.8322f) != 0)
    {
        func_8009DF94(self, 0x449, 1.0f, 0x36B0);
    }
    if (anctrl_isAt(arg1, 0.8669f) != 0)
    {
        func_8009DF94(self, 0x449, 1.0f, 0x36B0);
    }
    if (anctrl_isAt(arg1, 0.9048f) != 0)
    {
        func_8009DF94(self, 0x449, 1.0f, 0x36B0);
    }
    if (anctrl_isAt(arg1, 0.9649f) != 0)
    {
        func_800909EC(self);
    }
}

void bsstand_entrypoint_1(PlayerState* arg0)
{
    BanjoStateId nextState;
    AnimCtrl* sp28;
    f32 sp24;
    s32 var_v1;

    sp28 = baanim_getAnimCtrlPtr(arg0);
    if ((bastick_getZone(arg0) == BS_STICK_ZONE_ID_0) && (bastick_distance(arg0) > 0.0f))
    {
        arg0->unk168.word = 1;
        yaw_setUpdateType(arg0, YAW_TYPE_3_BOUNDED);
        yaw_setVelocityBounded(arg0, 200.0f, 14.0f);
    }
    else
    {
        if (arg0->unk168.word != 0)
        {
            yaw_setIdeal(arg0, yaw_get(arg0));
        }
        arg0->unk168.word = 0;
        yaw_setUpdateType(arg0, YAW_TYPE_1_DEFAULT);
    }
    nextState = func_80800038_bsstand(arg0, 0);
    var_v1 = func_80800000_bsstand(arg0)[arg0->unk15C.word];
    if (var_v1 & 8)
    {
        if (var_v1 & 4)
        {
            if (anctrl_isAt(sp28, 0.0909f) != 0)
            {
                func_8009D874(arg0);
            }
            if (anctrl_isAt(sp28, 0.0909f) != 0)
            {
                func_800A0CF4(arg0, 1);
            }
            if (anctrl_isAt(sp28, 0.6818f) != 0)
            {
                func_800A0CF4(arg0, 0);
            }
        }
        if (var_v1 & 2)
        {
            if (anctrl_isAt(sp28, 0.7727f) != 0)
            {
                func_800A0CF4(arg0, 1);
            }
            if (anctrl_isAt(sp28, 0.9999f) != 0)
            {
                func_800A0CF4(arg0, 0);
            }
        }
    }
    else if (var_v1 & 0x20)
    {
        if (anctrl_getIndex(sp28) == 0x95)
        {
            func_80800274_bsstand(arg0, sp28);
            if (anctrl_isAt(sp28, 0.37f) != 0)
            {
                anctrl_reset(sp28);
                func_8008B1C8(sp28, 0.1f);
                anctrl_setIndex(sp28, 0xF6);
                anctrl_setDuration(sp28, 5.0f);
                anctrl_setPlaybackType(sp28, 1);
                anctrl_start(sp28);
            }
        }
        else
        {
            if (anctrl_isAt(sp28, 0.069f) != 0)
            {
                func_8009DF94(arg0, 0x434, 1.4f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.1677f) != 0)
            {
                func_8009DF94(arg0, 0x4454, 1.0f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.2441f) != 0)
            {
                func_8009DF94(arg0, 0x4454, 1.03f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.3141f) != 0)
            {
                func_8009DF94(arg0, 0x4454, 1.06f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.3859f) != 0)
            {
                func_8009DF94(arg0, 0x4454, 1.5f, 0x7D00);
            }
            if (anctrl_isAt(sp28, 0.414f) != 0)
            {
                func_8009DF18(arg0, 0x41E, 1.0f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.6187f) != 0)
            {
                func_8009DF94(arg0, 0x445B, 1.7f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.7108f) != 0)
            {
                func_8009DF94(arg0, 0x445B, 1.6f, 0x4650);
            }
            if (anctrl_isAt(sp28, 0.7927f) != 0)
            {
                func_8009DF94(arg0, 0x445B, 1.5f, 0x4650);
            }
        }
    }
    else if (var_v1 & 0x10)
    {
        func_80800274_bsstand(arg0, sp28);
    }
    if (anctrl_isAt(sp28, 0.9999f) != 0)
    {
        arg0->unk15C.word = func_80800018_bsstand(arg0, arg0->unk15C.word);
        var_v1 = func_80800000_bsstand(arg0)[arg0->unk15C.word];
        if (var_v1 & 0x10)
        {
            baanim_playForDuration_onceSmooth(arg0, 0x95, 5.5f);
            anctrl_start(sp28);
            func_800A0CF4(arg0, 1);
            func_80090A2C(arg0);
        }
        else if (var_v1 & 0x40)
        {
            baanim_playForDuration_onceSmooth(arg0, 0xAE, 4.3f);
            anctrl_start(sp28);
            func_800A0CF4(arg0, 0);
            func_80090A2C(arg0);
        }
        else if (var_v1 & 0x20)
        {
            baanim_playForDuration_onceSmooth(arg0, 0x95, 5.5f);
            func_800A0CF4(arg0, 1);
            func_80090A2C(arg0);
        }
        else if (var_v1 & 8)
        {
            if (anctrl_getIndex(sp28) == 0x6F)
            {
                sp24 = anctrl_getAnimTimer(sp28);
            }
            else
            {
                sp24 = 0.0f;
                func_800909CC(arg0);
            }
            anctrl_reset(sp28);
            anctrl_setIndex(sp28, 0x6F);
            anctrl_setDuration(sp28, 5.5f);
            anctrl_setPlaybackType(sp28, 2);
            anctrl_setStart(sp28, sp24);
            anctrl_start(sp28);
            func_800A0CF4(arg0, 0);
        }
    }
    if (func_8008DD04(arg0) != 0)
    {
        nextState = BS_STATE_2F_FALL;
    }
    bs_setState(arg0, nextState);
}

void bsstand_entrypoint_2(PlayerState* self)
{
    func_800A0CF4(self, 0);
    func_80090A2C(self);
    func_800951B4(self);
}

s32 bsstand_entrypoint_3(s32 arg0) {
    return D_80800D98_bsstand[arg0];
}

void bsstand_entrypoint_4(PlayerState* self)
{
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void bsstand_entrypoint_5(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* temp_v0;

    nextState = BS_STATE_0_INVALID;
    temp_v0 = baanim_getAnimCtrlPtr(self);
    if (anctrl_getIndex(temp_v0) == 0xD2)
    {
        if (anctrl_isAt(temp_v0, 0.8264f) != 0)
        {
            func_8009DF18(self, 0x449, 1.0f, 0x36B0);
        }
        if (anctrl_isAt(temp_v0, 0.8864f) != 0)
        {
            func_8009DF18(self, 0x449, 1.0f, 0x36B0);
        }
    }
    if (anctrl_isStopped(temp_v0) != 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, func_80800038_bsstand(self, nextState));
}

void bsstand_entrypoint_6(s32 arg0) 
{
}

s32 bsstand_entrypoint_7(s32 arg0)
{
    return D_80800DA8_bsstand[arg0];
}

BanjoStateId bsstand_entrypoint_8(PlayerState* self, BanjoStateId state)
{
    return func_80800038_bsstand(self, state);
}

void bsstand_entrypoint_9(PlayerState* self)
{
    _bsdrone_entrypoint_0(self);
}

void bsstand_entrypoint_10(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstand_entrypoint_11(PlayerState* self)
{
    _bafpctrl_entrypoint_10(self,0);
    _bsdrone_entrypoint_2(self);
}

s32 bsstand_entrypoint_12(s32 arg0)
{
    return D_80800DB8_bsstand[arg0];
}