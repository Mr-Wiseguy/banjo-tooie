#ifndef __CORE2_1E72180_H__
#define __CORE2_1E72180_H__

#include "common.h"

#include "ba/playerstate.h"
#include "ba/attach.h"
#include "ba/bounce.h"
#include "ba/babykaz.h"
#include "ba/anim.h"
#include "ba/cough.h"
#include "ba/deathmatch.h"
#include "ba/drone.h"
#include "ba/dronemem.h"
#include "ba/dust.h"
#include "ba/duo.h"
#include "ba/egg/cursor.h"
#include "ba/flag.h"
#include "ba/fpctrl.h"	
#include "ba/hold.h"
#include "ba/input.h"
#include "ba/invisible.h"
#include "ba/key.h"
#include "ba/mum.h"
#include "ba/packctrl.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/setup.h"
#include "ba/squash.h"
#include "ba/shoes.h"
#include "ba/statetimer.h"
#include "ba/statemem.h"
#include "ba/stick.h"
#include "bs/state.h"
#include "ba/translate.h"
#include "gc/frontend.h"

#include "core2/1E66990.h"
#include "core2/1E6A190.h"
#include "core2/1E6A730.h"
#include "core2/1E6B700.h"
#include "core2/1E6B900.h"
#include "core2/1E6E870.h"
#include "core2/1E6EC70.h"
#include "core2/1E6F080.h"
#include "core2/1E71B00.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1E76500.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78170.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E7AB30.h"
#include "core2/1E7B250.h"
#include "core2/1E7BAB0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1EAD060.h"
#include "core2/1EAD6C0.h"
#include "core2/1EB3750.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1EC9740.h"
#include "core2/1ECE0B0.h"

s32 func_80098890();
void func_80098898(PlayerState* self);
void func_800989E4(PlayerState* self);
void func_80098B4C(PlayerState* self, s32 arg1);
void func_80098B5C(PlayerState* self, f32* arg1, f32* arg2);
s32 func_80098BA0();
void func_80098BA8(PlayerState* self, s32 arg1);
void func_80098BE0(PlayerState* self);
void func_80098C48(PlayerState* self);
void func_80098E64(PlayerState* self);
void func_8009919C(PlayerState* self, s32* arg1, s32 arg2);
void func_800991B0(PlayerState* self);
void func_80099544(PlayerState* self);

#endif
