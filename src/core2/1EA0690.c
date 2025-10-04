#include "core2/1EA0690.h"
#include "core2/1EB3750.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C6DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C6E18.s")

//Has Ability
s32 func_800C6E38(s32 AbilityID) {
    return func_800DA298(AbilityID + FLAG_0ED_ABILITY_BK_BEAK_BARGE);
}

//Immediate Return
void func_800C6E58(void) {
}

void func_800C6E60(void) {
    func_800C70B0(0, 1);
    func_800C70B0(1, 1);
    func_800C70B0(2, 1);
    func_800C70B0(3, 1);
    func_800C70B0(4, 1);
    func_800C70B0(5, 1);
    func_800C70B0(6, 1);
    func_800C70B0(7, 1);
    func_800C70B0(8, 1);
    func_800C70B0(9, 1);
    func_800C70B0(0xA, 1);
    func_800C70B0(0xB, 1);
    func_800C70B0(0xC, 1);
    func_800C70B0(0xD, 1);
    func_800C70B0(0xE, 1);
    func_800C70B0(0xF, 1);
    func_800C70B0(0x10, 1);
    func_800C70B0(0x11, 1);
    func_800C70B0(0x12, 1);
    func_800C70B0(0x13, 1);
    func_800C70B0(0x31, 1);
    func_800C70D0(0x3C, 1);
    func_800C70D0(0x3D, 1);
    func_800C70D0(0x3E, 1);
    func_800C70D0(0x3F, 1);
    func_800C70D0(0x40, 1);
    func_800C70D0(0x41, 1);
    func_800C70D0(0x42, 1);
    func_800C70D0(0x43, 1);
    func_800C70D0(0x44, 1);
    func_800C70D0(0x45, 1);
    func_800C70D0(0x46, 1);
    func_800C70D0(0x47, 1);
    func_800C70D0(0x48, 1);
}

//Give all Abilities
void func_800C7010(void) {
    s32 var_s0 = 0;
    while (var_s0 < 0x3C)
    {
        func_800C70B0(var_s0, 1);
        var_s0++;
    }
    var_s0 = 0x3C;
    while (var_s0 < 0x50)
    {
        func_800C70D0(var_s0, 1);
        var_s0 += 1;
    }
}

void func_800C7074(s32 arg0, s32 arg1) {
    func_800C70B0(arg0, arg1);
    if (arg1 != 0) {
        func_80101238(0x1A, arg0);
    }
}

//Set Ability Flag
void func_800C70B0(s32 arg0, s32 set) {
    func_800DA3B8(arg0 + FLAG_0ED_ABILITY_BK_BEAK_BARGE, set);
}

//Set Ability Flag offset by 1
void func_800C70D0(s32 arg0, s32 set) {
    func_800DA3B8(arg0 + FLAG_0EE_ABILITY_BK_BEAK_BOMB, set);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C70F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C710C.s")

void* func_800C7150(void* arg0) 
{
    return defrag(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C7170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0690/func_800C718C.s")
