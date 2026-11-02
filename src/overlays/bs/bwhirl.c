#include "bs/bwhirl.h"

extern u32 D_80800F50_bsbwhirl;
extern s32 D_80800F5C_bsbwhirl;
extern s32 D_80800F98_bsbwhirl[];
extern s32 D_80800FA8_bsbwhirl[];
extern s32 D_80800FB8_bsbwhirl[];
extern s32 D_80800FC8_bsbwhirl[];
extern s32 D_80800FD8_bsbwhirl[];
extern s32 D_80800FE8_bsbwhirl[];
extern s32 D_80800FF8_bsbwhirl[];

void func_80800000_bsbwhirl(PlayerState* self) {
    self->unk160.word = 0;
}

void func_80800008_bsbwhirl(PlayerState* self) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    if (func_800BF8E4() > 0) {
        if (self->unk160.word == 0)
        {
            self->unk160.word = func_800C8A98();
            func_800C8E54(self->unk160.word, 80.0f, 350.0f);
            func_800C8F64(self->unk160.word, 0xB);
            func_800C8E84(self->unk160.word, &D_80800F50_bsbwhirl);
        }
        sp24 = func_80092B8C(self, sp28);
        player_getCoords(self, sp34);
        ml_vec3f_add(&sp34, sp28);
        func_800EF1B8(&sp34, func_80092BE8(self), sp24);
        sp34[1] += sp24;
        func_800C8CB8(self->unk160.word, &sp34);
    }
}

void func_808000D8_bsbwhirl(PlayerState* self)
{
    if (self->unk160.word != 0)
    {
        self->unk160.word = _chlightfader_entrypoint_1(self->unk160.word, 0.25f, 2);
    }
}

void func_80800114_bsbwhirl(PlayerState* self) 
{
    f32 sp1C;

    sp1C = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) 
    {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp1C, 80.0f, 425.0f));
}

void func_8080017C_bsbwhirl(PlayerState* self)
{
    switch (bs_getNextState(self))
    {
        case BS_STATE_1B_WONDERWING_IDLE:
        case BS_STATE_1C_WONDERWING_WALK:
        case BS_STATE_1D_WONDERWING_JUMP:
        case BS_STATE_1E_WONDERWING_EXIT:
        case 0xA4:
        case 0xA5:
            break;
        default:
            bastick_resetZones(self);
            func_800A0CF4(self, 0);
            func_800FC74C(0xDU);
            func_808000D8_bsbwhirl(self);
            break;
    }
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
}

void func_80800200_bsbwhirl(PlayerState* self)
{
    f32 temp;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    s32 sp38;
    player_getCoords(self, sp3C);
    func_800EFCD8(sp60, yaw_get(self), 48.0f);
    sp60[1] = 0.0f;
    ml_vec3f_add(sp3C, sp60);
    sp38 = func_800B5BE4(0xE);
    func_800BABB8(sp38, sp3C, NULL, 1.0f, &D_80800F5C_bsbwhirl);
    func_8009BB24(self, sp60);
    func_800EFCD8(sp54, self->unk170, 250.0f);
    func_800EFCD8(sp48, self->unk170 + 45.0f, 250.0f);
    sp54[1] = 0.0f;
    sp48[1] = 0.0f;
    ml_vec3f_add(sp54, sp60);
    ml_vec3f_add(sp48, sp60);
    if (sp48[0] < sp54[0])
    {
        temp = sp48[0];
        sp48[0] = sp54[0];
        sp54[0] = temp;
    }
    if (sp48[2] < sp54[2])
    {
        temp = sp48[2];
        sp48[2] = sp54[2];
        sp54[2] = temp;
    }
    self->unk170 = func_800136E4(self->unk170 + 45.0f);
    func_800BA930((unkStruct800BA198*)sp38, sp54[0], 0xFA, sp54[2], sp48[0], 0xFA, sp48[2]);
    func_800BA22C(sp38, 2);
}

s32 func_808003A8_bsbwhirl(PlayerState* self, s32 arg1) 
{
    s32 var_s1;

    var_s1 = arg1;
    if (bastick_getZone(self) > 0) 
    {
        var_s1 = 0x1C;
    }
    if (bakey_released(self, BUTTON_Z) != 0) 
    {
        var_s1 = 0x1E;
    }
    if ((bakey_pressed(self, BUTTON_A) != 0) && (player_isStable(self) != 0))
    {
        var_s1 = 0x1D;
    }
    if (player_inWater(self) != 0) 
    {
        var_s1 = 0x2D;
    }
    return var_s1;
}

