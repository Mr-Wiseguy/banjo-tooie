#ifndef __BANJOSTATE_H__
#define __BANJOSTATE_H__

#include "common.h"

#include "buttons.h"
#include "core1/mlmtx.h"
#include "physicstypes.h"
#include "transformations.h"

typedef struct unkCUnk0 {
	s32 unk0;
	s32 unk4;
	s32 unk8;
	s32 unkC;
	s32 unk10;
	s32 unk14;
	s16 unk18;
    u16 unk1A;
	s16 unk1C;
	s16 unk1E;
	s32 unk20;
	s32 unk24;
	union {
		s32 unk28;
		struct {
			s32 unk28_11 : 21;
			s32 unk28_10 : 1;
			s32 unk28_9 : 1;
		};
	};

} unkCUnk0;
typedef struct ba_unknown_c_s {
	unkCUnk0* unk0;
	s32 pad4[2];
	s32 unkC[3];
	s32 unk18;
} BaUnknownC;

typedef struct ba_unknown_2C_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC[3];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} BaUnknown2C;

typedef struct {
    s32 unk0;
    Vec3f unk4[0x17];
} UNKfunc_800DBEB0_ARG0;

typedef struct ba_unknown_38_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    f32 unk2C;
    f32 unk30;
    s16 unk34;
    s16 unk36;
    u8 pad38;
    u8 unk39;
    u8 unk3A;
    u8 unk3B;
    s32 unk3C;
} ba_unknown_38_s;

typedef struct ba_unknown_50_s {
    u16 unk0;
    u16 unk2;
    UNKfunc_800DBEB0_ARG0* unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C[3];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44[3];
    s32 unk50[3];
    f32 unk5C;
    f32 unk60;
    s32 unk64[3];
    f32 unk70;
    f32 unk74;
    f32 unk78;
    u8 unk7C;
    u8 unk7D;
    u8 unk7E;
    u8 unk7F;
    u8 unk80;
    u8 unk81;
    u8 unk82;
    u8 unk83;
    s32 unk84;
    u8 unk88;
    u8 unk89;
    u8 unk8A;
    u8 unk8B;
    u8 unk8C;
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
    u16 unk90;
    u16 unk92;
    s32 unk94;
    f32 unk98;
    s16 unk9C;
    s16 unk9E;
    u8 unkA0;
    u8 unkA1;
    u8 unkA2;
    u8 unkA3;
    s8 unkA4;
    s8 unkA5;
    s8 padA6[0x1E];
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
    f32 unkC8;
    MtxF unkCC;
} BaUnknown50;
typedef struct ba_unk54_s {
	u8 unk0;
	u8 unk1;
	u8 unk2;
	u8 unk3;
	u8 unk4;
	u8 unk5;
	u8 unk6;
	u8 unk7;
	f32 unk8;
	f32 unkC;
	f32 unk10[3];
	void* (*unk1C)(s32,s32,s32);
	s32 unk20;
	f32 unk24[3];
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    f32 unk34[3];
	f32 unk40;
	f32 unk44;
	s32 unk48;
} BaUnknown54;
typedef struct {
    s32 unk0;
    u8 pad4[0x18];
    f32 unk1C[3][3];
    u8 pad40[0x24];
    f32 unk64[3];
    f32 unk74;
    f32 unk78;
    s32 unk7C;
    u8 pad80[0xC];
    s16 unk8C;
    u8 pad8E[5];
    u8 unk93;
    u8 pad94;
    u8 unk95;
} UNKfunc_800C68A0_ARG0;
typedef struct ba_unknown_94_s {
    UNKfunc_800C68A0_ARG0* unk0;
    f32 unk4;
    f32 unk8;
    void (*unkC)(s32 arg0, void* arg1);
    void (*unk10)(void* arg0);
    s32 unk14;
    u8 unk18[4];
    s32 unk1C;
    f32 unk20[3][3];
    f32 unk44[3];
    u8 unk50[0x14];
    f32 unk64;
    f32 unk68;
    u8 unk6C[8];
    s32 unk74;
    f32 unk78[3];
    f32 unk84[3];
    f32 unk90[3];
    s32 unk9C;
    u8 unkA0[2];
    u8 unkA2;
    u8 unkA3;
    u8 unkA4;
    u8 padA5[3];
    s32 unkA8;
} ba_unknown_94_s;
typedef struct ba_unknown_98_s {
    f32 unk0[3];
    f32 unkC[3];      // was: u8 padC[0xC];
    f32 unk18[3];
    u8 unk24;
    u8 unk25;
    u8 unk26;
} ba_unknown_98_s;
typedef struct ba_dust_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} BaDust;
typedef struct ba_cursor_s {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    f32 unkC;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    s32 unk14;
    f32 unk18;
} BaCursor;
typedef struct ba_unknown_6C_s {
	f32 unk0;
	s32 unk4;
	s32 unk8;
	s32 unkC;
	u8 unk10;
	u8 unk11;
	u8 unk12;
	u8 unk13;
} BaUnknown6C;

