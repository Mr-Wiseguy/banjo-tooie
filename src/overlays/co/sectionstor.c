#include "co/sectionstor.h"

typedef struct
{
    void* unk0[0x10B];
    u8 unk42C;
} UNKD_80127194;

extern UNKD_80127194 D_80127194;

void cosectionstor_entrypoint_0(void)
{
    s32 i;
    for (i = 1; i < 0x10B; i += 1)
    {
        D_80127194.unk0[i] = 0;
    }
}

void cosectionstor_entrypoint_1(void) {
    s32 i;

    for (i = 1; i < 0x10B; i++) 
    {
        if (D_80127194.unk0[i] != NULL) 
        {
            heap_free(D_80127194.unk0[i]);
            D_80127194.unk0[i] = NULL;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_4.s")
