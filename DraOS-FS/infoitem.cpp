#include "infoitem.h"

infoItem::infoItem()
{
    Indice=-1;
    Nombre="";
}

infoItem::infoItem(int index, string nombre)
{
    Indice=index;
    Nombre=nombre;
}

infoItem::infoItem(int index, QString nombre)
{
    Indice=index;
    Nombre=nombre.toStdString();
}
