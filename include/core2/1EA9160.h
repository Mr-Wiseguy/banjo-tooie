#ifndef __CORE2_1EA9160_H__
#define __CORE2_1EA9160_H__

#include "common.h"

s32 func_800CF87C();
s32 func_800CFA90();
void func_800CFBC8(Actor*, u32, s32, s32);
u32 func_800CFC8C(s16, s32);
s32 func_800D0018(s16, s32);
s32 func_800D035C(s16 a0);
void func_800D053C(u32, u32);
void func_800D0594(s32, s32, s32);
void func_800D05E4(s32, s32, s32);
s32 func_800D0634(u32, u32);
//Get Associated Level Id of given item
s32 func_800D06D4(s32 itemIndex, s32 itemType);
void func_800D0778(s32, s32, s32*);
//Check if collectable is valid type
s32 func_800D0820(s32 itemType);
void func_800CF870(s32);
s32 func_800CFFBC(u32, s32);
//Get Total Number of Given Object
s32 func_800D0894(s32 itemType);
s32 func_800D0908(s32, s32);
s32 func_800D0A80(s32, s32);
//Is Item Spawned
s32 func_800D0A9C(u32, u32);
void func_800D0B38(s16, s16);
//Is Item Collected
s32 func_800D0B68(u32, u32);
void func_800D0BD4(s32, u32);
void func_800D0C78(u32, u32, u32);
//Set Item Collected Flag
void func_800D0BD4(s32, u32);
//Spawn Collectable
void func_800D1000(u32, u32, f32*, u32, Unk80132ED0*);
//Get Total Number of Jinjos of Type
s32 func_800D129C(u32);
//Get Total Number of Jinjos Collected of Type
u32 func_800D1338(u32 JinjoColor);

#endif
