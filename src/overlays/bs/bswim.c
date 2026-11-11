#include "bs/bswim.h"

extern s32 D_80801E60_bsbswim[];
extern s32 D_80801E70_bsbswim[];
extern s32 D_80801E80_bsbswim[];
extern s32 D_80801E90_bsbswim[];
extern s32 D_80801EA0_bsbswim[];
extern s32 D_80801EB0_bsbswim[];
extern s32 D_80801EC0_bsbswim[];
extern s32 D_80801ED0_bsbswim[];
extern s32 D_80801EE0_bsbswim[];
extern s32 D_80801EF0_bsbswim[];
extern s32 D_80801F00_bsbswim[];
extern s32 D_80801F10_bsbswim[];
extern s32 D_80801F20_bsbswim;
extern s32 D_80801F78_bsbswim[];
extern s32 D_80801F88_bsbswim[];
extern s32 D_80801F98_bsbswim[];

void func_80800000_bsbswim(PlayerState* self)
{
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_9_NO_GRAVITY);
}

void func_80800030_bsbswim(PlayerState* self)
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

void func_80800104_bsbswim(PlayerState* self)
{
    if (func_8009E74C(self, 0xB) == 0)
    {
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009BC34(self);
        func_800A0CF4(self, 0);
        func_800961AC(self, 1);
        func_80093360(self, 0.0f);
        _baswim_entrypoint_6(self, 0);
        if (bs_getCurrentState(self) != BS_STATE_4C_LANDING_IN_WATER)
        {
            _baairbar_entrypoint_0(self, 1);
        }
        _baswim_entrypoint_4(self);
    }
}

void func_808001A8_bsbswim(PlayerState* self)
{
    func_80800104_bsbswim(self);
}

void func_808001C8_bsbswim(PlayerState* self) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x70);
    anctrl_setDuration(temp_v0, 2.0f);
    func_8008B1C8(temp_v0, 0.5f);
    anctrl_setPlaybackType(temp_v0, 2);
    anctrl_start(temp_v0);
    func_80800000_bsbswim(self);
    func_8009B94C(self, NULL);
    func_80800030_bsbswim(self);
    func_8009BC5C(self, 0.4f);
    _baswim_entrypoint_8(self, 300.0f);
    if (player_isSplitUp(self) != 0) {
        func_800A0CF4(self, 0);
    }
}

void func_80800288_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (player_isSplitUp(self) != 0) 
    {
        if ((bakey_held(self, BUTTON_A) != 0) || (bakey_held(self, BUTTON_B) != 0)) 
        {
            nextState = 0x81;
        }
    }
    else 
    {
        switch (_baswim_entrypoint_3(self))
        {
        case 0:
            break;
        case 1:
            nextState = 0x39;
            break;
        case 2:
            nextState = BS_STATE_2C_SWIM_UNDERWATER_KAZ_PUSH;
            break;
        case 3:
            nextState = BS_STATE_19_SWIM_UNDERWATER_KICK_PUSH;
            break;
        }
        if (bainput_func_8009803C(self) != 0)
        {
            nextState = BS_STATE_157_START_TALON_TORPEDO;
        }
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

s32 bsbswim_entrypoint_0(s32 arg0)
{
    return D_80801E60_bsbswim[arg0];
}

void func_8080039C_bsbswim(PlayerState* self) 
{
    AnimCtrl* sp24;
    f32 var_f2;

    sp24 = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == 0x19) 
    {
        var_f2 = anctrl_getAnimTimer(sp24);
    }
    else {
        var_f2 = 0.5f;
    }
    baanim_playForDuration_loopStartingAt(self, 0x3F, 1.0f, var_f2);
    func_80800000_bsbswim(self);
    func_80800030_bsbswim(self);
    _baswim_entrypoint_8(self, 300.0f);
    func_8009BC5C(self, 1.0f);
    func_800910BC(self, 2);
}

