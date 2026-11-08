#include "core2/1EA1DA0.h"

extern Vector* D_8012AB00;
extern u32 D_8011A9EC[3];
extern f32 D_8011A9F8[2];
extern u32 D_8011AA00[3];
extern s32 D_8012AB04[3];
extern s32 D_8012AB1C[3];
extern f32 D_8012AB28[3];
extern s32 D_8012AB10[3];
extern u32 D_8011A9CC[3];
extern f32 D_8011A9D8[2];
extern u32 D_8011A9E0[3];


extern f32 D_8012AB64;
extern s32 D_8011A930;
extern s32 D_8011A934;

extern s32 (*D_8011A9C0[])(unkStruct800C85A0*, s32);
extern unkStruct8012AB40 D_8012AB40;
extern unkStruct800C84B0 D_8011A938[];
extern unkStruct800C84B0 D_8011A9B8;
extern unkStruct8012AB60 D_8012AB60;

s32 func_800C84B0(s32 arg0) {
    unkStruct800C84B0* var_a0;
    s32 temp_v0;

    temp_v0 = arg0 & 0x1F00;
    if (arg0 & 0x20000) {
        return 4;
    }
    if (temp_v0 == 0) {
        return 0;
    }
    if (temp_v0 == D_8011A930) {
        return D_8011A934;
    }
    var_a0 = D_8011A938;
    while (1) {
        if (temp_v0 == var_a0->unk0) {
            return var_a0->unk4;
        }
        if (temp_v0 == var_a0->unk8) {
            return var_a0->unkC;
        }
        if (temp_v0 == var_a0->unk10) {
            return var_a0->unk14;
        }
        if (temp_v0 == var_a0->unk18) {
            return temp_v0 = var_a0->unk1C;
        }
        var_a0++;
        if (var_a0 == &D_8011A9B8) {
            return 1;
        }
    }
}

s32 func_800C8560(unkStruct800C85A0* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg0->unk16 != 0;
    if (var_v0 != 0) {
        return (arg0->unk15 & arg1) != 0;
    }
}

u8 func_800C8588(unkStruct800C85A0* arg0, s32 arg1) {
    return arg0->unk14;
}

s32 func_800C8594(unkStruct800C85A0* arg0, s32 arg1) {
    return arg0->unk15 & arg1;
}

s32 func_800C85A0(s32 (*arg0)(unkStruct800C85A0*, s32), s32 arg1) {
    unkStruct800C85A0* sp2C;
    unkStruct800C85A0* temp_v0;
    unkStruct800C85A0* var_s0;

    sp2C = vector_begin(D_8012AB00);
    temp_v0 = vector_end(D_8012AB00);
    for (var_s0 = sp2C; var_s0 < temp_v0; var_s0++) {
        if ((var_s0->unk15 != 0) && (arg0(var_s0, arg1) != 0) && ((var_s0->unk17 != 0) || (var_s0->unk18 != 0))) {
            return (var_s0 - sp2C) + 1;
        }
    }
    return 0;
}

s32 func_800C8678(s32 arg0, s32 (*arg1)(unkStruct800C85A0*, s32), s32 arg2) {
    unkStruct800C85A0* sp2C;
    unkStruct800C85A0* temp_v0;
    unkStruct800C85A0* var_s0;

    sp2C = vector_begin(D_8012AB00);
    var_s0 = vector_at(D_8012AB00, arg0 - 1);
    temp_v0 = vector_end(D_8012AB00);
    var_s0++;
    for (; var_s0 < temp_v0; var_s0++) {
        if ((var_s0->unk15 != 0) && (arg1(var_s0, arg2) != 0) && ((var_s0->unk17 != 0) || (var_s0->unk18 != 0))) {
            return (var_s0 - sp2C) + 1;
        }
    }
    return 0;
}

void func_800C8760(s32 arg0, s32 arg1) {
    func_800C85A0(D_8011A9C0[arg0], arg1);
}


void func_800C878C(s32 arg0, s32 arg1, s32 arg2) {
    func_800C8678(arg0, D_8011A9C0[arg1], arg2);
}