typedef struct ba_unknown_8C_s {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    s8 unkA;
    s8 unkB;
    s16 unkC;
    u8 unkE;
} BaUnknown8C;

typedef struct ba_hold_s {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    u8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    s32 unk14;
    f32 unk18;
} BaHold;

typedef struct ba_unkA0_s {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24;
    u8 unk28;
    u8 transformation;
    u8 unk2A;
    u8 unk2B;
    f32 unk2C[3];
    f32 unk38;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    f32 unk40;
    Unk80132ED0* unk44;
    f32 unk48;
    f32 unk4C;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
} ba_unkA0_s;

typedef struct ba_unknown_B8_s {
    void (*unk0)(s32);
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} ba_unknown_B8_s;

typedef struct ba_unknown_BC_s {
    f32 unk0[3];
    f32 unkC[3];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
} ba_unknown_BC_s;

typedef struct ba_unknown_C8_s {
    BaPhysicsType currentPhysicsType;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34[3];
    f32 unk40[3];
    f32 unk4C[3];
    u8 pad58[0x54];
    f32 unkAC[3];
    f32 unkB8[3];
} ba_unknown_C8_s;

typedef struct ba_unknown_DC_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} ba_unknown_DC_s;

typedef struct PositionInfo {
    f32 current[3];
    f32 oldPos[3];
    f32 olderPos[3];
    f32 unk24[3];
} PositionInfo;

typedef struct ba_unknown_E8_s {
	u8 unk0;
	u8 unk1;
	u8 unk2;
	u8 unk3;
	f32 unk4;
	f32 unk8;
} ba_unknown_E8_s;

typedef struct ba_unknown_134_s {
    f32 unk0;
    f32 unk4;
} BaUnknown134;

typedef struct ba_unknown_138_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
} BaUnknown138;

typedef struct ba_deathmatch_s {
    s16 unk0[4];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
} BaDeathmatch;

typedef struct bs_kazfly_s {
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    u8 unk1C;
} BsKazFly;

typedef struct bs_firstp_s {
    s32 unk0;
    f32 unk4[3];
    f32 unk10[2];
	f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s32 unk28;
    f32 unk2C[3];
    f32 unk38[3];
    f32 unk44[3];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    u8 pad64[0x28];
    s32 unk8C;
    f32 unk90;
    u8 pad94[0x4C];
    s16 unkE0;
    s16 unkE2;
    s16 unkE4;
    s16 unkE6;
    s16 unkE8;
    s16 unkEA;
    u8 padEC[0x120];
    f32 unk20C;
} BsFirstP;
typedef struct bs_van_s {
    s32 unk0;
    f32 unk4[3];
    s32 unk10;
} BsVan;

typedef struct ba_unknown_150_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[1];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} BaUnknown150;

