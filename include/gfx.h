#ifndef __GFX_H__
#define __GFX_H__

#include <ultra64.h>

#define SCREEN_WIDTH 304
#define SCREEN_HEIGHT 228
#define FRAMEBUFFER_SIZE_BYTES (SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u16))

// Ratio between the anamorphic widescreen aspect ratio (16:9) and the normal one (4:3) 
#define WIDESCREEN_ADJUSTMENT ((16.0f / 9.0f) / (4.0f / 3.0f))

extern s16 widescreen_enabled;

// get_framebuffer_size_bytes
u32 func_80014EC8();

// RSP Segments
typedef enum {
    RSP_SEGMENT_FACE_CULLING = 7
} RSPSegmentId;

#endif
