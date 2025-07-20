#include "core2/yaw.h"

s32 yaw_size(void){
    return sizeof(BaYaw);
}

void __yaw_update_limitless(PlayerState *self, f32 velocity_degPerSec) {
    f32 dYaw_deg;
    f32 sp20;

    velocity_degPerSec *= func_800D8FF8();
    dYaw_deg = self->yaw->ideal - self->yaw->value;
    if (mlAbsF(dYaw_deg) > 180.0f) {
        dYaw_deg += (dYaw_deg < 0.0f) ? 360.0f : -360.0f;
    }

    sp20 = (mlAbsF(dYaw_deg) > 180.0f) ? velocity_degPerSec : ((dYaw_deg < 0.0f)? -velocity_degPerSec: velocity_degPerSec);
    
    if (mlAbsF(sp20) <= mlAbsF(dYaw_deg)) {
        self->yaw->value += sp20;
    } else {
        self->yaw->value = self->yaw->ideal;
    }

    if (self->yaw->value < 360.0f) {
        if (self->yaw->value < 0.0f) {
            self->yaw->value = (f32) (self->yaw->value + 360.0f);
        }
    } else {
        self->yaw->value -= 360.0f;
    }
}

void __yaw_update_limited(PlayerState *self, f32 limit_degPerSec, f32 step_percent) {
        BaYaw *pYaw;
        f32 val_deg;
        f32 dyaw_deg;
        f32 dt_s;

        dt_s = func_800D8FF8();
        pYaw = self->yaw;
        dyaw_deg = func_80013728(pYaw->ideal - pYaw->value);

        val_deg = dyaw_deg * step_percent;
        if (val_deg != 0) {
            val_deg = (val_deg < 0) ? func_800F0D50(val_deg, -limit_degPerSec, -3.0f) : func_800F0D50(val_deg, 3.0f, limit_degPerSec);
        }
        pYaw->unk8 = val_deg;
        pYaw->value += func_800F212C(val_deg*dt_s, dyaw_deg);
        pYaw->value = func_800136E4(pYaw->value);
    }

void yaw_init(PlayerState *self) {
    self->yaw->value = 0.0f;
    self->yaw->ideal = 0.0f;
    yaw_setVelocityBounded(self, 700.0f, 7.5f);
    yaw_setVelocityUnbounded(self, 360.0f);
    self->yaw->update_type = YAW_TYPE_0_NONE;
    yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
}

void yaw_update(PlayerState *self) {
    switch(self->yaw->update_type) {
        case YAW_TYPE_0_NONE:
            break;
        case YAW_TYPE_1_DEFAULT:
            __yaw_update_limited(self, 700.0f, 7.5f);
            break;
        case YAW_TYPE_2_UNBOUNDED:
            __yaw_update_limitless(self, self->yaw->velocity_degPerSec);
            break;
        case YAW_TYPE_3_BOUNDED:
            __yaw_update_limited(self, self->yaw->limit_degPerSec, self->yaw->step_percent);
            break;
    }
}

void yaw_setUpdateType(PlayerState *self, YawType type) {
    self->yaw->update_type = type;
}

void yaw_setIdeal(PlayerState *self, f32 arg1) {
    self->yaw->ideal = func_800136E4(arg1);
}

void yaw_set(PlayerState *self, f32 arg1) {
    self->yaw->value = func_800136E4(arg1);
}

void yaw_applyIdeal(PlayerState *self) {
    self->yaw->value = self->yaw->ideal;
}

f32 yaw_get(PlayerState *self) {
    return self->yaw->value;
}

f32 yaw_getIdeal(PlayerState *self) {
    return self->yaw->ideal;
}

void yaw_setVelocityBounded(PlayerState *self, f32 limit_degPerSec, f32 step_percent){
    self->yaw->limit_degPerSec = limit_degPerSec;
    self->yaw->step_percent = step_percent;

}

void yaw_setVelocityUnbounded(PlayerState *self, f32 velocity_degPerSec){
    self->yaw->velocity_degPerSec = velocity_degPerSec;
}

void yaw_rotateTimed(PlayerState *self, f32 time_sec) {
    f32 dyaw_deg = self->yaw->ideal - self->yaw->value;
    if (180.0f < mlAbsF(dyaw_deg)) {
        dyaw_deg += (dyaw_deg < 0.0f)? 360.0f: -360.0f;
    }

    self->yaw->velocity_degPerSec = mlAbsF(dyaw_deg/time_sec);
}
