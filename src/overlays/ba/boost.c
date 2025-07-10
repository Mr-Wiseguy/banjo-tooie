#include "common.h"

#include "overlays/ba/boost.h"

s32 baboost_entrypoint_0(void) {
    return sizeof(BaBoost);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/boost/baboost_entrypoint_1.s")

s32 baboost_entrypoint_2(PlayerState *self, f32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/boost/baboost_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/boost/baboost_entrypoint_3.s")

void baboost_entrypoint_4(PlayerState *self, s32 arg1) {
    self->boost->unk0 = arg1;
    if(self->boost->unk0 == 0) {
        _baboost_entrypoint_3(self);
    }
} 

void baboost_entrypoint_5(PlayerState *self) {
    s32 i;
    f32 tmp_f2;
    if (self->boost->unk0){
        for ( i = 0; i < 5; i++) {
            func_800D9078(&self->boost->unk8[i]);
        }
        if (self->boost->unk4 != 0.0f) {
            tmp_f2 = self->boost->unk4;
            self->boost->unk4 = 0.0f;
            baboost_entrypoint_2(self, tmp_f2);
        }
    }
}
