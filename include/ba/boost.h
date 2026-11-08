#ifndef __BA_BOOST_H__
#define __BA_BOOST_H__

#include <ultra64.h>

#include "common.h"

#include "ba/playerstate.h"

typedef struct ba_boost_s {
    u8 unk0;
    u8 pad1[0x3];
    f32 unk4;
    f32 unk8[5];
} BaBoost;

// Code
s32 baboost_entrypoint_0(void);
s32 _baboost_entrypoint_1(PlayerState*);
s32 _baboost_entrypoint_2(PlayerState*, f32);
void _baboost_entrypoint_3(PlayerState*);
void _baboost_entrypoint_4(PlayerState*, s32);
void _baboost_entrypoint_5(PlayerState*);

#endif // __BA_BOOST_H__
