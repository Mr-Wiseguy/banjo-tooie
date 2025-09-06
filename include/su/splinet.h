#ifndef __SU_SPLINET__
#define __SU_SPLINET__
#include "common.h"

typedef struct
{
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk1C[3];
    f32 unk28;
    f32 unk2C;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    u32 unk40;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u32 unk54;
    s8 unk58;
} SplineMemory;

void _susplinet_entrypoint_0(SplineMemory*, s32, u32, u32);

s32 _susplinet_entrypoint_6(SplineMemory*);
void _susplinet_entrypoint_7(SplineMemory*, u32, f32*);
f32 _susplinet_entrypoint_8(SplineMemory*, u32);
f32 _susplinet_entrypoint_9(SplineMemory*);
void _susplinet_entrypoint_10(SplineMemory*, f32);
void _susplinet_entrypoint_11(SplineMemory*, f32);
s16* _susplinet_entrypoint_12(SplineMemory*);
s16* _susplinet_entrypoint_13(SplineMemory*);
Vec3f* _susplinet_entrypoint_14(SplineMemory*, s32);
f32* _susplinet_entrypoint_15(SplineMemory*, s32);
void _susplinet_entrypoint_17(SplineMemory*);
u32 _susplinet_entrypoint_18(s32, u32, u32);
void _susplinet_entrypoint_19(SplineMemory*, s32, u32, u32);

#endif
