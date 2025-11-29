#ifndef __CORE2_1ECE0B0_H__
#define __CORE2_1ECE0B0_H__

#include "../../src/overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
#include "transformations.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7AB30.h"

#include "overlays/ba/anim.h"
#include "overlays/ba/key.h"
#include "overlays/ba/drone.h"
#include "ba/hold.h"

#include <ultra64.h>
void func_800F497C(s32);
void func_800F49D4(s32 arg0, void* arg1, s32 arg2);
void func_800F4A58(s32,s32,f32);
s32 func_800F4B4C(s32);
s32 func_800F4B8C(u32, u32, s32);
s32 func_800F4BB8(u32, u32, s32);
void func_800F4CC0(s32);
void func_800F4CEC(s32, u32);
PlayerState* func_800F53D0(s32 arg0);
PlayerState* func_800F53E4(s32 arg0);
//Get the character control index
u32 func_800F54E4(void);
s32 func_800F5578(s32);
Unk80132ED0* func_800F56D8(s32 arg0);
void func_800F5A00(s32, f32[3]);
void func_800F5D44(s32, f32*);
f32 func_800F5F24(u32);
s32 func_800F5FE0(s32);
void func_800F608C(s32, s32);
void func_800F6388(s32, s32);
void func_800F63E0(s32, u32);
s32 func_800F6438(u32);
s32 func_800F6774(u32);

typedef enum
{
	ALLOW_BIGTREX = 1 << (TRANSFORM_13_BIGTREX + 0x1F),
	ALLOW_SMALLTREX = 1 << (TRANSFORM_12_SMALLTREX + 0x1F),
	ALLOW_CLOCKWORK = 1 << (TRANSFORM_11_CLOCKWORK + 0x1F),
	ALLOW_VAN = 1 << (TRANSFORM_10_VAN + 0x1F),
	ALLOW_PLUNGER = 1 << (TRANSFORM_F_PLUNGER + 0x1F),
	ALLOW_GOLDENGOLIATH = 1 << (TRANSFORM_E_GOLDENGOLIATH + 0x1F),
	ALLOW_MUMBO = 1 << (TRANSFORM_D_MUMBO + 0x1F),
	ALLOW_SUB = 1 << (TRANSFORM_C_SUB + 0x1F),
	ALLOW_KAZOOIE = 1 << (TRANSFORM_B_KAZOOIE + 0x1F),
	ALLOW_BANJO = 1 << (TRANSFORM_A_BANJO + 0x1F),
	ALLOW_FIRSTPERSON = 1 << (TRANSFORM_9_FIRSTPERSON + 0x1F),
	ALLOW_STONY = 1 << (TRANSFORM_8_STONY + 0x1F),
	ALLOW_WASHINGMACHINE = 1 << (TRANSFORM_7_WASHINGMACHINE + 0x1F),
	ALLOW_BEE = 1 << (TRANSFORM_6_BEE + 0x1F),
	ALLOW_SNOWBALL = 1 << (TRANSFORM_2_SNOWBALL + 0x1F),
	ALLOW_BK = 1 << (TRANSFORM_1_BK + 0x1F)
}AllowedTransformation;

//Does the character match the given transformation type
s32 func_800F64A4(s32 characterIndex, AllowedTransformation transformationType);
void func_800F7700(u32, s32, f32*);
//The moving object is moved towards/away from the target
void func_800F78EC(s32 moving, f32* target, f32 verticalSpeed, f32 horizontalSpeed);
void func_800F7B9C(s32, u32);
void func_800F7BC8(s32, s32, Unk80132ED0*);
s32 func_800F8004(s32);
void func_800F80E4(s32, u32);
void func_800F822C(s32, f32, f32);
void func_800F8294(s32, f32*);
void func_800F82C0(s32);
void func_800F82D4(s32, s32);
void func_800F832C(s32, f32*);
s32 func_800F8B64(void);
void func_800F8850();
void func_800F8DD8();
void func_800F8E08();
void func_800F911C(s32);
// Might take in a PlayerState *
void func_800F9BC4(void);


#endif // __CORE2_1ECE0B0_H__
