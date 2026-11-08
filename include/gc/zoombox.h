#ifndef __GC_ZOOMBOX_H__
#define __GC_ZOOMBOX_H__
#include "common.h"
#include "core1/1E29B60.h"
#include "core1/heap.h"
#include "core2/1E80A70.h"
#include "core2/1E9A960.h"
#include "core2/1EAC810.h"
#include "core2/1EAF950.h"
#include "core2/1EB2840.h"
#include "core2/1EB3750.h"
#include "core2/1EB5980.h"
#include "core2/1EC4CC0.h"
#include "core2/1ECD170.h"
#include "core2/1ED4E30.h"
#include "core2/1EDA900.h"
#include "core2/1EAEB40.h"
#include "fx/dialog.h"
#include "fx/fontstring.h"
#include "gc/audiolist.h"
#include "gl/dialog.h"

typedef struct {

	u8 pad0[0x12];
	u16 unk12_1 : 15;
	u16 unk12_0:1;
	u8 pad14[0x11C];
	s32 unk130;
	s16 unk134[3];
	s16 unk13A;
	s32 unk13C;
	u16 unk140;
	u16 unk142;
	u8 unk144[4];
	u8 unk148;
	u8 unk149;
	u8 unk14A;
	u8 unk14B;
	f32 unk14C;
	u8 pad150[0x1A];
	s16 unk16A;
	void(*unk16C)(s32);
	u8 unk170;
	u8 unk171;
	s16 unk172;
	u8 unk174;
	u8 unk175;
	u8 unk176;
	u8 unk177;
	u8 unk178;
	u8 unk179;
	u8 unk17A;
	u8 unk17B;
	s32 unk17C[8];
	u8 pad19C[0x10];
	s16 unk1AC;
	s16 unk1AE;
	s16 unk1B0;
	s16 unk1B2;
	u8 unk1B4;
	u8 unk1B5;
	u8 unk1B6;
	u8 unk1B7;
	u8 pad1B8[0x4];
	s16 unk1BC;
	s16 unk1BE;
	u8 pad1C0[0x18];
	f32 unk1D8;
	u8 pad1DC[0x4];
	f32 unk1E0;
	u32 unk1E4_19 : 13;
	u32 unk1E4_18 : 1;
	u32 unk1E4_12 : 6;
	u32 unk1E4_11 : 1;
	u32 unk1E4_7 : 4;
	u32 unk1E4_6 : 1;
	u32 unk1E4_5 : 1;
	u32 unk1E4_4 : 1;
	u32 unk1E4_0:4;
	f32 unk1E8;
	f32 unk1EC;
	f32 unk1F0;

}ZoomboxStruct;


s32 _gczoombox_entrypoint_0(s32);
s32 _gczoombox_entrypoint_2(s32);

#endif
