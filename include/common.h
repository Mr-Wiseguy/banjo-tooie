#ifndef __COMMON_H__
#define __COMMON_H__

#include "types.h"
#include "actorevents.h"

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
    /* 0x00 */ u32 unk0;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ u16 unkA_16 : 6;
    /* 0x0A */ u16 unkA_14 : 2;
    /* 0x0A */ u16 unkA_4 : 4;
    /* 0x0A */ u16 unkA_3 : 1;
    /* 0x0A */ u16 unkA_0 : 3;
    /* 0x0C */ u32 unkC;
} Unk80132ED0_2;

typedef struct {
	void ( *unk0) (s32, s32);
	void (*unk4) (s32, s32);
	void (*unk8) (s32, s32);
} CallbackTable;

// size: unknown
typedef struct {
    /* 0x00 */ Unk80132ED0_2* unk0;
    /* 0x04 */ u32* unk4;
    /* 0x08 */ CallbackTable* (*unk8)(void);
    /* 0x0C */ u32 unkC;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u16 unk12_1:15;
    /* 0x12 */ u16 unk12_0 : 1;
    /* 0x14 */ u16 unk14; //Model
    /* 0x16 */ u16 unk16;
	/* 0x18 */ u32 unk18_17 : 15;
	/* 0x18 */ u32 unk18_16 : 1;
	/* 0x18 */ u32 unk18_5 : 11; //Actor Index
	/* 0x18 */ u32 unk18_1 : 4;
	/* 0x18 */ u32 unk18_0 : 1;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24_22 : 10;
    /* 0x24 */ u32 unk24_16 : 6;
    /* 0x24 */ u32 unk24_7 : 9;
	/* 0x24 */ u32 unk24_0 : 7;
	/* 0x28 */ u32 unk28_23 : 9;
	/* 0x28 */ u32 unk28_14 : 9;
	/* 0x28 */ u32 unk28_13 : 1;
	/* 0x28 */ u32 unk28_12 : 1;
    /* 0x28 */ u32 unk28_11 : 1;
    /* 0x28 */ u32 unk28_10 : 1;
    /* 0x28 */ u32 unk28_9 : 1;
    /* 0x28 */ u32 unk28_0 : 9;
    /* 0x2C */ u32 unk2C;
} Unk80132ED0;

