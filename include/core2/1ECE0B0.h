#ifndef __CORE2_1ECE0B0_H__
#define __CORE2_1ECE0B0_H__

#include "ba/playerstate.h"
#include "player.h"
#include "vector.h"
#include "ba/yaw.h"
#include "transformations.h"
#include "core2/1E82660.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7AB30.h"
#include "core2/1EB2840.h"
#include "core2/1ECD170.h"
#include "core2/1E691A0.h"
#include "core2/1E78BF0.h"
#include "core2/1EC8070.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1EDA900.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E72EA0.h"
#include "core2/1E71B00.h"
#include "core2/1E72180.h"
#include "core2/1E67DA0.h"
#include "core2/1E77A20.h"
#include "core2/1E75620.h"
#include "core2/1E78170.h"
#include "core2/1E76360.h"
#include "core2/1E80A70.h"
#include "core2/1E6B700.h"
#include "core2/1E68670.h"
#include "core2/1EAE6C0.h"
#include "ba/motor.h"
#include "ba/shoes.h"
#include "ba/anim.h"
#include "ba/key.h"
#include "ba/stick.h"
#include "ba/drone.h"
#include "ba/cough.h"
#include "pl/camera.h"
#include "ba/invisible.h"
#include "ba/hold.h"
#include "bs/babykaz.h"
#include "ba/snowball.h"
#include "pl/su.h"
#include "ba/data.h"

#include "su/restart.h"
#include "gl/cutDll.h"

#include <ultra64.h>

#include "core2/1E75710.h"

typedef enum
{
	ALLOW_TREXLARGE = 1 << (TRANSFORM_13_TREXLARGE + 0x1F),
	ALLOW_TREXSMALL = 1 << (TRANSFORM_12_TREXSMALL + 0x1F),
	ALLOW_CLOCKWORK = 1 << (TRANSFORM_11_CLOCKWORK + 0x1F),
	ALLOW_VAN = 1 << (TRANSFORM_10_VAN + 0x1F),
	ALLOW_DETONATOR = 1 << (TRANSFORM_F_DETONATOR + 0x1F),
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
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    f32 unk4[3];
    f32 unk10[3];
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    u8 unk20;
    u8 unk21;
    s16 unk22;
    f32 unk24[3];
    f32 unk30[3];
} unkStruct800F88A0;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[0x3A];
} UnkStruct800F8AA4;
typedef struct {
    u8 unk0;
    u8 pad1[0x21];
    s16 unk22;
    u8 pad24[0x18];
} unkStruct800F8F3C;

typedef struct {
    u8 unk0;
    s8 unk1;
    s8 unk2;
} unkStructD_80135520;

typedef enum
{
    SPLIT_STATE_INVALID = 0,
    SPLIT_STATE_NOTSPLIT = 1,
    SPLIT_STATE_SPLIT = 2,
    SPLIT_STATE_TALON_TORPEDO = 3
}SPLITUP_STATUS;

typedef struct {
    u8 splitStatus;
    u8 unk1;
    u8 pad2[2];
    u8 unk4;
    u8 unk5;
    u8 pad6[0xE];
    f32 unk14;
    u8 pad18[0xC];
    s32 unk24;
} unkStructD_801354F8;

typedef struct {
    PlayerState* unk0[8];
    u8 unk20[8];
    PlayerState* unk28[2];
    u8 pad30[0x48 - 0x30];
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 pad4B[0x50 - 0x4B];
    s16 unk50;
    s16 unk52;
} Unk80135490;

