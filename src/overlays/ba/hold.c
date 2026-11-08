#include "ba/hold.h"

void bahold_entrypoint_7(PlayerState* self, f32 arg1, f32 arg2);

s32 bahold_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_bahold(PlayerState* self, s32 arg1) {
    s32 var_a2;

    self->hold->unk8 = arg1;
    if (arg1 != 0)
    {
        var_a2 = 1;
    }
    else
    {
        var_a2 = 0;
    }
    func_8009ADF0(self, 0xE, var_a2);
}
void bahold_entrypoint_1(PlayerState* self)
{
    func_80800008_bahold(self, NULL);
    self->hold->unkC = 0;
    bahold_entrypoint_7(self, 0.0f, 0.0f);
}

void bahold_entrypoint_2(PlayerState* self)
{
}
void func_80800088_bahold(Unk80132ED0* arg0, f32* arg1, f32* arg2)
{
    Actor* temp_v0;

    temp_v0 = func_80106790(arg0);
    if (temp_v0->unk64_23 > 0)
    {
        temp_v0->position[0] = arg1[0];
        temp_v0->position[1] = arg1[1];
        temp_v0->position[2] = arg1[2];
        temp_v0->rotation[1] = arg2[1];
    }
}

void func_808000E0_bahold(PlayerState* self) {
    f32 sp24[3];
    f32 sp18[3];

    func_8008FF40(sp18);
    func_80092D44(self, sp24);
    sp18[1] = ml_normalizeAngle_f(sp18[1] + self->hold->unk4);
    sp24[1] += self->hold->unk0;
    func_80800088_bahold(self->hold->unk8, sp24, &sp18);
}

void bahold_entrypoint_3(PlayerState* self)
{
    if (self->hold->unk8 != 0)
    {
        if (self->hold->unkC == 0)
        {
            func_80800008_bahold(self, NULL);
            return;
        }
        func_808000E0_bahold(self);
        self->hold->unkC = 0;
    }
}

void bahold_entrypoint_4(PlayerState* self)
{
    func_80800008_bahold(self,0);
}

s32 bahold_entrypoint_5(PlayerState* self) {
    return self->hold->unk8;
}

void bahold_entrypoint_6(PlayerState* self, s32 arg1) {
    func_80800008_bahold(self, arg1);
    func_808000E0_bahold(self);
    self->hold->unkC = 1;
}

void bahold_entrypoint_7(PlayerState* self, f32 arg1, f32 arg2) {
    self->hold->unk0 = arg1;
    self->hold->unk4 = arg2;
}
