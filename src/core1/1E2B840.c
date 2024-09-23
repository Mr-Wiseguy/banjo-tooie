#include "threads.h"
#include "types.h"
#include "buffers.h"

extern long long int n_aspMainTextStart[];
extern long long int n_aspMainDataStart[];

typedef enum task_type_e {
    TASK_TYPE_AUDIO,
    TASK_TYPE_GFX_3D,
    TASK_TYPE_GFX_LINE,
    TASK_TYPE_DISABLE_GFX = 7
} TaskType;

typedef struct {
    TaskType type;
} TaskHeader;

typedef struct {
    TaskHeader header;
    s32 unk4;
    Gfx* unk8;
    Gfx* unkC;
} GraphicsTask;

typedef struct {
    TaskHeader header;
    s32 unk4;
    Acmd* unk8;
    Acmd* unkC;
    OSMesgQueue* unk10;
    OSMesg unk14;
} AudioTask;

#define audioManager_getFrameMesgQueue func_80012F00
#define pfsManager_getStartReadData func_80016810
#define rumbleManager_80018634 func_80018634

OSMesgQueue* audioManager_getFrameMesgQueue(void);
void pfsManager_getStartReadData(void);
void rumbleManager_80018634(void);
void func_80014F64(OSMesgQueue* queue, OSMesg mesg);

#define SCHEDULER_EVENT_DP 4
#define SCHEDULER_EVENT_VI 5
#define SCHEDULER_EVENT_SP 6
#define SCHEDULER_EVENT_AUDIO_TIMER 8
#define SCHEDULER_EVENT_FAULT 10
#define SCHEDULER_EVENT_PRENMI 11
#define SCHEDULER_EVENT_CONT_TIMER 13

/* .data */
OSTask D_8003F3B0 = {
    M_AUDTASK,                /* type */
    0,                        /* flags */
    NULL, 0,                  /* ucode_boot */
    NULL, SP_UCODE_SIZE,      /* ucode */
    NULL, SP_UCODE_DATA_SIZE, /* ucode_data */
    NULL, 0,                  /* dram_stack */
    NULL, NULL,               /* output_buff */
    NULL, 0,                  /* data */
    NULL, 0,                  /* yield_data */
};

OSTask D_8003F3F0 = {
    M_GFXTASK,                       /* type */
    0,                               /* flags */
    NULL, 0,                         /* ucode_boot */
    NULL, SP_UCODE_SIZE,             /* ucode */
    NULL, SP_UCODE_DATA_SIZE,        /* ucode_data */
    D_80000400, SP_DRAM_STACK_SIZE8, /* dram_stack */
    D_80000800, &D_80000800[GFX_OUTPUT_BUFFER_SIZE64], /* output_buff */
    NULL, 0,                         /* data */
    NULL, OS_YIELD_DATA_SIZE,        /* yield_data */
};

/* .data continued later in file */

/* .bss */
extern u64 D_800777B0[OS_YIELD_DATA_SIZE / sizeof(u64)];
extern OSMesgQueue D_800783D0;
extern OSMesg      D_800783E8[20];
extern OSMesgQueue D_80078438;
extern OSMesg      D_80078450[10];
extern AudioTask *D_80078478;
extern s32 D_8007847C;
extern int D_80078480; // disable_graphics
extern s32 D_80078484;
extern s32 D_80078488;
extern s32 D_8007848C;
extern s32 D_80078490;
extern s32 D_80078494;
extern u64 D_80078498[SCHEDULER_THREAD_STACK_SIZE64]; //stack for thread D_80078C98;
extern OSThread D_80078C98;
extern GraphicsTask * D_80078E58[20];
extern volatile s32 D_80078EA8;
extern volatile s32 D_80078EAC;
extern AudioTask * D_80078EB0[20];
extern volatile s32 D_80078F00;
extern volatile s32 D_80078F04;
extern void* D_80078F08;
extern s32 D_80078F0C;
extern s32 D_80078F10;
extern s32 D_80078F14;
extern OSTimer D_80078F18; //audio_timer
extern OSTimer D_80078F38; //controller_timer
// TODO this only 0x10 bytes, so it's a different struct. Same deal as the joy thread.
extern __OSThreadOddFpStorage D_80078E48;
extern s32 D_80078F58;
extern s32 D_80078F5C;