void func_800C87B8(s32* arg0) {
    ml_vec3i_copy(arg0, D_8012AB04);
}

void func_800C87DC(s32* arg0) {
    ml_vec3i_copy(arg0, &D_8012AB10);
}


void func_800C8800(s32 arg0, f32* arg1) {
    ml_vec3s_to_vec3f(arg1, vector_at(D_8012AB00, arg0 - 1));
}

void func_800C883C(s32 arg0, f32* arg1) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);

    arg1[0] = temp_v0->unk6;
    arg1[1] = temp_v0->unk8;
}

void func_800C8898(s32 arg0, f32* arg1) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);

    arg1[0] = temp_v0->unk6;
    arg1[1] = temp_v0->unk8;
    arg1[2] = temp_v0->unk10;
}

void func_800C8900(s32 arg0, s32* arg1) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);

    if (temp_v0->unk17 == 0) {
        ml_vec3i_assign_value(arg1, 0, 0, 0);
        return;
    }
    func_800F2EE0(arg1, &temp_v0->unkA);
}

void func_800C8960(s32* arg0, f32* arg1) {
    if (arg0 != NULL) {
        ml_vec3i_copy(arg0, D_8012AB1C);
    }
    if (arg1 != NULL) {
        ml_vec3f_copy(arg1, D_8012AB28);
    }
}

u8 func_800C89A8(s32 arg0) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    return temp_v0->unk15;
}

u8 func_800C89D8(s32 arg0) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    return temp_v0->unk19;
}

void func_800C8A08(void) {
    unkStruct800C85A0* sp1C;
    unkStruct800C85A0* temp_v0;
    unkStruct800C85A0* var_v1;

    sp1C = vector_begin(D_8012AB00);
    temp_v0 = vector_end(D_8012AB00);
    for (var_v1 = sp1C; var_v1 < temp_v0; var_v1++) {
        if (var_v1->unk15 != 0) {
            if (var_v1->unk16 == 2) {
                var_v1->unk15 = 0;
            } else {
                var_v1->unk16 = 0;
            }
            if (var_v1->unk18 != 0) {
                var_v1->unk18 = 0;
            }
            var_v1->unk19 = 0;
        }
    }
}

s32 func_800C8A98(void) {
    unkStruct800C85A0* sp24;
    unkStruct800C85A0* temp_v0;
    unkStruct800C85A0* var_a2;
    s32 sp18;

    sp24 = vector_begin(D_8012AB00);
    temp_v0 = vector_end(D_8012AB00);
    for (var_a2 = sp24; var_a2 < temp_v0; var_a2++) {
        if (var_a2->unk15 == 0) {
            break;
        }
    }
    if (var_a2 == temp_v0) {
        var_a2 = vector_push_back(&D_8012AB00);
    }
    sp18 = vector_index_of(D_8012AB00, var_a2) + 1;
    var_a2->unk15 = 0xB;
    var_a2->unk16 = var_a2->unk17 = 1;
    var_a2->unk14 = 0;
    var_a2->unk18 = 0;
    var_a2->unk19 = 0;
    func_800C8CB8(sp18, D_8011A9CC);
    func_800C8D4C(sp18, D_8011A9D8);
    func_800C8E84(sp18, D_8011A9E0);
    return sp18;
}

void func_800C8B84(s32 arg0) {
    unkStruct800C85A0* sp1C = vector_at(D_8012AB00, arg0 - 1);

    func_800C8CB8(arg0, D_8011A9EC);
    func_800C8D4C(arg0, D_8011A9F8);
    func_800C8E84(arg0, D_8011AA00);
    sp1C->unk16 = 2;
}

void func_800C8BF4(void) {
    vector_size(D_8012AB00);
}

