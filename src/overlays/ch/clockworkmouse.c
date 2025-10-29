#include "overlays/ch/clockworkmouse.h"

#define CLOCKWORK_DATA(arg0) ((ClockworkActorData*)(arg0->actorData))

// size of 4 might be incorrect
extern Unk80803CD8 *D_80803CD8_chclockworkmouse[4];
extern s32 D_80803CE8_chclockworkmouse[4];
extern Unk80803E08 *D_80803E08_chclockworkmouse[4];
extern s32 D_80803E18_chclockworkmouse[4];
extern s32 D_80803E28_chclockworkmouse[4];
extern ActorData *D_80803E48_chclockworkmouse;
extern ActorData *D_80803EF0_chclockworkmouse;

extern f32 D_80803E3C_chclockworkmouse[3]; // all 0s

extern void *D_80803950_chclockworkmouse; // unknown data
extern void *D_80803964_chclockworkmouse; // unknown data
extern void *D_80803978_chclockworkmouse; // unknown data
extern void *D_80803E90_chclockworkmouse; // unknown data
extern void *D_80803E9C_chclockworkmouse; // unknown data
extern void *D_80803EB0_chclockworkmouse; // unknown data
extern void *D_80803EBC_chclockworkmouse; // unknown data
extern void *D_80803ED0_chclockworkmouse; // unknown data
extern void *D_80803EE0_chclockworkmouse; // unknown data

s32 func_80800000_chclockworkmouse(void) {
    return func_800DA564(FLAG3_A37_CANARY_MARY_RACE_STATE_1, 3);
}

void func_80800024_chclockworkmouse(s32 arg0) {
    func_800DA7A8(FLAG3_9DA_UNK, arg0, 2);
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

s32 func_80800090_chclockworkmouse(void) {
    return func_800DA564(FLAG3_9DA_UNK, 2);
}

void func_808000B4_chclockworkmouse(Actor *actor) {

    switch (((Unk80100094 *)func_80100094(actor, 0))->unkC.bytes[3]) {
    case 1:
        _gcgoto_entrypoint_1(0x161, 1);
        return;
    case 0:
    case 2:
        _gcgoto_entrypoint_1(0x136, 0x1F);
        return;
    }
}

u8 func_8080011C_chclockworkmouse(Actor *actor) {
    Unk80100094 *sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    sp1C->unkC.bytes[3] = func_800DA564(FLAG3_A37_CANARY_MARY_RACE_STATE_1, 3);
    return sp1C->unkC.bytes[3];
}

void func_80800158_chclockworkmouse(Actor *actor, s32 arg1) {
    Unk80100094 *sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    func_800DA7A8(FLAG3_A37_CANARY_MARY_RACE_STATE_1, arg1, 3);
    sp1C->unkC.bytes[3] = arg1;
}

void func_8080019C_chclockworkmouse(Actor *actor) {
    switch (((Unk80100094 *)func_80100094(actor, 0))->unkC.bytes[3]) {
    case 0:
        func_80800158_chclockworkmouse(actor, 1);
        func_808000B4_chclockworkmouse(actor);
        return;
    case 1:
        func_80800158_chclockworkmouse(actor, 2);
        _gcintrotext_entrypoint_0();
        func_808000B4_chclockworkmouse(actor);
        return;
    case 2:
        func_80800158_chclockworkmouse(actor, 0);
        func_80800024_chclockworkmouse(0);
        return;
    }
}

void func_80800240_chclockworkmouse(Actor *actor, s32 arg1) {
    Vec3f *sp6C[1];
    f32 *sp68[1];
    s16* var_s3;
    s16* var_s4;
    SplineMemory * splineMemory;
    s32 var_s0;
    s32 temp_s0;
    s32 pad;
    Unk80100094* sp4C;

    temp_s0 = arg1 - 1;
    sp4C = ((Unk80100094 *)func_80100094(actor, 0));
    splineMemory = (SplineMemory *)func_80100074(actor, 1, _susplinet_entrypoint_18(D_80803CE8_chclockworkmouse[temp_s0], 1, 1));
    _susplinet_entrypoint_19(splineMemory, D_80803CE8_chclockworkmouse[temp_s0], 1, 1);
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp6C[var_s0] = _susplinet_entrypoint_14(splineMemory, var_s0);
    }
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp68[var_s0] = _susplinet_entrypoint_15(splineMemory, var_s0);
    }
    var_s3 = _susplinet_entrypoint_12(splineMemory);
    var_s4 = _susplinet_entrypoint_13(splineMemory);
    for (var_s0 = 0; var_s0 < D_80803CE8_chclockworkmouse[temp_s0];) {
        func_800EE7F8(sp6C[0]->f, D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk0);
        var_s3[0] = D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk10;
        var_s4[0] = -1;
        sp68[0][0] = D_80803CD8_chclockworkmouse[temp_s0][var_s0].unkC;
        _susplinet_entrypoint_0(splineMemory, var_s0, 2, D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk12 & 1 ? 1 : 0);
        _susplinet_entrypoint_0(splineMemory, var_s0, 4, D_80803CD8_chclockworkmouse[temp_s0][var_s0].unk12 & 2 ? 1 : 0);
        var_s0++;
        var_s3++;
        var_s4++;
        sp68[0]++;
        sp6C[0]++;
    }
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp6C[var_s0] = _susplinet_entrypoint_14(splineMemory, var_s0);
    }
    for (var_s0 = 0; var_s0 < 1; var_s0++) {
        sp68[var_s0] = _susplinet_entrypoint_15(splineMemory, var_s0);
    }
    func_800F0EF0(D_80803CE8_chclockworkmouse[temp_s0], sp6C[0]->f);
    sp4C->unkFB = arg1;
    sp4C->unkFC = 0;
}

