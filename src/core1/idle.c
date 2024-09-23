#include <ultra64.h>
#include "threads.h"

void func_800131C0(void);
void func_80012548(void);
OSThread* func_80012598(void);

// idle_thread_stack
extern u64 D_800773F0[IDLE_THREAD_STACK_SIZE64];
// idle_thread
extern OSThread D_800775F0;
// TODO this only 0x10 bytes, so it's a different struct. Same deal as the joy thread.
extern __OSThreadOddFpStorage D_800777A0;

// idle_thread_entry
void func_80013678(void*);

// create_idle_thread
void func_80013620(void) {
    func_8001DCB0(&D_800775F0, &D_800777A0, THREAD_ID_IDLE, func_80013678, NULL, &D_800773F0[IDLE_THREAD_STACK_SIZE64], IDLE_THREAD_PRIORITY);
    osStartThread(&D_800775F0);
}

// idle_thread_entry
void func_80013678(void* arg) {
    func_800131C0();
    func_80012548();
    osStartThread(func_80012598());
    while (TRUE) {

    }
}
