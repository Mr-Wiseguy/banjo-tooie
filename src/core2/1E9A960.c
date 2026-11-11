#include "core2/1E9A960.h"

extern s16 D_8012A996;
extern unkStructD_80128B08 D_80128B08[];
extern unkStructD_8012A990 D_8012A990;
extern unkStructD_80128B08 D_80128B10[];
extern unkStruct800C39D0 D_80128B90[];
extern unkStruct800C39D0 D_80128C10[];
extern f32 D_8011A870;
extern f32 D_8011A874;
extern f32 D_8011A878;
extern f32 D_801257D4;
extern f32 D_801257D8;
extern f32 D_801257F0;
extern f32 D_801257F4;
extern f32 D_801257F8;
extern f32 D_801257FC;

void func_800C1070(f32* arg0, void* arg1) {
    s32 pad;
    s32 sp28;
    f32 sp1C[3];

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            _plsu_entrypoint_0(arg0, arg1);
            return;
        }
        sp28 = func_800F5EF8(_plsu_entrypoint_0(arg0, arg1));
        if (func_8010FFA8(sp28) != 2) {
            func_8010FFB0(sp28, arg0, sp1C);
        }
    } else {
        func_800E3980(arg0);
    }
}

s32 func_800C1104(unkStruct800C39D0* arg0) {
    f32 sp24[3];
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            sp20 = _plsu_entrypoint_0(sp24, arg0);
            if (func_800F5D18(sp20) == 2) {
                return 1;
            }
            return 0;
        }
        sp1C = _plsu_entrypoint_0(sp24, arg0);
        sp18 = func_800F5EF8(sp1C);
        if (func_8010FFA8(sp18) == 2) {
            if (func_800F5D18(sp1C) == 2) {
                return 1;
            }
            return 0;
        }
        if (func_8010FFD8(sp18) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_800A5490() != 0) {
        return 1;
    }
    return 0;
}


void func_800C11F8(unkStruct800C39D0* arg0, s32 arg1) {
    arg0->unk7A_13 = arg1;
}

void func_800C1210(unkStruct800C39D0* arg0, s32 arg1) {
    arg0->unk7A_10 = arg1;
}

s32 func_800C122C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f0;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;

    if (arg3 != 0) {
        if ((arg1 == 0) || (arg2 == 0)) {
            return arg0;
        }
        return arg0 + 0x80;
    }
    if ((arg1 == 0) || (arg2 == 0)) {
        temp_f0 = ((f32)arg0 + (D_8011A870 * 127.0f)) * D_8011A874;
        if (temp_f0 > 127.0f) {
            var_f2_2 = 127.0f;
        } else {
            var_f2_2 = temp_f0;
        }
        if (var_f2_2 < 0.0f) {
            var_f0 = 0.0f;
        } else {
            if (temp_f0 > 127.0f) {
                var_f2 = 127.0f;
            } else {
                var_f2 = temp_f0;
            }
            var_f0 = var_f2;
        }
        return (s32)var_f0;
    }
    temp_f0_2 = ((f32)arg0 + (D_8011A870 * 127.0f)) * D_8011A874;
    if (temp_f0_2 > 127.0f) {
        var_f2_3 = 127.0f;
    } else {
        var_f2_3 = temp_f0_2;
    }
    if (var_f2_3 < 0.0f) {
        var_f0 = 0.0f;
    } else {
        if (temp_f0_2 > 127.0f) {
            var_f2_4 = 127.0f;
        } else {
            var_f2_4 = temp_f0_2;
        }
        var_f0 = var_f2_4;
    }
    return (s32)(var_f0 + 128.0f);
}


void func_800C13A0(unkStruct800C39D0* arg0, s32 arg1) {
    arg0->unk7C |= arg1;
}

void func_800C13B0(unkStruct800C39D0* arg0, s32 arg1) {
    arg0->unk7C &= ~arg1;
}

s32 func_800C13C4(unkStruct800C39D0* arg0, s32 arg1) {
    return arg0->unk7C & arg1;
}


s32 func_800C13D0(unkStruct800C39D0* arg0, s32 arg1) {
    return (arg0->unk7C & arg1) == 0;
}

void func_800C13E4(void) {
    s32 i;

    for (i = 0; i < 0x3C; i++) {
        D_80128B90[i].unk78 = 0;
    }
}

unkStruct800C39D0* func_800C1414(u8 arg0) {
    return &D_80128B90[arg0];
}

unkStructD_80128B08* func_800C1430(s32 arg0) {
    return &D_80128B10[arg0 - 1];
}

s32 func_800C1448(s32 arg0) {
    return D_80128B08[arg0].unk0;
}

u8 func_800C145C(void) {
    s32 i;

    for (i = 1; i < 0x3C; i++) {
        if (D_80128B90[i].unk78 == 0) {
            D_80128B90[i].unk78 = 1;
            return i;
        }
    }
    return 0;
}


void func_800C1568(s32 arg0) {
    D_80128B08[arg0].unk4 = 0;
}

void func_800C157C(void) {
    s32 i;

    for (i = 1; i < 0x11; i++) {
        D_80128B08[i].unk0 = 0;
        D_80128B08[i].unk4 = 0;
    }
}

s32 func_800C15BC(void) {
    s32 i;
    s32 count;

    do {
        count = 0;
        for (i = 0; i < 0x10; i++) {
            if (D_80128B10[i].unk4 != 0) {
                count++;
            } else if (D_80128B10[i].unk0 == 0) {
                D_80128B10[i].unk4 = 1;
                return i + 1;
            }
        }
    } while (count < 0x10);
    return 0;
}

void func_800C16A4(u8 arg0) {
    unkStruct800C39D0* temp_v0;
    temp_v0 = func_800C1414(arg0);
    if (temp_v0->unk79 != 0) {
        func_800C1568(temp_v0->unk79);
        temp_v0->unk79 = 0;
    }
    D_80128B90[arg0].unk78 = 0;
}

