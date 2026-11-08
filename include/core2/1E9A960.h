#ifndef __CORE2_1E9A960_H__
#define __CORE2_1E9A960_H__

#include "common.h"
#include "core2/1ED68A0.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1E99980.h"
#include "core2/1EB2840.h"
#include "ba/playerstate.h"

#include "core2/1EB5C70.h"
#include "core2/1EB5980.h"
#include "pl/su.h"

typedef void (*unkFunc800C3CE8)(u8, s32);

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    f32 unk50;
    f32 unk54;
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 unk5E;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    unkFunc800C3CE8 unk64;
    s32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    u8 unk78;
    u8 unk79;
    u32 unk7A_13 : 3;
    u32 unk7A_10 : 3;
    u32 unk7A_6 : 4;
    u32 unk7B_5 : 1;
    u32 unk7B_4 : 1;
    u32 unk7B_3 : 1;
    u32 unk7B_2 : 1;
    u32 unk7B_1 : 1;
    u32 unk7B_0 : 1;
    u16 unk7C;
} unkStruct800C39D0;

typedef struct {
    s32 unk0;
    s32 unk4;
} unkStructD_80128B08;

typedef struct {
    f32 unk0;
    s16 unk4;
    s16 unk6;
} unkStructD_8012A990;

void func_800C1070(f32*, void*);
s32 func_800C1104(unkStruct800C39D0*);
void func_800C11F8(unkStruct800C39D0*, s32);
void func_800C1210(unkStruct800C39D0*, s32);
s32 func_800C122C(s32, s32, s32, s32);
void func_800C13A0(unkStruct800C39D0*, s32);
void func_800C13B0(unkStruct800C39D0*, s32);
s32 func_800C13C4(unkStruct800C39D0*, s32);
s32 func_800C13D0(unkStruct800C39D0*, s32);
unkStruct800C39D0* func_800C1414(u8);
unkStructD_80128B08* func_800C1430(s32);
s32 func_800C1448(s32);
u8 func_800C145C(void);
void func_800C1568(s32);
s32 func_800C15BC(void);
void func_800C16A4(u8);
void func_800C16F8(unkStruct800C39D0*, s32);
void func_800C1860(unkStruct800C39D0*);
void func_800C18C8(s32, s32, s32, s32, s32);
void func_800C191C(s32, s32);
void func_800C1950(s32, f32);
void func_800C1984(s32, s32, s32);
s32 func_800C19E4(unkStruct800C39D0*, s32);
void func_800C1AA4(unkStruct800C39D0*);
s32 func_800C1CCC(unkStruct800C39D0*, s32);
s32 func_800C1D80(u8);
void func_800C2000(u8);
s32 func_800C269C(u8);
void func_800C2718(void);
void func_800C2840(s32, f32, s32, s32, s32);
void func_800C28D8(void);
void func_800C2900(void);
void func_800C2A5C(s32 arg0, s32 arg1);
void func_800C2A68();
void func_800C2A90();
void func_800C2AB8(void);
void func_800C2B80(void);
void func_800C2C4C(u8 id);
u8 func_800C2E04(void);
void func_800C2E40(u8);
s32 func_800C2FDC(u8 id);
void func_800C301C(u8 id, s32);
void func_800C3058(u8 id, s32);
void func_800C30B8(u8, s32, f32*, f32, f32);
void func_800C316C(u8, s32, s32, f32);
void func_800C31DC(u8 id, f32);
void func_800C3224(u8, f32, f32, f32);
void func_800C32C4(u8 id, s32);
void func_800C330C(u8 id, s32);
void func_800C334C(u8 id, s32);
void func_800C33DC(u8 id, s32);
void func_800C3418(u8 id, s32);
void func_800C3584(u8, f32, f32);
void func_800C35E8(u8, s32);
void func_800C368C(u8 id, s32);
void func_800C36F4(u8 id, s32);
void func_800C3730(u8 id, f32, f32, f32);
void func_800C3798(u8 id, f32, f32);
// func_800C37E0
// func_800C3868
// func_800C38E4
s16 func_800C3920(u8);
f32 func_800C395C(u8);
s32 func_800C39A0(u8 id);
s32 func_800C39D0(unkStruct800C39D0*);
void func_800C3A40(u8, f32, f32, f32);
void func_800C3BDC(u8 id);
void func_800C3CE8(u8 id);
int func_800C3D78(u8);
s32 func_800C3E00(s32);
void func_800C3EB8(s32);
void func_800C3F48(u32);
void func_800C3FC0(s32, f32, s32);
void func_800C3FF0(s32, f32, s32);
void func_800C401C(s32, f32, s32, f32*, f32, f32, s32);
void func_800C4104(s32, f32, s32, f32*, f32, f32);
void func_800C4140(u32, f32*, u32);
void func_800C4208(s32, f32, s32, f32*, f32, f32);
void func_800C4244(Unk80132ED0*, f32, u32, f32*, f32, f32);
void func_800C427C();
s32 func_800C42E0(s32);
void func_800C4308(f32, f32);
u8 func_800C4350(u8, f32*, s16*);
void func_800C4AF0(f32 *, void*);
void func_800C4B64(f32);
void func_800C4B70(s32);
void func_800C4B7C(s32);
s32 func_800CBBE0(s32);
s32 func_800CBC00(s32);
s32 func_800CCEF4(unkStruct800C39D0*, s32*, s32*, s32, s32);
void func_800E3A58(Vec3f*);
void func_800EF7B0(Vec3f*, Vec3f*, f32, f32, f32);
s32 func_800A5490(void);
s32 func_800F5310(void);
s32 func_800F5D18(s32);
s32 func_8010FFA8(s32);
s32 func_8010FFD8(s32);

#endif // __CORE2_1E9A960_H__