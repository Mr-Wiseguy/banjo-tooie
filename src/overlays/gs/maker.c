#include "gs/maker.h"

//file close
void gsmaker_entrypoint_0(File* arg0) {
    if (arg0->mode == FILE_MODE_2_FROM_ASSET) {
        func_800D721C(arg0->unk20, 0);
        func_800D70F8(arg0->unk20, 0);
        func_800D6CEC(arg0->unk20);
    }
    heap_free(arg0);
}

//File open
File* gsmaker_entrypoint_1(s32 asset_id) {
    File* this;

    this = (File*)heap_alloc(sizeof(File));

    if (this == NULL) {
        return NULL;
    }

    this->mode = FILE_MODE_2_FROM_ASSET;
    this->last_expected = -1;
    this->unk1C = -1;
    this->unk20 = asset_id;
    this->asset_base_ptr = asset_load(this->unk20);
    this->asset_current_ptr = this->asset_base_ptr;
    func_800D70D0(1);
    func_800D71F4(1);
    if (this->asset_base_ptr != NULL) {
        return this;
    }

    heap_free(this);
    return NULL;
}

//file_openMap
File* gsmaker_entrypoint_2(s32 map_id) {
    return gsmaker_entrypoint_1(map_id + 0x955);
}

//file_openWithBaseIndex
File* gsmaker_entrypoint_3(s32 arg0, s32 arg1)
{
    return gsmaker_entrypoint_1(arg0 + arg1);
}

//file_openFromMem
File* gsmaker_entrypoint_4(void* ptr, s32 size) {
    File* this;

    this = (File*)heap_alloc(sizeof(File));
    this->mode = FILE_MODE_3_FROM_MEMORY;
    this->last_expected = -1;
    this->unk1C = -1;
    this->base_ptr = ptr;
    this->current_ptr = this->base_ptr;
    this->end_ptr = (u8*)this->base_ptr + size;

    return this;
}

//file_allocNew
File* gsmaker_entrypoint_5(void) {
    File* this;

    this = (File*)heap_alloc(sizeof(File));
    this->mode = FILE_MODE_4_ALLOCATED;
    this->last_expected = -1;
    this->unk1C = -1;
    this->base_ptr = heap_alloc(0x20);
    this->current_ptr = this->base_ptr;
    this->end_ptr = (u8*)this->base_ptr + FILE_DEFAULT_SIZE;

    return this;
}

//File Realloc
void gsmaker_entrypoint_6(File* file, void** arg1, s32* size) {
    *size = ((u32)file->current_ptr - (u32)file->base_ptr);
    *arg1 = heap_realloc(file->base_ptr, *size);
    file->base_ptr = NULL;
    gsmaker_entrypoint_0(file);
}

//File Get Byte
void gsmaker_entrypoint_7(File* file, u8* dst)
{
    gsmaker_entrypoint_13(file, dst,0x1);
}

//File getNum Bytes
void gsmaker_entrypoint_8(File* file, u8* dst, s32 cnt)
{
    while (cnt > 0) {
        gsmaker_entrypoint_7(file, dst);
        cnt--;
        dst++;
    }
}
//File Get Float
void gsmaker_entrypoint_9(File* file,f32* dst)
{
    gsmaker_entrypoint_13(file, dst,0x4);
}

//FilegetNumFloat
void gsmaker_entrypoint_10(File* file, f32* dst, s32 cnt) {
    while (cnt > 0) {
        gsmaker_entrypoint_9(file, dst);
        cnt--;
        dst++;
    }
}

//file_getWord
void gsmaker_entrypoint_11(File* file, s32* dst)
{
    gsmaker_entrypoint_13(file, dst,0x4);
}

//File Get NumWords
void gsmaker_entrypoint_12(File* file, s32* dst, s32 cnt) {
    while (cnt > 0) {
        gsmaker_entrypoint_11(file, dst);
        cnt--;
        dst++;
    }
}

