#include "overlays/ba/data.h"

s32 func_80800000_badata(PlayerState *self) {
    s32 sp1C  = bs_getCurrentState(self);
    switch(func_800A3274(self)) {
        case 2: 
            return 2;

        case 6:
            if(func_8009CA70(self, sp1C, 0x4000)) {
                return 0x1E;
            }
            return 0xB;

        case 7:
            return 0;

        case 8:
            return 0xE;

        case 0xA:
            if(func_8009E71C(self, 0x12)) {
                return 0xA;
            } else if (func_8009E71C(self, 0x13)) {
                return 0x1F;
            } else if (func_8009E71C(self, 0x14)) {
                return 0x20;
            } else if (func_8009CA70(self, sp1C, 0x400)) {
                return 0x1C;
            } else if (player_inWater(self)) {
                if (func_800F8B88() == 3) {
                    return 0x21;
                } else {
                    switch (func_800F40EC(self)) {
                        case 2:
                            return 0x5;
                        default:
                        case 1:
                            return 0x4;
                    }
                }
            } else {
                return 0xF;
            }
        case 0xB:
            if (func_8009CA70(self, sp1C, 0x200)) {
                return 0x22;
            } else if (func_8009CBDC(self, sp1C) == 0x9) {
                return 0x3;
            } else if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x1;
            } else if (func_800F8B88() == 3) {
                return 0x1A;
            } else if (player_inWater(self)) {
                return 0x1B;
            } else {
                return 0x10;
            }
            break;

        case 0xD:
            if (player_inWater(self)) {
                return 0x12;
            } else {
                return 0x11;
            }
            break;

        case 0xE:
            return 0x13;

        case 0xF:
            return 0x14;
        
        case 0x10:
            return 0x15;

        case 0xC:
            return 0x16;

        case 0x11:
            return 0x17;

        case 0x12:
            return 0x18;

        case 0x13:
            return 0x19;

        case 9:
            return 0x1D;
            
        case 1:
        default:
            if (func_8009CBDC(self, sp1C) == 2) {
                return 0x23;
            } else if (func_8009CBDC(self, sp1C) == 0xA) {
                return 0xC;
            } else if (func_8009CBDC(self, sp1C) == 0x9) {
                return 0x7;
            } else if (func_8009CA70(self, sp1C, 0x40)) {
                return 0x8;
            } else if (func_8009CA70(self, sp1C, 0x400)) {
                return 0x1C;
            } else if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x9;
            } else if (func_8009EA4C() == 5) {
                return 0x5;
            } else if (func_800F3ED0(self) == 3) {
                return 0xD;
            } else if (player_inWater(self)) {
                switch (func_800F40EC(self)) {
                    case 2:
                        return 0x5;
                    default:
                    case 1:
                        return 0x4;
                }
            } else {
                return 0x6;
            }
            break;
    }
}

s32 func_80800388_badata(PlayerState *self) {
    s32 sp1C;
    f32 sp18;

    sp1C = func_8009EA4C();
    switch (func_800A3274(self)) {
        case 2:
            return 2;
        
        case 6:
            if (sp1C == 4) {
                return 0x1E;
            }         
            return 0xB;
        
        case 7:
            return 0;
        
        case 8:
            return 0xE;

        case 0xA:
            if (player_inWater(self)) {
                if (func_800F8B88() == 3) {
                    return 0x21;
                }

                sp18 = func_8009C150(self);
                if(func_800964DC(self) - 80.0f < sp18) {
                    return 0x4;
                }
                
                return 0x5;
            }
            
            switch(sp1C) {
                case 0x3:
                    return 0xA;
                case 0x6:
                    return 0x1F;
                case 0x7:
                    return 0x20;
            }
            return 0xF;

        case 0xB:
            if (sp1C == 4) {
                return 0x3;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON) != 0.0f) {
                return 0x10;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x1;
            }

            if (func_800F8B88() == 3) {
                return 0x1A;
            }

            if (player_inWater(self)) {
                return 0x1B;
            }

            return 0x10;

        case 0xD:
            if (player_inWater(self)) {
                return 0x12;
            }
            return 0x11;
        
        case 0xE:
            return 0x13;

        case 0xF:
            return 0x14;

        case 0x10:
            return 0x15;

        case 0xC:
            return 0x16;

        case 0x11:
            return 0x17;

        case 0x12:
            return 0x18;
        
        case 0x13:
            return 0x19;


        case 9:
            return 0x1D;

        case 1:
        default:
            if (player_inWater(self)) {
                sp18 = func_8009C150(self);
                if (func_800964DC(self) - 95.0f < sp18) {
                    return 4;
                }
                return 5;
            }
            if (sp1C == 4) {
                return 0x7;
            }
            if (sp1C == 5) {
                return 0x5;
            }
            if (sp1C == 2) {
                return 0x8;
            }

            if(bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON) != 0.0f) {
                return 0x8;
            }

            if(bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x9;
            }
            return 0x6;
    }
}

void func_808006AC_badata(PlayerState *self , BaData_1 *arg1, s32 *arg2, f32 *arg3) {
    s32 tmp_v0 = func_80800000_badata(self);
    *arg2 = arg1[tmp_v0].unk2;
    *arg3 = arg1[tmp_v0].unk4;
}


