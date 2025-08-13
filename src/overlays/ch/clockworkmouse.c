#include "overlays/ch/clockworkmouse.h"

// size of 4 might be incorrect
extern Unk80803CD8 *D_80803CD8_chclockworkmouse[4];
extern s32 D_80803CE8_chclockworkmouse[4];
extern Unk80803E08 *D_80803E08_chclockworkmouse[4];
extern s32 D_80803E18_chclockworkmouse[4];
extern s32 D_80803E28_chclockworkmouse[4];
extern s32 *D_80803E48_chclockworkmouse;
extern s32 *D_80803EF0_chclockworkmouse;


void func_80800000_chclockworkmouse(void) {
    func_800DA564(0xA37, 3);
}

void func_80800024_chclockworkmouse(s32 arg0) {
    func_800DA7A8(0x9DA, arg0, 2);
    func_800FDC28(0);
    switch (arg0) {
    case 1:
        func_800FC660(0x17);
        return;
    case 2:
        func_800FC660(0x16);
        return;
    }
}

void func_80800090_chclockworkmouse(void) {
    func_800DA564(0x9DA, 2);
}

void func_808000B4_chclockworkmouse(Unk80100094 *arg0) {

    switch (func_80100094(arg0, 0)->unkF) {
    case 1:
        _gcgoto_entrypoint_1(0x161, 1);
        return;
    case 0:
    case 2:
        _gcgoto_entrypoint_1(0x136, 0x1F);
        return;
    }
}

u8 func_8080011C_chclockworkmouse(Unk80100094 *arg0) {
    Unk80100094 *sp1C;

    sp1C = func_80100094(arg0, 0);
    sp1C->unkF = func_800DA564(0xA37, 3);
    return sp1C->unkF;
}

void func_80800158_chclockworkmouse(Unk80100094 *arg0, s32 arg1) {
    Unk80100094 *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_800DA7A8(0xA37, arg1, 3);
    sp1C->unkF = arg1;
}

void func_8080019C_chclockworkmouse(Unk80100094 *arg0) {
    switch (func_80100094(arg0, 0)->unkF) {
    case 0:
        func_80800158_chclockworkmouse(arg0, 1);
        func_808000B4_chclockworkmouse(arg0);
        return;
    case 1:
        func_80800158_chclockworkmouse(arg0, 2);
        _gcintrotext_entrypoint_0();
        func_808000B4_chclockworkmouse(arg0);
        return;
    case 2:
        func_80800158_chclockworkmouse(arg0, 0);
        func_80800024_chclockworkmouse(0);
        return;
    }
}

void func_80800240_chclockworkmouse(Unk80100094 *arg0, s32 arg1) {
    s32 *sp6C[1]; // vec3f ref?
    f32 *sp68[1];
    s16* var_s3;
    s16* var_s4;
    s32 temp_v0;
    s32 var_s0;
    Unk80803CD8** temp_s2;
    s32 temp_s0;
    Unk80100094* sp4C;

    temp_s0 = arg1 - 1;
    sp4C = func_80100094(arg0, 0);
    temp_v0 = func_80100074(arg0, 1, _susplinet_entrypoint_18(D_80803CE8_chclockworkmouse[temp_s0], 1, 1));
    _susplinet_entrypoint_19(temp_v0, D_80803CE8_chclockworkmouse[temp_s0], 1, 1);
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp6C[var_s0] = _susplinet_entrypoint_14(temp_v0, var_s0);
    }
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp68[var_s0] = _susplinet_entrypoint_15(temp_v0, var_s0);
    }
    var_s3 = _susplinet_entrypoint_12(temp_v0);
    var_s4 = _susplinet_entrypoint_13(temp_v0);
    for (var_s0 = 0; var_s0 < D_80803CE8_chclockworkmouse[temp_s0];) {
        func_800EE7F8(sp6C[0], &D_80803CD8_chclockworkmouse[temp_s0][var_s0]);
        var_s3[0] = D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk10;
        var_s4[0] = -1;
        sp68[0][0] = D_80803CD8_chclockworkmouse[temp_s0][var_s0].unkC;
        _susplinet_entrypoint_0(temp_v0, var_s0, 2, D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk12 & 1 ? 1 : 0);
        _susplinet_entrypoint_0(temp_v0, var_s0, 4, D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk12 & 2 ? 1 : 0);
        var_s0++;
        var_s3++;
        var_s4++;
        sp68[0]++;
        sp6C[0] += 3;
    }
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp6C[var_s0] = _susplinet_entrypoint_14(temp_v0, var_s0);
    }
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp68[var_s0] = _susplinet_entrypoint_15(temp_v0, var_s0);
    }
    func_800F0EF0(D_80803CE8_chclockworkmouse[temp_s0], sp6C[0]);
    sp4C->unkFB = arg1;
    sp4C->unkFC = 0;
}

