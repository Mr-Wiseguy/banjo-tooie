#include "common.h"
#include "core1/1E2A0E0.h"

extern s16 D_8006A1CE;
extern void* D_80076958;
extern s32 D_8003CC70;
extern void* D_80076978;
extern OSMesgQueue D_800769B8;
extern s32 D_8003CC64;
extern s16 D_8006A1CC;
extern s32 D_8003CA40;
extern OSThread D_800459F8;
extern s32 D_80046A78;
extern s32 D_80069488;
extern s32 D_80069568;
extern s32 D_80045BB8;
extern s32 D_8007695C;
extern s32 D_80076940;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_800125B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_8001268C.s")

// audio_thread_entry
#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_800128C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_800129FC.s")

void func_80012B74(s32 arg0) {
    int new_var;
    new_var = 0;
    if (((osAiGetLength() >> 2) == new_var) && (D_8003CC64 == new_var)) {
        D_8003CC64 = new_var;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_80012BB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_80012D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_80012D84.s")

void func_80012EA0(void) {
    if (D_8003CA40 == 0) {
        D_8003CA40 = 1;
        osStartThread(&D_800459F8);
    }
}

s32* func_80012EDC(void) {
    return &D_80046A78;
}

s32* func_80012EE8(void) {
    return &D_80069488;
}

s32* func_80012EF4(void) {
    return &D_80069568;
}

s32* func_80012F00(void) {
    return &D_80045BB8;
}

void func_80012F0C(s32 arg0) {
    D_8006A1CC = arg0;
    func_80021A00(arg0 & 0xFF);
}

void func_80012F34(s32 arg0, s32 arg1) {
    *(&D_8006A1CE + arg0) = arg1;
    func_80021AD0();
}

s32* func_80012F60(void) {
    return &D_8007695C;
}

s32* func_80012F6C(void) {
    return &D_80076940;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/rom_dma_read.s")

void func_8001311C(void* arg0, u32 arg1) {
    osWritebackDCache(arg0, 0x1800);
    D_8003CC70 += 1;
    osPiStartDma((OSIoMesg* ) &D_80076940, 0, 0, arg1, arg0, 0x1800U, (OSMesgQueue* ) &D_8007695C);
    osRecvMesg((OSMesgQueue* ) &D_8007695C, NULL, 1);
    D_8003CC70 -= 1;
    osInvalDCache(arg0, 0x1800);
}

void func_800131C0(void) {
    osCreateMesgQueue((OSMesgQueue* ) &D_8007695C, &D_80076958, 1);
    osCreateMesgQueue(&D_800769B8, &D_80076978, 0x10);
    osCreatePiManager(0x96, &D_800769B8, &D_80076978, 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_80013224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_800132BC.s")

void func_80013324()
{
    func_80013224();
    func_800132BC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_8001334C.s")
