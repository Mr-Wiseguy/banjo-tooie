#include "common.h"

#include "types.h" //for SQ()

#include "ba/stick.h"

#include "ba/key.h"
#include "core2/1E2B200.h"
#include "core2/1E75920.h"
#include "core2/1E7D460.h"
#include "core2/1EA3AA0.h"

s32 bastick_getStructSize(void){
    return sizeof(BaStick);
}

f32 bastick_calculateZonePosition(f32 arg0, f32 arg1, f32 arg2){
    return (arg0 - arg1)/(arg2 - arg1);
}

void bastick_updateZone(PlayerState *self) {
    if (self->stick->distance <= self->stick->zone.markers[0]) {
        self->stick->zone.id = 0;
        self->stick->zone.position = 0.0f;
    } else if ((self->stick->zone.markers[0] < self->stick->distance) && (self->stick->distance <= self->stick->zone.markers[1])) {
        self->stick->zone.id = 1;
        self->stick->zone.position = bastick_calculateZonePosition(self->stick->distance, self->stick->zone.markers[0], self->stick->zone.markers[1]);
    } else if ((self->stick->zone.markers[1] < self->stick->distance) && (self->stick->distance <= self->stick->zone.markers[2])) {
        self->stick->zone.id = 2;
        self->stick->zone.position = bastick_calculateZonePosition(self->stick->distance, self->stick->zone.markers[1], self->stick->zone.markers[2]);
    } else if ((self->stick->zone.markers[2] < self->stick->distance) && (self->stick->distance <= self->stick->zone.markers[3])) {
        self->stick->zone.id = 3;
        self->stick->zone.position = bastick_calculateZonePosition(self->stick->distance, self->stick->zone.markers[2], self->stick->zone.markers[3]);
    } else if ((self->stick->zone.markers[3] < self->stick->distance) && (self->stick->distance <= self->stick->zone.markers[4])) {
        self->stick->zone.id = 4;
        self->stick->zone.position = bastick_calculateZonePosition(self->stick->distance, self->stick->zone.markers[3], self->stick->zone.markers[4]);
    }
}

f32 bastick_getAngle(PlayerState *self) {
    return self->stick->angle;
}

f32 bastick_getAngleRelativeToBanjo(PlayerState *self) {
    f32 player_position[3];
    func_8009C128(self, player_position);
    return func_800CAF00(func_800A4C48(self), self->stick->angle);
}

s32 bastick_func_8009EEF8(PlayerState *self) {
    return self->stick->unk65;
}

f32 bastick_distance(PlayerState *self) {
    return self->stick->distance;
}

BsStickZoneId bastick_getZone(PlayerState *self) {
    return self->stick->zone.id;
}

f32 bastick_getZonePosition(PlayerState *self) {
    return self->stick->zone.position;
}

f32 bastick_getX(PlayerState *self) {
    return self->stick->value[0];
}

f32 bastick_getY(PlayerState *self) {
    return self->stick->value[1];
}

void __bastick_zoneCopy(BaStickZone *dst, BaStickZone *source) {
    aligned4_memcpy(dst, source, sizeof(BaStickZone));
}

void bastick_popZone(PlayerState *self) {
    self->stick->unk66--;
    __bastick_zoneCopy(&self->stick->zone, &self->stick->stored_zones[self->stick->unk66]);
}

void bastick_pushZone(PlayerState *self) {
    __bastick_zoneCopy(&self->stick->stored_zones[self->stick->unk66], &self->stick->zone);
    self->stick->unk66++;
}

void bastick_update(PlayerState *self) {
    bakey_getStick(self, self->stick->value);
    if (self->stick->unk64 || self->stick->unk65 || self->stick->unk67 || !func_80091E80(self, 0x40)) {
        self->stick->unk67 = 0;
        self->stick->value[0] = self->stick->value[1] = 0.0f; 
    }
    self->stick->distance = sqrtf(SQ(self->stick->value[0]) + SQ(self->stick->value[1]));
    if (self->stick->distance != 0.0f) {
        self->stick->angle = func_80013B70(self->stick->value[1], self->stick->value[0], self->stick->distance);
    }
    if (self->stick->distance > 1.0f) {
        self->stick->distance = 1.0f;
    }
    bastick_updateZone(self);
}

void bastick_reset(PlayerState *self) {
    self->stick->unk64 = 0;
    self->stick->unk65 = 0;
    self->stick->value[0] = self->stick->value[1] = self->stick->distance = self->stick->angle = self->stick->zone.position = 0.0f;
    self->stick->unk67 = 1;
    self->stick->zone.id = 0;
    self->stick->unk66 = 0;
    bastick_resetZones(self);
}

void bastick_func_8009F18C(PlayerState *self, s32 arg1) {
    self->stick->unk64 = arg1;
}

void bastick_func_8009F198(PlayerState *self, s32 arg1) {
    self->stick->unk65 = arg1;
}

s32 bastick_func_8009F1A4(PlayerState *self) {
    return (self->stick->unk64) ? 1 : 0;
}

void bastick_setZoneMax(PlayerState *self, s32 zone_id, f32 value) {
    self->stick->zone.markers[zone_id] = value;
}

void bastick_resetZones(PlayerState *self) {
    bastick_setZoneMax(self, 0, 0.12f);
    bastick_setZoneMax(self, 1, 0.2f);
    bastick_setZoneMax(self, 2, 0.5f);
    bastick_setZoneMax(self, 3, 0.75f);
    bastick_setZoneMax(self, 4, 1.0f);
}

void bastick_func_8009F258(PlayerState *self) {
    bastick_setZoneMax(self, 0, 0.12f);
    bastick_setZoneMax(self, 1, 0.5f);
    bastick_setZoneMax(self, 2, 1.0f);
}

void bastick_func_8009F2A4(PlayerState *self) {
    bastick_setZoneMax(self, 0, 0.12f);
    bastick_setZoneMax(self, 1, 0.6f);
    bastick_setZoneMax(self, 2, 1.0f);
}