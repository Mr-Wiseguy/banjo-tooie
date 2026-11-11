#include "bs/trexlarge.h"

void bstrexlarge_entrypoint_1(PlayerState*);
void bstrexlarge_entrypoint_2(PlayerState*);
void bstrexlarge_entrypoint_3(PlayerState*);

extern s32 D_80801990_bstrexlarge[];
extern s32 D_808019A0_bstrexlarge[];
extern s32 D_808019B0_bstrexlarge[];
extern s32 D_808019C0_bstrexlarge[];
extern s32 D_808019D0_bstrexlarge[];
extern s32 D_808019E0_bstrexlarge[];
extern s32 D_808019F0_bstrexlarge[];
extern s32 D_80801A00_bstrexlarge[];
extern s32 D_80801A10_bstrexlarge[];
extern s32 D_80801A20_bstrexlarge[];
extern s32 D_80801A30_bstrexlarge[];
extern s32 D_80801A40_bstrexlarge[];

void func_80800000_bstrexlarge(PlayerState* self) {
    self->unk168.word = 5;
}

void func_8080000C_bstrexlarge(PlayerState* self)
{
    if (self->unk168.word > 0)
    {
        self->unk168.word--;
    }
}

s32 func_80800024_bstrexlarge(PlayerState* self)
{
    return self->unk168.word == 0;
}

s32 func_80800034_bstrexlarge(PlayerState* self)
{
    return self->unk164.word >= 4;
}

void func_80800044_bstrexlarge(PlayerState* self)
{
    f32 sp4C;
    f32 sp48;
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp2C;
    s32 pad[2];
    player_getCoords(self, sp3C);
    func_80096394(self, sp30);
    sp4C = func_800962D4(self);
    sp2C = func_80096518(self) == 0;
    sp48 = baphysics_get_vertical_velocity(self);
    if ((func_8009650C(self) != 0) && (sp2C != 0) && (sp4C < 70.0f) && (sp30[1] < 5.0f) && (sp48 < -100.0f))
    {
        self->unk164.word = (s32)ml_min_f((f32)(self->unk164.word + 1), 100.0f);
        return;
    }
    self->unk164.word = 0;
}

int func_80800140_bstrexlarge(PlayerState* self)
{
    return bakey_pressed(self,BUTTON_B);
}

int func_80800160_bstrexlarge(PlayerState* self)
{
    return bakey_pressed(self,BUTTON_A);
}

void func_80800180_bstrexlarge(PlayerState* self, s32(*arg1)(PlayerState*))
{
    switch (func_8009E6EC(self))
    {
    case 0x20:
    case 0x21:
    case 0x2E:
    case 0x4E:
    case 0x51:
    case 0x52:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x91:
        func_8009E830(self, 1);
        return;
    case 0x7E:
        self->unk15C.bytes[1] = 2;
        return;
    case 0x4F:
    case 0x50:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:

        break;
    }
    arg1(self);
}

void func_8080024C_bstrexlarge(PlayerState* self) {
    func_80800180_bstrexlarge(self, func_80099B94);
}

void func_80800270_bstrexlarge(PlayerState* self) {
    func_80800180_bstrexlarge(self, _bsdrone_entrypoint_3);
}

void func_80800294_bstrexlarge(PlayerState* self) {
    s16 temp_v0;

    temp_v0 = func_8009E6EC(self);
    if ((temp_v0 != 0x1C) && (temp_v0 != 0x1D) && (temp_v0 != 0x1E) && (temp_v0 != 0x25)) {
        func_8080024C_bstrexlarge(self);
    }
}

BanjoStateId func_808002E0_bstrexlarge(PlayerState* self, BanjoStateId arg1, s32 arg2) {
    BanjoStateId sp1C;
    s32 sp18;

    if (arg2 != 0)
    {
        sp18 = func_80800024_bstrexlarge(self);
    }
    else
    {
        sp18 = 1;
    }
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        sp1C = 0x151;
        break;
    case BS_STICK_ZONE_ID_1:
        sp1C = 0x152;
        break;
    case BS_STICK_ZONE_ID_2:
        sp1C = 0x150;
        break;
    }
    if (bs_getCurrentState(self) != sp1C)
    {
        arg1 = sp1C;
    }
    if (func_80800140_bstrexlarge(self) != 0)
    {
        arg1 = 0x14F;
    }
    if ((sp18 != 0) && (func_8008DD04(self) != 0))
    {
        arg1 = 0x14A;
    }
    if (func_80800160_bstrexlarge(self) != 0)
    {
        arg1 = 0x14B;
    }
    return arg1;
}

