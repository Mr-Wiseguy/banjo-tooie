#ifndef __GC_NEWPAUSE_H__
#define __GC_NEWPAUSE_H__
#include "common.h"
#include "memory.h"

typedef struct {
	u8 data[0x14];
	u32* textPointer;//0x14
	s16 pageTitleOffset; //0x18
	u8 unk1A; //0x1A
	u8 unk1B; //0x1B
} PauseState;

u8 func_80801248_gcnewpause(u32* a0, u32* a1, u32 a2, PauseState* a3);
void func_808012CC_gcnewpause(PauseState* a0, u32* a1);
u8 func_80801330_gcnewpause(PauseState* a0, u32 a1, u32 a2);



#endif