void func_800C16F8(unkStruct800C39D0* arg0, s32 arg1) {
    s32 temp_v0_2;
    s32 sp28;
    u8 temp_v0;

    if (arg1 != 0) {
        temp_v0 = arg0->unk79;
        if (temp_v0 != 0) {
            func_800C1568(temp_v0);
        }
        arg0->unk79 = arg1 & 0xFF;
        func_800C1210(arg0, 1);
        func_800C13A0(arg0, 4);
        func_800C13A0(arg0, 8);
        func_800C13A0(arg0, 0x10);
        arg0->unk20 = -1;
        arg0->unk24 = -1;
        if ((func_800CCEF4(arg0, &arg0->unk20, &arg0->unk24, 0, 0) != 0) && (func_800CBC00(arg0->unk20) != 0)) {
            temp_v0_2 = func_800CBBE0(arg0->unk20);
            switch (temp_v0_2) {
            case 2:
                arg0->unk60 = 0x19;
                break;
            case 3:
                arg0->unk60 = 0x14;
                break;
            case 4:
                arg0->unk60 = 0xF;
                break;
            case 5:
                arg0->unk60 = 0xA;
                break;
            case 6:
                arg0->unk60 = 5;
                break;
            }
        }
        sp28 = func_800C122C(arg0->unk60, arg0->unk1B, arg0->unk1C, func_800C13C4(arg0, 0x400));
        func_800DC3D4(arg0->unk58 - 0x3E9, arg0->unk6C, arg0->unk5A, arg0->unk61, sp28, func_800C1430(arg0->unk79));
    }
}


void func_800C1860(unkStruct800C39D0* arg0) {
    u8 temp_v0;

    if (arg0->unk7A_10 == 1) {
        func_800C13B0(arg0, 0x20);
        func_800C1210(arg0, 2);
        temp_v0 = arg0->unk79;
        if (temp_v0) {
            func_800DC4D4(func_800C1448(temp_v0));
        }
    }
}

void func_800C18C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 pad;
    s32 sp18;

    if (arg0 != 0) {
        sp18 = func_800C1448(arg0);
        func_800DC48C(sp18, func_800C122C(arg1, arg2, arg3, arg4));
    }
}

void func_800C191C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_800DC4B0(func_800C1448(arg0), arg1);
    }
}


void func_800C1950(s32 arg0, f32 arg1) {
    if (arg0 != 0) {
        func_800DC42C(func_800C1448(arg0), arg1);
    }
}


void func_800C1984(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        if (arg2 == 0) {
            arg1 = arg1 * D_8011A878;
        }
        func_800DC454(func_800C1448(arg0), arg1 & 0xFFFF);
    }
}

s32 func_800C19E4(unkStruct800C39D0* arg0, s32 arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    s32 var_v1;

    func_800C1070(sp3C, arg0);
    ml_getdiff_vec3f(sp30, arg0, sp3C);
    temp_f0 = ml_vec3f_magnitude_sq(sp30);
    temp_f12 = arg0->unkC;
    if (temp_f0 < temp_f12) {
        var_v1 = arg1;
    } else {
        temp_f2 = arg0->unk10;
        if (temp_f0 < temp_f2) {
            var_v1 = (s32)((f32)arg0->unk18 + (((temp_f2 - temp_f0) / (temp_f2 - temp_f12)) * (f32)(arg1 - arg0->unk18)));
        } else {
            var_v1 = (s32)arg0->unk18;
        }
    }
    return var_v1;
}

void func_800C1AA4(unkStruct800C39D0* arg0) {
    f32 sp5C[3];
    Vec3f sp50;
    s32 pad;
    s32 temp_f6;
    f32 sp44;
    Vec3f sp38;
    Vec3f sp2C;

    func_800E3980(sp5C);
    ml_getdiff_vec3f(sp50.f, arg0->unk0, sp5C);
    if ((SQ(sp50.f[0]) + SQ(sp50.f[1]) + SQ(sp50.f[2])) < 10.0f) {
        arg0->unk14 = 64.0f;
    } else {
        arg0->unk1C = arg0->unk1D;
        if (!arg0->unk1C) {
            func_800E3A58(&sp2C);
            sp2C.f[1] = -sp2C.f[1];
            sp2C.f[0] = -sp2C.f[0];
            sp2C.f[2] = -sp2C.f[2];
            func_800EF7B0(&sp38, &sp2C, sp50.f[0], sp50.f[1], sp50.f[2]);
            func_800F1EA4(sp38.f, &sp44);
            sp44 = 180.0f - sp44;
            if (sp44 < -90.0f) {
                sp44 = -180.0f - sp44;
                if (arg0->unk1B != 0) {
                    arg0->unk1C = 1;
                }
            } else {
                if (sp44 > 90.0f) {
                    sp44 = 180.0f - sp44;
                    if (arg0->unk1B != 0) {
                        arg0->unk1C = 1;
                    }
                }
            }
        }
        func_800C18C8(arg0->unk79, arg0->unk60, arg0->unk1B, arg0->unk1C, func_800C13C4(arg0, 0x400));
        temp_f6 = (sp44 * 0.7f) + 64.0f;
        if ((u8)arg0->unk1A != 0) {
            arg0->unk14 += 0.07f * (temp_f6 - arg0->unk14);
        } else {
            arg0->unk14 = temp_f6;
        }
    }
    func_800C191C(arg0->unk79, arg0->unk14);
}


s32 func_800C1CCC(unkStruct800C39D0* arg0, s32 arg1) {
    s32 sp24;

    if (func_800C13C4(arg0, 0x40) != 0) {
        sp24 = func_800C1104(arg0);
        if (func_800C13C4(arg0, 0x80) != 0) {
            if (sp24 == 1) {
                arg1 = arg1 * arg0->unk74;
            }
        } else if (sp24 == 0) {
            arg1 = arg1 * arg0->unk70;
        }
    }
    return arg1;
}

s32 func_800C1D80(u8 arg0) {
    s32 sp34;
    s32 sp30;
    s32 pad;
    s32 sp28;
    unkStruct800C39D0* temp_v0;

    sp34 = 0;
    temp_v0 = func_800C1414(arg0);
    if ((temp_v0->unk7A_10 == 1) && (temp_v0->unk79 != 0)) {
        sp28 = map_getCurrent() != temp_v0->unk5E;
        if (func_800C13C4(temp_v0, 4) != 0) {
            func_800C1950(temp_v0->unk79, temp_v0->unk6C);
        }
        if ((func_800C13C4(temp_v0, 0x10) != 0) && (temp_v0->unk1B == 0)) {
            func_800C18C8(temp_v0->unk79, temp_v0->unk60, temp_v0->unk1B, temp_v0->unk1C, func_800C13C4(temp_v0, 0x400));
        }
        if (func_800C13C4(temp_v0, 2) != 0) {
            if (sp28 != 0) {
                func_800C1984(temp_v0->unk79, temp_v0->unk5C, func_800C13C4(temp_v0, 0x200));
            } else {
                if (temp_v0->unk63 != 0) {
                    sp30 = func_800C19E4(temp_v0, temp_v0->unk5A);
                } else {
                    sp30 = temp_v0->unk5A;
                }
                if (sp30 < 0x64) {
                    sp34 = 1;
                }
                sp30 = func_800C1CCC(temp_v0, sp30);
                temp_v0->unk5C = sp30;
                func_800C1984(temp_v0->unk79, sp30, func_800C13C4(temp_v0, 0x200));
                if (func_800EA068(0x20) == 0) {
                    func_800C1AA4(temp_v0);
                }
            }
        } else {
            if (func_800C13C4(temp_v0, 0x100) != 0) {
                func_800C191C(temp_v0->unk79, temp_v0->unk61);
            }
            if (sp28 != 0) {
                func_800C1984(temp_v0->unk79, temp_v0->unk5C, func_800C13C4(temp_v0, 0x200));
            } else if (func_800C13C4(temp_v0, 8) != 0) {
                sp30 = func_800C1CCC(temp_v0, temp_v0->unk5A);
                temp_v0->unk5C = sp30;
                if (sp30 < 0x64) {
                    sp34 = 1;
                }
                func_800C1984(temp_v0->unk79, sp30, func_800C13C4(temp_v0, 0x200));
            }
        }
        func_800C13B0(temp_v0, 4);
        func_800C13B0(temp_v0, 8);
        func_800C13B0(temp_v0, 0x10);
    }
    if (func_800A8184() == 4) {
        sp34 += 1;
    }
    return sp34;
}

