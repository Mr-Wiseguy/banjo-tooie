#ifndef __BA_BABYKAZ_H__
#define __BA_BABYKAZ_H__

#include "ba/playerstate.h"

typedef struct ba_babykaz_s {
    u8 unk0;
    u8 unk1;
    // u8 pad2[0x2];
    f32 unk4;
} BaBabyKaz;

void _bababykaz_entrypoint_1(PlayerState*);
void _bababykaz_entrypoint_2(PlayerState*);
void _bababykaz_entrypoint_8(PlayerState*);
void _bababykaz_entrypoint_10(PlayerState*, s32);
#endif // __BA_BABYKAZ_H__
