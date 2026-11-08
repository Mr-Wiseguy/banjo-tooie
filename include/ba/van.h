#ifndef __BA_VAN_H__
#define __BA_VAN_H__

#include <ultra64.h>

#include "ba/playerstate.h"

typedef struct ba_van_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    // u8 pad11[0x3];
    f32 unk14;
} BaVan;

void _bavan_entrypoint_1(PlayerState*);
void _bavan_entrypoint_2(PlayerState*);
void _bavan_entrypoint_3(PlayerState*);
void _bavan_entrypoint_4(PlayerState*, f32);
void _bavan_entrypoint_5(PlayerState*, f32);
void _bavan_entrypoint_6(PlayerState*, f32);
void _bavan_entrypoint_7(PlayerState*, f32);
void _bavan_entrypoint_8(PlayerState*);

#endif 
