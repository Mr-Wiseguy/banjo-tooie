#ifndef __CH_DIPPY_H__
#define __CH_DIPPY_H__

#include "common.h"
#include "ca/pod.h"
#include "gl/cutDll.h"
#include "gl/id.h"
#include "ch/credits.h"
#include "ch/introtext.h"
#include "su/baddieaudioquick.h"
#include "su/baddiedialog.h"
#include "su/baddieDll.h"
#include "su/baddieskeleton.h"
#include "id/worldmake.h"
#include "id/world.h"
#include "id/wibble.h"
#include "core2/1EB5E70.h"
#include "core2/1E93440.h"
#include "core2/1E97EF0.h"
#include "core2/1EA9160.h"
#include "core2/1EA5180.h"
#include "core2/1EE7080.h"

typedef struct {
    u16 pad0;
    s16 unk2;
    u8 pad4[0x10 - 0x4];
} ChDippyUnk;

void _chdippy_entrypoint_2(s32, f32*);
void _chdippy_entrypoint_3(s32, ChDippyUnk*, ChDippyUnk*, s32, Unk80132ED0*);

#endif
