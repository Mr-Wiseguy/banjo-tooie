#include "ch/newmumbo.h"

#define MUMBO_DATA(arg0) ((MumboActorData*)(arg0->actorData))

extern s32 D_80801990_chnewmumbo[];
extern s32 D_8080199C_chnewmumbo[];
extern s32 D_808019A8_chnewmumbo[];
extern s32 D_808019B4_chnewmumbo[];
extern s32 D_808019C0_chnewmumbo[];
extern s32 D_808019C8_chnewmumbo[];
extern s32 D_808019D4_chnewmumbo[];
extern s32 D_808019E4_chnewmumbo[];
extern f32 D_80801AD4_chnewmumbo[3];
extern f32 D_80801AE0_chnewmumbo[];
extern f32 D_80801AF0_chnewmumbo[];
extern f32 D_80801AFC_chnewmumbo[];
extern f32 D_80801B08_chnewmumbo[3];

extern f32 D_808019F4_chnewmumbo;
extern f32 D_80801A00_chnewmumbo[3];
extern f32 D_80801A0C_chnewmumbo[];
extern f32 D_80801AB8_chnewmumbo[];
extern f32 D_80801AC8_chnewmumbo[];
extern ActorData D_80801B14_chnewmumbo;

void func_80800000_chnewmumbo(Actor*, s32, s32);
void func_8080009C_chnewmumbo(Actor*);
void func_80800264_chnewmumbo(Actor*, s32);
void func_8080073C_chnewmumbo(Actor*, s32);
void func_808014FC_chnewmumbo(Actor*, s32, s32);

void func_80800000_chnewmumbo(Actor* arg0, s32 arg1, s32 arg2)
{
	NewMumboStruct* temp_v0;

	temp_v0 = (NewMumboStruct*)func_80100094(arg0, 0U);
	switch (temp_v0->unk24)
	{
	case 0:
		_capod_entrypoint_2(arg0->unk0, 0xAU, 0);
	case 1:
		_capod_entrypoint_8(1);
		temp_v0->unk24 = 2;
		_gcdialogcamera_entrypoint_6(arg0->unk0);
		_gcdialogcamera_entrypoint_8();
	case 2:
		_capod_entrypoint_7(arg1, arg2);
		return;
	}
}

void func_8080009C_chnewmumbo(Actor* arg0) {
	NewMumboStruct* temp_v0;

	temp_v0 = (NewMumboStruct*)func_80100094(arg0, 0U);
	if (temp_v0->unk24 != 0) {
		_capod_entrypoint_3(0);
		temp_v0->unk24 = 0;
	}
}

void func_808000DC_chnewmumbo(Actor* arg0, u32 arg1, u32 arg2)
{
	arg0->unk74_30 = 1;
	_subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x10U);
}

GameFlag func_8080011C_chnewmumbo(void) {

	if (flag_getValue(0x9C5) == 0) {
		return 0;
	}
	switch (map_getCurrent())
	{
		case MAP_B7_MT_MUMBO:
			return FLAG_37F_PAID_GLOWBO_MUMBO_MT;
		case MAP_D9_GGM_MUMBO:
			return FLAG_380_PAID_GLOWBO_MUMBO_GGM;
		case MAP_176_WW_MUMBO:
			return FLAG_381_PAID_GLOWBO_MUMBO_WW;
		case MAP_EF_JRL_MUMBO:
			return FLAG_382_PAID_GLOWBO_MUMBO_JRL;
		case MAP_171_TDL_MUMBO:
			return FLAG_383_PAID_GLOWBO_MUMBO_TDL;
		case MAP_172_GI_MUMBO:
			return FLAG_387_PAID_GLOWBO_MUMBO_GI;
		case MAP_134_HP_MUMBO:
			return FLAG_384_PAID_GLOWBO_MUMBO_HFP;
		case MAP_13E_CCL_MUMBO:
		case MAP_13F_CCL_MINGY_JONGO:
			return FLAG_385_PAID_GLOWBO_MUMBO_CCL;
		case MAP_156_IOH_MUMBO:
			return FLAG_386_PAID_GLOWBO_MUMBO_IoH;
		default:
			return 0;
	}
}

void func_80800210_chnewmumbo(s32* arg0) {
	func_8008F8B0();
	func_8008F8D8(1);
	func_8008F938(1);
	func_8008F904(func_8010D5DC, *arg0);
	func_8008F990(D_80801A0C_chnewmumbo, 200.0f);
}

