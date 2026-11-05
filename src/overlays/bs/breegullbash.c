#include "bs/breegullbash.h"

extern s32 D_80800560_bsbreegullbash[];

void func_80800000_bsbreegullbash(PlayerState* self, f32 arg1, f32 arg2, f32 arg3) {
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    _babackpack_entrypoint_5(self, sp20, 2);
    sp20[1] -= 20.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = arg3;
    _badust_entrypoint_2(self, sp20, sp2C, 0.1f, 0.8f, 0.7f);
}

void func_808000A4_bsbreegullbash(PlayerState* self)
{
    f32 var_f20;
    var_f20 = 0.0f;
    while (var_f20 < 359.0f)
    {
        func_80800000_bsbreegullbash(self, var_f20, 730.0f, 100.0f);
        var_f20 += 60.0f;
    }
    var_f20 = 0.0f;
    while (var_f20 < 359.0f)
    {
        func_80800000_bsbreegullbash(self, ml_normalizeAngle_f(var_f20 + 30.0f), 430.0f, 40.0f);
        var_f20 += 60.0f;
    }
}

void func_808001B4_bsbreegullbash(PlayerState* self)
{
    _babackpack_set_state(self, 0x7);
}

void func_808001D4_bsbreegullbash(PlayerState* self)
{
    if (_babackpack_get_state(self) != 1)
    {
        _babackpack_set_state(self, 1);
        func_8009E4E0(self, 2, NULL);
        func_8009E55C(self, 2, 0.0f);
    }
}

void bsbreegullbash_entrypoint_0(PlayerState* self) {
    func_8009E474(self);
    func_808001D4_bsbreegullbash(self);
    baflag_clear(self, 0x3E);
}

void bsbreegullbash_entrypoint_1(PlayerState* self) {
    baanim_playForDuration_onceSmooth(self, 0x20, 1.75f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_8009E4AC(self);
    func_8009E4E0(self, 2, NULL);
    func_8009E55C(self, 2, 0.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

void bsbreegullbash_entrypoint_2(PlayerState* self) {
    enum bs_state_e sp2C;

    sp2C = BS_STATE_0_INVALID;
    if ((baanim_isAt(self, 0.22f) != 0) && (_babackpack_get_state(self) == 7)) {
        baflag_set(self, 0x3E);
        func_8009E55C(self, 2, 60.0f);
        func_8009E4E0(self, 2, _babackpack_entrypoint_5);
        func_8009E5A4(self, 2, 2);
    }
    if (baanim_isAt(self, 0.1188f) != 0) {
        func_808001B4_bsbreegullbash(self);
    }
    if (baanim_isAt(self, 0.21f) != 0) {
        func_8009DFD4(self, 0x4595, 1.0f, 1.1f, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(self, 0.36f) != 0) {
        func_8009DB04(self, 0x416, 1.0f, 0x55F0);
    }
    if (baanim_isAt(self, 0.37f) != 0) {
        func_8009DFD4(self, 0x4596, 1.0f, 1.1f, 0x7FFF, 0x7FFF);
    }
    if (baanim_isAt(self, 0.6714f) != 0) {
        func_8009DF18(self, 0x3EA, 1.0f, 0x55F0);
    }
    if (baanim_isAt(self, 0.335f) != 0) {
        _bashake_entrypoint_0(self, 3, 2);
        func_8009E55C(self, 2, 180.0f);
        func_808000A4_bsbreegullbash(self);
    }
    if (baanim_isAt(self, 0.38f) != 0) {
        func_8009E55C(self, 2, 0.0f);
        baflag_clear(self, 0x3E);
    }
    if (baanim_isAt(self, 0.8911f) != 0) {
        func_808001D4_bsbreegullbash(self);
    }
    if (baanim_isStopped(self) != 0) {
        sp2C = BS_STATE_1_IDLE;
    }
    if (player_inWater(self) != 0) {
        sp2C = BS_STATE_4C_LANDING_IN_WATER;
    }
    bs_setState(self, sp2C);
}

s32 bsbreegullbash_entrypoint_3(s32 arg0) {
    return D_80800560_bsbreegullbash[arg0];
}
