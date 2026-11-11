#ifndef __CORE2_1ECD170_H__
#define __CORE2_1ECD170_H__

#include "common.h"
#include "ba/playerstate.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/roll.h"
#include "ba/shoes.h"
#include "ba/statetimer.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "core1/heap.h"
#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E68670.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E72180.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1E76500.h"
#include "core2/1E77A20.h"
#include "core2/1E79FD0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E831D0.h"
#include "core2/1EAAD80.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1ECD170.h"
#include "core2/1ECE0B0.h"
#include "core2/1EDFED0.h"
#include "memory.h"
#include "vector.h"
#include "freelist.h"

void player_destroy(PlayerState*);
s32 func_800F38A8(PlayerState*, s32);
s32 func_800F3930(PlayerState*, s32, s32);
void player_getCoords_Dupe(PlayerState*, f32*);
void func_800F3BD0(PlayerState*, s32, f32[3]);
s32 func_800F3ED0(PlayerState*);
s32 func_800F40EC(PlayerState*);
void func_800F4200(PlayerState*, f32*);
s32 func_800F4244(PlayerState*);
s32 func_800F424C(PlayerState*);
PlayerState* func_800F43A8(s32);
void func_800F452C(PlayerState*, f32*);
void func_800F457C(PlayerState*, s32);
void func_800F45B0(PlayerState*, s32, f32*);
void func_800F4648(PlayerState*, f32*);
void func_800F468C(PlayerState*);
PlayerState* func_800F46D8(PlayerState*);
f32 func_800F3780(f32, s32[], s32);

#endif // __CORE2_1ECD170_H__