void func_80800264_chnewmumbo(Actor* arg0, s32 arg1) {
	NewMumboStruct* temp_v1;

	temp_v1 = (NewMumboStruct*)func_80100094(arg0, 0U);
	if ((arg0->unk70_10) == 6)
	{
		arg0->unk74_0 = 1;
	}
	if (flag_getValue(FLAG3_9C6_UNK) != 0)
	{
		func_80102424(arg0, arg1);
		switch (arg0->unk70_10)
		{
		case 1:
			temp_v1->unk1 = 1;
			temp_v1->unk2 = 0;
			return;
		case 2:
		case 3:
		case 4:
			func_80800210_chnewmumbo((s32*)arg0);
			return;
		case 5:
			func_8080073C_chnewmumbo(arg0, activePlayer_includedInTransformMask(1));
			func_80800000_chnewmumbo(arg0, 2, 1);
			return;
		case 6:
			arg0->unk74_0 = 1;
			arg0->unk7A_9 = 3;
			arg0->unk7A_12 = 7;
			arg0->unk6C_0 = 0;
			arg0->unk70_22 = 1;
			return;
		case 7:
			arg0->unk74_0 = 1;
			if (func_800DA9E4(FLAG_07D_FTT_MUMBO, 1) == 0)
			{
				func_808000DC_chnewmumbo(arg0, 0x11D6U, 7U);
			}
			else
			{
				func_808000DC_chnewmumbo(arg0, 0x11E4U, 7U);
			}
			_suexpression_entrypoint_12(func_80100094(arg0, 1U), 60.0f, 0.0f);
			return;
		case 8:
			if (inventory_getValue(0x48) > 0)
			{
				func_808000DC_chnewmumbo(arg0, 0x11D7U, 0x46U);
				return;
			}
			func_808000DC_chnewmumbo(arg0, 0x11DAU, 7U);
			return;
		case 18:
			temp_v1->unk1 = 0;
			ml_vec3f_copy(arg0->position, &D_808019F4_chnewmumbo);
			return;
		case 19:
			temp_v1->unk2 = 1;
			temp_v1->unk1 = 0;
			return;
		case 14:
			func_8080009C_chnewmumbo(arg0);
			func_800904C8(0x8D);
			func_80090590(0x3C, arg0->position);
			temp_v1->unk0 = 1;
			if (func_800DA9E4(FLAG_429_FTT_MUMBO_USED, 1) == 0)
			{
				func_80800000_chnewmumbo(arg0, 5, 1);
				func_808000DC_chnewmumbo(arg0, 0x11E6U, 0xFU);
				return;
			}
			break;
		case 10:
		case 11:
			temp_v1->unk1 = 1;
			temp_v1->unk2 = 0;
			func_8080009C_chnewmumbo(arg0);
			break;
		}
	}
}

