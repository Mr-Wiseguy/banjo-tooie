#include "core2/1E83680.h"

s32 func_800A9D90(s32 arg0) 
{
    if (has_free_block_after(arg0) == 0) {
        func_8008160C(2);
    }
    if (has_free_block_after(arg0) == 0) {
        func_800BFCC4(2);
        func_800D6E54(2);
    }
    if (has_free_block_after(arg0) == 0) {
        func_8008B6E0();
    }
    if (has_free_block_after(arg0) == 0) {
        func_800FFD10(2);
    }
    if (has_free_block_after(arg0) == 0) {
        func_80100670();
    }
    if (has_free_block_after(arg0) != 0) {
        return 1;
    }
    func_800D58CC();
    func_800A8168();
    if (has_free_block_after(arg0) == 0) {
        func_800BFCC4(3);
        func_800D6E54(3);
    }
    if (has_free_block_after(arg0) == 0) {
        func_800FFD10(2);
    }
    if (has_free_block_after(arg0) == 0) {
        func_800B59E0();
    }
    if (has_free_block_after(arg0) != 0) {
        return 1;
    }
    return 0;
}
