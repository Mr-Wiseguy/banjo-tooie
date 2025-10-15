#ifndef __COMMON_H__
#define __COMMON_H__

#include "types.h"

// This hacky structure allows coords to be accessed using
// coord->x, coord->y and coord->z, but also as
// coord->f[0], coord->f[1] and coord->f[2].
// In some places code only matches when using the float array.
typedef union {
    struct {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    f32 f[3];
} Vec3f;

// size: unknown
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

// size: unknown
typedef struct Actor {
    /* 0x00 */ Unk80132ED0* unk0;
    /* 0x04 */ f32 position[3];
    /* 0x10 */ u32* pointerToSyscallEntry;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 actorData[8]; //Cast this array to struct in actor
    /* 0x38 */ f32 scale;
    /* 0x3C */ Unk80132ED0 *unk3C;
    /* 0x40 */ s32 pad40;
    /* 0x44 */ f32 rotation[3];
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ u8 pad5C;
    /* 0x5D */ u8 pad5D;
    /* 0x5E */ u8 pad5E;
    /* 0x5F */ u8 unk5F;
    /* 0x60 */ s32 pad60;
    /* 0x64 */ u32 pad64_29 : 3;
    /* 0x64 */ u32 unk64_28 : 1;
    /* 0x64 */ u32 unk64_27 : 1;
    /* 0x64 */ u32 unk64_26 : 1;
    /* 0x64 */ u32 unk64_25 : 1;
    /* 0x64 */ u32 unk64_24 : 1;
    /* 0x64 */ u32 unk64_23 : 1;
    /* 0x64 */ u32 unk64_22 : 1;
    /* 0x64 */ u32 unk64_21 : 1;
    /* 0x64 */ u32 unk64_20 : 1;
    /* 0x64 */ u32 unk64_19 : 1; // flags & 0x80000
    /* 0x64 */ u32 unk64_18 : 1;
    /* 0x64 */ u32 unk64_17 : 1;
    /* 0x64 */ u32 unk64_16 : 1;
    /* 0x64 */ u32 unk64_0 : 16;
    /* 0x68 */ s32 pad68;
    /* 0x6C */ u32 pad6C_21 : 11;
    /* 0x6C */ u32 unk6C_9 : 12;
    /* 0x6C */ u32 unk6C_0 : 9; // if accessed directly: unk6C & 0x1FF, if assigned: ((u16)valueToAssign & 0x1FF) | (unk6E & 0xFE00);
    /* 0x70 */ u32 pad70_16: 16;
    /* 0x70 */ u32 unk70_10: 6; // unk72 >> 10
    /* 0x70 */ u32 pad70_0: 10;
    /* 0x74 */ u32 pad74_31 : 1;
    /* 0x74 */ u32 unk74_30 : 1; // unk74 & 0x40000000
    /* 0x74 */ u32 unk74_29 : 1; // unk74 & 0x20000000
    /* 0x74 */ u32 pad74_18 : 11;
    /* 0x74 */ u32 unk74_17 : 1;
    /* 0x74 */ u32 pad74_16 : 1;
    /* 0x74 */ u32 unk74_7 : 9; // unk76 >> 7
    /* 0x74 */ u32 pad74_0 : 7;
    /* 0x78 */ u8 unk78;
    /* 0x79 */ u8 unk79_4 : 4;
    /* 0x79 */ u8 unk79_3 : 1;
    /* 0x79 */ u8 unk79_2 : 1;
    /* 0x79 */ u8 unk79_1 : 1;
    /* 0x79 */ u8 unk79_0 : 1;
    /* 0x7A */ u16 pad7A_15:10;
    /* 0x7A */ u16 unk7A_5:1;
    /* 0x7A */ u16 pad7A_0:5;
    /* 0x7C */ u32 pad7C_29 : 3;
    /* 0x7C */ u32 unk7C_28 : 1;
    /* 0x7C */ u32 pad7C_13 : 15;
    /* 0x7C */ u32 unk7C_12 : 1; // unk7C & 0x1000
    /* 0x7C */ u32 unk7C_0 : 12; // unk7C & 0xFFF
    /* 0x80 */ u32 pad80;
    /* 0x84 */ u32 pad84;
    /* 0x88 */ u32 pad88;
    /* 0x8C */ u32 pad8C;
    /* 0x90 */ u32 pad90;
    /* 0x94 */ u32 pad94;
    /* 0x98 */ u8 pad98;
    /* 0x99 */ u8 pad99;
    /* 0x9A */ u8 pad9A;
    /* 0x9B */ u8 alpha;
} Actor;

typedef struct ActorData {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    void *unk8;
    void (*unkC_func)(Actor* actor);
    void (*unk10_func)(Actor* actor);
    void (*unk14_func)(s32 arg0, s32 arg1);
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    void (*unk28_func)(Actor* actor);
    s32 unk2C;
    s16 unk30;
    s16 unk32;
    void (*unk34_func)(Actor* actor);
    void (*unk38_func)(void* arg0, s32 arg1, void* arg2, s32 arg3, void* arg4); // argument types unknown currently
    s16 unk3C;
    s16 unk3E;
    void (*unk40_func)(Actor* actor, s32 arg1, s32 arg2);
    s16 unk44;
    s16 unk46;
    void (*unk48_func)(Actor* actor, s32 arg1, s32 arg2);
    s32 unk4C;
} ActorData;

typedef struct {
    /* 0x0 */ s16 position[3];
    /* 0x6 */ u16 unk6_7 : 9;
    /* 0x6 */ u16 unk6_1 : 6; //unk4 << 0x19 >> 0x1A
    /* 0x6 */ u16 unk6_0 : 1; //unk6 >> 0x7 << 0x7
    /* 0x8 */ u16 ItemID;
    /* 0x0A */ u16 unkA; //0xA
    /* 0x0C */ u32 FlagOrRotation : 9; //unkC >> 0x17
    /* 0x0C */ u32 unkC_0 : 23; //0xC
    /* 0x10 */ u16 unk10; //0x10
    /* 0x12 */ u16 unk12; //0x12
} Prop;


#endif // __COMMON_H__
