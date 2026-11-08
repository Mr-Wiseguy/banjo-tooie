#include "ba/deathmatch.h"

void badeathmatch_entrypoint_8(PlayerState* self, f32 arg1);
extern u8 D_80800550_badeathmatch[];

void func_80800000_badeathmatch(PlayerState* self)
{
    self->deathmatch->unk20 = 1;
    self->deathmatch->unk21 = 0;
    self->deathmatch->unk22 = 0;
    self->deathmatch->unk23 = 0;
}

u8 func_80800028_badeathmatch(s32 arg0) {
    return D_80800550_badeathmatch[arg0 - 1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_0.s")

void badeathmatch_entrypoint_1(PlayerState* self)
{
    BaDeathmatch* temp_v0;

    if (func_800EA068(0x40) != 0)
    {
        temp_v0 = heap_alloc(0x30);
        self->deathmatch = temp_v0;
        aligned8_memset(temp_v0, 0U, 0x30);
        func_80800000_badeathmatch(self);
    }
}

void badeathmatch_entrypoint_2(PlayerState* self)
{
    if (self->deathmatch != NULL)
    {
        heap_free(self->deathmatch);
        self->deathmatch = NULL;
        func_800C968C(func_800A4C68(self), 9);
    }
}

void badeathmatch_entrypoint_3(PlayerState* self)
{
    if ((player_getTransformation(self) != TRANSFORM_11_CLOCKWORK) && (bs_getCurrentState(self) != 0xD7))
    {
        if (self->deathmatch->unk21 == 0)
        {
            if (((!self->deathmatch->unk23) & 1) && (bainput_func_80097D28(self) != 0))
            {
                badeathmatch_entrypoint_0(self);
            }
        }
        else if ((self->deathmatch->unk22 != 0) && (_batimer_decrement(self, 0xD) != 0))
        {
            badeathmatch_entrypoint_8(self, 0.0f);
        }
    }
}

s32 badeathmatch_entrypoint_4(s32 arg0)
{
    switch (arg0)
    {
    case 0x40:
        return 1;
    case 0x41:
        return 2;
    case 0x42:
        return 3;
    case 0x43:
        return 4;
    case 0x44:
        return 5;
    case 0x45:
        return 6;
    default:
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_5.s")

int badeathmatch_entrypoint_6(PlayerState* self)
{
    return self->deathmatch->unk21 ? 7 : self->deathmatch->unk20;
}

void badeathmatch_entrypoint_7(PlayerState* self, s32 arg1)
{
    self->deathmatch->unk20 = arg1;
}

void badeathmatch_entrypoint_8(PlayerState* self, f32 arg1)
{
    if (arg1 != 0.0f)
    {
        self->deathmatch->unk21 = 1;
    }
    else
    {
        self->deathmatch->unk21 = 0;
    }
    if (arg1 > 0.0f)
    {
        self->deathmatch->unk22 = 1;
    }
    else
    {
        self->deathmatch->unk22 = 0;
    }
    _batimer_set(self, 0xD, arg1);
    if (self->deathmatch->unk21 == 0)
    {
        event_sendToActorsOfType(0x1CD, 0x76, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_9.s")

void badeathmatch_entrypoint_10(PlayerState* self, s32 arg1, s32 arg2, s32 arg3)
{
    self->deathmatch->unk0[arg1 + 8] = arg2;
    self->deathmatch->unk0[arg1] = arg3;
}

void badeathmatch_entrypoint_11(PlayerState* self, s32 arg1, s32 arg2)
{
    if (arg2 != 0)
    {
        self->deathmatch->unk23 = (self->deathmatch->unk23 | arg1);
        return;
    }
    self->deathmatch->unk23 = (self->deathmatch->unk23 & ~arg1);
}
