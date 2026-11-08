#include "bs/walk.h"

extern s32 D_80801520_bswalk[];
extern s32 D_80801530_bswalk[];
extern s32 D_80801540_bswalk[];
extern s32 D_80801550_bswalk[];
extern s32 D_80801560_bswalk[];

void func_80800000_bswalk(PlayerState* self)
{
    f32 sp24;
    BsStickZoneId sp20;

    sp24 = bastick_getZonePosition(self);
    sp20 = bastick_getZone(self);
    if ((func_8008DE24(self) != 0) && (player_isStable(self) != 0))
    {
        if (sp20 == BS_STICK_ZONE_ID_0)
        {
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            return;
        }
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(bastick_distance(self), 30.0f, 150.0f));
        return;
    }
    switch (sp20)
    {
        case BS_STICK_ZONE_ID_0:
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            return;
        case BS_STICK_ZONE_ID_1:
            baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 30.0f, 80.0f));
            return;
        case BS_STICK_ZONE_ID_2:
            baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 80.0f, 150.0f));
            return;
        case BS_STICK_ZONE_ID_3:
            baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 150.0f, 225.0f));
            return;
        case BS_STICK_ZONE_ID_4:
            baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 225.0f, 500.0f));
        default:
            return;
    }
}

void func_8080016C_bswalk(PlayerState* self)
{
    if (func_8008E1A0(self) != 0)
    {
        func_8008CA30(self, ml_map_f(func_8009BBB8(self), 0.0f, 1.0f, 0.5f, 0.9f));
        return;
    }
    func_8008CA30(self, 1.0f);
}

void func_808001D8_bswalk(PlayerState* self, f32 arg1)
{
    self->unk16C = arg1;
}

void func_808001E4_bswalk(PlayerState* self)
{
    self->unk16C = ml_max_f(0.0f, self->unk16C - time_getDelta());
}

s32 func_80800220_bswalk(PlayerState* self)
{
    return self->unk16C == 0.0f;
}

BsStickZoneId func_80800248_bswalk(PlayerState* self, BsStickZoneId arg1)
{
    if (bakey_pressed(self, BUTTON_B) != 0)
    {
        if (baphysics_get_target_horizontal_velocity(self) > 225.0f)
        {
            arg1 = func_800A04F4(self, arg1);
        }
        else
        {
            arg1 = bs_getTypeOfGroundedAttack(self, arg1);
        }
    }
    return arg1;
}

f32 bswalk_entrypoint_0(s32 arg0)
{
    return 500.0f;
}

void bswalk_entrypoint_1(PlayerState* self)
{
    func_80800000_bswalk(self);
}

void bswalk_entrypoint_2(PlayerState* self)
{
    func_800A2EDC(self, 1.0f);
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 3);
    }
}

void bswalk_entrypoint_3(PlayerState* self)
{
    AnimCtrl* temp_s0;
    f32 sp28;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == BS_STATE_2_SLOW_WALK)
    {
        sp28 = func_8008C0C8(func_8008AEDC(temp_s0));
    }
    else
    {
        sp28 = 0.0f;
    }
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, 2);
    anctrl_setDuration(temp_s0, 0.43f);
    anctrl_setStart(temp_s0, sp28);
    anctrl_setPlaybackType(temp_s0, 2);
    anctrl_start(temp_s0);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 30.0f, 80.0f, 1.8f, 1.2f);
    bastick_resetZones(self);
    func_800A2EDC(self, 0.2f);
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_4(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_8080016C_bswalk(self);
    if (bastick_distance(self) == 0.0f)
    {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self))
    {
        case BS_STICK_ZONE_ID_0:
            if (func_8009BCD4(self, 1.0f) != 0)
            {
                nextState = BS_STATE_1_IDLE;
            }
            break;
        case BS_STICK_ZONE_ID_2:
            nextState = BS_STATE_2_SLOW_WALK;
            break;
        case BS_STICK_ZONE_ID_3:
            nextState = BS_STATE_3_WALK;
            break;
        case BS_STICK_ZONE_ID_4:
            nextState = BS_STATE_4_RUN;
            break;
    }
    if (func_8008DE24(self) != 0)
    {
        nextState = 0x7A;
    }
    if (bainput_should_enter_first_person(self) != 0)
    {
        nextState = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self) != 0)
    {
        nextState = BS_STATE_2F_FALL;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        nextState = BS_STATE_7_CROUCH;
    }
    nextState = func_80800248_bswalk(self, nextState);
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        nextState = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f)
        {
            if (player_canSplitUp(self) != 0)
            {
                nextState = 0xB8;
            }
            else if (player_canSwap(self) != 0)
            {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self) != 0)
    {
        nextState = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, func_800A02DC(self, nextState));
}

s32 bswalk_entrypoint_5(s32 arg0)
{
    return D_80801520_bswalk[arg0];
}

