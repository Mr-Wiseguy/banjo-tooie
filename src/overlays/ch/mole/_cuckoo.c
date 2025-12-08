#include "ch/mole.h"

void func_80800000_chmole_cuckoo(Actor*, s32, s32);
void func_80800024_chmole_cuckoo(Actor*);
void func_80800090_chmole_cuckoo(Actor*);


MoveData D_808000C0_chmole_cuckoo[] =
{
	{ALLOW_BANJO,0xDB5,0xDB3,0xDB4,0x2A,0xFF,0x2FD,0x19,0x0}
};
ActorData D_808000D0_chmole_cuckoo = 
{
	/*0x0*/ 0x02EA,
	/*0x2*/ 0x0376,
	/*0x4*/ 0x0,
	/*0x6*/ 0x1,
	/*0x8*/ 0,
	/*0xC*/ func_80800090_chmole_cuckoo,
	/*0x10*/ 0,
	/*0x14*/ func_8010A730,
	/*0x18*/ 0x1F4,
	/*0x1A*/ 0,
	/*0x1C*/ 0,
	/*0x20*/ 0,
	/*0x22*/ 0,
	/*0x24*/ 0x8,
	/*0x26*/ 0x4,
	/*0x28*/ 0,
	/*0x2C*/ 0,
	/*0x30*/ 0,
	/*0x32*/ 0,
	/*0x34*/ func_80800024_chmole_cuckoo,
	/*0x38*/ func_80107C2C,
	/*0x3C*/ 0x8000,
	/*0x3E*/ 0x2202,
	/*0x40*/ func_80800000_chmole_cuckoo,
	/*0x44*/ 0,
	/*0x46*/ 0,
	/*0x48*/ 0
};

void func_80800000_chmole_cuckoo(Actor* a0, s32 a1,s32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_cuckoo);
}

void func_80800024_chmole_cuckoo(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_cuckoo(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_cuckoo);
}

ActorData* chmole_cuckoo_entrypoint_0()
{
	return &D_808000D0_chmole_cuckoo;
}

