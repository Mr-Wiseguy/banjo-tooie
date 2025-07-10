#ifndef __BA_BOOST_H__
#define __BA_BOOST_H__

#include "common.h"
#include "overlays/ba/playerstate.h"


typedef struct ba_boost_s {
    u8 unk0;
    u8 pad1[0x3];
    f32 unk4;
    f32 unk8[5];
} BaBoost;

extern s32 _baboost_entrypoint_1(PlayerState *self);
extern void _baboost_entrypoint_2(PlayerState *self, f32);
extern void _baboost_entrypoint_5(PlayerState *self);

#endif // __BA_BOOST_H__
