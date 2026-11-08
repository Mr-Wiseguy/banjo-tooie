#ifndef __BA_SHOES_H__
#define __BA_SHOES_H__

#include <ultra64.h>

#include "ba/playerstate.h"

typedef enum ShoeTypes {

	SHOETYPE_NO_SHOES = 0x2,
	SHOETYPE_TURBO_TRAINER = 0x3,
	SHOETYPE_CLAW_CLAMBER = 0x4,
	SHOETYPE_SPRINGY_STEP = 0x5
} ShoeType;

//Get Type of shoe being worn
ShoeType _bashoes_entrypoint_1(PlayerState *self);
s32 _bashoes_entrypoint_2(PlayerState *self);
void _bashoes_entrypoint_3(PlayerState*);
void _bashoes_entrypoint_4(PlayerState*);
void _bashoes_entrypoint_5(PlayerState *self, s32);
void _bashoes_entrypoint_6(PlayerState *self, s32);
void _bashoes_entrypoint_7(s32, s32 *);
void _bashoes_entrypoint_8(s32, s32 *);
void _bashoes_entrypoint_13(PlayerState*);
void _bashoes_entrypoint_14(PlayerState *self);
void _bashoes_entrypoint_15();
void _bashoes_entrypoint_16(PlayerState *self);
void _bashoes_entrypoint_17(PlayerState *self);
void _bashoes_entrypoint_18(PlayerState *self);
void _bashoes_entrypoint_19(PlayerState *self);
void _bashoes_entrypoint_20(PlayerState *self);

#endif // __BA_SHOES_H__
