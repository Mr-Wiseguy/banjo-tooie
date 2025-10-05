#ifndef __SU_BADDIE_DIALOG_H__
#define __SU_BADDIE_DIALOG_H__
#include "common.h"
#include "core1/1E2D890.h"
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
	/* 0x00 */ u16 unk0;
	/* 0x02 */ u16 unk2;
	/* 0x04 */ u16 unk4;
	/* 0x06 */ u16 unk6;
	/* 0x08 */ u32 unk8;
	/* 0x0C */ u16 unkC;
	/* 0x0E */ u16 unkE;
	/* 0x10 */ s16 unk10;
	/* 0x12 */ u16 unk12;
	/* 0x14 */ u16 unk14;
	/* 0x16 */ u8 unk16;
	/* 0x17 */ u8 unk17;
	/* 0x18 */ u8 unk18;
}subaddiedialog_UnkStruct0;

typedef struct {
	/* 0x00 */ u32 TransformationType;
	/* 0x04 */ s16 unk4;
	/* 0x06 */ u8 unk6;
	/* 0x07 */ u8 unk7;
}subaddiedialog_UnkStruct1;

typedef struct {
	/* 0x00 */ u16 DialogFlag;//Dialog Flag
	/* 0x02 */ u16 unk2;
	/* 0x04 */ u16 unk4;
	/* 0x06 */ s16 unk6;
	/* 0x08 */ u16 unk8;
	/* 0x0A */ u16 unkA;
	/* 0x0C */ u8 unkC;
	/* 0x0D */ u8 unkD;
	/* 0x0E */ u8 unkE;

}subaddiedialog_UnkStruct2;

s32 func_80800000_subaddiedialog(f32*, s32, s32);
s32 func_808010C8_subaddiedialog(Actor* a0, s32 arg1, s32 arg2);
s32 func_8080110C_subaddiedialog(f32*, s32, s32);
s32 func_8080118C_subaddiedialog(f32*, s32, s32, s32);
s32 func_80801208_subaddiedialog(f32*, s32, s32, s32);
s32 func_80801394_subaddiedialog(Actor*, s32, s32);
void func_808013E4_subaddiedialog(Actor*, s32, u32);
s32 func_8080141C_subaddiedialog(void);
s32 subaddiedialog_entrypoint_1(f32* a0, u32 a1, s32 arg2);
s32 _subaddiedialog_entrypoint_3(f32*, s32, u32, u32, s32);
s32 _subaddiedialog_entrypoint_4(f32*, s32, s32);
s32 _subaddiedialog_entrypoint_5(f32*, u32, u32, u32);
s32 _subaddiedialog_entrypoint_6(f32*, s32, u32, u32, s32);
u32 subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, s16);
s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);

#endif
