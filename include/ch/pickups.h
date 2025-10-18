#ifndef __CH_PICKUPS_H__
#define __CH_PICKUPS_H__

#include "common.h"

#include "core2/1E691A0.h"
#include "core2/1EB2840.h"
#include "core2/1EE27C0.h"
#include "core2/1EDCA30.h"
#include "core2/1EC8070.h"
#include "core2/1EDB4D0.h"
#include "core2/1ED8C80.h"
#include "core2/1ED4E30.h"
#include "core2/1ECE0B0.h"
#include "core2/1EDA900.h"

#include "fx/sparkle.h"
#include "su/baddieaudioquick.h"

#include "ch/doubloon.h"
#include "su/deflect.h"

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10[3];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
}PickupsData;

s32* _chpickups_entrypoint_0(void);
s32* _chpickups_entrypoint_1(void);
s32* _chpickups_entrypoint_2(void);
s32* _chpickups_entrypoint_3(void);
s32* _chpickups_entrypoint_4(void);
s32* _chpickups_entrypoint_5(void);
s32* _chpickups_entrypoint_6(void);
s32* _chpickups_entrypoint_7(void);
s32* _chpickups_entrypoint_8(void);
s32* _chpickups_entrypoint_9(void);
s32* _chpickups_entrypoint_10(void);

void func_80800110_chpickups(Actor* arg0);

#endif
