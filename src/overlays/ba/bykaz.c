#include "ba/bykaz.h"

s32 bababykaz_entrypoint_0(void) {
    return sizeof(BaBabyKaz);
}

void bababykaz_entrypoint_1(PlayerState *self) {
    if ((player_getTransformation(self) == TRANSFORM_11_CLOCKWORK) && !func_800EA068(0x20)) {
        func_8009EA94(self->babykaz->unk4);
    }
}

void bababykaz_entrypoint_2(PlayerState *self) {
    if(!func_800EA068(0x20)) {
        self->babykaz->unk4 = func_8009EA14();
    } else {
        self->babykaz->unk4 = 0.0f;
    }
    self->babykaz->unk0 = 0;
    self->babykaz->unk1 = 0;
}

s32 bababykaz_entrypoint_3(PlayerState *self) {
    return self->babykaz->unk1;
}

s32 bababykaz_entrypoint_4(PlayerState *self) {
    return self->babykaz->unk0;
}

s32 bababykaz_entrypoint_5(PlayerState *self) {
    TransformationId sp24 = (bs_getSplitStatus() == SPLIT_STATE_SPLIT) ? TRANSFORM_B_KAZOOIE : TRANSFORM_1_BK;
    s32 pad0;

    if(func_800F8A5C(sp24) != map_getCurrent()) {
        return -1;
    } else {
        return _character_findCharOfTransform(sp24);
    }
}

void bababykaz_entrypoint_6(PlayerState *self){
    _batimer_set(self, 0xC, ml_map_f(self->babykaz->unk4, 0.0f, 20.0f, 0.0f, 20.0f));

}

void bababykaz_entrypoint_7(PlayerState *self, s32 arg1) {
    self->babykaz->unk1 = arg1;
}

void bababykaz_entrypoint_8(PlayerState *self) {
    self->babykaz->unk4 = 20.0f;
    if (func_800EA068(0x800)) {
        func_800FC660(0x68);
    } else {
        func_800C77DC(4);
    }
}

void bababykaz_entrypoint_9(PlayerState *self) {
    if (!func_800EA068(0x800)) {
        func_800C77DC(1);
    }
}

void bababykaz_entrypoint_10(PlayerState *self, s32 arg1) {
    self->babykaz->unk0 = arg1;
}


void bababykaz_entrypoint_11(PlayerState *self) {
    f32 tmp_f0;
    s32 tmp0;
    s32 pad;
    s32 sp38;
    s32 sp28;

    sp38 = !(func_8008E124(self) || func_800C954C()  || func_800F8004(self->unk184) || func_800F99E8() || func_800F68B8(self->unk184));
    sp28 = (sp38 && !(func_800C0638() || func_800D3948())
    );
    if (sp38 && _batimer_decrement(self, 0xC)) {
        self->babykaz->unk1 = 1;
    }
    tmp_f0 = _batimer_get(self, 0xC);
    tmp0 = ml_map_f(tmp_f0, 0.0f, 20.0f, 1.0f, 21.0f) - 0.0001f;
    self->babykaz->unk4 = ml_max_f(0.0f, (f32)tmp0);

    if (sp28) {
        func_800D2498(0xC9, (s32)self->babykaz->unk4, 0);
    }


    if (player_inWater(self)) {
        if (40.0f < (player_getWaterHeight(self) - player_getCoordVertical(self))) {
            self->babykaz->unk1 = 1;
        }
    }
}

s32 bababykaz_entrypoint_12(PlayerState *self) {
    return (s32)self->babykaz->unk4;
}

void bababykaz_entrypoint_13(PlayerState *self) {
    baflag_set(self, 0x34);
    bastick_func_8009F198(self, 1);
    bakey_func_80091C74(self, 1);
}

void bababykaz_entrypoint_14(PlayerState *self) {
    baflag_clear(self, 0x34);
    bastick_func_8009F198(self, 0);
    bakey_func_80091C74(self, 0);
}
