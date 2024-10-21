#ifndef __BS_H__
#define __BS_H__

#include "ba/playerstate.h"

typedef enum {
    BS_SCRIPT_TYPE_0,
    BS_SCRIPT_TYPE_1_INIT,
    BS_SCRIPT_TYPE_2_UPDATE,
    BS_SCRIPT_TYPE_3
} BsScriptType;

typedef void (*BsScript)(PlayerState *);

#endif // __BS_H__
