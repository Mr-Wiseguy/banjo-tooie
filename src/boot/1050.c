#include "buffers.h"

// core1 entrypoint
void func_80012030();

// Boot segment versions of libultra symbols.
s32 boot___osPiRawStartDma(s32, u32 , void *, u32 );
u32 boot_osPiGetStatus(void);
void boot_osInitialize(void);

// core1 ROM addresses.
extern u8 core1_compressed_ROM_START[];
extern u8 core1_compressed_ROM_END[];
extern u8 core1_VRAM[];

// bootproc
void func_80000450(s32 arg0) {
    s32 compressed_data;
    void* decompressed_data;

    compressed_data = COMPRESSION_BUFFER;
    decompressed_data = core1_VRAM;
    boot_osInitialize();

    // Perform a raw PI DMA to load the compressed core1 segment into the compression buffer.
    boot___osPiRawStartDma(OS_READ, core1_compressed_ROM_START, compressed_data, core1_compressed_ROM_END - core1_compressed_ROM_START);
    while (boot_osPiGetStatus() & PI_STATUS_DMA_BUSY) {
        ;
    }

    // Build huft codes.
    func_80000540();
    
    // Decompress core1 .text.
    func_80000560(&compressed_data, &decompressed_data);
    // Get core1 .text checksums.
    D_80012000 = func_800005EC();
    D_80012004 = func_8000060C();

    // Decompress core1 .data/.rodata.
    func_80000560(&compressed_data, &decompressed_data);
    // Get core1 .data/.rodata checksums.
    D_80012008 = func_800005EC();
    D_8001200C = func_8000060C();

    // Load core2 addresses.
    func_80000670();

    // Run the core1 entrypoint.
    (&func_80012030)(arg0);
}
