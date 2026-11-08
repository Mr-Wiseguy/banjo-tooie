#ifndef __BS_BBILLDRILL_H__
#define __BS_BBILLDRILL_H__

#include <ultra64.h>

#include "common.h"
#include "buttons.h"
#include "bs.h"

#include "ba/anim.h"
#include "ba/assets.h"
#include "ba/dust.h"
#include "ba/flag.h"
#include "ba/motor.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "bs/state.h"
#include "ba/shake.h"
#include "ba/timer.h"
#include "bs/walk.h"
#include "ch/light/fader.h"
#include "fx/dlsmoke.h"

#include "core1/1E29B60.h"

#include "core2/anctrl.h"

#include "core2/1E66990.h"
#include "core2/1E68670.h"
#include "core2/1E6B900.h"
#include "core2/1E71B00.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78170.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E8F430.h"
#include "core2/1E93440.h"
#include "core2/1EA0690.h"
#include "core2/1EA1DA0.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1EB2840.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"

// Code
void func_80800000_bsbbilldrill(PlayerState*);
void func_80800008_bsbbilldrill(PlayerState*);
void func_808000C0_bsbbilldrill(PlayerState*);
void func_80800100_bsbbilldrill(PlayerState*);
s32 func_80800158_bsbbilldrill(f32[3]);
void func_8080019C_bsbbilldrill(PlayerState*);
void func_80800250_bsbbilldrill(PlayerState*);
void func_80800298_bsbbilldrill(PlayerState*);
void func_808002DC_bsbbilldrill(PlayerState*, s32);
void func_808005C0_bsbbilldrill(PlayerState*);
void bsbbilldrill_entrypoint_0(PlayerState*);
void bsbbilldrill_entrypoint_1(PlayerState*);
void bsbbilldrill_entrypoint_2(PlayerState*);
s32 bsbbilldrill_entrypoint_3(s32);

#endif // __BS_BBILLDRILL_H__
