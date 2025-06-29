#include "common.h"

#include "overlays/ba/cough.h"

#include "core2/1E76CC0.h"
#include "core2/1E7BFA0.h"
#include "core2/1EB5980.h"

s32 bacough_entrypoint_0(void) {
    return sizeof(BaCough);
}

s32 bacough_entrypoint_1(PlayerState *self) {
    return self->cough->unk0;
}

void bacough_entrypoint_2(PlayerState *self) {
    bacough_entrypoint_4(self, 0);
}

void bacough_entrypoint_3(PlayerState *self) {
    self->cough->unk0 = 0;
    bacough_entrypoint_4(self, 1);
}

void bacough_entrypoint_4(PlayerState *self, s32 arg1) {
    switch (arg1) {
        case 1:
            func_8009ADF0(self, 9, 0);
            break;

        case 2:
            self->cough->unk4 = 2.0f;
            func_8009ADF0(self, 9, 1);
            break;
    }
    self->cough->unk0 = arg1;
}

void bacough_entrypoint_5(PlayerState *self) {
    s32 sp24;
    f32 sp20;
    f32 sp1C;

    if ((self->cough->unk0 == 2)
        && func_800F424C(self)
        && func_800D9078(&self->cough->unk4)
    ){
        sp20 = func_800DC0C0();
        sp1C = func_800DC178(0.97f, 1.03f);
        switch (func_800A3274(self)) {
            case 1:
            case 0xA:
                if(sp20 < 0.3333f) {
                    sp24 = 0x571;
                } else if (0.6666f < sp20) {
                    sp24 = 0x572;
                } else {
                    sp24 = 0x573;
                }
                break;

            case 0xB:
                if (sp20 < 0.5f) {
                    sp24 = 0x45B;
                } else {
                    sp24 = 0x59F;
                }
                break;

            case 0xD:
                if (sp20  < 0.5f) {
                    sp24 = 0x50F;
                } else {
                    sp24 = 0x510;
                }
                break;
            default:
                sp24 = 0;
                break;
        }

        if (sp24 != 0) {
            func_8009DB04(self, sp24, sp1C, 24000);
        }
        
        if (func_800DC298(0.1f)) {
            self->cough->unk4 = func_800DC178(0.3f, 0.8f);
        } else if (func_800DC298(0.4f)) {
            self->cough->unk4 = func_800DC178(1.5f, 2.5f);
        } else {
            self->cough->unk4 = func_800DC178(3.5f, 4.5f);
        }
    }
}
