#ifndef __CH_CLOCKWORK_MOUSE_H__
#define __CH_CLOCKWORK_MOUSE_H__

#include "common.h"

#include "core2/1E691A0.h"
#include "core2/1ED8C80.h"
#include "core2/1EB3750.h"
#include "core2/1ED4E30.h"
#include "core2/1ED68A0.h"
#include "core2/1EDAEA0.h"
#include "su/deflect.h"

typedef struct
{
    u8 unk0[0xF];
    u8 unkF;
    u8 unk10[0x14];
    u8 unk24;
    u8 unk25[0x4C];
    u16 unk72;
    u8 unk74[0x86];
    u8 unkFA;
    u8 unkFB[0x5];
    u8 unk100;
} objectMemory;

#endif