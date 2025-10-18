#ifndef __CH_HEGGY_H__
#define __CH_HEGGY_H__

#include "common.h"

#include "core2/1EAAD80.h"
#include "core2/1EC8070.h"
#include "core2/1E691A0.h"
#include "core2/1E93440.h"
#include "core2/1E9A960.h"
#include "core2/1EB5E70.h"
#include "core2/1EDA900.h"
#include "core2/1EDAEA0.h"
#include "core2/1EDC7B0.h"
#include "core2/1EE27C0.h"
#include "core2/1EB2840.h"
#include "core2/1E8DFA0.h"
#include "core2/1EDCA30.h"
#include "core2/1EC9740.h"

#include "core2/1EB3750.h"
#include "core2/1EB5980.h"

#include "core2/1EE1510.h"
#include "core2/1ECD170.h"
#include "core2/1EDB4D0.h"
#include "core2/1EDC070.h"
#include "core2/1EDED00.h"
#include "core2/1ED8C80.h"
#include "core2/1ECA640.h"
#include "core2/1EAD6C0.h"
#include "core2/1EA0690.h"
#include "core2/1EA1270.h"

#include "su/baddieDll.h"
#include "ca/pod.h"
#include "gc/dialogcamera.h"
#include "gc/cubesearch.h"
#include "gs/propctrl.h"
#include "gl/splinefind.h"
#include "gl/cutDll.h"
#include "su/baddiedialog.h"
#include "su/baddieskeleton.h"
#include "su/baddiefind.h"
#include "su/baddieitem.h"
#include "su/deflect.h"

#include "ch/skeletonexplode.h"

typedef struct Unk80100094 {
    Vec3f unk0[1]; // unknown size, could be up to 5
    u8 padC[0x3C - 0xC];
    Vec3f unk3C;
    s32 unk48[7]; // unknown size
    f32 unk64[3];
    f32 unk70[3];
} Unk80100094;


s32* chheggy_entrypoint_0(void);
s32* _chheggy_entrypoint_0(void);

s32* chheggy_entrypoint_1(void);
s32* _chheggy_entrypoint_1(void);


#endif

