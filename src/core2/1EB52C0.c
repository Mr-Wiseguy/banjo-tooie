#include "core2/1EB52C0.h"

FreeList* D_8012C7E0;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
} unkfunc_800DB9FC_inner;

typedef struct {
    unkfunc_800DB9FC_inner unk0[7];
    f32 unk38[7];
} unkfunc_800DB9FC;

unkfunc_800DB9FC* func_800DB9D0(u8 index) {
    return (unkfunc_800DB9FC*)freelist_at(D_8012C7E0, index);
}

s32 func_800DB9FC(u8 arg0, s32 arg1, s32* arg2) {
    unkfunc_800DB9FC* temp_v0;

    temp_v0 = func_800DB9D0(arg0);
    if (temp_v0->unk0[arg1].unk0 != 0) {
        *arg2 = (s32)temp_v0->unk38[arg1] * temp_v0->unk0[arg1].unk0;
        return 1;
    }
    return 0;
}

u8 func_800DBA84(void) {
    unkfunc_800DB9FC* var_v0;
    s32 ret;
    s32 i;
    if (D_8012C7E0 == NULL) {
        D_8012C7E0 = freelist_new(sizeof(unkfunc_800DB9FC), 2);
    }
    var_v0 = freelist_next(&D_8012C7E0, &ret);

    for (i = 0; i < ARRLEN(var_v0->unk0); i++) {
        var_v0->unk0[i].unk0 = 0;
        var_v0->unk38[i] = 0.0f;
    }

    return ret;
}

void func_800DBB24(void) {
    if (D_8012C7E0 != NULL) {
        freelist_free(D_8012C7E0);
        D_8012C7E0 = NULL;
    }
}

void func_800DBB5C(void) {
}

void func_800DBB64(void) {
    if (D_8012C7E0 != NULL) {
        D_8012C7E0 = freelist_defrag(D_8012C7E0);
    }
}

void func_800DBB9C(u8 arg0) {
    s32 used_count;
    if (D_8012C7E0 != NULL) {
        freelist_erase(D_8012C7E0, arg0);
        used_count = freelist_used_count(D_8012C7E0);
        if (used_count == 0) {
            freelist_free(D_8012C7E0);
            D_8012C7E0 = NULL;
        }
    }
}

void func_800DBBF8(u8 arg0, unkfunc_800DB9FC* arg1) {
    unkfunc_800DB9FC* var_v0 = func_800DB9D0(arg0);
    s32 i;
    rare_memcpy(var_v0, arg1, sizeof(var_v0->unk0));
    for (i = 0; i < ARRLEN(var_v0->unk0); i++) {
        var_v0->unk38[i] = 0.0f;
    }
}

void func_800DBC68(void) {
    s32 var_a1;
    s32 var_s1;
    f32 temp_f20;
    unkfunc_800DB9FC* temp_v0;

    if (D_8012C7E0 != NULL) {
        temp_f20 = func_800D8FF8();
        for (var_s1 = 1; var_s1 < freelist_capacity(D_8012C7E0); var_s1++) {
            if (freelist_is_element_alive(D_8012C7E0, var_s1) != 0) {
                temp_v0 = freelist_at(D_8012C7E0, var_s1);
                for (var_a1 = 0; var_a1 < ARRLEN(temp_v0->unk0); var_a1++) {
                    if (temp_v0->unk0[var_a1].unk0) {
                        temp_v0->unk38[var_a1] += temp_v0->unk0[var_a1].unk4 * temp_f20;
                        if ((s32)temp_v0->unk38[var_a1] >= temp_v0->unk0[var_a1].unk2) {
                            temp_v0->unk38[var_a1] -= temp_v0->unk0[var_a1].unk2;
                        }
                    }
                }
            }
        }
    }
}

s32 func_800DBE28(u8 arg0, s32 arg1) {
    unkfunc_800DB9FC* var_v0 = func_800DB9D0(arg0);
    return var_v0->unk0[arg1].unk2;
}

void func_800DBE60(u8 arg0, s32 arg1, s32 arg2) {
    unkfunc_800DB9FC* var_v0 = func_800DB9D0(arg0);
    var_v0->unk38[arg1] = arg2;
}
