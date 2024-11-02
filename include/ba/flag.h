#ifndef __BA_FLAG_H__
#define __BA_FLAG_H__

#include <ultra64.h>

#include "ba/playerstate.h"

typedef enum {
    BA_FLAG_0, // unused
    BA_FLAG_1_ON_FLIGHT_PAD,
    BA_FLAG_2_ON_SPRING_PAD,
    BA_FLAG_3,
    BA_FLAG_4,
    BA_FLAG_5_HAS_PECKED,
    BA_FLAG_6,
    BA_FLAG_7,
    BA_FLAG_8,
    BA_FLAG_9,
    BA_FLAG_A,
    BA_FLAG_B,
    BA_FLAG_C,
    BA_FLAG_D, // unused
    BA_FLAG_E_TOUCHING_WADING_BOOTS,
    BA_FLAG_F, // related to A button ?
    BA_FLAG_10_TOUCHING_TURBO_TRAINERS,
    BA_FLAG_11, // unused
    BA_FLAG_12_HAS_FLAPPED, // has used flap
    BA_FLAG_13, // related to ground damage ?
    BA_FLAG_14_LOSE_BOGGY_RACE, // in difficult terrain (mud)
    BA_FLAG_15_LOADZONE, // touching loadzone?
    BA_FLAG_16, // related to flying
    BA_FLAG_17_FIRST_PERSON_VIEW,
    BA_FLAG_18, // related to underwater state
    BA_FLAG_19, // related to transformations
    BA_FLAG_1A, // related to bee transformation
    BA_FLAG_1B_TRANSFORMING,
    NUM_BA_FLAGS = 0x42
} BaFlagId;

typedef struct ba_flag_s {
    u8 bytes[NUM_BA_FLAGS];
} BaFlag;

// Definitions
s32 baflag_getStuctSize(void);
void baflag_clearAll(PlayerState *self);
int baflag_isTrue(PlayerState *self, BaFlagId id);
int baflag_isFalse(PlayerState *self, BaFlagId id);
void baflag_set(PlayerState *self, BaFlagId id);
void baflag_clear(PlayerState *self, BaFlagId id);

#endif // __BA_FLAG_H__
