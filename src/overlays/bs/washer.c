#include "bs/washer.h"

extern s32 D_80801D60_bswasher;
extern s32 D_80801E10_bswasher[];
extern s32 D_80801E20_bswasher[];
extern s32 D_80801E30_bswasher[];
extern s32 D_80801E40_bswasher[];
extern s32 D_80801E50_bswasher[];
extern s32 D_80801E60_bswasher[];
extern s32 D_80801E70_bswasher[];
extern s32 D_80801E80_bswasher[];
extern s32 D_80801E90_bswasher[];
extern s32 D_80801EA0_bswasher[];
extern s32 D_80801EB0_bswasher;
extern s32 D_80801EC4_bswasher[];
extern s32 D_80801ED4_bswasher[];

void func_80800000_bswasher(PlayerState* self) {
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 900.0f));
}

BanjoStateId func_80800064_bswasher(PlayerState* self, BanjoStateId arg1)
{

    if (bainput_should_enter_first_person(self))
    {
        arg1 = _badrone_entrypoint_24(self);
    }
    if (bakey_pressed(self, BUTTON_A))
    {
        arg1 = 0x35;
    }
    return arg1;
}

void func_808000BC_bswasher(PlayerState* self) {
    yaw_setUpdateType(self, YAW_TYPE_3_BOUNDED);
    yaw_setVelocityBounded(self, 300.0f, 6.0f);
}

void func_808000F0_bswasher(PlayerState* self) {
    if (func_8009E74C(self, 0x15) == 0) {
        func_800947EC(self, 1, 0);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009C000(self);
        baroll_resetAngularVelocity(self);
        bastick_popZone(self);
        func_80095A40(self);
        func_80095964(self, 0);
        func_8009E474(self);
        baflag_clear(self, BA_FLAG_3);
        baflag_clear(self, BA_FLAG_4);
        _bawasher_entrypoint_1(self);
        func_80092864(self, 1.0f);
    }
}

void func_808001A8_bswasher(PlayerState* self) {
    if (func_8009E77C(self, 0x15) == 0) {
        _bawasher_entrypoint_2(self);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800959C8(self, 100.0f, 52.0f);
        func_80095964(self, 1);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 70.0f);
        func_8009E55C(self, 1, 78.0f);
        baflag_set(self, BA_FLAG_3);
        baflag_set(self, BA_FLAG_4);
        func_800947EC(self, 1, 1);
        func_80092864(self, 1.7999878f);
    }
}

void bswasher_entrypoint_0(PlayerState* self) {
    f32 sp24[3];
    s32 sp20;

    sp20 = func_800B5BE4(8);
    player_getCoords(self, &sp24);
    func_800BABB8(sp20, &sp24, NULL, 1.0f, &D_80801D60_bswasher);
}

void func_80800300_bswasher(PlayerState* self) {
    f32 sp3C;
    s32 pad[3];
    f32 sp2C;
    f32 temp_f0;

    sp2C = yaw_getIdeal(self);
    _bawasher_entrypoint_4(self, func_800F1DCC(sp2C, yaw_get(self)));
    temp_f0 = baphysics_get_horizontal_velocity(self);
    if (temp_f0 > 1.0f)
    {
        temp_f0 = ml_map_f(temp_f0, 30.0f, 900.0f, 45.0f, 1350.0f);
    }
    else
    {
        temp_f0 = 0.0f;
    }
    _bawasher_entrypoint_5(self, temp_f0);
    temp_f0 = baphysics_get_horizontal_velocity(self);
    if (temp_f0 > 0.0f)
    {
        sp3C = ml_map_f(temp_f0, 30.0f, 900.0f, 0.8f, 1.25f);
    }
    else
    {
        sp3C = 0.8f;
    }
    if (player_isStable(self) == 0) {
        ml_min_f(1.9f, sp3C + 0.3f);
    }
    _bawasher_entrypoint_9(self);
}

