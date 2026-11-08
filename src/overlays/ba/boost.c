#include "ba/boost.h"

s32 baboost_entrypoint_0(void) {
    return sizeof(BaBoost);
}

s32 baboost_entrypoint_1(PlayerState* self)
{
    s32 index;
    s32 count;

    count = 0;
    for (index = 0; index < 5; index++)
    {
        if(self->boost->unk8[index] != 0.0f)
        {
            count++;
        }
    }
    return count;
}

s32 baboost_entrypoint_2(PlayerState* self, f32 arg1)
{
    s32 index;

    for (index = 0; index < 5; index++)
    {
        if ((arg1 - 0.25f) < self->boost->unk8[index]) {
            self->boost->unk4 = arg1;
            return 0;
        }
    }
    for (index = 0; index < 5; index++)
    {
        if (self->boost->unk8[index] == 0.0f) {
            self->boost->unk8[index] = arg1;
            return 1;
        }
    }
    self->boost->unk4 = arg1;
    return 0;
}

void baboost_entrypoint_3(PlayerState *self)
{
    s32 index;

    for (index = 0; index < ARRLEN(self->boost->unk8); index++)
    {
        self->boost->unk8[index] = 0;
        // coOKed
        self->boost->unk8[index] = self->boost->unk8[index];
    }
    self->boost->unk4 = 0.f;
    self->boost->unk0 = self->boost->unk4;
}

void baboost_entrypoint_4(PlayerState *self, s32 arg1) {
    self->boost->unk0 = arg1;
    if(self->boost->unk0 == 0) {
        _baboost_entrypoint_3(self);
    }
} 

void baboost_entrypoint_5(PlayerState *self) {
    s32 index;
    f32 prev_unk4;

    if (self->boost->unk0){
        for (index = 0; index < 5; index++) {
            timer_reachedZero(&self->boost->unk8[index]);
        }
        if (self->boost->unk4 != 0.0f) {
            prev_unk4 = self->boost->unk4;
            self->boost->unk4 = 0.0f;
            baboost_entrypoint_2(self, prev_unk4);
        }
    }
}
