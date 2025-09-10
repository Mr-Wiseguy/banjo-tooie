#ifndef __CH_HONEY_CARRIER_H__
#define __CH_HONEY_CARRIER_H__

#include "common.h"
#include "core2/1E2B200.h"

#include "core2/1EB2840.h"
#include "core2/1EB3750.h"

#include "core2/1EB5980.h"
#include "core2/1EA1DA0.h"
#include "core2/1EA9160.h"

#include "core2/1EAAD80.h"

#include "core2/1EC8070.h"
#include "core2/1ECE0B0.h"

#include "core2/1ED4E30.h"
#include "core2/1ED8C80.h"
#include "core2/1EDAEA0.h"
#include "core2/1EDC7B0.h"
#include "core2/1EDCA30.h"
#include "su/dialog.h"

#include "fx/sparkle.h"
#include "fx/twinkle.h"

#include "gameflags.h"


typedef struct {
    u16 pad0[0xD];
    u16 unk1A;
} unkStructHoneyCarrier;

void func_80800000_chhoneycarrier(Actor* arg0, unkStructHoneyCarrier* arg1);

#endif
