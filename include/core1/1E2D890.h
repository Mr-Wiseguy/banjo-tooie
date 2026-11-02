#ifndef __CORE1_1E2D890_H__
#define __CORE1_1E2D890_H__

#include "common.h"
#include "core1/1E2B200.h"
#include "core1/1E2D890.h"
#include "core2/1EB5980.h"

//Is Pause Button Pressed
u8 func_80015FA0(u8);
void func_80016068(u8, f32*);
void func_8001608C();
void func_80016734();
u8 controller_getError();
void func_80016864();
//Get Number of Frames button held for
u8 func_80016B30(u8, u32);
void func_80016BDC(s32);

#endif
