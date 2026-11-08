#ifndef __BA_DUO_H__
#define __BA_DUO_H__

#include "ba/playerstate.h"
#include "pl/su.h"
#include "ba/babykaz.h"
#include "ba/kaztorpedo.h"
#include "ba/drone.h"
#include "ba/duo.h"
#include "ba/packctrl.h"
#include "ba/physics.h"
#include "ba/shoes.h"
#include "ba/yaw.h"
#include "bs/firstp.h"
#include "bs/state.h"
#include "bs/statue.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E7AB30.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E82660.h"
#include "core2/1EAE6C0.h"
#include "core2/1EC8070.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECB9F0.h"
#include "core2/1ECD170.h"
#include "core2/1ECE0B0.h"
#include "core2/1EDA900.h"
#include "core2/1EE92B0.h"
#include "core2/1EE9AB0.h"
#include "pl/su.h"
#include "su/dialog.h"
#include "su/restart.h"

s32 _duo_getOtherCharacter(PlayerState*);
s32 _baduo_entrypoint_3(PlayerState*);
s32 _baduo_entrypoint_4(PlayerState*);
void _baduo_entrypoint_5(PlayerState*);
void _baduo_entrypoint_6(PlayerState*);
extern void _baduo_entrypoint_7(PlayerState *self, s32);
void _baduo_entrypoint_8(PlayerState* self, f32* arg1);
extern void _baduo_entrypoint_12(PlayerState *self);
void _baduo_entrypoint_13(PlayerState*);
void _baduo_entrypoint_21(PlayerState*);

#endif // __BA_DUO_H__
