#ifndef __CORE2_1EDB4D0_H__
#define __CORE2_1EDB4D0_H__

#include "common.h"

void func_80101CDC(Actor*, f32);
s32 func_80101DDC(Actor*);
s32 func_80101E14(Actor*, f32);
s32 func_80101E4C(Actor*, f32*);
f32 func_80101F24(Actor *);
void func_80101FDC(Actor*, u32);
s32 func_801022E4(Actor*);
void func_80102424(Actor*, s32);
s32 func_8010262C(Unk80132ED0*, u32);

typedef struct Vec3s32 {
    s32 x, y, z;
} Vec3s32;
void func_801026CC(Actor*, Vec3s32, f32);

#endif
