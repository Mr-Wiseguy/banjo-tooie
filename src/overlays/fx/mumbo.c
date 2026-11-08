#include "fx/mumbo.h"

extern s32 D_80800060_fxmumbo;

void fxmumbo_entrypoint_0(f32* arg0, s32 arg1) {
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0xD);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, NULL, 1.0f, &D_80800060_fxmumbo);
    func_800BA22C(sp24, arg1);
}