BanjoStateId func_808003C4_bstrexlarge(PlayerState* self, BanjoStateId arg1, s32 arg2)
{
    s32 sp1C;
    if (arg2 != 0)
    {
        sp1C = func_80800024_bstrexlarge(self);
    }
    else
    {
        sp1C = 1;
    }
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        break;
    case BS_STICK_ZONE_ID_1:
        arg1 = 0x152;
        break;
    case BS_STICK_ZONE_ID_2:
        arg1 = 0x150;
        break;
    }
    if (bainput_should_enter_first_person(self) != 0) {
        arg1 = _badrone_entrypoint_24(self);
    }
    if (func_80800140_bstrexlarge(self) != 0) {
        arg1 = 0x14F;
    }
    if (sp1C != 0) {
        if (func_8008DD04(self) != 0) {
            arg1 = 0x14A;
        }
    }
    if (func_80800160_bstrexlarge(self) != 0) {
        arg1 = 0x14B;
    }
    return arg1;
}

void func_808004B4_bstrexlarge(PlayerState* self) {
    f32 sp24;

    sp24 = bastick_getZonePosition(self);
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    case BS_STICK_ZONE_ID_1:
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 100.0f, 400.0f));
        return;
    case BS_STICK_ZONE_ID_2:
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 400.0f, 1000.0f));
        return;
    }
}

void func_80800560_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
}
void func_80800580_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 300.0f, 3.5f);
    func_80800000_bstrexlarge(self);
}

void func_808005D4_bstrexlarge(PlayerState* self) {
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    func_8080000C_bstrexlarge(self);
    bstrexlarge_entrypoint_3(self);
    if (baanim_isStopped(self) != 0) {
        sp24 = 0x151;
    }
    bs_setState(self, func_808003C4_bstrexlarge(self, sp24, 1));
}

s32 bstrexlarge_entrypoint_0(s32 arg0) {
    return D_80801990_bstrexlarge[arg0];
}

void bstrexlarge_entrypoint_1(PlayerState* self) {
    if (func_8009E74C(self, 0x11) == 0) {
        bastick_popZone(self);
        func_800A4D6C(self, 1.0f, 1.0f);
        func_80092864(self, 1.0f);
        func_8009E474(self);
        func_80095A40(self);
        func_8009590C(self, 0.0f);
        baphysics_reset_gravity(self);
        func_80095964(self, 0);
        func_800947EC(self, 1, 0);
    }
}

void bstrexlarge_entrypoint_2(PlayerState* self)
{
    if (func_8009E77C(self, 0x11) == 0)
    {
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 0.6f);
        bastick_setZoneMax(self, 2, 1.0f);
        func_800A4D6C(self, 1.75f, 0.75f);
        func_80092864(self, 6.0f);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 180.0f);
        func_8009E53C(self, 0, 0.0f);
        func_8009E55C(self, 1, 240.0f);
        func_8009E53C(self, 1, 0.0f);
        func_800959C8(self, 400.0f, 270.0f);
        func_8009590C(self, 400.0f);
        baphysics_set_gravity(self, -3000.0f);
        func_80095964(self, 1);
        func_800947EC(self, 1, 1);
        self->unk15C.bytes[1] = 0;
        self->unk15C.bytes[2] = 0;
        self->unk164.word = 0;
    }
}

void bstrexlarge_entrypoint_3(PlayerState* self) {
    u8 temp_v0;

    temp_v0 = self->unk15C.bytes[1];
    if (temp_v0 != 0) {
        self->unk15C.bytes[1] = temp_v0 - 1;
    }
}

void func_80800834_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
}
void func_80800854_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_2(self);
}

void func_80800874_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_3(self);
}

