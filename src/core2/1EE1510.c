#include "core2/1EE1510.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80107C20.s")

Actor* func_80107C2C(s32 coords[3], s32 arg1, ActorData* actorData, s32 arg3, Prop* prop)
{
    Actor* actor;
    s32 sp38;
    s32 i;

    actor = actorList_pushback(&sp38);
    actor->pointerToSyscallEntry = arg3;
    actor->unk70_10 = actorData->unk6;
    actor->position[0] = coords[0];
    actor->position[1] = coords[1];
    actor->position[2] = coords[2];
    actor->rotation[1] = arg1;
    actor->unk64_16 = 1;
    actor->scale = 1.0f;
    actor->unk54 = arg1;
    actor->unk6C_9 = actorData->unk2;
    ((f32*)actor->actorData)[7] = 0/*.0f*/;
    actor->unk74_0 = 0;
    actor->unk7A_14 = 1;
    actor->unk64_18 = 1;
    actor->unk7C = actorData->unk18;
    if (actorData->unk1C != 0.0f)
    {
        actor->unk74_20 = 1;
    }
    else
    {
        actor->unk74_20 = 0;
    }
    actor->unk94_16 = actor->unk74_20;
    func_80100074(actor, 0U, actorData->unk30);
    func_80100074(actor, 1U, actorData->unk32);
    if (actorData->Model == 0xFFFF)
    {
        actor->unk0 = func_800EBED4(coords, 1, actorData->unk0, (actorData->unk24w & 0x400) ? 1 : 0);
    }
    else
    {
        actor->unk0 = func_800EBED4(coords, func_800D738C(actorData->Model) == 7 ? 0 : 1, actorData->unk0, (actorData->unk24w & 0x400) ? 1 : 0);
    }
    actor->unk0->unk18_16 = 1;
    if (actorData->unk2C_func != NULL)
    {
        actor->unk0->unk8 = actorData->unk2C_func;
    }
    else
    {
        actor->unk0->unk8 = func_80107C20;
    }
    func_800EC340(actor->unk0, sp38);
    func_800EC360(actor->unk0, actorData->Model);
    func_800EC368(actor->unk0, actorData->unk22);
    actor->unk74_16 = 1;
    actor->unk74_19 = ((u16*)actor)[0x74 / 2];
    if (func_80102FA0(actorData, 1) != 0) {
        _subaddieDll_entrypoint_1(actor);
    }
    if (func_80102FA0(actorData, 0x800000) != 0) {
        actor->unk70_21 = 1;
    }
    if (func_80102FA0(actorData, 8) != 0) {
        actor->unk70_24 = 1;
    }
    if (func_80102FA0(actorData, 0x100) != 0) {
        actor->unk74_0 = 1;
    }
    if (func_80102FA0(actorData, 0x200000) != 0) {
        actor->unk64_25 = 1;
    }
    if (func_80102FA0(actorData, 0x04000000) != 0) {
        actor->unk70_22 = 1;
    }
    if (func_80102FA0(actorData, 4) == 0) {
        actor->unk74_17 = 1;
    }
    if (func_80102FA0(actorData, 0x100000) == 0) {
        actor->unk70_20 = 1;
    }
    if (func_80102FA0(actorData, 0x08000000) != 0) {
        actor->unk70_18 = 1;
    }
    if (func_80102FA0(actorData, 0x80000002) != 0) {
        actor->unk0->unk28_9 = 0;
    }
    if (func_80102FA0(actorData, 0x80000004) != 0) {
        actor->unk64_31 = 1;
    }
    if (func_80102FA0(actorData, 0x80000008) != 0) {
        actor->unk64_30 = 1;
    }
    if (func_80102FA0(actorData, 0x80000400) != 0) {
        actor->unk70_17 = 1;
    }
    if (func_80102FA0(actorData, 0x80001000) != 0) {
        actor->unk70_16 = 1;
    }
    if (func_80102FA0(actorData, 0x80002000) != 0) {
        actor->unk74_5 = 1;
    }
    if (func_80102FA0(actorData, 0x80004000) != 0) {
        actor->unk7C_13 = 1;
    }
    if (func_80102FA0(actorData, 0x80000100) != 0) {
        actor->unk74_26 = 1;
    }
    if (func_80102FA0(actorData, 0x80100000) != 0) {
        actor->unk74_23 = 1;
    }
    if (func_80102FA0(actorData, 0x80000001) != 0) {
        actor->unk64_24 = 1;
    }
    if (func_80102FA0(actorData, 0x80000010) != 0) {
        actor->unk7A_1 = 1;
    }
    if (func_80102FA0(actorData, 0x80400000) != 0) {
        actor->unk94_31 = 1;
    }
    if (func_80102FA0(actorData, 0x80800000) != 0) {
        actor->unk94_30 = 1;
    }
    if (func_80102FA0(actorData, 0x80000040) != 0) {
        actor->unk70_2 = 1;
    }
    if (func_80102FA0(actorData, 0x80040000) != 0) {
        actor->unk79_3 = 1;
    }
    if (func_80102FA0(actorData, 0x80200000) != 0) {
        actor->unk94_17 = 1;
    }
    if (func_80102FA0(actorData, 0x84000000) != 0) {
        actor->unk94_14 = 1;
    }
    if (func_80102FA0(actorData, 0x80000080) != 0) {
        actor->unk70_19 = 1;
    }
    if (func_80102FA0(actorData, 0x82000000) != 0) {
        actor->unk94_16 = 0;
    }
    func_8010A800(actor, 0);
    if (func_80102FA0(actorData, 0x800) != 0) {
        func_8010A800(actor, 1);
        func_8010A63C(actor);
    }
    if (func_80102FA0(actorData, 0x20000) != 0)
    {
        func_8010A800(actor, 2);
    }
    else if (func_80102FA0(actorData, 0x400000) != 0)
    {
        func_8010A800(actor, 3);
    }
    else if (func_80102FA0(actorData, 0x80008000) != 0)
    {
        func_8010A800(actor, 4);
    }
    if (func_80102FA0(actorData, 0x80000800) != 0)
    {
        actor->unk7C_14 = 0;
    }
    else
    {
        actor->unk7C_14 = 1;
    }
    if (func_80102FA0(actorData, 0x80000200) != 0)
    {
        actor->unk64_16 = 0;
    }
    else
    {
        actor->unk64_16 = 1;
    }
    if (prop != NULL)
    {
        actor->unk6C_21 = prop->unk10_5;
        actor->unk70_0 = (s32)prop->unk12_1;
    }
    func_80108658(actor, actorData->unk24w, actorData->unk3Cw, prop);
    actor->unk14 = 0x4A0021;
    for (i = 0; i < 3; i++)
    {
        actor->unk5C[i] = 0x63;
    }
    func_800F31FC(&actor->unk98, 0xFF, 0xFF, 0xFF, 0xFF);
    actor->unk74_28 = actorData->eventHandler != 0 ? 1 : 0;
    actor->unk74_27 = 1;
    func_80102424(actor, actor->unk70_10);
    func_80103930(actor);
    func_8010A3E8(actor, 1.0f);
    func_80106E88(actor);
    func_80104F2C(actor, func_80102FA0(actorData, 0x40000000), func_80102FA0(actorData, 0x10));
    if (func_800BEC1C() != 0)
    {
        _subaddiezone_entrypoint_0(actor);
    }

    return actor;
}

Actor* func_80108454(PropId arg0, s32* arg1, s32 arg2)
{
	return func_80108C90(arg0, arg1, (u32)arg2, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_801084B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_8010856C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_801085CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_801088A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108C14.s")

Actor* func_80108C90(PropId prop, s32* coords, u32 arg2, Prop* arg3)
{
	ActorData* (*temp_v0_2)(void);
	ActorData* actorData;
	temp_v0_2 = (ActorData * (*)(void))_gemarkersDll_entrypoint_0(prop);
	if (temp_v0_2 == NULL)
	{
		return NULL;
	}
	actorData = temp_v0_2();
	return actorData->unk38_func(coords, arg2, actorData, temp_v0_2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108DC0.s")
