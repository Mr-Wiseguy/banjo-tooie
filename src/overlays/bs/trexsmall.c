#include "bs/trexsmall.h"

void bstrexsmall_entrypoint_1(PlayerState*);
void bstrexsmall_entrypoint_2(PlayerState*);
void bstrexsmall_entrypoint_3(PlayerState*);

extern s32 D_80801AF0_bstrexsmall;
extern s32 D_80801B08_bstrexsmall[];
extern s32 D_80801B18_bstrexsmall[];
extern s32 D_80801B28_bstrexsmall[];
extern s32 D_80801B38_bstrexsmall[];
extern s32 D_80801B48_bstrexsmall[];
extern s32 D_80801B58_bstrexsmall[];
extern s32 D_80801B68_bstrexsmall[];
extern s32 D_80801B78_bstrexsmall[];
extern s32 D_80801B88_bstrexsmall[];
extern s32 D_80801B98_bstrexsmall[];
extern s32 D_80801BA8_bstrexsmall[];
extern s32 D_80801BB8_bstrexsmall[];

int func_80800000_bstrexsmall(PlayerState* self) {
    return bakey_pressed(self, BUTTON_B) && ability_getValue(ABILITY_20_TREX_ROAR);
}

int func_8080003C_bstrexsmall(PlayerState* self)
{
    return bakey_pressed(self, BUTTON_A);
}

void func_8080005C_bstrexsmall(PlayerState* self)
{
    func_80099B94(self);
}
void func_8080007C_bstrexsmall(PlayerState* self)
{
    switch (func_8009E6EC(self))
    {
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x25:
        break;
    default:
        func_80099B94(self);
    }
}
void func_808000C8_bstrexsmall(PlayerState* self, s32 arg1)
{

    if (self->unk15C.bytes[2] == 0)
    {
        self->unk160.bytes[0] = 0;
    }
    self->unk15C.bytes[2] = arg1;
    switch (arg1)
    {
    case 0:
    case 1:
        if (self->unk160.bytes[0] != 0) {
            func_800C2FDC(self->unk160.bytes[0]);
            self->unk160.bytes[0] = 0;
            return;
        }
        return;
    case 2:
        self->unk160.bytes[0] = func_8009D454(self, 0, &D_80801AF0_bstrexsmall);
        break;
    }
}

BanjoStateId func_80800154_bstrexsmall(PlayerState* self, BanjoStateId arg1) {
    BanjoStateId sp1C;

    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        sp1C = 0x145;
        break;
    case BS_STICK_ZONE_ID_1:
        sp1C = 0x146;
        break;
    case BS_STICK_ZONE_ID_2:
        sp1C = 0x144;
        break;
    }
    if (bs_getCurrentState(self) != sp1C) {
        arg1 = sp1C;
    }
    if (func_80800000_bstrexsmall(self) != 0) {
        arg1 = 0x143;
    }
    if (func_8008DD04(self) != 0) {
        arg1 = 0x13E;
    }
    if (func_8080003C_bstrexsmall(self) != 0) {
        arg1 = 0x13F;
    }
    return arg1;
}

BanjoStateId func_8080020C_bstrexsmall(PlayerState* self, BanjoStateId arg1)
{
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        break;
    case BS_STICK_ZONE_ID_1:
        arg1 = 0x146;
        break;
    case BS_STICK_ZONE_ID_2:
        arg1 = 0x144;
        break;
    }
    if (bainput_should_enter_first_person(self) != 0) {
        arg1 = _badrone_entrypoint_24(self);
    }
    if (func_80800000_bstrexsmall(self) != 0) {
        arg1 = 0x143;
    }
    if (func_8008DD04(self) != 0) {
        arg1 = 0x13E;
    }
    if (func_8080003C_bstrexsmall(self) != 0) {
        arg1 = 0x13F;
    }
    return arg1;
}