//File Read
void gsmaker_entrypoint_13(File* file, void* dst, s32 len) {
    u32 curr_offset;
    u32 capacity;
    void* new_base_ptr;

    if (file->mode == FILE_MODE_2_FROM_ASSET) {
        rare_memcpy(dst, file->asset_current_ptr, len);
        file->asset_current_ptr = (void*)((u32)file->asset_current_ptr + len);
    }
    else if (file->mode == FILE_MODE_3_FROM_MEMORY) {
        rare_memcpy(dst, file->current_ptr, len);
        file->current_ptr = (void*)((u32)file->current_ptr + len);
    }
    else if (file->mode == FILE_MODE_4_ALLOCATED) { // why does it write in read function?
        if ((u8*)file->end_ptr < (u8*)file->current_ptr + len) {
            curr_offset = (u8*)file->current_ptr - (u8*)file->base_ptr;
            capacity = ((u8*)file->end_ptr - (u8*)file->base_ptr) * 2;

            while (((u8*)file->base_ptr + capacity) < ((u8*)file->current_ptr + len)) {
                capacity *= 2;
            }

            new_base_ptr = heap_realloc(file->base_ptr, capacity);
            file->base_ptr = new_base_ptr;
            file->current_ptr = (u8*)new_base_ptr + curr_offset;
            file->end_ptr = (u8*)new_base_ptr + capacity;
        }

        rare_memcpy(file->current_ptr, dst, len);
        file->current_ptr = (u8*)file->current_ptr + len;
    }
}

//file get short
void gsmaker_entrypoint_14(File* file, void* dst)
{
    gsmaker_entrypoint_13(file, dst,0x2);
}
//File get num shorts
void gsmaker_entrypoint_15(File* file, s16* dst, s32 cnt)
{
    while (cnt > 0)
    {
        gsmaker_entrypoint_14(file, dst);
        cnt--;
        dst++;
    }
}
//file_isNextByteExpected
s32 gsmaker_entrypoint_16(File* file, s32 expected) {
    u8 saved_expected;

    saved_expected = expected;

    if ((file->mode == FILE_MODE_1_UNKNOWN) || (file->mode == FILE_MODE_4_ALLOCATED)) {
        gsmaker_entrypoint_7(file, &saved_expected);
        return TRUE;
    }

    if (file->last_expected == -1) {
        gsmaker_entrypoint_7(file, &saved_expected);

        if (expected == saved_expected) {
            return TRUE;
        }

        file->last_expected = saved_expected;
        return FALSE;
    }

    if (expected == file->last_expected) {
        file->last_expected = -1;
        return TRUE;
    }

    return FALSE;
}
//file_getByte_ifExpected
s32 gsmaker_entrypoint_17(File* file, s32 expected, u8* dst)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_7(file, dst);
    return 1;
}

//file_getNBytes_ifExpected
s32 gsmaker_entrypoint_18(File* file, s32 expected, void* dst, s32 cnt)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_8(file, dst, cnt);
    return 1;
}
//file_getFloat_ifExpected
s32 gsmaker_entrypoint_19(File* file, s32 expected, f32* dst)
{
    if (gsmaker_entrypoint_16(file, expected) == 0)
    {
        return 0;
    }
    gsmaker_entrypoint_9(file, dst);
    return 1;
}
//file_getNFloats_ifExpected
s32 gsmaker_entrypoint_20(File* file, s32 expected, f32* dst, s32 cnt)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_10(file, dst, cnt);
    return 1;
}
//file_getWord_ifExpected
s32 gsmaker_entrypoint_21(File* file, s32 expected, void* dst)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_11(file, dst);
    return 1;
}

//file_getNWords_ifExpected
s32 gsmaker_entrypoint_22(File* file, s32 expected, s32* dst, s32 cnt)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_12(file, dst, cnt);
    return 1;
}

//file_get_ifExpected
s32 gsmaker_entrypoint_23(File* file, s32 expected, void* dst, s32 len)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_13(file, dst, len);
    return 1;
}
//file_getShort_ifExpected
s32 gsmaker_entrypoint_24(File* file, s32 expected, s16* dst)
{
    if (gsmaker_entrypoint_16(file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_14(file, dst);
    return 1;
}

//file_getNShorts_ifExpected
s32 gsmaker_entrypoint_25(File* file, s32 expected, s16* dst, s32 cnt) {
    if (!gsmaker_entrypoint_16(file, expected)) {
        return FALSE;
    }
    else {
        gsmaker_entrypoint_15(file, dst, cnt);
        return TRUE;
    }
}