void func_8080042C_bswasher(PlayerState* self, s32 arg1) {
    AnimCtrl* sp24;

    switch (arg1)
    {
    case 4:
        break;
    case 1:
        sp24 = baanim_getAnimCtrlPtr(self);
        anctrl_reset(sp24);
        anctrl_setSmoothTransition(sp24, 0);
        anctrl_setIndex(sp24, 0x32);
        anctrl_setSubrange(sp24, 0.0f, 0.2541f);
        anctrl_setDuration(sp24, 2.5f);
        anctrl_setPlaybackType(sp24, 1);
        anctrl_start(sp24);
        func_8009D820(self, 1.8f);
        break;
    case 2:
        baanim_setEnd(self, 0.5741f);
        func_8009DF94(self, 0x417, 0.8f, 0x4650);
        func_8009DF18(self, 0x428, 1.8f, 0x4650);
        baphysics_set_vertical_velocity(self, 400.0f);
        break;
    case 3:
        baanim_setEnd(self, 1.0f);
        func_8009DF94(self, 0x417, 0.8f, 0x4650);
        func_8009DF18(self, 0x428, 1.8f, 0x4650);
        break;
    }
    self->unk15C.word = arg1;
}

void func_80800590_bswasher(PlayerState* self)
{
    _basudie_entrypoint_6(self);
    func_808000F0_bswasher(self);
}

void func_808005B8_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    _basudie_entrypoint_2(self, self->unk16C, 420.0f, -1200.0f);
    self->unk15C.word = 0;
    self->unk16C = 250.0f;
    func_8080042C_bswasher(self, 1);
}

void func_80800608_bswasher(PlayerState* self)
{
    f32 temp_f0;
    s32 temp_v0;

    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.word)
    {
    case 1:
        if (player_isStable(self) != 0)
        {
            func_8080042C_bswasher(self, 2);
        }
        break;
    case 2:
        if (player_isStable(self) != 0)
        {
            func_8080042C_bswasher(self, 3);
        }
        break;
    case 3:
        func_8080042C_bswasher(self, 4);
        break;
    case 4:
        temp_f0 = self->unk16C;
        if (temp_f0 > 0.0f) {
            self->unk16C = ml_max_f(0.0f, temp_f0 - 10.0f);
        }
        break;
    }
    func_80800300_bswasher(self);
    bs_setState(self, BS_STATE_0_INVALID);
}

s32 bswasher_entrypoint_1(s32 arg0) {
    return D_80801E10_bswasher[arg0];
}

void func_80800714_bswasher(PlayerState* self) {
    if (_badrone_entrypoint_3(self) == 2) {
        _bafpctrl_entrypoint_10(self, 0);
        func_800947EC(self, 2, 0);
    }
    func_808000F0_bswasher(self);
    _bsdrone_entrypoint_2(self);
}

void func_80800770_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    _bsdrone_entrypoint_0(self);
    _batimer_set(self, 2, 0.0f);
    if (_badrone_entrypoint_3(self) == 2) {
        func_800947EC(self, 2, 1);
        _bafpctrl_entrypoint_10(self, 1);
    }
}

void func_808007DC_bswasher(PlayerState* self) {
    _bsdrone_entrypoint_1(self);
    func_80800300_bswasher(self);
    if (_badrone_entrypoint_3(self) == 2) {
        _batimer_decrement(self, 2);
        if ((bakey_pressed(self, BUTTON_Z) != 0) && (_batimer_isZero(self, 2) != 0)) {
            func_8009DBB0(self, 0x573, 1.05f, 1.15f, 0x4E20);
            func_8009DBB0(self, 0x406, 0.85f, 0.95f, 0x4E20);
            _bawasher_entrypoint_7(self);
            _batimer_set(self, 2, 0.5f);
        }
    }
}

s32 bswasher_entrypoint_2(s32 arg0)
{
    return D_80801E20_bswasher[arg0];
}

void func_808008BC_bswasher(PlayerState* self)
{
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_808000F0_bswasher(self);
}

void func_808008F4_bswasher(PlayerState* self)
{
    AnimCtrl* temp_v0;

    func_808001A8_bswasher(self);
    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x355);
    anctrl_setStart(temp_v0, 0.5036f);
    anctrl_setDuration(temp_v0, 0.7f);
    anctrl_setPlaybackType(temp_v0, 3);
    anctrl_start(temp_v0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_6_AIRBORN);
    func_808000BC_bswasher(self);
    self->unk15C.word = 0;
}