void func_808004B0_chclockworkmouse(Unk80100094* arg0) {
    Unk80100094* sp74;
    Unk80100094* temp_s0;
    f32 sp6C;
    Unk80100094* sp68;
    s32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 temp_f2;

    sp74 = func_80100094(arg0, 1);
    temp_s0 = func_80100094(arg0, 0);
    sp6C = func_800D8FF8();
    sp68 = NULL;
    if (temp_s0->unkFA == 3) {
        switch (temp_s0->unkFB) {
        case 1:
        case 3:
            sp68 = arg0;
            break;
        case 2:
        case 4:
            sp68 = func_80106790(arg0->unk3C);
            break;
        }
        _susplinet_entrypoint_11(sp74, _susplinet_entrypoint_9(sp74));
        _susplinet_entrypoint_10(sp74, func_80105AE8(sp68) * 1000.0f);
        _susplinet_entrypoint_17(sp74);
        _susplinet_entrypoint_7(sp74, 0, sp5C);
        func_800EF5A0(sp50, sp5C, 0.0f, 0.0f, -_susplinet_entrypoint_8(sp74, 0));
        if (_susplinet_entrypoint_6(sp74) != 0) {
            temp_s0->unkFC = 0;
        }
        if (temp_s0->unkFC != 0) {
            temp_f2 = 3.0f * sp6C;
            temp_s0->unk10C += func_800F1DCC(sp68->unk44, temp_s0->unk10C) * temp_f2;
            temp_s0->unk110 += func_800F1DCC(sp68->unk48, temp_s0->unk110) * temp_f2;
        } else {
            temp_s0->unk10C = sp68->unk44;
            temp_s0->unk110 = sp68->unk48;
            temp_s0->unkFC = 1;
        }
        func_800EF4E4(sp50, temp_s0->unk10C, temp_s0->unk110, sp50[0], sp50[1], sp50[2]);
        func_800EF4E4(sp38, temp_s0->unk10C, temp_s0->unk110, 0, 75.0f, 150.0f);
        func_800EF04C(sp50, &sp68->unk4);
        func_800EF04C(sp38, &sp68->unk4);
        func_800A516C(sp44, sp38, sp50);
        _capod_entrypoint_1(sp50, sp44);
    }
}

void func_80800700_chclockworkmouse(s32 *arg0, s32 arg1) {
    _capod_entrypoint_2(*arg0, 0x1C, arg1 | 0x800);
}

void func_80800734_chclockworkmouse(Unk80100094 *arg0) {
    if (func_80100094(arg0, 0)->unkFA == 3) {
        func_80100074(arg0, 1, 0);
    }
}

void func_80800774_chclockworkmouse(s32 *arg0) {
    func_8008FB58(&arg0[1], 0.0f, 70.0f);
}

// jump table issues
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080079C_chclockworkmouse.s")

// jump table issues
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800850_chclockworkmouse.s")

// jump table issues
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808008DC_chclockworkmouse.s")

// jump table issues
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800968_chclockworkmouse.s")

void func_808009F4_chclockworkmouse(Unk80100094 *arg0) {
    Unk80100094 *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_80800734_chclockworkmouse(arg0);
    if (sp1C->unkFA != 0) {
        _capod_entrypoint_3(0);
        sp1C->unkFA = 0;
    }
}

void func_80800A44_chclockworkmouse(Unk80100094 *arg0) {
    Unk80100094* temp_v0;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s4;

    temp_v0 = func_80100094(arg0, 0);
    temp_v1 = temp_v0->unkFB - 1;
    if (D_80803E08_chclockworkmouse[temp_v1] == NULL) {
        return;
    }

    if (!(arg0->unk7C & 0xFFF)) {
        return;
    }

    for (var_s4 = 0, var_s0 = 0; var_s4 < D_80803E18_chclockworkmouse[temp_v1];  var_s4++, var_s0++) {
        if (func_80105998(arg0, D_80803E08_chclockworkmouse[temp_v1][var_s0].unk0) != 0) {
            switch (D_80803E08_chclockworkmouse[temp_v1][var_s0].unkC) {
            case 1:
                if (temp_v0->unkFE != 0) {
                    func_80800968_chclockworkmouse(arg0, temp_v0->unkFB, 4);
                }
                break;
            case 2:
                if (temp_v0->unkFE != 0) {
                    func_808008DC_chclockworkmouse(arg0, D_80803E08_chclockworkmouse[temp_v1][var_s0].unkE, 5, arg0->unk0);
                }
                break;
            case 3:
                if (temp_v0->unkFE != 0) {
                    temp_v0->unk104 = D_80803E08_chclockworkmouse[temp_v1][var_s0].unk4;
                    temp_v0->unk108 = D_80803E08_chclockworkmouse[temp_v1][var_s0].unk8;
                    func_80800850_chclockworkmouse(arg0, D_80803E08_chclockworkmouse[temp_v1][var_s0].unkE, 4, arg0->unk0);
                }
                break;
            }
            temp_v0->unkFF = D_80803E08_chclockworkmouse[temp_v1][var_s0].unkC;
        }
    }
}

