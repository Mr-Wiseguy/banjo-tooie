#include "bs/ban/shack.h"

extern s32 D_80800CB0_bsbanshack[];
extern s32 D_80800CC0_bsbanshack[];
extern s32 D_80800CD0_bsbanshack[];
extern s32 D_80800CE0_bsbanshack[];
extern s32 D_80800CF0_bsbanshack[];
extern s32 D_80800D00_bsbanshack[];
extern s32 D_80800D10_bsbanshack[];

BanjoStateId func_80800000_bsbanshack(PlayerState* self, BanjoStateId arg1)
{
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = BS_STATE_16E_SHACK_PACK_JUMP;
    }
    if (func_8008E148(self) != 0)
    {
        arg1 = BS_STATE_1_IDLE;
    }
    if (func_8008E260(self) != 0)
    {
        arg1 = BS_STATE_3D_FALL_TUMBLING;
    }
    if (bakey_released(self, BUTTON_Z) != 0)
    {
        arg1 = BS_STATE_16B_SHACK_PACK_EXIT;
    }
    return arg1;
}

BanjoStateId func_80800074_bsbanshack(PlayerState* self, BanjoStateId arg1)
{
    arg1 = arg1;
    if (bastick_getZone(self) > 0)
    {
        arg1 = BS_STATE_16D_SHACK_PACK_WALK;
    }
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = BS_STATE_16E_SHACK_PACK_JUMP;
    }
    if (func_8008E148(self) != 0)
    {
        arg1 = BS_STATE_1_IDLE;
    }
    if (func_8008E260(self) != 0)
    {
        arg1 = BS_STATE_3D_FALL_TUMBLING;
    }
    if (bakey_released(self, BUTTON_Z) != 0)
    {
        arg1 = BS_STATE_16B_SHACK_PACK_EXIT;
    }
    return arg1;
}

void func_80800100_bsbanshack(PlayerState* self)
{
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0)
    {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 30.0f, 300.0f));
}

void func_80800164_bsbanshack(PlayerState* self)
{
    if (func_8009E74C(self, 0x13) != 0)
    {
        if (_babackpack_get_state(self) != 5)
        {
            _babackpack_set_state(self, 5);
        }
    }
    else
    {
        if (_babackpack_get_state(self) != 1)
        {
            _babackpack_set_state(self, 1);
        }
        func_800A0CD0(self, 1);
        if (bs_getCurrentState(self) != 0x16B)
        {
            baanim_playForDuration_once(self, 0x6F, 5.5f);
            func_8008CA98(self);
        }
        func_80095A40(self);
        bastick_popZone(self);
    }
}

void func_8080021C_bsbanshack(PlayerState* self) {
    if (func_8009E77C(self, 0x13) == 0) {
        _babackpack_set_state(self, 5);
        func_800A0CD0(self, 0);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800959C8(self, 53.0f, 25.0f);
        func_8009590C(self, 53.0f);
    }
}

void func_808002AC_bsbanshack(PlayerState* self) {
    if (self->unk15C.bytes[1] != 0) {
        func_80800164_bsbanshack(self);
        return;
    }
    if (_babackpack_get_state(self) != 1) {
        func_800A0CD0(self, 1);
        _babackpack_set_state(self, 1);
    }
}