s32 func_808004E8_chnewmumbo(Actor* arg0, s32 arg1, s32 arg2)
{
	u32 temp2;
	u32 temp;
	NewMumboStruct* sp24;

	switch (arg1)
	{
		case 0x32:
			switch (arg0->unk70_10)
			{
			case 2:
				func_80800264_chnewmumbo(arg0, 5);
				break;
			case 3:
				if (flag_getValue(func_8080011C_chnewmumbo()) != 0)
				{
					func_8080073C_chnewmumbo(arg0, 1);
					func_80800000_chnewmumbo(arg0, 2, 1U);
					func_808000DC_chnewmumbo(arg0, 0x11DBU, 0x4EU);
				}
				else
				{
					func_80800000_chnewmumbo(arg0, 2, 1U);
					func_8080073C_chnewmumbo(arg0, 1);
					func_80800264_chnewmumbo(arg0, 7);
				}
				break;
			case 4:                                     /* switch 2 */
				func_80800000_chnewmumbo(arg0, 2, 1U);
				func_808000DC_chnewmumbo(arg0, 0x11DBU, 0x4EU);
				break;
			}
			break;
		case EVENT_2E_ACTOR_DIALOG_ENDED:
			func_808014FC_chnewmumbo(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
			break;
		case 0x52:
			_gcdialogcamera_entrypoint_3(&D_80801AB8_chnewmumbo, arg0->scale);
			if ((s32)arg0->unk70_10 < 0xE)
			{
				_gcdialogcamera_entrypoint_4(&D_80801AC8_chnewmumbo);
			}
			break;
		case 0x57:
			temp2 = (arg2 & 0xFFFF);
			temp = (arg2 & 0xFFFF0000) >> 0x10;

			if (_gcdialogcamera_entrypoint_0(temp2, temp) != 0)
			{
				func_80800000_chnewmumbo(arg0, temp2, temp);
			}
			break;
		case EVENT_1F_ACTOR_ONSCREEN:
			sp24 = (NewMumboStruct*)func_80100094(arg0, 0U);
			func_801015D0(arg0);
			if (sp24->unk1 != 0)
			{
				func_800DF744(5, 1);
			}
			else
			{
				func_800DF744(5, 0);
			}
			if (sp24->unk2 != 0)
			{
				func_800DF744(4, 1);
			}
			else
			{
				func_800DF744(4, 0);
			}
			break;
		default:
			return 0;
	}
	return 1;
}

void func_8080073C_chnewmumbo(Actor* arg0, s32 arg1)
{
	if (!(arg0->unk64_19))
	{
		if (arg1 != 0)
		{
			func_800F7B9C(_character_findCharOfTransform(TRANSFORM_1_BK), 0x8DU);
		}
		func_800F8300(character_getActiveIndex(), 2, arg0->position);
		arg0->unk64_19 = 1;
	}
}

void func_808007B0_chnewmumbo(Actor* arg0)
{
	if (arg0->unk64_19)
	{
		func_800F82D4(character_getActiveIndex(), 0);
		arg0->unk64_19 = 0;
	}
}

void func_808007FC_chnewmumbo(Actor* arg0, s32 arg1)
{
	NewMumboStruct* temp_v0;

	temp_v0 = (NewMumboStruct*)func_80100094(arg0, 0U);
	if (temp_v0->unk0 == 0)
	{
		func_80101808(arg0, func_801017D0);
		if ((temp_v0->unk1 != 0) && (arg0->unk7C_12)) {
			func_800DBEFC(arg0->unk0->unk4, 0xB, temp_v0->unk4);
		}
	}
}

void func_80800878_chnewmumbo(Actor* arg0)
{
    func_80800264_chnewmumbo(arg0,0xE);
}

void func_80800898_chnewmumbo(Actor* arg0)
{
	s32 index;
	for (index = 0; index < 3; index++)
	{
		if (D_80801A00_chnewmumbo[index] != arg0->position[index])
		{
			arg0->position[index] += ((D_80801A00_chnewmumbo[index] - arg0->position[index]) * 0.25f);
		}
	}
	if (arg0->rotation[1] != 0.0f)
	{
		arg0->rotation[1] = (f32)(arg0->rotation[1] * 0.25f);
	}
	if (arg0->rotation[0] != 0.0f)
	{
		arg0->rotation[0] = (f32)(arg0->rotation[0] * 0.25f);
	}
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_8080092C_chnewmumbo.s")
#else
void func_8080092C_chnewmumbo(Actor* arg0)
{
	f32 sp6C[3] = D_80801AD4_chnewmumbo;
	f32 sp60[3];
	NewMumboStruct* sp5C;
	s32 temp_v0;
	f32 sp4C[3];
	Actor* temp_v0_5;
	f32 sp44;
	f32 sp38[3];
	f32 sp2C[3];

	sp5C = (NewMumboStruct*)func_80100094(arg0, 0U);
	if (func_800C0638() != 0)
	{
		MUMBO_DATA(arg0)->unkC = 1.5f;
	}
	else if (MUMBO_DATA(arg0)->unkC > 0.0f)
	{
		MUMBO_DATA(arg0)->unkC -= time_getDelta();
	}

	if ((flag_getValue(func_8080011C_chnewmumbo()) == 0) && (MUMBO_DATA(arg0)->unkC <= 0.0f))
	{
		inventory_showValue(0x48);
	}
	if (func_8010D278() == 0xD)
	{
		func_8010D254(sp4C);
		temp_v0 = _character_findCharOfTransform(TRANSFORM_1_BK);
		if (func_800F6D24(temp_v0) != 0)
		{
			func_800F8804(temp_v0, sp4C);
		}
	}
	if (sp5C->unk0 == 0)
	{
		func_8008FB10(arg0->position, arg0->scale * 150.0f, arg0->scale * -75.0f, arg0->scale * 100.0f);
	}
	func_8010D254(sp60);
	_suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0U);
	switch (arg0->unk70_10)
	{
	case 19:
		switch (activePlayer_getTransformationBit())
		{
		case 0x1:
			if (!(arg0->unk74_30) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x2EEU, 0x5AU, 6) != 0)) {
				func_80800264_chnewmumbo(arg0, 4);
			}
			return;
		case 0x200:
		case 0x400:
			if (!(arg0->unk74_30) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x2EEU, 0x5AU, 6) != 0)) {
				func_80800000_chnewmumbo(arg0, 2, 1);
				func_808000DC_chnewmumbo(arg0, 0x11EBU, 0xFU);
				return;
			}
			break;
		}
		break;
	case 1:
		arg0->unk74_0 = 2;
		if (func_80101E14(arg0, 0.3f) != 0)
		{
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801990_chnewmumbo);
		}
		else if (func_80101E14(arg0, 0.7f) != 0)
		{
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080199C_chnewmumbo);
		}
		switch (activePlayer_getTransformationBit())
		{
		case 0x1:
		case 0x200:
		case 0x400:
			if (_subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 0x1F4U, 0x5AU, 6) != 0)
			{
				func_80800264_chnewmumbo(arg0, 2);
				return;
			}
		}
		break;
	case 2:
		if (func_80101E14(arg0, 0.3f) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801990_chnewmumbo);
			return;
		}
		if (func_80101E14(arg0, 0.7f) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080199C_chnewmumbo);
			return;
		}
		break;
	case 5:
		if (func_80101E14(arg0, 0.999f) != 0) {
			func_80800264_chnewmumbo(arg0, 6);
			return;
		}
		break;
	case 6:
		if (func_80101E14(arg0, 0.2f) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808019A8_chnewmumbo);
		}
		if (arg0->unk6C_0 < 0x64U)
		{
			arg0->unk6C_0++;
			if (arg0->unk6C_0 < 0x14U)
			{
				arg0->unk7A_9 = 3;
			}
			else if (arg0->unk6C_0 < 0x28U)
			{
				arg0->unk7A_9 = 2;
			}
			else if (arg0->unk6C_0 < 0x3CU)
			{
				arg0->unk7A_9 = 1;
			}
			else
			{
				arg0->unk7A_9 = 0;
				arg0->unk7A_12 = 1;
			}
		}
		else if (rand_percentChance(0.3f) != 0 && arg0->unk7A_9 < 3)
		{
			arg0->unk7A_12 = 1;
		}
		else if (rand_percentChance(0.05f) != 0 && arg0->unk7A_9 > 0)
		{
			arg0->unk7A_12 = 2;
		}
		if (func_80101E14(arg0, 0.999f) != 0)
		{
			switch (activePlayer_getTransformationBit())
			{
			case 0x1:
				func_80800264_chnewmumbo(arg0, 7);
				return;
			case 0x200:
			case 0x400:
				func_808007B0_chnewmumbo(arg0);
				func_808000DC_chnewmumbo(arg0, 0x11EBU, 0xFU);
				func_80800264_chnewmumbo(arg0, 0xB);
				return;
			default:
				func_80800264_chnewmumbo(arg0, 0xB);
				return;
			}
		}
		break;
	case 7:
		if (func_80101E14(arg0, 0.999f) != 0)
		{
			func_80800264_chnewmumbo(arg0, 8);
			return;
		}
		break;
	case 8:
		if (flag_getValue(func_8080011C_chnewmumbo()) == 0)
		{
			switch (sp5C->unk3)
			{

			case 0:
				return;
			case 1:
				func_808007B0_chnewmumbo(arg0);
				func_80090658(1);
				sp5C->unk3 = 2U;
				return;
			case 2:
				if ((arg0->unk7C_12) && (func_800902E4(arg0->position, 750.0f, 0x29F, &arg0) != 0) && (func_8008FE14() == 0x29F) && (func_80090818() != 0))
				{
					arg0->unk3C = func_8008FDEC();
					func_80090768(sp5C->unk4);
					sp5C->unk3 = 3U;
					return;
				}
				break;
			case 3:
				temp_v0_5 = func_80106790(arg0->unk3C);
				ml_vec3f_copy((f32*)&temp_v0_5->actorData[0], sp5C->unk4);
				temp_v0_5->unk74_30 = 1;
				temp_v0_5->unk64_19 = 1;
				sp5C->unk3 = 4U;
				func_8080073C_chnewmumbo(arg0, 1);
				func_80090658(0);
				return;
			case 4:
				func_80800264_chnewmumbo(arg0, 0xD);
				sp5C->unk3 = 0U;
				return;
			}
		}
		break;
	case 13:
		if (func_80101E14(arg0, 0.7f) != 0)
		{
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808019C0_chnewmumbo);
			_chjujubagfx_entrypoint_2();
		}
		if (func_80101E14(arg0, 0.999f) != 0)
		{
			func_800FC6B0(0x10U);
			func_80800264_chnewmumbo(arg0, 0x11);
			func_80800000_chnewmumbo(arg0, 2, 1);
			flag_setValueTrue(func_8080011C_chnewmumbo());
			inventory_addValue(0x48, -1);
			return;
		}
		break;
	case 17:
		if (func_80101E14(arg0, 0.05f) != 0)
		{
			flag_setValueTrue(FLAG3_9F3_UNK);
			return;
		}
		if (func_80101DDC(arg0) != 0) {
			func_80800264_chnewmumbo(arg0, 0x12);
			return;
		}
		if (func_80101E14(arg0, 0.87f) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808019B4_chnewmumbo);
			return;
		}
		if (func_80101E14(arg0, 0.76f) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808019C8_chnewmumbo);
			return;
		}
		if (func_80101E4C(arg0, D_80801AE0_chnewmumbo) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808019D4_chnewmumbo);
			return;
		}
		break;
	case 18:
		if (func_80101E14(arg0, 0.79f) != 0) {
			sp5C->unk2 = 1;
			return;
		}
		if (func_80101E14(arg0, 0.999f) != 0) {
			func_80800878_chnewmumbo(arg0);
			return;
		}
		if (func_80101E4C(arg0, D_80801AF0_chnewmumbo) != 0) {
			_subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808019E4_chnewmumbo);
			return;
		}
		break;
	case 14:
		if (func_8010C9FC(arg0->position, 0x1C2, 0x1F4, 0x96) == 0) {
			func_80800264_chnewmumbo(arg0, 0xF);
			return;
		}
		break;
	case 15:
		if ((func_800EFED0(D_80801AFC_chnewmumbo, D_80801B08_chnewmumbo, sp60) != 0) && (func_80090248() != 0))
		{
			func_8010D254(sp38);
			func_800F7B9C(_character_findCharOfTransform(TRANSFORM_1_BK), 0x3DU);
			sp5C->unk0 = 0U;
			func_80800264_chnewmumbo(arg0, 0x10);
			ml_vec3f_copy(arg0->position, sp38);
			func_808007B0_chnewmumbo(arg0);
			return;
		}
		break;
	case 16:
		arg0->rotation[1] = func_80013728(func_80090010());
		arg0->rotation[0] = func_8008FEF0();
		func_80800264_chnewmumbo(arg0, 9);
		return;
	case 9:
		func_80800898_chnewmumbo(arg0);
		if (func_80101E14(arg0, 0.21f) != 0)
		{
			sp5C->unk2 = 0;
		}
		if (func_80101E14(arg0, 0.83f) != 0)
		{
			sp5C->unk1 = 1;
		}
		if (func_80101DDC(arg0) != 0)
		{
			func_80800264_chnewmumbo(arg0, 0xA);
			_suexpression_entrypoint_12(func_80100094(arg0, 1U), 0.0f, 0.0f);
			return;
		}
		break;
	case 10:
		func_8010D254(sp2C);
		func_80800898_chnewmumbo(arg0);
		func_80800264_chnewmumbo(arg0, 0xB);
		return;
	case 11:
		switch (activePlayer_getTransformationBit())
		{
		case 0x1:
			if (!(arg0->unk74_30) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x2EEU, 0x5AU, 6) != 0))
			{
				func_80800264_chnewmumbo(arg0, 3);
				return;
			}
			break;
		case 0x200:
		case 0x400:
			if (!(arg0->unk74_30) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x2EEU, 0x5AU, 6) != 0))
			{
				func_80800000_chnewmumbo(arg0, 2, 1);
				func_808000DC_chnewmumbo(arg0, 0x11EBU, 0xFU);
			}
			break;
		}
		break;
	}
}
#endif