void func_800C2000(u8 arg0) {
    s32 pad44;
    s32 sp40;
    f32 sp3C;
    s32 sp38;
    s32 pad34;
    s32 pad30;
    f32 sp2C;
    f32 new_var;
    s32 pad28;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v1_3;
    s16 temp_v1_4;
    u8 temp_v0_5;
    u8 temp_v0_7;
    u32 temp_t6;
    unkStruct800C39D0* temp_v0;

    sp3C = time_getDelta();
    temp_v0 = func_800C1414(arg0);
    temp_v0->unk54 += sp3C;
    if (temp_v0->unk7B_5) {
        if (temp_v0->unk44 == 0.0f) {
            temp_v0->unk5A = 0;
        } else {
            temp_v0->unk5A = (s32)((f32)temp_v0->unk5A - (((f32)temp_v0->unk4E / temp_v0->unk44) * sp3C));
            temp_v0->unk5A = ml_max_i(0, temp_v0->unk5A);
            if (map_getCurrent() != temp_v0->unk5E) {
                temp_v0->unk5C = ml_min_i(temp_v0->unk5C, temp_v0->unk5A);
            }
        }
        if (temp_v0->unk5A <= 0) {
            func_800C2FDC(arg0);
            return;
        }
        func_800C13A0(temp_v0, 8);
    } else if (temp_v0->unk7B_3) {
        if (temp_v0->unk54 < temp_v0->unk40) {
            temp_v0->unk5A = (s32)(((temp_v0->unk54 / temp_v0->unk40) * (f32)(temp_v0->unk4C + temp_v0->unk4E)) / 2);
        } else if (temp_v0->unk54 <= (temp_v0->unk40 + temp_v0->unk48)) {
            if ((temp_v0->unk5A < temp_v0->unk4C) || (temp_v0->unk4E < temp_v0->unk5A)) {
                temp_v0->unk5A = (s32)(temp_v0->unk4C + temp_v0->unk4E) / 2;
            }
            new_var = rand2_fBounded(-1.0f, 1.0f);
            temp_v0->unk5A = (s32)((f32)temp_v0->unk5A + (new_var * temp_v0->unk50));
            temp_v0_2 = temp_v0->unk5A;
            temp_v1_3 = temp_v0->unk4E;
            if (temp_v1_3 < temp_v0_2) {
                temp_v0->unk5A = temp_v1_3;
            } else {
                temp_v0->unk5A = temp_v0_2;
            }
            temp_v0_3 = temp_v0->unk5A;
            temp_v1_4 = temp_v0->unk4C;
            if (temp_v0_3 < temp_v1_4) {
                temp_v0->unk5A = temp_v1_4;
            } else {
                temp_v0->unk5A = temp_v0_3;
            }
        } else {
            temp_v0->unk5A = (s32)(((1.0f - (((temp_v0->unk54 - temp_v0->unk40) - temp_v0->unk48) / temp_v0->unk44)) * (f32)(temp_v0->unk4C + temp_v0->unk4E)) / 2);
        }
        if (map_getCurrent() != temp_v0->unk5E) {
            temp_v0->unk5C = ml_min_i(temp_v0->unk5C, temp_v0->unk5A);
        }
        func_800C13A0(temp_v0, 8);
    }
    if (temp_v0->unk7B_4 && ((temp_v0->unk40 + temp_v0->unk48 + temp_v0->unk44) <= temp_v0->unk54)) {
        if (temp_v0->unk7B_1) {
            func_800C2FDC(arg0);
            return;
        }
        func_800C1860(temp_v0);
    }
    temp_v0_5 = temp_v0->unk79;
    if ((temp_v0_5) && (temp_v0->unk7A_10 == 1) && (func_800C1448(temp_v0_5) != 0)) {
        switch (temp_v0->unk7A_6) {
        case 0:
            break;
        case 1:
            temp_v0->unk6C += temp_v0->unk28 * sp3C;
            if (temp_v0->unk28 > 0.0f) {
                temp_v0->unk6C = ml_min_f(temp_v0->unk6C, temp_v0->unk2C);
            } else {
                temp_v0->unk6C = ml_max_f(temp_v0->unk6C, temp_v0->unk2C);
            }
            func_800C13A0(temp_v0, 4);
            break;
        case 2:
            temp_v0->unk6C += rand2_fBounded(-temp_v0->unk30, temp_v0->unk30) * sp3C;
            temp_v0->unk6C = ml_clamp_f(temp_v0->unk6C, temp_v0->unk2C, temp_v0->unk28);
            func_800C13A0(temp_v0, 4);
            break;
        case 3:
            temp_v0->unk6C = ml_map_f(temp_v0->unk54, temp_v0->unk28, temp_v0->unk2C, temp_v0->unk30, temp_v0->unk34);
            func_800C13A0(temp_v0, 4);
            break;
        case 4:
            sp2C = temp_v0->unk54;
            if (sp2C < temp_v0->unk28) {
                temp_v0->unk6C = ml_map_f(sp2C, 0.0f, temp_v0->unk28, temp_v0->unk34, temp_v0->unk38);
            } else if (sp2C < (temp_v0->unk28 + temp_v0->unk2C)) {
                temp_v0->unk6C = temp_v0->unk38;
            } else {
                temp_v0->unk6C = ml_map_f(sp2C - (temp_v0->unk28 + temp_v0->unk2C), 0.0f, temp_v0->unk30, temp_v0->unk38, temp_v0->unk3C);
            }
            func_800C13A0(temp_v0, 4);
            break;
        }
    }
    switch (temp_v0->unk7A_13) {
    case 1:
        temp_t6 = temp_v0->unk7A_10;
        if ((temp_t6 == 0) || ((temp_t6 == 1) && (temp_v0->unk79 == 0))) {
            func_800C2FDC(arg0);
            return;
        }
        goto block_60;
    case 2:
        if ((temp_v0->unk7A_10 == 1) && (func_800C13D0(temp_v0, 1) != 0)) {
            func_800C3CE8(arg0);
        } else {
            func_800C13B0(temp_v0, 1);
        }
    default:
    case 3:
block_60:
        sp40 = func_800C1D80(arg0);
        if (temp_v0->unk7A_10 == 1) {
            if (func_800C42E0(temp_v0->unk58) != 0) {
                if (func_800C13C4(temp_v0, 0x20) != 0) {
                    if (sp40 == 0) {
                        sp38 = func_800C15BC();
                        osSetThreadPri(NULL, 0x33);
                        func_800C16F8(temp_v0, sp38);
                        func_800C13B0(temp_v0, 0x20);
                        func_800C1D80(arg0);
                        osSetThreadPri(NULL, 0x14);
                    }
                } else if (sp40 != 0) {
                    func_800C1860(temp_v0);
                    func_800C1210(temp_v0, 1);
                    func_800C13A0(temp_v0, 0x20);
                }
            }
        }
        temp_v0_7 = temp_v0->unk79;
        if ((temp_v0_7) && (func_800C1448(temp_v0_7) == 0)) {
            func_800C1568(temp_v0->unk79);
            temp_v0->unk79 = 0;
        }
        return;
    }
}


