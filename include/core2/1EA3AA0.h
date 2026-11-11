#ifndef __CORE2_1EA3AA0_H__
#define __CORE2_1EA3AA0_H__

#include <ultra64.h>
#include "core1/mlmtx.h"

typedef struct {
    f32 unk0[3];
    u8 padC[0x10];
    f32 unk1C;
    u8 pad20[0xA4 - 0x20];
    MtxF unkA4;
    f32 unkE4;
    u8 padE8[0xF4 - 0xE8];
    f32 unkF4;
    u8 padF8[0x164 - 0xF8];
    f32 unk164;
} unkStruct800CA334;

// func_800CA1B0
// func_800CA218
// func_800CA2A8
void func_800CA314(void*, void*);
unkStruct800CA334* func_800CA334();
void func_800CA364(void*);
void* func_800CA384(void*);
// func_800CA3A4
void func_800CA3F4(f32*, f32*, f32);
// func_800CA440
// func_800CA510
void func_800CA558(unkStruct800CA334*, f32);
void func_800CA5B8(void);
void func_800CA5D8(void);
// func_800CA5F8
void func_800CA628(f32*, s32*, s32*);
// func_800CA668
// func_800CA688
// func_800CA6C0
// func_800CA6D4
f32 func_800CA6E8(s32);
// func_800CA6F0
// func_800CA6FC
// func_800CA704
void func_800CA740(f32*, f32*);
// func_800CA768
// func_800CA794
// func_800CA79C
// func_800CA7A4
MtxF* func_800CA7AC(s32);
// func_800CA7B4
// func_800CA7BC
f32 func_800CA7E4(unkStruct800CA334*, f32[3]);
void func_800CA810(unkStruct800CA334*, s32);
// func_800CA8B4
// func_800CA8F4
// func_800CA934
void func_800CA9D8(f32 *, s32 *);
// func_800CAA00
f32 func_800CAA1C(unkStruct800CA334*);
// func_800CAA24
// func_800CAB70
// func_800CACEC
// func_800CAD9C
// func_800CAEA4
f32 func_800CAF00(f32 [3], f32);
u16 func_800CB124(s32, MtxF*);

#endif // __CORE2_1EA3AA0_H__
