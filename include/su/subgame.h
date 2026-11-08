#ifndef __SU_SUBGAME__
#define __SU_SUBGAME__
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} unkSubGameStruct;

void _susubgame_entrypoint_0(Actor*, void*, s32);
s32 _susubgame_entrypoint_2(Actor*, void*);
s32 _susubgame_entrypoint_3(Actor*, s32, s32, u32);
void _susubgame_entrypoint_4(Actor*, void*);
void _susubgame_entrypoint_5(Actor*, s32, s32, s32, s32);
void _susubgame_entrypoint_6(Actor*, void*, s32, s32, s32);
void _susubgame_entrypoint_12(s32, s32*);
#endif
