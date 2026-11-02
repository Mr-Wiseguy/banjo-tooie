#include "core2/1EAF950.h"

extern s32 D_8012BE70;
extern s16 D_8011B910;
extern s16 D_8012BE64;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D61B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D62E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D66AC.s")

void* asset_load(s32 id) {
    s32 index; // sp34
    u32 sp30;
    unkD_8012B800* sp2C;
    void* sp28;
    void* sp24;

    index = func_800D6254(id);
    // If the asset is already loaded, return it.
    if (index != -1) {
        D_8011B910 = index;
        D_8012BE64 = id;
        sp2C = &D_8012B800[index];
        if (sp2C->unk0_1 == 2) {
            if (func_8001211C() == sp2C->unk0_5) {
                if (sp2C->unk8_17) {
                    sp2C->unk8_16 = 1;
                }
                else {
                    sp2C->unk8_17 = 1;
                }
            }
            else {
                if (func_8001211C() == sp2C->unk0_5 + 1) {
                    sp2C->unk0_0 = sp2C->unk8_17 || sp2C->unk8_16;
                }
                sp2C->unk8_17 = 1;
                sp2C->unk8_16 = 0;
            }
        }
        sp2C->unk0_5 = func_8001211C();
        return sp2C->unk4;
    }
    // Otherwise, try to load the asset.
    else {
        // No free asset slots, so the asset can't be loaded.
        if (D_8012BE62 >= (u32)ARRLEN(D_8012B800) - 1) {
            return NULL;
        }
        sp30 = func_800D58FC(id);
        sp28 = func_800D5B34(id);
        if (sp28 == 0) {
            D_8012BE64 = 0;
            return NULL;
        }
        index = func_800D6060(id);
        sp2C = &D_8012B800[index];
        D_8012BE62++;
        D_8011B910 = index;
        sp2C->unk0_5 = func_8001211C();
        sp2C->unk4 = sp28;
        sp2C->unk8_12 = 0;
        sp2C->unk8_8 = 0;
        sp2C->id = id;
        D_8012BE64 = id;
        switch (sp30) {
        case 0:
            sp2C->unk0_1 = 2;
            sp2C->unk8_17 = 1;
            sp2C->unk8_16 = 0;
            sp2C->unk8_0 = 0;
            if (sp2C->unk4->unk2C != 0) {
                sp24 = (u8*)sp2C->unk4 + sp2C->unk4->unk2C;
            }
            else {
                sp24 = NULL;
            }
            if (sp24 != NULL) {
                sp2C->unk8_0 = func_800DBA84();
                func_800DBBF8(sp2C->unk8_0, sp24);
            }
            break;
        case 1:
            sp2C->unk0_1 = 1;
            break;
        case 3:
        case 10:
            sp2C->unk0_1 = 4;
            break;
        case 5:
            sp2C->unk0_1 = 3;
            break;
        case 6:
            sp2C->unk0_1 = 5;
            break;
        case 7:
            sp2C->unk0_1 = 6;
            break;
        case 8:
            sp2C->unk0_1 = 7;
            break;
        case 2:
            sp2C->unk0_1 = 8;
            break;
        case 9:
            sp2C->unk0_1 = 9;
            break;
        }
        return sp28;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D70D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D70F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D71F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D721C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D725C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D731C.s")

s32 func_800D738C(s32 arg0)
{
    return func_800D58FC(arg0);
}

void func_800D73AC()
{
    func_800D59C0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D73CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D740C.s")

void func_800D7418()
{
    _glsplineDll_entrypoint_0(&D_8012BE70);
}

void func_800D743C()
{
    _glsplineDll_entrypoint_1(&D_8012BE70);
}

void func_800D7460()
{
    func_800D743C();
    func_800D7418();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D75DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7754.s")

void func_800D7900(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D86F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8744.s")

void func_800D87B0()
{
    _glsplineDll_entrypoint_2(&D_8012BE70);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D87D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D87EC.s")

void func_800D8800(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8808.s")
