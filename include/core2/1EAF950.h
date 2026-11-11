#ifndef __CORE2_1EAF950_H__
#define __CORE2_1EAF950_H__

#include <common.h>
#include "ba/playerstate.h"

typedef struct {
	s16 unk0;
	u8 pad2[0x6];
	s16 unk8;
	s16 unkA;
} ImageStruct;

void func_800D62E4(s32, s32, PlayerState*);
void func_800D66AC();
ImageStruct *func_800D674C(s32 a0);
void func_800D6C64();
s32 func_800D6CEC(s16);
void func_800D6D68(void);
void func_800D70D0(s32);
s32 func_800D70F8(s16, s32);
void func_800D71F4(s32);
s32 func_800D721C(s16, s32);
u8 func_800D731C(u16);
void func_800D740C();
void *func_800D7520(s32);
void func_800D8674(void);

#endif