void func_80800440_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp18;

    nextState = BS_STATE_0_INVALID;
    sp18 = baanim_getAnimCtrlPtr(self);
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(sp18, 0.1f) != 0) 
    {
        func_8009DE74(self, 0x3FD, 1.2f, 1.4f);
        _baswim_entrypoint_10(self, 600.0f);
    }
    if (anctrl_isAt(sp18, 0.4626f) != 0) {
        anctrl_setDuration(sp18, 1.0f);
    }
    if (anctrl_isAt(sp18, 0.2766f) != 0) {
        anctrl_setDuration(sp18, 3.0f);
    }
    switch (_baswim_entrypoint_3(self)) 
    {
    case 2:
        break;
    case 0:
        if (anctrl_isAt(sp18, 0.4625f) != 0) {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    case 1:
        nextState = 0x39;
        break;
    case 3:
        nextState = BS_STATE_19_SWIM_UNDERWATER_KICK_PUSH;
        break;
    }
    if ((anctrl_isAt(sp18, 0.4625f) != 0) && (bakey_held(self, BUTTON_B) == 0)) {
        if (bakey_held(self, BUTTON_A) != 0) {
            nextState = 0x39;
        }
        else {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
    }
    if (bainput_func_8009803C(self) != 0) {
        nextState = BS_STATE_157_START_TALON_TORPEDO;
    }
    if (_baswim_entrypoint_2(self) != 0) {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (player_inWater(self) == 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

void func_808005F4_bsbswim(PlayerState* self)
{
    func_800910BC(self,0x1);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_1(s32 arg0)
{
    return D_80801E70_bsbswim[arg0];
}


void func_80800634_bsbswim(PlayerState* self) {
    AnimCtrl* sp24;
    f32 var_f2;

    sp24 = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == BS_STATE_2C_SWIM_UNDERWATER_KAZ_PUSH) {
        var_f2 = anctrl_getAnimTimer(sp24);
    }
    else {
        var_f2 = 0.5f;
    }
    baanim_playForDuration_loopStartingAt(self, 0xEB, 1.0f, var_f2);
    func_80800000_bsbswim(self);
    func_80800030_bsbswim(self);
    _baswim_entrypoint_8(self, 600.0f);
    func_8009BC5C(self, 1.0f);
    func_800910BC(self, 2);
    self->unk164.bytes[2] = 0;
}

void func_808006DC_bsbswim(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp48;
    s32 sp44;
    f32 sp38[3];

    nextState = BS_STATE_0_INVALID;
    sp48 = baanim_getAnimCtrlPtr(self);
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(sp48, 0.3f) != 0)
    {
        self->unk164.bytes[2] = 1;
    }
    if (func_8001210C(1) == 0)
    {
        player_getCoords(self, sp38);
        sp38[1] += 60.0f;
        sp44 = func_8009FBB0(self, sp38, 40.0f);
        func_800BA930((unkStruct800BA198*)sp44, -0x3C, -0x32, -0x3C, 0x3C, 0x64, 0x3C);
        func_800BA22C(sp44, 1);
    }
    if (anctrl_isAt(sp48, 0.08f) != 0)
    {
        func_8009DE74(self, 0x3FD, 1.2f, 1.4f);
        _baswim_entrypoint_10(self, 900.0f);
    }
    else
    {
        _baswim_entrypoint_10(self, 500.0f);
    }
    switch (_baswim_entrypoint_3(self))
    {
    case 3:
        break;
    case 0:
        if (anctrl_isAt(sp48, 0.4791f) != 0)
        {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    case 1:
        if (self->unk164.bytes[2] != 0)
        {
            nextState = 0x39;
        }
        break;
    case 2:
        if (self->unk164.bytes[2] != 0)
        {
            nextState = BS_STATE_2C_SWIM_UNDERWATER_KAZ_PUSH;
        }
        break;
    }
    if (bainput_func_8009803C(self) != 0)
    {
        nextState = BS_STATE_157_START_TALON_TORPEDO;
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

void func_808008CC_bsbswim(PlayerState* self)
{
    func_800910BC(self,0x1);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_2(s32 arg0)
{
    return D_80801E80_bsbswim[arg0];
}

void func_8080090C_bsbswim(PlayerState* self)
{
    baanim_playForDuration_loopSmooth(self, 0x71, 0.75f);
    func_80800000_bsbswim(self);
    func_80800030_bsbswim(self);
    _baswim_entrypoint_10(self, 250.0f);
    _baswim_entrypoint_8(self, 600.0f);
    func_8009BC5C(self, 2.0f);
    func_800910BC(self, 2);
}

void func_8080097C_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp20;
    s32 temp_v0;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    _baswim_entrypoint_10(self, 250.0f);
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
    case 1:
        break;
    case 0:
        if (anctrl_isAt(sp20, 0.4791f) != 0)
        {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    case 2:
        nextState = BS_STATE_2C_SWIM_UNDERWATER_KAZ_PUSH;
        break;
    case 3:
        nextState = BS_STATE_19_SWIM_UNDERWATER_KICK_PUSH;
        break;
    }
    if (bainput_func_8009803C(self) != 0)
    {
        nextState = BS_STATE_157_START_TALON_TORPEDO;
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

void func_80800AD0_bsbswim(PlayerState* self)
{
    func_800910BC(self,0x1);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_3(s32 arg0)
{
    return D_80801E90_bsbswim[arg0];
}

void func_80800B10_bsbswim(PlayerState* self)
{
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];

    _bareact_entrypoint_1(self, func_80099A58(self));
    baanim_playForDuration_once(self, 0x14, 1.4f);
    func_8009D89C(self, 1.0f);
    player_getCoords(self, sp40);
    func_800A32C4(self, sp34);
    func_800F1E6C(sp34, sp40, &sp4C);
    yaw_setIdeal(self, sp4C);
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, _bareact_entrypoint_4(self));
    baphysics_set_target_yaw(self, sp4C);
    baphysics_set_horizontal_velocity(self, sp4C, baphysics_get_target_horizontal_velocity(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    func_8008E944(self);
    func_8009514C(self);
    func_80800030_bsbswim(self);
}

void func_80800C0C_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp38[3];
    s32 sp34;

    nextState = BS_STATE_0_INVALID;
    player_getCoords(self, sp38);
    sp38[1] += 60.0f;
    sp34 = func_8009FBB0(self, sp38, 25.0f);
    func_800BA930((unkStruct800BA198*)sp34, -0x3C, -0x32, -0x3C, 0x3C, 0x64, 0x3C);
    func_800BA22C(sp34, 1);
    if (baanim_isAt(self, 0.3f) != 0)
    {
        func_800951B4(self);
    }
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0)
    {
        nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
    }
    bs_setState(self, nextState);
}

void func_80800CE4_bsbswim(PlayerState* self)
{
    func_8009BD88(self);
    func_8008E95C(self);
    func_800951B4(self);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_4(s32 arg0)
{
    return D_80801EA0_bsbswim[arg0];
}

void func_80800D30_bsbswim(PlayerState* self)
{
    _baspin_entrypoint_1(self);
    func_80800104_bsbswim(self);
}

void func_80800D58_bsbswim(PlayerState* self) 
{
    func_80800030_bsbswim(self);
    _baspin_entrypoint_2(self, 0xB9, 0.7f, 3, 1);
}

void func_80800D98_bsbswim(PlayerState* self) 
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_800914FC(self, 40.0f, 0.0f);
    if (_baspin_entrypoint_3(self) == 2) 
    {
        nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
    }
    bs_setState(self, nextState);
}

s32 bsbswim_entrypoint_5(s32 arg0) 
{
    return D_80801EB0_bsbswim[arg0];
}

void func_80800DFC_bsbswim(PlayerState* self) 
{
    _babounce_entrypoint_3(self);
    func_800961AC(self, 3);
    func_80800104_bsbswim(self);
}

void func_80800E30_bsbswim(PlayerState* self) 
{
    func_80800030_bsbswim(self);
    func_800961AC(self, 1);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0xF, 0.5823f);
}

void func_80800E7C_bsbswim(PlayerState* self) 
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_9(self) != 0)
    {
        nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
    }
    bs_setState(self, nextState);
}

s32 bsbswim_entrypoint_6(s32 arg0) 
{
    return D_80801EC0_bsbswim[arg0];
}

void func_80800EC8_bsbswim(PlayerState* self) {
    func_800C6DA0(0x3F);
    baanim_playForDuration_onceSmooth(self, 0x3C, 1.5f);
    func_80800000_bsbswim(self);
    yaw_setVelocityBounded(self, 500.0f, 5.0f);
    func_8009B94C(self, NULL);
    func_80800030_bsbswim(self);
    _baswim_entrypoint_10(self, 0.0f);
    _baswim_entrypoint_8(self, 600.0f);
    func_8009BFE4(self, 200.0f, 2.5f);
    func_8009D874(self);
    self->unk164.bytes[0] = 0;
}

void func_80800F64_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp20;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    switch (self->unk164.bytes[0])
    {
    case 0:
        func_8009BF5C(self, 50.0f);
        if (anctrl_isAt(sp20, 0.2916f) != 0)
        {
            if (_baswim_entrypoint_1(self) != 0)
            {
                func_800A0E64(self);
            }
            _baswim_entrypoint_10(self, 400.0f);
            _baswim_entrypoint_8(self, 300.0f);
            self->unk164.bytes[0] = 1;
        }
        break;
    case 1:
        _baswim_entrypoint_11(self);
        _baswim_entrypoint_13(self);
        if (anctrl_isAt(sp20, 0.58f) != 0)
        {
            nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
        }
        break;
    }
    if (anctrl_isAt(sp20, 0.6f) != 0)
    {
        func_8009DE38(self, 0x3FD, 1.0f);
    }
    if (player_inWater(self) == 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

void func_80801084_bsbswim(PlayerState* self)
{
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_7(s32 arg0)
{
    return D_80801ED0_bsbswim[arg0];
}

void func_808010B8_bsbswim(PlayerState* self)
{
    s32 var_a1;

    var_a1 = func_8009E6C4(self, 4) != 0;
    if (var_a1 == 0)
    {
        var_a1 = func_800F8B64() != 0;
    }
    self->unk15C.word = var_a1;
    _basudie_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0xB9, 0.7f);
    func_80800000_bsbswim(self);
    func_80800030_bsbswim(self);
    func_8009BC5C(self, 1.0f);
    func_8009B94C(self, NULL);
    func_8009BA9C(self, NULL);
    func_8009BF5C(self, 275.0f);
    baroll_setIdeal(self, 0.0f);
    func_8008E944(self);
    _batimer_set(self, 0, 0.0f);
    _batimer_set(self, 1, 0.0f);
    func_800910BC(self, 3);
    func_8009DF18(self, 0x467, 1.0f, 0x5DC0);
    _baswim_entrypoint_6(self, 0);
}

void func_808011C0_bsbswim(PlayerState* self)
{
    s32 pad;
    f32 sp48[3];
    s32 sp44;
    f32 sp38[3];
    func_800EF4E4(sp48, -90.0f, 0.0f, 0.0f, 0.0f, 100.0f);
    func_8009B94C(self, sp48);
    func_8009BA9C(self, sp48);
    _batimer_increment(self, 1);
    if ((_batimer_isAt_rising(self, 1, 0.2f) != 0) || (_batimer_isAt_rising(self, 1, 0.8f) != 0) || (_batimer_isAt_rising(self, 1, 1.4f) != 0))
    {
        func_8009DF18(self, 0x468, 1.0f, 0x5DC0);
    }
    if (func_8001210C(1) == 0)
    {
        player_getCoords(self, sp38);
        sp38[1] += 60.0f;
        sp44 = func_8009FBB0(self, sp38, 25.0f);
        func_800BA930((unkStruct800BA198*)sp44, -0x3C, -0x32, -0x3C, 0x3C, 0x64, 0x3C);
        func_800BA22C(sp44, 1);
    }
    if (_batimer_isGreaterThan(self, 1, 1.55f) != 0)
    {
        baphysics_set_vertical_velocity(self, -50.0f);
    }
    if (_batimer_isAt_rising(self, 1, 1.9f) != 0)
    {
        func_800A4DA4(self, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(self), 80.0f);
        if (self->unk15C.word != 0) {
            _batimer_set(self, 0, 0.5f);
        }
        else {
            func_800A0180(self);
            _batimer_set(self, 0, 3.5f);
        }
    }
    if (_batimer_decrement(self, 0) != 0) {
        _basudie_entrypoint_0(self);
    }
    bs_setState(self, BS_STATE_0_INVALID);
}

void func_808013C4_bsbswim(PlayerState* self) {
    _baswim_entrypoint_6(self, 1);
    func_800910BC(self, 1);
    func_800A4E30(self);
    func_8008E95C(self);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_8(s32 arg0) {
    return D_80801EE0_bsbswim[arg0];
}

void func_80801428_bsbswim(PlayerState* self) {
    baanim_playForDuration_loopSmooth(self, 0x70, 2.0f);
    func_80800000_bsbswim(self);
    func_8009B94C(self, NULL);
    _baswim_entrypoint_9(self, 0.0f);
    func_8009BA9C(self, NULL);
    func_80800030_bsbswim(self);
    func_800A0024(self);
    _baswim_entrypoint_6(self, 0);
}

void func_808014A0_bsbswim(PlayerState* self) {
    BanjoStateId sp1C;

    sp1C = BS_STATE_0_INVALID;
    func_800A0024(self);
    if (player_inWater(self) == 0) {
        sp1C = 0x74;
    }
    if (func_8009CC68(self) == 0) {
        sp1C = BS_STATE_2B_SWIM_UNDERWATER_KICK;
    }
    bs_setState(self, sp1C);
}

void func_808014F8_bsbswim(PlayerState* self)
{
    _baswim_entrypoint_6(self,0x1);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_9(s32 arg0) {
    return D_80801EF0_bsbswim[arg0];
}

void func_80801538_bsbswim(PlayerState* self)
{
    AnimCtrl* temp_s0;
    f32 sp28;
    f32 temp_f0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    func_80800030_bsbswim(self);
    func_800A046C(self);
    sp28 = func_800A3298(self);
    if (bs_getPreviousState(self) == BS_STATE_F_BBUSTER)
    {
        sp28 = ml_max_f(sp28, 600.0f);
    }
    if (sp28 > 80.0f)
    {
        anctrl_reset(temp_s0);
        anctrl_setIndex(temp_s0, 0xEA);
        anctrl_setPlaybackType(temp_s0, 3);
        anctrl_setDuration(temp_s0, 1.2f);
        anctrl_setStart(temp_s0, 0.8204f);
        anctrl_start(temp_s0);
    }
    else
    {
        anctrl_reset(temp_s0);
        anctrl_setIndex(temp_s0, 0x57);
        anctrl_setPlaybackType(temp_s0, 2);
        anctrl_setDuration(temp_s0, 1.2f);
        anctrl_setStart(temp_s0, 0.6412f);
        anctrl_start(temp_s0);
    }
    temp_f0 = ml_map_f(sp28, 40.0f, 1000.0f, -300.0f, -1200.0f);
    self->unk178 = temp_f0;
    baphysics_set_vertical_velocity(self, temp_f0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_9_NO_GRAVITY);
    baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
}

void func_808016B8_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp40[3];
    s32 sp3C;

    nextState = BS_STATE_0_INVALID;
    player_getCoords(self, &sp40);
    sp40[1] += 60.0f;
    sp3C = func_8009FBB0(self, &sp40, 20.0f);
    func_800BA930((unkStruct800BA198*)sp3C, -0x1E, -0x1E, -0x1E, 0x1E, 0x1E, 0x1E);
    func_800BA22C(sp3C, 1);
    if (self->unk178 < 0.0f)
    {
        self->unk178 += ml_max_f(mlAbsF(self->unk178) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(self, self->unk178);
    }
    if (player_isStable(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    if (player_inWater(self) == 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    if (baphysics_get_vertical_velocity(self) >= 0.0f)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, nextState);
}

void func_808017F8_bsbswim(PlayerState* self)
{
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_10(s32 arg0)
{
    return D_80801F00_bsbswim[arg0];
}

void func_8080182C_bsbswim(PlayerState* self)
{
    func_80800030_bsbswim(self);
    _bsdrone_entrypoint_0(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

void func_8080186C_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_badrone_entrypoint_30(self) != 0)
    {
        nextState = BS_STATE_BB;
    }
    _bsdrone_entrypoint_1(self);
    bs_setState(self, nextState);
}

void func_808018B0_bsbswim(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_11(s32 arg0)
{
    return D_80801F10_bsbswim[arg0];
}

void func_808018EC_bsbswim(PlayerState* self)
{
    if (func_8009E6EC(self) == 0x11)
    {
        func_80099B94(self);
        return;
    }
    func_80099AA8(self);
}

void func_80801930_bsbswim(PlayerState* self)
{
    if (self->unk164.bytes[1] != 0) {
        _baduo_entrypoint_7(self, 3);
    }
    func_80800104_bsbswim(self);
}

void func_8080196C_bsbswim(PlayerState* self)
{
    func_80800030_bsbswim(self);
    baanim_playForDuration_onceSmooth(self, 0x131, 1.5f);
    func_80800000_bsbswim(self);
    func_8009B94C(self, NULL);
    func_8009BA9C(self, NULL);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    self->unk164.bytes[1] = 0;
}

void func_808019E0_bsbswim(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp30[3];
    s32 temp;
    nextState = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.21f) != 0)
    {
        func_800A0CF4(self, 0);
        _baduo_entrypoint_21(self);
        player_setTransformation(self, TRANSFORM_A_BANJO);
        self->unk164.bytes[1] = 1;
        player_getCoords(self, sp30);
        sp30[1] += 60.0f;
        temp = func_8009FBB0(self, sp30, 70.0f);
        func_800BABB8(temp, sp30, sp30, 1.0f, &D_80801F20_bsbswim);
        func_8009DF18(self, 0x4592, 1.0f, 0x55F0);
        nextState = 0xED;
    }
    bs_setState(self, nextState);
}

s32 bsbswim_entrypoint_12(s32 arg0)
{
    return D_80801F78_bsbswim[arg0];
}

void func_80801ACC_bsbswim(PlayerState* self)
{

    switch (func_8009E6EC(self))
    {
    case 0x71:
        self->unk164.bytes[3] = 1;
        func_8009E830(self, 2);
        return;
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x24:
    case 0x2D:
    case 0x2E:
    case 0x31:
    case 0x33:
    case 0x4E:
    case 0x51:
    case 0x52:
    case 0x68:
    case 0x6F:
        if (self->unk164.bytes[3] == 0) {
            func_800F9BC4();
            func_80099B94(self);
            return;
        }
        return;
    default:
        func_80099B94(self);
        break;
    }
}

void func_80801B84_bsbswim(PlayerState* self)
{
    self->unk164.bytes[3] = 0;
    baanim_playForDuration_loopSmooth(self, 0x70, 2.0f);
    func_80800000_bsbswim(self);
    func_8009B94C(self, NULL);
    _baswim_entrypoint_9(self, 0);
    func_8009BA9C(self, NULL);
    func_80800030_bsbswim(self);
    _baswim_entrypoint_6(self, 0);
    func_80091104(self, 0);
}

void func_80801C04_bsbswim(PlayerState* self) {}

void func_80801C0C_bsbswim(PlayerState* self) {
    func_80091104(self, 1);
    _baswim_entrypoint_7(self, 1, 1);
    func_8009679C(self);
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_13(s32 arg0) {
    return D_80801F88_bsbswim[arg0];
}

void func_80801C64_bsbswim(PlayerState* self) {
    func_80800030_bsbswim(self);
    baanim_playForDuration_once(self, 0x136, 0.6f);
    func_80800000_bsbswim(self);
    func_8009B94C(self, NULL);
    func_8009BA9C(self, NULL);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_800A0CF4(self, 1);
}

void func_80801CE4_bsbswim(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if ((baanim_isStopped(self) != 0) || (_baswim_entrypoint_3(self) != 0)) {
        nextState = BS_STATE_2B_SWIM_UNDERWATER_KICK;
    }
    bs_setState(self, nextState);
}

void func_80801D30_bsbswim(PlayerState* self)
{
    func_80800104_bsbswim(self);
}

s32 bsbswim_entrypoint_14(s32 arg0)
{
    return D_80801F98_bsbswim[arg0];
}