void func_808004B0_chclockworkmouse(Actor* actor) {
    SplineMemory* splineMemory;
    Unk80100094* temp_s0;
    f32 sp6C;
    Actor* sp68;
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 temp_f2;

    splineMemory = (SplineMemory *)func_80100094(actor, 1);
    temp_s0 = ((Unk80100094 *)func_80100094(actor, 0));
    sp6C = func_800D8FF8();
    sp68 = NULL;
    if (temp_s0->unkFA == 3) {
        switch (temp_s0->unkFB) {
        case 1:
        case 3:
            sp68 = actor;
            break;
        case 2:
        case 4:
            sp68 = func_80106790(actor->unk3C);
            break;
        }
        _susplinet_entrypoint_11(splineMemory, _susplinet_entrypoint_9(splineMemory));
        _susplinet_entrypoint_10(splineMemory, func_80105AE8(sp68) * 1000.0f);
        _susplinet_entrypoint_17(splineMemory);
        _susplinet_entrypoint_7(splineMemory, 0, sp5C);
        func_800EF5A0(sp50, sp5C, 0.0f, 0.0f, -_susplinet_entrypoint_8(splineMemory, 0));
        if (_susplinet_entrypoint_6(splineMemory) != 0) {
            temp_s0->unkFC = 0;
        }
        if (temp_s0->unkFC != 0) {
            temp_f2 = 3.0f * sp6C;
            temp_s0->unk10C += func_800F1DCC(sp68->rotation[0], temp_s0->unk10C) * temp_f2;
            temp_s0->unk110 += func_800F1DCC(sp68->rotation[1], temp_s0->unk110) * temp_f2;
        } else {
            temp_s0->unk10C = sp68->rotation[0];
            temp_s0->unk110 = sp68->rotation[1];
            temp_s0->unkFC = 1;
        }
        func_800EF4E4(sp50, temp_s0->unk10C, temp_s0->unk110, sp50[0], sp50[1], sp50[2]);
        func_800EF4E4(sp38, temp_s0->unk10C, temp_s0->unk110, 0, 75.0f, 150.0f);
        func_800EF04C(sp50, sp68->position);
        func_800EF04C(sp38, sp68->position);
        func_800A516C(sp44, sp38, sp50);
        _capod_entrypoint_1(sp50, sp44);
    }
}

void func_80800700_chclockworkmouse(Unk80132ED0 **arg0, s32 arg1) {
    _capod_entrypoint_2(*arg0, 0x1C, arg1 | 0x800);
}

void func_80800734_chclockworkmouse(Actor *actor) {
    if (((Unk80100094 *)func_80100094(actor, 0))->unkFA == 3) {
        func_80100074(actor, 1, 0);
    }
}

void func_80800774_chclockworkmouse(Actor *actor) {
    func_8008FB58(actor->position, 0.0f, 70.0f);
}

void func_8080079C_chclockworkmouse(Actor *actor, Actor *arg1, s32 arg2, s32 arg3) {
    Unk80100094 *sp1C;
    u8 temp_t8;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    func_80800734_chclockworkmouse(actor);
    if (arg1 == NULL) {
        arg1 = actor;
    }
    switch (sp1C->unkFA) {
    case 0:
        func_80800700_chclockworkmouse(&actor->unk0, 0);
        /* fallthrough */
    case 1:
    case 3:
    case 4:
        _capod_entrypoint_8(1);
        sp1C->unkFA = 2;
        _gcdialogcamera_entrypoint_6(arg1->unk0);
        _gcdialogcamera_entrypoint_8();
        /* fallthrough */
    case 2:
        _capod_entrypoint_7(arg2, arg3);
        break;
    }
}

void func_80800850_chclockworkmouse(Actor* actor, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    Unk80100094* sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    func_80800734_chclockworkmouse(actor);
    switch (sp1C->unkFA) {
    case 0:
        func_80800700_chclockworkmouse(&actor->unk0, arg2);
        /* fallthrough */
    case 2:
    case 3:
    case 4:
        sp1C->unkFA = 1;
        /* fallthrough */
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
        break;
    }
}

void func_808008DC_chclockworkmouse(Actor* actor, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    Unk80100094* sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    func_80800734_chclockworkmouse(actor);
    switch (sp1C->unkFA) {
    case 0:
        func_80800700_chclockworkmouse(&actor->unk0, arg2);
        /* fallthrough */
    case 1:
    case 2:
    case 3:
        sp1C->unkFA = 4;
        /* fallthrough */
    case 4:
        _capod_entrypoint_20(arg3, arg1, arg2);
        break;
    }
}

void func_80800968_chclockworkmouse(Actor* actor, s32 arg1, s32 arg2) {
    Unk80100094* sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    func_80800734_chclockworkmouse(actor);
    switch (sp1C->unkFA) {
    case 0:
        func_80800700_chclockworkmouse(&actor->unk0, arg2);
        /* fallthrough */
    case 1:
    case 2:
    case 4:
        sp1C->unkFA = 3;
        /* fallthrough */
    case 3:
        _capod_entrypoint_8(0);
        func_80800240_chclockworkmouse(actor, arg1);
        break;
    }
}

void func_808009F4_chclockworkmouse(Actor *actor) {
    Unk80100094 *sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    func_80800734_chclockworkmouse(actor);
    if (sp1C->unkFA != 0) {
        _capod_entrypoint_3(0);
        sp1C->unkFA = 0;
    }
}

void func_80800A44_chclockworkmouse(Actor *actor) {
    Unk80100094* temp_v0;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s4;

    temp_v0 = ((Unk80100094 *)func_80100094(actor, 0));
    temp_v1 = temp_v0->unkFB - 1;
    if (D_80803E08_chclockworkmouse[temp_v1] == NULL) {
        return;
    }

    if (!actor->unk7C_0) {
        return;
    }

    for (var_s4 = 0, var_s0 = 0; var_s4 < D_80803E18_chclockworkmouse[temp_v1];  var_s4++, var_s0++) {
        if (func_80105998(actor, D_80803E08_chclockworkmouse[temp_v1][var_s0].unk0) != 0) {
            switch (D_80803E08_chclockworkmouse[temp_v1][var_s0].unkC) {
            case 1:
                if (temp_v0->unkFE != 0) {
                    func_80800968_chclockworkmouse(actor, temp_v0->unkFB, 4);
                }
                break;
            case 2:
                if (temp_v0->unkFE != 0) {
                    func_808008DC_chclockworkmouse(actor, D_80803E08_chclockworkmouse[temp_v1][var_s0].unkE, 5, actor->unk0);
                }
                break;
            case 3:
                if (temp_v0->unkFE != 0) {
                    temp_v0->unk104 = D_80803E08_chclockworkmouse[temp_v1][var_s0].unk4;
                    temp_v0->unk108 = D_80803E08_chclockworkmouse[temp_v1][var_s0].unk8;
                    func_80800850_chclockworkmouse(actor, D_80803E08_chclockworkmouse[temp_v1][var_s0].unkE, 4, actor->unk0);
                }
                break;
            }
            temp_v0->unkFF = D_80803E08_chclockworkmouse[temp_v1][var_s0].unkC;
        }
    }
}

void func_80800C14_chclockworkmouse(Actor *actor) {
    f32 sp1C[3];

    func_800904C8(0x28);
    func_800EEB9C(sp1C, actor->rotation[1], 120.0f);
    func_800EF04C(sp1C, actor->position);
    func_800903D0(sp1C);
}

