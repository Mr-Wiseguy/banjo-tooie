#include <ultra64.h>
#include "gfx.h"
#include "core2/1E99980.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C00BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C00E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C01A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C01D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C04C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C05B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C064C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C067C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C06C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C075C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C07F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C082C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C08C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C08F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0984.s")

void func_800C0A2C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0BB4.s")

// Probably a file split here based on bk decomp and bss (D_80128AF4)

extern Gfx D_8011A7E0[];
extern Gfx D_8011A840[];

#define ROUND_UP_DIVIDE(x, y) (((x) + (y) - 1) / (y))

#if 0
// Scratch: https://decomp.me/scratch/iFD8T
// Much higher percent scratch with expanded macros: https://decomp.me/scratch/cyGKA

// copy_framebuffer
void func_800C0BC0(Gfx** gfx, void* destination, void* source) {
    s32 row;
    s32 col;
    Gfx* cur_gfx = *gfx;
    
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A7E0));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(destination));
    
    for (row = 0; row < ROUND_UP_DIVIDE(SCREEN_HEIGHT, 32); row++) {
        for (col = 0; col < ROUND_UP_DIVIDE(SCREEN_WIDTH, 32); col++) {
            gDPLoadTextureTile(cur_gfx++, osVirtualToPhysical(source), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                (col * 32), (row * 32), ((col + 1) * 32 - 1), ((row + 1) * 32 - 1), 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(cur_gfx++,
                (col * 32) * 4, (row * 32) * 4,
                ((col + 1) * 32) * 4, ((row + 1) * 32) * 4,
                0,
                (col * 32) << 5, (row * 32) << 5,
                1 << 10, 1 << 10);
        }
    }
    
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A840));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(func_80014F00()));
    
    *gfx = cur_gfx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0BC0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C1044.s")
