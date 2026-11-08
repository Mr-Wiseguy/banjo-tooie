#ifndef __BA_DIALOG__
#define __BA_DIALOG__

#include "common.h"
#include "core2/1E67DA0.h"
#include "core2/1E72EA0.h"
#include "core2/1E75920.h"
#include "core2/1E77A20.h"
#include "core2/1E99980.h"
#include "core2/1EB3750.h"
#include "core2/1ECE0B0.h"

typedef struct {
    u8 unk0[0x1A];
    u16 unk1A_5 : 11;
    u16 unk1A_0 : 5;
} UNKBADIALOGARG0;

void _badialog_entrypoint_0(UNKBADIALOGARG0*, s32, s32);
void _badialog_entrypoint_1(s32, s32, s32);
s32 _badialog_entrypoint_2(s32, s32, s32);
s32 _badialog_entrypoint_3(PlayerState*, u32, u32);
s32 _badialog_entrypoint_4(PlayerState*, u32, u32, GameFlag);

#endif // __BA_DIALOG__
