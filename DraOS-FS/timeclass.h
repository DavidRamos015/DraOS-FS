#ifndef TIMECLASS_H
#define TIMECLASS_H
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <QString>

using namespace std;

class TimeClass
{
public:
    TimeClass();
    int Anio;
    int Mes;
    int Dia;
    int DiaSemana;
    int Hora;
    int Minuto;
    int Segundo;
    string FechaActual();
    string HoraActual();
    string FechaActual_103();
    string HoraActual_103();
    void RefrescarFecha();
};

#endif // TIMECLASS_H