s32 bstrexlarge_entrypoint_4(s32 arg0) {
    return D_808019A0_bstrexlarge[arg0];
}
void func_808008A8_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
    _bsdrone_entrypoint_2(self);
}
void func_808008D0_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_2(self);
    _bsdrone_entrypoint_0(self);
}
void func_808008F8_bstrexlarge(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
    bstrexlarge_entrypoint_3(self);
}
s32 bstrexlarge_entrypoint_5(s32 arg0) {
    return D_808019B0_bstrexlarge[arg0];
}

void func_80800934_bstrexlarge(PlayerState* self, s32 arg1) {
    AnimCtrl* temp_s0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    switch (arg1) {
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
        baanim_setEndAndDuration(self, 1, 0.8f);
        break;
    }
    self->unk15C.bytes[0] = (u8)arg1;
}


void func_80800A00_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
}
void func_80800A20_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    self->unk15C.bytes[0] = 0;
    func_80800934_bstrexlarge(self, 1);
}

void func_80800A50_bstrexlarge(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bstrexlarge_entrypoint_3(self);
    func_808004B4_bstrexlarge(self);
    switch (self->unk15C.bytes[0])
    {
    case 1:
        if (func_8008DF8C(self, 0x82) != 0) {
            func_80800934_bstrexlarge(self, 2);
        }
        break;
    case 2:
        func_80800044_bstrexlarge(self);
        if ((player_isStable(self) != 0) || (func_80800034_bstrexlarge(self) != 0))
        {
            func_800A2EAC(self);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            nextState = 0x147;
        }
        break;
    }
    bs_setState(self, nextState);
}

s32 bstrexlarge_entrypoint_6(s32 arg0) {
    return D_808019C0_bstrexlarge[arg0];
}

s32 bstrexlarge_entrypoint_7(PlayerState* self, f32* arg1)
{
    f32 temp_f0;
    f32 sp18[3];

    player_getCoords(self, sp18);
    temp_f0 = func_800EFC7C(sp18, arg1);
    if (temp_f0 < 160000.0f)
    {
        return 1;
    }
    if (temp_f0 > 2250000.0f)
    {
        return 0;
    }
    if (func_8008DAE8(self, arg1, 90.0f) == 0)
    {
        return 0;
    }
    return 1;
}

void func_80800BC4_bstrexlarge(PlayerState* self, s32 arg1)
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
        if (bastick_distance(self) != 0.0f)
        {
            yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
        }
        baphysics_set_target_yaw(self, yaw_getIdeal(self));
        sp28 = yaw_getIdeal(self);
        baphysics_set_horizontal_velocity(self, sp28, baphysics_get_target_horizontal_velocity(self));
        baphysics_set_vertical_velocity(self, 900.0f);
        baphysics_set_gravity(self, -1350.0f);
        if (rand_f() > 0.5f)
        {
            func_8009DBB0(self, 0x4D8, 0.5, 0.55f, 0x61A8);
            return;
        }
        func_8009DBB0(self, 0x4D9, 0.5, 0.55f, 0x61A8);
        return;
    case 2:
        baanim_setEndAndDuration(self, 1, 0.8f);
        return;
    case 0:
        baphysics_set_gravity(self, -3000.0f);
        return;
    }
}

void func_80800DAC_bstrexlarge(PlayerState* self)
{
    func_80800BC4_bstrexlarge(self,0);
    bstrexlarge_entrypoint_1(self);
}

void func_80800DD8_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_2(self);
    self->unk15C.bytes[0] = 0;
    func_80800BC4_bstrexlarge(self, 1);
}

void func_80800E08_bstrexlarge(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp28[3];

    nextState = BS_STATE_0_INVALID;
    bstrexlarge_entrypoint_3(self);
    func_8009BB24(self, sp28);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp28[1] > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.bytes[0])
    {
    case 1:
        func_808004B4_bstrexlarge(self);
        if (func_8008DF8C(self, 0x82) != 0)
        {
            func_80800BC4_bstrexlarge(self, 2);
        }
        break;
    case 2:
        func_808004B4_bstrexlarge(self);
        func_80800044_bstrexlarge(self);
        if ((player_isStable(self) != 0) || (func_80800034_bstrexlarge(self) != 0))
        {
            func_800A2EAC(self);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            nextState = 0x147;
        }
        break;
    }
    bs_setState(self, nextState);
}

