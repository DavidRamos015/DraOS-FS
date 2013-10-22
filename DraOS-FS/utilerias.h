#ifndef UTILERIAS_H
#define UTILERIAS_H
#include <string>
#include <QMessageBox>
#include <QString>
#include "sectorceroinfo.h"
#include <stdint.h>
#include "fstream"
#include "iostream"
#include "sstream"

using namespace std;

enum ColumnIndex
{
    FS_Indice=0,
    FS_Nombre=1,
    FS_Extension=2,
    FS_FechaCreacion=3,  
    FS_FechaModificacion=4,
    FS_Tamano=5,
    FS_Propietario=6,
    FS_Permiso=7,
    FS_BloqueDatosInicio=8,
    FS_Padre=9,
    FS_NoCluster=10
};

enum FS_SIZE
{
    FS_SIZE_User_Nombre=12,
    FS_SIZE_User_Clave=10,
    FS_SIZE_Dir_Nombre=20,
    FS_SIZE_Dir_Extension=3,
    FS_SIZE_Dir_Permiso=3,
    FS_SIZE_BUFFER=504
};

enum FSStatus
{
    DiscoNoExiste=0,
    DiscoSinFormato=1,
    DiscoNoAbierto=2,
    DiscoConFormato=3
};

class Utilerias
{
public:
    Utilerias();
    static void MostraAlerta(QString mensaje,QString titulo);
    static void MostraAlerta(QString mensaje);
    static void MostraAlertaStd(string mensaje);
    static bool Preguntar(QString mensaje);
    static SectorCeroInfo InfoDisco;
    static string Trim(string w);
    static string getFileExtension(string path);
    static string getFileName(string path);

    static QString PadLeft(QString w,int len, char padding);
    static int TamanoSectorCero();
    static int TamanoUsuario();
    static int TamanoCluster();
    static int TamanoDisco;
    static int TamanoMapaBits();
    static int TamanoDirectorio();
    static int IndiceUsuarioActual;
    static const int UsuariosSoportado;
    static const char *PathDisco;
    static int GetHashNextUserPointer(SectorCeroInfo infoDisco, int CurrentNumber);
    static long getFileSize(FILE *file);
    static long getFileSize(string Path);

};

#endif // UTILERIAS_H
