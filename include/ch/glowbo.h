#ifndef __CH_GLOWBO_H__
#define __CH_GLOWBO_H__

#include "common.h"
#include "ch/baddiesetup.h"
#include "fx/sparkle.h"
#include "fx/twinkle.h"

#include "su/baddiefade.h"
#include "su/baddieDll.h"
#include "su/baddierouteDll.h"
#include "su/baddiesect.h"
#include "su/baddieaudioquick.h"
#include "su/baddiedialog.h"
#include "su/dialog.h"

#include "core2/1E2B200.h"

#include "core2/1E691A0.h"
#include "core2/1E93440.h"

#include "core2/1EA1DA0.h"
#include "core2/1EA9160.h"
#include "core2/1EAAD80.h"

#include "core2/1EB2840.h"
#include "core2/1EB3750.h"
#include "core2/1EB5980.h"
#include "core2/1EB5E70.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"

#include "core2/1ECB0F0.h"
#include "core2/1ECD170.h"


#include "core2/1ED8C80.h"
#include "core2/1EDAEA0.h"
#include "core2/1EDB4D0.h"

#include "core2/1EE1510.h"
#include "core2/1EE27C0.h"
#include "core2/1EE4270.h"
#include "core2/1EE5DF0.h"

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
}GlowboActorData;

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u16 unk14;
    u8 unk16;
    u8 unk17;
}glowboStruct;

typedef struct {
    u32 unk0;
    u16 unk4;
    u16 unk6;
}glowboStruct2;


void func_80800000_chglowbo(Actor* arg0);
void func_80801258_chglowbo(Actor*);

#endif
