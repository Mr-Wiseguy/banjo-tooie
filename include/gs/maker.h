#ifndef __GS_MAKER_H__
#define __GS_MAKER_H__

#include "common.h"
#include "memory.h"
#include "core2/1EAF950.h"

enum file_mode_e {
    FILE_MODE_0_UNKNOWN,
    FILE_MODE_1_UNKNOWN,
    FILE_MODE_2_FROM_ASSET,
    FILE_MODE_3_FROM_MEMORY,
    FILE_MODE_4_ALLOCATED
};
typedef struct file_s {
    void* asset_base_ptr;
    void* asset_current_ptr;
    void* base_ptr;
    void* current_ptr;
    void* end_ptr;
    enum file_mode_e mode;
    s32 last_expected; // used in file_isNextByteExpected
    s32 unk1C;
    s16 unk20;
    s16 unk22;
} File;
#define FILE_DEFAULT_SIZE 0x20

void gsmaker_entrypoint_0(File*);
File* gsmaker_entrypoint_1(s32);
void gsmaker_entrypoint_8(File*, u8*, s32);
void gsmaker_entrypoint_10(File*, f32*, s32);
void gsmaker_entrypoint_12(File*, s32*, s32);
void gsmaker_entrypoint_13(File*, void*, s32);
s32 gsmaker_entrypoint_16(File*, s32);

#endif