s32 func_800C8C18(void) {
    unkStruct800C85A0* sp24;
    s32 sp20;
    s32 sp1C;
    unkStruct800C85A0* var_v1;

    sp24 = vector_end(D_8012AB00);
    sp1C = 0;
    for (var_v1 = vector_begin(D_8012AB00); var_v1 < sp24; var_v1++) {
        if ((var_v1->unk15 != 0) && (var_v1->unk14 != 0)) {
            sp1C++;
        }
    }
    return sp1C;
}

void func_800C8C90(s32* arg0) {
    ml_vec3i_copy(D_8012AB04, arg0);
}


void func_800C8CB8(s32 arg0, f32* arg1) {
    unkStruct800C85A0* sp24;
    s16 sp1C[3];

    sp24 = vector_at(D_8012AB00, arg0 - 1);
    ml_vec3f_to_vec3s(sp1C, arg1);
    if ((sp24->unk0 != sp1C[0]) || (sp24->unk2 != sp1C[1]) || (sp24->unk4 != sp1C[2])) {
        ml_vec3s_copy(&sp24->unk0, sp1C);
        sp24->unk16 = sp24->unk19 = 1;
    }
}


void func_800C8D4C(s32 arg0, f32* arg1) {
    s32 pad;
    s16 sp18[2];
    unkStruct800C85A0* temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    sp18[0] = arg1[0];
    sp18[1] = arg1[1];
    if (sp18[1] < sp18[0]) {
        sp18[1] = sp18[0];
    }
    if (sp18[1] < sp18[0]) {
        sp18[0] = sp18[1];
    }
    if (sp18[0] == sp18[1]) {
        sp18[1] += 1;
    }
    if ((temp_v0->unk6 != sp18[0]) || (temp_v0->unk8 != sp18[1])) {
        temp_v0->unk6 = sp18[0];
        temp_v0->unk8 = sp18[1];
        temp_v0->unk10 = 1.0f / (f32)(sp18[1] - sp18[0]);
        temp_v0->unk16 = temp_v0->unk19 = 1;
    }
}

void func_800C8E54(s32 arg0, f32 arg1, f32 arg2) {
    f32 sp18[2];

    sp18[0] = arg1;
    sp18[1] = arg2;
    func_800C8D4C(arg0, sp18);
}

void func_800C8E84(s32 arg0, u32* arg1) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);

    if ((temp_v0->unkA != arg1[0]) || (temp_v0->unkB != arg1[1]) || (temp_v0->unkC != arg1[2])) {
        temp_v0->unkA = arg1[0];
        temp_v0->unkB = arg1[1];
        temp_v0->unkC = arg1[2];
        temp_v0->unk16 = 1;
    }
}

void func_800C8F08(s32* arg0, f32* arg1) {
    if (arg0 != NULL) {
        ml_vec3i_copy(D_8012AB1C, arg0);
    }
    if (arg1 != NULL) {
        ml_vec3f_copy(D_8012AB28, arg1);
        ml_vec3f_normalizeMagnitude(D_8012AB28);
    }
}

void func_800C8F64(s32 arg0, s32 arg1) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);

    if (arg1 != temp_v0->unk15) {
        temp_v0->unk15 = arg1;
        temp_v0->unk16 = 1;
    }
}

void func_800C8FB0(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 sp1C[3];

    sp1C[0] = arg1;
    sp1C[1] = arg2;
    sp1C[2] = arg3;
    func_800C8E84(arg0, sp1C);
}

void func_800C8FE0(s32 arg0, s32 arg1) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);

    if (temp_v0->unk16 == 0) {
        temp_v0->unk16 = arg1 != temp_v0->unk17;
    }
    temp_v0->unk17 = arg1;
    if (arg1 == 0) {
        temp_v0->unk18 = 1;
    }
}

s32 func_800C9044(s32 arg0) {
    unkStruct800C85A0* temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    return temp_v0->unk17;
}

void func_800C9074(void) {
    if (D_8012AB00 != 0) {
        D_8012AB00 = vector_defrag(D_8012AB00);
    }
}

void func_800C90AC()
{
    _gclightsDll_entrypoint_0(&D_8012AB00);
}

void func_800C90D0()
{
    _gclightsDll_entrypoint_1(&D_8012AB00);
}

