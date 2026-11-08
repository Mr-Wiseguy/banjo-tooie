#include "core2/1E72180.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
}UNKD_80117EC0;
extern UNKD_80117EC0 D_80117EC0[];

s32 func_80098890() 
{
    return sizeof(ba_unknown_BC_s);
}

void func_80098898(PlayerState* self) 
{
    s32 sp3C[3];
    s32 sp30[3];
    enum map_e sp2C;
    s32 index;
    UNKD_80117EC0* temp;

    sp2C = map_getCurrent();
    func_800BED18(sp30, sp3C);
    ml_vec3i_to_vec3f(self->unkBC->unkC, sp30);
    ml_vec3i_to_vec3f(self->unkBC->unk0, sp3C);
    temp = D_80117EC0;
    while (temp->unk0 != 0 && sp2C != temp->unk0)
    {
        temp++;
    }
    self->unkBC->unkC[0] -= (f32)temp->unk2;
    self->unkBC->unkC[1] -= (f32)temp->unk4;
    self->unkBC->unkC[2] -= (f32)temp->unk6;
    self->unkBC->unk0[0] += (f32)temp->unk8;
    self->unkBC->unk0[1] += (f32)temp->unkA;
    self->unkBC->unk0[2] += (f32)temp->unkC;
    self->unkBC->unk18 = 0;
    self->unkBC->unk19 = 0;
}

void func_800989E4(PlayerState* self) {
    f32 sp2C[3];
    s32 temp_v0;
    s32 sp24;
    s32 sp20;

    if (func_8008DAA8(self) == 0) {
        return;
    }
    if (self->unkBC->unk19 != 0)
    {
        return;
    }
    temp_v0 = func_800BF6B8();
    if (temp_v0 == 1)
    {
        return;
    }
    player_getCoords(self, sp2C);
    if (temp_v0 != 2 && (func_800EFED0((self->unkBC->unkC), self->unkBC->unk0, sp2C) != 0))
    {
        return;
    }
    if (self->unkBC->unk18 == 0)
    {
        self->unkBC->unk18 = 1;
        if ((func_800D3948() != 0) || (func_800D395C() != 0))
        {
            _gcfrontend_entrypoint_12();
            return;
        }
        sp24 = 0;
        sp20 = 0;
        switch (player_getTransformation(self))
        {
        case TRANSFORM_11_CLOCKWORK:
            sp24 = 1;
            break;
        case TRANSFORM_B_KAZOOIE:
            if (bs_getSplitStatus() == SPLIT_STATE_TALON_TORPEDO)
            {
                sp20 = 1;
            }
            break;
        }
        if (sp24 != 0)
        {
            func_800F7B9C(self->unk184, 0x1FU);
        }
        else if (sp20 != 0)
        {
            func_800F7B9C(self->unk184, 0x88U);
        }
        else
        {
            func_800A05DC(self);
        }
    }
    else
    {
        baphysics_set_type(self, BA_PHYSICS_7_FREEZE);
    }
}

void func_80098B4C(PlayerState* self, s32 arg1)
{
    self->unkBC->unk19 = (s8)(arg1 == 0);
}

void func_80098B5C(PlayerState* self, f32* arg1, f32* arg2)
{
    ml_vec3f_copy(arg1, self->unkBC->unkC);
    ml_vec3f_copy(arg2, self->unkBC->unk0);
}

s32 func_80098BA0() 
{
    return sizeof(ba_unknown_B8_s);
}

void func_80098BA8(PlayerState* self, s32 arg1)
{
    if (func_80091E80(self, 1) != 0)
    {
        func_80092444(self, arg1);
    }
}

void func_80098BE0(PlayerState* self)
{
    if (func_800A9420(self->unk184) != 0)
    {
        if (func_8009AD78(self, 8) != 0)
        {
            _baeggcursor_entrypoint_1(self);
        }
        if (func_8009AD78(self, 0xB) != 0)
        {
            _bsfirstp_entrypoint_37(self);
        }
    }
}

