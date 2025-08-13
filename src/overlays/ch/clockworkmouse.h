#ifndef __CH_CLOCKWORKMOUSE_H__
#define __CH_CLOCKWORKMOUSE_H__

#include "common.h"
#include "core2/1E9A960.h"
#include "core2/1EB5E70.h"

s32 func_800DA564(s32 startIndex, s32 length);
void func_800DA7A8(s32 startIndex, s32 set, s32 length);
void func_800FC660(s32);
void func_800FDC28(s32);
void _gcgoto_entrypoint_1(s32, s32);

// size: unknown
typedef struct Unk80100094 {
    s32 unk0;
    s32 unk4;
    u8 pad8[0xF - 0x8];
    u8 unkF;
    u8 pad10[0x24 - 0x10];
    f32 unk24;
    u8 pad28[0x3C - 0x28];
    s32 unk3C;
    s32 pad40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x5F - 0x4C];
    u8 unk5F;
    u8 pad60[0x72 - 0x60];
    u16 unk72;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0xFA - 0x80];
    u8 unkFA;
    u8 unkFB;
    u8 unkFC;
    s8 padFD;
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    f32 unk104;
    f32 unk108;
    f32 unk10C;
    f32 unk110;
} Unk80100094;

// size: 0x14
typedef struct Unk80803CD8 {
    u8 pad0[0xC];
    f32 unkC;
    s16 unk10;
    s16 unk12;
} Unk80803CD8;

// size: 0x10
typedef struct Unk80803E08  {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} Unk80803E08;

Unk80100094 *func_80100094(Unk80100094 *, s32);
void _gcintrotext_entrypoint_0();                      /* extern */

void _susplinet_entrypoint_0(s32, s32, s32, s32);          /* extern */
s16 *_susplinet_entrypoint_12(s32);                 /* extern */
s16 *_susplinet_entrypoint_13(s32);                 /* extern */
s32 *_susplinet_entrypoint_14(s32, s32);             /* extern */
f32 *_susplinet_entrypoint_15(s32, s32);             /* extern */
s32 _susplinet_entrypoint_18(s32, s32, s32);          /* extern */
void _susplinet_entrypoint_19(s32, s32, s32, s32);       /* extern */
void func_800F0EF0(s32, s32 *);                        /* extern */
s32 func_80100074(Unk80100094 *, s32, s32);                     /* extern */
void func_800EE7F8(s32 *, Unk80803CD8 *);
void _capod_entrypoint_1(f32[3], f32[3]);                  /* extern */
void _susplinet_entrypoint_10(Unk80100094 *, f32);     /* extern */
void _susplinet_entrypoint_11(Unk80100094 *, f32);     /* extern */
void _susplinet_entrypoint_17(Unk80100094 *);          /* extern */
s32 _susplinet_entrypoint_6(Unk80100094 *);         /* extern */
void _susplinet_entrypoint_7(Unk80100094 *, s32, s32 *);   /* extern */
f32 _susplinet_entrypoint_8(Unk80100094 *, s32);      /* extern */
f32 _susplinet_entrypoint_9(Unk80100094 *);         /* extern */
void func_800A516C(f32[3], f32[3], f32[3]);
f32 func_800D8FF8();
void func_800EF04C(f32[3], s32 *);
void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
void func_800EF5A0(f32[3], s32 *, f32, f32, f32);
f32 func_800F1DCC(f32, f32);
f32 func_80105AE8(Unk80100094 *);
Unk80100094 *func_80106790(s32);
void _capod_entrypoint_2(s32, s32, s32);                 /* extern */
void func_8008FB58(s32 *, f32, f32);                         /* extern */
s32 func_80105998(Unk80100094 *, s32);                        /* extern */
void func_80800850_chclockworkmouse(Unk80100094 *, s16, s32, s32); /* extern */
void func_808008DC_chclockworkmouse(Unk80100094 *, s16, s32, s32); /* extern */
void func_80800968_chclockworkmouse(Unk80100094 *, u8, s32);       /* extern */
void _subaddieDll_entrypoint_4(Unk80100094 *, s32);                     /* extern */
void func_800903D0(f32[3]);                             /* extern */
void func_800904C8(s32);                                 /* extern */
s32 func_8009EA64(void);                                /* extern */
void func_800EEB9C(f32[3], f32, f32);                     /* extern */
void func_800906DC(f32 *);                               /* extern */
void func_800907C0(s32 *);                               /* extern */
void func_80800D14_chclockworkmouse(Unk80100094 *, s32);      /* extern */
void func_808022E4_chclockworkmouse(Unk80100094 *, s32); /* extern */
s32 func_80016B30(s32, s32);                            /* extern */
f32 func_800F10B4(f32, f32, f32, f32, f32);               /* extern */
s32 func_800C4350(s32, s32 *, s32 *);            /* extern */

#endif // __CH_CLOCKWORKMOUSE_H__
