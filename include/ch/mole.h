#ifndef __CH_MOLE_CUCKOO_H__
#define __CH_MOLE_CUCKOO_H__

#include "common.h"
#include "su/mole.h"
typedef struct {
	/* 0x00 */ u32 unk0;
	/* 0x04 */ u32 unk4;
	/* 0x08 */ u32 unk8;
	/* 0x0C */ u32* unkC;
	/* 0x10 */ u32 unk10;
	/* 0x14 */ u32* unk14; //8010A730
	/* 0x18 */ u32 unk18;
	/* 0x1C */ u32 unk1C;
	/* 0x20 */ u32 unk20;
	/* 0x24 */ u32 unk24;
	/* 0x28 */ u32 unk28;
	/* 0x2C */ u32 unk2C;
	/* 0x30 */ u32 unk30;
	/* 0x34 */ u32* unk34;
	/* 0x38 */ u32* unk38; //80107C2C
	/* 0x3C */ u32 unk3C;
	/* 0x40 */ u32 unk40; //func_80800000
	/* 0x44 */ u32 unk44;
	/* 0x48 */ u32 unk48;

} D_808000D0;


#endif 