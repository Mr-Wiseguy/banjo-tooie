#include "buffers.h"

extern u8 core2_compressed_ROM_END[];
extern u8 core2_compressed_ROM_START[];

void func_80000670(void) {
    D_80012010[0].rom_start = core2_compressed_ROM_START;
    D_80012010[0].rom_end = core2_compressed_ROM_END;
}
