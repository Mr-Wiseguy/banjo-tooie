#include "core2/1EC4CC0.h"

extern s32 D_80123540;
extern Vector* D_80132E80[];
extern s16 D_80132E9C;
extern s32 D_80132ED0[];

typedef struct {
	u8 pad0[0x14];
	s32 unk14;
	s32 unk18;
	s32 unk1C;
	s32 unk20;
	s32 unk24;
} UNKD_80132EA0;
extern UNKD_80132EA0 D_80132EA0;

extern s32 D_8013546C;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB70C.s")

void func_800EB750(void)
{
    int i;
    for (i = 0; i < 0x7; i++)
    {
        if (D_80132E80[i]) {
            vector_free(D_80132E80[i]);
            D_80132E80[i] = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB7A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB800.s")

s32 func_800EB854(void) {
	return D_80132E9C;
}

void func_800EB860(s32 arg0, s32 arg1) {
	D_80132EA0.unk20 = arg0;
	D_80132EA0.unk24 = arg1;
}

void func_800EB874(void) {
	D_80132EA0.unk20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB8C0.s")

s32 func_800EBB30(s32* arg0, s32* arg1) {
	*arg0 = D_80132EA0.unk14;
	*arg1 = D_80132EA0.unk18;
	return D_80132EA0.unk1C;
}

s32* func_800EBB50(void) {
	return &D_80123540;
}
void func_800EBB5C(void) {
	D_8013546C = 0x6B7;
}
void func_800EBB6C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBB94.s")

void func_800EBC04(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBE74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBF8C.s")

void func_800EBFD4(s32 a0, s32 a1, s32 a2)
{
	func_800EBF8C(a0, a1, a2, 0);
}

void func_800EBFF4(Unk80132ED0* arg0)
{
	func_800E9AC0(func_800BDB9C(arg0->unk1C), arg0->unk0);
	func_800EBE24(arg0);
}

void func_800EC030(Unk80132ED0* arg0, s32* arg1)
{
	arg0->unk0->unk4 = arg1[0];
	arg0->unk0->unk6 = arg1[1];
	arg0->unk0->unk8 = arg1[2];
}

void func_800EC058(s32* arg0, Unk80132ED0* arg1)
{
	s32 var_a2;

	if (arg1->unk12_0)
	{
		var_a2 = -1;
	}
	else
	{
		var_a2 = func_800BD97C(arg0);
	}
	if (var_a2 == arg1->unk1C)
	{
		func_800EC030(arg1, arg0);
	}
	else
	{
		func_800EBD2C(arg1, arg0, var_a2);
	}
	if (arg1->unk28_10)
	{
		func_800CDFD0(arg1);
	}
}

void func_800EC0EC(f32* arg0, Unk80132ED0* arg1)
{
	s32 sp1C[3];

	ml_vec3f_to_vec3i(sp1C, arg0);
	func_800EC058(sp1C, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC124.s")

void func_800EC340(Unk80132ED0* arg0, s32 arg1)
{
	arg0->unk18_5 = arg1;
}

void func_800EC358(Unk80132ED0* arg0, s32 arg1) {
	arg0->unkC = arg1;
}

void func_800EC360(Unk80132ED0* arg0, s32 arg1) {
	arg0->unk14 = arg1;
}

void func_800EC368(Unk80132ED0* arg0, s32 arg1) {
	arg0->unk16 = arg1;
}

void func_800EC370(Unk80132ED0* arg0, s16* arg1)
{
	arg1[0] = (arg0->unk0->unk4);
	arg1[1] = (arg0->unk0->unk6);
	arg1[2] = (arg0->unk0->unk8);
}

void func_800EC398(Unk80132ED0* arg0, f32* arg1) {
	ml_vec3s_to_vec3f(arg1, &arg0->unk0->unk4);
}

CallbackTable* func_800EC3C4(Unk80132ED0* arg0)
{
	return arg0->unk8();
}

ImageStruct* func_800EC3E8(Unk80132ED0* arg0)
{
	if ((arg0->unk14 == 0) || (arg0->unk14 == 0xFFFF)) {
		return NULL;
	}
	return asset_load((s32)arg0->unk14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC75C.s")

void func_800EC7D4(Unk80132ED0* arg0, GraphicsBuffers* arg1)
{
	func_8010A79C(func_80106790(arg0), arg1);
}

int func_800EC800(Unk80132ED0* arg0)
{
	return (arg0->unk18_16) && arg0->unk14;
}

void func_800EC828(void) {
	D_80132ED0[0x967]--;
	if (D_80132ED0[0x967] < 0x6B7)
	{
		D_80132ED0[0x967] = 0x7FFF;
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC854.s")
