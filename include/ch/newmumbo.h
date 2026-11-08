#ifndef __CH_NEWMUMBO_H__
#define __CH_NEWMUMBO_H__

#include "common.h"
#include "ca/pod.h"
#include "su/expression.h"
#include "su/baddiedialog.h"
#include "su/baddieaudioquick.h"

#include "ch/jujubagfx.h"

#include "gl/cutDll.h"
#include "gc/dialogcamera.h"
#include "pl/su.h"

#include "core1/1E2B200.h"
#include "core2/1E691A0.h"
#include "core2/1EAAD80.h"
#include "core2/1EB2840.h"

#include "core2/1EB3750.h"
#include "core2/1EB5980.h"
#include "core2/1EB5E70.h"
#include "core2/1EC3810.h"

#include "core2/1EC8070.h"
#include "core2/1EC9740.h"
#include "core2/1ECE0B0.h"

#include "core2/1ED4E30.h"
#include "core2/1ED8C80.h"
#include "core2/1EDAEA0.h"
#include "core2/1EE5DF0.h"

typedef struct NewMumboStruct {
	u8 unk0;
	u8 unk1;
	u8 unk2;
	u8 unk3;
	f32 unk4[3];
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1C;
	u32 unk20;
	u8 unk24;
} NewMumboStruct;

typedef struct {
	f32 unk0;
	f32 unk4;
	f32 unk8;
	f32 unkC;
	f32 unk10;
	f32 unk14;
	f32 unk18;
}MumboActorData;



#endif
