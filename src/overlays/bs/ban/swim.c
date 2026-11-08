#include "bs/ban/swim.h"

extern s32 D_80800A30_bsbanswim[];
extern s32 D_80800A40_bsbanswim[];
extern s32 D_80800A50_bsbanswim[];
extern s32 D_80800A60_bsbanswim[];

void func_80800000_bsbanswim(PlayerState* self)
{
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_9_NO_GRAVITY);
}

void func_80800030_bsbanswim(PlayerState* self)
{
    if (func_8009E77C(self, 0xB) == 0)
    {
        _baswim_entrypoint_5(self);
        baroll_setAngularVelocity(self, 130.0f, 0.9f);
        baphysics_set_gravity(self, 0.0f);
        baphysics_set_terminal_velocity(self, -399.99f);
        if (bs_getSplitStatus() != SPLIT_STATE_TALON_TORPEDO)
        {
            func_800A0CF4(self, 1);
        }
        func_800961AC(self, 3);
        func_80093360(self, 60.0f);
        func_8009BC5C(self, 2.0f);
        _baswim_entrypoint_6(self, 1);
        if (bs_getCurrentState(self) != BS_STATE_4C_LANDING_IN_WATER)
        {
            _baairbar_entrypoint_0(self, 2);
        }
    }
}

void func_80800104_bsbanswim(PlayerState* self) {
    if (func_8009E74C(self, 0xB) == 0) {
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009BC34(self);
        func_800A0CF4(self, 0);
        func_800961AC(self, 1);
        func_80093360(self, 0.0f);
        _baswim_entrypoint_6(self, 0);
        if (bs_getCurrentState(self) != BS_STATE_4C_LANDING_IN_WATER) {
            _baairbar_entrypoint_0(self, 1);
        }
        _baswim_entrypoint_4(self);
    }
}
void func_808001A8_bsbanswim(PlayerState* self)
{
    func_80800104_bsbanswim(self);
}

void func_808001C8_bsbanswim(PlayerState* self) {
    func_800C6DA0(0x3F);
    baanim_playForDuration_onceSmoothStartingAt(self, 0x27D, 1.7f, 0.1f);
    func_80800000_bsbanswim(self);
    yaw_setVelocityBounded(self, 500.0f, 5.0f);
    func_80800030_bsbanswim(self);
    _baswim_entrypoint_10(self, 0.0f);
    _baswim_entrypoint_8(self, 600.0f);
    func_8009BFE4(self, 200.0f, 2.5f);
    self->unk164.bytes[0] = 0;
}