void func_808002B8_bstrexsmall(PlayerState* self) {
    f32 sp24;

    sp24 = bastick_getZonePosition(self);
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    case BS_STICK_ZONE_ID_1:
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 100.0f, 300.0f));
        return;
    case BS_STICK_ZONE_ID_2:
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 300.0f, 600.0f));
        return;
    }
}

void func_80800364_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_1(self);
}

void func_80800384_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_2(self);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 500.0f, 6.5f);
}

void func_808003D0_bstrexsmall(PlayerState* self) {
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    func_8009D3A8(self, 0);
    bstrexsmall_entrypoint_3(self);
    if (baanim_isStopped(self) != 0) {
        sp24 = 0x145;
    }
    bs_setState(self, func_8080020C_bstrexsmall(self, sp24));
}

s32 bstrexsmall_entrypoint_0(s32 arg0) {
    return D_80801B08_bstrexsmall[arg0];
}

void bstrexsmall_entrypoint_1(PlayerState* self) {
    if (func_8009E74C(self, 0x10) == 0) {
        func_808000C8_bstrexsmall(self, 0U);
        bastick_popZone(self);
        func_80092864(self, 1.0f);
        func_8009E474(self);
        func_80095A40(self);
        func_8009590C(self, 0.0f);
        baphysics_reset_gravity(self);
        func_800947EC(self, 1, 0);
    }
}

void bstrexsmall_entrypoint_2(PlayerState* self) {
    if (func_8009E77C(self, 0x10) == 0) {
        self->unk15C.bytes[2] = 0;
        func_808000C8_bstrexsmall(self, 1U);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 0.6f);
        bastick_setZoneMax(self, 2, 1.0f);
        func_80092864(self, 1.5f);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 70.0f);
        func_8009E53C(self, 0, 0.0f);
        func_8009E55C(self, 1, 80.0f);
        func_8009E53C(self, 1, 0.0f);
        func_800959C8(self, 100.0f, 56.0f);
        func_8009590C(self, 125.0f);
        baphysics_set_gravity(self, -3000.0f);
        func_800947EC(self, 1, 1);
    }
}

void bstrexsmall_entrypoint_3(PlayerState* self) {
    s32 pad[2];
    s32 sp1C;
    s32 temp_v0;

    if ((self->unk160.bytes[0] != 0) && (self->unk15C.bytes[2] == 3))
    {
        sp1C = func_800C3920(self->unk160.bytes[0]);
        temp_v0 = ml_max_i(0, (s32)((f32)sp1C - (time_getDelta() * 60000.0f)));
        if (temp_v0 != 0)
        {
            func_800C3058(self->unk160.bytes[0], temp_v0);
            return;
        }
        func_808000C8_bstrexsmall(self, 1U);
    }
}

void func_80800680_bstrexsmall(PlayerState* self) {
    f32 var_f20;

    var_f20 = 0.0f;
    while (var_f20 < 360.0f)
    {
        _badust_entrypoint_5(self, var_f20, 230.0f);
        var_f20 += 45.0f;
    }
}

