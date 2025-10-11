#ifndef __CH_CLOCKWORKMOUSE_H__
#define __CH_CLOCKWORKMOUSE_H__

#include "ca/pod.h"
#include "common.h"
#include "core1/1E2D890.h"
#include "core2/1E691A0.h"
#include "core2/1E691A0.h"
#include "core2/1E78170.h"
#include "core2/1E7E9A0.h"
#include "core2/1E97EF0.h"
#include "core2/1E9A960.h"
#include "core2/1EA1270.h"
#include "core2/1EA9160.h"
#include "core2/1EAF950.h"
#include "core2/1EB2840.h"
#include "core2/1EB2C90.h"
#include "core2/1EB3750.h"
#include "core2/1EB5980.h"
#include "core2/1EB5E70.h"
#include "core2/1EB5E70.h"
#include "core2/1EB93C0.h"
#include "core2/1EBB4F0.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECE0B0.h"
#include "core2/1ED4E30.h"
#include "core2/1ED68A0.h"
#include "core2/1ED8C80.h"
#include "core2/1EDA900.h"
#include "core2/1EDAEA0.h"
#include "core2/1EDB4D0.h"
#include "core2/1EDC070.h"
#include "core2/1EDCA30.h"
#include "core2/1EDD9C0.h"
#include "core2/1EDED00.h"
#include "core2/1EDFED0.h"
#include "core2/1EE1510.h"
#include "core2/1EE5DF0.h"
#include "gc/cubesearch.h"
#include "gc/dialogcamera.h"
#include "gc/goto.h"
#include "gc/introtext.h"
#include "gl/cutDll.h"
#include "gl/splinefind.h"
#include "gs/propctrl.h"
#include "su/baddieaudioquick.h"
#include "su/baddiedialog.h"
#include "su/baddieDll.h"
#include "su/deflect.h"
#include "su/expression.h"
#include "su/splinet.h"

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
}ClockworkActorData;

// size: 0x14
typedef struct Unk80803CD8 {
    f32 unk0[3];
    f32 unkC;
    s16 unk10;
    s16 unk12;
} Unk80803CD8;

// size: 0x10
typedef struct Unk80803E08  {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} Unk80803E08;

// size: unknown
typedef struct Unk80100094 {
    union {
        struct {
            s16 unk0;
            s16 pad2;
        } shorts;
        f32 f;
    } unk0;
    f32 unk4;
    f32 unk8;
    union {
        u8 bytes[0x84 - 0xC];
        s16 shorts[(0x84 - 0xC) / 2];
        Vec3f vecs[10];
    } unkC;
    f32 unk84[10];
    f32 unkAC[10];
    f32 unkD4;
    f32 unkD8;
    f32 unkDC;
    u8 unkE0[10];
    u8 padEA;
    u8 padEB;
    f32 unkEC;
    u8 unkF0[10];
    u8 unkFA;
    u8 unkFB;
    u8 unkFC;
    u8 unkFD;
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    f32 unk104;
    f32 unk108;
    f32 unk10C;
    f32 unk110;
    f32 unk114;
} Unk80100094;

// used before definition
void func_808022E4_chclockworkmouse(Actor *, s32);
void func_808026E0_chclockworkmouse(Actor*, s32);

#endif // __CH_CLOCKWORKMOUSE_H__
