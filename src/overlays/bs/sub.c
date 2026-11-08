#include "bs/sub.h"

extern s32 D_808016E0_bssub;
extern s32 D_8080172C_bssub;
extern s32 D_80801748_bssub;
extern s32 D_80801774_bssub;
extern s32 D_808017A0_bssub;
extern s32 D_808017CC_bssub;
extern s32 D_80801840_bssub;

s32 D_80801890_bssub[];
s32 D_808018A0_bssub[];
s32 D_808018B0_bssub[];
s32 D_808018C0_bssub[];
s32 D_808018D0_bssub[];
s32 D_808018E0_bssub[];
s32 D_808018F0_bssub[];
s32 D_80801900_bssub[];


void func_80800C60_bssub(PlayerState*);

void func_80800000_bssub(PlayerState* self) {
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 3, 0xF);
}

f32 func_80800030_bssub(f32 self, f32 arg1) {
    return arg1 * 300.0f;
}

f32 func_80800048_bssub(f32 self, f32 arg1) {
    return -arg1 * 428.57144f;
}

void func_80800064_bssub(PlayerState* self) {

    switch (func_8009E6EC(self))
    {


    case 0x85:
        _basub_entrypoint_15(self, func_80099A58(self));
        break;

    case 0x2D:
        func_800995B8(self, 3);
        func_8009E830(self, 2);
        bs_setState(self, 0x46);
        break;
    default:
        func_80099B94(self);
        break;
    }
}

void func_808000F0_bssub(PlayerState* self) {
    f32 var_f22;
    f32 sp48;
    f32 temp_f0;
    f32 temp_f20;

    temp_f20 = ml_map_f(baphysics_get_velocity(self), 0.0f, 225.0f, 0.0f, 1.0f);
    if (player_inWater(self) != 0)
    {
        var_f22 = ml_mapNormal_f(temp_f20, 50.0f, 150.0f);
        sp48 = ml_mapNormal_f(temp_f20, 0.5f, 2.0f);
        baroll_setAngularVelocity(self, ml_mapNormal_f(temp_f20, 40.0f, 150.0f), ml_mapNormal_f(temp_f20, 0.6f, 3.0f));
        yaw_setVelocityBounded(self, 250.0f, 20.0f);
    }
    else
    {
        var_f22 = 250.0f;
        sp48 = 2.8f;
        baroll_setAngularVelocity(self, 250, 2.8f);
        yaw_setVelocityBounded(self, 300.0f, 3.0f);
    }
    temp_f0 = _bafpctrl_entrypoint_3(self);
    var_f22 *= ml_map_f(temp_f0, 0.1f, 1.0f, SQ(temp_f0), 1.0f);
    func_8009BFE4(self, var_f22, sp48);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800254_bssub.s")

void func_80800634_bssub(PlayerState* self) {
    f32 sp3C;
    s32 pad[2];
    f32 sp30;
    f32 sp2C;
    f32 temp_f0;
    f32 var_f2;

    sp2C = bastick_getX(self);
    sp30 = time_getDelta();
    temp_f0 = ml_map_f(baphysics_get_velocity(self), 0.0f, 225.0f, 11.25f, 45.0f);
    baroll_setIdeal(self, ml_map_f(sp2C, -1.0f, 1.0f, -temp_f0, temp_f0));
    if (player_inWater(self) != 0)
    {
        var_f2 = ml_map_f(baphysics_get_velocity(self), 0.0f, 225.0f, 42.666668f, 128.0f);
    }
    else
    {
        var_f2 = 300.0f;
    }
    sp3C = ml_map_f(sp2C, -1.0f, 1.0f, var_f2, -var_f2) * sp30;
    sp3C *= _bafpctrl_entrypoint_3(self);
    yaw_setIdeal(self, yaw_getIdeal(self) + sp3C);
}

void func_80800768_bssub(PlayerState* self) {
    s32 pad;

    f32 sp28;
    f32 sp24;
    f32 temp_f0;
    if (player_inWater(self) != 0) {
        sp28 = 275.0f;
        sp24 = 85.0f;
    }
    else {
        sp28 = 325.0f;
        sp24 = 30.0f;
    }
    temp_f0 = bastick_getY(self);
    if (temp_f0 < 0.0f) {
        func_8009BF5C(self, ml_map_f(temp_f0, -1.0f, 0.0f, sp28, 360.0f));
        return;
    }
    func_8009BF5C(self, ml_map_f(temp_f0, 0.0f, 1.0f, 0.0f, sp24));
}

void func_80800834_bssub(PlayerState* self) {
    if (bakey_pressed(self, BUTTON_L) != 0) {
        _basub_entrypoint_1(self);
    }
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        _basub_entrypoint_8(self, baphysics_get_velocity(self));
    }
    if (bakey_pressed(self, BUTTON_B) != 0) {
        if (func_800EA068(0x40) != 0) {
            _basub_entrypoint_3(self, 160, 1.0f);
            return;
        }
        _basub_entrypoint_5(self);
    }
}