void func_8080099C_bswasher(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_8009D3A8(self, 0);
    func_80800000_bswasher(self);
    func_8009BB24(self, sp24);
    switch (self->unk15C.word)
    {
    case 2:
        break;
    case 0:
        if (func_8008DF8C(self, 0x82) != 0)
        {
            baanim_setEnd(self, 0.706f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(self) != 0)
        {
            func_800A2EAC(self);
            baphysics_set_target_horizontal_velocity(self, 0);
            baanim_setEndAndDuration(self, 1, 1.0f);
            self->unk15C.word = 2;
        }
        break;
    }
    if ((player_isStable(self) != 0) && ((bastick_getZone(self) > 0) || ((self->unk15C.word == 2) && (anctrl_isStopped(sp30) != 0))))
    {
        if (baflag_isTrue(self, BA_FLAG_19) != 0)
        {
            nextState = _badrone_entrypoint_28(self);
        }
        else
        {
            nextState = 0x32;
        }
    }
    func_80800300_bswasher(self);
    bs_setState(self, nextState);
}

s32 bswasher_entrypoint_3(s32 arg0) {
    return D_80801E30_bswasher[arg0];
}

void func_80800B08_bswasher(PlayerState* self) {
    s32 pad[2];
    f32 sp2C;
    AnimCtrl* temp_v0;

    func_808001A8_bswasher(self);
    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x355);
    anctrl_setSubrange(temp_v0, 0.0f, 0.5f);
    anctrl_setDuration(temp_v0, 1.0f);
    anctrl_setStart(temp_v0, 0.15f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_6_AIRBORN);
    func_808000BC_bswasher(self);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800000_bswasher(self);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 693.5f);
    baphysics_set_gravity(self, -2400.0f);
    func_8009D7A4(self, 1.35f, 1.45f);
    self->unk15C.word = 0;
}

void func_80800C70_bswasher(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_80800000_bswasher(self);
    func_8009BB24(self, sp24);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp24[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word)
    {
    case 0:
        if (func_8008DF8C(self, 0x82) != 0)
        {
            baanim_setEndAndDuration(self, 1, 0.7f);
            self->unk15C.word = 2;
        }
        else if (anctrl_isStopped(sp30) != 0) {
            baanim_setEndAndDuration(self, 0.706f, 3.0f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(self, 0x82) != 0) {
            baanim_setEndAndDuration(self, 1, 1.0f);
            self->unk15C.word = 2;
        }
        break;
    case 2:
        func_8009D3A8(self, 0);
        if (player_isStable(self) != 0) {
            func_800A2EAC(self);
            baanim_setEndAndDuration(self, 1, 1.0f);
            self->unk15C.word = 3;
        }
        break;
    case 3:
        func_8009D2D8(self, 3);
        func_8009D3A8(self, 0);
        if (baphysics_get_horizontal_velocity(self) > 0.0f) {
            nextState = 0x33;
        }
        else if (anctrl_isStopped(sp30) != 0) {
            nextState = 0x32;
        }
        if (bakey_pressed(self, BUTTON_A) != 0) {
            nextState = 0x35;
        }
        break;
    }
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        nextState = 0x38;
    }
    func_80800300_bswasher(self);
    bs_setState(self, nextState);
}