void func_800140D8(GraphicsTask *arg0);
void func_800146D8(void);

void func_80013D10(OSMesg arg0){
    static s32 D_8003F430 = 1;
    osSendMesg(&D_800783D0, arg0, 1);
    if((s32) arg0 == 3 ){
        D_80078F0C = 0x1e;
        if(D_8003F430){
            osDpSetStatus(DPC_CLR_FREEZE);
            D_8003F430 = 0;
        }
        osRecvMesg(&D_80078438, NULL, OS_MESG_BLOCK);
        D_80078F0C = 0;
    }
}

void func_80013D94(AudioTask* arg0){
    s32 tmp = (D_80078F00 + 1) % ARRLEN(D_80078EB0);
    if(D_80078F04 != tmp){
        D_80078EB0[D_80078F00] = arg0;
        D_80078F00 = tmp;
    }
}

void func_80013DE4(GraphicsTask* arg0){
    s32 tmp = (D_80078EA8 + 1) % ARRLEN(D_80078E58);
    if(D_80078EAC != tmp){
        D_80078E58[D_80078EA8] = arg0;
        D_80078EA8 = tmp;
    }
}

void func_80013E34(AudioTask * arg0) {
    D_8003F3B0.t.ucode_boot = (u64*)rspbootTextStart;
    D_8003F3B0.t.ucode_boot_size = (u8*)rspbootTextEnd - (u8*)rspbootTextStart;
    D_8003F3B0.t.ucode = (u64*)n_aspMainTextStart;
    D_8003F3B0.t.ucode_data = (u64*)n_aspMainDataStart;
    D_8003F3B0.t.data_ptr = (u64*)arg0->unk8;
    D_8003F3B0.t.data_size = (arg0->unkC - arg0->unk8) * sizeof(Acmd);
    osWritebackDCache(D_8003F3B0.t.data_ptr , D_8003F3B0.t.data_size);
    osWritebackDCache(&D_8003F3B0, sizeof(OSTask));
    D_80078478 = arg0;
    osSpTaskStart(&D_8003F3B0);
    D_8007848C = 4;
}

void func_80013EF0(GraphicsTask * arg0) {
    D_8003F3F0.t.ucode_boot = (u64*)rspbootTextStart;
    D_8003F3F0.t.ucode_boot_size = (u8*)rspbootTextEnd - (u8*)rspbootTextStart;
    D_8003F3F0.t.ucode = (u64*)gspF3DEX2_NoN_fifoTextStart;
    D_8003F3F0.t.ucode_data = (u64*)gspF3DEX2_NoN_fifoDataStart;
    D_8003F3F0.t.data_ptr = (u64*)arg0->unk8;
    D_8003F3F0.t.data_size = (arg0->unkC - arg0->unk8) * sizeof(Gfx);
    osWritebackDCache(D_8003F3F0.t.data_ptr , D_8003F3F0.t.data_size);
    osWritebackDCache(&D_8003F3F0, sizeof(OSTask));
    osSpTaskStart(&D_8003F3F0);
    D_8007848C = arg0->unk4 | 0x8;
    D_80078488 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_80078484 = D_80078488;
        D_80078F10 = 0x1e;
    }
}

void func_80013FE4(GraphicsTask * arg0){
    D_8003F3F0.t.ucode_boot = (u64*)rspbootTextStart;
    D_8003F3F0.t.ucode_boot_size = (u8*)rspbootTextEnd - (u8*)rspbootTextStart;
    D_8003F3F0.t.ucode = (u64*)gspL3DEX2_fifoTextStart;
    D_8003F3F0.t.ucode_data = (u64*)gspL3DEX2_fifoDataStart;
    D_8003F3F0.t.data_ptr = (u64*) arg0->unk8;
    D_8003F3F0.t.data_size = (arg0->unkC - arg0->unk8) * sizeof(Gfx);
    osWritebackDCache(D_8003F3F0.t.data_ptr , D_8003F3F0.t.data_size);
    osWritebackDCache(&D_8003F3F0, sizeof(OSTask));
    osSpTaskStart(&D_8003F3F0);
    D_8007848C = arg0->unk4 | 0x8;
    D_80078488 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_80078484 = D_80078488;
        D_80078F10 = 0x1e;
    }
}