s32 bstrexlarge_entrypoint_8(s32 arg0) {
    return D_808019D0_bstrexlarge[arg0];
}

void func_80800F2C_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
}
void func_80800F4C_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_2(self);
}

void func_80800F6C_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_3(self);
}

s32 bstrexlarge_entrypoint_9(s32 arg0) {
    return D_808019E0_bstrexlarge[arg0];
}

void func_80800FA0_bstrexlarge(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bstrexlarge_entrypoint_1(self);
}
void func_80800FC8_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0x147, 0.69f);
}

void func_80801008_bstrexlarge(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bstrexlarge_entrypoint_3(self);
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x151;
    }
    bs_setState(self, nextState);
}

s32 bstrexlarge_entrypoint_10(s32 arg0) {
    return D_808019F0_bstrexlarge[arg0];
}

void func_80801060_bstrexlarge(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    bstrexlarge_entrypoint_1(self);
}
void func_80801088_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_2(self);
    _bsrest_entrypoint_16(self);
}
void func_808010B0_bstrexlarge(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _bsrest_entrypoint_13(self);
    }
    bstrexlarge_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bstrexlarge_entrypoint_11(s32 arg0) {
    return D_80801A00_bstrexlarge[arg0];
}

void func_80801110_bstrexlarge(PlayerState* self) {
    f32 sp24[3];

    player_getCoords(self, sp24);
    self->unk160.word = func_800E1610(0, 30.0f, 1.0f, sp24);
    func_8009DF18(self, 0x56C, 1.0f, 0x7FFF);
    func_8009E5A4(self, 2, 1);
    func_8009E55C(self, 2, 600.0f);
    _bamotor_entrypoint_1(self, 1.0f, 1.0f, 5.0f);
}

void func_808011A8_bstrexlarge(PlayerState* self) {
    s32 temp_a2;

    temp_a2 = self->unk160.word;
    if (temp_a2 != -1) {
        func_800E144C(temp_a2, 0.86f);
    }
    func_8009E55C(self, 2, 0.0f);
    _bamotor_entrypoint_2(self, 1.0f, 0.1f, 0.5f);
}

void func_80801208_bstrexlarge(PlayerState* self) {
    func_808011A8_bstrexlarge(self);
    self->unk15C.bytes[2] = 0;
}

void func_80801230_bstrexlarge(PlayerState* self) {
    self->unk160.word = -1;
    self->unk15C.bytes[2] = self->unk15C.bytes[1];
}

void func_80801244_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
    func_80801208_bstrexlarge(self);
}
void func_8080126C_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    baanim_playForDuration_onceSmooth(self, 0x1D0, 3.1f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 8, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 55.0f, 0.8f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_80801230_bstrexlarge(self);
}

void func_808012EC_bstrexlarge(PlayerState* self)
{
    AnimCtrl* temp_v0;
    BanjoStateId nextState;
    f32 sp3C;
    Unkfunc_800E0960_1* sp38;
    f32 sp34;
    f32 sp28[3];
    temp_v0 = baanim_getAnimCtrlPtr(self);
    nextState = BS_STATE_0_INVALID;
    sp3C = anctrl_getAnimTimer(temp_v0);
    bstrexlarge_entrypoint_3(self);
    if (self->unk15C.bytes[2] != 0)
    {
        sp38 = func_80092AD8(self);
        func_800E0AF0(sp38, 1.0f);
        sp34 = ml_map_f(sp3C, 0.75f, 1.0f, -25.0f, 0.0f);
        func_800E0AFC(sp38, 1U, 1.0f, sp34, 0.0f, 0.0f);
        func_800E0AFC(sp38, 0x12U, 1.0f, sp34, 0.0f, 0.0f);
    }
    if ((func_800DB9B0() != 0) && (func_8009D2E4(self) == 8))
    {
        func_8009D2D8(self, 2);
    }
    if ((sp3C >= 0.3f) && (sp3C <= 0.7f))
    {
        player_getCoords(self, sp28);
        func_801013A8(sp28, 0x1B, self->unk184);
    }
    if (baanim_isAt(self, 0.13f) != 0)
    {
        func_80801110_bstrexlarge(self);
    }
    if (baanim_isAt(self, 0.9f) != 0)
    {
        func_808011A8_bstrexlarge(self);
    }
    if (baanim_isStopped(self) != 0)
    {
        nextState = 0x151;
    }
    bs_setState(self, nextState);
}

