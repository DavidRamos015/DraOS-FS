#include "usuario.h"

Usuario::Usuario()
{
    status='0';
    for(int i=0;i<FS_SIZE_User_Nombre;i++)
    {
        if (i<FS_SIZE_User_Clave)
        {
            Clave[i]=' ';
        }
        Nombre[i]=' ';
    }
}


int Usuario::TamanoEstructura()
{
    return sizeof(Usuario);
}

int Usuario::BloqueInicio(SectorCeroInfo *infoDisco)
{
    int b=infoDisco->BloqueInicioUsuarios+((Indice >1?(Indice-1):0)*TamanoEstructura());

    return b;
}
