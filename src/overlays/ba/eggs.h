#ifndef __BA_EGGS_H__
#define __BA_EGGS_H__

#include "overlays/ba/playerstate.h"

// Functions beginning with an underscore are trampolines. They exist to intercept calls
// to the real function and load the corresponding overlay if necessary.

void _bsbeggass_entrypoint_0(PlayerState* arg0); // bseggass_init
void _bsbeggass_entrypoint_1(PlayerState* arg0); // bseggass_update
void _bsbeggass_entrypoint_2(PlayerState* arg0); // bseggass_end

void _bsbegghead_entrypoint_0(PlayerState* player); // bsbegghead_init
void _bsbegghead_entrypoint_1(PlayerState* player); // bsbegghead_update
void _bsbegghead_entrypoint_2(PlayerState* player); // bsbegghead_end

void _baeggsetup_entrypoint_2(PlayerState*, s32, f32, f32);
void _baeggsetup_entrypoint_5(PlayerState*, s32, f32, f32);
void _baeggsetup_entrypoint_8(PlayerState*, s32);
void _baeggsetup_entrypoint_9(PlayerState*);
void _baeggsetup_entrypoint_10(PlayerState*);

#endif // __BA_EGGS_H__
