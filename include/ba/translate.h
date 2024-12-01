#ifndef __BA_TRANSLATE_H__
#define __BA_TRANSLATE_H__

#include <ultra64.h>

#include "playerstate.h"

typedef struct ba_translate_s {
    u8 unk0;
    // u8 pad1[0x3];
    s32 unk4;
    f32 unk8[3];
    f32 unk14[3];
} BaTranslate;

void batranslate_entrypoint_3(PlayerState *self, s32 arg1);

#endif 