void func_8080025C_bsbanswim(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp20;
    u8 temp_v1;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    temp_v1 = self->unk164.bytes[0];
    switch (temp_v1) 
    {
    case 0:
        func_8009BF5C(self, 50.0f);
        if (anctrl_isAt(sp20, 0.37f) != 0) {
            if (_baswim_entrypoint_1(self) != 0) {
                func_800A0E64(self);
            }
            _baswim_entrypoint_10(self, 300.0f);
            _baswim_entrypoint_8(self, 200.0f);
            self->unk164.bytes[0] = 1;
        }
        break;
    case 1:
        _baswim_entrypoint_11(self);
        _baswim_entrypoint_13(self);
        if (anctrl_isAt(sp20, 0.76f) != 0) {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    }
    if (anctrl_isAt(sp20, 0.6f) != 0) {
        func_8009DE38(self, 0x3FD, 1.0f);
    }
    if (player_inWater(self) == 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanswim_entrypoint_0(s32 arg0) {
    return D_80800A30_bsbanswim[arg0];
}

s32 func_80800390_bsbanswim(BanjoStateId arg0)
{
    if ((arg0 == 0x81) || (arg0 == 0x82) || (arg0 == 0x90))
    {
        return 1;
    }
    return 0;
}

void func_808003BC_bsbanswim(PlayerState* self)
{
    if (func_80800390_bsbanswim(bs_getNextState(self)) == 0)
    {
        if (func_8008E0E8(self) != 0) {
            _bapackctrl_entrypoint_5(self, 3);
        }
        func_80800104_bsbanswim(self);
    }
}

void func_8080040C_bsbanswim(PlayerState* self)
{
    if (func_80800390_bsbanswim(bs_getPreviousState(self)) == 0)
    {
        baanim_playForDuration_loopSmooth(self, 0x27E, 0.75f);
        func_80800000_bsbanswim(self);
        func_80800030_bsbanswim(self);
        _baswim_entrypoint_10(self, 0.0f);
        _baswim_entrypoint_8(self, 600.0f);
        func_8009BC5C(self, 2.0f);
        if (func_8008E0E8(self) != 0)
        {
            _bapackctrl_entrypoint_5(self, 4);
        }
    }
}

void func_8080049C_bsbanswim(PlayerState* self)
{
    func_808003BC_bsbanswim(self);
}

void func_808004BC_bsbanswim(PlayerState* self) {
    AnimCtrl* sp1C;

    sp1C = baanim_getAnimCtrlPtr(self);
    func_8080040C_bsbanswim(self);
    anctrl_setDuration(sp1C, 1.0f);
}

void func_808004F4_bsbanswim(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp20;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(sp20, 0.512f) != 0) {
        _baswim_entrypoint_10(self, 320.0f);
    }
    else {
        _baswim_entrypoint_10(self, 250.0f);
    }
    if (anctrl_isAt(sp20, 0.17f) != 0) {
        func_8009DF18(self, 0x3FD, 1.9f, 0x2710);
    }
    if (anctrl_isAt(sp20, 0.67f) != 0) {
        func_8009DF18(self, 0x3FD, 1.7f, 0x2710);
    }
    switch (_baswim_entrypoint_3(self)) {
    case 1:
        break;
    case 0:
        if (anctrl_isAt(sp20, 0.99f) != 0) {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    case 2:
        nextState = 0x82;
        break;
    case 3:
        nextState = 0x90;
        break;
    }
    if (_baswim_entrypoint_2(self) != 0) {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (player_inWater(self) == 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanswim_entrypoint_1(s32 arg0) {
    return D_80800A40_bsbanswim[arg0];
}

void func_80800670_bsbanswim(PlayerState* self)
{
    func_808003BC_bsbanswim(self);
}

void func_80800690_bsbanswim(PlayerState* self) {
    AnimCtrl* sp1C;

    sp1C = baanim_getAnimCtrlPtr(self);
    func_8080040C_bsbanswim(self);
    anctrl_setDuration(sp1C, 0.8f);
}

void func_808006CC_bsbanswim(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp20;
    s32 temp_v0;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(sp20, 0.512f) != 0) {
        _baswim_entrypoint_10(self, 450.0f);
    }
    else {
        _baswim_entrypoint_10(self, 300.0f);
    }
    if (anctrl_isAt(sp20, 0.17f) != 0) {
        func_8009DF18(self, 0x3FD, 1.9f, 0x2710);
    }
    if (anctrl_isAt(sp20, 0.67f) != 0) {
        func_8009DF18(self, 0x3FD, 1.7f, 0x2710);
    }
    temp_v0 = _baswim_entrypoint_3(self);
    switch (temp_v0) {                              /* irregular */
    case 2:
        break;
    case 0:
        if (anctrl_isAt(sp20, 0.99f) != 0) {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    case 1:
        nextState = 0x81;
        break;
    case 3:
        nextState = 0x90;
        break;
    }
    if (_baswim_entrypoint_2(self) != 0) {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (player_inWater(self) == 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanswim_entrypoint_2(s32 arg0) {
    return D_80800A50_bsbanswim[arg0];
}
void func_80800848_bsbanswim(PlayerState* self)
{
    func_808003BC_bsbanswim(self);
}

void func_80800868_bsbanswim(PlayerState* self) 
{
    AnimCtrl* sp1C;

    sp1C = baanim_getAnimCtrlPtr(self);
    func_8080040C_bsbanswim(self);
    anctrl_setDuration(sp1C, 0.7f);
}

void func_808008A4_bsbanswim(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp20;
    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(sp20, 0.512f) != 0)
    {
        _baswim_entrypoint_10(self, 600.0f);
    }
    else
    {
        _baswim_entrypoint_10(self, 400.0f);
    }
    if (anctrl_isAt(sp20, 0.17f) != 0)
    {
        func_8009DF18(self, 0x3FD, 1.9f, 0x2710);
    }
    if (anctrl_isAt(sp20, 0.67f) != 0)
    {
        func_8009DF18(self, 0x3FD, 1.7f, 0x2710);
    }
    switch (_baswim_entrypoint_3(self))
    {
    case 3:
        break;
    case 0:
        if (anctrl_isAt(sp20, 0.99f) != 0)
        {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    case 1:
        nextState = 0x81;
        break;
    case 2:
        nextState = 0x82;
        break;
    }
    if (_baswim_entrypoint_2(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (player_inWater(self) == 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanswim_entrypoint_3(s32 arg0) {
    return D_80800A60_bsbanswim[arg0];
}