void func_800C90F4(s32 arg0) {
    _gclightsDll_entrypoint_2(&D_8012AB00, arg0);
}

Vector** func_800C911C(void) {
    return &D_8012AB00;
}

void func_800C9128(s32 arg0) {
    _gclightsDll_entrypoint_3(&D_8012AB00, arg0);
}

unkStruct800C9150* func_800C9150(s32 arg0) {
    unkStruct800C9150* var_a2;

    var_a2 = func_800C91C8(arg0);
    if (var_a2 == NULL) {
        var_a2 = heap_alloc(0x34);
        bzero(var_a2, 0x34);
        D_8012AB40.unk0[D_8012AB40.unk14] = var_a2;
        D_8012AB40.unk14++;
        _gctransitionDll_entrypoint_8(var_a2, arg0);
    }
    return var_a2;
}

unkStruct800C9150* func_800C91C8(s32 arg0) {
    s32 i;
    for (i = 0; i < D_8012AB54; i++) {
        if (arg0 == D_8012AB40.unk0[i]->unk0) {
            return D_8012AB40.unk0[i];
        }
    }
    return NULL;
}

void func_800C9214(unkStruct800C9150* arg0) {
    s32 i;

    for (i = 0; i < D_8012AB40.unk14; i++) {
        if (D_8012AB40.unk0[i] == arg0) {
            heap_free(D_8012AB40.unk0[i]);
            D_8012AB40.unk0[i] = D_8012AB40.unk0[--D_8012AB40.unk14];
            return;
        }
    }
}

void func_800C929C()
{
	D_8012AB54 = 0;
}

void func_800C92A8(void) {
    s32 i;

    for (i = 0; i < D_8012AB40.unk14; i++) {
        _gctransitionDll_entrypoint_9(D_8012AB40.unk0[i]);
    }
}

void func_800C9310(void) {
    if (D_8012AB40.unk14 != 0) {
        do {
            _gctransitionDll_entrypoint_5(D_8012AB40.unk0[0]);
        } while (D_8012AB40.unk14 != 0);
    }
}

void func_800C9358(s32 arg0, s32 arg1) {
    s32 temp_a1;
    unkStruct800C9150** var_s0;
    s32 var_s1;

    if (D_8012AB54) {
        var_s1 = 0;
        if (D_8012AB54 > 0) {
            var_s0 = D_8012AB40.unk0;
            do {
                temp_a1 = (*var_s0)->unk0;
                if (temp_a1 != 4) {
                    func_800A8BD4(arg0, temp_a1, arg1);
                    _gctransitionDll_entrypoint_0(*var_s0, arg0);
                }
                var_s1++;
                var_s0++;
            } while (var_s1 < D_8012AB54);
        }
        func_800A8CCC(arg0, arg1);
    }
}

void func_800C940C(s32 arg0, s32 arg1) {
    unkStruct800C9150** var_a0;
    unkStruct800C9150* temp_a2;
    s32 var_v1;
    s32 new_var;

    if (D_8012AB54) {
        var_v1 = 0;
        if (D_8012AB54 > 0) {
            var_a0 = D_8012AB40.unk0;
            do {
                temp_a2 = *var_a0;
                var_v1++;
                if ((new_var = temp_a2->unk0) == 4) {
                    _gctransitionDll_entrypoint_0(temp_a2, arg0);
                    return;
                }
                var_a0++;
            } while (var_v1 < D_8012AB54);
        }
    }
}

void func_800C9484(void) {
    s32 i;

    for (i = 0; i < D_8012AB54; i++) {
        if (D_8012AB40.unk0[i] != NULL) {
            if (D_8012AB40.unk0[i]->unk2C != NULL) {
                D_8012AB40.unk0[i]->unk2C = func_8008AEB4(D_8012AB40.unk0[i]->unk2C);
            }
            D_8012AB40.unk0[i] = defrag(D_8012AB40.unk0[i]);
        }
    }
}

