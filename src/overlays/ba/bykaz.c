#include "common.h"

#include "overlays/ba/babykaz.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/key.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/timer.h"
#include "core2/1E66990.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E78170.h"
#include "core2/1E7BFA0.h"
#include "core2/1EA0AA0.h"
#include "core2/1ECA640.h"
#include "core2/1ED4E30.h"
#include "core2/1E99980.h"

s32 bababykaz_entrypoint_0(void) {
    return sizeof(BaBabyKaz);
}

void bababykaz_entrypoint_1(PlayerState *self) {
    if ((func_800A3274(self) == 0x11) && !func_800EA068(0x20)) {
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
    s32 sp24 = (func_800F8B88() == 2) ? 0xB : 0x1;
    s32 pad0;

    if(func_800F8A5C(sp24) != func_800EA05C()) {
        return -1;
    } else {
        return _plsu_entrypoint_1(sp24);
    }
}

void bababykaz_entrypoint_6(PlayerState *self){
    _batimer_set(self, 0xC, func_800F10B4(self->babykaz->unk4, 0.0f, 20.0f, 0.0f, 20.0f));

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
    tmp0 = func_800F10B4(tmp_f0, 0.0f, 20.0f, 1.0f, 21.0f) - 0.0001f;
    self->babykaz->unk4 = func_800F0E00(0.0f, (f32)tmp0);

    if (sp28) {
        func_800D2498(0xC9, (s32)self->babykaz->unk4, 0);
    }


    if (player_inWater(self)) {
        if (40.0f < (func_800964DC(self) - func_8009C150(self))) {
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
