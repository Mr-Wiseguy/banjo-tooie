#include "ch/mole_cuckoo.h"

void func_80800000_chmole_cuckoo(void* a0, u32 a1,u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_cuckoo);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_cuckoo/func_80800024_chmole_cuckoo.s")
#else
void func_80800024_chmole_cuckoo(unkStruc_chmole* a0)
{
	f32 var_f6;
	s16 temp_t2;
	u32 temp_v0;
	u32 temp_t4;
	_sumole_entrypoint_0(a0, 0);
	temp_v0 = a0->unk3[0xF];
	temp_t2 = ((temp_v0 >> 7) - 0x32) << 7;
	temp_t2 = temp_t2 | (temp_v0 & 0x7F);
	temp_t4 = ((u32)(temp_t2 & 0xFFFF)) >> 7;
	a0->unk3[0xF] = temp_t2;
	var_f6 = temp_t4;
	if (temp_t4 < 0)
	{
		var_f6 += 4294967296.0f;
	}
	a0->unk2 = var_f6;
}
#endif

void func_80800090_chmole_cuckoo(void* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_cuckoo);
}

void* chmole_cuckoo_entrypoint_0()
{
	return &D_808000D0_chmole_cuckoo;
}

