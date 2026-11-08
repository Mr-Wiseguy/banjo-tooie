#ifndef __CORE2_1EA1DA0_H__
#define __CORE2_1EA1DA0_H__

#include "common.h"
#include "memory.h"
#include "gc/lightsDll.h"
#include "gc/transitionDll.h"
#include "core2/1EC8070.h"
#include "core2/1E7EDB0.h"
#include "core2/1ECBCC0.h"
#include "core2/1E9A960.h"
#include "core2/anctrl.h"
#include "core2/1E7EAB0.h"
#include "core2/1E691A0.h"

#include "ba/playerstate.h"
#include "su/baddiedialog.h"
#include "vector.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} unkStruct800C84B0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 padD[3];
    f32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
} unkStruct800C85A0;

typedef struct {
    s32 unk0;
    u8 pad4[6];
    u8 unkA;
    u8 pad0B[0x11];
    u8 unk1C;
    u8 pad1D[0xF];
    AnimCtrl* unk2C;
    u8 pad30[4];
} unkStruct800C9150;

typedef struct {
    f32 unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20[0x50];
} unkStruct800C9750;

typedef struct {
    Unk80132ED0* unk0;
    f32 unk4;
    u32 unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
} unkStruct800C99F0;

typedef struct {
    Unk80132ED0* unk0;
    u32 unk4;
    u32 unk8;
    f32 unkC[3];
    s16 unk18;
} unkStruct800C9A38;

typedef struct {
    u8 pad0[0x12];
    u16 unk12;
} unkStruct800C9B30;

typedef struct {
    u32 unk0;
    f32 unk4;
    u32 unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
} unkStruct800C9C70;

typedef struct {
    Vector* unk0;
    f32 unk4;
} unkStruct8012AB60;

typedef struct {
    unkStruct800C9150* unk0[5];
    u8 unk14;
} unkStruct8012AB40;

s32 func_800C84B0(s32);
void func_800C8900(s32, s32*);
s32 func_800C8A98(void);
void func_800C8B84(s32);
void func_800C8CB8(s32, f32[3]);
void func_800C8D4C(s32, f32*);
void func_800C8E54(s32, f32, f32);
void func_800C8E84(s32, u32[3]);
void func_800C8F64(s32, s32);
void func_800C8FB0(s32, u32, u32, u32);
void func_800C8FE0(s32, s32);
s32 func_800C9044(s32);
unkStruct800C9150* func_800C91C8(s32);
void func_800C929C();
void func_800C92A8();
s32 func_800C9510();
s32 func_800C954C();
s32 func_800C95D4();
s32 func_800C964C(s32);
void func_800C968C(s32, s32);
unkStruct800C9750* func_800C9750(f32, s32, u32*, s32, s32, s32, s32, s32);
void func_800C986C(unkStruct800C9750*);
void func_800C9974(u32, u32);
void func_800C9994(u32, u32, u32);
void func_800C99B4(s32, s32, s32);
void func_800C99F0(unkStruct800C99F0*);
void func_800C9A38(unkStruct800C9A38*);
void func_800C9AB0();
void func_800C9B30(Unk80132ED0*, s32, s32);
void func_800C9BB4(f32, s32, f32, s32);
void func_800C9C70(f32, u32, f32, u32, f32*, f32, f32);
void func_800C9DAC(f32, u32*);
void func_800C9DE4(f32, u32*, s32);
//Set a timer to execute the callback
void func_800C9E20(f32 timerLength, u32* callback, u32 callbackArg0, u32 callbackArg1);
void func_800C9E64(f32, u32*, s32, s32, s32);
void func_800C9EF8(f32, u32*, void*);
void func_800CA0A8();
extern u8 D_8012AB54;

#endif // __CORE2_1EA1DA0_H__
