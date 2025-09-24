#ifndef __GC_COLLECT_DLL_H__
#define __GC_COLLECT_DLL_H__

#include "common.h"
#include "gc/gamefix.h"
#include "gl/reflight.h"

#include "core2/1EA9160.h"
#include "core2/1EB3750.h"
#include "core2/1EB45C0.h"
#include "core2/1EC2FD0.h"
#include "core2/1EC8070.h"

#include "core2/1EE1510.h"
#include "core2/1EE27C0.h"

void gccollectDll_entrypoint_0(s32);
void gccollectDll_entrypoint_1();
void _gccollectDll_entrypoint_2();
void _gccollectDll_entrypoint_3();

s32 func_808003E0_gccollectDll(void*, void*);
void func_808005BC_gccollectDll(u32, Prop*);
s32 func_80800660_gccollectDll(void*, void*);
void func_808007D8_gccollectDll(Prop*);
#endif