#ifndef __SU_BADDIE_DIALOG_H__
#define __SU_BADDIE_DIALOG_H__
#include "common.h"
#include "core2/1E2D890.h"
#include "core2/1EB45C0.h"
#include "core2/1ECE0B0.h"
#include "core2/1EDA900.h"
#include "core2/1EE5DF0.h"
#include "core2/1EB3750.h"
#include "core2/1E99980.h"
#include "core2/1ECB9F0.h"
#include "core2/1ECB0F0.h"
#include "core2/1EDB4D0.h"


typedef struct {
	u16 unk0;
	u16 unk2;
	u16 unk4;
	u16 unk6;
	u32 unk8;
	u16 unkC;
	u16 unkE;
	s16 unk10;
	u16 unk12;
	u16 unk14;
	u8 unk16;
	u8 unk17;
	u8 unk18;
}subaddiedialog_UnkStruct0;

typedef struct {
	u32 unk0;
	s16 unk4;
	u8 unk6;
	u8 unk7;
}subaddiedialog_UnkStruct1;

typedef struct {
	u16 unk0;
	u16 unk2;
	u16 unk4;
	s16 unk6;
	u16 unk8;
	u16 unkA;
	u8 unkC;
	u8 unkD;
	u8 unkE;

}subaddiedialog_UnkStruct2;

s32 func_80800000_subaddiedialog(f32* a0, s32 a1, s32 arg2);
s32 func_808010C8_subaddiedialog(s32 a0, s32 arg1, s32 arg2);
s32 func_8080110C_subaddiedialog(f32*, s32, s32);
s32 func_8080118C_subaddiedialog(f32*, s32, s32, s32);
s32 func_80801208_subaddiedialog(f32*, s32, s32, s32);
s32 func_80801394_subaddiedialog(Actor*, s32, s32);
void func_808013E4_subaddiedialog(Actor* arg0, s32 arg1, u32 arg2);
s32 func_8080141C_subaddiedialog(void);
s32 subaddiedialog_entrypoint_1(f32* a0, u32 a1, s32 arg2);
s32 _subaddiedialog_entrypoint_3(f32*, s32, u32, u32, s32);
s32 _subaddiedialog_entrypoint_5(f32*, u32, u32, u32);
s32 _subaddiedialog_entrypoint_6(f32*, s32, u32, u32, s32);
u32 subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 arg1, u32 arg2, f32* arg3, s16 arg4);
void _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);

#endif