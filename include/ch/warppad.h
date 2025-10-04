#ifndef __CH_WARPPAD_H__
#define __CH_WARPPAD_H__

#include "common.h"
#include "core2/1E691A0.h"

#include "core2/1EB3750.h"

#include "core2/1EC4CC0.h"
#include "core2/1EC8070.h"
#include "core2/1ECE0B0.h"

#include "core2/1ED8C80.h"
#include "core2/1EDA900.h"
#include "core2/1EDAEA0.h"

#include "core2/1EA0AA0.h"
#include "core2/1EE4020.h"
#include "core2/1EE5DF0.h"

#include "gc/goto.h"
#include "gc/dialogcamera.h"
#include "gc/newoption.h"
#include "ca/pod.h"
#include "su/baddiedialog.h"

#include "su/baddieDll.h"
#include "su/baddiefade.h"
#include "su/baddiesect.h"

#include "ch/appearfx.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
}WarppadActorData;


typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} D_808010A0;

typedef struct {
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u32 unk8;
} D_808010B0;

s32 func_80800064_chwarppad(Actor*, s32);
void func_80800418_chwarppad(Actor*, u32);
void func_80800AB8_chwarppad(Actor* arg0, s32 arg1, s32 arg2);
void func_80800B34_chwarppad(Actor*, OptionState*, s32, s32);
s32 func_80800E10_chwarppad(s32);
void func_80800F34_chwarppad(Actor* arg0, s32 arg1, s32 arg2);
void func_80801018_chwarppad(Actor* arg0);

#endif