void func_8080070C_bstrexsmall(PlayerState* self) {
    _basudie_entrypoint_6(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

void func_80800744_bstrexsmall(PlayerState* self) {
    AnimCtrl* temp_a0;
    AnimCtrl* temp_s0;
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    temp_s0 = temp_v0;
    temp_a0 = temp_v0;
    self->unk16C = 250.0f;
    anctrl_reset(temp_a0);
    anctrl_setSmoothTransition(temp_s0, 0);
    anctrl_setIndex(temp_s0, 0x148);
    anctrl_setSubrange(temp_s0, 0.0f, 0.12f);
    anctrl_setDuration(temp_s0, 4.5f);
    anctrl_setPlaybackType(temp_s0, 1);
    anctrl_start(temp_s0);
    _basudie_entrypoint_3(self, self->unk16C, 800.0f, -2400.0f, 10.0f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    func_8009D820(self, 1.4f);
    self->unk15C.bytes[0] = 0;
}

void func_80800818_bstrexsmall(PlayerState* self) {
    AnimCtrl* sp24;
    f32 temp_f0;

    sp24 = baanim_getAnimCtrlPtr(self);
    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.bytes[0])
    {
    case 3:
        break;
    case 0:
        if (func_8008DF8C(self, 0x5A) != 0) {
            self->unk15C.bytes[0] = 1;
        }
        break;
    case 1:
        if (player_isStable(self) != 0) {
            func_8009DF18(self, 0x428, 1.0f, 0x4650);
            _bamotor_entrypoint_1(self, 1.0f, 1.0f, 0.4f);
            func_80800680_bstrexsmall(self);
            func_8009E058(self);
            baanim_setEndAndDuration(self, 0.6f, 2.5f);
            self->unk15C.bytes[0] = 2;
        }
        break;
    case 2:
        temp_f0 = ml_max_f(self->unk16C - 7.0f, 0.0f);
        self->unk16C = temp_f0;
        if (temp_f0 > 140.0f) {
            _badust_entrypoint_9(self);
        }
        if (anctrl_isStopped(sp24) != 0) {
            baanim_setEnd(self, 1.0f);
            self->unk15C.bytes[0] = 3;
            self->unk16C = 0.0f;
        }
        break;
    }
    bs_setState(self, BS_STATE_0_INVALID);
}

s32 bstrexsmall_entrypoint_4(s32 arg0) {
    return D_80801B18_bstrexsmall[arg0];
}

void func_80800998_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_1(self);
    _bsdrone_entrypoint_2(self);
}
void func_808009C0_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_2(self);
    _bsdrone_entrypoint_0(self);
}
void func_808009E8_bstrexsmall(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
    bstrexsmall_entrypoint_3(self);
}
s32 bstrexsmall_entrypoint_5(s32 arg0) {
    return D_80801B28_bstrexsmall[arg0];
}

void func_80800A24_bstrexsmall(PlayerState* self, s32 arg1) {
    AnimCtrl* temp_s0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    switch (arg1)
    {
    case 1:
        anctrl_reset(temp_s0);
        anctrl_setIndex(temp_s0, 0x1D1);
        anctrl_setDuration(temp_s0, 4.0f);
        anctrl_setSubrange(temp_s0, 0.0f, 0.715f);
        anctrl_setPlaybackType(temp_s0, 1);
        anctrl_setStart(temp_s0, 0.45f);
        anctrl_start(temp_s0);
        break;
    case 2:
        baanim_setEndAndDuration(self, 1.0f, 0.8f);
        break;
    }
    self->unk15C.bytes[0] = (u8)arg1;
}

void func_80800AF0_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_1(self);
}

void func_80800B10_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_2(self);
    self->unk15C.bytes[0] = 0;
    func_80800A24_bstrexsmall(self, 1);
}

void func_80800B40_bstrexsmall(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bstrexsmall_entrypoint_3(self);
    func_808002B8_bstrexsmall(self);
    switch (self->unk15C.bytes[0])
    {
    case 1:
        if (func_8008DF8C(self, 0x82) != 0) {
            func_80800A24_bstrexsmall(self, 2);
        }
        break;
    case 2:
        func_8009D3A8(self, 0);
        if (player_isStable(self) != 0) {
            func_800A2E18(self);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            nextState = 0x13B;
        }
        break;
    }
    bs_setState(self, nextState);
}

s32 bstrexsmall_entrypoint_6(s32 arg0) {
    return D_80801B38_bstrexsmall[arg0];
}

s32 bstrexsmall_entrypoint_7(PlayerState* self, f32* arg1)
{
    f32 temp_f0;
    f32 sp18[3];

    player_getCoords(self, sp18);
    temp_f0 = func_800EFC7C(sp18, arg1);
    if (temp_f0 < 40000.0f)
    {
        return 1;
    }
    if (temp_f0 > 250000.0f)
    {
        return 0;
    }
    if (func_8008DAE8(self, arg1, 90.0f) == 0)
    {
        return 0;
    }
    return 1;
}