void func_808008D8_bssub(PlayerState* self) {
    if (func_8009E74C(self, 0xF) == 0) {
        func_800947EC(self, 1, 0);
        func_800961AC(self, 1);
        func_8009BC34(self);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        func_8009C000(self);
        baroll_resetAngularVelocity(self);
        bastick_resetZones(self);
        func_80095A40(self);
        func_80095964(self, 0);
        func_80093360(self, 0.0f);
        _basub_entrypoint_9(self);
        func_800910BC(self, 1);
        _bafpctrl_entrypoint_18(self, 0);
        func_8009E474(self);
        func_80092864(self, 1.0f);
    }
}

void func_808009B0_bssub(PlayerState* self)
{
    if (func_8009E77C(self, 0xF) == 0)
    {
        _basub_entrypoint_10(self);
        self->unk16C = 0.0f;
        self->unk170 = 0.0f;
        baphysics_set_gravity(self, 0);
        baphysics_set_terminal_velocity(self, -399.99f);
        func_800961AC(self, 9);
        func_80095964(self, 1);
        func_8009BC5C(self, 2.0f);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800959C8(self, 90.0f, 70.0f);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 70.0f);
        func_8009E55C(self, 1, 0.0f);
        func_8009E55C(self, 2, 0.0f);
        func_80093360(self, 55.0f);
        func_800910BC(self, 4);
        func_808000F0_bssub(self);
        _bafpctrl_entrypoint_18(self, 1);
        func_800947EC(self, 1, 1);
        func_80092864(self, 2.0f);
    }
}

void func_80800AEC_bssub(PlayerState* self)
{
    _basub_entrypoint_14(self);
}

void func_80800B0C_bssub(PlayerState* self)
{
    _baspin_entrypoint_1(self);
}

void func_80800B2C_bssub(PlayerState* self)
{
    baanim_playForDuration_loopSmooth(self, 0x12E, 6.0f);
    func_80800000_bssub(self);
    _bamovethrust_entrypoint_3(self, 0.0f);
    _bamovethrust_entrypoint_4(self, 0.9f);
    _basub_entrypoint_11(self, 0.6f);
    _basub_entrypoint_13(self, 1.0f);
    _baspin_entrypoint_2(self, 0x130, 1.8f, 3, 1);
    _batimer_set(self, 9, 1.8f);
    func_800FC660(0x19);
}

void func_80800BD8_bssub(PlayerState* self) {
    _baspin_entrypoint_3(self);
    if (_batimer_decrement(self, 9) != 0) {
        event_sendToActorsOfType(0x2C4, 0x71, self->unk184);
    }
}