void func_80800430_bsbwhirl(PlayerState* self, BanjoStateId* arg1)
{
    self->unk16C += time_getDelta();
    if (self->unk16C > 2.0f) 
    {
        self->unk16C = 0.0f;
        _suinv_entrypoint_0(arg1, 0x1E, -1, 0x47, 1);
        if (*arg1 != 0x1E) 
        {
            func_8009DF18(self, 0x3E9, 0.8f, 0x6D60);
            _chusefeather_entrypoint_1(self->unk184, 1);
        }
    }
}

void bsbwhirl_entrypoint_0(PlayerState* self)
{
    baanim_playForDuration_once(self, 0x22, 0.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    bastick_setZoneMax(self, 0, 0.03f);
    bastick_setZoneMax(self, 1, 1.0f);
    func_800A0CF4(self, 1);
    self->unk170 = 0.0f;
    self->unk16C = 0.0f;
    func_800FC660(0xD);
    func_80800000_bsbwhirl(self);
    func_8009D874(self);
    bainput_enable(self, BA_INPUT_1_ROTATE_CAMERA_RIGHT, 0);
}

void bsbwhirl_entrypoint_1(PlayerState* self)
{
    BanjoStateId sp1C;

    sp1C = BS_STATE_0_INVALID;
    bainput_enable(self, BA_INPUT_1_ROTATE_CAMERA_RIGHT, 1);
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0)
    {
        sp1C = BS_STATE_1B_WONDERWING_IDLE;
    }
    func_80800008_bsbwhirl(self);
    bs_setState(self, sp1C);
}

void bsbwhirl_entrypoint_2(PlayerState* self)
{
    bainput_enable(self, BA_INPUT_1_ROTATE_CAMERA_RIGHT, 1);
    func_8080017C_bsbwhirl(self);
}