void func_808014FC_chnewmumbo(Actor* arg0, s32 arg1, s32 arg2)
{
	u32 temp_t1;
	u32 temp_t2;
	NewMumboStruct* temp_v0;

	temp_v0 = (NewMumboStruct*)func_80100094(arg0, 0U);
	arg0->unk74_30 = 0;
	switch (arg1)
	{
	case 0x11D7:
		if (arg2 > 0)
		{
			func_808000DC_chnewmumbo(arg0, 0x11D8U, 7U);
			return;
		}
		func_808000DC_chnewmumbo(arg0, 0x11D9U, 7U);
		return;
	case 0x11D9:                                    /* switch 1 */
		ml_vec3f_copy((f32*)arg0->actorData, arg0->position);
		func_808007B0_chnewmumbo(arg0);
		func_80800264_chnewmumbo(arg0, 0xA);
		return;
	case 0x11DA:                                    /* switch 1 */
		ml_vec3f_copy((f32*)arg0->actorData, arg0->position);
		func_808007B0_chnewmumbo(arg0);
		func_80800264_chnewmumbo(arg0, 0xA);
		return;
	case 0x11D8:                                    /* switch 1 */
		temp_v0->unk3 = 1;
		return;
	case 0x11EB:                                    /* switch 1 */
		func_8080009C_chnewmumbo(arg0);
		return;
	case 0x11DB:
		switch (arg0->unk70_10)
		{
		case 4:
			if (arg2 > 0)
			{
				func_80800878_chnewmumbo(arg0);
				return;
			}
			func_808000DC_chnewmumbo(arg0, 0x11EAU, 0xFU);
			return;
		case 3:

			if (arg2 > 0)
			{
				func_80800000_chnewmumbo(arg0, 2, 1);
				func_80800264_chnewmumbo(arg0, 0x11);
				return;
			}
			break;
		default:
			return;
		}
		func_808000DC_chnewmumbo(arg0, 0x11EAU, 0xFU);
		return;
	case 0x11EA:
		switch (arg0->unk70_10)
		{
		case 3:
			func_80800264_chnewmumbo(arg0, 0xB);
			func_808007B0_chnewmumbo(arg0);
			return;
		case 4:
			func_8080009C_chnewmumbo(arg0);
			func_808007B0_chnewmumbo(arg0);
			func_80800264_chnewmumbo(arg0, 0x13);
			return;
		}
		break;
	case 0x11E6:
		func_8080009C_chnewmumbo(arg0);
		break;
	}
}

