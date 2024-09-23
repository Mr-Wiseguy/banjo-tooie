#ifndef __THREADS_H__
#define __THREADS_H__

#include <ultra64.h>

enum {
    THREAD_ID_VI,
    THREAD_ID_IDLE,
    THREAD_ID_TIDY,
    THREAD_ID_CIC6105,
    THREAD_ID_AUDIO,
    THREAD_ID_SCHEDULER,
    THREAD_ID_MAIN,
    THREAD_ID_JOY,
    THREAD_ID_MOTOR,
    THREAD_ID_CRASH
};

// create_thread
void func_8001DCB0(OSThread* t, __OSThreadOddFpStorage* fp_storage, s32 id, void (*entry)(void*), void* arg, void* sp, OSPri p);
// create_thread_with_odd_floats
void func_8001DD28(OSThread* t, __OSThreadOddFpStorage* fp_storage, s32 id, void (*entry)(void*), void* arg, void* sp, OSPri p);

#define IDLE_THREAD_STACK_SIZE 0x200
#define IDLE_THREAD_STACK_SIZE64 ((IDLE_THREAD_STACK_SIZE) / sizeof(u64))
#define IDLE_THREAD_PRIORITY OS_PRIORITY_IDLE

#define TIDY_THREAD_STACK_SIZE 0x800
#define TIDY_THREAD_STACK_SIZE64 ((TIDY_THREAD_STACK_SIZE) / sizeof(u64))
#define TIDY_THREAD_PRIORITY 10

#define SCHEDULER_THREAD_STACK_SIZE 0x800
#define SCHEDULER_THREAD_STACK_SIZE64 ((SCHEDULER_THREAD_STACK_SIZE) / sizeof(u64))
#define SCHEDULER_THREAD_PRIORITY 60

#define JOY_THREAD_STACK_SIZE 0x200
#define JOY_THREAD_STACK_SIZE64 ((JOY_THREAD_STACK_SIZE) / sizeof(u64))
#define JOY_THREAD_PRI 40

#endif
