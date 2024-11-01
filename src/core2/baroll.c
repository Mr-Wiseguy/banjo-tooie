#include "ba/roll.h"

#include "common.h"

#include "ba/playerstate.h"

#include "core2/1E2B200.h"
#include "core2/1EB2840.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"

void baroll_resetAngularVelocity(PlayerState *);

// Definitions
s32 baroll_getStructSize(void) {
    return sizeof(BaRoll);
}

void __baroll_update(PlayerState *self, f32 limit, f32 rate) {
    f32 diff;
    f32 val;
    f32 dt;
    f32 max;

    dt = func_800D8FF8();
    max = limit*dt;
    diff = self->roll->ideal - self->roll->value;
    if(180.0f < mlAbsF(diff)){
        diff += (diff < 0.0f)? 360.0f: -360.0f;
    }
    val = diff * rate * dt;
    val = (val < 0.0f) ? func_800F0D50(val, -max, -0.1f) : func_800F0D50(val, 0.1f, max);
    if ( mlAbsF(val) <= mlAbsF(diff)) {
        self->roll->value =  self->roll->value + val;
    } else {
        self->roll->value = self->roll->ideal;
    }
    if(self->roll->value < 360.0f){
        if(self->roll->value < 0.0f) {
            self->roll->value += 360.0f;
        }
    } else {
        self->roll->value -= 360.0f;
    }
}

void baroll_reset(PlayerState *self) {
    self->roll->value = 0.0f;
    self->roll->ideal = 0.0f;
    baroll_resetAngularVelocity(self);
}

void baroll_update(PlayerState *self) {
    __baroll_update(self, self->roll->limit, self->roll->rate);
}

void baroll_setIdeal(PlayerState *self, f32 arg1) {
    self->roll->ideal = func_800136E4(arg1);
}

void baroll_set(PlayerState *self, f32 arg1) {
    self->roll->value = func_800136E4(arg1);
}

void baroll_applyIdeal(PlayerState *self) {
    self->roll->value = self->roll->ideal;
}

f32 baroll_get(PlayerState *self) {
    return self->roll->value;
}

f32 baroll_getIdeal(PlayerState *self) {
    return self->roll->ideal;
}

void baroll_setAngularVelocity(PlayerState *self, f32 limit, f32 rate) {
    self->roll->limit = limit;
    self->roll->rate = rate;
}

void baroll_resetAngularVelocity(PlayerState *self) {
    baroll_setAngularVelocity(self, 700.0f, 7.5f);
}
