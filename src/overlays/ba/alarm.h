#ifndef __BA_ALARM_H__
#define __BA_ALARM_H__

#include "overlays/ba/playerstate.h"

typedef struct ba_alarm_s {
    u8 id;
    u8 active;
} BaAlarm;

s32 baalarm_get_size(void);
void baalarm_free(PlayerState *self);
void baalarm_new(PlayerState *self);
void baalarm_entrypoint_3(PlayerState *self, f32 arg1, f32 arg2);

void func_80800294_baalarm(u8 id, s32 arg1);

void _baalarm_entrypoint_3(PlayerState *, f32, f32);
void _baalarm_free(PlayerState *);
void _baalarm_new(PlayerState *);
void _batimer_incrementBy(PlayerState *, s32, f32);

#endif // __BA_ALARM_H__