void func_80800CA4_bstrexsmall(PlayerState* self, s32 arg1)
{
    AnimCtrl* temp_a0;
    s32 pad[2];
    f32 sp28;

    temp_a0 = baanim_getAnimCtrlPtr(self);
    self->unk15C.bytes[0] = (u8)arg1;
    switch (arg1)
    {
    case 1:
        anctrl_reset(temp_a0);
        anctrl_setIndex(temp_a0, 0x1D1);
        anctrl_setDuration(temp_a0, 2.2f);
        anctrl_setSubrange(temp_a0, 0.0f, 0.715f);
        anctrl_setPlaybackType(temp_a0, 1);
        anctrl_setStart(temp_a0, 0.194f);
        anctrl_start(temp_a0);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
        if (bastick_distance(self) != 0.0f) {
            yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
        }
        baphysics_set_target_yaw(self, yaw_getIdeal(self));
        sp28 = yaw_getIdeal(self);
        baphysics_set_horizontal_velocity(self, sp28, baphysics_get_target_horizontal_velocity(self));
        baphysics_set_vertical_velocity(self, 1100.0f);
        baphysics_set_gravity(self, -1800.0f);
        if (rand_f() > 0.5f) {
            func_8009DBB0(self, 0x4D8, 1.3f, 1.35f, 0x55F0);
            return;
        }
        func_8009DBB0(self, 0x4D9, 1.3f, 1.35f, 0x55F0);
        return;
    case 2:
        baanim_setEndAndDuration(self, 1.0f, 0.8f);
        return;
    case 0:
        baphysics_set_gravity(self, -3000.0f);
        return;
    }
}

void func_80800E94_bstrexsmall(PlayerState* self)
{
    func_80800CA4_bstrexsmall(self,0);
    bstrexsmall_entrypoint_1(self);
}

void func_80800EC0_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_2(self);
    self->unk15C.bytes[0] = 0;
    func_80800CA4_bstrexsmall(self, 1);
}

void func_80800EF0_bstrexsmall(PlayerState* self) {
    BanjoStateId nextState;
    f32 sp28[3];

    nextState = BS_STATE_0_INVALID;
    bstrexsmall_entrypoint_3(self);
    func_8009BB24(self, sp28);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp28[1] > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.bytes[0])
    {
    case 1:
        func_808002B8_bstrexsmall(self);
        if (func_8008DF8C(self, 0x82) != 0)
        {
            func_80800CA4_bstrexsmall(self, 2);
        }
        break;
    case 2:
        func_8009D3A8(self, 0);
        func_808002B8_bstrexsmall(self);
        if (player_isStable(self) != 0)
        {
            func_800A2E18(self);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            nextState = 0x13B;
        }
        break;
    }
    bs_setState(self, nextState);
}

s32 bstrexsmall_entrypoint_8(s32 arg0) {
    return D_80801B48_bstrexsmall[arg0];
}

void func_80801004_bstrexsmall(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bstrexsmall_entrypoint_1(self);
}
void func_8080102C_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_2(self);
    _babounce_entrypoint_4(self, 1);
    _babounce_entrypoint_5(self, 0x147, 0.69f);
}

void func_8080106C_bstrexsmall(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bstrexsmall_entrypoint_3(self);
    if (baanim_isAt(self, 0.5f) != 0) {
        func_800951B4(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x145;
    }
    bs_setState(self, nextState);
}

s32 bstrexsmall_entrypoint_9(s32 arg0) {
    return D_80801B58_bstrexsmall[arg0];
}

void func_808010E8_bstrexsmall(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bstrexsmall_entrypoint_1(self);
}
void func_80801110_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_2(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0x147, 0.69f);
}

