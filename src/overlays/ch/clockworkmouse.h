#ifndef __CH_CLOCKWORKMOUSE_H__
#define __CH_CLOCKWORKMOUSE_H__

#include "common.h"
#include "core2/1E9A960.h"
#include "core2/1EB5E70.h"
#include "core2/1EC8070.h"

s32 func_800DA564(s32 startIndex, s32 length);
void func_800DA7A8(s32 startIndex, s32 set, s32 length);
void func_800FC660(s32);
void func_800FDC28(s32);
void _gcgoto_entrypoint_1(s32, s32);

// size: unknown
typedef struct Actor {
    s32 unk0;
    f32 pos[3];
    u8 pad10[0x24 - 0x10];
    f32 unk24;
    u8 pad28[0x38 - 0x28];
    s32 unk38;
    s32 unk3C;
    s32 pad40;
    f32 rotation[3];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C;
    u8 pad5D;
    u8 pad5E;
    u8 unk5F;
    s32 pad60;
    union {
        u32 flags;
        u8 bytes[4];
        struct {
            u32 unk64_24 : 8;
            u32 unk64_20 : 4;
            u32 unk64_19 : 1; // flags & 0x80000
            u32 unk64_18 : 1;
            u32 unk64_17 : 1;
            u32 unk64_16 : 1;
            u32 unk64_15 : 1;
        } bits;
    } unk64;
    u8 pad68[0x70 - 0x68];
    u32 unk70_16: 16;
    u32 unk70_10: 6; // unk72 >> 0xA
    u32 unk70_A: 0xA;
    union {
        u32 flags;
        u8 bytes[4];
        struct {
            u32 unk74_31 : 1;
            u32 unk74_30 : 1;
        } bits;
    } unk74;
    s32 pad78;
    union {
        u32 flags;
        struct {
            s32 unk7C_13 : 19;
            s32 unk7C_12 : 1;
        } bits;
    } unk7C;
} Actor;

typedef struct ActorData {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    void *unk8;
    void (*unkC_func)(Actor* actor);
    void (*unk10_func)(Actor* actor);
    void (*unk14_func)(s32 arg0, s32 arg1);
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    void (*unk28_func)(Actor* actor);
    s32 unk2C;
    s16 unk30;
    s16 unk32;
    void (*unk34_func)(Actor* actor);
    void (*unk38_func)(void* arg0, s32 arg1, void* arg2, s32 arg3, void* arg4); // argument types unknown currently
    s16 unk3C;
    s16 unk3E;
    void (*unk40_func)(Actor* actor, s32 arg1, s32 arg2);
    s16 unk44;
    s16 unk46;
    void (*unk48_func)(Actor* actor, s32 arg1, s32 arg2);
    s32 unk4C;
} ActorData;

// size: 0x14
typedef struct Unk80803CD8 {
    u8 pad0[0xC];
    f32 unkC;
    s16 unk10;
    s16 unk12;
} Unk80803CD8;

// size: 0x10
typedef struct Unk80803E08  {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} Unk80803E08;

// size: unknown
typedef struct Unk80100094 {
    union {
        struct {
            s16 unk0;
            s16 pad2;
        } shorts;
        f32 f;
    } unk0;
    f32 unk4;
    f32 unk8;
    union {
        u8 bytes[0x84 - 0xC];
        s16 shorts[(0x84 - 0xC) / 2];
        Vec3f vecs[10];
    } unkC;
    f32 unk84[10];
    f32 unkAC[10];
    f32 unkD4;
    f32 unkD8;
    f32 unkDC;
    u8 unkE0[10];
    u8 padEA;
    u8 padEB;
    f32 unkEC;
    u8 unkF0[10];
    u8 unkFA;
    u8 unkFB;
    u8 unkFC;
    u8 unkFD;
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    f32 unk104;
    f32 unk108;
    f32 unk10C;
    f32 unk110;
    f32 unk114;
} Unk80100094;

Unk80100094 *func_80100094(Actor *, s32);
void _gcintrotext_entrypoint_0();                      /* extern */