void func_80800E74_bswasher(PlayerState* self) {
    baphysics_reset_gravity(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_808000F0_bswasher(self);
}

s32 bswasher_entrypoint_4(s32 self) {
    return D_80801E40_bswasher[self];
}

void func_80800EC8_bswasher(PlayerState* self) {
    if (func_8009E6EC(self) == 0x65) {
        self->unk160.object = func_80099A4C(self);
        bs_setState(self, 0x37);
    }
    func_80099B94(self);
}

void func_80800F1C_bswasher(PlayerState* self) {

    if (self->unk164.bytes[1] != 0) {
        func_800C2FDC(self->unk164.bytes[1]);
        self->unk164.bytes[1] = 0U;
    }
}

void func_80800F54_bswasher(PlayerState* self) {
    self->unk164.bytes[1] = func_8009D454(self, 0, D_80801E50_bswasher);
}

void func_80800F88_bswasher(PlayerState* self)
{
    s32 pad;
    f32 sp38;
    f32 sp2C[3];

    if (self->unk164.bytes[1] != 0)
    {
        sp38 = baphysics_get_horizontal_velocity(self);
        player_getCoords(self, sp2C);
        func_800C35E8(self->unk164.bytes[1], sp2C);
        func_800C31DC(self->unk164.bytes[1], ml_map_f(sp38, 0.0f, 900.0f, 0.9f, 1.2f));
    }
}

void func_8080100C_bswasher(PlayerState* self)
{
    func_80800F1C_bswasher(self);
    func_808000F0_bswasher(self);
}

void func_80801034_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    baanim_playForDuration_loopSmooth(self, 0x359, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 30.0f, 900.0f, 0.7f, 0.3f);
    func_8008CA30(self, 1.0f);
    func_808000BC_bswasher(self);
    func_80800F54_bswasher(self);
}

void func_808010DC_bswasher(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800F88_bswasher(self);
    func_8009D3A8(self, 0);
    func_80800000_bswasher(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        nextState = 0x32;
    }
    if (func_8008DD04(self) != 0) {
        nextState = 0x36;
    }
    if (bakey_pressed(self, BUTTON_A) != 0) {
        nextState = 0x35;
    }
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        nextState = 0x38;
    }
    if (func_8008E148(self) != 0) {
        nextState = _badrone_entrypoint_25(self);
    }
    func_80800300_bswasher(self);
    bs_setState(self, nextState);
}

s32 bswasher_entrypoint_5(s32 arg0) {
    return D_80801E60_bswasher[arg0];
}

void func_808011B4_bswasher(PlayerState* self)
{
    _baspin_entrypoint_1(self);
    func_808000F0_bswasher(self);
}

void func_808011DC_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    _baspin_entrypoint_2(self, 0x358, 1.8f, 2, 0);
}

void func_80801218_bswasher(PlayerState* self) {
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    func_80800300_bswasher(self);
    if (func_8009640C(self) != 0) {
        func_800A2EAC(self);
    }
    if (_baspin_entrypoint_3(self) == 2) {
        sp24 = 0x32;
    }
    bs_setState(self, sp24);
}

s32 bswasher_entrypoint_6(s32 arg0) {
    return D_80801E70_bswasher[arg0];
}

void func_80801294_bswasher(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    func_808000F0_bswasher(self);
}

void func_808012BC_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0x358, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(self), 0.1026f);
}

void func_80801314_bswasher(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_2(self) != 0) {
        func_80800000_bswasher(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x32;
    }
    bs_setState(self, nextState);
}

s32 bswasher_entrypoint_7(s32 arg0) {
    return D_80801E80_bswasher[arg0];
}

void func_8080137C_bswasher(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_808000F0_bswasher(self);
}

void func_808013A4_bswasher(PlayerState* self)
{
    func_808001A8_bswasher(self);
    _bsrest_entrypoint_16(self);
}

void func_808013CC_bswasher(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _bsrest_entrypoint_13(self);
    }
    func_80800300_bswasher(self);
    bs_setState(self, nextState);
}

s32 bswasher_entrypoint_8(s32 arg0) {
    return D_80801E90_bswasher[arg0];
}

void func_8080142C_bswasher(PlayerState* self)
{
    func_808000F0_bswasher(self);
    func_80090A2C(self);
}