s32 func_800C269C(u8 arg0) {
    unkStruct800C39D0* temp_v0;

    temp_v0 = func_800C1414(arg0);
    if (temp_v0->unk7A_10 != 3) {
        return 0;
    }
    if (temp_v0->unk79 == 0) {
        return 1;
    }
    if (func_800C1448(temp_v0->unk79) != 0) {
        return 0;
    }
    return 1;
}


void func_800C2718(void) {
    unkStruct800C39D0* var_s2;
    s32 var_s1;

    if (func_800C0638() != 0) {
        D_8011A878 -= time_getDelta();
        if (D_8011A878 < 0.5f) {
            D_8011A878 = 0.5f;
        }
    } else {
        D_8011A878 += time_getDelta();
        if (D_8011A878 > 1.0f) {
            D_8011A878 = 1.0f;
        }
    }
    var_s2 = D_80128C10;
    var_s1 = 1;
    do {
        if (var_s2->unk78 != 0) {
            if (var_s2->unk7A_10 != 3) {
                func_800C2000(var_s1);
            }
            if (func_800C269C(var_s1) != 0) {
                func_800C16A4(var_s1);
            }
        }
        var_s1 += 1;
        var_s2 += 1;
    } while (var_s1 != 0x3C);
}


void func_800C2840(s32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_v0;
    u8 temp_s0;

    temp_v0 = func_800C2E04();
    temp_s0 = temp_v0;
    if (temp_v0 != 0) {
        func_800C301C(temp_s0, arg0);
        func_800C3058(temp_s0, arg2);
        func_800C31DC(temp_s0, arg1);
        func_800C32C4(temp_s0, arg3);
        func_800C330C(temp_s0, 1);
        func_800C3418(temp_s0, arg4);
        func_800C36F4(temp_s0, 0);
        func_800C3BDC(temp_s0);
    }
}

void func_800C28D8()
{
    func_800C157C();
    func_800C13E4();
}

void func_800C2900(void) {
    s32 var_s1;
    s32 i;

    for (i = 1; i < 0x3C; i++) {
        if (D_80128B90[i].unk78 != 0) {
            func_800C2FDC(i);
        }
    }
    do {
        var_s1 = 0;
        func_800C2718();
        for (i = 1; i < 0x3C; i++) {
            if (D_80128B90[i].unk78 != 0) {
                var_s1++;
            }
        }
    } while (var_s1 != 0);
}

void func_800C2A08(void) {
    func_800C28D8();
    func_800C4308(0.0f, 1.0f);
    func_800C4B64(1.0f);
    func_800C4B70(0x55F0);
    func_800C4B7C(-1);
}

void func_800C2A5C(s32 arg0, s32 arg1) {
}
void func_800C2A68()
{
    func_80017244();
    func_80016E7C();
}

void func_800C2A90()
{
    func_800C2900();
    func_800C2A68();
}

void func_800C2AB8(void) {
    unkStruct800C39D0* var_s1;
    s32 var_s2;
    s32 var_s3;

    func_800C2B80();
    do {
        var_s1 = D_80128C10;
        var_s2 = 1;
        var_s3 = 0;
        do {
            if (var_s1->unk78 != 0) {
                if (var_s1->unk7A_10 == 3) {
                    if (func_800C269C(var_s2) != 0) {
                        func_800C16A4(var_s2);
                    } else {
                        var_s3 += 1;
                    }
                }
            }
            var_s2 += 1;
            var_s1 += 1;
        } while (var_s2 != 0x3C);
    } while (var_s3 != 0);
}


void func_800C2B80(void) {
    unkStruct800C39D0* var_s0;
    s32 var_s1;

    var_s0 = D_80128C10;
    var_s1 = 1;
    while (var_s1 != 0x3C) {
        if ((var_s0->unk78 != 0) && (var_s0->unk7A_10 != 3)) {
            if (var_s0->unk62 != 0xFF) {
                if (var_s0->unk62 == ((var_s1 != 0x3C) * 0)) {
                    func_800C2FDC(var_s1);
                } else {
                    var_s0->unk62 = var_s0->unk62 - 1;
                    if (var_s0->unk62 == 0) {
                        var_s0->unk54 = 0.0f;
                        var_s0->unk7B_5 = 1;
                    }
                }
            }
        }
        var_s1++;
        var_s0++;
    }
}


