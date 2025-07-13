#ifndef __SU_MOLE__
#define __SU_MOLE__

typedef struct {
	u32 charactersAllowed;
	u16 CannotAffordDialog;
	u16 MoveTutorialDialog;
	u16 AlreadyLearnedDialog;
	u8 AbilityToLearn;
	u8 unk11; //0x11
	u16 price;
	u16 TitleToShow;
} MoveData;

void _sumole_entrypoint_3(void*, u32, u32, MoveData*);
void _sumole_entrypoint_4(void*, MoveData*);

#endif