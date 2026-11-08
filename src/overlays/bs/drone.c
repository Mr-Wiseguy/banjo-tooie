#include "bs/drone.h"
typedef struct unkbsdrone {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    void* (*unk4)(PlayerState*);
    void* (*unk8)(PlayerState*);
    void* (*unkC)(PlayerState*);
    void* (*unk10)(PlayerState*);
} UNKBSDRONE;
extern UNKBSDRONE D_80800180_bsdrone[];

s32 func_80800000_bsdrone(PlayerState* self)
{
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = _badrone_entrypoint_3(self);
    var_a1 = 0;
    while (D_80800180_bsdrone[var_a1].unk0 != 0)
    {
        if (D_80800180_bsdrone[var_a1].unk0 == temp_v0)
            return var_a1;
        var_a1++;
    }
    return 0;
}

void bsdrone_entrypoint_0(PlayerState* self)
{
    _badrone_entrypoint_4(self);
    D_80800180_bsdrone[func_80800000_bsdrone(self)].unk4(self);
}

void bsdrone_entrypoint_1(PlayerState* self)
{
    D_80800180_bsdrone[func_80800000_bsdrone(self)].unk8(self);
}

void bsdrone_entrypoint_2(PlayerState* self)
{
    D_80800180_bsdrone[func_80800000_bsdrone(self)].unkC(self);
}

void bsdrone_entrypoint_3(PlayerState* self)
{
    void* (*temp_v1)(PlayerState*);

    temp_v1 = D_80800180_bsdrone[func_80800000_bsdrone(self)].unk10;
    if (temp_v1 != NULL) {
        temp_v1(self);
    }
}