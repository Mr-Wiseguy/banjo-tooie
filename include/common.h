#ifndef __COMMON_H__
#define __COMMON_H__

#include "types.h"

typedef struct {
    u32* unk0;
    u32* unk4;
    u32* unk8;
    u32 unkC;
    u32 unk10;
    u16 unk14;
    u16 unk16;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
} Unk80132ED0;

typedef struct {
    Unk80132ED0* unk0;
    f32 position[3];
    u32* pointerToSyscallEntry;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u32 unk30;
    f32 unk34;
    f32 scale;
    u32 unk3C;
    u32 unk40;
    f32 rotation[3];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    f32 unk60;
    u32 unk64_20 : 12;
    u32 unk64_19 : 1;
    u32 unk64_18 : 1;
    u32 unk64_17 : 1;
    u32 unk64_16 : 1;
    u32 unk68;
    u16 unk6C;
    u16 unk6E;
    u16 unk70;
    u16 unk72;
    u32 unk74_31 : 1;
    u32 unk74_30 : 1;
    u32 unk74_16 : 14;
    u32 unk74_7 : 9;
    u8 unk78;
    u8 unk79;
    u16 unk7A;
    u32 unk7C_13 : 19;
    u32 unk7C_12 : 1;
    u32 unk7C_14 : 12;
    u16 unk80;
    s16 IndexForMemory;
    u8 unk84[0x18];
} Actor;


typedef struct {
    s16 position[3]; //0x0
    u16 unk6;
    u16 ItemID; //0x8
    u16 unkA; //0xA
    u32 unkC; //0xC
    u16 unk10; //0x10
    u16 unk12; //0x12
    u8 unk14; //0x14
} Prop;


#endif // __COMMON_H__
