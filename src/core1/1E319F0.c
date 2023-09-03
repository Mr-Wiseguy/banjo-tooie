#include "buffers.h"

extern void     bzero(void *, int);
extern void		osInvalDCache(void *, s32);
extern void		osInvalICache(void *, s32);
extern void		osWritebackDCache(void *, s32);
extern void		osWritebackDCacheAll(void);

void func_80012F78(s32, u8*, u32);                     /* extern */
s32 func_8001A0A8();                                /* extern */
void func_8001A2B0();                                  /* extern */
void func_8001C1E0(s32*, void**);                      /* extern */
s32 func_8001C26C();                                /* extern */
s32 func_8001C28C();                                /* extern */
extern s32 D_8007E994;

// Loads a non-relocatable overlay
void func_80019EC0(s32 arg0, u8* ovl_start, u8* ovl_end, u8* ovl_rom_start, u8* ovl_rom_end, u8* ovl_text_start, u8* ovl_text_end, u8* ovl_rodata_start, u8* ovl_data_end, u8* ovl_bss_start, u8* ovl_bss_end) {
    s32 var_a0;
    s32 sp30;
    s32 sp2C;
    s32* test;

    osWritebackDCacheAll();
    osInvalDCache(ovl_start, ovl_end - ovl_start);
    osInvalICache(ovl_start, ovl_end - ovl_start);
    if (ovl_bss_start != NULL) {
        osInvalDCache(ovl_bss_start, ovl_bss_end - (u8*)ovl_bss_start);
    }
    ovl_rom_start = D_80012010[arg0].rom_start;
    ovl_rom_end = D_80012010[arg0].rom_end;
    if (arg0 != 0) {
        func_8001A2B0();
        var_a0 = func_8001A0A8();
    } else {
        var_a0 = D_8007E994;
    }
    func_80012F78(var_a0, ovl_rom_start, ovl_rom_end - ovl_rom_start);
    func_8001C1E0(&var_a0, (void** ) &ovl_start);
    sp2C = func_8001C26C();
    sp30 = func_8001C28C();
    func_8001C1E0(&var_a0, (void** ) &ovl_start);
    if (ovl_bss_start != NULL) {
        bzero(ovl_bss_start, ovl_bss_end - (u8*)ovl_bss_start);
        osWritebackDCacheAll();
        test = (s32*)ovl_bss_start;
        *test++ = sp2C;
        *test++ = sp30;
        ovl_bss_start += 2; // Needed to match
        *test++ = func_8001C26C();
        *test++ = func_8001C28C();
    }
}
