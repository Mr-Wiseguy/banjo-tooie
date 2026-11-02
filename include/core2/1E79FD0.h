#ifndef __CORE2_1E79FD0_H__
#define __CORE2_1E79FD0_H__

#include <ultra64.h>

#include "ba/playerstate.h"
#include "ba/physics.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E82660.h"
#include "core2/1E93440.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1EB5E70.h"
#include "core2/1ECA640.h"
#include "core2/1ECD170.h"
#include "fx/airbub.h"
#include "fx/ripple.h"
#include "fx/splash.h"
#include "fx/splash25d.h"
#include "player.h"

s32 func_800A06E0();
// func_800A06E8
void func_800A0714(PlayerState*, s32);
s32 func_800A0C20(PlayerState*);
f32 func_800A0C2C(PlayerState*);
f32 func_800A0C38(PlayerState*);
void func_800A0C44(PlayerState*);
void func_800A0CD0(PlayerState*, s32);
void func_800A0CDC(PlayerState *, s32);
void func_800A0CE8(PlayerState *, s32);
void func_800A0CF4(PlayerState *, s32);
void func_800A0D14(PlayerState *, s32, f32);
void func_800A0D44(PlayerState*, s32);
void func_800A0D68(PlayerState*, s32);
void func_800A0D74(PlayerState*, f32);
void func_800A0D84(PlayerState*, f32);
void func_800A0D94(PlayerState*, s32);
void func_800A0DA0(PlayerState *, s32);
void func_800A0DAC(PlayerState *, s32);
void func_800A0DB8(PlayerState*, s32);
void func_800A0DC4(PlayerState *, s32);
void func_800A0DD0(PlayerState *, s32);
void func_800A0DDC(PlayerState*);
s32 func_800A0E50(void);
f32 func_800A0E58(PlayerState*);
void func_800A0E64(PlayerState*); 
s32 player_isGrounded(PlayerState*);
s32 func_800A0FD8(PlayerState*);
s32 func_800A0FE4(PlayerState*);
void func_800A0FF0(PlayerState*); 
void func_800A1040(PlayerState *);
void func_800A106C(PlayerState *, f32, f32);
void func_800A10A0(PlayerState*);

#endif // __CORE2_1E79FD0_H__
