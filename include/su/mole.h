#ifndef __SU_MOLE__
#define __SU_MOLE__

#include "common.h"

#include "gl/cutDll.h"
#include "ca/pod.h"

#include "ch/bounce.h"
#include "ch/molehill.h"
#include "ch/appearfx.h"
#include "ch/introtext.h"
#include "ch/baddiesetup.h"

#include "gc/cubesearch.h"
#include "gc/dialogcamera.h"

#include "su/baddiefind.h"
#include "su/baddiedialog.h"
#include "su/baddieDll.h"

#include "nc/poddialog.h"
#include "gs/propctrl.h"

#include "core2/1E99980.h"
#include "core2/1E9A960.h"

#include "core2/1EA0690.h"
#include "core2/1EA9160.h"
#include "core2/1EABAC0.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ED4E30.h"
#include "core2/1EDA900.h"
#include "core2/1EDCA30.h"
#include "core2/1EDFED0.h"
#include "core2/1EE1510.h"
#include "core2/1EE4020.h"
#include "core2/1EE5DF0.h"

typedef struct {
	f32 unk0[3];
	f32 unkC;
	f32 unk10;
	f32 unk14;
	f32 unk18;
	f32 unk1C;
}MoleActorData;

typedef struct {
	AllowedTransformation charactersAllowed;
	u16 CannotAffordDialog;
	s16 MoveTutorialDialog;
	u16 AlreadyLearnedDialog;
	s8 AbilityToLearn;
	u8 unk11;
	u16 price;
	u8 titleToShow;
	u8 unkF;
} MoveData;
void _sumole_entrypoint_0(Actor*, u32);
void sumole_entrypoint_2(Actor*, s32);
void _sumole_entrypoint_3(Actor*, s32, s32, MoveData*);
void _sumole_entrypoint_4(Actor*, MoveData*);
s32 sumole_entrypoint_5(Actor*, s32, AllowedTransformation, s32);
void sumole_entrypoint_7(Actor*);
s32 sumole_entrypoint_8(Actor*, s32);
s32 sumole_entrypoint_10(Actor*, s32);
void sumole_entrypoint_11(Actor*);
s32 sumole_entrypoint_12(Actor*);
s32 sumole_entrypoint_14(Actor*);
s32 sumole_entrypoint_15(Actor*, s32, s32);
void sumole_entrypoint_16(Actor*, s32);
void sumole_entrypoint_18(Actor*, f32);
void sumole_entrypoint_19(Actor*, s32);
s32 sumole_entrypoint_20(Actor*, s32, s32);
#endif