void badata_entrypoint_0(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801EF8_badata, assetId, arg2);
}

void badata_entrypoint_1(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801A78_badata, assetId, arg2);
}

void badata_entrypoint_2(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801B98_badata, assetId, arg2);
}

void badata_entrypoint_3(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801DD8_badata, assetId, arg2);
}

void badata_entrypoint_4(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80802018_badata, assetId, arg2);
}

void badata_entrypoint_5(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801CB8_badata, assetId, arg2);
}


void badata_entrypoint_6(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_3 *tmp_v1 = &D_80801718_badata[tmp_v0];
    *arg1  = tmp_v1->unk2;
    *arg2  = tmp_v1->unk4;
    *arg3  = tmp_v1->unk8;
    *arg4  = tmp_v1->unkC;
}

void badata_entrypoint_7(PlayerState * self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801958_badata, assetId, arg2);
}

void badata_entrypoint_8(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802648_badata[tmp_v0];
    *arg1  = tmp_v1->unk0;
    *arg2  = tmp_v1->unk4;
    *arg3  = tmp_v1->unk8;
}

void badata_entrypoint_9(PlayerState *self, AssetId *assetId, f32 *arg2){
    func_808006AC_badata(self, D_80802138_badata, assetId, arg2);
}

void badata_entrypoint_10(PlayerState *self, AssetId *assetId, f32 *arg2){
    func_808006AC_badata(self, D_80802378_badata, assetId, arg2);
}

void badata_entrypoint_11(PlayerState *self, AssetId *assetId, f32 *arg2){
    func_808006AC_badata(self, D_80802258_badata, assetId, arg2);
}

void badata_entrypoint_12(PlayerState *self, s32 *arg1, f32 *arg2) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802498_badata[tmp_v0];
    *arg1  = tmp_v1->unk2;
    *arg2  = tmp_v1->unk8;
}

void badata_entrypoint_13(PlayerState *self, s32 *arg1, f32 *arg2) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802498_badata[tmp_v0];
    *arg1  = tmp_v1->unk0;
    *arg2  = tmp_v1->unk4;
}

s32 badata_entrypoint_14(PlayerState *self) {
    return D_80801640_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_15(PlayerState *self) {
    return D_80801664_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_16() {
    return 11;
}

s32 func_80800AA4_badata(PlayerState *self, BaData_5 *arg1, s32 index, s32 *arg3, f32 *arg4, s32 *arg5) {
    s32 max;
    s32 valid;
    s32 tmp_v0;

    valid = 1;
    tmp_v0 = func_80800000_badata(self);
    max = arg1[tmp_v0].count;
    if(index >= max) {
        index = 0;
        valid = 0;
    }
    *arg3 = arg1[tmp_v0].unk0[index].unk0;
    *arg4 = arg1[tmp_v0].unk0[index].unk4 + arg1[tmp_v0].unk8;
    *arg5 = arg1[tmp_v0].unk0[index].unk2;
    return valid;
}


void badata_entrypoint_17(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4) {
    func_80800AA4_badata(self, D_808010C8_badata, index, arg2, arg3, arg4);
}

f32 badata_entrypoint_18(PlayerState *self) {
    return D_808010C8_badata[func_80800000_badata(self)].unk8;
}

void badata_entrypoint_19(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4) {
    func_80800AA4_badata(self, D_80801298_badata, index, arg2, arg3, arg4);
}

s32 badata_entrypoint_20(PlayerState *self) {
    if (0.5f < func_800DC0C0()) {
        return D_80801568_badata[func_80800000_badata(self)].unk2;
    } else {
        return D_80801568_badata[func_80800000_badata(self)].unk4;
    }
}

s32 badata_entrypoint_21(PlayerState *self) {
    return D_80801A78_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_22(PlayerState *self) {
    return D_80801718_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_23(PlayerState *self) {
    return D_80802018_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_24(PlayerState *self) {
    return D_808014D8_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_25(PlayerState *self) {
    return D_80801520_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_26(PlayerState *self) {
    return D_80801568_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_27(PlayerState *self) {
    func_80800000_badata(self);
    return D_80801448_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_28(PlayerState *self) {
    return D_80801688_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_29(PlayerState *self) {
    return D_80802138_badata[func_80800000_badata(self)].unk0;
}


s32 badata_entrypoint_30(PlayerState *self, s32 arg1) {
    switch (arg1) {
        case 1:
            return 0x73;

        case 2:
            return 0x74;

        case 3:
            return 0x75;

        case 4:
            return 0x74;
    }
    return 0;
}

s32 badata_entrypoint_31(PlayerState *self) {
    return D_80802378_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_32(PlayerState *self) {
    return D_80802258_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_33(PlayerState *self) {
    switch (func_8009EA64()) {
        case 0x305:
            return 0x12A;

        case 0x171:
            return 0x7C;
        
        case 0x2A2:
            return 0x12B;
        
        case 0x38A:
            return 0xB7;
    }
    return 0xB7;
}

s32 badata_entrypoint_34(PlayerState *self) {
    return D_80801490_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_35(PlayerState *self) {
    return D_80801490_badata[func_80800388_badata(self)];
}