void func_8080030C_bsbanshack(PlayerState* self) {
    self->unk15C.bytes[1] = 0;
    baanim_playForDuration_onceSmooth(self, 0x145, 1.4f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    bainput_enable(self, BA_INPUT_5_EXIT_FIRST_PERSON, 0);
}

void func_8080037C_bsbanshack(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    bainput_enable(self, BA_INPUT_5_EXIT_FIRST_PERSON, 1);
    if (baanim_isAt(self, 0.31f) != 0) {
        func_8009DBF0(self, 0x3FF, 0.9f);
    }
    if (baanim_isAt(self, 0.1976f) != 0) {
        self->unk15C.bytes[1] = 1;
        func_8080021C_bsbanshack(self);
    }
    if (baanim_isStopped(self) != 0) {
        nextState = BS_STATE_16C_SHACK_PACK_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanshack_entrypoint_0(s32 arg0) {
    return D_80800CB0_bsbanshack[arg0];
}

void func_80800430_bsbanshack(PlayerState* self)
{
    func_80800164_bsbanshack(self);
}

void func_80800450_bsbanshack(PlayerState* self) {
    func_8080021C_bsbanshack(self);
    baanim_playForDuration_onceSmooth(self, 0x295, 1.4f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void func_808004AC_bsbanshack(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp28;

    nextState = BS_STATE_0_INVALID;
    sp28 = baanim_getAnimCtrlPtr(self);
    if (anctrl_isAt(sp28, 0.29f) != 0) {
        func_8009DEC0(self, 0x583, 0.95f, 1.05f, 0x55F0, 0x55F0);
    }
    if (anctrl_isAt(sp28, 0.74f) != 0) {
        func_8009DEC0(self, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(self, 0.1351f) != 0) {
        baphysics_set_vertical_velocity(self, 600.0f);
    }
    if (baanim_isAt(self, 0.6757f) != 0) {
        _babackpack_set_state(self, 1);
        func_800A0CD0(self, 1);
    }
    if (baanim_isStopped(self) != 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanshack_entrypoint_1(s32 arg0) {
    return D_80800CC0_bsbanshack[arg0];
}

void func_808005DC_bsbanshack(PlayerState* self, s32 arg1) 
{
    AnimCtrl* temp_s0;

    switch (arg1) 
    {
    case 0:
        baphysics_reset_gravity(self);
        break;
    case 1:
        temp_s0 = baanim_getAnimCtrlPtr(self);
        self->unk160.word = 0;
        anctrl_reset(temp_s0);
        anctrl_setIndex(temp_s0, 0x294);
        anctrl_setDuration(temp_s0, 1.0f);
        func_8008B1C8(temp_s0, 0.134f);
        anctrl_setStart(temp_s0, 0.14f);
        anctrl_setSubrange(temp_s0, 0.0f, 0.7f);
        anctrl_setPlaybackType(temp_s0, 1);
        anctrl_start(temp_s0);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
        baphysics_set_vertical_velocity(self, 610.0f);
        baphysics_set_gravity(self, -1000.0f);
        func_8009DF18(self, 0x589, 1.0f, 0x3A98);
        break;
    case 2:
        baanim_setEndAndDuration(self, 0.81f, 3.2f);
        break;
    case 3:
        baanim_setEndAndDuration(self, 1.0f, 0.8f);
        break;
    }
    self->unk15C.bytes[0] = (u8)arg1;
}

void func_80800744_bsbanshack(PlayerState* self)
{
    func_808005DC_bsbanshack(self,0);
    func_80800164_bsbanshack(self);
}

void func_80800770_bsbanshack(PlayerState* self) {
    func_8080021C_bsbanshack(self);
    self->unk15C.bytes[0] = 0;
    func_808005DC_bsbanshack(self, 1);
}

void func_808007A0_bsbanshack(PlayerState* self)
{
    BanjoStateId nextState;
    nextState = BS_STATE_0_INVALID;
    if ((bakey_released(self, BUTTON_A) != 0) && (baphysics_get_vertical_velocity(self) > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.bytes[0])
    {
    case 1:
        func_80800100_bsbanshack(self);
        if (baanim_isStopped(self) != 0) {
            func_808005DC_bsbanshack(self, 2);
        }
        if (func_8008DF8C(self, 0x5A) != 0) {
            func_808005DC_bsbanshack(self, 3);
        }
        break;
    case 2:
        func_80800100_bsbanshack(self);
        if (func_8008DF8C(self, 0x5A) != 0) {
            func_808005DC_bsbanshack(self, 3);
        }
        break;
    case 3:
        if (player_isStable(self) != 0) {
            if (self->unk160.word == 0)
            {
                self->unk160.word = self->unk160.word + 1;
                func_8009FE58(self);
            }
            if (baanim_isStopped(self) != 0) {
                nextState = 0x16C;
            }
            nextState = func_80800074_bsbanshack(self, nextState);
            if (nextState == BS_STATE_0_INVALID)
            {
                baphysics_set_target_horizontal_velocity(self, 0.0f);
            }
        }
        break;
    }
    if (func_8008E260(self) != 0)
    {
        nextState = BS_STATE_3D_FALL_TUMBLING;
    }
    bs_setState(self, nextState);
}

s32 bsbanshack_entrypoint_2(s32 arg0) {
    return D_80800CD0_bsbanshack[arg0];
}

void func_80800928_bsbanshack(PlayerState* self)
{
    func_80800164_bsbanshack(self);
}

void func_80800948_bsbanshack(PlayerState* self)
{
    func_8080021C_bsbanshack(self);
    baanim_playForDuration_loopSmooth(self, 0x146, 0.7f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baanim_setDurationRange(self, 0.1f, 5.0f);
    func_8008C9F0(self, 30.0f, 300.0f, 0.8f, 0.5f);
    func_8008CA30(self, 1.0f);
}

void func_808009E4_bsbanshack(PlayerState* self)
{
    BanjoStateId sp24;

    sp24 = BS_STATE_0_INVALID;
    func_80800100_bsbanshack(self);
    func_800A2CE8(self, 0.25f, 4);
    func_800A2CE8(self, 0.75f, 3);
    if (baanim_isAt(self, 0.51f) != 0)
    {
        func_8009DF18(self, rand_f() < 0.5f ? 0x58A : 0x58B, 1.0f, 0x1388);
    }
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (func_8009BCD4(self, 3.0f) != 0))
    {
        sp24 = BS_STATE_16C_SHACK_PACK_IDLE;
    }
    bs_setState(self, func_80800000_bsbanshack(self, sp24));
}

s32 bsbanshack_entrypoint_3(s32 arg0) {
    return D_80800CE0_bsbanshack[arg0];
}

void func_80800AD0_bsbanshack(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_80800164_bsbanshack(self);
}
void func_80800AF8_bsbanshack(PlayerState* self)
{
    func_8080021C_bsbanshack(self);
    _bsdrone_entrypoint_0(self);
}
void func_80800B20_bsbanshack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}

s32 bsbanshack_entrypoint_4(s32 arg0) {
    return D_80800CF0_bsbanshack[arg0];
}

void func_80800B54_bsbanshack(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_80800164_bsbanshack(self);
}
void func_80800B7C_bsbanshack(PlayerState* self)
{
    func_8080021C_bsbanshack(self);
    _bsrest_entrypoint_16(self);
}
void func_80800BA4_bsbanshack(PlayerState* self)
{
    BanjoStateId nextState;
    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0)
    {
        nextState = BS_STATE_16C_SHACK_PACK_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbanshack_entrypoint_5(s32 arg0)
{
    return D_80800D00_bsbanshack[arg0];
}

void func_80800BF0_bsbanshack(PlayerState* self)
{
    func_80800164_bsbanshack(self);
}

void func_80800C10_bsbanshack(PlayerState* self)
{
    func_8080021C_bsbanshack(self);
    baanim_playForDuration_loopSmooth(self, 0x293, 5.4f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void func_80800C6C_bsbanshack(PlayerState* self)
{
    bs_setState(self, func_80800074_bsbanshack(self, 0));
}

s32 bsbanshack_entrypoint_6(s32 arg0)
{
    return D_80800D10_bsbanshack[arg0];
}
