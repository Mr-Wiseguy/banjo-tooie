#include "common.h"
#include "core2/1EC6180.h"

extern s16 D_80123580[];

void func_800EC890(s32 arg0) 
{
}
void func_800EC898(unkStruct800EC898* arg0, s32 arg1, s32 arg2, s32 arg3) {
    unkStruct800EC898_var_t0* var_t0;
    unkStruct800EC898_var_t0* var_t7;
    s32 var_v1;
    s32 temp_lo;
    s32 temp_v0;
    s16 temp_v0_2;
    int new_var;

    temp_v0 = map_getCurrent();
    var_t0 = (unkStruct800EC898_var_t0*) D_80123580;
    var_t7 = (unkStruct800EC898_var_t0*) D_80123580;
    while (var_t0->unk0 != 0) {
        if ((temp_v0 != var_t0->unk0) || (arg3 != var_t0->unk2)) {
        }
        else { 
            break; 
        }
        var_t0++;
    }
    arg0->unk14 = 2048.0f / ((f32)(var_t0->unk4));
    arg0->unkC = (f32)((var_t0->unk6 << 6));
    _glidmake_entrypoint_2(arg2, arg3, arg0, (s32)(((u8*)arg0) + 6));
    temp_lo = arg1 / 10;
    do {
    } while (0);
    if (temp_lo & 1) {
        arg0->unk1A = 0;
    } else {
        arg0->unk1A = 1;
    }
    if (temp_lo & 2) {
        arg0->unk1B = 0;
    } else {
        arg0->unk1B = 1;
    }
    if (temp_lo & 4) {
        arg0->unk1C = 0;
    } else {
        arg0->unk1C = 1;
    }
    temp_v0_2 = arg0->unk18;
    if (temp_v0_2 == 0) {
        arg0->unk1C = (new_var = 0);
        return;
    }
    arg0->unk10 = (f32)(50.0f / ((f32)temp_v0_2));
}

void func_800EC9E0(s32 arg0, s32 arg1, s32 arg2) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EC9F0.s")

void func_800ECD60(s32 arg0, unkStruct800ECD60_var1 *arg1, unkStruct800ECD60_var1 *arg2, s32 arg3, unkStruct800ECD60 *arg4) {
    unkStruct800ECD60_var1 *end;
    f32 sp28[3];
    f32 temp_f0;

    temp_f0 = arg4->unk44 / arg4->unk48;
    temp_f0 = temp_f0 * temp_f0 * temp_f0 * temp_f0;

    func_800EFE50(
        sp28,
        &arg4->unk2C,
        &arg4->unk38,
        temp_f0
    );

    end = (unkStruct800ECD60_var1 *)((arg3 * 0x10) + (u8 *)arg1);

    if (arg1 < end) {
        do {
            arg2->unk0 = (s16)((f32)arg1->unk0 + sp28[0]);
            arg2->unk2 = (s16)((f32)arg1->unk2 + sp28[1]);
            arg2->unk4 = (s16)((f32)arg1->unk4 + sp28[2]);

            arg1 = (unkStruct800ECD60_var1 *)((u8 *)arg1 + 0x10);
            arg2 = (unkStruct800ECD60_var1 *)((u8 *)arg2 + 0x10);
        } while (arg1 < end);
    }
}

