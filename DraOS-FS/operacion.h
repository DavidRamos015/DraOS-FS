#ifndef OPERACION_H
#define OPERACION_H
#include "fstream"
#include "iostream"
#include "sstream"
#include "sectorceroinfo.h"
#include "utilerias.h"
#include "usuario.h"
#include "mapabits.h"
#include "directorio.h"
#include "datablock.h"
#include <QListWidgetItem>
#include <QTableWidgetItem>

using namespace std;

class Operacion
{
public:
    Operacion();
    FSStatus StatusDisco(SectorCeroInfo &InfoDisco);
    list<QListWidgetItem> LeerUsuarios(SectorCeroInfo &InfoDisco);
    string ArrayToString(char *arreglo,int cant);

    bool FormatearDisco(SectorCeroInfo &InfoDisco);
    char *IntToChar(int value);

};

#endif // OPERACION_H