void func_800C2C4C(u8 id) {
    s16 temp_v0_2;
    unkStruct800C39D0* temp_v0;

    temp_v0 = func_800C1414(id);
    temp_v0->unk64 = NULL;
    temp_v0->unk58 = -1;
    temp_v0->unk5C = 0;
    temp_v0->unk5A = 0x55F0;
    temp_v0->unk60 = 0;
    temp_v0->unk61 = 0x3F;
    temp_v0->unk79 = 0;
    temp_v0->unk62 = 0xFF;
    temp_v0->unk6C = 1.0f;
    temp_v0_2 = map_getCurrent();
    temp_v0->unk40 = 1.0f;
    temp_v0->unk44 = 1.0f;
    temp_v0->unk48 = 3.0f;
    temp_v0->unk54 = 0.0f;
    temp_v0->unk63 = 1;
    temp_v0->unk7A_6 = 0;
    temp_v0->unk5E = temp_v0_2;
    temp_v0->unk7B_4 = 0;
    temp_v0->unk7B_1 = 1;
    temp_v0->unk7B_3 = 0;
    temp_v0->unk7B_5 = 0;
    temp_v0->unk7B_2 = 0;
    func_800C1210(temp_v0, 0);
    func_800C11F8(temp_v0, 0);
    func_800C13A0(temp_v0, 1);
    func_800C13A0(temp_v0, 4);
    func_800C13A0(temp_v0, 8);
    func_800C13A0(temp_v0, 0x10);
    temp_v0->unkC = 62500.0f;
    temp_v0->unk10 = 1440000.0f;
    temp_v0->unk14 = 64.0f;
    temp_v0->unk18 = 0xA;
    temp_v0->unk1A = 0;
    temp_v0->unk1B = 0;
    temp_v0->unk1C = 0;
    temp_v0->unk1D = 0;
    ml_vec3f_clear((f32*)temp_v0);
    func_800C13B0(temp_v0, 2);
    func_800C13B0(temp_v0, 0x20);
    func_800C13B0(temp_v0, 0x200);
    func_800C13B0(temp_v0, 0x400);
    func_800C3418(id, 2);
    func_800C3798(id, 0.2f, 0.1f);
}

u8 func_800C2E04(void) {
    u8 sp1F;
    s32 temp_v0;

    temp_v0 = func_800C145C();
    sp1F = temp_v0;
    if (temp_v0 == 0) {
        return 0;
    }
    func_800C2C4C(sp1F);
    return sp1F;
}
void func_800C2E40(u8 arg0) {
    s16 temp_v0_2;
    unkStruct800C39D0* temp_v0;

    func_800C3CE8(arg0);
    temp_v0 = func_800C1414(arg0);
    temp_v0->unk64 = NULL;
    temp_v0->unk58 = -1;
    temp_v0->unk5C = 0;
    temp_v0->unk5A = 0x55F0;
    temp_v0->unk60 = 0;
    temp_v0->unk61 = 0x3F;
    temp_v0->unk62 = 0xFF;
    temp_v0->unk6C = 1.0f;
    temp_v0_2 = map_getCurrent();
    temp_v0->unk40 = 1.0f;
    temp_v0->unk44 = 1.0f;
    temp_v0->unk48 = 3.0f;
    temp_v0->unk54 = 0.0f;
    temp_v0->unk63 = 1;
    temp_v0->unk7A_6 = 0;
    temp_v0->unk5E = temp_v0_2;
    temp_v0->unk7B_4 = 0;
    temp_v0->unk7B_1 = 1;
    temp_v0->unk7B_3 = 0;
    temp_v0->unk7B_5 = 0;
    temp_v0->unk7B_2 = 0;
    func_800C1210(temp_v0, 0);
    func_800C11F8(temp_v0, 0);
    func_800C13A0(temp_v0, 1);
    func_800C13A0(temp_v0, 4);
    func_800C13A0(temp_v0, 8);
    func_800C13A0(temp_v0, 0x10);
    temp_v0->unkC = 62500.0f;
    temp_v0->unk10 = 1440000.0f;
    temp_v0->unk18 = 0xA;
    temp_v0->unk1A = 0;
    temp_v0->unk1B = 0;
    temp_v0->unk14 = 64.0f;
    ml_vec3f_clear((f32*)temp_v0);
    func_800C13B0(temp_v0, 2);
    func_800C13B0(temp_v0, 0x20);
    func_800C3418(arg0, 2);
    func_800C3798(arg0, 0.2f, 0.1f);
}

s32 func_800C2FDC(u8 id) {
    unkStruct800C39D0* temp_v0;

    temp_v0 = func_800C1414(id);
    func_800C3CE8(id);
    func_800C1210(temp_v0, 3);
    return 0;
}

void func_800C301C(u8 id, s32 arg1) {
    if (id != 0) {
        func_800C1414(id)->unk58 = arg1;
    }
}

void func_800C3058(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk5A = arg1;
        if (!temp_v0->unk7B_3) {
            temp_v0->unk4C = arg1;
            temp_v0->unk4E = arg1;
            temp_v0->unk50 = 0.0f;
        }
        func_800C13A0(temp_v0, 8);
    }
}

void func_800C30B8(u8 arg0, s32 arg1, f32* arg2, f32 arg3, f32 arg4) {
    f32 sp24[3];
    f32 temp_f0;
    f32 var_f2;

    func_800C1070(sp24, arg2);
    temp_f0 = ml_vec3f_distance(arg2, sp24);
    if (arg4 <= temp_f0) {
        var_f2 = 0.0f;
    } else if (arg3 <= temp_f0) {
        var_f2 = 1.0f - ((temp_f0 - arg3) / (arg4 - arg3));
    } else {
        var_f2 = 1.0f;
    }
    func_800C3058(arg0, (s32)((f32)arg1 * var_f2));
}


void func_800C316C(u8 id, s32 arg1, s32 arg2, f32 arg3) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk7B_3 = 1;
        temp_v0->unk4C = arg1;
        temp_v0->unk4E = arg2;
        temp_v0->unk50 = arg3;
        temp_v0->unk5A = 0;
        func_800C13A0(temp_v0, 8);
    }
}

void func_800C31DC(u8 id, f32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk6C = arg1;
        func_800C13A0(temp_v0, 4);
    }
}

void func_800C3224(u8 id, f32 arg1, f32 arg2, f32 arg3) {
    f32 new_var;
    f32 var_f20;

    var_f20 = func_800C395C(id);
    if (var_f20 < arg1) {
        var_f20 = var_f20 + arg3;
    } else if (arg2 < var_f20) {
        var_f20 = var_f20 - arg3;
    } else {
        new_var = rand2_fBounded(-arg3, arg3);
        var_f20 = ml_clamp_f(var_f20 + new_var, arg1, arg2);
    }
    func_800C31DC(id, var_f20);
    if (var_f20) {
    }
}

void func_800C32C4(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk60 = arg1;
        func_800C13A0(temp_v0, 0x10);
    }
}

void func_800C330C(u8 id, s32 arg1) {
    if (id != 0) {
        func_800C11F8(func_800C1414(id), arg1);
    }
}

void func_800C334C(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk61 = arg1;
        func_800C13A0(temp_v0, 0x100);
    }
}

void func_800C3394(u8 id, unkFunc800C3CE8 arg1, s32 arg2) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk64 = arg1;
        temp_v0->unk68 = arg2;
    }
}

