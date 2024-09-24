#include "types.h"
#include "gfx.h"
#include "memory.h"

s32 func_80014F00();
void func_8001D96C();
void func_8001D3D8(s32, s32, const char*, ...);
void _gzthread_entrypoint_0(s32, char*);
void func_8001D9CC(s32, s32);
void _gzreg_entrypoint_0(void*);
void _gzthread_entrypoint_1(s32);
void _gztrace_entrypoint_1(void*, s32, s32, s32);
s32 func_80014F00();
s32 func_80014F38();
void func_80015430(s32);
void func_8001DA60(s32);
void wait_five_seconds_gzpublic();
void func_80800040_gzpublic(s32);

struct unkD_8007E94C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

// Do not edit this struct, it reflects the layout of data in the build_data ROM segment
struct BuildData {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 time;
    /* 0x18 */ u32 month;
    /* 0x1C */ u32 day;
};

extern u8 build_data_ROM_START[];

void wait_five_seconds_gzpublic(void) {
    s32 i;

    for (i = 0; i < 300; i++) {
        wait_one_frame();
    }
}

void func_80800040_gzpublic(s32 thread_id) {
    uintptr_t rom_address;
    char thread_name[12];
    u32 day;
    u32 month;
    u32 time;
    u16 hour;
    u16 minute;

    aligned8_memset(func_80014F00(), 0x12211221, func_80014EC8());
    func_8001D96C();
    rom_address = (uintptr_t)build_data_ROM_START;
    rom_read_word(rom_address + offsetof(struct BuildData, day), &day);
    rom_read_word(rom_address + offsetof(struct BuildData, month), &month);
    rom_read_word(rom_address + offsetof(struct BuildData, time), &time);
    hour = (time / 100);
    minute = time - hour * 100;
    func_8001D3D8(0x22, 0, "Build: %02d:%02d %02d/%02d/00", hour, minute, month, day);
    _gzthread_entrypoint_0(thread_id, thread_name);
    func_8001D3D8(0, 0, "Thread: %s", thread_name);
    func_8001D9CC(0, 3);
}

void gzpublic_entrypoint_0(struct unkD_8007E94C* arg0) {
    wait_five_seconds_gzpublic();
    func_80015430(func_80014F38());
    wait_five_seconds_gzpublic();
    while (TRUE) {
        func_80800040_gzpublic(arg0->unk14);
        _gztrace_entrypoint_1(arg0, 0, 0, 0);
        func_8001DA60(func_80014F00());
        wait_five_seconds_gzpublic();

        func_80800040_gzpublic(arg0->unk14);
        _gzreg_entrypoint_0(arg0);
        func_8001DA60(func_80014F00());
        wait_five_seconds_gzpublic();

        func_80800040_gzpublic(arg0->unk14);
        _gzthread_entrypoint_1(-1);
        func_8001DA60(func_80014F00());
        wait_five_seconds_gzpublic();

        func_80015430(func_80014F38());
        wait_five_seconds_gzpublic();

        func_80015430(func_80014F38());
    }
}
