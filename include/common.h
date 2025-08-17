#ifndef __COMMON_H__
#define __COMMON_H__

#include "types.h"

typedef struct {
    /* 0x00 */ u32* unk0;
    /* 0x04 */ u32* unk4;
    /* 0x08 */ u32* unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u32 unk2C;
} Unk80132ED0;

typedef struct {
    /* 0x00 */ Unk80132ED0* unk0;
    /* 0x04 */ f32 position[3];
    /* 0x10 */ u32* pointerToSyscallEntry;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ f32 unk18[3];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ u32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 scale;
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ f32 rotation[3];
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */  f32 unk58;
    /* 0x5C */  u8 unk5C;
    /* 0x5D */ u8 unk5D;
    /* 0x5E */ u8 unk5E;
    /* 0x5F */ u8 unk5F;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ u32 unk64_20 : 12;
    /* 0x64 */ u32 unk64_19 : 1;
    /* 0x64 */ u32 unk64_18 : 1;
    /* 0x64 */ u32 unk64_17 : 1;
    /* 0x64 */ u32 unk64_16 : 1;
    /* 0x68 */ u32 unk68;
    /* 0x68 */ u32 unk6C_24 : 7;
    /* 0x68 */ u32 unk6C_16 : 9;
    /* 0x68 */ u32 unk6C_8 : 7;
    /* 0x68 */ u32 unk6C_0 : 9;
    /* 0x70 */ u16 unk70;
    /* 0x72 */ u16 unk72;
    /* 0x74 */ u32 unk74_31 : 1;
    /* 0x74 */ u32 unk74_30 : 1;
    /* 0x74 */ u32 unk74_16 : 14;
    /* 0x74 */ u32 unk74_7 : 9;
    /* 0x78 */ u8 unk78;
    /* 0x79 */ u8 unk79_4 : 4;
    /* 0x79 */ u8 unk79_3 : 1;
    /* 0x79 */ u8 unk79_2 : 1;
    /* 0x79 */ u8 unk79_1 : 1;
    /* 0x79 */ u8 unk79_0 : 1;
    /* 0x7A */ u16 unk7A;
    /* 0x7C */ u32 unk7C_13 : 19;
    /* 0x7C */ u32 unk7C_12 : 1;
    /* 0x7C */ u32 unk7C_14 : 12;
    /* 0x80 */ u16 unk80;
    /* 0x82 */ s16 IndexForMemory;
    /* 0x84 */ u8 unk84[0x18];
} Actor;


typedef struct {
    /* 0x0 */ s16 position[3];
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 ItemID;
    /* 0x0A */ u16 unkA; //0xA
    /* 0x0C */ u32 unkC; //0xC
    /* 0x10 */ u16 unk10; //0x10
    /* 0x12 */ u16 unk12; //0x12
    /* 0x14 */ u8 unk14; //0x14
} Prop;


#endif // __COMMON_H__
