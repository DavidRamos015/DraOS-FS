#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <QString>
#include <QDebug>
#include "directorio.h"
using namespace std;

class nodoP
{
   protected:
               Directorio dato;
               nodoP *next;
   public:
             nodoP(Directorio);
             nodoP *get_siguiente(){return next;}
             Directorio get_dato(){return dato;}
             void set_siguiente(nodoP *x){next=x;}
};

class pila_
{
      private:
              nodoP *pila;
              nodoP *pila_aux;
              int Longitud;
      public:
             pila_();
             bool es_vacia();
             void limpiar_pila(){pila=NULL;}
             void Insertar(Directorio);
             QString ObtenerFormatoURL(QString root);
             void Eliminar();
             Directorio MostrarUltimo();
             void Imprimir();
             void Buscar(Directorio);
             void Eliminar_repetidos();
             int Tamano();
};

#endif // PILA_H