void func_80801150_bstrexsmall(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bstrexsmall_entrypoint_3(self);
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x145;
    }
    bs_setState(self, nextState);
}

s32 bstrexsmall_entrypoint_10(s32 arg0) {
    return D_80801B68_bstrexsmall[arg0];
}

void func_808011A8_bstrexsmall(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    bstrexsmall_entrypoint_1(self);
}
void func_808011D0_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_2(self);
    _bsrest_entrypoint_16(self);
}
void func_808011F8_bstrexsmall(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _bsrest_entrypoint_13(self);
    }
    bstrexsmall_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bstrexsmall_entrypoint_11(s32 arg0) {
    return D_80801B78_bstrexsmall[arg0];
}

void func_80801258_bstrexsmall(PlayerState* self, s32 arg1) {
    f32 sp1C[3];

    player_getCoords(self, sp1C);
    func_801013A8(sp1C, arg1, self->unk184);
}

void func_80801294_bstrexsmall(PlayerState* self, s32 arg1) {

    switch (self->unk15C.bytes[0])
    {
    case 2:
        func_80801258_bstrexsmall(self, 0x1D);
        break;
    case 3:
        func_80801258_bstrexsmall(self, 0x1E);
        break;
    }
    self->unk15C.bytes[0] = (u8)arg1;
    switch (arg1)
    {
    case 0:
        func_808000C8_bstrexsmall(self, 3U);
        return;
    case 1:
        bstrexsmall_entrypoint_2(self);
        baanim_playForDuration_onceSmooth(self, 0x1D0, 3.1f);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 8, BA_PHYSICS_2_NORMAL);
        yaw_setVelocityBounded(self, 55.0f, 0.8f);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        self->unk15C.bytes[1] = 1;
        return;
    case 2:
        anctrl_setSubrange(baanim_getAnimCtrlPtr(self), 0.0f, 0.29f);
        return;
    case 3:
        anctrl_setSubrange(baanim_getAnimCtrlPtr(self), 0.0f, 0.49f);
        return;
    }
}

void func_808013E8_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_1(self);
    func_80801294_bstrexsmall(self, NULL);
}

void func_80801414_bstrexsmall(PlayerState* self) {
    self->unk15C.bytes[0] = 0;
    func_80801294_bstrexsmall(self, 1);
}

void func_80801438_bstrexsmall(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bstrexsmall_entrypoint_3(self);
    if ((func_800DB9B0() != 0) && (func_8009D2E4(self) == 8))
    {
        func_8009D2D8(self, 2);
    }
    switch (self->unk15C.bytes[0])
    {
    case 1:
        if (baanim_isAt(self, 0.13f) != 0)
        {
            func_808000C8_bstrexsmall(self, 2U);
        }
        if (bakey_newlyReleased(self, BUTTON_B) != 0)
        {
            self->unk15C.bytes[1] = 0;
        }
        if (baanim_isAt(self, 0.2f) != 0)
        {
            if (self->unk15C.bytes[1] != 0)
            {
                func_80801294_bstrexsmall(self, 3);
            }
            else
            {
                func_80801294_bstrexsmall(self, 2);
            }
        }
        break;
    case 2:
        if (baanim_isAt(self, 0.25f) != 0)
        {
            func_808000C8_bstrexsmall(self, 3U);
        }
        if (baanim_isStopped(self) != 0)
        {
            nextState = 0x145;
        }
        break;
    case 3:
        if (baanim_isAt(self, 0.45f) != 0)
        {
            func_808000C8_bstrexsmall(self, 3U);
        }
        if (baanim_isStopped(self) != 0)
        {
            nextState = 0x145;
        }
        break;
    }
    bs_setState(self, nextState);
}

s32 bstrexsmall_entrypoint_12(s32 arg0) {
    return D_80801B88_bstrexsmall[arg0];
}

void func_808015BC_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_1(self);
}

