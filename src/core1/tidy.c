#include "core1/tidy.h"

// tidy_thread_entry
void func_80013544(void*);

// do_tidy
void func_800A7FD4(void);

extern OSMesgQueue D_800769E0;
extern OSMesg D_800769F8;

extern OSMesgQueue D_80076A00;
extern OSMesg D_80076A18;

// tidy_thread
extern OSThread D_80076A20;
// TODO this only 0x10 bytes, so it's a different struct. Same deal as the joy thread.
extern __OSThreadOddFpStorage D_80076BD0;
// tidy_thread_stack
extern u64 D_80076BE0[TIDY_THREAD_STACK_SIZE64];
// is_tidying (or maybe the getter should be named that)
extern s32 D_800773E0;

// create_tidy_thread
void func_800133A0(void) {
    osCreateMesgQueue(&D_800769E0, &D_800769F8, 1);
    osCreateMesgQueue(&D_80076A00, &D_80076A18, 1);
    func_8001DCB0(&D_80076A20, &D_80076BD0, THREAD_ID_TIDY, func_80013544, NULL, &D_80076BE0[TIDY_THREAD_STACK_SIZE64], TIDY_THREAD_PRIORITY);
    osStartThread(&D_80076A20);
    D_800773E0 = 0;
}

// destroy_tidy_thread
void func_80013430(void) {
    osStopThread(&D_80076A20);
    osDestroyThread(&D_80076A20);
}

s32 func_80013460(void) {
    return MQ_GET_COUNT(&D_800769E0) < 1u;
}

s32 func_80013474(void) {
    return MQ_GET_COUNT(&D_80076A00) < 1u;
}

void func_80013488(void) {
    if (func_80012530() == 1) {
        osSendMesg(&D_800769E0, NULL, OS_MESG_BLOCK);
    }
}

void func_800134C4(void) {
    if (func_80012530() == 1) {
        osSendMesg(&D_80076A00, NULL, OS_MESG_BLOCK);
    }
}

void func_80013500(OSPri pri) {
    if (func_80012530() == 1) {
        osSetThreadPri(&D_80076A20, pri);
    }
}

s32 func_80013538(void) {
    return D_800773E0;
}

// tidy_thread_entry
void func_80013544(void *arg) {
    s32 i;
    while (TRUE) {
        osRecvMesg(&D_800769E0, NULL, OS_MESG_BLOCK);
        D_800773E0 = 1;
        for (i = 0; i < 2 && MQ_GET_COUNT(&D_80076A00) == 0; i++) {
            func_800A7FD4();
        }
        D_800773E0 = 0;
        osRecvMesg(&D_80076A00, NULL, OS_MESG_BLOCK);
    }
} 