void func_80800C1C_bssub(PlayerState* self) {
    if (self->unk15C.word != 0) {
        func_80800B0C_bssub(self);
    }
    else {
        _basudie_entrypoint_8(self);
    }
    func_808008D8_bssub(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800C60_bssub.s")

void func_80800E34_bssub(PlayerState* self)
{
    func_808009B0_bssub(self);
    self->unk15C.word = func_800EA068(0x40);
    if (self->unk15C.word != 0)
    {
        func_80800B2C_bssub(self);
        return;
    }
    _bafpctrl_entrypoint_19(self);
    _basudie_entrypoint_9(self, 30.0f);
    func_80800C60_bssub(self);
}

void func_80800E98_bssub(PlayerState* self)
{
    func_80800AEC_bssub(self);
    if (self->unk15C.word != 0)
    {
        func_80800BD8_bssub(self);
        return;
    }
    _basudie_entrypoint_10(self);
}

void func_80800EE0_bssub(PlayerState* self)
{
    if (func_8009E6EC(self) == 0x83)
    {
        func_8009BDAC(self, func_80099A34(self));
        func_80093370(self, 1);
        bs_setState(self, 0x131);
        func_8009E830(self, 2);
        return;
    }
    _basudie_entrypoint_11(self);
}

s32 bssub_entrypoint_0(s32 arg0) {
    return D_80801890_bssub[arg0];
}

void func_80800F70_bssub(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_808008D8_bssub(self);
}

void func_80800F98_bssub(PlayerState* self)
{
    func_808009B0_bssub(self);
    _bsdrone_entrypoint_0(self);
}

void func_80800FC0_bssub(PlayerState* self)
{
    func_80800AEC_bssub(self);
    func_80800254_bssub(self);
    _bsdrone_entrypoint_1(self);
}

s32 bssub_entrypoint_1(s32 arg0) {
    return D_808018A0_bssub[arg0];
}

void func_80801004_bssub(PlayerState* self)
{
    func_80090A2C(self);
    func_808008D8_bssub(self);
}

void func_8080102C_bssub(PlayerState* self) {
    AnimCtrl* sp2C;
    AssetId sp28;

    sp2C = baanim_getAnimCtrlPtr(self);
    sp28 = anctrl_getIndex(sp2C);
    func_8008CA4C(self, BAANIM_UPDATE_2_SCALE_HORZ);
    if (baphysics_get_velocity(self) < 300.0f)
    {
        if (sp28 != 0x12E)
        {
            baanim_playForDuration_loopSmooth(self, 0x12E, 6.0f);
            func_8008B1C8(sp2C, 0.4f);
        }
        func_8008C9F0(self, 0.0f, 900.0f, 6.0f, 6.0f);
        return;
    }
    if (sp28 != 0x12F)
    {
        baanim_playForDuration_loopSmooth(self, 0x12F, 0.45f);
        func_8008B1C8(sp2C, 0.4f);
    }
    func_8008C9F0(self, 0.0f, 900.0f, 1.5f, 0.45f);
}

void func_80801130_bssub(PlayerState* self)
{
    func_808009B0_bssub(self);
    func_8080102C_bssub(self);
    baanim_setDurationRange(self, 0.3f, 10.0f);
    func_8008CA30(self, 1.0f);
    func_800909CC(self);
}

void func_80801188_bssub(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800AEC_bssub(self);
    func_8080102C_bssub(self);
    func_80800634_bssub(self);
    func_80800768_bssub(self);
    func_80800254_bssub(self);
    func_80800834_bssub(self);
    if (self->unk16C == 0.0f) {
        nextState = 0x131;
    }
    bs_setState(self, nextState);
}

s32 bssub_entrypoint_2(s32 arg0) {
    return D_808018B0_bssub[arg0];
}

void func_8080121C_bssub(PlayerState* self)
{
    _baspin_entrypoint_1(self);
    func_808008D8_bssub(self);
}

void func_80801244_bssub(PlayerState* self) {
    func_808009B0_bssub(self);
    _baspin_entrypoint_2(self, 0x130, 1.8f, 3, 1);
}

void func_80801284_bssub(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800AEC_bssub(self);
    func_800914FC(self, 40.0f, 0);
    if (_baspin_entrypoint_3(self) == 2) {
        nextState = 0x131;
    }
    bs_setState(self, nextState);
}

s32 bssub_entrypoint_3(s32 arg0) {
    return D_808018C0_bssub[arg0];
}

void func_808012F0_bssub(PlayerState* self)
{
    _baspin_entrypoint_1(self);
    func_808008D8_bssub(self);
}

void func_80801318_bssub(PlayerState* self) {
    func_808009B0_bssub(self);
    _baspin_entrypoint_2(self, 0x130, 1.8f, 3, 1);
}

void func_80801358_bssub(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800AEC_bssub(self);
    func_800914FC(self, 40.0f, 0);
    if (_baspin_entrypoint_3(self) == 2) {
        nextState = 0x131;
    }
    bs_setState(self, nextState);
}

s32 bssub_entrypoint_4(s32 arg0) {
    return D_808018D0_bssub[arg0];
}

void func_808013C4_bssub(PlayerState* self)
{
    _babounce_entrypoint_3(self);
    func_808008D8_bssub(self);
}

void func_808013EC_bssub(PlayerState* self) {
    func_808009B0_bssub(self);
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0x12E, 6.0f);
}

void func_80801428_bssub(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800AEC_bssub(self);
    func_800914FC(self, 40.0f, 0);
    if (_babounce_entrypoint_9(self) != 0) {
        nextState = 0x131;
    }
    bs_setState(self, nextState);
}

s32 bssub_entrypoint_5(s32 arg0) {
    return D_808018E0_bssub[arg0];
}

void func_80801490_bssub(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_808008D8_bssub(self);
}
void func_808014B8_bssub(PlayerState* self) {
    func_808009B0_bssub(self);
    func_8009BF5C(self, 0.0f);
    _bsrest_entrypoint_16(self);
    func_8009B94C(self, NULL);
    func_8009BA9C(self, NULL);
    self->unk16C = 0.0f;
}

void func_80801518_bssub(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800AEC_bssub(self);
    if (_bsrest_entrypoint_20(self) != 0) {
        nextState = _badata_entrypoint_34(self);
    }
    bs_setState(self, nextState);
}

s32 bssub_entrypoint_6(s32 arg0) {
    return D_808018F0_bssub[arg0];
}

void func_80801578_bssub(PlayerState* self)
{
    func_80090A2C(self);
    func_808008D8_bssub(self);
}

void func_808015A0_bssub(PlayerState* self) {
    AnimCtrl* sp24;

    sp24 = baanim_getAnimCtrlPtr(self);
    func_808009B0_bssub(self);
    if (anctrl_getIndex(sp24) == 0x12E) {
        anctrl_setDuration(sp24, 6.0f);
    }
    else {
        baanim_playForDuration_loopSmooth(self, 0x12E, 6.0f);
    }
    func_800909CC(self);
    func_80800000_bssub(self);
}

void func_80801618_bssub(PlayerState* self) {
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    func_80800AEC_bssub(self);
    func_80800634_bssub(self);
    func_80800768_bssub(self);
    func_80800254_bssub(self);
    func_80800834_bssub(self);
    if (self->unk16C != 0.0f) {
        sp24 = 0x12C;
    }
    bs_setState(self, sp24);
}

s32 bssub_entrypoint_7(s32 arg0) {
    return D_80801900_bssub[arg0];
}