void func_800ECEEC(s32 arg0, unkStruct800ECD60_var1 *arg1, unkStruct800ECD60_var1 *arg2, s32 arg3, unkStruct800ECD60 *arg4) {
    unkStruct800ECD60_var1 *end;
    f32 sp28[3];
    f32 temp_f0;

    temp_f0 = arg4->unk44 / arg4->unk48;

    func_800EFE50(
        sp28,
        &arg4->unk2C,
        &arg4->unk38,
        temp_f0
    );

    end = (unkStruct800ECD60_var1 *)((arg3 * 0x10) + (u8 *)arg1);

    if (arg1 < end) {
        do {
            arg2->unk0 = (s16)((f32)arg1->unk0 + sp28[0]);
            arg2->unk2 = (s16)((f32)arg1->unk2 + sp28[1]);
            arg2->unk4 = (s16)((f32)arg1->unk4 + sp28[2]);

            arg1 = (unkStruct800ECD60_var1 *)((u8 *)arg1 + 0x10);
            arg2 = (unkStruct800ECD60_var1 *)((u8 *)arg2 + 0x10);
        } while (arg1 < end);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDC10.s")

void func_800EDC64(unkStruct800EDC64* arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    arg0->unk29 = 7;
    arg0->unk4 = arg1;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk8 = arg2;
    arg0->unk4C = 0;
    arg0->unk4E = arg4;
    func_800ED964(arg1, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDCB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDCEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDDDC.s")

void func_800EDE54(unkStruct800EDE54_arg0* arg0, unkStruct800EDE54_arg1* arg1, unkStruct800EDE54_arg2* arg2, f32 arg3) {
    arg0->unk78 = arg1->unk0;
    arg0->unk7C = arg1->unk4;
    arg0->unk80 = arg1->unk8;
    arg0->unk84 = arg1->unkC;
    arg0->unk88 = arg2->unk0;
    arg0->unk8C = arg2->unk4;
    arg0->unk90 = arg2->unk8;
    arg0->unk94 = arg2->unkC;
    arg0->unk28 = 0;
    if (arg3 > 0.0f) {
        arg0->unk9C = arg3;
    } else {
        arg0->unk9C = 0.001000000047f;
    }
    arg0->unk98 = 0/*.0f*/;
}

void func_800EDF2C(unkStruct800EDF2C *arg0, s32 arg1, s32 arg2, f32 arg3)
{
    int new_var;
    new_var = 0;
    arg0->unk29 = 5;
    arg0->unk28 = new_var;
    arg0->unk84 = (f32) arg1;
    arg0->unk80 = 0.0f;
    arg0->unk7C = 0.0f;
    arg0->unk78 = 0.0f;
    arg0->unk94 = (f32) arg2;
    arg0->unk90 = 0.0f;
    arg0->unk8C = 0.0f;
    arg0->unk88 = 0.0f;
    if (arg3 > (0.0f * 0.0f))
    {
        arg0->unk9C = arg3;
    }
    else
    {
        arg0->unk9C = 0.001000000047f;
    }
    arg0->unk98 = 0.0f;
}


void func_800EDF98(unkStruct800EDF2C *arg0, s32 arg1) {
    func_800EDF2C(arg0, arg1, arg1, 0.0f);
}

void func_800EDFBC(unkStruct800EDFBC* arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    arg0->unk29 = 4;
    arg0->unk4 = arg1;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk8 = arg2;
    arg0->unk4C = 0;
    arg0->unk4E = arg4;
    func_800ED964(arg1, arg3);
}

void func_800EE010(unkStruct800EE040 *arg0) {
    func_800EE040(arg0, 0x3EC, 0.7f, 0.9f);
}

void func_800EE040(unkStruct800EE040* arg0, s32 arg1, f32 arg2, f32 arg3) {
    u8 var_a2;
    var_a2 = arg0->unk0;
    if (var_a2 == 0) {
        var_a2 = (arg0->unk0 = func_800C2E04());
        if (!arg0) {
        }
    }
    arg0->unk20 = arg2;
    arg0->unk24 = arg3;
    func_800C301C(var_a2, arg1);
    func_800C330C(arg0->unk0, 3);
    func_800C31DC(arg0->unk0, (arg2 + arg3) * 0.5f);
    func_800C3058(arg0->unk0, 0x7D00);
    func_800C3BDC(arg0->unk0);
}


void func_800EE0F0(unkStruct800EE0F0* arg0, s32 arg1) {
    arg0->unkC = arg1;
}

void func_800EE0F8(unkStruct800EE0F8* arg0, s32 arg1) {
    arg0->unk10 = arg1;
}

void func_800EE100(unkStruct800EE100 *arg0, s32 arg1) {
    arg0->unk4C = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EE108.s")