void func_800F48BC(s32, f32*);
void func_800F497C(s32);
void func_800F49D4(s32 arg0, void* arg1, s32 arg2);
void func_800F4A58(s32,s32,f32);
void func_800F4AC0(s32, s32, f32);
void func_800F4AF4(s32, s32);
void func_800F4B20(s32);
s32 func_800F4B4C(s32);
s32 func_800F4B8C(u32, u32, s32);
s32 func_800F4BB8(u32, u32, s32);
s32 func_800F4BE4(s32);
void func_800F4CC0(s32);
void func_800F4CEC(s32, u32);
void character_affectCurrentHealth(s32, s32);
void func_800F4F34(s32, f32*, f32, f32);
PlayerState* character_getPlayerState(s32 arg0);
PlayerState* character_getPlayerStateBounded(s32 arg0);
TransformationId character_getTransform(s32);
s32 character_getTransformBit(s32);
//Get the character control index
u32 character_getActiveIndex(void);
s32 character_getCurrentHealth(s32);
s32 character_getMaxHealth(s32);
Unk80132ED0* func_800F55D0(s32);
f32 character_getGroundHeight(s32);
s32 func_800F56AC(s32);
Unk80132ED0* func_800F56D8(s32 arg0);
void func_800F57F0(s32, f32*);
s32 character_getMaxCharacters();
void character_getCoords(s32, f32[3]);
void func_800F5A2C(s32, s32, f32[3]);
void character_getCoords3s(s32, s32[3]);
f32 func_800F5AE0(s32);
s32 func_800F5B0C(s32);
void func_800F5D44(s32, f32*);
void func_800F5D70(s32, f32*);
void func_800F5D9C(s32, f32*);
s32 func_800F5EF8(s32);
f32 func_800F5F24(u32);
s32 func_800F5FA8(s32);
s32 func_800F5FE0(s32);
void func_800F608C(s32, s32);
s32 character_createNew(s32);
void func_800F6388(s32, s32);
void func_800F63E0(s32, u32);
s32 func_800F6438(u32);
s32 func_800F6478(s32);
s32 character_includedInTransformMask(s32 characterIndex, AllowedTransformation transformationType);
s32 func_800F651C(u32);
s32 func_800F66BC(s32, f32*, f32);
s32 func_800F65D0(s32);
s32 func_800F66F0(u32);
int func_800F6720();
int func_800F6774(u32);
//Does the character match the given transformation type
s32 func_800F68B8(s32);
s32 func_800F690C();
s32 func_800F693C(s32);
s32 character_existsAtIndex(s32);
s32 func_800F6C1C(s32 arg0);
s32 character_isStable(s32);
s32 func_800F6C88(s32);
s32 func_800F6CC8(u32);
s32 func_800F6D24(s32);
s32 func_800F6DE0(f32*);
s32 func_800F70BC(u32);
s32 func_800F7150(s32);
s32 func_800F71D4(u32);
s32 func_800F7200(s32 arg0, f32* arg1, f32 arg2, s32 arg3, s32 arg4);
int func_800F72DC(u32);
void func_800F759C(s32);
void func_800F7664(u32, s32, s32);
s32 func_800F7700(u32, s32, f32*);
s32 func_800F7750(s32, f32[3], f32, f32, s32);
void func_800F77E8(u32, f32[3]);
s32 func_800F7874(s32, Unk80132ED0*, f32[3]);
//The moving object is moved towards/away from the target
s32 func_800F78EC(s32 moving, f32* target, f32 verticalSpeed, f32 horizontalSpeed);
s32 func_800F798C(s32 arg0, s32 arg1, s32 arg2);
s32 func_800F7B1C(s32, f32*, f32, f32);
s32 func_800F7B9C(s32, u32);
void func_800F7BC8(s32, s32, Unk80132ED0*);
void func_800F7C0C(s32, s32, f32);
s32 func_800F7C58(s32 arg0, s32 arg1, s32 arg2);
void func_800F7C9C(u32, s32, s32, s32);
void func_800F7CF4(s32, s32, f32*);
s32 func_800F7E3C(s32, s32);
void func_800F7E64(s32, TransformationId);
void func_800F7F50(u32, f32*, f32*, f32, s32, s32);
void func_800F7F98(u32, s32);
int func_800F8004(s32);
int func_800F8088(s32);
void func_800F80D8(u32);
void func_800F80E4(s32, u32);
void func_800F8128(s32);
void func_800F822C(s32, f32, f32);
void func_800F8268(s32, s32, s32);
void func_800F8294(s32, f32*);
void func_800F82C0(s32);
void func_800F82D4(s32, s32);
void func_800F8300(s32, s32, f32*);
void func_800F832C(s32, f32*);
void func_800F8418(s32, f32*);
void func_800F86C4(s32, s32);
void func_800F8804(s32, f32*);
void func_800F8850();
unkStruct800F88A0* func_800F88A0(s32);
s32 func_800F8914(unkStruct800F88A0*, s32);
s32 func_800F8B64(void);
SPLITUP_STATUS bs_getSplitStatus();
void func_800F8B94(void);
MapId func_800F8A5C(s32);
void func_800F8D80(s32, unkStruct800F88A0*);
void func_800F8DD8();
void func_800F8E08();
void func_800F8EBC(s32);
void func_800F8EE4(s32);
void func_800F9098(s32, f32*);
void func_800F90EC(f32);
void func_800F90F8(s32);
void func_800F9104(s32);
void func_800F9110(s32);
void func_800F911C(s32);
void func_800F9178();
s32 func_800F9184(void);
// Might take in a PlayerState *
void func_800F9198(void);
s32 func_800F9214(s32);
TransformationId func_800F929C(void);
void func_800F93C4(s32*, s32*);
int func_800F9488(s32);
s32 func_800F99E8(void);
s32 func_800F9A24();
void func_800F9A44(void);
void func_800F9A6C();
void func_800F9BC4(void);
void func_800F9C6C(void);

#endif // __CORE2_1ECE0B0_H__