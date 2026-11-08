#include "core2/1ECD070.h"

void func_800F3780(f32 arg0, Vec2f* arg1, s16 arg2) {
    s32 lo;
    s32 hi;
    s32 mid;
    Vec2f* new_var;
    s32 next;
    s32 temp;

    hi = (temp = (arg2 - 1) ^ 0);
    lo = 0;
    if (arg0 < arg1[0].x) {
        lo = temp;
        hi = 0;
    } else if (((arg1 + arg2) - 1)->x < arg0) {
        lo = temp;
        hi = 0;
    } else if ((hi | 0) >= 2) {
        do {
            mid = (hi - lo) / 2 + lo;
            if ((new_var = mid + arg1)->x <= arg0) {
                lo = mid;
                next = mid + 1;
            } else {
                hi = mid;
                next = lo + 1;
            }
        } while (next < hi);
    }
    ml_map_f(arg0, (lo + arg1)->x, (hi + arg1)->x, (lo + arg1)->y, (hi + arg1)->y);
}