void bswalk_entrypoint_6(PlayerState* self)
{
    AnimCtrl* temp_s0;
    f32 sp28;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == BS_STATE_3_WALK)
    {
        sp28 = func_8008C0C8(func_8008AEDC(temp_s0));
    }
    else
    {
        sp28 = 0.0f;
    }
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, 3);
    anctrl_setDuration(temp_s0, 0.43f);
    anctrl_setStart(temp_s0, sp28);
    anctrl_setPlaybackType(temp_s0, 2);
    anctrl_start(temp_s0);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 80.0f, 150.0f, 1.3f, 0.6f);
    bastick_resetZones(self);
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_7(PlayerState* self)
{
    BanjoStateId var_s1;
    var_s1 = BS_STATE_0_INVALID;
    func_8080016C_bswalk(self);
    if (bastick_distance(self) == 0.0f)
    {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        if (func_8009BCD4(self, 3.0f) != 0)
        {
            var_s1 = BS_STATE_1_IDLE;
        }
        break;
    case BS_STICK_ZONE_ID_1:
        var_s1 = BS_STATE_1F_TIPTOE;
        break;
    case BS_STICK_ZONE_ID_3:
        var_s1 = BS_STATE_3_WALK;
        break;
    case BS_STICK_ZONE_ID_4:
        var_s1 = BS_STATE_4_RUN;
        break;
    }
    if (func_8008DE24(self) != 0)
    {
        var_s1 = 0x7A;
    }
    if (bainput_should_enter_first_person(self) != 0) {
        var_s1 = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self) != 0)
    {
        var_s1 = BS_STATE_2F_FALL;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        var_s1 = BS_STATE_7_CROUCH;
    }
    var_s1 = func_80800248_bswalk(self, var_s1);
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        var_s1 = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f)
        {
            if (player_canSplitUp(self) != 0)
            {
                var_s1 = 0xB8;
            }
            else if (player_canSwap(self) != 0)
            {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self) != 0)
    {
        var_s1 = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        var_s1 = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, func_800A02DC(self, var_s1));
}

void bswalk_entrypoint_8(PlayerState* self)
{
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 3);
    }
}

s32 bswalk_entrypoint_9(s32 arg0)
{
    return D_80801530_bswalk[arg0];
}

void bswalk_entrypoint_10(PlayerState* self)
{
    AnimCtrl* temp_s0;
    f32 sp28;
    BanjoStateId temp_v0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    temp_v0 = bs_getPreviousState(self);
    if ((temp_v0 != BS_STATE_2_SLOW_WALK) && (temp_v0 != BS_STATE_4_RUN))
    {
        sp28 = 0.0f;
    }
    else
    {
        sp28 = func_8008C0C8(func_8008AEDC(temp_s0));
    }
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, 0xC);
    anctrl_setDuration(temp_s0, 0.66f);
    func_8008B1C8(temp_s0, 0.14f);
    anctrl_setStart(temp_s0, sp28);
    anctrl_setPlaybackType(temp_s0, 2);
    anctrl_start(temp_s0);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 150.0f, 225.0f, 0.92f, 0.58f);
    func_808001D8_bswalk(self, 0.3f);
    bastick_resetZones(self);
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_11(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_8080016C_bswalk(self);
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_808001E4_bswalk(self);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self))
    {
        case BS_STICK_ZONE_ID_0:
        case BS_STICK_ZONE_ID_1:
        case BS_STICK_ZONE_ID_2:
            if ((func_8009BCD4(self, 150.0f) != 0) && (func_80800220_bswalk(self) != 0))
            {
                nextState = BS_STATE_2_SLOW_WALK;
            }
            break;
        case BS_STICK_ZONE_ID_4:
            nextState = BS_STATE_4_RUN;
            break;
    }
    if (func_8008DE24(self) != 0)
    {
        nextState = 0x7A;
    }
    if ((func_8008E300(self) != 0) && (baphysics_get_horizontal_velocity(self) > 125.0f))
    {
        nextState = BS_STATE_C_QUICK_TURN;
    }
    if (bainput_should_enter_first_person(self) != 0)
    {
        nextState = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self) != 0)
    {
        nextState = BS_STATE_2F_FALL;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        nextState = BS_STATE_7_CROUCH;
    }
    nextState = func_80800248_bswalk(self, nextState);
    if (bakey_pressed(self, BUTTON_A) != 0) 
    {
        nextState = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f)
        {
            if (player_canSplitUp(self) != 0) 
            {
                nextState = 0xB8;
            }
            else if (player_canSwap(self) != 0)
            {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self) != 0)
    {
        nextState = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, func_800A02DC(self, nextState));
}

void bswalk_entrypoint_12(PlayerState* self)
{
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 3);
    }
}

s32 bswalk_entrypoint_13(s32 arg0)
{
    return D_80801540_bswalk[arg0];
}