s32 func_800C9510(void) {
    unkStruct800C9150* temp_v0 = func_800C91C8(4);

    if (temp_v0 != NULL) {
        return _gctransitionDll_entrypoint_4(temp_v0);
    }
    return 0;
}

s32 func_800C954C(void) {
    unkStruct800C9150* temp_v0 = func_800C91C8(4);

    if (temp_v0 != NULL) {
        return _gctransitionDll_entrypoint_3(temp_v0);
    }
    return 0;
}

f32 func_800C9588(void) {
    return 300.0f;
}

void func_800C9598(void) {
    unkStruct800C9150* var_a0 = func_800C91C8(4);

    if (var_a0 == NULL) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_1(var_a0);
}

s32 func_800C95D4(void) {
    unkStruct800C9150* temp_v0 = func_800C91C8(4);

    if (temp_v0 != NULL) {
        return _gctransitionDll_entrypoint_2(temp_v0);
    }
    return 1;
}

void func_800C9610(void) {
    unkStruct800C9150* var_a0 = func_800C91C8(4);

    if (var_a0 == NULL) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_6(var_a0);
}

s32 func_800C964C(s32 arg0) {
    unkStruct800C9150* var_a0 = func_800C91C8(4);

    if (var_a0 == NULL) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_7(var_a0, arg0);
}


void func_800C968C(s32 arg0, s32 arg1) {
    unkStruct800C9150* var_a0 = func_800C91C8(arg0);

    if (var_a0 == NULL) {
        var_a0 = func_800C9150(arg0);
    }
    _gctransitionDll_entrypoint_7(var_a0, arg1);
}


s32 func_800C96CC(s32 arg0) {
    unkStruct800C9150* temp_v0 = func_800C91C8(arg0);

    if (temp_v0 != NULL) {
        return (temp_v0->unk1C == temp_v0->unkA) ? 1 : 0;
    }
    return 0;
}

s32 func_800C9714(s32 arg0) {
    unkStruct800C9150* temp_v0 = func_800C91C8(arg0);

    if (temp_v0 != NULL) {
        return _gctransitionDll_entrypoint_3(temp_v0);
    }
    return 1;
}

unkStruct800C9750* func_800C9750(f32 arg0, s32 arg1, u32* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    unkStruct800C9750* sp24;
    Vector* var_a0;
    unkStruct800C9750* temp_v0_2;
    unkStruct800C9750* var_v1;
    unkStruct800C9750* temp_v0_3;

    var_a0 = D_8012AB60.unk0;
    if (var_a0 == NULL) {
        D_8012AB60.unk0 = vector_new(0x70, 8);
        var_a0 = D_8012AB60.unk0;
    }
    sp24 = vector_begin(var_a0);
    temp_v0_2 = vector_end(D_8012AB60.unk0);
    if (temp_v0_2 == sp24) {
        D_8012AB60.unk4 = 0.0f;
    } else {
        arg0 += D_8012AB60.unk4;
    }
    for (var_v1 = sp24; var_v1 < temp_v0_2; var_v1++) {
        if (arg0 < var_v1->unk0) {
            break;
        }
    }
    temp_v0_3 = vector_insert(&D_8012AB60.unk0, var_v1 - sp24);
    temp_v0_3->unk0 = arg0;
    temp_v0_3->unk4 = arg1;
    temp_v0_3->unk8 = arg2;
    temp_v0_3->unkC = arg3;
    temp_v0_3->unk10 = arg4;
    temp_v0_3->unk14 = arg5;
    temp_v0_3->unk18 = arg6;
    temp_v0_3->unk1C = arg7;
    return temp_v0_3;
}

