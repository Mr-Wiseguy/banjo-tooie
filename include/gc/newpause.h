#ifndef __GC_NEWPAUSE_H__
#define __GC_NEWPAUSE_H__
#include "common.h"
#include "memory.h"
#include "gc/newoption.h"

typedef struct {
	u8 data[0x14];
	u32* textPointer;//0x14
	s16 pageTitleOffset; //0x18
	u8 unk1A; //0x1A
	u8 unk1B; //0x1B
	u8 pad[0x14];
	OptionState optionState;
} PauseState;

void gcnewpause_entrypoint_0(void);
void func_80800534_gcnewpause(PauseState* a0, u32 a1);
void func_80800E10_gcnewpause(PauseState* a0, u32 a1);
void func_8080105C_gcnewpause(u32 a0, u32 a1, u32 a2, u32 a3);
u8 func_80801248_gcnewpause(u32* a0, u32* a1, u32 a2, PauseState* a3);
void func_808012CC_gcnewpause(PauseState* a0, u32* a1);
u8 func_80801330_gcnewpause(PauseState* a0, u32 a1, u32 a2);
u8 func_8080152C_gcnewpause(PauseState* a0);
void func_80801E80_gcnewpause(u32 a0, u32 a1);
void func_80801EF0_gcnewpause(u32 a0);

u32 func_80801F18_gcnewpause(u32 a0);



#endif
