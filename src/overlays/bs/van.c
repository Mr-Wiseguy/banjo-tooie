#include "bs/van.h"

extern s32 D_80801B90_bsvan;
extern s32 D_80801C40_bsvan;
extern s32 D_80801C8C_bsvan[];
extern s32 D_80801C9C_bsvan[];
extern s32 D_80801CAC_bsvan[];
extern s32 D_80801CBC_bsvan[];
extern s32 D_80801CCC_bsvan[];
extern s32 D_80801CDC_bsvan[];
extern s32 D_80801CEC_bsvan[];
extern s32 D_80801CFC_bsvan[];
extern s32 D_80801D0C_bsvan[];
extern s32 D_80801D70_bsvan[];
extern s32 D_80801D80_bsvan[];

extern s32 _bsvan_entrypoint_15;

void func_80800000_bsvan(PlayerState* self) {
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 900.0f));
}

BanjoStateId func_80800064_bsvan(PlayerState* self, BanjoStateId arg1)
{
    if (bainput_should_enter_first_person(self) != 0)
    {
        arg1 = _badrone_entrypoint_24(self);
    }
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = 0x115;
    }
    return arg1;
}

void func_808000BC_bsvan(PlayerState* self) {
    if (bakey_pressed(self, BUTTON_B) != 0) {
        _bavan_entrypoint_1(self);
    }
}

void bsvan_entrypoint_0(PlayerState* self) {
    if (func_8009E74C(self, 0xD) == 0) {
        _bastatemem_entrypoint_1(self);
        func_80092864(self, 1.0f);
        func_800947EC(self, 1, 0);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009C000(self);
        baroll_resetAngularVelocity(self);
        bastick_popZone(self);
        func_80095A40(self);
        func_8009E474(self);
        baflag_clear(self, BA_FLAG_3);
        baflag_clear(self, BA_FLAG_4);
        _bavan_entrypoint_2(self);
    }
}

void bsvan_entrypoint_1(PlayerState* self) {
    if (func_8009E77C(self, 0xD) == 0) {
        _bastatemem_entrypoint_0(self, 0x14);
        _bavan_entrypoint_3(self);
        //I think this is an error
        self->bsvan->unk0 = 0;
        self->unk174 = 1.0f;
        _batimer_set(self, 2, 0.0f);
        func_80092864(self, 2.2999878f);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800959C8(self, 110.0f, 65.0f);
        func_8009590C(self, 110.0f);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 70.0f);
        func_8009E55C(self, 1, 78.0f);
        baflag_set(self, BA_FLAG_3);
        baflag_set(self, BA_FLAG_4);
        func_800947EC(self, 1, 1);
    }
}

void bsvan_entrypoint_2(PlayerState* self) {
    f32 sp24[3];
    s32 sp20;

    sp20 = func_800B5BE4(8);
    player_getCoords(self, sp24);
    func_800BABB8(sp20, sp24, NULL, 1.0f, &D_80801B90_bsvan);
}

void func_8080032C_bsvan(PlayerState* self) {
    f32 sp2C[3];
    s32 sp28;

    func_80092C90(self, sp2C, 4);
    sp28 = func_800B5BE4(8);
    func_800BABB8(sp28, sp2C, NULL, 1.0f, &D_80801C40_bsvan);
    func_800BA77C(sp28, 0, 0, (s16)(s32)rand_fBounded(0.0f, 359.0f));
    func_800BA22C(sp28, 1);
}

void bsvan_entrypoint_3(PlayerState* self)
{
    f32 sp3C;
    s32 pad;
    f32 var_f12;
    f32 temp_f0;
    f32 sp2C;


    sp2C = yaw_getIdeal(self);
    _bavan_entrypoint_5(self, func_800F1DCC(sp2C, yaw_get(self)));
    var_f12 = baphysics_get_horizontal_velocity(self);
    var_f12 = var_f12 > 1.0f ? ml_map_f(var_f12, 30.0f, 900.0f, 45.0f, 1350.0f) : 0.0f;
    _bavan_entrypoint_6(self, var_f12);
    temp_f0 = baphysics_get_horizontal_velocity(self);
    if (temp_f0 > 0.0f)
    {
        sp3C = ml_map_f(temp_f0, 30.0f, 900.0f, 0.8f, 1.25f);
    }
    else
    {
        sp3C = 0.8f;
    }
    if (!player_isStable(self))
    {
        sp3C = ml_min_f(1.9f, sp3C + 0.3f);
    }
    _bavan_entrypoint_4(self, sp3C);
    _bavan_entrypoint_8(self);
}

void func_808004F8_bsvan(PlayerState* self)
{
    _basudie_entrypoint_6(self);
    bsvan_entrypoint_0(self);
}