void func_800C986C(unkStruct800C9750* arg0) {
    switch (arg0->unk4) {
    case 0:
        ((void (*)()) arg0->unk8)();
        break;
    case 1:
        ((void (*)()) arg0->unk8)(arg0->unkC);
        break;
    case 2:
        ((void (*)()) arg0->unk8)(arg0->unkC, arg0->unk10);
        break;
    case 3:
        ((void (*)()) arg0->unk8)(arg0->unkC, arg0->unk10, arg0->unk14);
        break;
    case 4:
        ((void (*)()) arg0->unk8)(arg0->unkC, arg0->unk10, arg0->unk14, arg0->unk18);
        break;
    case 5:
        ((void (*)()) arg0->unk8)(arg0->unkC, arg0->unk10, arg0->unk14, arg0->unk18, arg0->unk1C);
        break;
    case 6:
        ((void (*)()) arg0->unk8)(&arg0->unk20);
        break;
    }
}

void func_800C9974(u32 arg0, u32 arg1)
{
    func_800FC63C(arg0, arg1);
}

void func_800C9994(u32 arg0, u32 arg1, u32 arg2)
{
    func_800FCAE0(arg0, arg1, arg2);
}



void func_800C99B4(s32 arg0, s32 arg1, s32 arg2) {
    func_800C3FF0(arg0, arg1 / 1000.0f, arg2);
}

void func_800C99F0(unkStruct800C99F0* arg0) {
    func_800C4244(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC, arg0->unk18, arg0->unk1C);
}

void func_800C9A38(unkStruct800C9A38* arg0) {
    f32* sp28;

    sp28 = arg0->unkC;
    if (ml_vec3f_is_zero(sp28) != 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, arg0->unk4, arg0->unk8, NULL, arg0->unk18);
        return;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg0->unk4, arg0->unk8, sp28, arg0->unk18);
}

void func_800C9AB0(s32 arg0) {
    switch (arg0) {
    case 1:
        func_80090708(1);
        break;
    case 2:
        func_80090708(3);
        break;
    case 3:
        func_80090708(2);
        break;
    case 0:
        func_80090708(0);
        break;
    case 5:
        func_800A51C0();
        break;
    }
}

void func_800C9B30(Unk80132ED0* arg0, s32 arg1, s32 arg2)
{
    Unk80132ED0* sp1C = arg0;
    s32* p2 = &arg2;
    s32* p1 = &arg1;
    s32* p0 = (s32*)&arg0;

    if (sp1C->unk12_1) {
    }
    if ((func_801069A4(sp1C) != 0) && (arg1 == ((u32)sp1C->unk12_1)))
    {
        func_8010114C(sp1C, 0x22, arg2);
    }
}

void func_800C9B84(void) {
    if (D_8012AB60.unk0 != NULL) {
        vector_clear(D_8012AB60.unk0);
    }
}

void func_800C9BB4(f32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    func_800C9E64(arg0, (u32*)func_800C99B4, arg1, arg2 * 1000.0f, arg3);
}

void func_800C9C04(f32 arg0, u32 arg1, u32 arg2) {
    func_800C9E20(arg0, (u32* ) func_800C9974, arg1, arg2);
}

void func_800C9C34(f32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800C9E64(arg0, (u32*)func_800C9994, arg1, arg2, arg3);
}


void func_800C9C70(f32 arg0, u32 arg1, f32 arg2, u32 arg3, f32* arg4, f32 arg5, f32 arg6) {
    unkStruct800C9C70 sp18;

    sp18.unk0 = arg1;
    sp18.unk8 = arg3;
    sp18.unk4 = arg2;
    sp18.unk18 = arg5;
    sp18.unk1C = arg6;
    ml_vec3f_copy(sp18.unkC, arg4);
    func_800C9EF8(arg0, (u32*)func_800C99F0, &sp18);
}

void func_800C9CD0(f32 arg0, Unk80132ED0* arg1, u32 arg2, u32 arg3, f32* arg4, s16 arg5) {
    unkStruct800C9A38 sp1C;

    sp1C.unk0 = arg1;
    sp1C.unk4 = arg2;
    sp1C.unk8 = arg3;
    sp1C.unk18 = arg5;
    if (arg4 != NULL) {
        ml_vec3f_copy(sp1C.unkC, arg4);
    } else {
        ml_vec3f_clear(sp1C.unkC);
    }
    func_800C9EF8(arg0, (u32*)func_800C9A38, &sp1C);
}

