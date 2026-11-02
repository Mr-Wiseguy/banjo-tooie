#include "ba/move/hover.h"

void bamovehover_entrypoint_0(s32 arg0) {}

void bamovehover_entrypoint_1(PlayerState* self) {
    ml_vec3f_clear(self->unkC8->unkAC);
    ml_vec3f_clear(self->unkC8->unkB8);
    ml_vec3f_assign_value(self->unkC8->unk10, 16.666668f, 33.333336f, 50.0f);
}

void bamovehover_entrypoint_2(PlayerState* self)
{
    f32 gameSpeed;
    f32 sp80[3];
    f32 temp_f0_2;
    f32 temp_f20;
    s32 var_s1;
    s32 pad;

    gameSpeed = time_getDelta();
    func_800EF174(self->unkC8->unkAC, self->unkC8->unkB8, gameSpeed);

    for (var_s1 = 0; var_s1 < 3; var_s1++)
    {
        temp_f20 = self->unkC8->unkAC[var_s1] - self->unkC8->unk4[var_s1];
        temp_f0_2 = mlAbsF(temp_f20);
        if (temp_f0_2 > 5.0f)
        {
            temp_f0_2 = ml_map_f(temp_f0_2, 5.0f, 40.0f, 50.0f, 150.0f);
            if (temp_f20 > 0.0f)
            {
                sp80[var_s1] = temp_f0_2;
            }
            else
            {
                sp80[var_s1] = -temp_f0_2;
            }
            self->unkC8->unk10[var_s1] = func_800F15F8(self->unkC8->unk10[var_s1], sp80[var_s1], 220.0f * gameSpeed);
        }
    }
    func_800EF174(self->unkC8->unk4, self->unkC8->unk10, gameSpeed);
}

void bamovehover_entrypoint_3(PlayerState* self, f32* arg1)
{
    ml_vec3f_copy(self->unkC8->unkAC, arg1);
}

void bamovehover_entrypoint_4(PlayerState* self, f32* arg1)
{
    if (arg1 == NULL)
    {
        ml_vec3f_clear(self->unkC8->unkB8);
        return;
    }
    ml_vec3f_copy(self->unkC8->unkB8, arg1);
}
