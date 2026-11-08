#ifndef __CORE2_1EDB4D0_H__
#define __CORE2_1EDB4D0_H__

#include "common.h"
#include "core2/anctrl.h"
#include "core2/1EB5980.h"
#include "core2/1ED8C80.h"
#include "core2/1EDA900.h"

s32 func_80101BE0(Actor*, u32);
void func_80101CDC(Actor*, f32);
void func_80101D4C(Actor*);
void func_80101DAC(Actor*, s32);
s32 func_80101DDC(Actor*);
s32 func_80101E14(Actor*, f32);
s32 func_80101E4C(Actor*, f32*);
void func_80101EE4(Actor*, f32);
f32 func_80101F24(Actor *);
s32 func_80101F64();
void func_80101FDC(Actor*, u32);
void func_801020DC(Actor*, s32);
void func_80102190(Actor*, s32);
s32 func_801022E4(Actor*);
s32 func_80102320(Actor*, f32, f32);
//Set actor state 
void func_80102424(Actor*, s32);
s32 func_8010262C(Unk80132ED0*, u32);

typedef struct Vec3s32 {
    s32 x, y, z;
} Vec3s32;
void func_801026CC(Actor*, Vec3s32, f32);
AnimCtrl* func_80104248(Actor*);

#endif