void func_800C33DC(u8 id, s32 arg1) {
    if (id != 0) {
        func_800C1414(id)->unk1B = arg1;
    }
}


void func_800C3418(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_s0;

    if (id != 0) {
        temp_s0 = func_800C1414(id);
        switch (arg1) {
        case 0:
            func_800C13B0(temp_s0, 0x40);
            func_800C13B0(temp_s0, 0x80);
            break;
        case 1:
            func_800C13A0(temp_s0, 0x40);
            func_800C13B0(temp_s0, 0x80);
            break;
        case 2:
            func_800C13A0(temp_s0, 0x40);
            func_800C13A0(temp_s0, 0x80);
            break;
        }
    }
}

void func_800C34CC(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_a0;

    if (id != 0) {
        temp_a0 = func_800C1414(id);
        if (arg1 != 0) {
            func_800C13B0(temp_a0, 0x200);
        } else {
            func_800C13A0(temp_a0, 0x200);
        }
    }
}

void func_800C3528(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_a0;

    if (id != 0) {
        temp_a0 = func_800C1414(id);
        if (arg1 != 0) {
            func_800C13A0(temp_a0, 0x400);
        } else {
            func_800C13B0(temp_a0, 0x400);
        }
    }
}

void func_800C3584(u8 id, f32 arg1, f32 arg2) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unkC = arg1 * arg1;
        temp_v0->unk10 = arg2 * arg2;
        func_800C368C(id, 1);
    }
}

void func_800C35E8(u8 id, s32 arg1) {
    unkStruct800C39D0* sp1C;

    if (id != 0) {
        sp1C = func_800C1414(id);
        ml_vec3f_copy(sp1C, arg1);
        func_800C368C(id, 1);
        sp1C->unk5E = map_getCurrent();
    }
}

void func_800C3648(u8 id, s32 arg1) {
    unkStruct800C39D0* sp1C;

    if (id != 0) {
        sp1C = func_800C1414(id);
        sp1C->unk5E = map_getCurrent();
    }
}

void func_800C368C(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        if (arg1 != 0) {
            func_800C13A0(temp_v0, 2);
        } else {
            func_800C13B0(temp_v0, 2);
        }
        func_800C33DC(id, arg1);
    }
}

void func_800C36F4(u8 id, s32 arg1) {
    if (id != 0) {
        func_800C1414(id)->unk62 = arg1;
    }
}

void func_800C3730(u8 id, f32 arg1, f32 arg2, f32 arg3) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk7A_6 = 1;
        temp_v0->unk28 = arg3;
        temp_v0->unk2C = arg2;
        func_800C31DC(id, arg1);
    }
}

void func_800C3798(u8 id, f32 arg1, f32 arg2) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk70 = arg1;
        temp_v0->unk74 = arg2;
    }
}

void func_800C37E0(u8 id, f32 arg1, f32 arg2, f32 arg3) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk7A_6 = 2;
        temp_v0->unk30 = arg3;
        temp_v0->unk2C = arg1;
        temp_v0->unk28 = arg2;
        func_800C31DC(id, (arg1 + arg2) * 0.5f);
    }
}

void func_800C3868(u8 id, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk7A_6 = 3;
        temp_v0->unk28 = arg1;
        temp_v0->unk2C = arg2;
        temp_v0->unk30 = arg3;
        temp_v0->unk34 = arg4;
        func_800C31DC(id, arg3);
    }
}

s16 func_800C38E4(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_800C1414(arg0)->unk58;
}


s16 func_800C3920(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_800C1414(arg0)->unk5A;
}

f32 func_800C395C(u8 arg0) {
    if (arg0 == 0) {
        return 1.0f;
    }
    return func_800C1414(arg0)->unk6C;
}

s32 func_800C39A0(u8 id) {
    return func_800C1414(id)->unk7A_13;
}

s32 func_800C39D0(unkStruct800C39D0* arg0) {
    s32 var_v1;

    if (func_800C13C4(arg0, 0x800) != 0) {
        return 1;
    }
    if ((arg0->unk63 != 0) && (func_800C13C4(arg0, 2) != 0)) {
        var_v1 = func_800C19E4(arg0, arg0->unk5A);
    } else {
        var_v1 = arg0->unk5A;
    }
    return var_v1 >= 0x65;
}

void func_800C3A40(u8 id, f32 arg1, f32 arg2, f32 arg3) {
    unkStruct800C39D0* temp_v0;

    s16 temp_v1;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk7B_4 = 1;
        temp_v0->unk7B_1 = 1;
        temp_v0->unk40 = arg1;
        temp_v0->unk44 = arg3;
        temp_v0->unk48 = arg2;
        temp_v0->unk54 = 0.0f;
        if (!temp_v0->unk7B_3) {
            temp_v1 = temp_v0->unk5A;
            temp_v0->unk7B_3 = 1;
            temp_v0->unk5A = 0;
            temp_v0->unk4C = temp_v1;
            temp_v0->unk4E = temp_v1;
            temp_v0->unk50 = 0.0;
        }
    }
}

void func_800C3AE0(u8 id, f32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        if (temp_v0->unk7B_3) {
            temp_v0->unk4C = (s32)((f32)temp_v0->unk4C * arg1);
            temp_v0->unk4E = (s32)((f32)temp_v0->unk4E * arg1);
        } else {
            temp_v0->unk5A = (s32)((f32)temp_v0->unk5A * arg1);
        }
    }
}

void func_800C3B8C(u8 id, s32 arg1) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        temp_v0->unk7B_1 = arg1;
    }
}

void func_800C3BDC(u8 id) {
    unkStruct800C39D0* temp_v0;
    s32 sp20;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        if (temp_v0->unk7B_2) {
            func_800FEC60(4);
        }
        if ((func_800C39D0(temp_v0) != 0) || (func_800C42E0(temp_v0->unk58) != 0)) {
            if (temp_v0->unk7A_13 == 2) {
                func_800C13A0(temp_v0, 1);
                if (temp_v0->unk7A_10 == 1) {
                    return;
                }
            } else if (temp_v0->unk7A_10 == 1) {
                func_800C3CE8(id);
            }
            sp20 = func_800C15BC();
            osSetThreadPri(NULL, 0x33);
            func_800C16F8(temp_v0, sp20);
            func_800C1D80(id);
            osSetThreadPri(NULL, 0x14);
        }
    }
}

void func_800C3CE8(u8 id) {
    unkStruct800C39D0* temp_v0;

    if (id != 0) {
        temp_v0 = func_800C1414(id);
        if (temp_v0->unk7A_10 == 1) {
            func_800C1860(temp_v0);
            if (temp_v0->unk7B_2) {
                func_800FECB8(4);
            }
            if (temp_v0->unk64 != NULL) {
                temp_v0->unk64(id, temp_v0->unk68);
            }
        }
    }
}

