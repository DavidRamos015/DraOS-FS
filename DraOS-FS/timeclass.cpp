#include "timeclass.h"

TimeClass::TimeClass()
{
    RefrescarFecha();
}

void TimeClass::RefrescarFecha()
{
    time_t tiempo = time(0);
    struct tm * Actual = localtime( & tiempo );

    Anio=Actual->tm_year + 1900;
    Mes=Actual->tm_mon + 1;
    Dia=Actual->tm_mday;
    DiaSemana=Actual->tm_wday;
    Hora=Actual->tm_hour;
    Minuto=Actual->tm_min;
    Segundo=Actual->tm_sec;
}

string TimeClass::FechaActual()
{
    return (QString::number(Anio) +"/" + QString::number(Mes).rightJustified(2,'0') +"/"+QString::number(Dia).rightJustified(2,'0')).toStdString();
}

string TimeClass::HoraActual()
{
    return (QString::number(Hora).rightJustified(2,'0') +":"+QString::number(Minuto).rightJustified(2,'0')+":"+QString::number(Segundo).rightJustified(2,'0')).toStdString();
}

string TimeClass::FechaActual_103()
{
    return (QString::number(Anio) + QString::number(Mes).rightJustified(2,'0') + QString::number(Dia).rightJustified(2,'0')).toStdString();
}

string TimeClass::HoraActual_103()
{    
    return (QString::number(Hora).rightJustified(2,'0') + QString::number(Minuto).rightJustified(2,'0') + QString::number(Segundo).rightJustified(2,'0')).toStdString();
}