void func_80098C48(PlayerState* self)
{
    self->unkB8->unk8 = 1;
    func_8009AD90(self);
    _badronemem_entrypoint_3(self);
    _bastatemem_entrypoint_3(self);
    func_800A3820(self);
    self->unkB8->unk0 = NULL;
    bakey_init(self);
    func_8009FE78(self);
    func_8009C038(self);
    _badrone_entrypoint_32(self);
    _badust_entrypoint_11(self);
    func_800955CC(self);
    baflag_clearAll(self);
    func_800A0FF0(self);
    bastick_reset(self);
    bainput_init(self);
    _bainvisible_entrypoint_3(self);
    func_80098408(self);
    func_8009CBFC(self);
    func_8009E7AC(self);
    func_800A16F4(self);
    func_80091E20(self);
    func_80094644(self);
    _baeggcursor_entrypoint_5(self);
    _bafpctrl_entrypoint_8(self);
    _bapackctrl_entrypoint_3(self);
    _bababykaz_entrypoint_2(self);
    func_800A4168(self);
    _bacough_entrypoint_3(self);
    func_80091EC8(self);
    _badeathmatch_entrypoint_1(self);
    _baduo_entrypoint_6(self);
    _baattach_entrypoint_4(self);
    func_80098898(self);
    func_8009AC6C(self);
    func_8009B4FC(self);
    func_8009BD50(self);
    func_8009BF04(self);
    func_80098538(self);
    func_8009CC90(self);
    baroll_reset(self);
    func_8009CF98(self);
    func_80094F38(self);
    func_800A0C44(self);
    func_80095068(self);
    func_80090938(self);
    func_8009105C(self);
    bastatetimerlist_init(self);
    _bahold_entrypoint_1(self);
    func_80095AD0(self);
    _bamum_entrypoint_2(self);
    baanim_init(self);
    func_800A21C8(self);
    func_80092898(self);
    func_8008E618(self);
    _basetup_entrypoint_4(self);
    func_8009D4D8(self);
    func_800A1F78(self);
    _bashoes_entrypoint_4(self);
    func_8009E390(self);
    _basquash_entrypoint_2(self);
    func_800A2D94(self);
    _batranslate_entrypoint_2(self);
}

void func_80098E64(PlayerState* self)
{
    s32 var_v0;
    s32 sp30;
    f32 sp2C;
    s32 sp28;
    s32 var_a1;

    if ((player_getTransformation(self) == TRANSFORM_E_GOLDENGOLIATH) && (baflag_isTrue(self, 0x40) != 0))
    {
        player_setTransformation(self, TRANSFORM_D_MUMBO);
        func_800F8EBC(self->unk184);
    }
    sp30 = func_8009CBDC(self, bs_getCurrentState(self));
    if (func_8008DAA8(self) != 0)
    {
        func_8009E880();
        if ((func_800A81C4() != 0) || (func_800EA068(0x800) != 0))
        {
            _bashoes_entrypoint_6(self, 1);
        }
        sp28 = 0;
        sp2C = 0.0f;
        if (func_8008E39C(self) != 0)
        {
            sp2C = bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON);
            sp28 = 1;
        }
        else
        {
            if (func_8009E674(self, 0x40) != 0)
            {
                sp28 = 1;
            }
        }
        if (sp28 != 0)
        {
            func_8009EAD0(2);
        }
        func_8009EB0C(sp2C);
        func_8009EAF4(_bashoes_entrypoint_1(self));
        func_8009E9D8(player_getTransformation(self));
        func_8009E9FC(0.0f);
        switch (sp30)
        {
        case 8:
            func_8009E9FC(bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG));
            break;
        case 9:
            if (player_getTransformation(self) == TRANSFORM_6_BEE)
            {
                func_8009EAD0(4);
            }
            break;
        case 18:
            func_8009EAD0(3);
            break;
        case 19:
            func_8009EAD0(6);
            break;
        case 20:
            func_8009EAD0(7);
            break;
        }
    }
    var_a1 = func_8009E71C(self, 5)?1:0;
    var_a1 &= func_800EA068(8)?1:0;
    func_8009EB18(var_a1);
    bs_setState(self, 0x5A);
    _baattach_entrypoint_3(self);
    func_8008E6BC(self);
    func_80091054(self);
    _bababykaz_entrypoint_1(self);
    bastatetimerlist_free(self);
    _baeggcursor_entrypoint_4(self);
    func_80094538(self);
    func_80092A1C(self);
    func_800A22A8(self);
    baanim_free(self);
    func_80095C10(self);
    _bahold_entrypoint_2(self);
    _bamum_entrypoint_1(self);
    _basetup_entrypoint_3(self);
    func_8009D5E0(self);
    func_800A2058(self);
    _bashoes_entrypoint_3(self);
    _basquash_entrypoint_1(self);
    func_800A2D70(self);
    _batranslate_entrypoint_1(self);
    _bastatemem_entrypoint_2(self);
    _badronemem_entrypoint_2(self);
    _bapackctrl_entrypoint_2(self);
    _baduo_entrypoint_5(self);
    func_8009E388((s32)self);
    _bafpctrl_entrypoint_7(self);
    func_80091E18(self);
    bakey_free(self);
    _bacough_entrypoint_2(self);
    _badeathmatch_entrypoint_2(self);
    func_80091EA8(self);
    _bainvisible_entrypoint_4(self);
    func_8009AD88((s32)self);
    func_800A4160(self);
    self->unkB8->unk8 = 0;
}

