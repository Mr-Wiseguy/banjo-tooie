#ifndef __CH_BUBBLE_ELEVATOR_H__
#define __CH_BUBBLE_ELEVATOR_H__

#include "common.h"
#include "maps.h"

#include "core1/1E2C940.h"

#include "core2/1E9A960.h"

#include "core2/1EAD6C0.h"
#include "core2/1EB2840.h"

#include "core2/1EB3750.h"
#include "core2/1EBCFC0.h"

#include "core2/1ECA640.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1EC9740.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECE0B0.h"

#include "core2/1ED4E30.h"
#include "core2/1EDA900.h"
#include "core2/1EDB4D0.h"
#include "core2/1EDC7B0.h"

#include "core2/1EE5DF0.h"

#include "ca/pod.h"

#include "ch/bubble.h"

#include "su/jiggy.h"
#include "su/baddieDll.h"
#include "su/baddieaudioloop.h"
#include "su/baddiedialog.h"
#include "su/deflect.h"

#include "gl/cutDll.h"
#include "gc/cubesearch.h"
#include "gc/goto.h"

#include "gs/propctrl.h"

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
}BubbleElevatorActorData;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u32 entranceId;
    u32 mapId;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} BubbleWarpData;

void func_808004DC_chbubbleelevator(Actor*, s32);
void func_808008A8_chbubbleelevator(Actor* arg0);

#endif