void func_800140D8(GraphicsTask *arg0) {
    switch(arg0->header.type){
        case TASK_TYPE_GFX_3D:
            func_80013EF0(arg0);
            break;

        case TASK_TYPE_GFX_LINE:
            func_80013FE4(arg0);
            break;
    }
}

void func_80014128(AudioTask* msg) {
    func_80013D94(msg);
}

void func_80014148(GraphicsTask* msg){
    func_80013DE4(msg);
    if(D_8007848C == 0x10 && !D_80078480){
        func_80013EF0(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
    }
}

void func_800141D0(GraphicsTask* msg){
    func_80013DE4(msg);
    if(D_8007848C == 0x10 && !D_80078480){
        func_80013FE4(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
    }
}

void func_80014258(void) {
    if( D_8007848C == 0x10 
        && D_80078484 == 2 
        && D_80078EAC == D_80078EA8
        && !(osDpGetStatus() & DPC_STATUS_FREEZE)
    ){
        osSendMesg(&D_80078438, NULL, OS_MESG_NOBLOCK);
    }
    else{
        D_8007847C++;
    }
}

void func_800142F0(void) {
    if((D_80078484 << 1) < 0){
        osDpSetStatus(DPC_SET_FREEZE);
        D_80078F08 = osViGetCurrentFramebuffer();
        func_80015190();
    }
    D_80078484 = D_80078488 = 2;
    D_80078F10 = 0;
    if(D_8007848C == 0x10 && D_80078EAC != D_80078EA8 && !D_80078480){
        func_800140D8(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
    }
    else{
        if(D_8007847C && D_80078EAC == D_80078EA8 && !(osDpGetStatus() & DPC_STATUS_FREEZE)){
            osSendMesg(&D_80078438, NULL, 0);
            D_8007847C--;
        }
    }
}

void func_8001443C(void){
    s32 sp2C = (D_8007847C != 0) && (D_80078EAC == D_80078EA8) && (D_80078488 == 2) && (D_8007848C == 0x10);
    s32 sp30;
    static s32 D_8003F434 = 0;

    sp30 = FALSE;
    if( osViGetCurrentFramebuffer() != D_80078F08 || sp2C){
        if(osDpGetStatus() & DPC_STATUS_FREEZE){
            osDpSetStatus(DPC_CLR_FREEZE);

            D_80078484 = D_80078488;
            // dummy_func_8025AFB8();

            if(D_80078484 & 1){
                D_80078F10 = 0x1E;
            }
        }

        if(sp2C){
            osSendMesg(&D_80078438, NULL, OS_MESG_NOBLOCK);
            D_8007847C--;
        }
    }

    if(D_80078F0C != 0){
        D_80078F0C--;
        if (D_80078F0C == 0) {
            sp30 = TRUE;
        }
    }

    if(D_80078F14 != 0){
        D_80078F14--;
        if (D_80078F14 == 0) {
            sp30 = TRUE;
        }
    }

    if(D_80078F10 != 0){
        D_80078F10--;
        if(D_80078F10 == 0){
            sp30 = TRUE;
        }
    }
    if (sp30) {
        func_8001E5DC(1);
    }
    D_80078480 = 0;
    D_8003F434++;
    if(!(D_8003F434 & 1)){
        osStopTimer(&D_80078F18);
        // Set up the timer for approximately 6 milliseconds.
        osSetTimer(&D_80078F18, OS_NSEC_TO_CYCLES(5973334), 0, &D_800783D0, (OSMesg)SCHEDULER_EVENT_AUDIO_TIMER);
    }

    if(D_80078F58){
        osStopTimer(&D_80078F38);
        // Set up the timer for 2/3 of a VI refresh (11.1 milliseconds on NTSC).
        osSetTimer(&D_80078F38, ((osClockRate / 60)* 2) / 3, 0, &D_800783D0, (OSMesg)SCHEDULER_EVENT_CONT_TIMER);
    }
}

void func_800146D8(void) {
    AudioTask *sp1C;
    s32 temp_v1;
    AudioTask *temp_v0;

    temp_v1 = D_8007848C;
    if (D_8007848C == 0x20) {
        sp1C = D_80078EB0[D_80078F04];
        D_80078F04 = (D_80078F04 + 1) % ARRLEN(D_80078EB0);
        D_80078494 = (osSpTaskYielded(&D_8003F3F0) == 1);
        func_80013E34(sp1C);
        D_80078F14 = 0;
        return;
    }

    if (D_8007848C == 4) {
        osSendMesg(D_80078478->unk10, D_80078478->unk14, 0);
    }

    if ((D_8007848C == 4) && (D_80078494 != 0)) {
        osSpTaskLoad(&D_8003F3F0);
        osSpTaskStartGo(&D_8003F3F0);
        D_8007848C = D_80078490;
        D_80078494 = 0;
        return;
    }

    D_8007848C = 0x10;
    if ((D_80078EAC != D_80078EA8) && (D_80078480 == 0)) {
        func_800140D8(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
        return;
    }
    
    if ((D_8007847C != 0) && (D_80078484 == 2) && !(osDpGetStatus() & 2)) {
        osSendMesg(&D_80078438, NULL, 0);
        D_8007847C -= 1;
    }
}

void func_800148B0(OSMesg msg){
    D_80078480 = TRUE;
}

void func_800148C4(void) {
    AudioTask *ptr;
    osSendMesg(audioManager_getFrameMesgQueue(), NULL, OS_MESG_NOBLOCK);
    if((D_8007848C == 0x10) && (D_80078F04 != D_80078F00)){
        ptr = D_80078EB0[D_80078F04];
        D_80078F04 = (D_80078F04 + 1) % ARRLEN(D_80078EB0);
        func_80013E34(ptr);
    } else if((D_8007848C & 0x8) && (D_80078F04 != D_80078F00)){
        osSpTaskYield();
        D_80078490 = D_8007848C;
        D_8007848C = 0x20;
        D_80078F14 = 0x1E;
    }
}

// .data (continued, needs to be declared after func_8001443C)
OSViMode D_8003F438 = {
    OS_VI_MPAL_LPN1, /* type */
    { 
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
        320,          /*width*/
        0x4651E39,    /*burst*/
        0x20D,        /*vSync*/
        0x40C11,      /* hSync*/
        0xC190C1A,    /* leap*/
        0x6C02EC,     /* hStart*/
        0, /* xScale*/
        0, /* vCurrent*/
    },
    {
        {640, 1024, 0x2501FF, 0xE0204, 2},
        {640, 1024, 0x2501FF, 0xE0204, 2}
    }
};

OSViMode D_8003F488 = {
    OS_VI_NTSC_LPN1, /* type */
    { 
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
        320,          /*width*/
        0x3E52239,    /*burst*/
        0x20D,        /*vSync*/
        0xC15,        /* hSync*/
        0xC150C15,    /* leap*/
        0x6C02EC,     /* hStart*/
        0, /* xScale*/
        0, /* vCurrent*/
    },
    {
        {0x280, 1024, 0x2501FF, 0xE0204, 2},
        {640, 1024, 0x2501FF, 0xE0204, 2}
    }
};

void func_800149BC(void){
    // This can also be matched as a function-local static instead of using a local pointer variable.
    s32* D_80078F5C_ptr = &D_80078F5C;

    if(!*D_80078F5C_ptr){
        *D_80078F5C_ptr = TRUE;
        func_800155BC();
        switch (osTvType) {
            case OS_TV_PAL:
            case OS_TV_NTSC:
                osViSetMode(&D_8003F488);
                break;
            case OS_TV_MPAL:
                osViSetMode(&D_8003F438);
                break;
        }
        func_80015430(0);
        rumbleManager_80018634(); //stop controller motors
        while (TRUE) { 
            osDpSetStatus(DPC_STATUS_FLUSH);
        }
    }
}

void func_80014A54(void) {
    if (!(__osGetSR_2() & SR_IBIT5)) {
        func_800149BC();
    }
}

// scheduler_thread_entry
void func_80014A88(void *arg0){
    OSMesg msg = NULL;
    while (TRUE) {
        osRecvMesg(&D_800783D0, &msg, OS_MESG_BLOCK);
        func_80014A54();
        if((s32)msg == 3){ func_80014258(); }
        else if((u32)msg == SCHEDULER_EVENT_VI)          { func_8001443C(); }
        else if((u32)msg == SCHEDULER_EVENT_DP)          { func_800142F0(); }
        else if((u32)msg == SCHEDULER_EVENT_SP)          { func_800146D8(); }
        else if((u32)msg == SCHEDULER_EVENT_AUDIO_TIMER) { func_800148C4(); }
        else if((u32)msg == SCHEDULER_EVENT_FAULT)       { func_8001E5DC(0); }
        else if((u32)msg == SCHEDULER_EVENT_PRENMI)      { func_800149BC(); }
        else if((u32)msg == 12) { }
        else if((u32)msg == SCHEDULER_EVENT_CONT_TIMER)  { pfsManager_getStartReadData(); }
        else if((u32)msg >= 100) {
            if      (((TaskHeader*)msg)->type == TASK_TYPE_AUDIO)       { func_80014128((AudioTask*)msg); }
            else if (((TaskHeader*)msg)->type == TASK_TYPE_GFX_3D)      { func_80014148((GraphicsTask*)msg); }
            else if (((TaskHeader*)msg)->type == TASK_TYPE_GFX_LINE)    { func_800141D0((GraphicsTask*)msg); }
            else if (((TaskHeader*)msg)->type == TASK_TYPE_DISABLE_GFX) { func_800148B0(msg); }
        }
    }
}

// scheduler_init
void func_80014C40(void) {
    u8 *tmp_v0;
    osCreateMesgQueue(&D_800783D0, D_800783E8, ARRLEN(D_800783E8));
    osCreateMesgQueue(&D_80078438, D_80078450, ARRLEN(D_80078450));
    osSetEventMesg(OS_EVENT_DP, &D_800783D0, (OSMesg)SCHEDULER_EVENT_DP);
    osSetEventMesg(OS_EVENT_SP, &D_800783D0, (OSMesg)SCHEDULER_EVENT_SP);
    osSetEventMesg(OS_EVENT_FAULT, &D_800783D0, (OSMesg)SCHEDULER_EVENT_FAULT);
    osSetEventMesg(OS_EVENT_PRENMI, &D_800783D0, (OSMesg)SCHEDULER_EVENT_PRENMI);
    func_80014F64(&D_800783D0, (OSMesg)SCHEDULER_EVENT_VI);
    D_8007847C = 0;
    D_80078480 = 0;
    D_80078484 = D_80078488 = 2;
    D_8007848C = D_80078490 = 0x10;
    D_80078494 = 0;
    D_80078EAC = 0;
    D_80078EA8 = 0;
    D_80078F04 = 0;
    D_80078F00 = 0;
    tmp_v0 = (u8*)D_800777B0;
    while((u32)tmp_v0 % 0x10){tmp_v0++;}
    D_8003F3F0.t.yield_data_ptr = (u64*)tmp_v0;
    func_8001DCB0(&D_80078C98, &D_80078E48, THREAD_ID_SCHEDULER, func_80014A88, NULL, &D_80078498[SCHEDULER_THREAD_STACK_SIZE64], SCHEDULER_THREAD_PRIORITY);
    osStartThread(&D_80078C98);
}

void func_80014DC4(void) {
    D_80078F58 = 1;
}

void func_80014DD4(Gfx **gfx){
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}
