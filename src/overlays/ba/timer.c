#include "common.h"

#include "overlays/ba/timer.h"

#include "core2/1EB2840.h"
#include "core2/1ECA640.h"

s32 batimer_get_size(void) {
    return sizeof(BaTimer);
}

void batimer_incrementBy(PlayerState *self, s32 id, f32 arg2) {
    self->timer->unk3C[id] = self->timer->unk0[id];
    self->timer->unk0[id] += arg2;
}

int batimer_decrement(PlayerState *self, s32 id){
    self->timer->unk3C[id] = self->timer->unk0[id];
    if (self->timer->unk0[id] == 0.0f) {
        return 0;
    }

    self->timer->unk0[id] = func_800F0E00(0.0f, self->timer->unk0[id] - func_800D8FF8());
    return (self->timer->unk0[id] == 0.0f); 
    
}

void batimer_increment(PlayerState *self, s32 id) {
    self->timer->unk3C[id] = self->timer->unk0[id];
    self->timer->unk0[id] += func_800D8FF8();
}

f32 batimer_get(PlayerState *self, s32 id) {
    return self->timer->unk0[id];
}

int batimer_isAt_falling(PlayerState *self, s32 id, f32 time) {
    return (time <= self->timer->unk3C[id]) && (self->timer->unk0[id] < time);
}

int batimer_isAt_rising(PlayerState *self, s32 id, f32 time) {
    return (self->timer->unk3C[id] <= time) && (time < self->timer->unk0[id]);
}

int batimer_isLessThan(PlayerState *self, s32 id, f32 time) {
    return (self->timer->unk0[id] < time); 
}

int batimer_isGreaterThan(PlayerState *self, s32 id, f32 time) {
    return (self->timer->unk0[id] > time); 
}

int batimer_isNonzero(PlayerState *self, s32 id) {
    return (self->timer->unk0[id] != 0.0f); 
}

int batimer_isZero(PlayerState *self, s32 id) {
    return (self->timer->unk0[id] == 0.0f); 
}

void batimer_set(PlayerState *self, s32 id, f32 value) {
    self->timer->unk3C[id] = value;
    self->timer->unk0[id] = value;
}