int func_800C3D78(u8 arg0) {
    unkStruct800C39D0* temp_a0;

    if ((arg0 != 0) == 0) {
        return 0;
    }

    temp_a0 = func_800C1414(arg0);
    return arg0 != 0 && temp_a0->unk7A_10 == 1 && temp_a0->unk79 && func_800C1448(temp_a0->unk79);
}

s32 func_800C3E00(s32 arg0) {
    s32 i;
    unkStruct800C39D0* var_s1;

    for (i = 1, var_s1 = D_80128C10; i < 0x3C; i++, var_s1++) {
        if ((var_s1->unk78 != 0) && (func_800C3D78(i) != 0) && (arg0 == var_s1->unk58)) {
            return 1;
        }
        if (0) {
        }
    }
    return 0;
}

void func_800C3E88(s32 arg0) {
    func_800C2840(arg0, 1.0f, 0x55F0, 0, 2);
}

void func_800C3EB8(s32 arg0) {
    func_800C2840(arg0, 1.0f, 0x55F0, 0, 0);
}

void func_800C3EE4(s32 arg0, s32 arg1) {
    func_800C2840(arg0, 1.0f, arg1, 0, 2);
}

void func_800C3F14(s32 arg0, f32 arg1) {
    func_800C2840(arg0, arg1, 0x55F0, 0, 2);
}


void func_800C3F48(u32 arg0) {
    func_800C2840(arg0 & 0x7FF, (f32)((arg0 >> 21) & 0x7FF) / 1024, (arg0 >> 6) & 0x7FE0, 0, 2);
}

void func_800C3FC0(s32 arg0, f32 arg1, s32 arg2) {
    func_800C2840(arg0, arg1, arg2, 0, 2);
}

void func_800C3FF0(s32 arg0, f32 arg1, s32 arg2) {
    func_800C2840(arg0, arg1, arg2, 0, 0);
}

void func_800C401C(s32 arg0, f32 arg1, s32 arg2, f32* arg3, f32 arg4, f32 arg5, s32 arg6) {
    u8 temp_s0;
    f32 sp20[3];

    func_800C1070(sp20, arg3);
    if (!(arg5 <= ml_vec3f_distance(sp20, arg3))) {
        temp_s0 = func_800C2E04();
        if (temp_s0 != 0) {
            func_800C3418(temp_s0, arg6);
            func_800C301C(temp_s0, arg0);
            func_800C3058(temp_s0, arg2);
            func_800C31DC(temp_s0, arg1);
            func_800C3584(temp_s0, arg4, arg5);
            func_800C35E8(temp_s0, arg3);
            func_800C330C(temp_s0, 1);
            func_800C33DC(temp_s0, 1);
            func_800C36F4(temp_s0, 0);
            func_800C3BDC(temp_s0);
        }
    }
}

void func_800C4104(s32 arg0, f32 arg1, s32 arg2, f32* arg3, f32 arg4, f32 arg5) {
    func_800C401C(arg0, arg1, arg2, arg3, arg4, arg5, 2);
}


void func_800C4140(u32 arg0, f32* arg1, u32 arg2) {
    func_800C401C(
        arg0 & 0x7FF,
        (f32)((arg0 >> 21) & 0x7FF) / 1024, 
        (arg0 >> 6) & 0x7FE0, arg1, 
        (f32)(arg2 & 0xFFFF), 
        (f32)((arg2 >> 16) & 0xFFFF), 2
    );
}


void func_800C4208(s32 arg0, f32 arg1, s32 arg2, f32* arg3, f32 arg4, f32 arg5) {
    func_800C401C(arg0, arg1, arg2, arg3, arg4, arg5, 1);
}

void func_800C4244(Unk80132ED0* arg0, f32 arg1, u32 arg2, f32* arg3, f32 arg4, f32 arg5) {
    func_800C401C((s32) arg0, arg1, (s32) arg2, arg3, arg4, arg5, 0);
}


void func_800C427C()
{
    func_800C2718();
}

u8 func_800C429C(s32 arg0, s32 arg1) {
    u8 sp1F;

    sp1F = func_800C2E04();
    func_800C301C(sp1F, arg0);
    func_800C330C(sp1F, arg1);
    return sp1F;
}

s32 func_800C42E0(s32 arg0) {
    return func_800DC548(0, arg0 - 0x3E9, arg0);
}

void func_800C4308(f32 arg0, f32 arg1) {
    D_8011A870 = arg0;
    D_8011A874 = arg1;
}

void func_800C431C(u8 id, s32 arg1) {
    func_800C1414(id)->unk63 = arg1;
}

