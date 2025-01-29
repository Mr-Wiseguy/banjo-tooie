#ifndef __BS_KAZ_H__
#define __BS_KAZ_H__

#include <ultra64.h>

#include "ba/flag.h"
#include "ba/key.h"
#include "ba/shoes.h"
#include "ba/stick.h"
#include "bs/kaz.h"
#include "bs/kazmove.h"

extern s32 func_8008D3B0(PlayerState *self);
extern s32 func_8008E430();
extern s32 func_800C6E38(s32);
extern s32 func_8009EA2C();
extern void func_80092864(PlayerState *self, f32);
extern void func_800962B0(s32, s32);

void _bskaz_entrypoint_0();
void _bskaz_entrypoint_1();
void _bskaz_entrypoint_2(PlayerState *self);
s32 _bskaz_entrypoint_3(PlayerState *self);
s32 _bskaz_entrypoint_4(PlayerState *self);

#endif // __BS_KAZ_H__