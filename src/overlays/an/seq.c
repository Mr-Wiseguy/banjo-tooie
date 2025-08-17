#include "seq.h"

void anseq_entrypoint_1(s16 * pSeqIndx, s32 arg1);

typedef struct{
    f32 duration;
    u8 argCount;
    u8 unk5;
    u8 unk6;
    u8 pad7[1];
    s32 arg0;
    s32 arg1;
    s32 arg2;
    s32 arg3;
    void *func_ptr; //function_ptr
} AnSeqElement;

struct {
    s32 unk0;
    AnSeqElement *unk4;
} B_80800490_anseq;

void func_80800000_anseq(s16 *pSeqIndx, AnSeqElement *element) {
    if (element->unk6) {
        if (element->unk6 == 0xFF) {
            return;
        }
    
        element->unk6--;
        if (element->unk6) {
            return;
        }

        element->unk6 = 0xFF;
    }

     switch(element->argCount) {
        case 0:// 80288BF8
            ((void (*)(void)) element->func_ptr)();
            break;
        case 1:// 80288C0C
            ((void (*)(s32)) element->func_ptr)(element->arg0);
            break;
        case 2:// 80288C24
            ((void (*)(s32, s32)) element->func_ptr)(element->arg0, element->arg1);
            break;
        case 3:// 80288C40
            ((void (*)(s32, s32, s32)) element->func_ptr)(element->arg0, element->arg1, element->arg2);
            break;
        case 4:
            ((void (*)(s32, s32, s32, s32)) element->func_ptr)(element->arg0, element->arg1, element->arg2, element->arg3);
            break;
        case 5:// 80288C5C
            ((void (*)(void*)) element->func_ptr)((void*)&element->arg0);
            break;
     }
}

void anseq_entrypoint_0(s16 *pSeqIndx) {
    vector_clear(func_800B2890(*pSeqIndx));
}

void* func_80800134_anseq(s16 *pSeqIndx, f32 duration, s32 arg_count, void * func_ptr, s32 a0, s32 a1, s32 a2, s32 a3){
    AnSeqElement *v0 = func_800B2A58(*pSeqIndx);
    v0->duration = duration;
    v0->argCount = arg_count;
    v0->func_ptr = func_ptr;
    v0->arg0 = a0;
    v0->arg1 = a1;
    v0->arg2 = a2;
    v0->arg3 = a3;
    v0->unk6 = B_80800490_anseq.unk0;
    if (duration == -1) {
        anseq_entrypoint_1(pSeqIndx, 1);
    } else {
        v0->unk5 = 0;
    }
    B_80800490_anseq.unk0 = 0;
    B_80800490_anseq.unk4 = v0;
    return v0;
}

void anseq_entrypoint_1(s16 * pSeqIndx, s32 arg1) {
    B_80800490_anseq.unk4->unk5 = arg1;
}

void anseq_entrypoint_2(s16 *pSeqIndx, f32 duration, void *func_ptr, s32 arg3, s32 arg4) {
    func_80800134_anseq(pSeqIndx, duration, 2, func_ptr, arg3, arg4, NULL, NULL);
}

void anseq_entrypoint_3(s16 *pSeqIndx, f32 duration, void *func_ptr, s32 arg3, s32 arg4, s32 arg5) {
    func_80800134_anseq(pSeqIndx, duration, 3, func_ptr, arg3, arg4, arg5, NULL);
}

void anseq_entrypoint_4(s16 *pSeqIndx, f32 duration, void *func_ptr, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_80800134_anseq(pSeqIndx, duration, 4, func_ptr, arg3, arg4, arg5, arg6);
}

void anseq_entrypoint_5(s16 arg0) {
    s16* v0 = (s16 *) func_8001B798(arg0);
    func_800B2D48(*v0);
    func_8001B754(arg0);
}

s16 anseq_entrypoint_6(void) {
    s16* sp1C;
    s16 sp18 = func_8001B668(0, 2);
    sp1C = (s16 *) func_8001B798(sp18);
    *sp1C = func_800B2DC0(sizeof(AnSeqElement), 0x2); //vector_new
    anseq_entrypoint_0(sp1C);
    return sp18;
}

void anseq_entrypoint_7(s16 *pSeqIndx, s32 arg1) {
    B_80800490_anseq.unk0 = arg1;
}

void anseq_entrypoint_8(s16 *pSeqIndx, AnimCtrl *pAnCtl) {
    void* s0 = func_800B2890(*pSeqIndx);
    AnSeqElement *iPtr;
    for (iPtr = vector_begin(s0); iPtr != (void*)vector_end(s0); iPtr++) {
        if ((iPtr->duration == -1.0f) || anctrl_isAt(pAnCtl, iPtr->duration)) {
            func_80800000_anseq(pSeqIndx, iPtr);
        }
    }
}

void anseq_entrypoint_9(s16 arg0){
    func_8001B798(arg0);
}