u8 func_800C4350(u8 arg0, f32* arg1, s16* arg2) {
    s16 var_v1;
    s16 var_a1;
    s16 var_a2;
    s32 var_s4;
    s32 temp_v0;
    unkStruct800C39D0* var_v0;
    f32 var_fv0;
    f32 var_fv1;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fa2;
    f32 var_fa3;

    var_s4 = 0;
    if (arg0 == 0) {
        arg0 = func_800C2E04();
        if (arg0 == 0) {
            return 0;
        }
        var_v0 = func_800C1414(arg0);
    } else {
        var_v0 = func_800C1414(arg0);
    }
    if (arg1 != NULL) {
        ml_vec3f_copy((f32*)var_v0, arg1);
        func_800C13A0(var_v0, 2);
        var_v0->unk1B = 1;
        var_v0->unk5E = map_getCurrent();
    }
    if (arg2 == NULL) {
        if (arg0 != 0) {
            func_800C3BDC(arg0);
        }
        return arg0;
    }
    while ((var_v1 = *arg2++) != 0) {
        switch (var_v1 & 0xFF) {
        case 1:
            var_fv0 = arg2[0];
            var_fv1 = arg2[1];
            if (arg1 != NULL) {
                var_v0->unk1B = 1;
                var_v0->unkC = SQ(var_fv0);
                var_v0->unk10 = SQ(var_fv1);
                func_800C13A0(var_v0, 2);
            }
            arg2 += 2;
            break;
        case 2:
            var_v0->unk63 = (s32)(var_v1 & 0xFF00) >> 8;
            break;
        case 32:
            if (((s32)(var_v1 & 0xFF00) >> 8) != 0) {
                func_800C13B0(var_v0, 0x200);
            } else {
                func_800C13A0(var_v0, 0x200);
            }
            break;
        case 34:
            if (((s32)(var_v1 & 0xFF00) >> 8) != 0) {
                func_800C13B0(var_v0, 0x400);
            } else {
                func_800C13A0(var_v0, 0x400);
            }
            break;
        case 36:
            if (((s32)(var_v1 & 0xFF00) >> 8) != 0) {
                func_800C13A0(var_v0, 0x800);
            } else {
                func_800C13B0(var_v0, 0x800);
            }
            break;
        case 3:
            return arg0;
        case 4:
            func_800C2FDC(arg0);
            return 0;
        case 5:
            var_v0->unk60 = (s32)(var_v1 & 0xFF00) >> 8;
            func_800C13A0(var_v0, 0x10);
            break;
        case 6:
            func_800C11F8(var_v0, (s32)(var_v1 & 0xFF00) >> 8);
            break;
        case 7:
            var_v0->unk62 = (s32)(var_v1 & 0xFF00) >> 8;
            break;
        case 8:
            var_v0->unk61 = (s32)(var_v1 & 0xFF00) >> 8;
            func_800C13A0(var_v0, 0x100);
            break;
        case 9:
            if (((s32)(var_v1 & 0xFF00) >> 8) & 0xFF) {
                var_v0->unk1A = 1;
            } else {
                var_v0->unk1A = 0;
            }
            break;
        case 10:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk6C = var_fv0;
            func_800C13A0(var_v0, 4);
            break;
        case 11:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_fv1 = *arg2++ * (1.0f / 256.0f);
            var_fa0 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk6C = var_fv0;
            var_v0->unk2C = var_fv1;
            var_v0->unk28 = var_fa0;
            var_v0->unk7A_6 = 1;
            func_800C13A0(var_v0, 4);
            break;
        case 12:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_fv1 = *arg2++ * (1.0f / 256.0f);
            var_fa0 = *arg2++ * (1.0f / 256.0f);
            var_fa1 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk28 = var_fv0;
            var_v0->unk2C = var_fv1;
            var_v0->unk30 = var_fa0;
            var_v0->unk34 = var_fa1;
            var_v0->unk7A_6 = 3;
            func_800C13A0(var_v0, 4);
            break;
        case 13:
            var_fa0 = *arg2++ * (1.0f / 256.0f);
            var_fa1 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk6C = rand2_fBounded(var_fa0, var_fa1);
            func_800C13A0(var_v0, 4);
            break;
        case 29:
            var_fv0 = D_8012A990.unk0;
            var_v0->unk6C = var_fv0;
            func_800C13A0(var_v0, 4);
            break;
        case 14:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_fv1 = *arg2++ * (1.0f / 256.0f);
            var_fa0 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk2C = var_fv0;
            var_v0->unk28 = var_fv1;
            var_v0->unk30 = var_fa0;
            var_v0->unk6C = (var_v0->unk2C + var_v0->unk28) * 0.5f;
            var_v0->unk7A_6 = 2;
            func_800C13A0(var_v0, 4);
            break;
        case 15:
            func_800C11F8(var_v0, 1);
            var_s4 = 1;
            var_v0->unk62 = 0;
            break;
        case 16:
            func_800C2E40(arg0);
            break;
        case 17:
            var_s4 = 1;
            break;
        case 18:
            var_s4 = 0;
            if (var_v0->unk7A_10 == 1) {
                func_800C1860(var_v0);
                if (var_v0->unk64 != NULL) {
                    var_v0->unk64(arg0, var_v0->unk68);
                }
            }
            break;
        case 19:
            temp_v0 = *arg2++;
            var_v0->unk58 = temp_v0;
            break;
        case 20:
            if (arg1 != NULL) {
                var_v0->unk1B = (s32)(var_v1 & 0xFF00) >> 8;
                if (((s32)(var_v1 & 0xFF00) >> 8) != 0) {
                    func_800C13A0(var_v0, 2);
                } else {
                    func_800C13B0(var_v0, 2);
                }
            }
            break;
        case 21:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_fv1 = *arg2++ * (1.0f / 256.0f);
            var_fa0 = *arg2++ * (1.0f / 256.0f);
            func_800C3A40(arg0, var_fv0, var_fv1, var_fa0);
            break;
        case 31:
            var_v0->unk1D = 1;
            break;
        case 22:
            func_800C3058(arg0, *arg2++);
            break;
        case 23:
            var_a1 = *arg2++;
            var_a2 = *arg2++;
            var_fv0 = *arg2++;
            func_800C316C(arg0, var_a1, var_a2, var_fv0);
            break;
        case 24:
            func_800C3058(arg0, 0x7FFF);
            break;
        case 25:
            func_800C3058(arg0, rand2_iBounded(arg2[0], arg2[1]));
            arg2 += 2;
            break;
        case 30:
            func_800C3058(arg0, D_8012A990.unk4);
            break;
        case 26:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_fv1 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk70 = var_fv0;
            var_v0->unk74 = var_fv1;
            break;
        case 27:
            func_800C3418(arg0, (s32)(var_v1 & 0xFF00) >> 8);
            break;
        case 28:
            var_v0->unk7B_2 = 1;
            break;
        case 33:
            func_800C301C(arg0, D_8012A990.unk6);
            break;
        case 35:
            var_fv0 = *arg2++ * (1.0f / 256.0f);
            var_fv1 = *arg2++ * (1.0f / 256.0f);
            var_fa0 = *arg2++ * (1.0f / 256.0f);
            var_fa1 = *arg2++ * (1.0f / 256.0f);
            var_fa2 = *arg2++ * (1.0f / 256.0f);
            var_fa3 = *arg2++ * (1.0f / 256.0f);
            var_v0->unk28 = var_fv0;
            var_v0->unk2C = var_fv1;
            var_v0->unk30 = var_fa0;
            var_v0->unk34 = var_fa1;
            var_v0->unk38 = var_fa2;
            var_v0->unk3C = var_fa3;
            var_v0->unk7A_6 = 4;
            func_800C13A0(var_v0, 4);
            break;
        }
    }
    if (var_s4 != 0) {
        func_800C3BDC(arg0);
    }
    return arg0;
}

void func_800C4AF0(f32* arg0, void* arg1) {
    s32 temp_v0;
    u8 temp_s0;

    temp_v0 = func_800C4350(0, arg0, arg1);
    temp_s0 = temp_v0;
    if (temp_v0 != 0) {
        if (arg0 == NULL) {
            func_800C33DC(temp_s0, 0);
        }
        func_800C330C(temp_s0, 1);
        func_800C36F4(temp_s0, 0);
        func_800C3BDC(temp_s0);
    }
}

void func_800C4B64(f32 arg0) {
    D_8012A990.unk0 = arg0;
}

void func_800C4B70(s32 arg0) {
    D_8012A990.unk4 = arg0;
}

void func_800C4B7C(s32 arg0) {
    D_8012A996 = (s16) arg0;
}

