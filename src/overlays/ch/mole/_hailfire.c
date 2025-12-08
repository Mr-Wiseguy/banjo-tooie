#include "ch/mole.h"

void func_80800000_chmole_hailfire(Actor*, s32, s32);
void func_80800024_chmole_hailfire(Actor*);
void func_80800090_chmole_hailfire(Actor*);

extern MoveData D_808000C0_chmole_hailfire[] =
{
	{ALLOW_BANJO,0xD98,0xD96,0xD97,0x21,0xFF,0x280,0x14,0x0},
	{ALLOW_KAZOOIE,0xD9B,0xD99,0xD9A,0x22,0xFF,0x294,0x15,0x0}
};
ActorData D_808000E0_chmole_hailfire =
{
	/*0x0*/ 0x02EA,
	/*0x2*/ 0x0184,
	/*0x4*/ 0x0000,
	/*0x6*/ 0x0001,
	/*0x8*/ 0x00000000,
	/*0xC*/ func_80800090_chmole_hailfire,
	/*0x10*/ 0x00000000,
	/*0x14*/ func_8010A730,
	/*0x18*/ 0x01F4,
	/*0x1A*/ 0x0000,
	/*0x1C*/ 0x00000000,
	/*0x20*/ 0x0000,
	/*0x22*/ 0x0000,
	/*0x24*/ 0x0008,
	/*0x26*/ 0x0004,
	/*0x28*/ 0x00000000,
	/*0x2C*/ 0x00000000,
	/*0x30*/ 0x0000,
	/*0x32*/ 0x0000,
	/*0x34*/ func_80800024_chmole_hailfire,
	/*0x38*/ func_80107C2C,
	/*0x3C*/ 0x8000,
	/*0x3E*/ 0x2202,
	/*0x40*/ func_80800000_chmole_hailfire,
	/*0x44*/ 0x0000,
	/*0x46*/ 0x0000,
	/*0x48*/ 0x00000000
};

void func_80800000_chmole_hailfire(Actor* a0, s32 a1, s32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_hailfire);
}

void func_80800024_chmole_hailfire(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_hailfire(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_hailfire);
}

ActorData* chmole_hailfire_entrypoint_0()
{
	return &D_808000E0_chmole_hailfire;
}

