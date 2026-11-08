#ifndef __CORE2_1E78170_H__
#define __CORE2_1E78170_H__

#include "common.h"
#include "gameflags.h"
#include "core2/1EA0690.h"
#include "core2/1EAD060.h"
#include "core2/1EB3750.h"

typedef struct {
    f32 unk0[3];
    s8 unkC;
    u8 padD[3];
    s16 unk10[8];
    u8 unk20;
} D_80127040_STRUCT;

typedef struct {
    f32 unk0[3];
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    s16 unk14;
    s8 unk16;
    s8 unk17;
    s32 unk18;
} D_80127068_STRUCT;

void func_8009E880();
void func_8009E8B4();
void func_8009E8D4();
u8 func_8009E958(void);
u8 func_8009E964(void);
f32 func_8009E970(void);
f32 func_8009E97C(void);
f32 func_8009E988(void);
u8 func_8009E994(void);
void func_8009E9A0();
void func_8009E9A8();
void func_8009E9D8(TransformationId);
void func_8009E9E4(s32);
void func_8009E9F0(f32);
void func_8009E9FC(f32);
void func_8009EA08(f32);
f32 func_8009EA14(void);
u8 func_8009EA20(void);
s32 bs_getDragonKazooieState(void);
u8 func_8009EA4C(void);
s32 func_8009EA58(void);
s32 func_8009EA64(void);
u8 func_8009EA70(void);
f32 func_8009EA7C(void);
f32 func_8009EA88(void);
void func_8009EA94(f32);
void func_8009EAA0(s32);
void bs_setDragonKazooieState(s32);
s32 func_8009EAD0(s32);
void func_8009EADC(s32);
void func_8009EAE8(s32);
void func_8009EAF4(s32);
void func_8009EB00(f32);
void func_8009EB0C(f32);
void func_8009EB18(s32);
void func_8009EB24(s16, s16);
void func_8009EB8C(s16, s16);
void func_8009EBD0(void);
s32 func_8009EC08(s16*, s16*);
void func_8009EC3C(void);
void func_8009EC60(s16, s16);
u8 func_8009EC7C(void);
s32 func_8009EC88(s32, s32, s32, s32);

#endif // __CORE2_1E78170_H__
