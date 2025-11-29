#include "su/restart.h"

typedef struct {
    s16 respawnMap;
    s16 transformationMap; //Used by Mumbo transformations to tell what level he is in
    u8 transformation;
    u8 entranceId;
} RestartData;

extern RestartData D_808000D0_surestart[];

void surestart_entrypoint_0(s32 arg0)
{
    s32 transformationHome;
    s32 currentMap;
    s32 mapId;
    s32 entranceId;
    s32 i = 0;
    currentMap = func_800EA05C();
    if (arg0 == 1)
    {
        func_8009EBD0();
        return;
    }
    for (i = 0; i < 20; i++)
    {
        if ((arg0 == D_808000D0_surestart[i].transformation) && (transformationHome = D_808000D0_surestart[i].transformationMap, (transformationHome == 0) || (currentMap == transformationHome)))
        {
            mapId = D_808000D0_surestart[i].respawnMap;
            entranceId = D_808000D0_surestart[i].entranceId;
            if ((transformationHome == MAP_13E_CCL_MUMBO) || (transformationHome == MAP_13F_CCL_MINGY_JONGO))
            {
                if (func_800DA298(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0)
                {
                    entranceId = 9;
                }
            }
            func_8009EB24(mapId, entranceId);
            return;
        }
    }
}
