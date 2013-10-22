#include "mapabits.h"
#include "utilerias.h"

MapaBits::MapaBits()
{
    Indice=-1;
    status='0';
}

int MapaBits::TamanoEstructura()
{
    return sizeof(MapaBits);
}

int MapaBits::BloqueInicio(SectorCeroInfo *infoDisco)
{
    int b=infoDisco->BloqueInicioMapaBits+((Indice >1?(Indice-1):0)*TamanoEstructura());

    return b;
}

int MapaBits::BloqueInicio(SectorCeroInfo *infoDisco,int NoCluster)
{
    int b=infoDisco->BloqueInicioMapaBits+((NoCluster >1?(NoCluster-1):0)*TamanoEstructura());

    return b;
}

int MapaBits::BloqueInicioCluster(SectorCeroInfo *infoDisco)
{
    int b=infoDisco->BloqueInicioDatos+((Indice >1?(Indice-1):0)*Utilerias::TamanoCluster());

    return b;
}