void func_80800C64_chclockworkmouse(Actor *actor) {
    Unk80100094 *sp1C;

    sp1C = ((Unk80100094 *)func_80100094(actor, 0));
    if ((func_8009EA64() == 0x171) && (sp1C->unk100 != 0)) {
        sp1C->unk100 = 0;
        func_80800C14_chclockworkmouse(actor);
        CLOCKWORK_DATA(actor)->unkC = 0.0f;
    }
}

void func_80800CC0_chclockworkmouse(Actor *actor) {
    if (actor->unk70_10 == 0 || actor->unk70_10 == 1 || actor->unk70_10 == 2) {
        _subaddieDll_entrypoint_4(actor, 0);
        return;
    }
    _subaddieDll_entrypoint_4(actor, 1);
}

void func_80800D14_chclockworkmouse(Actor* actor, s32 arg1) {
    Unk80100094* sp24;
    s32 var_a0;

    sp24 = ((Unk80100094 *)func_80100094(actor, 0));
    switch (actor->unk70_10) {
    case 11:
        break;
    case 4: 
        func_800F4CC0(func_800F54E4());
        break;
    case 23:
        func_80103140(actor, 0x8A0, ((u16*)actor->unk0)[0xB]);
        break;
    }
    func_80102424(actor, arg1);
    switch (actor->unk70_10) {
    case 3:
        func_800903D0(actor->position);
        break;
    case 4:
        func_800904F4(0x27, actor->unk0);
        sp24->unk100 = 1;
        func_800F4CEC(func_800F54E4(), 0x3B);
        break;
    case 5:
        func_800904F4(0x27, actor->unk0);
        sp24->unk100 = 1;
        break;
    case 6:
        sp24->unkDC = 0.15f;
        for (var_a0 = 0; var_a0 < 10; var_a0++) {
            sp24->unkF0[var_a0] = 1;
        }
        break;
    case 7:
        func_80800C64_chclockworkmouse(actor);
        break;

        // ?????????
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
    func_80800CC0_chclockworkmouse(actor);
}

void func_80800E8C_chclockworkmouse(Actor *actor, s32 arg1) {
    Actor *sp1C;

    sp1C = func_80106790(actor->unk3C);
    func_80800D14_chclockworkmouse(actor, arg1);
    func_808022E4_chclockworkmouse(sp1C, arg1);
}

void func_80800ED0_chclockworkmouse(Actor *actor) {
    if (func_8009EA64() == 0x171) {
        func_800907C0(actor->position);
        func_800906DC(actor->rotation);
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

void func_80801044_chclockworkmouse(Actor* actor) {
    f32 temp_f12;

    if (CLOCKWORK_DATA(actor)->unkC > 10.0f) {
        temp_f12 = func_800F10B4(1.0f - (CLOCKWORK_DATA(actor)->unkC / 200.0f), 0.0f, 1, 0.5f, 3.0f);
        if (actor->unk5F == 0) {
            actor->unk5F = func_800C4350(actor->unk5F, actor->position, (s32 *)D_80803E28_chclockworkmouse);
            return;
        }
        func_800C31DC(actor->unk5F, func_800F10B4(temp_f12, 0.5f, 3.0f, 1.2f, 0.8f));
        func_800C4350(actor->unk5F, actor->position, NULL);
    }
}

void func_8080111C_chclockworkmouse(Actor* actor) {
    Unk80100094* temp_s1;
    f32 sp28;
 
    sp28 = 0.1f;
    temp_s1 = ((Unk80100094 *)func_80100094(actor, 0));
    func_80105A9C(actor, CLOCKWORK_DATA(actor)->unkC * 10.0f);
    func_80105834(actor);
    temp_s1->unkD8 = (((func_800F1DCC(actor->rotation[1], temp_s1->unkD4) * 10.0f) - temp_s1->unkD8) * 0.02f);
    actor->rotation[2] = func_800F10B4(CLOCKWORK_DATA(actor)->unkC, 0.0f, 500.0f, 0.0f, temp_s1->unkD8);
    temp_s1->unkD4 = actor->rotation[1];
    if (temp_s1->unkFD == 0) {
        sp28 = 1.0f;
        temp_s1->unkFD = 1;
    }
    actor->rotation[0] += func_800F1DCC(actor->unk50, actor->rotation[0]) * sp28;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * sp28;
    func_80801044_chclockworkmouse(actor);
}

void func_80801240_chclockworkmouse(Actor* actor) {
    Unk80100094* temp_v0;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f28;
    Unk800C7A68 *temp_s5;
    s32 var_s3;

    temp_f20 = func_80105AE8(actor);
    temp_v0 = (Unk80100094 *)func_80100094(actor, 0);
    temp_s5 = (Unk800C7A68 *)func_800D7520(temp_v0->unk0.shorts.unk0);
    temp_f28 = func_800D8FF8(); 
    for (var_s3 = 0; var_s3 < 10; var_s3++) {
        if (temp_v0->unkF0[var_s3] == 1) {
            temp_f0 = func_800C7B7C(temp_s5, temp_v0->unkEC, 250.0f, 1.0f);
            temp_v0->unkEC = temp_f0;
            temp_v0->unk84[var_s3] = temp_f0;
            func_800C7A68(temp_s5, temp_v0->unkEC, (s32)&temp_v0->unkC.vecs[var_s3]);
            temp_v0->unkF0[var_s3] = 2U;
            temp_v0->unkAC[var_s3] = temp_v0->unkDC;
            temp_v0->unkDC += 0.0075000003f;
            if (temp_v0->unkDC > 0.3f) {
                temp_v0->unkDC = 0.15f;
            }
            temp_v0->unkE0[var_s3] = 0;
        }
    }
    for (var_s3 = 0; var_s3 < 10; var_s3++) {
        if (temp_v0->unkF0[var_s3] == 2) {
            temp_f0 = 1.5f * temp_f28;
            if (temp_v0->unkE0[var_s3] != 0) {
                temp_v0->unkAC[var_s3] -= temp_f0;
                if (temp_v0->unkAC[var_s3] <= 0.15f) {
                    temp_v0->unkE0[var_s3] = 0U;
                }
            } else {
                temp_v0->unkAC[var_s3] += temp_f0;
                if (temp_v0->unkAC[var_s3] >= 0.3f) {
                    temp_v0->unkE0[var_s3] = 1U;
                }
            }
            if (temp_v0->unk84[var_s3] <= temp_f20) {
                if (temp_f20 >= 1.0f) {
                    temp_v0->unkF0[var_s3] = 0U;
                } else {
                    temp_v0->unkF0[var_s3] = 1U;
                }
            }
        }
    }
}


void func_80801508_chclockworkmouse(Actor* actor) {
    CLOCKWORK_DATA(actor)->unkC *= 0.95f;
    actor->rotation[0] += func_800F1DCC(0.0f, actor->rotation[0]) * 0.05f;
    actor->rotation[2] += func_800F1DCC(0.0f, actor->rotation[2]) * 0.05f;
}

void func_80801588_chclockworkmouse(Actor* actor) {
    Actor* sp3C;
    f32 sp38;
    Unk80100094* sp34;

    if (actor->unk3C == 0) {
        func_80800774_chclockworkmouse(actor);
        return;
    }
    sp38 = func_800D8FF8();
    sp3C = func_80106790(actor->unk3C);
    sp34 = ((Unk80100094 *)func_80100094(actor, 0));
    sp34->unk8 += 5.0f * CLOCKWORK_DATA(actor)->unkC * sp38;
    switch (actor->unk70_10) {
    case 2:
    case 17:
        func_80800774_chclockworkmouse(actor);
        if ((func_80090178(1) != 0) && (func_8010C9B0(actor->position, 0x96) != 0)) {
            func_80800E8C_chclockworkmouse(actor, 3);
        }
        break;
    case 3:
        if (func_8010CB0C(actor->position, 0x32, 0x32, 0) != 0) {
            func_800DA544(FLAG_42B_UNK);
            func_80800E8C_chclockworkmouse(actor, 4);
        }
        break;
    case 4:
        {
            f32 sp28[3] = D_80803E3C_chclockworkmouse;
            f32 temp_f0;
            func_800907C0(actor->position);
            sp28[1] = func_80090010();
            temp_f0 = func_800F1DCC(actor->rotation[1], sp28[1]);
            if ((temp_f0 < -35.0f) || (temp_f0 > 35.0f)) {
                sp28[1] += temp_f0 * sp38 * 5.0f;
                func_800906DC(sp28);
            } else {
                func_8080019C_chclockworkmouse(sp3C);
            }
        }
        break;
    case 5:
        func_80800ED0_chclockworkmouse(actor);
        break;
    case 6:
        CLOCKWORK_DATA(actor)->unkC = func_80800F10_chclockworkmouse(&sp34->unk4, CLOCKWORK_DATA(actor)->unkC);
        func_8080111C_chclockworkmouse(actor);
        func_80800ED0_chclockworkmouse(actor);
        func_80801240_chclockworkmouse(actor);
        if (func_80105A5C(actor) != 0) {
            func_80800E8C_chclockworkmouse(actor, 7);
        }
        break;
    case 9:
    case 10:
    case 11:
        CLOCKWORK_DATA(actor)->unkC = func_80800F10_chclockworkmouse(&sp34->unk4, CLOCKWORK_DATA(actor)->unkC);
        func_8080111C_chclockworkmouse(actor);
        func_80800ED0_chclockworkmouse(actor);
        func_80801240_chclockworkmouse(actor);
        break;
    case 7:
    case 8:
    case 12:
    case 13:
        func_80801508_chclockworkmouse(actor);
        break;
    case 14:
    case 15:
        func_80800774_chclockworkmouse(actor);
        func_80801508_chclockworkmouse(actor);
        break;
    }
    if ((sp34->unkFB == 1) || (sp34->unkFB == 3)) {
        func_80800A44_chclockworkmouse(actor);
        func_808004B0_chclockworkmouse(actor);
    }
}

void func_80801848_chclockworkmouse(s32 actor) {
}

void func_80801850_chclockworkmouse(Actor *actor) {
    Actor *temp_v0;
    s32 pad;
    f32 sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x226, actor->position), sp1C);
    temp_v0 = func_80108528(0x383, sp1C, 0, &actor);
    actor->unk3C = temp_v0->unk0;
    temp_v0->unk3C = actor->unk0;
    func_80100120(temp_v0);
}

void func_808018BC_chclockworkmouse(Actor* actor) {
    Unk80100094* sp24;
    Prop *prop;

    sp24 = ((Unk80100094 *)func_80100094(actor, 0));
    actor->unk64_19 = func_800D0A9C(0x4A, 1);
    sp24->unkFA = 0;
    sp24->unk4 = 0.0f;
    if ((func_800D0A9C(4, 4) == 0) || (func_800D0A9C(0x16, 4) != 0)) {
        func_80103140(actor, 0x8A1, ((u16**)actor)[0][0xB]);
        return;
    }
    switch (func_80800000_chclockworkmouse()) {
    case 0:
        if (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0) {
            func_80103140(actor, 0x8A1, ((u16**)actor)[0][0xB]);
        }
        break;
    case 1:
        if (actor->unk64_19) {
            sp24->unk0.shorts.unk0 = _glsplinefind_entrypoint_0(0x314, actor->position);
        } else {
            sp24->unk0.shorts.unk0 = _glsplinefind_entrypoint_0(0x313, actor->position);
        }
        func_801058C4(actor, (s16)sp24->unk0.shorts.unk0, CLOCKWORK_DATA(actor)->unkC, 0);
        func_8080111C_chclockworkmouse(actor);
        break;
    case 2:
        if (actor->unk64_19) {
            prop = _gccubesearch_entrypoint_0(0x201, actor);
        } else {
            prop = _gccubesearch_entrypoint_0(0x1F6, actor);
        }
        func_800EE88C(&sp24->unk114, prop->position);
        if ((actor->unk64_19) && (func_80800090_chclockworkmouse() == 2)) {
            func_80103140(actor, 0x8A1, ((u16**)actor)[0][0xB]);
        }
        break;
    }
    func_80108B04(actor, 0);
}

void func_80801A94_chclockworkmouse(Actor* actor) {
    Unk80100094* sp3C;
    s32 sp38;
    f32 sp2C[3];
    f32 sp1C[4];

    sp3C = ((Unk80100094 *)func_80100094(actor, 0));
    sp38 = func_801040D0();
    func_801015D0(actor);
    func_800DF41C(sp38);
    func_800EFA4C(sp2C, -70.0f, 0.0f, 0.0f);
    func_800D93A0(sp1C, sp2C);
    func_800DFF2C(sp38, 0x5C, sp1C);
    func_800EFA4C(sp2C, 0.0f, sp3C->unk8, 0.0f);
    func_800D93A0(sp1C, sp2C);
    func_800DFF2C(sp38, 0x5D, sp1C);
}

void func_80801B44_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2) {
    arg2 |= 4;
    _subaddiedialog_entrypoint_11(actor->unk0, arg1, arg2, actor->position, 0x36);
    actor->unk74_30 = 1;
}

