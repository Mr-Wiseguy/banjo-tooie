#ifndef __CORE2_1EE27C0_H__
#define __CORE2_1EE27C0_H__

#include "common.h"
#include "core2/1EA0210.h"
#include "core2/1EB5980.h"
#include "core2/1EC4CC0.h"
#include "core2/1ECE0B0.h"
#include "core2/1EDA900.h"
#include "core2/1EDC7B0.h"
#include "core2/1EDCA30.h"
#include "core2/1EDFED0.h"

void* func_80108ED0(void);
void* func_80108EDC(void);
void* func_80108EE8(void);
void func_801094E0(f32*, f32);
s32 func_80109EE0(Actor*, s32);
void func_80109EEC(Actor*, s32);
void func_80109EF4(Actor*, s32);
void func_80109F08(Actor*, s32);
void func_80109F18(s32, s32);
void func_80109F40(s32, s32);
void func_80109F68(s32, s32);
void func_80109F90(s32, s32);
void func_80109FB8(Unk80132ED0*, Unk80132ED0*);
void func_80109FE8(Actor*, s32);
void func_8010A3E8(Actor*, f32);
f32 func_8010A40C(Actor*);
//Disable Actor Collision
s32 actor_disableCollision(Actor*);
//Enable Actor Collision
s32 actor_enableCollision(Actor*);
//Set Actor Collision
s32 actor_setCollision(Actor*, s32);
//Get Actor Collision State
u32 actor_getCollision(Actor*);
void func_8010A624(Actor*);
void func_8010A63C(Actor*);
u32 func_8010A654(Actor*, s32);
u32 func_8010A698(Actor*);
s32 func_8010A6B0(Actor*, s32);
#endif
