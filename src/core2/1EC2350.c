#include "core2/1EC2350.h"

extern FreeList* D_8012D680;
extern s32 D_80123500;
extern u16 D_80132560[];
extern u32 D_80123524;
extern unkStructD_8012D690 D_8012D690;
extern u8 D_80132650[];
extern s32 D_80123514[];
extern s32 D_8012351C[];
extern s32 D_80123510;
extern u8 unknown3_ROM_START[];
extern u8 unknown2_ROM_START[];


void func_800E8A60(void) {
}

void func_800E8A68(void) {
    f32 temp_f20;
    s32 var_s0;

    temp_f20 = time_getDelta();
    if (D_8012D680 != NULL) {
        var_s0 = 1;
        if (freelist_capacity(D_8012D680) >= 2) {
            do {
                if (freelist_is_element_alive(D_8012D680, var_s0) != 0) {
                    func_800E8DE4(func_800E8CB0(var_s0), temp_f20);
                }
                var_s0 += 1;
            } while (var_s0 < freelist_capacity(D_8012D680));
        }
    }
}

void func_800E8B04(void) {
    if (D_8012D680 != NULL) {
        freelist_free(D_8012D680);
        D_8012D680 = NULL;
    }
}

void func_800E8B3C(){
    if(D_8012D680)
    {
       D_8012D680 = freelist_defrag(D_8012D680);
    }
}

u8 func_800E8B74(u32 arg0) {
    unkStruct800E8B74* temp_v0;
    s32 sp20;
    s32 pad[2];

    if (D_8012D680 == NULL) {
        D_8012D680 = freelist_new(0x50, 2);
    }
    temp_v0 = freelist_next(&D_8012D680, &sp20);
    if (arg0 != 0) {
        temp_v0->unk0 = ((ImageStruct*)asset_load(arg0))->unk0;
    } else {
        bzero(temp_v0, 0x50);
    }
    func_800E8CDC(sp20);
    return sp20;
}

void func_800E8C08(u8 a0) {
    freelist_erase(D_8012D680, a0);
    if (freelist_used_count(D_8012D680) == 0) {
        freelist_free(D_8012D680);
        D_8012D680 = NULL;
    }
}

s32 func_800E8C58(u8 arg0) {
    unkStruct800E8B74* temp_v0;
    s32 var_v1;

    temp_v0 = func_800E8CB0(arg0);
    var_v1 = temp_v0->unkC * temp_v0->unk0;
    if (var_v1 >= temp_v0->unk0) {
        var_v1 = temp_v0->unk0 - 1;
    }
    return var_v1;
}

unkStruct800E8B74* func_800E8CB0(u8 arg0) {
    return freelist_at(D_8012D680, arg0);
}

void func_800E8CDC(u8 arg0) {
    func_800E8CB0(arg0)->unk4 = 0.0f;
    func_800E8D28(arg0, 1.0f);
    func_800E8D5C(arg0, &D_80123500, 2U);
}

void func_800E8D28(u8 arg0, f32 arg1) {
    func_800E8CB0(arg0)->unk8 = arg1;
}

void func_800E8D5C(u8 arg0, void* arg1, s16 arg2) {
    unkStruct800E8B74* temp_v0;

    temp_v0 = func_800E8CB0(arg0);
    temp_v0->unk2 = arg2;
    rare_memcpy(temp_v0->unk10, arg1, arg2 * 8);
    func_800E8E3C(temp_v0);
}

void func_800E8DB0(u8 arg0, s32 arg1) {
    func_800E8CB0(arg0)->unk0 = (s16) arg1;
}

void func_800E8DE4(unkStruct800E8B74* arg0, f32 arg1) {
    f32 temp_f2;
    f32 temp_f0;

    temp_f2 = arg1 / arg0->unk8;
    arg0->unk4 += temp_f2;
    temp_f0 = arg0->unk4;
    arg0->unk4 = temp_f0 - (f32)(s32)temp_f0;
    func_800E8E3C(arg0);
}

void func_800E8E3C(unkStruct800E8B74* arg0) {
    arg0->unkC = func_800F3780(arg0->unk4, arg0->unk10, arg0->unk2);
}

void func_800E8E70(void* arg0, u32 arg1, u32 arg2, s32 arg3) {
    if (arg3 == 0) {
        osWritebackDCache(arg0, arg2);
        osPiStartDma(func_80012F6C(), 1, 0, arg1, arg0, arg2, func_80012F60());
        osRecvMesg(func_80012F60(), NULL, 1);
        osInvalDCache(arg0, arg2);
    } else {
        osWritebackDCache(arg0, arg2);
        osPiStartDma(func_80012EF4(), 1, 0, arg1, arg0, arg2, func_80012EE8());
        osRecvMesg(func_80012EE8(), NULL, 1);
        osInvalDCache(arg0, arg2);
    }
}

s32* func_800E8F68(unkStruct800E8F8C* arg0) {
    if (arg0->unk20 != arg0->unk24) {
        return &arg0->unk20;
    }
    return NULL;
}

