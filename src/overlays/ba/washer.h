#ifndef __BA_WASHER_H__
#define __BA_WASHER_H__

#include <ultra64.h>

#include "overlays/ba/playerstate.h"

typedef struct ba_washer_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
} BaWasher;

void _bawasher_entrypoint_6(s32 arg0);

void bawasher_entrypoint_8(PlayerState *self, f32 arg1[3], f32 arg2[3], f32 arg3[3]);


#endif 
