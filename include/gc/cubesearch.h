#ifndef __GC_CUBESEARCH_H__
#define __GC_CUBESEARCH_H__

#include "common.h"
#include "props.h"
#include "gs/propmarker.h"
#include "core2/1E96E60.h"
#include "core2/1EC2FD0.h"
#include "core2/1EC8070.h"

Prop* _gccubesearch_entrypoint_0(PropId, Actor*);
Prop* _gccubesearch_entrypoint_1(PropId, f32[3]);
s32 _gccubesearch_entrypoint_3(s32, f32[3]);
s16* _gccubesearch_entrypoint_6(s32*, s32);
//Find all props of type
s32 _gccubesearch_entrypoint_9(PropId, Prop**, s32);

#endif
