#include "pila.h"
#include <iostream>


using namespace std;

nodoP::nodoP(Directorio n)
{
      dato=n;
      next=NULL;
}

pila_::pila_()
{
            pila=NULL;
            pila_aux=NULL;
            Longitud=0;
}

bool pila_::es_vacia()
{
     if(pila==NULL){ return true;}
     else {return false;}
}
void pila_::Insertar(Directorio Dato)
{
     nodoP *nuevo;
     nuevo = new nodoP(Dato);
     if (es_vacia())
     {
                     pila = nuevo;
                     Longitud++;
     }
     else
     {
         nuevo->set_siguiente(pila);
         pila = nuevo;
         Longitud++;
     }
}

void pila_::Eliminar()
{
     if (es_vacia()) { cout<<"La pila esta vacia!!!";}
     else
     {

         pila = pila->get_siguiente();
         Longitud--;
     }
}

Directorio pila_::MostrarUltimo()
{
    if (es_vacia()) { cout<<"La pila esta vacia!!!";}
    else
    {
        return pila->get_dato();
    }
}


void pila_::Imprimir()
{
//     if(es_vacia()){cout<<"La pila esta vacia!!!"<<endl;}
//     else
//     {
//          pila_aux=pila;

//          int pos=Longitud;
//          while (pila_aux->get_siguiente()!=NULL)
//          {
//                qDebug()<<" posicion: "<<pos<<" dato: "<<pila_aux->get_dato().Nombre<<endl;

//                pila_aux = pila_aux->get_siguiente();
//                pos--;
//          }
//          qDebug()<<" posicion: "<<pos<<" dato: "<<pila_aux->get_dato().Nombre<<endl;
//          qDebug()<<"n";
//     }
}

QString pila_::ObtenerFormatoURL(QString root)
{
    QString url=root;
     if(!es_vacia())
     {
          pila_aux=pila;

          //url=pila->get_dato().getNombre().trimmed();
          int pos=Longitud;
          while (pila_aux->get_siguiente()!=NULL)
          {
                url+= "\\"+pila_aux->get_dato().getNombre().trimmed();

                pila_aux = pila_aux->get_siguiente();
                pos--;
          }
     }


    return url;
}


void pila_::Buscar(Directorio x)
{
     int pos=Longitud;
     if(es_vacia()){cout<<"La pila esta vacia!!!"<<endl;}
     else
     {
         nodoP *pila_aux_=pila;
         while(pila_aux_->get_dato().Indice!=x.Indice && pila_aux_->get_siguiente()!=NULL)
         {
               pila_aux_=pila_aux_->get_siguiente();
               pos--;
         }
         if(pila_aux_->get_dato().Indice==x.Indice){cout<<"encontrado en la posicion: "<<pos<<endl;}
         else
         {
             cout<<"dato no encontrado"<<endl;
         }
     }
}

int pila_::Tamano()
{
    return Longitud;
}

void pila_::Eliminar_repetidos()
{
     if(es_vacia()){cout<<"La pila esta vacia!!!"<<endl;}
     else
     {
         nodoP *pila_aux_=pila;
         nodoP *p=pila->get_siguiente();
         nodoP *q=pila_aux_;
         while(pila_aux_->get_siguiente()!=NULL)
         {
             p=pila_aux_->get_siguiente();
             while(p->get_siguiente()!=NULL)
             {
                 q=pila_aux_;
                 if(pila_aux_->get_dato().Indice==p->get_dato().Indice)
                 {
                    q->set_siguiente(p->get_siguiente());
                    Longitud--;
                 }
                 p=p->get_siguiente();
             }
             pila_aux_=pila_aux_->get_siguiente();
         }
         Longitud--;
     }
}
