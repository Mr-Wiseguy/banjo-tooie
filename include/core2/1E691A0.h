#ifndef __CORE2_1E691A0_H__
#define __CORE2_1E691A0_H__

#include "common.h"
#include "transformations.h"
#include "core2/1ECE0B0.h"

void func_8008F8B0();
void func_8008F8D8(s32);
void func_8008F904(void*, s32);
void func_8008F938(s32);
void func_8008F964(f32*);
void func_8008F990(s32, f32);
void func_8008F9F8(f32*, f32);
s32 func_8008FA2C(s32, s32);
s32 func_8008FA60(s32, s32);
void func_8008FB10(f32*, f32, f32, f32);
s32 func_8008FB58(f32[3], f32, f32);
void func_8008FBE0(u32 a0);
s32 activePlayer_getCurrentHealth();
s32 activePlayer_getMaxHealth();
void activePlayer_incrementCurrentHealth();
TransformationId activePlayer_getTransformation();
s32 activePlayer_getTransformationBit();
s32 func_8008FDC4();
Unk80132ED0* func_8008FDEC();
s32 func_8008FE14();
void activePlayer_getCoords(f32*);
void func_8008FE94(s32, f32*);
f32 func_8008FEF0();
void func_8008FF40(f32*);
void func_8008FFBC(f32*);
f32 func_80090010(void);
s32 func_80090080();
void func_800900D0(s32);
s32 func_80090128();
//Does the current character match given transformation
s32 activePlayer_includedInTransformMask(s32); 
s32 func_800901CC(f32*, f32);
s32 func_80090248(void);
s32 func_80090270(void);
s32 func_800902E4(f32*, f32, s32, Actor**);
void func_8009032C(s32);
s32 func_800903D0(f32[3]);
void func_800904C8(s32);
void func_800904F4(s32, Unk80132ED0*);
void func_80090590(s32, f32*);
void func_80090658(s32);
void func_800906DC(f32[3]);
void func_80090708(s32);
void func_80090734(s32, f32[3]);
void func_80090768(void*);
void func_800907C0(f32[3]);
void func_800907EC(TransformationId);
s32 func_80090818();
#endif
