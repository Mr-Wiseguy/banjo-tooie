#ifndef __BA_TRANSLATE_H__
#define __BA_TRANSLATE_H__

#include "common.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1EC8070.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
#include "overlays/db/skeleton.h"


typedef struct ba_translate_s {
    u8 unk0;
    // u8 pad1[0x3];
    s32 unk4;
    f32 unk8[3];
    f32 unk14[3];
} BaTranslate;

void _batranslate_entrypoint_3(PlayerState *self, s32);

#endif 
