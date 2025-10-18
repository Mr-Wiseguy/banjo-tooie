#ifndef __CORE2_1EA1DA0_H__
#define __CORE2_1EA1DA0_H__

#include <ultra64.h>

#include "overlays/ba/playerstate.h"


s32 func_800C8A98(void);
void func_800C8B84(s32);
void func_800C8CB8(s32, f32[3]);
void func_800C8E54(s32, f32, f32);
void func_800C8E84(s32, u32[3]);
void func_800C8FB0(s32, u32, u32, u32);
void func_800C9BB4(f32, s32, s32, s32);
void func_800C9C70(f32, u32, f32, u32, f32*, f32, f32);
void func_800C8D4C(s32, f32*);
//Set a timer to execute the callback
void func_800C9E20(f32 timerLength, u32* callback, u32 callbackArg0, u32 callbackArg1);
extern u8 D_8012AB54;

#endif // __CORE2_1EA1DA0_H__
