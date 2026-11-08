#include "core2/1E75920.h"

s32 func_8009C030() 
{
    return sizeof(PositionInfo);
}

//Clear Position History
void func_8009C038(PlayerState* self)
{
    ml_vec3f_clear(self->posInfo->unk24);
    ml_vec3f_clear(self->posInfo->current);
    ml_vec3f_clear(self->posInfo->oldPos);
    ml_vec3f_clear(self->posInfo->olderPos);
}

void func_8009C08C(PlayerState* self)
{
    func_8009C21C(self);
    ml_vec3f_clear(self->posInfo->unk24);
}

void func_8009C0BC(PlayerState* self, f32* src)
{
    ml_vec3f_copy(self->posInfo->current, src);
    ml_vec3f_copy(self->posInfo->oldPos, src);
}

void player_setCoords(PlayerState* self, f32* src)
{
    ml_vec3f_copy(self->posInfo->current, src);
}

void player_setCoordVertical(PlayerState* self, f32 src)
{
    self->posInfo->current[1] = src;
}

void player_getCoords(PlayerState* self, f32* dst) {
    ml_vec3f_copy(dst, self->posInfo->current);
}

f32 player_getCoordVertical(PlayerState* self)
{
    return self->posInfo->current[1];
}

void func_8009C15C(PlayerState* self, f32* dst) { ml_vec3f_copy(dst, self->posInfo->oldPos); }

void func_8009C188(PlayerState* self, f32* dst)
{
    ml_vec3f_copy(dst, self->posInfo->olderPos);
}

void func_8009C1B4(PlayerState* self, f32 src)
{
    self->posInfo->current[1] += src;
}

void func_8009C1CC(PlayerState* self, f32* dst)
{
    ml_vec3f_copy(dst, self->posInfo->unk24);
}

void func_8009C1F8(PlayerState* self, f32* src)
{
    ml_vec3f_copy(self->posInfo->unk24, src);
}

void func_8009C21C(PlayerState* self)
{
    ml_vec3f_copy(self->posInfo->olderPos, self->posInfo->oldPos);
    ml_vec3f_copy(self->posInfo->oldPos, self->posInfo->current);
}

void func_8009C25C(PlayerState* self)
{
    ml_vec3f_add(self->posInfo->current, self->posInfo->unk24);
    ml_vec3f_clear(self->posInfo->unk24);
}
