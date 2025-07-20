#ifndef __BA_WOBBLE_H__
#define __BA_WOBBLE_H__

#include "common.h"
#include "core2/1E6A730.h"
#include "core2/1E6B900.h"
#include "core2/1EBA250.h"
#include "core2/1ECA640.h"
#include "overlays/ba/playerstate.h"


typedef struct ba_wobble_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    u8 unk1D;
} BaWobble;

void bawobble_entrypoint_4(PlayerState *self, f32 arg1, f32 arg2);


#endif 
