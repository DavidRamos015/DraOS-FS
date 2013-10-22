#ifndef SECTORCEROINFO_H
#define SECTORCEROINFO_H

class SectorCeroInfo
{
public:
    SectorCeroInfo();
    int TamanoDisco;
    int NoCluster;
    int BloqueInicioDatos;
    int BloqueInicioUsuarios;
    int BloqueInicioMapaBits;
    int BloqueInicioDirectorio;
    int EspacioUsado;
    static int TamanoEstructura();
};

#endif // SECTORCEROINFO_H
