#include "core2/1EB2840.h"

extern u32 D_8012C764;
extern f32 D_8012C760;
extern f32 D_80125D10;
extern f32 D_80125D14;
extern f32 D_80125D18;
extern f32 D_80125D1C;

void func_800D8F50(f32 arg0)
{
    if (arg0 < 0.050000004f)
    {
        D_8012C760 = arg0;
        return;
    }
    D_8012C760 = 0.050000004f;
}

void func_800D8F84(void) {
    D_8012C760 = 0.01f;
    D_8012C764 = 0;
}

void func_800D8FA0(s32 arg0)
{
    D_8012C764 = ml_clamp_i(arg0, 1, 0xF);
    func_800D8F50((s32)D_8012C764 * 0.016666668f);
}

s32 func_800D8FEC()
{
	return D_8012C764;
}
//Get Gamespeed
f32 time_getDelta()
{
	return D_8012C760;
}

f32 func_800D9004(void)
{
    return (s32)D_8012C764 * 0.016666668f;
}

f32 func_800D902C(void) {
    return time_getDelta() * 30.0f;
}

s32 func_800D9058(f32 arg0)
{
    return (s32)(arg0 * 30.0f);
}

s32 timer_reachedZero(f32* timer)
{
    return ml_timer_update(timer, time_getDelta());
}

s32 timer_reachedZero_dupe(f32* timer)
{
    if (*timer > 0.0f)
    {
        return ml_timer_update(timer, time_getDelta());
    }
    *timer = 0.0f;
    return TRUE;
}

s32 timer_reachedValueDec(f32* timer, f32 arg1)
{
    *timer -= time_getDelta();
    if (*timer < arg1)
    {
        *timer = arg1;
        return TRUE;
    }
    return FALSE;
}

s32 func_800D9154(f32* timer, f32 arg1)
{

    *timer -= time_getDelta();
    if (*timer < 0.0f)
    {
        *timer = *timer + arg1;
        return TRUE;
    }
    return FALSE;
}

f32 timer_countUp(f32* timer)
{
    *timer += time_getDelta();
    return *timer;
}

s32 timer_reachedValueInc(f32* timer, f32 timerLength)
{
    if (timerLength < timer_countUp(timer))
    {
        *timer = timerLength;
        return TRUE;
    }
    return FALSE;
}