void func_80800520_bsvan(PlayerState* self) {
    AnimCtrl* temp_s0;

    temp_s0 = baanim_getAnimCtrlPtr(self);
    bsvan_entrypoint_1(self);
    self->unk16C = 250.0f;
    _basudie_entrypoint_2(self, 250.0f, 420.0f, -1200.0f);
    anctrl_reset(temp_s0);
    anctrl_setSmoothTransition(temp_s0, 0);
    anctrl_setIndex(temp_s0, 0xD7);
    anctrl_setSubrange(temp_s0, 0.0f, 0.3966f);
    anctrl_setDuration(temp_s0, 1.7f);
    anctrl_setPlaybackType(temp_s0, 1);
    anctrl_start(temp_s0);
    func_8009D820(self, 1.8f);
    self->unk15C.word = 0;
}

void func_808005E4_bsvan(PlayerState* self) {
    f32 temp_f0;
    s32 temp_v0;

    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.word)
    {
    case 0:
        if (player_isStable(self) != 0)
        {
            baanim_setEnd(self, 0.7453f);
            func_8009DF18(self, 0x417, 0.8f, 0x4650);
            func_8009DF18(self, 0x428, 1.8f, 0x4650);
            baphysics_set_vertical_velocity(self, 400.0f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(self) != 0) {
            baanim_setEnd(self, 1.0f);
            func_8009DF18(self, 0x417, 0.8f, 0x4650);
            func_8009DF18(self, 0x428, 1.8f, 0x4650);
            self->unk15C.word = 2;
        }
        break;
    case 2:
        self->unk15C.word = 3;
        break;
    case 3:
        temp_f0 = self->unk16C;
        if (temp_f0 > 0.0f)
        {
            self->unk16C = ml_max_f(0.0f, temp_f0 - 10.0f);
        }
        break;
    }
    bsvan_entrypoint_3(self);
    bs_setState(self, BS_STATE_0_INVALID);
}

s32 bsvan_entrypoint_4(s32 arg0) {
    return D_80801C8C_bsvan[arg0];
}

void func_80800760_bsvan(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    bsvan_entrypoint_0(self);
}

void func_80800788_bsvan(PlayerState* self)
{
    bsvan_entrypoint_1(self);
    _bsdrone_entrypoint_0(self);
}

void func_808007B0_bsvan(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
    bsvan_entrypoint_3(self);
}

s32 bsvan_entrypoint_5(s32 arg0) {
    return D_80801C9C_bsvan[arg0];
}

void func_808007EC_bsvan(PlayerState* self) {
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    bsvan_entrypoint_0(self);
}

void func_80800824_bsvan(PlayerState* self) {
    AnimCtrl* temp_v0;

    bsvan_entrypoint_1(self);
    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0xED);
    anctrl_setStart(temp_v0, 0.359f);
    anctrl_setDuration(temp_v0, 0.7f);
    anctrl_setPlaybackType(temp_v0, 3);
    anctrl_start(temp_v0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_6_AIRBORN);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    self->unk15C.word = 0;
}

void func_808008D4_bsvan(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_8009D3A8(self, 0);
    func_80800000_bsvan(self);
    func_8009BB24(self, sp24);
    switch (self->unk15C.word)
    {
    case 2:
        break;
    case 0:
        if (func_8008DF8C(self, 0x82) != 0)
        {
            baanim_setEnd(self, 0.6939f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(self) != 0)
        {
            func_800A2EAC(self);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
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
            nextState = 0x11A;
        }
    }
    if (player_inWater(self))
    {
        nextState = 0x11D;
    }
    func_808000BC_bsvan(self);
    bsvan_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_6(s32 arg0) {
    return D_80801CAC_bsvan[arg0];
}

void func_80800A5C_bsvan(PlayerState* self)
{
    s32 pad[2];
    f32 sp2C;
    AnimCtrl* temp_v0;

    bsvan_entrypoint_1(self);
    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0xED);
    anctrl_setSubrange(temp_v0, 0.0f, 0.359f);
    anctrl_setDuration(temp_v0, 1.0f);
    anctrl_setStart(temp_v0, 0.15f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_6_AIRBORN);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800000_bsvan(self);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 693.5f);
    baphysics_set_gravity(self, -1200.0f);
    func_8009D7A4(self, 1.35f, 1.45f);
    _bavan_entrypoint_7(self, 0.0f);
    self->unk15C.word = 0;
}

