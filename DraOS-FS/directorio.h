#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include <string>
#include <QString>
#include "utilerias.h"
#include <ctime>
#include <stdio.h>
#include <time.h>

using namespace std;
class Directorio
{
public:
    Directorio();

    int Indice;    
    int NoCluster;
    int Padre;
    int Tamano;
    int Propietario;

    char Nombre[FS_SIZE_Dir_Nombre];
    char Extension[FS_SIZE_Dir_Extension];
    char Permiso[FS_SIZE_Dir_Permiso];

    time_t Creado;
    time_t Modificado;

    char status;

    string ArrayToString(char * arreglo,int cant);
    QString ArrayToQString(char * arreglo,int cant);

    QString getFechaModificado();
    QString getFechaCreado();
    QString getExtension();
    QString getPermisos();
    QString getNombre();

    static int TamanoEstructura();
    int BloqueInicio(SectorCeroInfo *infoDisco);
    int BloqueInicioMapaBits(SectorCeroInfo *infoDisco);
    int BloqueInicioClusterDatos(SectorCeroInfo *infoDisco);

    void SetNombre(string s);
    void setExtension(string s);
    void setPermiso(string s);

    void setFechaCreo();
    void setFechaMod();


};

#endif // DIRECTORIO_H
