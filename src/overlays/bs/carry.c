#include "bs/carry.h"

extern s32 D_808007B0_bscarry[];
extern s32 D_808007C0_bscarry[];
extern s32 D_808007D0_bscarry[];
extern s32 D_808007E0_bscarry[];
extern s32 D_808007F0_bscarry[];

void func_80800000_bscarry(PlayerState* self)
{
    switch (func_8009E6EC(self))
    {
    case 8:
        func_8009E830(self, 2);
        bs_setState(self, 0x3C);
        return;
    case 18:
        func_8008F6B8(self, func_8008E9AC(self));
        return;
    case 22:
        if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_1_THROW) != 0)
        {
            bs_setState(self, 0x5B);
            func_8009E830(self, 2);
            return;
        }
        func_8009E830(self, 1);
        return;
    default:
        func_80099B94(self);
        return;
    }
}

void func_808000D0_bscarry(PlayerState* self)
{
    switch (func_8009E6EC(self))
    {
    case 8:
    case 0x12:
    case 0x16:
        func_80800000_bscarry(self);
        return;
    }
    _bsdrone_entrypoint_3(self);
}

void func_80800128_bscarry(PlayerState* self) {
    f32 sp24;
    sp24 = bastick_getZonePosition(self);
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    case BS_STICK_ZONE_ID_1:
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 30.0f, 60.0f));
        return;
    case BS_STICK_ZONE_ID_2:
        baphysics_set_target_horizontal_velocity(self, ml_mapNormal_f(sp24, 60.0f, 300.0f));
        return;
    }
}

void func_808001D4_bscarry(PlayerState* self)
{
    if (func_8009E69C(self, 0x400) == 0)
    {
        bastick_popZone(self);
    }
}

void func_80800208_bscarry(PlayerState* self)
{
    if (func_8009E6C4(self, 0x400) == 0)
    {
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.03f);
        bastick_setZoneMax(self, 1, 0.2f);
        bastick_setZoneMax(self, 2, 1.0f);
    }
}

void func_8080027C_bscarry(PlayerState* self)
{
    func_808001D4_bscarry(self);
}

void func_8080029C_bscarry(PlayerState* self)
{
    func_80800208_bscarry(self);
    baanim_playForDuration_loopSmooth(self, 0x28, 0.8f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8008C9F0(self, 30.0f, 60.0f, 1.8f, 1.2f);
}

void func_80800310_bscarry(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800128_bscarry(self);
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        if (func_8009BCD4(self, 1.0f) != 0) {
            nextState = 0x3A;
        }
        break;
    case BS_STICK_ZONE_ID_2:
        nextState = 0x3B;
        break;
    }
    if (_bahold_entrypoint_5(self) == 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bscarry_entrypoint_0(s32 arg0) {
    return D_808007B0_bscarry[arg0];
}

void func_808003D8_bscarry(PlayerState* self)
{
    func_808001D4_bscarry(self);
}

void func_808003F8_bscarry(PlayerState* self) {
    func_80800208_bscarry(self);
    baanim_playForDuration_loopSmooth(self, 0x72, 1.2f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
}

void func_8080047C_bscarry(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_1:
        nextState = 0x9F;
        break;
    case BS_STICK_ZONE_ID_2:
        nextState = 0x3B;
        break;
    }
    if (_bahold_entrypoint_5(self) == 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bscarry_entrypoint_1(s32 arg0) {
    return D_808007C0_bscarry[arg0];
}

void func_80800500_bscarry(PlayerState* self)
{
    func_808001D4_bscarry(self);
}

void func_80800520_bscarry(PlayerState* self)
{
    func_80800208_bscarry(self);
    baanim_playForDuration_loopSmooth(self, 0x73, 0.8f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8008C9F0(self, 60.0f, 300.0f, 0.84f, 0.4f);
}

void func_80800594_bscarry(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800128_bscarry(self);
    switch (bastick_getZone(self))
    {
    case BS_STICK_ZONE_ID_0:
        if (func_8009BCD4(self, 1.0f) != 0) {
            nextState = 0x3A;
        }
        break;
    case BS_STICK_ZONE_ID_1:
        nextState = 0x9F;
        break;
    }
    if (_bahold_entrypoint_5(self) == 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bscarry_entrypoint_2(s32 arg0) {
    return D_808007D0_bscarry[arg0];
}

void func_8080065C_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_808001D4_bscarry(self);
}

void func_80800684_bscarry(PlayerState* self)
{
    func_80800208_bscarry(self);
    _bsdrone_entrypoint_0(self);
}

void func_808006AC_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}

s32 bscarry_entrypoint_3(s32 arg0) {
    return D_808007E0_bscarry[arg0];
}

void func_808006E0_bscarry(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_808001D4_bscarry(self);
}

void func_80800708_bscarry(PlayerState* self)
{
    func_80800208_bscarry(self);
    _bsrest_entrypoint_16(self);
}

void func_80800730_bscarry(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0)
    {
        nextState = 0x3A;
    }
    if (_bahold_entrypoint_5(self) == 0)
    {
        nextState = 0x73;
    }
    bs_setState(self, nextState);
}

s32 bscarry_entrypoint_4(s32 arg0)
{
    return D_808007F0_bscarry[arg0];
}