void func_80800BDC_bsvan(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 sp24[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_8080032C_bsvan(self);
    func_80800000_bsvan(self);
    func_8009BB24(self, sp24);
    if ((bakey_released(self, BUTTON_A) != 0) && (sp24[1] > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word)
    {
    case 0:
        if (func_8008DF8C(self, 0x82) != 0) {
            baanim_setEndAndDuration(self, 1.0f, 0.7f);
            self->unk15C.word = 2;
        }
        else if (anctrl_isStopped(sp30) != 0) {
            baanim_setEndAndDuration(self, 0.69f, 3.0f);
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
            nextState = 0x116;
        }
        else if (anctrl_isStopped(sp30) != 0) {
            nextState = 0x11A;
        }
        if (bakey_pressed(self, BUTTON_A) != 0) {
            nextState = 0x115;
        }
        break;
    }
    if ((baphysics_get_vertical_velocity(self) < 0.0f) && (player_inWater(self) != 0)) {
        nextState = 0x11D;
    }
    func_808000BC_bsvan(self);
    bsvan_entrypoint_3(self);
    bs_setState(self, nextState);
}

void func_80800E0C_bsvan(PlayerState* self) {
    baphysics_reset_gravity(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    bsvan_entrypoint_0(self);
}

s32 bsvan_entrypoint_7(s32 arg0) {
    return D_80801CBC_bsvan[arg0];
}

void func_80800E60_bsvan(PlayerState* self, s32(*arg1)(PlayerState*))
{
    s32 temp;
    switch (func_8009E6EC(self))
    {
    case 0x46:
        self->bsvan->unk0 = func_80099A4C(self);
        self->bsvan->unk10 = _chfaircoinbox_entrypoint_0(self->bsvan->unk0, self->bsvan->unk4);
        func_8009E830(self, 2);
        bs_setState(self, 0x121);
        return;
    default:
        arg1(self);
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x2E:
    case 0x4E:
    case 0x51:
    case 0x52:
        return;
    }
    return;
}

void bsvan_entrypoint_8(PlayerState* self)
{
    func_80800E60_bsvan(self, func_80099B94);
}

void bsvan_entrypoint_9(PlayerState* self) {
    func_80800E60_bsvan(self, _bsdrone_entrypoint_3);
}

void func_80800F50_bsvan(PlayerState* self)
{
    bsvan_entrypoint_0(self);
}

void func_80800F70_bsvan(PlayerState* self) {
    bsvan_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0xEC, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 30.0f, 900.0f, 1.0f, 0.4f);
    func_8008CA30(self, 1.0f);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
}

void func_80801034_bsvan(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_8009D3A8(self, 0);
    func_80800000_bsvan(self);
    func_8080032C_bsvan(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        nextState = 0x11A;
    }
    if (func_8008E148(self) != 0) {
        nextState = _badrone_entrypoint_25(self);
    }
    if (func_8008DD04(self) != 0) {
        nextState = 0x114;
    }
    func_808000BC_bsvan(self);
    if (bakey_pressed(self, BUTTON_A) != 0) {
        nextState = 0x115;
    }
    if (player_inWater(self) != 0) {
        nextState = 0x11B;
    }
    bsvan_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_10(s32 arg0) {
    return D_80801CCC_bsvan[arg0];
}

void func_80801118_bsvan(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bsvan_entrypoint_0(self);
}

void func_80801140_bsvan(PlayerState* self) {
    bsvan_entrypoint_1(self);
    _babounce_entrypoint_4(self, 1);
    _babounce_entrypoint_5(self, 0xEF, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(self), 0.1026f);
}

void func_80801198_bsvan(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.5f) != 0) {
        func_800951B4(self);
    }
    if (_babounce_entrypoint_2(self) != 0) {
        func_80800000_bsvan(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x11A;
    }
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_11(s32 self) {
    return D_80801CDC_bsvan[self];
}

void func_80801224_bsvan(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    bsvan_entrypoint_0(self);
}

void func_8080124C_bsvan(PlayerState* self) {
    bsvan_entrypoint_1(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0xEF, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(self), 0.1026f);
}

void func_808012A4_bsvan(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_2(self) != 0) {
        func_80800000_bsvan(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x11A;
    }
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_12(s32 arg0)
{
    return D_80801CEC_bsvan[arg0];
}

void func_8080130C_bsvan(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    bsvan_entrypoint_0(self);
}

void func_80801334_bsvan(PlayerState* self)
{
    bsvan_entrypoint_1(self);
    _bsrest_entrypoint_16(self);
}

void func_8080135C_bsvan(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _bsrest_entrypoint_13(self);
    }
    bsvan_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_13(s32 arg0) {
    return D_80801CFC_bsvan[arg0];
}

void func_808013BC_bsvan(PlayerState* self)
{
    bsvan_entrypoint_0(self);
    func_80090A2C(self);
}

void func_808013E4_bsvan(PlayerState* self) {
    bsvan_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0xEE, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_8080145C_bsvan(PlayerState* self) {
    BanjoStateId nextState;
    f32 sp64[2];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    s32 sp3C;

    nextState = BS_STATE_0_INVALID;
    func_8009D3A8(self, 0);
    if ((baanim_isAt(self, 0.0122f) != 0) || (baanim_isAt(self, 0.5122f) != 0))
    {
        sp3C = func_800B5BE4(8);
        player_getCoords(self, sp58);
        func_80092C90(self, sp40, 4);
        ml_getdiff_vec3f(sp4C, sp40, sp58);
        func_800F1A88(sp4C, sp64);
        sp64[0] = -sp64[0] - 10/*.0f*/;

        func_800BA994((unkStruct800BA198*)sp3C, sp64[0], (sp64[1] - 10.0f), 0x96, sp64[0], (sp64[1] + 10.0f), 0xC8);
        func_800BA77C(sp3C, 0, 0, rand_fBounded(0.0f, 359.0f));
        func_800BABB8(sp3C, sp40, NULL, 1.0f, &D_80801D0C_bsvan);
    }
    func_808000BC_bsvan(self);
    if (bastick_getZone(self) > 0)
    {
        nextState = 0x116;
    }
    if (func_8008E148(self) != 0)
    {
        nextState = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0)
    {
        nextState = 0x11D;
    }
    nextState = func_800A02DC(self, func_80800064_bsvan(self, nextState));
    bsvan_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_14(s32 arg0) {
    return D_80801D70_bsvan[arg0];
}

void func_8080164C_bsvan(PlayerState* self, s32 arg1) {
    f32 sp24[3];

    player_getCoords(self, sp24);
    switch (arg1)
    {
    case 1:
        yaw_setIdeal(self, func_800F1DF4(sp24, self->bsvan->unk4) + 180.0f);
        break;
    case 2:
        baanim_playForDuration_onceSmooth(self, 0xF1, 1.2f);
        break;
    case 3:
        if (self->unk15C.word == 2)
        {
            _batimer_set(self, 3, 0.001f);
        }
        else
        {
            _batimer_set(self, 3, 0.5f);
        }
        break;
    case 4:
        baanim_playForDuration_onceSmooth(self, 0xF2, 1.3f);
        break;
    case 5:
        yaw_setIdeal(self, func_800F1DF4(sp24, self->bsvan->unk4));
        break;
    }
    self->unk15C.word = arg1;
}

void func_80801770_bsvan(PlayerState* self) {
    _chfaircoinbox_entrypoint_1(self->bsvan->unk0);
    bsvan_entrypoint_0(self);
}

void func_808017A0_bsvan(PlayerState* self) {
    bsvan_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0xEE, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, BA_PHYSICS_2_NORMAL);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    self->unk15C.word = 0;
    func_8080164C_bsvan(self, 1);
}

void bsvan_entrypoint_15(s32 self)
{
    PlayerState* sp34;
    f32 sp28[3];
    f32 sp1C[3];

    sp34 = character_getPlayerState(self);
    player_getCoords(sp34, sp28);
    ml_vec3f_copy(sp1C, sp34->bsvan->unk4);
    sp28[1] += 20.0f;
    sp1C[1] += 40.0f;
    _chfaircoin_entrypoint_0(sp28, sp1C, 0.5f);
}

void func_80801890_bsvan(PlayerState* self)
{
    BanjoStateId nextState;
    f32 sp20;

    nextState = BS_STATE_0_INVALID;
    func_8009D3A8(self, 0);
    switch (self->unk15C.word)
    {
    case 1:
        sp20 = yaw_get(self);
        if (yaw_getIdeal(self) == sp20)
        {
            func_8080164C_bsvan(self, 2);
        }
        break;
    case 2:
        if (baanim_isAt(self, 0.08f) != 0)
        {
            func_8009DF18(self, 0x56D, 1.0f, 0x55F0);
        }
        if (baanim_isAt(self, 0.5049f) != 0)
        {
            func_8080164C_bsvan(self, 3);
        }
        break;
    case 3:
        if (_batimer_decrement(self, 3) != 0)
        {
            _chbaddiesetup_entrypoint_1(&_bsvan_entrypoint_15,self->unk184);
            self->bsvan->unk10--;
            if (self->bsvan->unk10 != 0)
            {
                func_8080164C_bsvan(self, 3);
            }
            else
            {
                func_8080164C_bsvan(self, 4);
            }
        }
        break;
    case 4:
        if (baanim_isStopped(self) != 0)
        {
            func_8080164C_bsvan(self, 5);
        }
        break;
    case 5:
        sp20 = yaw_get(self);
        if (yaw_getIdeal(self) == sp20)
        {
            if (func_8008E124(self) != 0)
            {
                nextState = 0x119;
            }
            else
            {
                nextState = 0x11A;
            }
        }
        break;
    }
    bsvan_entrypoint_3(self);
    bs_setState(self, nextState);
}

s32 bsvan_entrypoint_16(s32 arg0) {
    return D_80801D80_bsvan[arg0];
}