s32 bsbwhirl_entrypoint_3(s32 arg0)
{
    return D_80800F98_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_4(PlayerState* self) {
    baanim_playForDuration_loopSmooth(self, 0x23, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void bsbwhirl_entrypoint_5(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800200_bsbwhirl(self);
    nextState = func_808003A8_bsbwhirl(self, nextState);
    func_80800430_bsbwhirl(self, &nextState);
    func_80800008_bsbwhirl(self);
    if (func_8008E148(self) != 0) {
        nextState = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self) != 0) {
        nextState = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, nextState);
}

void bsbwhirl_entrypoint_6(PlayerState* self)
{
    func_8080017C_bsbwhirl(self);
}

s32 bsbwhirl_entrypoint_7(s32 arg0) {
    return D_80800FA8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_8(PlayerState* self) {
    baanim_playForDuration_loopSmooth(self, 0x11, 0.53f);
    func_8008C9F0(self, 80.0f, 425.0f, 0.56f, 0.4f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
}

void bsbwhirl_entrypoint_9(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_80800200_bsbwhirl(self);
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    func_80800114_bsbwhirl(self);
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (func_8009BCD4(self, 1.0f) != 0)) {
        nextState = BS_STATE_1B_WONDERWING_IDLE;
    }
    if (bakey_released(self, BUTTON_Z) != 0) {
        nextState = BS_STATE_1E_WONDERWING_EXIT;
    }
    if ((bakey_pressed(self, BUTTON_A) != 0) && (player_isStable(self) != 0)) {
        nextState = BS_STATE_1D_WONDERWING_JUMP;
    }
    if (player_inWater(self) != 0) {
        nextState = BS_STATE_4C_LANDING_IN_WATER;
    }
    func_80800430_bsbwhirl(self, &nextState);
    func_80800008_bsbwhirl(self);
    if (func_8008E148(self) != 0) {
        nextState = _badrone_entrypoint_25(self);
    }
    bs_setState(self, nextState);
}

void bsbwhirl_entrypoint_10(PlayerState* self)
{
    func_8080017C_bsbwhirl(self);
}

s32 bsbwhirl_entrypoint_11(s32 arg0) {
    return D_80800FB8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_12(PlayerState* self) {
    s32 pad[2];
    f32 sp2C;
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x1B);
    anctrl_setDuration(temp_v0, 0.8f);
    func_8008B1C8(temp_v0, 0.134f);
    anctrl_setStart(temp_v0, 0.14f);
    anctrl_setSubrange(temp_v0, 0.0f, 0.4495f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800114_bsbwhirl(self);
    sp2C = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, sp2C, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 693.5f);
    baphysics_set_gravity(self, -1200.0f);
    func_8009D7A4(self, 0.91f, 1.09f);
    self->unk15C.word = 0;
}

void bsbwhirl_entrypoint_13(PlayerState* self) {
    BanjoStateId nextState;
    AnimCtrl* sp30;
    f32 BanjoStateId[3];

    nextState = BS_STATE_0_INVALID;
    sp30 = baanim_getAnimCtrlPtr(self);
    func_80800200_bsbwhirl(self);
    func_80800114_bsbwhirl(self);
    func_8009BB24(self, BanjoStateId);
    if ((bakey_released(self, BUTTON_A) != 0) && (BanjoStateId[1] > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    switch (self->unk15C.word)
    {
    case 0:
        if (func_8008DF8C(self, 0x82) != 0)
        {
            anctrl_setSubrange(sp30, 0.0f, 1.0f);
            anctrl_setDuration(sp30, 0.8f);
            anctrl_setPlaybackType(sp30, 1);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_inWater(self) != 0)
        {
            nextState = BS_STATE_2D_SWIM_IDLE;
        }
        if (player_isStable(self) != 0)
        {
            self->unk15C.word = 2;
            func_8009FE58(self);
        }
        break;
    case 2:
        if (anctrl_isStopped(sp30) != 0)
        {
            nextState = BS_STATE_1B_WONDERWING_IDLE;
        }
        nextState = func_808003A8_bsbwhirl(self, nextState);
        break;
    }
    func_80800430_bsbwhirl(self, &nextState);
    func_80800008_bsbwhirl(self);
    if (player_canGripGrab(self) != 0)
    {
        nextState = BS_STATE_A8_GRIP_GRAB_START;
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, nextState);
}

void bsbwhirl_entrypoint_14(PlayerState* self)
{
    baphysics_reset_gravity(self);
    func_8080017C_bsbwhirl(self);
}

s32 bsbwhirl_entrypoint_15(s32 arg0) {
    return D_80800FC8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_16(PlayerState* self) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    func_8008B188(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x22);
    anctrl_setDuration(temp_v0, 0.5f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    func_8009D2D8(self, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800FCAE0(0xDU, 0U, 0xFA0U);
}

void bsbwhirl_entrypoint_17(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self)) != 0) {
        nextState = BS_STATE_1_IDLE;
    }
    func_80800008_bsbwhirl(self);
    bs_setState(self, nextState);
}

void bsbwhirl_entrypoint_18(PlayerState* self)
{
    func_8080017C_bsbwhirl(self);
}

s32 bsbwhirl_entrypoint_19(s32 arg0) {
    return D_80800FD8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_20(PlayerState* self)
{
    _bsdrone_entrypoint_0(self);
}

void bsbwhirl_entrypoint_21(PlayerState* self)
{
    func_80800200_bsbwhirl(self);
    func_80800008_bsbwhirl(self);
    _bsdrone_entrypoint_1(self);
}

void bsbwhirl_entrypoint_22(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_8080017C_bsbwhirl(self);
}

s32 bsbwhirl_entrypoint_23(s32 arg0) {
    return D_80800FE8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_24(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_8080017C_bsbwhirl(self);
}

void bsbwhirl_entrypoint_25(PlayerState* self)
{
    _bsrest_entrypoint_16(self);
}

void bsbwhirl_entrypoint_26(PlayerState* self) {
    BanjoStateId BanjoStateId;

    BanjoStateId = 0;
    func_80800200_bsbwhirl(self);
    func_80800008_bsbwhirl(self);
    if (_bsrest_entrypoint_20(self) != 0) {
        BanjoStateId = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, BanjoStateId);
}

s32 bsbwhirl_entrypoint_27(s32 arg0) {
    return D_80800FF8_bsbwhirl[arg0];
}

void func_80800EA0_bsbwhirl(PlayerState* self, s32(*arg1)(PlayerState*))
{
    s16 temp_v0;

    switch (func_8009E6EC(self))
    {
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x4E:
    case 0x51:
    case 0x52:
        func_8009E830(self, 1);
        return;
    }
    arg1(self);
}

void bsbwhirl_entrypoint_28(PlayerState* self)
{
    func_80800EA0_bsbwhirl(self, func_80099B94);
}