void func_80801B90_chclockworkmouse(Actor *actor, s32 arg1) {
    f32 sp1C[3];

    func_800EE7F8(sp1C, actor->position);
    sp1C[1] += 75.0f;
    if ((arg1 == 0x47) || (arg1 == 0x4B)) {
        _capod_entrypoint_19(sp1C);
    }
} 

s32 func_80801BF0_chclockworkmouse(Actor* actor, s32 arg1, s32 arg2) {
    Actor* sp1C;
    s32 sp18;

    switch (arg1) {
    case 0x1F:
        func_80801A94_chclockworkmouse(actor);
        break;
    case 0xE:
        func_80801B90_chclockworkmouse(func_80106790(actor->unk3C), arg2);
        return 3;
    case 0xB:
        sp1C = func_80106790(actor->unk3C);
        sp18 = 0;
        switch (arg2) {
        case 23:
            sp18 = 0x142B;
            break;
        case 25:
            sp18 = 0x142F;
            break;
        }
        if (sp18 != 0) {
            func_8080079C_chclockworkmouse(actor, sp1C, 2, 1);
            func_80801B44_chclockworkmouse(sp1C, sp18, 0xB);
        }
        return 4;
    case 0x3D:
        func_80801850_chclockworkmouse(actor);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801CFC_chclockworkmouse(Actor* actor, s32 arg1) {
    Unk80100094* temp_s4;
    f32 sp50[3];
    ImageStruct *imageStruct;
    s32 var_s0;

    func_801018A4();
    if (actor->unk7C_12) {
        imageStruct = func_800D674C(0x9E2);
        temp_s4 = ((Unk80100094 *)func_80100094(actor, 0));
        func_800E2588(2);
        func_800E2594(arg1, imageStruct);
        for (var_s0 = 0; var_s0 < 10; var_s0++) {
            if (temp_s4->unkF0[var_s0] == 2) {
                func_800EFA4C(sp50, temp_s4->unkAC[var_s0], temp_s4->unkAC[var_s0], temp_s4->unkAC[var_s0]);
                func_800E2720(arg1, 0, 0, &temp_s4->unkC.vecs[var_s0], sp50, 0xFF);
            }
        }
        func_800E2A14(arg1);
    }
}

ActorData **chclockworkmouse_entrypoint_0(void) {
    return &D_80803E48_chclockworkmouse;
}

void func_80801E2C_chclockworkmouse(Actor* actor) {
    Unk80100094* sp2C;
    s32 pad;

    sp2C = ((Unk80100094 *)func_80100094(actor, 0));
    sp2C->unk0.f = (f32) (sp2C->unk0.f - func_800D8FF8());
    switch (func_801022E4(actor)) {
    case 0x7D:
        _subaddieaudioquick_entrypoint_3(actor, actor->position, (u32 *)&D_80803964_chclockworkmouse, 0.1f);
        if ((sp2C->unk0.f <= 0.0f) && (func_800DC298(0.03f) != 0) && (func_800C0638() == 0)) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80803950_chclockworkmouse);
            sp2C->unk0.f = 1.5f;
            return;
        }
    default:
        return;
    case 0x89:
        _subaddieaudioquick_entrypoint_4(actor, actor->position, (u32 *)&D_80803964_chclockworkmouse, (u32 *)&D_80803E90_chclockworkmouse);
        return;
    case 0x8A:
        _subaddieaudioquick_entrypoint_4(actor, actor->position, (u32 *)&D_80803964_chclockworkmouse, (u32 *)&D_80803E9C_chclockworkmouse);
        return;
    case 0x85:
        _subaddieaudioquick_entrypoint_4(actor, actor->position, (u32 *)&D_80803978_chclockworkmouse, (u32 *)&D_80803EB0_chclockworkmouse);
        return;
    case 0x80:
        _subaddieaudioquick_entrypoint_4(actor, actor->position, (u32 *)&D_80803964_chclockworkmouse, (u32 *)&D_80803EBC_chclockworkmouse);
        _subaddieaudioquick_entrypoint_3(actor, actor->position, (u32 *)&D_80803978_chclockworkmouse, 0.9f);
        break;
    }
}

