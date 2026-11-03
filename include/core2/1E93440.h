#ifndef __CORE2_1E93440_H__
#define __CORE2_1E93440_H__

#include "common.h"
#include "core2/1E8DFA0.h"
#include "core2/1EC8070.h"
#include "ba/assets.h"

typedef struct {
    u8 pad0[0x2];
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 pad6[0x1];
    u8 unk7;
    u8 pad8[0x2];
    u8 unkA;
    u8 padB[0x18 - 0xB];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    u8 pad30[0x54 - 0x30];
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    u8 pad60[0x78 - 0x60];
    f32 unk78;
    f32 unk7C;
    u8 pad80[0x83 - 0x80];
    s8 unk83;
    s16 unk84;
    s16 unk86;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    u8 pad94[0x98 - 0x94];
    s16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    u8 padA6[0xA8 - 0xA6];
    u16 unkA8;
    s16 unkAA;
    u8 padAC[0xAE - 0xAC];
    s16 unkAE;
    f32 unkB0;
    f32 unkB4;
    f32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s16 unkC4;
    s16 unkC6;
    s16 unkC8;
    s16 unkCA;
    s16 unkCC;
    s16 unkCE;
} unkStruct800BA198;

void func_800BA1D0(s32, f32*, f32*, s32);
void func_800BA22C(s32, s32);
int func_800BA28C(unkStruct800BA198*);
void func_800BA3FC(s32, AssetId);
void func_800BA450(s32, s32, s32, s32, s32, s32, s32);
void func_800BA4D0(unkStruct800BA198*, s32);
void func_800BA544(unkStruct800BA198*, s32);
void func_800BA568(unkStruct800BA198*, s16);
void func_800BA5A8(s16*, s32);
void func_800BA5BC(unkStruct800BA198*, f32, f32);
void func_800BA5D0(s32, s16);
void func_800BA660(unkStruct800BA198*, s32, s16);
void func_800BA670(unkStruct800BA198*, s32);
void func_800BA6B0(s32, s16, s16, s16, s16, s16, s16);
void func_800BA714(unkStruct800BA198*, s16, s16);
void func_800BA75C(s32, f32*);
void func_800BA77C(s32, s16, s16, s16);
void func_800BA7C4(unkStruct800BA198*, f32, f32);
void func_800BA7FC(unkStruct800BA198*, f32, f32);
void func_800BA8F8(unkStruct800BA198*, f32, f32);
void func_800BA930(unkStruct800BA198*, s16, s16, s16, s16, s16, s16);
void func_800BA994(unkStruct800BA198*, s16, s16, s16, s16, s16, s16);
void func_800BAA60(unkStruct800BA198*, f32*, s16, s16);
void func_800BAB80(s32, s32*); 
s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
s32 func_800BBCB8(f32[3], f32[3], f32, s32, s32*);

#endif // __CORE2_1E93440_H__