void func_8009919C(PlayerState* self, s32* arg1, s32 arg2) {
    self->unkB8->unk0 = (void (*)(s32)) arg1;
    self->unkB8->unk4 = arg2;
}

void func_800991B0(PlayerState* self)
{
    s32 sp24;
    s32 sp20;
    void (*temp_v1)(s32);

    sp24 = func_800EA068(8) == 0;
    sp20 = flag_getValue(FLAG2_6B5_UNK);
    if (func_80091E80(self, 0x20) != 0)
    {
        func_80092AB0(self);
        func_80099970(self);
        func_8009CF04(self);
        bastatetimerlist_update(self);
        func_800A0DDC(self);
        bakey_update(self);
        bastick_update(self);
        bainput_update(self);
        if (func_8009AD78(self, 2) != 0)
        {
            _baduo_entrypoint_13(self);
        }
        func_8009E83C(self);
        if ((func_80091E80(self, 2) != 0) && (func_8008E454(self) != 0))
        {
            func_8009B590(self);
        }
        if (func_8009AD78(self, 6) != 0)
        {
            _batranslate_entrypoint_4(self);
        }
        func_8009C25C(self);
        if (sp24 != 0) {
            func_8009561C(self);
        }
        func_80095C94(self);
        if (func_80091E80(self, 2) != 0)
        {
            func_8009BF34(self);
            baroll_update(self);
            func_8009D088(self);
        }
        if (sp20 != 0)
        {
            func_80091110(self);
        }
        if (func_80091E80(self, 0x10) != 0)
        {
            baanim_update(self);
        }
        func_800A2060(self);
        if (sp24 != 0) {
            func_800987CC(self);
        }
        if (func_8009AD78(self, 4) != 0)
        {
            func_80090A4C(self);
        }
        if (sp24 != 0) {
            func_800951F4(self);
        }
        if (func_8009AD78(self, 3) != 0)
        {
            _badust_entrypoint_13(self);
        }
        func_8009C08C(self);
        func_8008E6F0(self);
        if (func_8009AD78(self, 0xE) != 0)
        {
            _bahold_entrypoint_3(self);
        }
        func_800A10A0(self);
        func_8009BDE4(self);
        func_800A3A80(self);
        func_800A4B08(self);
        if (self->deathmatch == NULL)
        {
            func_80094864(self);
        }
        else {
            _badeathmatch_entrypoint_3(self);
        }
        if (func_8009AD78(self, 9) != 0)
        {
            _bacough_entrypoint_5(self);
        }
        if (func_8009AD78(self, 8) != 0)
        {
            _baeggcursor_entrypoint_11(self);
        }
        if (func_8009AD78(self, 0xC) != 0)
        {
            _bainvisible_entrypoint_6(self);
        }
        if (func_8009AD78(self, 5) != 0)
        {
            _bamum_entrypoint_3(self);
        }
        if (func_8009AD78(self, 7) != 0)
        {
            _bafpctrl_entrypoint_15(self);
        }
        if (func_8009AD78(self, 0xA) != 0)
        {
            _basquash_entrypoint_4(self);
        }
        if (func_8009AD78(self, 0xD) != 0)
        {
            _bashoes_entrypoint_13(self);
        }
        func_80093448(self);
        func_800A2534(self);
        if ((cheat_isActive(CHEAT_4_HONEYBACK) != 0) && (func_8008DAA8(self) != 0) && (func_8008E124(self) == 0))
        {
            func_800A18E8(self);
        }
        func_80091F30(self);
        if (self->unkB8->unk0 != NULL)
        {
            self->unkB8->unk0(self->unkB8->unk4);
            self->unkB8->unk0 = NULL;
        }
        func_800989E4(self);
    }
}

void func_80099544(PlayerState* self)
{
    if (self->unkB8->unk8 != 0)
    {
        baanim_defrag(self);
        func_800934C4(self);
        func_80096728(self);
        func_800A300C(self);
        bakey_defrag(self);
        func_800A266C(self);
    }
}