void func_80801FC8_chclockworkmouse(Actor* actor) {
    s32 pad[2];
    f32 sp2C;
    Unk80100094* sp28;

    sp28 = ((Unk80100094 *)func_80100094(actor, 0));
    actor->unk64_19 = func_800D0A9C(0x4A, 1);
    switch (func_8080011C_chclockworkmouse(actor)) {
    case 0:
        break;
    case 1:
        if (actor->unk64_19) {
            sp28->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x385, &sp2C);
        } else {
            sp28->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x384, &sp2C);
        }
        func_80800024_chclockworkmouse(0);
        func_808026E0_chclockworkmouse(actor, 5);
        break;
    case 2:
        func_808026E0_chclockworkmouse(actor, 0xF);
        if (actor->unk64_19) {
            sp28->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x389, &sp2C);
        }
        func_8080019C_chclockworkmouse(actor);
        break;
    }
    if ((func_800D0A9C(4, 4) != 0) && (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0)) {
        sp28->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x388, actor->position);
        func_801058C4(actor, (s16)sp28->unkC.shorts[0], CLOCKWORK_DATA(actor)->unkC, 0);
        if (_glcutDll_entrypoint_19(0x55) != 0) {
            func_808026E0_chclockworkmouse(actor, 0x14);
        } else {
            func_808026E0_chclockworkmouse(actor, 0x13);
        }
    }
    _suexpression_entrypoint_7(actor, 1, 0x36);
    _suexpression_entrypoint_12(func_80100094(actor, 1), 45.0f, 15.0f);
}