void chnewmumbo_entrypoint_0(Actor* arg0, f32 arg1[3])
{
	ml_vec3f_copy(arg1, ((NewMumboStruct*)func_80100094(arg0, 0U))->unk4);
}

void func_8080172C_chnewmumbo(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

void func_80801760_chnewmumbo(Actor* arg0)
{
	NewMumboStruct* sp2C;

	sp2C = (NewMumboStruct*)func_80100094(arg0, 0U);
	ml_vec3f_copy(arg0->position, &D_80801A00_chnewmumbo);
	arg0->scale = 0.5f;
	_suexpression_entrypoint_7(arg0, 1U, 0x10U);
	if (func_8010D278() == 0xD)
	{
		sp2C->unk0 = 1;
		func_80800264_chnewmumbo(arg0, 0xF);
	}
	else
	{
		sp2C->unk0 = 0;
		if ((flag_getValue(func_8080011C_chnewmumbo()) != 0) || (_glcutDll_entrypoint_20() != 0))
		{
			ml_vec3f_copy(arg0->position, &D_808019F4_chnewmumbo);
			func_80800264_chnewmumbo(arg0, 0x13);
		}
		else if (flag_getValue(FLAG_07D_FTT_MUMBO) != 0)
		{
			func_80800264_chnewmumbo(arg0, 0xA);
		}
		else
		{
			func_80800264_chnewmumbo(arg0, 1);
		}
	}
	arg0->rotation[0] = 0.0f;
}

ActorData* chnewmumbo_entrypoint_1(void) {
	return &D_80801B14_chnewmumbo;
}
