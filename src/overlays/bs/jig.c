#include "bs/jig.h"


extern u8 D_8012762C;
extern s32 D_808005B0_bsjig[];
extern s32 D_808005C0_bsjig[];

s32 bsjig_entrypoint_0(s32 arg0)
{
    return arg0 == 0x44;
}
void bsjig_entrypoint_1(PlayerState* self)
{
    AnimCtrl* sp2C;
    s32 var_a1;

    sp2C = baanim_getAnimCtrlPtr(self);
    anctrl_reset(sp2C);
    anctrl_setSmoothTransition(sp2C, 0);
    anctrl_setIndex(sp2C, 0x2E);
    anctrl_setDuration(sp2C, 4.3f);
    anctrl_setPlaybackType(sp2C, 1);
    anctrl_start(sp2C);
    yaw_setIdeal(self, func_8009F308(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    var_a1 = collectable_getCollectedInLevel(1, (s32)D_8012762C) != 0;
    if (var_a1 == 0) {
        var_a1 = 0;
    }
    self->unk160.word = var_a1;
    func_800FC660(5);
    func_800A4DFC(self, 9);
    func_800C52F4(func_800A4C68(self), 2);
    func_800A0CF4(self, 1);
    func_8009DE38(self, 0x422, 1.0f);
    baflag_clear(self, BA_FLAG_7);
    baflag_clear(self, BA_FLAG_F);
    func_8008E944(self);
    _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(self)), 1);
    self->unk15C.word = 0;
}

void bsjig_entrypoint_2(s32 self)
{
    PlayerState* temp_v0;

    temp_v0 = character_getPlayerState(self);
    if (func_800A32F8(temp_v0) != NULL)
    {
        _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(temp_v0)), 4);
    }
}

void bsjig_entrypoint_3(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp20;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    yaw_setIdeal(self, func_8009F308(self));
    if (anctrl_isAt(sp20, 0.6502f) != 0) {
        func_8009D874(self);
    }
    if (anctrl_isAt(sp20, 0.835f) != 0) {
        self->unk15C.word += 1;
        func_8009DE38(self, 0x434, 1.3f);
    }
    if (anctrl_isAt(sp20, 0.94f) != 0) {
        func_8009DE38(self, 0x3EA, 1.0f);
    }
    if (anctrl_isStopped(sp20) != 0) {
        if (self->unk160.word != 0) {
            nextState = 0x34;
        }
        else {
            nextState = BS_STATE_1_IDLE;
        }
    }
    func_8009919C(self, &_bsjig_entrypoint_2, self->unk184);
    bs_setState(self, nextState);
}

void bsjig_entrypoint_4(PlayerState* self)
{
    Unk80132ED0* temp_v0;

    temp_v0 = func_800A32F8(self);
    if (temp_v0 != NULL) {
        _chjigsawdance_entrypoint_1(func_80106790(temp_v0), 5);
        func_800A34D8(self, 0);
    }
}

void bsjig_entrypoint_5(PlayerState* self)
{
    bsjig_entrypoint_4(self);
    func_800A0CF4(self, 0);
    func_800A4E30(self);
    func_800C53EC(func_800A4C68(self), 2);
    func_8008E95C(self);
    func_8009CEE8(self);
}

s32 bsjig_entrypoint_6(s32 arg0)
{
    return D_808005B0_bsjig[arg0];
}

void bsjig_entrypoint_7(PlayerState* self)
{
    if (func_8009E6EC(self) == 0x26)
    {
        func_80099B94(self);
        return;
    }
    func_80099AA8(self);
}

void bsjig_entrypoint_8(PlayerState* self)
{
    func_8008E95C(self);
    func_800A0CF4(self, 0);
    func_800A4E30(self);
    func_800C53EC(func_800A4C68(self), 2);
    func_8009CEE8(self);
}

void bsjig_entrypoint_9(PlayerState* self)
{
    AnimCtrl* temp_s1;

    temp_s1 = baanim_getAnimCtrlPtr(self);
    self->unk164.word = bs_getPreviousState(self) == 0x44;
    baflag_clear(self, BA_FLAG_1A);
    anctrl_reset(temp_s1);
    anctrl_setIndex(temp_s1, 0x282);
    anctrl_setDuration(temp_s1, 3.6f);
    anctrl_setPlaybackType(temp_s1, 1);
    anctrl_start(temp_s1);
    yaw_setIdeal(self, func_8009F308(self));
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800FC660(0x1B);
    func_800A4DFC(self, 9);
    func_800C52F4(func_800A4C68(self), 2);
    func_800A0CF4(self, 1);
    func_8009DE38(self, 0x422, 1.0f);
    func_8008E944(self);
}

void bsjig_entrypoint_10(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if ((baanim_isAt(self, 0.59f) != 0) || (baanim_isAt(self, 0.84f) != 0))
    {
        func_8009DF18(self, 0x3EA, 1.0f, 0x7530);
    }
    if (baanim_isStopped(self) != 0) {
        nextState = BS_STATE_1_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsjig_entrypoint_11(s32 arg0) {
    return D_808005C0_bsjig[arg0];
}