void func_80800C14_chclockworkmouse(Unk80100094 *arg0) {
    f32 sp1C[3];

    func_800904C8(0x28);
    func_800EEB9C(sp1C, arg0->unk48, 120.0f);
    func_800EF04C(sp1C, &arg0->unk4);
    func_800903D0(sp1C);
}

void func_80800C64_chclockworkmouse(Unk80100094 *arg0) {
    Unk80100094 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if ((func_8009EA64() == 0x171) && (sp1C->unk100 != 0)) {
        sp1C->unk100 = 0;
        func_80800C14_chclockworkmouse(arg0);
        arg0->unk24 = 0.0f;
    }
}

void func_80800CC0_chclockworkmouse(Unk80100094 *arg0) {
    u32 temp_t6;

    temp_t6 = arg0->unk72;
    temp_t6 >>= 0xA;
    if (temp_t6 == 0 || temp_t6 == 1 || temp_t6 == 2) {
        _subaddieDll_entrypoint_4(arg0, 0);
        return;
    }
    _subaddieDll_entrypoint_4(arg0, 1);
}

// jump table issues
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800D14_chclockworkmouse.s")

void func_80800E8C_chclockworkmouse(Unk80100094 *arg0, s32 arg1) {
    Unk80100094 *sp1C;

    sp1C = func_80106790(arg0->unk3C);
    func_80800D14_chclockworkmouse(arg0, arg1);
    func_808022E4_chclockworkmouse(sp1C, arg1);
}

void func_80800ED0_chclockworkmouse(Unk80100094 *arg0) {
    if (func_8009EA64() == 0x171) {
        func_800907C0(&arg0->unk4);
        func_800906DC(&arg0->unk44);
    }
}

f32 func_80800F10_chclockworkmouse(f32* arg0, f32 arg1) {
    f32 sp34;
    s32 temp_v0;

    sp34 = func_800D8FF8();
    temp_v0 = func_80016B30(0, 0);
    if (*arg0 < 0.0f) {
        if (temp_v0 != 0) {
            arg1 += func_800F10B4(*arg0, -1.0f, -0.01f, 0.0f, 3.0f);
            *arg0 = 0.01f;
            return arg1;
        }
        *arg0 -= sp34;
        arg1 *= 0.98f;
    } else {
        if (temp_v0 == 0) {
            arg1 += func_800F10B4(*arg0, 1.0f, 0.01f, 0.0f, 3.0f);
            *arg0 = -0.01f;
            return arg1;
        }
        *arg0 += sp34;
        arg1 *= 0.98f;
    }

    if (arg1 > 200.0f) {
        arg1 = 200.0f;
    }

    return arg1;
}

void func_80801044_chclockworkmouse(Unk80100094* arg0) {
    f32 temp_f12;

    if (arg0->unk24 > 10.0f) {
        temp_f12 = func_800F10B4(1.0f - (arg0->unk24 / 200.0f), 0.0f, 1, 0.5f, 3.0f);
        if (arg0->unk5F == 0) {
            arg0->unk5F = func_800C4350(arg0->unk5F, &arg0->unk4, D_80803E28_chclockworkmouse);
            return;
        }
        func_800C31DC(arg0->unk5F, func_800F10B4(temp_f12, 0.5f, 3.0f, 1.2f, 0.8f));
        func_800C4350(arg0->unk5F, &arg0->unk4, NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080111C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801240_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801508_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801588_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801848_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801850_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808018BC_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801A94_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801B44_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801B90_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801BF0_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801CFC_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/chclockworkmouse_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801E2C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801FC8_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802170_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808021C4_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808022E4_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808026E0_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802724_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080297C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802A48_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802BCC_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802C04_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802C64_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802CC8_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808032F8_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080364C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/chclockworkmouse_entrypoint_1.s")