void func_808015DC_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_2(self);
    baanim_playForDuration_loopSmooth(self, 0x1CF, 0.7f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 500.0f, 6.5f);
    baanim_setDurationRange(self, 0.1f, 10.0f);
    func_8008C9F0(self, 300.0f, 600.0f, 0.86f, 0.48f);
    func_8008CA30(self, 1.0f);
}

void func_80801688_bstrexsmall(PlayerState* self) {
    bstrexsmall_entrypoint_3(self);
    func_808002B8_bstrexsmall(self);
    func_8009D3A8(self, 0);
    func_800A2CE8(self, 0.5702f, 3);
    func_800A2CE8(self, 0.0702f, 4);
    bs_setState(self, func_80800154_bstrexsmall(self, BS_STATE_0_INVALID));
}

s32 bstrexsmall_entrypoint_13(s32 arg0) {
    return D_80801B98_bstrexsmall[arg0];
}

void func_80801718_bstrexsmall(PlayerState* self)
{
    func_80090A2C(self);
    func_800951B4(self);
    bstrexsmall_entrypoint_1(self);
}

void func_80801748_bstrexsmall(PlayerState* self)
{
    AnimCtrl* temp_s0;
    f32 var_f0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    bstrexsmall_entrypoint_2(self);
    if (bs_getPreviousState(self) == 0x143)
    {
        var_f0 = 0.5f;
    }
    else
    {
        var_f0 = 0.2f;
    }
    anctrl_reset(temp_s0);
    func_8008B1C8(temp_s0, var_f0);
    anctrl_setIndex(temp_s0, 0x1D2);
    anctrl_setDuration(temp_s0, 8.5f);
    anctrl_setStart(temp_s0, 0.13f);
    anctrl_setPlaybackType(temp_s0, 2);
    anctrl_start(temp_s0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 2, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 500.0f, 6.5f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_80801844_bstrexsmall(PlayerState* self)
{
    func_8009D3A8(self, 0);
    bstrexsmall_entrypoint_3(self);
    if (baanim_isAt(self, 0.095f) != 0)
    {
        func_8009DF18(self, 0x570, 1.2f, 0x4650);
    }
    if (baanim_isAt(self, 0.545f) != 0)
    {
        func_8009DEC0(self, 0x56F, 1.2f, 1.4f, 0x4E20, 0x55F0);
    }
    if (baanim_isAt(self, 0.82f) != 0)
    {
        func_8009DF18(self, 0x570, 1.2f, 0x4E20);
    }
    if (baanim_isAt(self, 0.92f) != 0)
    {
        func_8009DF18(self, 0x570, 1.3f, 0x32C8);
    }
    func_808002B8_bstrexsmall(self);
    bs_setState(self, func_8080020C_bstrexsmall(self, BS_STATE_0_INVALID));
}

s32 bstrexsmall_entrypoint_14(s32 arg0)
{
    return D_80801BA8_bstrexsmall[arg0];
}

void func_80801970_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_1(self);
}

void func_80801990_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_2(self);
    baanim_playForDuration_loopSmooth(self, 0x1CE, 1.2f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 500.0f, 6.5f);
    baanim_setDurationRange(self, 0.1f, 10.0f);
    func_8008C9F0(self, 100.0f, 300.0f, 1.15f, 0.61f);
    func_8008CA30(self, 1.0f);
}

void func_80801A3C_bstrexsmall(PlayerState* self)
{
    bstrexsmall_entrypoint_3(self);
    func_808002B8_bstrexsmall(self);
    func_8009D3A8(self, 0);
    func_800A2CE8(self, 0.8977f, 3);
    func_800A2CE8(self, 0.3977f, 4);
    bs_setState(self, func_80800154_bstrexsmall(self, BS_STATE_0_INVALID));
}

s32 bstrexsmall_entrypoint_15(s32 arg0)
{
    return D_80801BB8_bstrexsmall[arg0];
}
