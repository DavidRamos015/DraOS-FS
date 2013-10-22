#ifndef DATABLOCK_H
#define DATABLOCK_H
#include "utilerias.h"
class DataBlock
{
public:
    DataBlock();
    char Buffer[FS_SIZE_BUFFER];
    int Siguiente;
    int BufferPosicion;
    static int TamanoEstructura();
    int BloqueInicio(SectorCeroInfo *infoDisco,int NoCluster);
};

#endif // DATABLOCK_H