void bswalk_entrypoint_14(PlayerState* self)
{
    AnimCtrl* sp34;
    f32 sp30;
    s32 sp2C;

    sp34 = baanim_getAnimCtrlPtr(self);
    sp2C = 1;
    sp30 = 0.0f;
    switch (bs_getPreviousState(self))
    {
        case BS_STATE_1_IDLE:
        case BS_STATE_2_SLOW_WALK:
            if (baphysics_get_horizontal_velocity(self) < 200.0f)
            {
                _badust_entrypoint_3(self, 0.0f, 0.0f);
            }
            break;
        case BS_STATE_C_QUICK_TURN:
            sp2C = 0;
            break;
        case BS_STATE_3_WALK:
            sp30 = func_8008C0C8(func_8008AEDC(sp34));
            break;
    }
    anctrl_reset(sp34);
    anctrl_setSmoothTransition(sp34, sp2C);
    anctrl_setIndex(sp34, 0xC);
    anctrl_setDuration(sp34, 0.66f);
    func_8008B1C8(sp34, 0.1f);
    anctrl_setStart(sp34, sp30);
    anctrl_setPlaybackType(sp34, 2);
    anctrl_start(sp34);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 225.0f, 500.0f, 0.54f, 0.44f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
    func_808001D8_bswalk(self, 0.3f);
    bastick_resetZones(self);
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_15(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_8080016C_bswalk(self);
    func_8009D2F0(self, 0, 0.5f);
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_808001E4_bswalk(self);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self))
    {
        case BS_STICK_ZONE_ID_0:
            if (func_8009BCD4(self, 18.0f) != 0)
            {
                nextState = BS_STATE_1_IDLE;
            }
            if (bainput_should_enter_first_person(self) != 0)
            {
                nextState = _badrone_entrypoint_24(self);
            }
            break;
        case BS_STICK_ZONE_ID_1:
        case BS_STICK_ZONE_ID_2:
            if (func_8009BCD4(self, 150.0f) != 0)
            {
                nextState = BS_STATE_2_SLOW_WALK;
            }
            if (bainput_should_enter_first_person(self) != 0)
            {
                nextState = _badrone_entrypoint_24(self);
            }
            break;
        case BS_STICK_ZONE_ID_3:
            if ((func_8009BCD4(self, 225.0f) != 0) && (func_80800220_bswalk(self) != 0))
            {
                nextState = BS_STATE_3_WALK;
            }
            if (bainput_should_enter_first_person(self) != 0)
            {
                nextState = _badrone_entrypoint_24(self);
            }
            break;
    }
    if (func_8008DE24(self) != 0) {
        nextState = 0x7A;
    }
    if ((func_8008E300(self) != 0) && (baphysics_get_horizontal_velocity(self) > 125.0f)) {
        nextState = BS_STATE_C_QUICK_TURN;
    }
    if (func_8008DD04(self) != 0)
    {
        nextState = BS_STATE_2F_FALL;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        nextState = BS_STATE_7_CROUCH;
    }
    nextState = func_80800248_bswalk(self, nextState);
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        nextState = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f)
        {
            if (player_canSplitUp(self) != 0)
            {
                nextState = 0xB8;
            }
            else if (player_canSwap(self) != 0)
            {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self) != 0)
    {
        nextState = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, func_800A02DC(self, nextState));
}

void bswalk_entrypoint_16(PlayerState* self)
{
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    if (func_8008E0E8(self) != 0)
    {
        _bapackctrl_entrypoint_5(self, 3);
    }
}

s32 bswalk_entrypoint_17(s32 arg0) 
{
    return D_80801550_bswalk[arg0];
}

void bswalk_entrypoint_18(s32 arg0) 
{
}

void bswalk_entrypoint_19(PlayerState* self)
{
    baanim_playForDuration_loopSmooth(self, 0xB, 0.43f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 30.0f, 150.0f, 1.2f, 0.9f);
}

void bswalk_entrypoint_20(PlayerState* self)
{
    BanjoStateId var_s1;

    var_s1 = BS_STATE_0_INVALID;
    func_8080016C_bswalk(self);
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800000_bswalk(self);
    if (func_8008DE24(self) == 0)
    {
        var_s1 = BS_STATE_2_SLOW_WALK;
    }
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0)
    {
        var_s1 = BS_STATE_1_IDLE;
    }
    if (bainput_should_enter_first_person(self) != 0)
    {
        var_s1 = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self) != 0)
    {
        var_s1 = BS_STATE_2F_FALL;
    }
    if (bakey_held(self, BUTTON_Z) != 0)
    {
        var_s1 = BS_STATE_7_CROUCH;
    }
    var_s1 = func_80800248_bswalk(self, var_s1);
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        var_s1 = bs_getTypeOfJump(self);
    }
    if (func_8008E148(self) != 0)
    {
        var_s1 = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        var_s1 = BS_STATE_2D_SWIM_IDLE;
    }
    bs_setState(self, func_800A02DC(self, var_s1));
}

s32 bswalk_entrypoint_21(s32 arg0) {
    return D_80801560_bswalk[arg0];
}

void bswalk_entrypoint_22(PlayerState* self, f32 arg1)
{
    if (arg1 < 150.0f)
    {
        func_8009FF44(self, 3, 80.0f, 150.0f, 1.3f, 0.6f);
        return;
    }
    else
    {
        func_8009FF44(self, 0xC, 225.0f, 500.0f, 0.54f, 0.44f);
    }
}