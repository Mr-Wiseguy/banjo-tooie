#include "core2/1EE27C0.h"

extern s32 D_801245D0;
extern s32 D_801245E4;
extern s32 D_801245F8;

void* func_80108ED0(void)
{
    return &D_801245D0;
}

void* func_80108EDC(void)
{
    return &D_801245E4;
}

void* func_80108EE8(void) 
{
    return &D_801245F8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80108EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80108F08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801094E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010965C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801096C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801098D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801099D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109CC4.s")

s32 func_80109EE0(Actor* arg0, s32 arg1)
{
    return arg0->unk64_0 & arg1;
}

void func_80109EEC(Actor* arg0, s32 arg1)
{
    arg0->unk64_0 = arg1;
}

void func_80109EF4(Actor* arg0, s32 arg1)
{
    arg0->unk64_0 &= ~arg1;
}

void func_80109F08(Actor* arg0, s32 arg1)
{
    arg0->unk64_0 |= arg1;
}

void func_80109F18(s32 arg0, s32 arg1)
{
    func_8010114C(arg0, EVENT_3E_ACTOR_TOUCHED, arg1);
    if (arg1) {}
}

void func_80109F40(s32 arg0, s32 arg1)
{
    func_8010114C(arg0, 0x3F, arg1);
    if (arg1) {}
}

void func_80109F68(s32 arg0, s32 arg1)
{
    func_8010114C(arg0, 0x40, arg1);
    if (arg1) {}
}

void func_80109F90(s32 arg0, s32 arg1)
{
    func_8010114C(arg0, 0x41, arg1);
    if (arg1) {}
}

void func_80109FB8(Unk80132ED0* arg0, Unk80132ED0* arg1)
{
    func_80106790(arg1)->unk3C = arg0;
    if (arg1) {}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A2FC.s")

void func_8010A3E8(Actor* arg0, f32 arg1)
{
    arg0->unk92 = (s16)(256.0f * arg1);
}

f32 func_8010A40C(Actor* arg0)
{
    return (f32)arg0->unk92 * 0.00390625f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A430.s")

s32 actor_disableCollision(Actor* arg0)
{
    return actor_setCollision(arg0,0);
}

s32 actor_enableCollision(Actor* arg0)
{
    return actor_setCollision(arg0,1);
}

s32 actor_setCollision(Actor* arg0, s32 arg1)
{
    s32 currentState;

    currentState = actor_getCollision(arg0);
    if (arg1 != 0)
    {
        arg0->unk0->unk28_9 = 1;
    }
    else
    {
        arg0->unk0->unk28_9 = 0;
    }
    return currentState;
}

u32 actor_getCollision(Actor* arg0)
{
    return arg0->unk0->unk28_9;
}

void func_8010A624(Actor* arg0)
{
    arg0->unk0->unk0->unkA_3 = 0;
}

void func_8010A63C(Actor* arg0)
{
    arg0->unk0->unk0->unkA_3 = 1;
}

u32 func_8010A654(Actor* arg0, s32 arg1)
{
    s32 returnVal;
    returnVal = arg0->unk0->unk0->unkA_3;
    if (arg1 != 0)
    {
        arg0->unk0->unk0->unkA_3 = 1;
    }
    else
    {
        arg0->unk0->unk0->unkA_3 = 0;
    }
    return returnVal;
}

u32 func_8010A698(Actor* arg0)
{
    return arg0->unk0->unk0->unkA_3;
}

s32 func_8010A6B0(Actor* arg0, s32 arg1)
{
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    if (func_800F4B4C(arg1) == 0)
    {
        return 0;
    }
    func_800F57F0(arg1, &sp28);
    func_80103DFC(arg0, &sp34);
    if (func_800C6A7C(sp28, sp34, sp1C, 0x4A0021) != 0)
    {
        return 0;
    }
    return 1;
}
