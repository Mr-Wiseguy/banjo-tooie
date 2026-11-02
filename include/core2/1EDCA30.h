#ifndef __CORE2_1EDCA30_H__
#define __CORE2_1EDCA30_H__

#include "common.h"

typedef struct {
    s32 pad[5];
    u32 unk31 : 31;
    u32 unk0 : 1;
} unkStruct80103CB8;

void func_80103140(Actor*, u32, u16);
void func_801032B0(Actor*, s32, s32);
s32 func_8010347C(Unk80132ED0*);
void func_80103930(Actor*);
s32 func_801039E4(Unk80132ED0*);
unkStruct80103CB8* func_80103CB8(Actor*, s32);
void func_80103DFC(Actor*, f32*);
f32 func_80103EAC(Actor*);
f32 func_80103EF4(Actor*);
f32 func_80103FB8(Actor*);
#endif