void _susplinet_entrypoint_0(s32, s32, s32, s32);          /* extern */
s16 *_susplinet_entrypoint_12(s32);                 /* extern */
s16 *_susplinet_entrypoint_13(s32);                 /* extern */
Vec3f *_susplinet_entrypoint_14(s32, s32);             /* extern */
f32 *_susplinet_entrypoint_15(s32, s32);             /* extern */
s32 _susplinet_entrypoint_18(s32, s32, s32);          /* extern */
void _susplinet_entrypoint_19(s32, s32, s32, s32);       /* extern */
void func_800F0EF0(s32, Vec3f *);                        /* extern */
s32 func_80100074(Actor *, s32, s32);                     /* extern */
void _capod_entrypoint_1(f32[3], f32[3]);                  /* extern */
void _susplinet_entrypoint_10(Unk80100094 *, f32);     /* extern */
void _susplinet_entrypoint_11(Unk80100094 *, f32);     /* extern */
void _susplinet_entrypoint_17(Unk80100094 *);          /* extern */
s32 _susplinet_entrypoint_6(Unk80100094 *);         /* extern */
void _susplinet_entrypoint_7(Unk80100094 *, s32, s32[3]);   /* extern */
f32 _susplinet_entrypoint_8(Unk80100094 *, s32);      /* extern */
f32 _susplinet_entrypoint_9(Unk80100094 *);         /* extern */
void func_800A516C(f32[3], f32[3], f32[3]);
f32 func_800D8FF8();
void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
void func_800EF5A0(f32[3], s32[3], f32, f32, f32);
f32 func_800F1DCC(f32, f32);
f32 func_80105AE8(Actor *);
Actor *func_80106790(s32);
void _capod_entrypoint_2(s32, s32, s32);                 /* extern */
void func_8008FB58(f32[3], f32, f32);                         /* extern */
s32 func_80105998(Actor *, f32);                        /* extern */
void _subaddieDll_entrypoint_4(Actor *, s32);                     /* extern */
void func_800903D0(f32[3]);                             /* extern */
void func_800904C8(s32);                                 /* extern */
s32 func_8009EA64(void);                                /* extern */
void func_800EEB9C(f32[3], f32, f32);                     /* extern */
void func_800906DC(f32[3]);                               /* extern */
void func_800907C0(f32[3]);                               /* extern */
void func_80800D14_chclockworkmouse(Actor *, s32);      /* extern */
void func_808022E4_chclockworkmouse(Actor *, s32); /* extern */
s32 func_80016B30(s32, s32);                            /* extern */
f32 func_800F10B4(f32, f32, f32, f32, f32);               /* extern */
s32 func_800C4350(s32, f32[3], s32 *);            /* extern */
void _capod_entrypoint_7(s32, s32);                    /* extern */
void _capod_entrypoint_8(s32);                           /* extern */
void _gcdialogcamera_entrypoint_6(s32);                /* extern */
void _gcdialogcamera_entrypoint_8(void);                   /* extern */
void func_80105834(Actor*);                      /* extern */
void func_80105A9C(Actor*, f32);                 /* extern */
void func_800C7A68(s32, f32, Vec3f*);                   /* extern */
f32 func_800C7B7C(s32, f32, f32, f32);                  /* extern */
s32 func_800D7520(s16);                             /* extern */
f32 func_80090010(void);                                /* extern */
s32 func_80090178(s32);                               /* extern */
void func_800DA544(s32);                                 /* extern */
s32 func_80105A5C(Actor*);                            /* extern */
s32 func_8010C9B0(f32[3], s32);                         /* extern */
s32 func_8010CB0C(f32[3], s32, s32, s32);                   /* extern */
void func_80801240_chclockworkmouse(Actor*);             /* extern */
s32 _gccubesearch_entrypoint_1(s32, f32[3]);             /* extern */
void _gspropctrl_entrypoint_11(s32, s32 *);              /* extern */
void func_80100120(Actor *);                            /* extern */
Actor *func_80108528(s32, s32 *, s32, Actor **);            /* extern */
void func_800D93A0(f32[4], f32[3]);                            /* extern */
void func_800DF41C(s32);                               /* extern */
void func_800DFF2C(s32, s32, f32[4]);                        /* extern */
void func_800EFA4C(f32[3], f32, f32, f32);                     /* extern */
void func_801015D0(Actor*);                      /* extern */
s32 func_801040D0(void);                                /* extern */
void _subaddiedialog_entrypoint_11(s32, s32, s32, f32[3], s32); /* extern */
void _capod_entrypoint_19(f32[3]);                      /* extern */
s16* _gccubesearch_entrypoint_0(s32, Actor*);         /* extern */
s16 _glsplinefind_entrypoint_0(s32, f32*);            /* extern */
s32 func_800D0A9C(s32, s32);                            /* extern */
s32 func_800DA298(s32);                               /* extern */
void func_80103140(Actor*, s32, u16);                    /* extern */
void func_801058C4(Actor*, s16, f32, s32);               /* extern */
void func_80108B04(Actor*, s32);                         /* extern */
void _subaddieaudioquick_entrypoint_2(Actor*, f32*, void*); /* extern */
void _subaddieaudioquick_entrypoint_3(Actor*, f32*, void*, f32); /* extern */
void _subaddieaudioquick_entrypoint_4(Actor*, f32*, void*, void*); /* extern */
s32 func_800C0638();                                /* extern */
s32 func_800DC298(f32);                             /* extern */
s32 func_801022E4(Actor*);                          /* extern */
s32 _glcutDll_entrypoint_19(s32);                     /* extern */
s16 _glsplinefind_entrypoint_0(s32, f32*);            /* extern */
void _suexpression_entrypoint_12(Unk80100094*, f32, f32);  /* extern */
void _suexpression_entrypoint_7(Actor*, s32, s32);         /* extern */
s32 func_800D0A9C(s32, s32);                            /* extern */
s32 func_800DA298(s32);                               /* extern */
void func_801058C4(Actor*, s16, f32, s32);               /* extern */
void func_808026E0_chclockworkmouse(Actor*, s32);        /* extern */
void _capod_entrypoint_6(s32, s32, s32);               /* extern */
void func_800904F4(s32, s32);                            /* extern */
void func_800F4CC0(s32);                               /* extern */
void func_800F4CEC(s32, s32);                            /* extern */
s32 func_800F54E4(void);                                /* extern */
void func_80102424(Actor*, s32);                       /* extern */
void _suexpression_entrypoint_8(Actor*, s32);            /* extern */
void func_80090658(s32);                                 /* extern */
void func_80090708(s32);                            /* extern */
void func_80090734(s32, f32[3]);                           /* extern */
s32 func_800BEF00(f32[3], f32[3], f32[3], s32);               /* extern */
f32 func_80101F24(Actor*);                          /* extern */
void func_80102B2C(Actor*, f32);                         /* extern */
f32 func_8010CD28(Actor *);                                /* extern */
void _sudeflect_entrypoint_1(f32[3], f32, f32, f32, s32); /* extern */
void _glcutDll_entrypoint_17(void);                  /* extern */
s32 _subaddiedialog_entrypoint_3(f32[3], s32, s32, s32, s32); /* extern */
s32 _subaddiedialog_entrypoint_6(f32[3], s32, s32, s32, s32); /* extern */
void _suexpression_entrypoint_10(Unk80100094*, s32, s32); /* extern */
s32 func_80090248(void);                                /* extern */
void func_800FFAB0(Actor*);                            /* extern */
s32 func_80101DDC(Actor*);                          /* extern */
s32 func_80101E14(Actor*, f32);                       /* extern */
void func_80105634(Actor*);                            /* extern */
void _capod_entrypoint_14(void);                           /* extern */
void _gcdialogcamera_entrypoint_3(void**, s32);            /* extern */
void func_800D1000(s32, s32, f32*, s32, s32);                /* extern */
void func_800DF744(s32, s32);                              /* extern */
s32 func_80101080(void);                                /* extern */
void func_801018A4(void);
void func_800E2594(s32, s32);
#endif // __CH_CLOCKWORKMOUSE_H__
