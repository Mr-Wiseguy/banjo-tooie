#ifndef __GC_NEWOPTION_H__
#define __GC_NEWOPTION_H__

typedef struct {
	u8 data[0x260];
} OptionState;

int gcnewoption_entrypoint_2(void);
int _gcnewoption_entrypoint_2(void);

void gcnewoption_entrypoint_7(OptionState* a0);
void _gcnewoption_entrypoint_7(OptionState* a0);

//Setup Option Text
void gcnewoption_entrypoint_12(OptionState* a0, u32 optionIndex, s16 textIndex);
void _gcnewoption_entrypoint_12(OptionState* a0, u32 optionIndex, s16 textIndex);

void gcnewoption_entrypoint_41(OptionState*, u8);
void _gcnewoption_entrypoint_41(OptionState*, u8);

#endif
