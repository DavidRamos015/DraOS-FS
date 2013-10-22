#include "directorio.h"
#include <QString>
Directorio::Directorio()
{
    Indice=-1;    
    Padre=-1;
    Tamano=TamanoEstructura();
    NoCluster=-1;
    Propietario=0;
    status='0';

    Modificado=NULL;

    for(int i=0;i<FS_SIZE_Dir_Nombre;i++)
    {
        if (i<FS_SIZE_Dir_Extension)
        {
            Permiso[i]='7';
            Extension[i]='F';
        }

        Nombre[i]=' ';
    }
}



string Directorio::ArrayToString(char *arreglo,int cant)
{    
    string cad="";
    for(int i=0;i< cant;i++)
    {
        cad+=arreglo[i];
    }

    return cad;
}

QString Directorio::ArrayToQString(char *arreglo,int cant)
{
    string cad=ArrayToString(arreglo,cant);

    return QString::fromStdString(cad);
}


void Directorio::setExtension(string s)
{
    int l=sizeof(Extension);
    for(int i=0;i< l;i++)
    {
        if (i>=s.length())
        {
            Extension[i]='F';
            continue;
        }

        Extension[i]=s[i];
    }
}

void Directorio::setFechaCreo()
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    Creado=rawtime;
}

void Directorio::setFechaMod()
{

    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    Modificado=rawtime;
}

void Directorio::SetNombre(string s)
{
    int l=sizeof(Nombre);
    for(int i=0;i< l  ;i++)
    {
        if (i>=s.length())
        {
            Nombre[i]=' ';
            continue;
        }

        Nombre[i]=s[i];
    }
}

void Directorio::setPermiso(string s)
{
    int l=sizeof(Permiso);
    for(int i=0;i< l ;i++)
    {
        if (i>=s.length())
        {
            Permiso[i]='7';
            continue;
        }

        Permiso[i]=s[i];
    }
}

QString Directorio::getFechaCreado()
{
    if (Creado==0)
        return "";
    else
    {
        char buff[20];
        strftime(buff, 20, "%Y/%m/%d %H:%M:%S", localtime(&Creado));
        string f="";
        f.assign(buff,20);
        return QString::fromStdString(f).trimmed();
    }
}
QString Directorio::getFechaModificado()
{
    if (Modificado==0)
        return "";
    else
    {
        char buff[20];
        strftime(buff, 20, "%Y/%m/%d %H:%M:%S", localtime(&Modificado));
        string f="";
        f.assign(buff,20);
        return QString::fromStdString(f).trimmed();
    }
}

QString Directorio::getExtension()
{
    string ext="";
    for(int i=0;i<FS_SIZE_Dir_Extension;i++)
    {
        ext+=Extension[i];
    }

    return QString::fromStdString(ext);
}

QString Directorio::getPermisos()
{
    string ext="";
    for(int i=0;i<FS_SIZE_Dir_Permiso;i++)
    {
        if (isdigit(Permiso[i]))
            ext+=Permiso[i];
        else
            ext+='0';
    }

    return QString::fromStdString(ext);
}

QString Directorio::getNombre()
{

    string n="";
    for(int i=0;i<FS_SIZE_Dir_Nombre;i++)
    {
        n+=Nombre[i];
    }

    return QString::fromStdString(n);
}

int Directorio::TamanoEstructura()
{
    int t=sizeof(Directorio);
    return t;
}

int Directorio::BloqueInicio(SectorCeroInfo *infoDisco)
{
    int b=infoDisco->BloqueInicioDirectorio+((Indice >1?(Indice-1):0)*TamanoEstructura());

    return b;
}

int Directorio::BloqueInicioMapaBits(SectorCeroInfo *infoDisco)
{
    int b=infoDisco->BloqueInicioMapaBits+((NoCluster >1?(NoCluster-1):0)*Utilerias::TamanoMapaBits());

    return b;
}

int Directorio::BloqueInicioClusterDatos(SectorCeroInfo *infoDisco)
{
    int b=infoDisco->BloqueInicioDatos+((NoCluster >1?(NoCluster-1):0)*Utilerias::TamanoCluster());

    return b;
}
