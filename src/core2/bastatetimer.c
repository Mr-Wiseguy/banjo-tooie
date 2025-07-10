#include "core2/bastatetimer.h"

s32 bastatetimerList_getSize(void) {
    return sizeof(BaStateTimerList);
}

f32 bastatetimer_get(PlayerState *self, BaStateTimerId id) {
    return self->state_timer->timer[id].now;
}

f32 bastatetimer_getPrevious(PlayerState *self, BaStateTimerId id) {
    return self->state_timer->timer[id].prev;
}

int bastatetimer_isActive(PlayerState *self, BaStateTimerId id) {
    return (self->state_timer->timer[id].now != 0.0f);
}

int bastatetimer_isDone(PlayerState *self, BaStateTimerId id) {
    return (self->state_timer->timer[id].now == 0.0f);
}

int bastatetimer_isAt(PlayerState *self, BaStateTimerId id, f32 arg2) {
    BaStateTimer *timer = &self->state_timer->timer[id];
    return ((timer->now  < arg2) && (arg2 <= timer->prev));
}

void bastatetimerlist_free(PlayerState *self) {}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bastatetimer/bastatetimerlist_init.s")
#else
void bastatetimerlist_init(PlayerState *self) {
    int i;

    for (i = 0; i < BA_STATE_TIMER_COUNT; i++) {
        self->state_timer->timer[i].now = 0.0f;
        self->state_timer->timer[i].prev = 0.0f;
        self->state_timer->timer[i].unk8 = 0;
    }
}
#endif

void bastatetimer_clear(PlayerState *self, BaStateTimerId id) {
    bastatetimer_set(self, id, 0.0f);
}

void bastatetimer_set(PlayerState *self, BaStateTimerId id, f32 arg2) {
    self->state_timer->timer[id].now = arg2;
    self->state_timer->timer[id].prev = arg2;
}


void bastatetimerlist_update(PlayerState *self){
    int i;
    f32 pad0;
    s32 sp1C;
    f32 delta;

    sp1C = !func_800F424C(self);
    delta = func_800D8FF8();
    for(i = 0; i < BA_STATE_TIMER_COUNT; i++){
        self->state_timer->timer[i].prev = self->state_timer->timer[i].now;
        if(0.0f != self->state_timer->timer[i].now
            && !(self->state_timer->timer[i].unk8 && sp1C)
        ){
            self->state_timer->timer[i].now -= delta;
            if(self->state_timer->timer[i].now < 0.0f){
                self->state_timer->timer[i].now = 0.0f;
            }
        }
    }
}