// size: unknown
typedef struct Actor {
    /* 0x00 */ Unk80132ED0* unk0;
    /* 0x04 */ f32 position[3];
    /* 0x10 */ void* (*pointerToSyscallEntry)();
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 actorData[8]; //Cast this array to struct in actor
    /* 0x38 */ f32 scale;
    /* 0x3C */ Unk80132ED0* unk3C; //Child Object?
    /* 0x40 */ Unk80132ED0* unk40; //Shadow Reference?
    /* 0x44 */ f32 rotation[3];
    /* 0x50 */ f32 unk50;
    union
    {
        /* 0x54 */ f32 unk54;
        /* 0x54 */ s32 unk54s;
    };
    /* 0x58 */ f32 unk58;
    /* 0x5C */ u8 unk5C[3];
    /* 0x5F */ u8 unk5F;
    /* 0x60 */ s32 pad60;
    /* 0x64 */ u32 unk64_31 : 1;
    /* 0x64 */ u32 unk64_30 : 1;
    /* 0x64 */ u32 unk64_29 : 1; //unk64 & 0x20000000
    /* 0x64 */ u32 unk64_28 : 1;
    /* 0x64 */ u32 unk64_27 : 1;
    /* 0x64 */ u32 unk64_26 : 1;
    /* 0x64 */ u32 unk64_25 : 1;
    /* 0x64 */ u32 unk64_24 : 1; //unk64 & 0xFFFE
    /* 0x64 */ u32 unk64_23 : 1;
    /* 0x64 */ u32 unk64_22 : 1;
    /* 0x64 */ u32 unk64_21 : 1;
    /* 0x64 */ u32 unk64_20 : 1; //unk65 & 0xFFEF or unk65 | 0x10
    /* 0x64 */ u32 unk64_19 : 1; // flags & 0x80000 (unk65 & 0xFFF7)
    /* 0x64 */ u32 unk64_18 : 1;
    /* 0x64 */ u32 unk64_17 : 1; //Marked for Deletion?
    /* 0x64 */ u32 unk64_16 : 1;
    /* 0x64 */ u32 unk64_0 : 16;
    /* 0x68 */ s32 pad68;
    /* 0x6C */ u32 unk6C_21 : 11;
    /* 0x6C */ u32 unk6C_9 : 12; //PropId
    /* 0x6C */ u32 unk6C_0 : 9; // if accessed directly: unk6C & 0x1FF, if assigned: ((u16)valueToAssign & 0x1FF) | (unk6E & 0xFE00);
    /* 0x70 */ u32 unk70_25 : 7;//unk70 >> 0x19
    /* 0x70 */ u32 unk70_24 : 1;
    /* 0x70 */ u32 unk70_23 : 1;
	/* 0x70 */ u32 unk70_22 : 1;
    /* 0x70 */ u32 unk70_21 : 1;
    /* 0x70 */ u32 unk70_20 : 1;
    /* 0x70 */ u32 unk70_19 : 1;
    /* 0x70 */ u32 unk70_18 : 1;
    /* 0x70 */ u32 unk70_17 : 1;
    /* 0x70 */ u32 unk70_16 : 1;
    /* 0x70 */ u32 unk70_10: 6; // unk72 >> 10 ActorState
    /* 0x70 */ u32 unk70_4 : 6; //(unk70 << 0x16) >> 0x1A
    /* 0x70 */ u32 unk70_3 : 1;
    /* 0x70 */ u32 unk70_2 : 1;
    /* 0x70 */ u32 unk70_1 : 1;
    /* 0x70 */ u32 unk70_0 : 1;
    /* 0x74 */ u32 unk74_31 : 1;
    /* 0x74 */ u32 unk74_30 : 1; // unk74 & 0x40000000
    /* 0x74 */ u32 unk74_29 : 1; // unk74 & 0x20000000
    /* 0x74 */ u32 unk74_28 : 1; //Has Event Handler
    /* 0x74 */ u32 unk74_27 : 1;
    /* 0x74 */ u32 unk74_26 : 1;
    /* 0x74 */ u32 unk74_25 : 1;
    /* 0x74 */ u32 unk74_24 : 1;
    /* 0x74 */ u32 unk74_23 : 1;
    /* 0x74 */ u32 unk74_22 : 1;
    /* 0x74 */ u32 unk74_21 : 1;
    /* 0x74 */ u32 unk74_20 : 1;
    /* 0x74 */ u32 unk74_19 : 1;
    /* 0x74 */ u32 unk74_18 : 1;
    /* 0x74 */ u32 unk74_17 : 1;
    /* 0x74 */ u32 unk74_16 : 1;
    /* 0x74 */ u32 unk74_7 : 9; // unk76 >> 7
    /* 0x74 */ u32 unk74_6 : 1;
    /* 0x74 */ u32 unk74_5 : 1;
    /* 0x74 */ u32 unk74_4 : 1;
	/* 0x74 */ u32 unk74_0 : 4; //unk77 & 0xFFF0
    /* 0x78 */ u8 unk78;
    /* 0x79 */ u8 unk79_4 : 4;
    /* 0x79 */ u8 unk79_3 : 1; 
    /* 0x79 */ u8 unk79_2 : 1;
    /* 0x79 */ u8 unk79_0 : 2; //unk78 & 3
    /* 0x7A */ u16 unk7A_14 : 2;
    /* 0x7A */ u16 unk7A_12 : 2;
	/* 0x7A */ u16 unk7A_9 : 3;
    /* 0x7A */ u16 unk7A_8 : 1;
    /* 0x7A */ u16 unk7A_7 : 1;
	/* 0x7A */ u16 unk7A_6 : 1;
    /* 0x7A */ u16 unk7A_5 : 1; //unk78 & 0x20
    /* 0x7A */ u16 unk7A_4 : 1; 
    /* 0x7A */ u16 unk7A_3 : 1;
    /* 0x7A */ u16 unk7A_2 : 1; //unk78 & 4
    /* 0x7A */ u16 unk7A_1 : 1;
    /* 0x7A */ u16 unk7A_0 : 1;
    union {
        struct {
            u16 unk7C;
            s16 unk7E;
        };
        struct {
            /* 0x7C */ u32 pad7C_29 : 3;
            /* 0x7C */ u32 unk7C_28 : 1;
            /* 0x7C */ u32 pad7C_16 : 12;
            /* 0x7C */ u32 unk7C_15 : 1; //unk7E | 0x80 IsInitialized
            /* 0x7C */ u32 unk7C_14 : 1;
            /* 0x7C */ u32 unk7C_13 : 1;
            /* 0x7C */ u32 unk7C_12 : 1; // unk7C & 0x1000
            /* 0x7C */ u32 unk7C_0 : 12; // unk7C & 0xFFF
        };
    };
    /* 0x80 */ s16 pad80;
    /* 0x82 */ s16 unk82[2]; //Holds index of extra memory
    /* 0x86 */ s16 pad86;
    /* 0x88 */ u32 pad88;
    /* 0x8C */ s16 unk8C;
	/* 0x8E */ s16 unk8E;
    /* 0x90 */ s16 unk90;
    /* 0x92 */ s16 unk92;
    /* 0x94 */ u32 unk94_31 : 1;
    /* 0x94 */ u32 unk94_30 : 1;
    /* 0x94 */ u32 unk94_20 : 10; //(unk94 * 4) >> 0x16
    /* 0x94 */ u32 pad94_18 : 2;
    /* 0x94 */ u32 unk94_17 : 1;
    /* 0x94 */ u32 unk94_16 : 1;
    /* 0x94 */ u32 pad94_15 : 1;
    /* 0x94 */ u32 unk94_14 : 1;
    /* 0x94 */ u32 pad94_0 : 14;
    /* 0x98 */ u8 unk98; //r
    /* 0x99 */ u8 unk99; //g
    /* 0x9A */ u8 unk9A; //b
    /* 0x9B */ u8 alpha;
} Actor;
typedef struct {
    /* 0x0 */ s16 position[3];
    /* 0x6 */ u16 unk6_7 : 9;
    /* 0x6 */ u16 unk6_1 : 6; //unk4 << 0x19 >> 0x1A
    /* 0x6 */ u16 unk6_0 : 1; //unk6 >> 0x7 << 0x7
    /* 0x8 */ u16 PropID;
    /* 0x0A */ u16 unkA; //0xA
    /* 0x0C */ u32 FlagOrRotation : 9; //unkC >> 0x17
    /* 0x0C */ u32 unkC_0 : 23; //0xC
    /* 0x10 */ u16 unk10_5 : 11;
    /* 0x10 */ u16 unk10_0 : 5;
    /* 0x12 */ u16 unk12_9 : 7;
    /* 0x12 */ u16 unk12_8 : 1;
    /* 0x12 */ u16 unk12_7 : 1;
    /* 0x12 */ u16 unk12_2 : 5;
    /* 0x12 */ u16 unk12_1 : 1;
    /* 0x12 */ u16 unk12_0 : 1;
} Prop;
typedef struct {
    Gfx* gfx;
    Mtx* mtx;
} GraphicsBuffers;

typedef struct ActorData {
    s16 unk0;
    s16 unk2; //PropId
    u16 Model;
    s16 unk6;
    void *unk8;
    void (*update_func)(Actor* actor); //Update
    void (*unk10_func)(Actor* actor);
    void (*unk14_func)(Actor* arg0, GraphicsBuffers* arg1);
    u16 unk18;
    u16 unk1A;
    f32 unk1C;
    s16 unk20;
    u16 unk22;
	union {
		struct {
			s16 unk24;
			s16 unk26;
		};
		s32 unk24w;
	};
    void (*unk28_func)(Actor* actor); //Destructor
    void* (*unk2C_func)();
    u16 unk30;
    u16 unk32;
    void (*unk34_func)(Actor* actor);
    //Arg2 is ActorData*
	Actor* (*unk38_func)(void* arg0, s32 arg1, void* arg2, s32 arg3, Prop* arg4); // argument types unknown currently
	union {
		struct {
			s16 unk3C;
			s16 unk3E;
		};
		s32 unk3Cw; //Collision Mask?
	};
    s32 (*eventHandler)(Actor* actor, ActorEventId arg1, s32 arg2);
    s16 unk44;
    s16 unk46;
} ActorData;




#endif // __COMMON_H__
