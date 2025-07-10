#ifndef __BA_ATTACH_H__
#define __BA_ATTACH_H__

#include "common.h"
#include "overlays/ba/playerstate.h"

typedef struct ba_attach_s {
    s32 unk0;
    void (*unk4)(s32 , s32, s32, s32);
} BaAttach;

s32 baattach_entrypoint_0(void);
s32 baattach_entrypoint_1(PlayerState *self);
s32 baattach_entrypoint_2(PlayerState *self, s32 arg1, void (*arg2)(s32, s32, s32, s32));
void baattach_entrypoint_3(PlayerState *self);
void baattach_entrypoint_4(PlayerState *self);
void baattach_entrypoint_5(PlayerState *self, s32 arg1);
void baattach_entrypoint_6(PlayerState *self, s32 arg1, s32 arg2, s32 arg3);

#endif // __BA_ATTACH_H__