void func_800C9D38(f32 arg0, s32 arg1) {
    func_800C9DE4(arg0, (u32*)func_800C9AB0, arg1);
}

void func_800C9D60(f32 arg0, s32 arg1) {
    func_800C9DE4(arg0, (u32*)func_800A54F8, arg1);
}

void func_800C9D88(f32 arg0) {
    func_800C9DAC(arg0, (u32*)func_800A5524);
}

void func_800C9DAC(f32 arg0, u32* arg1) {
    func_800C9750(arg0, 0, arg1, 0, 0, 0, 0, 0);
}

void func_800C9DE4(f32 arg0, u32* arg1, s32 arg2) {
    func_800C9750(arg0, 1, arg1, arg2, 0, 0, 0, 0);
}

void func_800C9E20(f32 arg0, u32* arg1, u32 arg2, u32 arg3) {
    func_800C9750(arg0, 2, arg1, arg2, arg3, 0, 0, 0);
}

void func_800C9E64(f32 arg0, u32* arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_800C9750(arg0, 3, arg1, arg2, arg3, arg4, 0, 0);
}


void func_800C9EAC(f32 arg0, u32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_800C9750(arg0, 4, arg1, arg2, arg3, arg4, arg5, 0);
}


void func_800C9EF8(f32 arg0, u32* arg1, void* arg2) {
    rare_memcpy(func_800C9750(arg0, 6, arg1, 0, 0, 0, 0, 0)->unk20, arg2, 0x50);
}

void func_800C9F48(f32 arg0, unkStruct800C9B30* arg1, s32 arg2) {
    unkStruct800C9B30** new_var;

    new_var = &arg1;
    func_800C9750(arg0, 3, (u32*)func_800C9B30, *new_var, (u32)(*new_var)->unk12 >> 1, arg2, 0, 0);
}

s32 func_800C9F94(void) {
    s32 var_v0;

    var_v0 = D_8012AB60.unk0 == NULL;
    if (var_v0 == 0) {
        var_v0 = vector_size(D_8012AB60.unk0) == 0;
        return var_v0;
    }
}

void func_800C9FD0(void) {
    unkStruct800C9750* temp_v0;
    unkStruct800C9750 sp24;

    if (D_8012AB60.unk0 != NULL) {
        if (vector_size(D_8012AB60.unk0) > 0) {
            do {
                temp_v0 = vector_begin(D_8012AB60.unk0);
                rare_memcpy(&sp24, temp_v0, 0x70);
                vector_erase(D_8012AB60.unk0, 0);
                func_800C986C(&sp24);
            } while (vector_size(D_8012AB60.unk0) > 0);
        }
        vector_free(D_8012AB60.unk0);
        D_8012AB60.unk0 = NULL;
    }
}

void func_800CA060(void) {
    if (D_8012AB60.unk0 != NULL) {
        vector_free(D_8012AB60.unk0);
        D_8012AB60.unk0 = NULL;
    }
}

void func_800CA098(void) {
    D_8012AB64 = 0.0f;
}

void func_800CA0A8(void) {
    f32* temp_v0;
    unkStruct800C9750 sp24;

    if (func_800C9F94() == 0) {
        D_8012AB60.unk4 += time_getDelta();
        if (vector_size(D_8012AB60.unk0) > 0) {
            do {
                temp_v0 = vector_begin(D_8012AB60.unk0);
                if (D_8012AB60.unk4 < *temp_v0) {
                    break;
                }
                rare_memcpy(&sp24, temp_v0, 0x70);
                vector_erase(D_8012AB60.unk0, 0);
                func_800C986C(&sp24);
            } while (vector_size(D_8012AB60.unk0) > 0);
        }
        if (vector_size(D_8012AB60.unk0) == 0) {
            vector_free(D_8012AB60.unk0);
            D_8012AB60.unk0 = NULL;
        }
    }
}

void func_800CA174(void) {
    if (D_8012AB60.unk0 != NULL) {
        D_8012AB60.unk0 = vector_defrag(D_8012AB60.unk0);
    }
}

