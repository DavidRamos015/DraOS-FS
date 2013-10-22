#include "datablock.h"
#include "utilerias.h"
DataBlock::DataBlock()
{
    Siguiente=-1;//un puntero(posicion en el disco) al siguiente bloqe de datos

    for(int i=0;i<FS_SIZE_BUFFER;i++)
    {
        Buffer[i]=' ';
    }

    BufferPosicion=FS_SIZE_BUFFER-1;//indicar hasta que posicion se lleno

}

int DataBlock::TamanoEstructura()
{
    return sizeof(DataBlock);
}

int DataBlock::BloqueInicio(SectorCeroInfo *infoDisco,int NoCluster)
{
    int b=infoDisco->BloqueInicioDatos+((NoCluster >1?(NoCluster-1):0)*TamanoEstructura());

    return b;
}