s32 bstrexlarge_entrypoint_12(s32 arg0) {
    return D_80801A10_bstrexlarge[arg0];
}

void func_808014A4_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
}
void func_808014C4_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    baanim_playForDuration_loopSmooth(self, 0x1CF, 0.7f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 300.0f, 3.5f);
    baanim_setDurationRange(self, 0.1f, 10.0f);
    func_8008C9F0(self, 400.0f, 1000.0f, 1.0f, 0.6f);
    func_8008CA30(self, 1.0f);
    func_80800000_bstrexlarge(self);
}

void func_80801574_bstrexlarge(PlayerState* self) {
    func_8080000C_bstrexlarge(self);
    bstrexlarge_entrypoint_3(self);
    func_808004B4_bstrexlarge(self);
    func_800A2D2C(self, 0.5702f, 3);
    func_800A2D2C(self, 0.0702f, 4);
    bs_setState(self, func_808002E0_bstrexlarge(self, BS_STATE_0_INVALID, 1));
}

s32 bstrexlarge_entrypoint_13(s32 arg0) {
    return D_80801A20_bstrexlarge[arg0];
}

void func_80801604_bstrexlarge(PlayerState* self)
{
    func_80090A2C(self);
    func_800951B4(self);
    bstrexlarge_entrypoint_1(self);
}

void func_80801634_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    baanim_playForDuration_loopSmooth(self, 0x1D2, 8.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 2, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 300.0f, 3.5f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
    func_80800000_bstrexlarge(self);
}

void func_808016B4_bstrexlarge(PlayerState* self) {
    func_8080000C_bstrexlarge(self);
    bstrexlarge_entrypoint_3(self);
    if (baanim_isAt(self, 0.095f) != 0) {
        func_8009DF18(self, 0x570, 0.9f, 0x4650);
    }
    if (baanim_isAt(self, 0.545f) != 0) {
        func_8009DEC0(self, 0x56F, 0.9f, 1.1f, 0x4E20, 0x55F0);
    }
    if (baanim_isAt(self, 0.82f) != 0) {
        func_8009DF18(self, 0x570, 0.9f, 0x4E20);
    }
    if (baanim_isAt(self, 0.92f) != 0) {
        func_8009DF18(self, 0x570, 1.0f, 0x32C8);
    }
    func_808004B4_bstrexlarge(self);
    bs_setState(self, func_808003C4_bstrexlarge(self, BS_STATE_0_INVALID, 1));
}

s32 bstrexlarge_entrypoint_14(s32 arg0) {
    return D_80801A30_bstrexlarge[arg0];
}

void func_808017DC_bstrexlarge(PlayerState* self)
{
    bstrexlarge_entrypoint_1(self);
}
void func_808017FC_bstrexlarge(PlayerState* self) {
    bstrexlarge_entrypoint_2(self);
    baanim_playForDuration_loopSmooth(self, 0x1CE, 1.2f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 300.0f, 3.5f);
    baanim_setDurationRange(self, 0.1f, 10.0f);
    func_8008C9F0(self, 100.0f, 400.0f, 1.5f, 1.0f);
    func_8008CA30(self, 1.0f);
    func_80800000_bstrexlarge(self);
}

void func_808018AC_bstrexlarge(PlayerState* self) {
    func_8080000C_bstrexlarge(self);
    bstrexlarge_entrypoint_3(self);
    func_808004B4_bstrexlarge(self);
    func_800A2D2C(self, 0.8977f, 3);
    func_800A2D2C(self, 0.3977f, 4);
    bs_setState(self, func_808002E0_bstrexlarge(self, BS_STATE_0_INVALID, 1));
}

s32 bstrexlarge_entrypoint_15(s32 arg0) {
    return D_80801A40_bstrexlarge[arg0];
}