void func_800E8F8C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    unkStruct800E8F8C* temp_a0;
    s32 pad;

    temp_v0 = D_80132560[arg1] + arg2;
    func_800E8E70(&D_8012D690.unk2D0, (u32)D_80123524 + temp_v0 * 0xD8, 0xD8, arg3);
    temp_a0 = &D_8012D690.unk3A8[arg0];
    rare_memcpy(temp_a0, &D_8012D690.unk2D0, 0xD8);
    temp_a0->unk18 = temp_a0->unk18 + unknown3_ROM_START;
}

s16 func_800E9048(void) {
    return D_8012D690.unk4650;
}

s16 func_800E9054(s32 arg0) {
    return D_8012D690.unk4658[arg0].unkE;
}

void func_800E9070(unkStruct800E8F8C* arg0, s32 arg1) {
    D_8012D690.unk0[arg0 - D_8012D690.unk3A8] += 1;
}

void func_800E90A4(unkStruct800E8F8C* arg0, s32 arg1) {
    D_8012D690.unk0[arg0 - D_8012D690.unk3A8] -= 1;
}

unkStruct800E8F8C* func_800E90D8(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 slot;
    s32 temp_v0;

    temp_v0 = D_80132560[arg0] + arg1;
    slot = D_80132650[(temp_v0 * 2) + arg2];
    if (slot != 0xFF) {
        D_8012D690.unk50[slot] = func_8001211C();
        return &D_8012D690.unk3A8[slot];
    }
    if (D_8012D690.unk4EC8[arg2] >= (D_80123514[arg2] - D_8012351C[arg2])) {
        func_800E95AC(0, arg2);
        if (D_8012D690.unk4EC8[arg2] >= (D_80123514[arg2] - D_8012351C[arg2])) {
            D_8012D690.unk50[D_8012351C[arg2]] = func_8001211C();
            return &D_8012D690.unk3A8[D_8012351C[arg2]];
        }
    }
    for (i = D_8012351C[arg2]; i < D_80123514[arg2]; i++) {
        if (D_8012D690.unk190[i] == -1) {
            break;
        }
    }
    func_800E8F8C(i, arg0, arg1, arg2);
    D_8012D690.unk190[i] = arg0;
    D_8012D690.unk230[i] = arg1;
    D_8012D690.unk50[i] = func_8001211C();
    D_8012D690.unk4EC8[arg2]++;
    D_80132650[(temp_v0 * 2) + arg2] = i;
    return &D_8012D690.unk3A8[i];
}

void func_800E9300(s32 arg0,s32 arg1) {
    func_800E90D8(arg0,arg1,1);
}

void func_800E9320(s32 arg0, s32 arg1) {
    func_800E90D8(arg0, arg1, 0);
}

void func_800E9340(unkStruct800E93AC* arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg1 * 0x12;
    func_800E8E70(arg0, temp_v0 + 8 + unknown2_ROM_START, 0x12, arg2);
    rare_memcpy(&D_8012D690.unk4658[arg1], arg0, 0x12);
}

unkStruct800E93AC* func_800E93AC(s32 arg0) {
    return &D_8012D690.unk4658[arg0];
}

void func_800E93CC(s32 arg0) {
    func_800E8E70(&D_8012D690.unk4650, unknown2_ROM_START, 8, arg0);
    D_80123524 = ((D_8012D690.unk4650 * 0x12) + 0xB) & ~3;
    D_80123524 += (u32)unknown2_ROM_START;
}

void func_800E9438(s32 arg0) {
    s32 sum;
    s32 i;
    unkStruct800E93AC* buf;

    sum = 0;
    buf = heap_alloc(0x12);
    for (i = 0; i < D_8012D690.unk4650; i++) {
        func_800E9340(buf, i, arg0);
        D_80132560[i] = sum;
        sum += buf->unkE;
    }
    heap_free(buf);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E94E4.s")

void func_800E9574(void) {
    func_800E94E4();
    func_800E93CC(0);
    func_800E9438(0);
    D_80123510 = 1;
}

void func_800E95AC(u32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_ra;
    s32 temp_a0;
    s32 i;

    temp_v0 = func_8001211C();
    temp_v1 = D_8012351C[arg1];
    temp_ra = D_80123514[arg1];
    for (i = temp_v1; i < temp_ra; i++) {
        if (D_8012D690.unk190[i] == -1) {
            continue;
        }
        if (D_8012D690.unk0[i] != 0) {
            continue;
        }
        if (arg0 < (temp_v0 - D_8012D690.unk50[i])) {
            temp_a0 = D_80132560[D_8012D690.unk190[i]] + D_8012D690.unk230[i];
            D_80132650[temp_a0 * 2 + arg1] = 0xFF;
            D_8012D690.unk190[i] = -1;
            D_8012D690.unk4EC8[arg1]--;
        }
    }
}

void func_800E96B0(s32 arg0) {
    func_800E95AC(0xC8, arg0);
}
