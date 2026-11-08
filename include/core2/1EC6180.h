#ifndef __CORE2_1EC6180_H__
#define __CORE2_1EC6180_H__
#include "gl/idmake.h"
#include "core2/1EC9740.h"
#include "core2/1EC3810.h"
#include "core2/1E9A960.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} unkStruct800EC898_var_t0;

typedef struct {
    u8 pad00[0x0C];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} unkStruct800EC898;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 pad0[0xC];
    s16 unkC;
    s16 unkE;
} unkStruct800ECD60_var1;

typedef struct {
    u8  pad00[0x20];

    f32 unk20;
    f32 unk24;

    u8  pad28[0x2C - 0x28];

    f32 unk2C;
    f32 unk30;
    f32 unk34;

    f32 unk38;
    f32 unk3C;
    f32 unk40;

    f32 unk44;
    f32 unk48;
} unkStruct800ECD60;

typedef struct {
    u8  pad0[4];
    f32 unk4;
    f32 unk8;
    u8  padC[0x29 - 0x0C];
    s8  unk29;
    u8  pad2A[0x44 - 0x2A];
    f32 unk44;
    f32 unk48;
    s16 unk4C; 
    s16 unk4E;
} unkStruct800EDC64;

typedef struct 
{
    u8 pad0[0x28];
    s8 unk28;
    s8 unk29;
    u8 pad2A[0x78 - 0x2A];
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    f32 unk98;
    f32 unk9C;
} unkStruct800EDE54_arg0;

typedef struct 
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} unkStruct800EDE54_arg1;

typedef struct 
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} unkStruct800EDE54_arg2;
typedef struct 
{
    u8 pad00[0x28];
    u8 unk28;
    s8 unk29;
    u8 pad2A[0x78 - 0x2A];
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    f32 unk98;
    f32 unk9C;
} unkStruct800EDF2C;
typedef struct {
    u8 pad[4];
    f32 unk4;
    f32 unk8;
    u8 pad0C[0x29 - 0x0C];
    s8 unk29;
    u8 pad2A[0x44 - 0x2A];
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
} unkStruct800EDFBC;

typedef struct {
    u8 unk0;
    u8 pad[0x20 - 1];
    f32 unk20;
    f32 unk24;
}unkStruct800EE040;

typedef struct {
    u8 pad[0xc];
    s32 unkC;
} unkStruct800EE0F0;

typedef struct {
    u8 pad[0x10];
    s32 unk10;
} unkStruct800EE0F8;

typedef struct {
    u8 pad[0x4c];
    s16 unk4C;
} unkStruct800EE100;

f32 func_800ED964(f32, f32);
void func_800EE040(unkStruct800EE040* arg0, s32 arg1, f32 arg2, f32 arg3);      

#endif