void func_80802170_chclockworkmouse(Actor *actor) {
    if (actor->unk70_10 == 0x10) {
        func_800904C8(0x28);
    }
    if (func_80100094(actor, 1) != NULL) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_808021C4_chclockworkmouse(Actor* actor) {
    Unk80100094* temp_s1;
    f32 sp20;
    f32 f2;

    sp20 = 0.1f;
    temp_s1 = ((Unk80100094 *)func_80100094(actor, 0));
    func_80105A9C(actor, CLOCKWORK_DATA(actor)->unkC * 10.0f);
    func_80105834(actor);
    f2 = (CLOCKWORK_DATA(actor)->unkC * func_800F1DCC(actor->rotation[1], temp_s1->unk4) * 0.5f);
    temp_s1->unk8 = (f2 - temp_s1->unk8) * 0.02f;
    actor->rotation[2] = temp_s1->unk8;
    temp_s1->unk4 = actor->rotation[1];
    if (temp_s1->unkC.bytes[2] == 0) {
        sp20 = 1.0f;
        temp_s1->unkC.bytes[2] = 1;
    }
    actor->rotation[0] += func_800F1DCC(actor->unk50 * 0.1f, actor->rotation[0]) * sp20;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * sp20;
}

void func_808022E4_chclockworkmouse(Actor* actor, s32 arg1) {
    Actor* sp2C;
    Unk80100094* sp28;
    s32 sp24;
    s32 sp20;
    s32 temp_v0;
    u16 temp_a1;
    u32 temp_t1;
    u32 temp_t6;
    u8 var_a1;
    u8 var_a1_2;

    sp2C = func_80106790(actor->unk3C);
    sp28 = ((Unk80100094 *)func_80100094(actor, 0));
    switch (actor->unk70_10) {
    case 19:
        actor->unk64_16 = 1;
        break;
    case 23:
        func_808009F4_chclockworkmouse(sp2C);
        break;
    case 15:
        func_80090708(0);
        break;
    }
    func_80102424(actor, arg1);
    switch (actor->unk70_10) {
    case 19:
        actor->unk64_16 = 0;
        break;
    case 20:
        func_800DA544(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL);
        CLOCKWORK_DATA(actor)->unkC = 40.0f;
        func_80800850_chclockworkmouse(sp2C, 0x47, 0x20B0, actor->unk0);
        break;
    case 23:
        actor->unk58 = 1.0f;
        break;
    case 5:
        func_808008DC_chclockworkmouse(sp2C, 4, 5, sp2C->unk0);
        func_80801B44_chclockworkmouse(actor, 0xCEC, 3);
        func_801058C4(actor, sp28->unkC.shorts[0], CLOCKWORK_DATA(actor)->unkC, 0);
        break;
    case 6:
        func_800FDC28(0x13);
        if (actor->unk64_19) {
            CLOCKWORK_DATA(actor)->unkC = 55.0f;
        } else {
            CLOCKWORK_DATA(actor)->unkC = 35.0f;
        }
        break;
    case 7:
        func_80800024_chclockworkmouse(2);
        func_80090658(1);
        break;
    case 8:
        if (func_80105AE8(actor) < 0.93f) {
            func_80800968_chclockworkmouse(sp2C, actor->unk64_19 ? 4 : 2, 4);
        } else {
            func_808008DC_chclockworkmouse(sp2C, 5, 5, actor->unk0);
        }
        break;
    case 9:
        func_80800024_chclockworkmouse(1);
        break;
    case 10:
        if (func_80105AE8(sp2C) < 0.93f) {
            func_80800968_chclockworkmouse(sp2C, actor->unk64_19 ? 3 : 1, 4);
        } else {
            func_808008DC_chclockworkmouse(sp2C, 5, 5, sp2C->unk0);
        }
        break;
    case 14:
        actor->unk58 = 0.5f;
        break;
    case 16:
        if (func_800D0A9C(0x4A, 1) != 0) {
            sp24 = 0x142D;
        } else {
            sp24 = 0x1429;
        }
        func_8080079C_chclockworkmouse(sp2C, actor, 3, 1);
        func_80801B44_chclockworkmouse(actor, sp24, 3);
        func_800FDC28(0);
        func_800FC660(0x17);
        break;
    case 15:
        sp20 = 0;
        func_80090658(0);
        func_80090734(1, actor->position);
        func_8080079C_chclockworkmouse(sp2C, actor, 2, 1);
        temp_v0 = func_80800090_chclockworkmouse();
        switch (temp_v0) {                          /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            if (func_800D0A9C(0x4A, 1) != 0) {
                sp20 = 0x142C;
            } else {
                sp20 = 0x1428;
            }
            break;
        case 2:                                     /* switch 2 */
            if (func_800D0A9C(0x4A, 1) != 0) {
                sp20 = 0x142E;
            } else {
                sp20 = 0x142A;
            }
            break;
        }
        func_80801B44_chclockworkmouse(actor, sp20, 0xB);
        break;
    case 18:
        CLOCKWORK_DATA(actor)->unkC = 40.0f;
        func_801058C4(actor, (s16)sp28->unkC.shorts[0], 40.0f, 0);
        func_808021C4_chclockworkmouse(actor);
        func_80800850_chclockworkmouse(sp2C, 0x4B, 0x20B0, actor->unk0);
        break;
    }
    func_80800CC0_chclockworkmouse(actor);
}

void func_808026E0_chclockworkmouse(Actor *actor, s32 arg1) {
    Actor *sp1C;

    sp1C = func_80106790(actor->unk3C);
    func_808022E4_chclockworkmouse(actor, arg1);
    func_80800D14_chclockworkmouse(sp1C, arg1);
}

void func_80802724_chclockworkmouse(Actor* actor, Actor* arg1) {
    f32 sp1C;
    f32 sp18;
    f32 temp_f0;
    f32 var_f2;
    u32 temp_v0;

    if (arg1->unk7C_0) {
        sp1C = func_80105AE8(arg1);
    } else {
        sp1C = 1.0f;
    }
    sp1C = sp1C;
    sp18 = func_80105AE8(actor);
    temp_f0 = func_800D8FF8();
    temp_v0 = actor->unk64_19;
    if (sp1C <= (sp18 - 0.099990845f)) {
        func_808026E0_chclockworkmouse(actor, 0x10);
        return;
    }
    if (temp_v0 != 0) {
        var_f2 = 0.004989624f;
    } else {
        var_f2 = 0.009994507f;
    }
    if (sp1C <= (sp18 - var_f2)) {
        if (temp_v0 != 0) {
            sp18 = 185.0f;
        } else {
            sp18 = 165.0f;
        }
        if (temp_v0 != 0) {
            var_f2 = 15.0f;
        } else {
            var_f2 = 25.0f;
        }
        if ((sp18 - var_f2) < CLOCKWORK_DATA(actor)->unkC) {
            if (temp_v0 != 0) {
                var_f2 = 65.0f;
            } else {
                var_f2 = 45.0f;
            }
            CLOCKWORK_DATA(actor)->unkC -= (var_f2 * temp_f0);
        }
        return;
    }

    if (temp_v0 != 0) {
        var_f2 = 0.004989624f;
    } else {
        var_f2 = 0.019989014f;
    }
    if ((var_f2 + sp18) <= sp1C) {
        if (temp_v0 != 0) {
            sp18 = 185.0f;
        } else {
            sp18 = 165.0f;
        }
        if (CLOCKWORK_DATA(actor)->unkC < (15.0f + sp18)) {
            if (temp_v0 != 0) {
                var_f2 = 65.0f;
            } else {
                var_f2 = 45.0f;
            }
            CLOCKWORK_DATA(actor)->unkC += (var_f2 * temp_f0);
        }
    } else {
        if (temp_v0 != 0) {
            var_f2 = 185.0f;
        } else {
            var_f2 = 165.0f;
        }
        if (CLOCKWORK_DATA(actor)->unkC < var_f2) {
            if (temp_v0 != 0) {
                var_f2 = 65.0f;
            } else {
                var_f2 = 45.0f;
            }
            CLOCKWORK_DATA(actor)->unkC += (var_f2 * temp_f0);
        }
    }
}

s32 func_8080297C_chclockworkmouse(Actor* actor) {
    s32 pad;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    sp1C = func_800D8FF8();
    func_800EE7F8(sp38, actor->position);
    sp38[1] += 50.0f;
    func_800EE7F8(sp2C, actor->position);
    sp2C[1] -= 50.0f;
    if (func_800BEF00(sp38, sp2C, sp20, 0x20020) == 0 || sp2C[1] < actor->position[1]) {
        actor->position[1] -= 250.0f * sp1C;
        return 0;
    }
    return 1;
}

void func_80802A48_chclockworkmouse(Actor* actor) {
    f32 sp24;
    f32 sp20;

    actor->unk54 = func_8010CD28(actor);
    sp24 = func_800F1DCC(actor->rotation[1], actor->unk54);
    if ((sp24 < -10.0f) || (sp24 > 10.0f)) {
        sp20 = func_80101F24(actor);
        switch (func_801022E4(actor)) {
        case 0x80:
            if ((sp20 > 0.75f) && (sp20 < 0.88f)) {
                func_80102B2C(actor, 6.0f);
                return;
            }
            break;
        case 0x85:
            if (((sp20 > 0.76f) && (sp20 < 0.99f)) || ((sp20 > 0.25f) && (sp20 < 0.51f))) {
                actor->rotation[1] += sp24 > 0.0f ? -6.0f : 6.0f;
            }
            break;
        }
    }
}

void func_80802BCC_chclockworkmouse(Actor *actor) {
    _sudeflect_entrypoint_1(actor->position, 180.0f, 0.0f, 65.0f, 0x1E);
}

void func_80802C04_chclockworkmouse(Actor *actor, Actor *actor2) {
    Unk80100094 *sp1C;

    sp1C = (Unk80100094 *)func_80100094(actor2, 0);
    if (func_80105998(actor2, 0.94f) != 0) {
        sp1C->unkFE = 0;
        func_808008DC_chclockworkmouse(actor2, 5, 5, actor2->unk0);
    }
}

void func_80802C64_chclockworkmouse(Actor *actor, Actor *actor2) {
    Unk80100094 *sp1C;

    sp1C = (Unk80100094 *)func_80100094(actor2, 0);
    if (func_80105998(actor, 0.94f) != 0) {
        sp1C->unkFE = 0;
        func_808008DC_chclockworkmouse(actor2, 5, 5, actor->unk0);
    }
}

void func_80802CC8_chclockworkmouse(Actor* arg0) {
    Actor* sp34;
    Unk80100094* sp30;
    f32 sp2C;

    sp34 = func_80106790(arg0->unk3C);
    sp30 = (Unk80100094 *)func_80100094(sp34, 0);
    sp2C = func_800D8FF8();
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    switch (arg0->unk70_10) {
    case 20:
        func_808021C4_chclockworkmouse(arg0);
        if (func_80105A5C(arg0) != 0) {
            func_80105634(arg0);
            func_808026E0_chclockworkmouse(arg0, 0x15);
        }
        break;
    case 21:
        if ((func_8080297C_chclockworkmouse(arg0) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_808026E0_chclockworkmouse(arg0, 0x16);
        }
        break;
    case 22:
        if (func_80101DDC(arg0) != 0) {
            func_808026E0_chclockworkmouse(arg0, 0x17);
        }
        break;
    case 23:
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= sp2C;
        } else if (_glcutDll_entrypoint_19(0x55) != 0) {
            _glcutDll_entrypoint_17();
        } else {
            func_808026E0_chclockworkmouse(arg0, 0x11);
        }
        break;
    case 17:
        func_80802BCC_chclockworkmouse(arg0);
        func_80802A48_chclockworkmouse(arg0);
        if (func_800DA298(FLAG_42B_UNK) != 0) 
        {
            func_808026E0_chclockworkmouse(arg0, 2);
        } else if (!(arg0->unk74_30) && (func_80090178(1) != 0) && (_subaddiedialog_entrypoint_3(arg0->position, arg0->rotation[1], 0xC8, 0x46, 6) != 0)) {
            func_800DA544(FLAG_42B_UNK);
            func_8080079C_chclockworkmouse(sp34, arg0, 2, 0);
            func_80801B44_chclockworkmouse(arg0, 0x1426, 0xB);
        }
        break;
    case 2:
        func_80802BCC_chclockworkmouse(arg0);
        func_80802A48_chclockworkmouse(arg0);
        if (!arg0->unk74_30 && (func_80090178(1) != 0) && (_subaddiedialog_entrypoint_6(arg0->position, arg0->rotation[1], 0xC8, 0x46, 6) != 0)) {
            func_80801B44_chclockworkmouse(arg0, arg0->unk64_19 ? 0x1436 : 0x1427 , 0xB);
        }
        break;
    case 5:
        func_80802A48_chclockworkmouse(arg0);
        func_80802BCC_chclockworkmouse(arg0);
        func_808021C4_chclockworkmouse(arg0);
        break;
    case 6:
        func_80802724_chclockworkmouse(arg0, sp34);
        func_808021C4_chclockworkmouse(arg0);
        if (func_80105998(sp34, 0.05f) != 0) {
            sp30->unkFE = 1;
            func_80800968_chclockworkmouse(sp34, sp34->unk64_19 ? 3 : 1, 4);
        }
        func_80802C04_chclockworkmouse(arg0, sp34);
        if (func_80105A5C(arg0) != 0) {
            func_808026E0_chclockworkmouse(arg0, 9);
        }
        break;
    case 7:
        func_80802724_chclockworkmouse(arg0, sp34);
        func_808021C4_chclockworkmouse(arg0);
        func_80802C64_chclockworkmouse(arg0, sp34);
        if (func_80090248() != 0) {
            func_808026E0_chclockworkmouse(arg0, 8);
        }
        if (func_80105A5C(arg0) != 0) {
            func_808026E0_chclockworkmouse(arg0, 0xC);
        }
        break;
    case 8:
        func_80802724_chclockworkmouse(arg0, sp34);
        func_808021C4_chclockworkmouse(arg0);
        func_80802C64_chclockworkmouse(arg0, sp34);
        if (func_80105A5C(arg0) != 0) {
            func_808026E0_chclockworkmouse(arg0, 0xC);
        }
        break;
    case 9:
        func_80802C04_chclockworkmouse(arg0, sp34);
        if (func_80105A5C(sp34) != 0) {
            func_80800C64_chclockworkmouse(sp34);
        }
        if ((func_8080297C_chclockworkmouse(arg0) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_808026E0_chclockworkmouse(arg0, 0xA);
        }
        break;
    case 10:
        func_80802C04_chclockworkmouse(arg0, sp34);
        func_80802BCC_chclockworkmouse(arg0);
        if (func_80105A5C(sp34) != 0) {
            func_80800C64_chclockworkmouse(sp34);
        }
        if (func_80101DDC(arg0) != 0) {
            func_808026E0_chclockworkmouse(arg0, 0xB);
        }
        break;
    case 11:
        func_80802C04_chclockworkmouse(arg0, sp34);
        func_80802BCC_chclockworkmouse(arg0);
        func_80802A48_chclockworkmouse(arg0);
        if (func_80105A5C(sp34) != 0) {
            func_80800C64_chclockworkmouse(sp34);
            func_808026E0_chclockworkmouse(arg0, 0xE);
        }
        break;
    case 12:
        if ((func_8080297C_chclockworkmouse(arg0) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_808026E0_chclockworkmouse(arg0, 0xD);
        }
        break;
    case 13:
        func_80802BCC_chclockworkmouse(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_808026E0_chclockworkmouse(arg0, 0xE);
        }
        break;
    case 14:
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= sp2C;
        } else {
            func_8080019C_chclockworkmouse(arg0);
        }
        break;
    case 15:
        func_80802A48_chclockworkmouse(arg0);
        func_80802BCC_chclockworkmouse(arg0);
        break;
    case 18:
        if (CLOCKWORK_DATA(arg0)->unkC < 150.0f) {
            CLOCKWORK_DATA(arg0)->unkC += 50.0f * sp2C;
        }
        func_808021C4_chclockworkmouse(arg0);
        if (func_80105A5C(arg0) != 0) {
            func_80105634(arg0);
            func_808009F4_chclockworkmouse(sp34);
            sp34->unk3C = 0;
            func_800FFAB0(arg0);
        }
        break;
    }
    func_80801E2C_chclockworkmouse(arg0);
    switch (sp30->unkFB) {
        case 2:
        case 4:
            func_80800A44_chclockworkmouse(sp34);
            func_808004B0_chclockworkmouse(sp34);
            break;
    }
}

s32 func_808032F8_chclockworkmouse(Actor* actor, s32 arg1, s32 arg2) {
    s16 *new_var;
    s32 pad;
    Actor* sp28;
    Actor* temp_a2;
    Unk80100094* temp_t0;

    new_var = (s16 *) &arg2;
    switch (arg1) {
    case 14:
        func_80801B90_chclockworkmouse(actor, arg2);
        return 3;
    case 47:
        temp_t0 = (Unk80100094 *)func_80100094(func_80106790(actor->unk3C), 0);
        switch (*new_var) {
        case 0x142A:
            func_800D1000(0x4A, 1, &temp_t0->unk114, 1, actor->unk0);
            break;
        case 0x142E:
            func_800D1000(0x16, 4, &temp_t0->unk114, 1, actor->unk0);
            break;
        }
        break;
    case 13:
        sp28 = func_80106790(actor->unk3C);
        switch (*((s32 *)new_var) & 0xFFFF) {
        case 1:
            func_80800850_chclockworkmouse(sp28, 0x17, 0x2000, func_80101080());
            break;
        case 4:
            func_80800850_chclockworkmouse(sp28, 0x19, 0x2000, func_80101080());
            break;
        }
        break;
    case 46:
        temp_a2 = func_80106790(actor->unk3C);
        switch (*new_var) {
        case 0x1426:
            func_808009F4_chclockworkmouse(temp_a2);
            func_808026E0_chclockworkmouse(actor, 2);
            break;
        case 0xCEC:
            func_808026E0_chclockworkmouse(actor, 6);
            break;
        case 0x1429:
        case 0x142D:
            func_80800158_chclockworkmouse(actor, 0);
            func_808000B4_chclockworkmouse(actor);
            func_800904C8(0x28);
            break;
        case 0x1428:
            func_808009F4_chclockworkmouse(temp_a2);
            func_808026E0_chclockworkmouse(actor, 2);
            break;
        case 0x142C:
            func_808009F4_chclockworkmouse(temp_a2);
            func_808026E0_chclockworkmouse(actor, 2);
            break;
        case 0x142B:
            func_808009F4_chclockworkmouse(temp_a2);
            func_808026E0_chclockworkmouse(actor, 2);
            actor->unk64_19 = 1;
            temp_a2->unk64_19 = 1;
            break;
        case 0x142F:
            func_808009F4_chclockworkmouse(temp_a2);
            func_808026E0_chclockworkmouse(actor, 0x12);
            break;
        }
        actor->unk74_30 = 0;
        break;
        case 0x52:
        
        if (func_801022E4(actor) == 0x7D) {
            _gcdialogcamera_entrypoint_3((u32 *)&D_80803ED0_chclockworkmouse, actor->scale);
        } else {
            _gcdialogcamera_entrypoint_3((u32 *)&D_80803EE0_chclockworkmouse, actor->scale);
        }
        return 1;
    case 11:
        if ((arg2 == 0x1F) && (actor->unk70_10 == 0x13)) {
            _capod_entrypoint_14();
            func_808026E0_chclockworkmouse(actor, 0x14);
            return 4;
        }
        return 3;
    case 31:
        func_801015D0(actor);
        func_800DF744(3, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080364C_chclockworkmouse(void) {
    func_801018A4();
}

ActorData **chclockworkmouse_entrypoint_1(void) {
    return &D_80803EF0_chclockworkmouse;
}
