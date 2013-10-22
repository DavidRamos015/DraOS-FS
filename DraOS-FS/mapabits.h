#ifndef MAPABITS_H
#define MAPABITS_H

#include "sectorceroinfo.h"

class MapaBits
{
public:
    MapaBits();
    int Indice;
    char status;
    int BloqueInicio(SectorCeroInfo * infoDisco);
    int BloqueInicio(SectorCeroInfo * infoDisco,int NoCluster);
    int BloqueInicioCluster(SectorCeroInfo * infoDisco);
    static int TamanoEstructura();
};

#endif // MAPABITS_H
