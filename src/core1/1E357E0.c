#include "core1/1E357E0.h"

extern OSThread* D_8007D820[];

void func_8001DCB0(OSThread* t, __OSThreadOddFpStorage* fp_storage, s32 id, void (*entry)(void*), void* arg, void* sp, OSPri p) {
    osCreateThread(t, id, entry, arg, sp, p);
    t->odd_float_save = fp_storage;
    if (fp_storage != NULL) {
        fp_storage->unk4 = fp_storage->unk8 = fp_storage->unkC = 0;
    }
    D_8007D820[id] = t;
}

void func_8001DD28(OSThread* t, __OSThreadOddFpStorage* fp_storage, s32 id, void (*entry)(void*), void* arg, void* sp, OSPri p) {
    osCreateThread(t, id, entry, arg, sp, p);
    t->odd_float_save = fp_storage;
    if (fp_storage != NULL) {
        fp_storage->unkC = 1;
        fp_storage->unk4 = fp_storage->unk8 = 0;
    }
    D_8007D820[id] = t;
}

// get_thread
OSThread* func_8001DDA4(s32 id) {
    return D_8007D820[id];
}