typedef struct player_state_s {
    /* 0x00 */ struct ba_alarm_s *alarm;
    /* 0x04 */ struct ba_anim_s *anim;
    /* 0x08 */ struct ba_attach_s *attach;
    /* 0x0C */ struct ba_unknown_c_s *unkC; // baavatar? from BK XBox debug strings?
    /* 0x10 */ struct ba_babykaz_s *babykaz;
    /* 0x14 */ struct ba_backpack_s *backpack;
    u8 pad18[0x4];
    /* 0x1C */ struct ba_bee_s *bee;
    /* 0x20 */ struct ba_unknown_20_s *unk20;
    /* 0x24 */ struct ba_boost_s *boost;
    /* 0x28 */ struct ba_bounce_s *bounce;
    /* 0x2C */ struct ba_unknown_2C_s *unk2C; //something with camera
    u8 pad30[0x4];
    /* 0x34 */ struct ba_buzz_s *buzz;
    /* 0x38 */ struct ba_unknown_38_s *unk38;
    /* 0x3C */ struct ba_state_timer_list_s *state_timer; // clock?
    /* 0x40 */ struct ba_key_s *key; // controller?
    /* 0x44 */ struct ba_cough_s *cough;
    u8 unk48;
    u8 pad49[0x7];
    struct ba_unknown_50_s* unk50;
    /* 0x54 */  BaUnknown54* unk54;
    u8 pad58[0x4];
    /* 0x5C */ BaDust* dust;
    u8 pad60[0x4];
    u8* unk64;
    /* 0x68 */ BaCursor* cursor;
	struct ba_unknown_6C_s* unk6C;
	u8 pad70[0x10];
    /* 0x80 */ struct ba_flag_s *flag;
    u8 pad84[0x8];
    /* 0x8C */ struct ba_unknown_8C_s* unk8C;
    u8 pad90[0x4];
    /* 0x94 */ struct ba_unknown_94_s* unk94;
    /* 0x98 */ struct ba_unknown_98_s* unk98;
    /* 0x9C */ BaHold* hold;
    /* 0xA0 */ ba_unkA0_s* unkA0;
    /* 0xA4 */ struct ba_input_s *input;
    u8 padA8[0x10];
    /* 0xB8 */ struct ba_unknown_B8_s* unkB8;
    /* 0xBC */ struct ba_unknown_BC_s* unkBC;
    /* 0xC0 */ struct ba_unknown_C0_s *unkC0; // 1E72EA0
    /* 0xC4 */ u8 *unkC4;
    /* 0xC8 */ struct ba_unknown_C8_s *unkC8;
    u8 padCC[0xDC - 0xCC];
    /* 0xDC */ ba_unknown_DC_s* unkDC;
    u8 padE0[4];
    /* 0xE4 */ PositionInfo* posInfo;
	/* 0xE8 */ ba_unknown_E8_s* unkE8;
	u8 padEC[0x8];
    /* 0xF4 */ struct ba_roll_s *roll;
    /* 0xF8 */ struct ba_yaw_s *yaw;
    u8 padFC[0x24];
    /* 0x120 */ struct bs_state_s *state;
    u8 pad124[4];
    /* 0x128 */ struct ba_stick_s *stick;
    u8 pad12C[0x8];
    /* 0x134 */ BaUnknown134* swim;
    /* 0x138 */ struct ba_unknown_138_s *unk138;
    /* 0x13C */ struct ba_timer_s *timer;
    /* 0x140 */ struct ba_translate_s *translate;
    /* 0x144 */ struct ba_van_s *van;
    /* 0x148 */ struct ba_wandglow_s *wandglow;
    /* 0x14C */ struct ba_washer_s *washer;
    /* 0x150 */ struct ba_unknown_150_s *unk150;
    /* 0x154 */ struct ba_wobble_s *wobble;
    /* 0x158 */ BaDeathmatch* deathmatch;
    union {
        s32 word;
        u8 bytes[4];
    } unk15C; // Some sort of state
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    union {
        s32 word;
        u8 bytes[4];
    } unk164;
    union {
        s32 word;
        u8 bytes[4];
    } unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    f32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    union var188 {
        /* 0x188 */ BsKazFly* kazfly;
        /* 0x188 */ BsFirstP* firstp;
        /* 0x188 */ BsVan* bsvan;
    };
    s32 unk18C;
	union {
		f32 word;
		u8 bytes[4];
	} unk190;
	union {
		f32 word;
		u8 bytes[4];
	} unk194;
} PlayerState;
#endif
