#ifndef __BA_statetimer_H__
#define __BA_statetimer_H__

#include <ultra64.h>

#include "../ba/playerstate.h" // for PlayerState

#define BA_STATE_TIMER_COUNT 10

typedef struct {
    f32 now;
    f32 prev;
    u8 unk8;
} BaStateTimer;

typedef struct ba_state_timer_list_s {
    BaStateTimer timer[BA_STATE_TIMER_COUNT];
} BaStateTimerList;

typedef enum {
    BA_STATE_TIMER_ID_0_UNKNOWN,
    BA_STATE_TIMER_ID_1_THROW = 1,
    BA_STATE_TIMER_ID_2_LONGLEG,
    BA_STATE_TIMER_ID_3_TURBO_TALON,
    BA_STATE_TIMER_ID_4_UNKNOWN,
    BA_STATE_TIMER_ID_5_UNKNOWN, //slide timer
    BA_STATE_TIMER_ID_6_UNKNOWN,  //trot slide timer
    BA_STATE_TIMER_ID_7_UNKNOWN,
    BA_STATE_TIMER_ID_8_UNKNOWN,
    BA_STATE_TIMER_ID_9_UNKNOWN
} BaStateTimerId;

s32 bastatetimerList_getSize(void);
f32 bastatetimer_get(PlayerState *self, BaStateTimerId id);
f32 bastatetimer_getPrevious(PlayerState *self, BaStateTimerId arg1);
int bastatetimer_isActive(PlayerState *self, BaStateTimerId arg1);
int bastatetimer_isDone(PlayerState *self, BaStateTimerId arg1);
int bastatetimer_isAt(PlayerState *self, BaStateTimerId arg1, f32 arg2);
void bastatetimerlist_free(PlayerState *self);
void bastatetimerlist_init(PlayerState *self);
void bastatetimer_clear(PlayerState *self, BaStateTimerId arg1);
void bastatetimer_set(PlayerState *self, BaStateTimerId arg1, f32 arg2);
void bastatetimerlist_update(PlayerState *self);

#endif // __BA_statetimer_H__
