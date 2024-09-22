#include <ultra64.h>

// compare_vec4i
int func_800F371C(u32[4], u32[4]);
// copy_vec4i
void func_800F2E7C(u32[4], u32[4]);

typedef struct {
    /* 0x00 */ u32 prim_color[4];
    /* 0x10 */ u32 texture_lut;
    /* 0x14 */ u32 cycle_type;
    /* 0x18 */ u32 filtering_mode;
    /* 0x1C */ u32 texture_persp;
    /* 0x20 */ u32 combiner;
    /* 0x24 */ u8 needs_pipesync;
    /* 0x25 */ u8 unk25;
} unkD_8012D580;

extern unkD_8012D580 D_8012D580;

#ifdef NON_MATCHING
// regalloc
void func_800E7620(void) {
    unkD_8012D580* state = &D_8012D580;
    
    state->prim_color[0] =
    state->prim_color[1] =
    state->prim_color[2] =
    state->prim_color[3] =
    state->cycle_type =
    state->combiner =
    state->filtering_mode = (u32)-1;

    state->texture_lut = 0;
    state->texture_persp = G_TP_PERSP;
    state->needs_pipesync = FALSE;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0F10/func_800E7620.s")
#endif

// do_pipesync
void func_800E765C(Gfx** gfx) {
    if (D_8012D580.needs_pipesync) {
        gDPPipeSync((*gfx)++);
        D_8012D580.needs_pipesync = FALSE;
    }
}

// set_needs_pipesync
void func_800E7694() {
    D_8012D580.needs_pipesync = TRUE;
}

// set_combiner
void func_800E76A4(Gfx** gfx, s32 arg1) {
    if (D_8012D580.combiner != arg1) {
        D_8012D580.combiner = arg1;
        func_800E765C(gfx);
        switch (arg1) {
            case 0:
                gDPSetCombineLERP((*gfx)++,
                    TEXEL0, 0, PRIMITIVE, 0,
                    TEXEL0, 0, PRIMITIVE, 0, 
                    TEXEL0, 0, PRIMITIVE, 0,
                    TEXEL0, 0, PRIMITIVE, 0);
                break;
            case 1:
                gDPSetCombineLERP((*gfx)++,
                    0, 0, 0, TEXEL0,
                    TEXEL0, 0, TEXEL1, 0,
                    COMBINED, 0, PRIMITIVE, 0,
                    COMBINED, 0, PRIMITIVE, 0);
                break;
            case 2:
                gDPSetCombineLERP((*gfx)++,
                    0, 0, 0, PRIMITIVE,
                    0, 0, 0, PRIMITIVE,
                    0, 0, 0, PRIMITIVE,
                    0, 0, 0, PRIMITIVE);
                break;
        }
    }
}

// set_cycle_type
void func_800E7778(Gfx** gfx, u32 cycle_type) {
    if (D_8012D580.cycle_type != cycle_type) {
        D_8012D580.cycle_type = cycle_type;
        func_800E765C(gfx);
        gDPSetCycleType((*gfx)++, cycle_type);

        // Pick a render mode suitable for the cycle type.
        if (cycle_type == G_CYC_1CYCLE) {
            gDPSetRenderMode((*gfx)++, G_RM_XLU_SURF | ZMODE_XLU, G_RM_XLU_SURF2 | ZMODE_XLU);
        }
        else {
            gDPSetRenderMode((*gfx)++, G_RM_PASS, G_RM_XLU_SURF2 | ZMODE_XLU);
        }
    }
}

// set_primitive_color
void func_800E7828(Gfx** gfx, u8 color[4]) {
    u32 color_u32[4];
    func_800F2EFC(color_u32, color);
    if (!func_800F371C(D_8012D580.prim_color, color_u32)) {
        func_800F2E7C(D_8012D580.prim_color, color_u32);
        func_800E765C(gfx);

        gDPSetPrimColor((*gfx)++, 0, 0, color_u32[0], color_u32[1], color_u32[2], color_u32[3]);
    }
}

// set_texture_filtering_mode
void func_800E78C8(Gfx** gfx, u32 mode) {
    if (D_8012D580.filtering_mode != mode) {
        D_8012D580.filtering_mode = mode;
        func_800E765C(gfx);
        gDPSetTextureFilter((*gfx)++, mode);
    }
}

// set_texture_lut
void func_800E7928(Gfx** gfx, u32 texture_lut) {
    if (D_8012D580.texture_lut != texture_lut) {
        D_8012D580.texture_lut = texture_lut;
        func_800E765C(gfx);
        gDPSetTextureLUT((*gfx)++, texture_lut);
    }
}

// set_texture_persp
void func_800E7988(Gfx** gfx, u32 texture_persp) {
    if (D_8012D580.texture_persp != texture_persp) {
        D_8012D580.texture_persp = texture_persp;
        func_800E765C(gfx);
        gDPSetTexturePersp((*gfx)++, texture_persp);
    }
}

extern Gfx D_80123310[];

void func_800E79E8(Gfx** gfx) {
    gSPDisplayList((*gfx)++, OS_K0_TO_PHYSICAL(D_80123310));
    func_800E7620();
    D_8012D580.unk25 = 1;
}

void func_800E7A2C(Gfx** gfx) {
    func_800E7620();
}

void func_800E7A4C(Gfx** gfx) {
    func_800E7928(gfx, G_TT_NONE);
    func_800E7988(gfx, G_TP_PERSP);
    func_800E78C8(gfx, G_TF_BILERP);
    D_8012D580.unk25 = 0;
}
