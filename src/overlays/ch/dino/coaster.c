#include "ch/dino/coaster.h"

extern s32 D_80800468_chdinocoaster;
extern ActorData D_808004E0_chdinocoaster;
extern u32 D_80800544_chdinocoaster;

ActorData* chdinocoaster_entrypoint_0()
{
    return &D_808004E0_chdinocoaster;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_8080000C_chdinocoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_80800064_chdinocoaster.s")

s32 func_808001C8_chdinocoaster(Actor* arg0, s32 arg1, s32 arg2)
{
	f32 sp2C[3];
	s16* split = (s16*)&arg2;
	switch (arg1)
	{
		case EVENT_2E_ACTOR_DIALOG_ENDED:
			func_80101FDC(arg0, 0x14U);
			actor_enableCollision((s32)arg0);
			if (split[0] == 0x17B8)
			{
				func_8009032C(0x20);
			}
			break;
		case 0x38:
			func_80101074(&D_80800468_chdinocoaster);
			return 0xA;
		case 0x52:
			ml_vec3f_assign_value(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
			_gcdialogcamera_entrypoint_3(&D_80800544_chdinocoaster, arg0->scale);
			_gcdialogcamera_entrypoint_5(sp2C);
			break;
		case EVENT_95_ACTOR_SPAWNED:
			arg0->unk64_20 = 0;
		default:
			return _sucoaster_entrypoint_21(arg0, arg1, arg2);
	}
	return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_808002CC_chdinocoaster.s")
