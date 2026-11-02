#include "core2/1E7AB30.h"


extern u8 D_80127090[];

void func_800A1240(TransformationId arg0)
{

    D_80127090[9] = transformation_getIcon(arg0);
    D_80127090[6] = arg0;
    func_800D2748(0xCF, D_80127090[9]);
    func_800D2748(0xCD, D_80127090[9]);
}

void func_800A1294(s32 arg0)
{
    TransformationId activeTransformation;
    u32 maxHealth;

    if ((D_80127090[4] == 0) && (func_800D3948() == 0)
        && (flag_getValue(FLAG2_6B6_UNK) == 0)
        && (cheat_isActive(9U) == 0) && (D_80127090[7] == 0))
    {
        activeTransformation = activePlayer_getTransformation();
        maxHealth = transformation_getMaxHealth(activeTransformation);
        if (maxHealth != 0)
        {
            if (arg0 != 0)
            {
                func_800D2498(0xCF, transformation_getCurrentHealth(activeTransformation), maxHealth);
                return;
            }
            func_800D24E8(0xCF, transformation_getCurrentHealth(activeTransformation), maxHealth);
        }
    }
}

void func_800A1364(void)
{
    D_80127090[1] = 0;
    D_80127090[0] = 0;
    transformation_setAllMaxHealth();
    func_800A1240(func_8009E958());
}

void func_800A13A0(void) {
    D_80127090[0] = 1;
}

void func_800A13B0(s32 arg0)
{
    D_80127090[2] = _gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(arg0), 0x1000);
    D_80127090[1] = 0;
    if (func_800F8B64() != 0)
    {
        D_80127090[1] = 1;
        D_80127090[3] = 1;
    }
    if (func_800F99E8() != 0)
    {
        D_80127090[1] = 1;
    }
    D_80127090[4] = 1;
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(arg0), 0x1000) != 0) {
        D_80127090[5] = 1;
        return;
    }
    D_80127090[5] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1450.s")

void func_800A1618(s32 arg0) {
    D_80127090[2] = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1694.s")

u8 func_800A16A4(void) {
    return D_80127090[7];
}

u8 func_800A16B0(void) {
    return D_80127090[9];
}

void func_800A16BC(s32 arg0)
{
    if (arg0 != 0)
    {
        D_80127090[5]++;
        return;
    }
    D_80127090[5]--;
}

void func_800A16F4(PlayerState* self)
{
    _batimer_set(self, 0xE, 3.0f);
}

s32 player_getCurrentHealth(PlayerState* self)
{
    if (self->deathmatch != NULL)
    {
        return func_800F9F04(self->unk184, self);
    }
    return transformation_getCurrentHealth(player_getTransformation(self));
}
s32 player_getMaxHealth(PlayerState* self)
{
    if (self->deathmatch != NULL)
    {
        return func_800F9F18(self->unk184, self);
    }
    return transformation_getMaxHealth(player_getTransformation(self));
}

void player_affectCurrentHealth(PlayerState* self, s32 arg1)
{
    TransformationId currentTransform;

    if (self->deathmatch != NULL)
    {
        func_800F9EC0(self->unk184, arg1);
        return;
    }
    currentTransform = player_getTransformation(self);
    if ((arg1 >= 0) || (D_80127090[2] == 0))
    {
        if (transformation_getMaxHealth(currentTransform))
        {
            if (cheat_isActive(9U))
            {
                arg1 = transformation_getMaxHealth(currentTransform);
            }
            transformation_affectCurrentHealth(currentTransform, arg1);
            func_800A1294(0);
            if (cheat_isActive(4U))
            {
                _batimer_set(self, 0xE, 3.0f);
            }
        }
    }
}

void player_setCurrentHealth(PlayerState* self, s32 arg1)
{
    if (self->deathmatch != NULL)
    {
        func_800F9F2C(self->unk184, arg1);
        return;
    }
    transformation_setCurrentHealth(player_getTransformation(self), arg1);
    func_800A1294(1);
}

void func_800A18C8(PlayerState* self) {
    func_800F9F74(self->unk184);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A18E8.s")
