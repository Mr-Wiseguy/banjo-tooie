#include "core2/1EA0690.h"
#include "core2/1EB3750.h"

extern s32 D_8012AAD0[];
extern u32 D_8012AAE0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C6DA0.s")

s32 func_800C6E18(s32 arg0)
{
    return flag_getValue(arg0 + 0xEE);
}

//Has Ability
s32 ability_getValue(AbilityId AbilityID) {
    return flag_getValue(AbilityID + FLAG_0ED_ABILITY_BK_BEAK_BARGE);
}

//Immediate Return
void func_800C6E58(void) {
}

void func_800C6E60(void) {
    ability_setValue(0, 1);
    ability_setValue(1, 1);
    ability_setValue(2, 1);
    ability_setValue(3, 1);
    ability_setValue(4, 1);
    ability_setValue(5, 1);
    ability_setValue(6, 1);
    ability_setValue(7, 1);
    ability_setValue(8, 1);
    ability_setValue(9, 1);
    ability_setValue(0xA, 1);
    ability_setValue(0xB, 1);
    ability_setValue(0xC, 1);
    ability_setValue(0xD, 1);
    ability_setValue(0xE, 1);
    ability_setValue(0xF, 1);
    ability_setValue(0x10, 1);
    ability_setValue(0x11, 1);
    ability_setValue(0x12, 1);
    ability_setValue(0x13, 1);
    ability_setValue(0x31, 1);
    ability_offsetSetValue(0x3C, 1);
    ability_offsetSetValue(0x3D, 1);
    ability_offsetSetValue(0x3E, 1);
    ability_offsetSetValue(0x3F, 1);
    ability_offsetSetValue(0x40, 1);
    ability_offsetSetValue(0x41, 1);
    ability_offsetSetValue(0x42, 1);
    ability_offsetSetValue(0x43, 1);
    ability_offsetSetValue(0x44, 1);
    ability_offsetSetValue(0x45, 1);
    ability_offsetSetValue(0x46, 1);
    ability_offsetSetValue(0x47, 1);
    ability_offsetSetValue(0x48, 1);
}

//Give all Abilities
void func_800C7010(void) {
    s32 var_s0 = 0;
    while (var_s0 < 0x3C)
    {
        ability_setValue(var_s0, 1);
        var_s0++;
    }
    var_s0 = 0x3C;
    while (var_s0 < 0x50)
    {
        ability_offsetSetValue(var_s0, 1);
        var_s0 += 1;
    }
}

void func_800C7074(s32 arg0, s32 arg1) {
    ability_setValue(arg0, arg1);
    if (arg1 != 0) {
        func_80101238(0x1A, arg0);
    }
}

//Set Ability Flag
void ability_setValue(AbilityId arg0, s32 set) {
    flag_setValue(arg0 + FLAG_0ED_ABILITY_BK_BEAK_BARGE, set);
}

//Set Ability Flag offset by 1
void ability_offsetSetValue(s32 arg0, s32 set) {
    flag_setValue(arg0 + FLAG_0EE_ABILITY_BK_BEAK_BOMB, set);
}

void func_800C70F0(s32 arg0) {
    D_8012AAD0[arg0] = D_8012AAE0;
}

s32 func_800C710C(s32 arg0)
{

    if (D_8012AAD0[arg0] + 5 < D_8012AAE0)
    {
        D_8012AAD0[arg0] = D_8012AAE0;
        return 1;
    }
    return 0;
}

void* func_800C7150(void* arg0) 
{
    return defrag(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C7170.s")

void func_800C718C(void) {
    D_8012AAE0 += 1;
}