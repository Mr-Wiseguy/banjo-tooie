#include "common.h"
#include "core2/1E8A640.h"

s16 func_800B0D50(unkStruct800B0D58* arg0) {
    return arg0->unk0;
}

s16 func_800B0D58(unkStruct800B0D58* arg0) {
    return arg0->unk2;
}

u8* func_800B0D60(unkStruct800B0D58* arg0) {
    return (u8*)arg0 + arg0->unk8;
}

s32 func_800B0D6C(unkStruct800B0D58* arg0, s32 arg1) {
    return (s32)&arg0->unkC[arg1 * 8];
}