void func_80801454_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    baanim_playForDuration_loopSmooth(self, 0x356, 3.9f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_2_NORMAL);
    func_808000BC_bswasher(self);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_808014C8_bswasher(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_8009D3A8(self, 0);
    if ((baanim_isAt(self, 0.1487f) != 0) || (baanim_isAt(self, 0.2737f) != 0)) {
        func_8009DEC0(self, 0x4A1, 0.9f, 1.1f, 0xBB8, 0xFA0);
    }
    if (func_8008E148(self) != 0) {
        nextState = _badrone_entrypoint_25(self);
    }
    if (func_8008DD04(self) != 0) {
        nextState = 0x36;
    }
    if (bastick_getZone(self) != BS_STICK_ZONE_ID_0) {
        nextState = 0x33;
    }
    nextState = func_800A02DC(self, func_80800064_bswasher(self, nextState));
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        nextState = 0x38;
    }
    func_80800300_bswasher(self);
    bs_setState(self, nextState);
}

s32 bswasher_entrypoint_9(s32 arg0) {
    return D_80801EA0_bswasher[arg0];
}

void func_808015EC_bswasher(PlayerState* self, u32 arg1)
{
    switch (self->unk15C.word)
    {
    case 3:
        if (self->unk164.bytes[0] != 0)
        {
            func_800C2FDC(self->unk164.bytes[0]);
            self->unk164.bytes[0] = 0;
        }
        break;
    }
    self->unk15C.word = arg1;
    switch (arg1)
    {
    case 0:
        break;
    case 1:
        baanim_playForDuration_onceSmooth(self, 0x354, 6.7f);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 2, BA_PHYSICS_2_NORMAL);
        func_808000BC_bswasher(self);
        yaw_setIdeal(self, yaw_get(self));
        self->unk164.bytes[0] = 0;
        break;
    case 2:
        _chfactoryworkerdirty_entrypoint_1(self->unk160.word, 1);
        break;
    case 3:
        _chfactoryworkerdirty_entrypoint_1(self->unk160.word, 2);
        break;
    case 4:
        func_8009DBB0(self, 0x573, 1.05f, 1.15f, 0x4E20);
        func_8009DBB0(self, 0x406, 0.85f, 0.95f, 0x4E20);
        _chfactoryworkerdirty_entrypoint_1(self->unk160.word, 3);
        break;
    case 5:
        _chfactoryworkerdirty_entrypoint_1(self->unk160.word, 4);
    }
    return;
}

void func_80801744_bswasher(PlayerState* self)
{
    func_808015EC_bswasher(self,0);
    func_808000F0_bswasher(self);
}

void func_80801770_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    self->unk15C.word = 0;
    func_808015EC_bswasher(self, 1U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808017A0_bswasher.s")

s32 bswasher_entrypoint_10(s32 arg0) {
    return D_80801EC4_bswasher[arg0];
}
void func_80801B10_bswasher(PlayerState* self)
{
    func_808000F0_bswasher(self);
}

void func_80801B30_bswasher(PlayerState* self) {
    func_808001A8_bswasher(self);
    baanim_playForDuration_onceSmooth(self, 0x357, 0.8f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 2, BA_PHYSICS_2_NORMAL);
    func_808000BC_bswasher(self);
    yaw_setIdeal(self, yaw_get(self));
}

void func_80801BA4_bswasher(PlayerState* self) {
    BanjoStateId nextState;
    s32 pad2[1];
    f32 sp2C;

    nextState = BS_STATE_0_INVALID;
    sp2C = baphysics_get_target_horizontal_velocity(self);
    baphysics_set_target_horizontal_velocity(self, (0.028f / time_getDelta()) * sp2C);
    if (baanim_isAt(self, 0.1309f) != 0) {
        func_8009DBB0(self, 0x573, 1.05f, 1.15f, 0x4E20);
        func_8009DBB0(self, 0x406, 0.85f, 0.95f, 0x4E20);
        _bawasher_entrypoint_7(self);
        func_8009D2D8(self, 1);
    }
    if (baanim_isStopped(self) != 0) {
        nextState = 0x32;
    }
    if (baanim_getTimer(self) > 0.8f) {
        if (bastick_getZone(self) != BS_STICK_ZONE_ID_0) {
            nextState = 0x33;
        }
        if (bakey_pressed(self, BUTTON_Z) != 0) {
            nextState = 0x38;
        }
    }
    bs_setState(self, nextState);
}

s32 bswasher_entrypoint_11(s32 arg0) {
    return D_80801ED4_bswasher[arg0];
}
