#include "ch/mole.h"

extern MoveData D_808000C0_chmole_lagoon[];
extern D_808000D0 D_808000F0_chmole_lagoon;

void func_80800000_chmole_lagoon(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_lagoon);
}

void func_80800024_chmole_lagoon(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_lagoon(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_lagoon);
}

void* chmole_lagoon_entrypoint_0()
{
	return &D_808000F0_chmole_lagoon;
}

