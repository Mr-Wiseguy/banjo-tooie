#ifndef __CORE2_1ECE0B0_H__
#define __CORE2_1ECE0B0_H__

#include "../../src/overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7AB30.h"

#include "overlays/ba/anim.h"
#include "overlays/ba/key.h"
#include "overlays/ba/drone.h"
#include "ba/hold.h"


#include <ultra64.h>
void func_800F497C(s32);
void func_800F49D4(s32 arg0, void* arg1, s32 arg2);
void func_800F4A58(s32,s32,f32);
s32 func_800F4B4C(s32);
s32 func_800F4B8C(u32, u32, s32);
s32 func_800F4BB8(u32, u32, s32);
void func_800F4CC0(s32);
void func_800F4CEC(s32, u32);
PlayerState* func_800F53D0(s32 arg0);
PlayerState* func_800F53E4(s32 arg0);
//Get the character control index
u32 func_800F54E4(void);
Unk80132ED0* func_800F56D8(s32 arg0);
void func_800F5A00(s32, f32[3]);
void func_800F5D44(s32, f32*);
f32 func_800F5F24(u32);
s32 func_800F5FE0(s32);
void func_800F608C(s32, s32);
void func_800F6388(s32, s32);
void func_800F63E0(s32, u32);
s32 func_800F6438(u32);
s32 func_800F6774(u32);
//Does the character match the given transformation type
s32 func_800F64A4(s32 characterIndex, s32 transformationType);
void func_800F7700(u32, s32, f32*);
//The moving object is moved towards/away from the target
void func_800F78EC(s32 moving, f32* target, f32 verticalSpeed, f32 horizontalSpeed);
void func_800F7B9C(s32, u32);
void func_800F7BC8(s32, s32, Unk80132ED0*);
s32 func_800F8004(s32);
void func_800F80E4(s32, u32);
void func_800F822C(s32, f32, f32);
void func_800F8294(s32, f32*);
void func_800F82C0(s32);
void func_800F82D4(s32, s32);
void func_800F832C(s32, f32*);
s32 func_800F8B64(void);
void func_800F8DD8();
void func_800F8E08();
void func_800F911C(s32);
// Might take in a PlayerState *
void func_800F9BC4(void);


#endif // __CORE2_1ECE0B0_H__
