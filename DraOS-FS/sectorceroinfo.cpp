#include "sectorceroinfo.h"

SectorCeroInfo::SectorCeroInfo()
{
    TamanoDisco=0;
    NoCluster=0;
    BloqueInicioDatos=0;
    BloqueInicioUsuarios=0;
    BloqueInicioMapaBits=0;
    BloqueInicioDirectorio=0;
    EspacioUsado=0;
}

int SectorCeroInfo::TamanoEstructura()
{
    return sizeof(SectorCeroInfo);
}


