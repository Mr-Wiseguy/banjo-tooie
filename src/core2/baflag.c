#include "common.h"

#include "ba/flag.h"

s32 baflag_getStuctSize(void) {
    return sizeof(BaFlag);
}

void baflag_clearAll(PlayerState *self) {
    BaFlagId id;
    for(id = 1; id < NUM_BA_FLAGS; id++){
        baflag_clear(self, id);
    }
}

int baflag_isTrue(PlayerState *self, BaFlagId id) {
    return self->flag->bytes[id];
}

int baflag_isFalse(PlayerState *self, BaFlagId id) {
    return !self->flag->bytes[id];
}

void baflag_set(PlayerState *self, BaFlagId id) {
    self->flag->bytes[id] = 1;
}

void baflag_clear(PlayerState *self, BaFlagId id) {
    self->flag->bytes[id] = 0;
}