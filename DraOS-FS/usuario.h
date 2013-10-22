#ifndef USUARIO_H
#define USUARIO_H
#include "utilerias.h"

class Usuario
{
public:
    Usuario();
    int Indice;
    char Nombre[FS_SIZE_User_Nombre];
    char Clave[FS_SIZE_User_Clave];
    char status;
    int BloqueInicio(SectorCeroInfo *infoDisco);
    static int TamanoEstructura();

};

#endif // USUARIO_H
