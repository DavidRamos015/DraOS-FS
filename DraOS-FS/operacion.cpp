#include "operacion.h"
#include <QDebug>
#include <stdio.h>
#include "timeclass.h"

typedef unsigned char BYTE;

Operacion::Operacion()
{
}





char *Operacion::IntToChar(int value)
{
    //char *c=new char[sizeof(value)];
    char *c=new char();
    itoa(value,c,sizeof(value));

    return c;
}

//fstream & operator <<(fstream output,SectorCeroInfo disk)
//{
//    output.write(*(char)disk.TamanoDisco,sizeof(disk.TamanoDisco));
//}


list<QListWidgetItem> Operacion::LeerUsuarios(SectorCeroInfo &InfoDisco)
{
    fstream disco;
    disco.open(Utilerias::PathDisco);

    list<QListWidgetItem> ListItem;

    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir.");
        return ListItem;
    }

    disco.seekp(0,ios::beg);
    int posdisk=InfoDisco.BloqueInicioUsuarios;
    disco.seekp(posdisk);


    int pos=0;
    while(pos < Utilerias::UsuariosSoportado)
    {
        Usuario usuario;
        disco.read((char*)&usuario, sizeof(usuario));
        QListWidgetItem newItem;

        string nombre=ArrayToString((char*)&usuario.Nombre,FS_SIZE_User_Nombre);
        string Clave= ArrayToString((char*)&usuario.Clave,FS_SIZE_User_Clave);
        string status=ArrayToString((char*)&usuario.status,1);
        QString indice=QString("%0").arg(usuario.Indice);

        if (usuario.Indice>=10)
            indice=indice.leftJustified(9,' ');
        else
            indice=indice.leftJustified(10,' ');


        if (status!="x")
        {
            newItem.setText(QString("%0 - %1 - %2").arg(indice).arg(QString::fromStdString(nombre)).arg(QString::fromStdString(Clave)));
            ListItem.push_back(newItem);
        }
        pos++;
    }

    if (ListItem.empty())
    {
        QListWidgetItem newItem;
        newItem.setText("No hay usuarios registrados.");
        ListItem.push_back(newItem);
    }


    return ListItem;

}

FSStatus Operacion::StatusDisco(SectorCeroInfo &InfoDisco)
{
    FILE *file = NULL;

    //Verificar si existe y puede abrir
    if ((file = fopen(Utilerias::PathDisco, "rw")) == NULL)
    {
        Utilerias::MostraAlertaStd("No se puede abrir el disco.");
        return DiscoNoExiste;//Disco no encontrado
    }

    fstream disco;
    disco.open(Utilerias::PathDisco);

    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir.");
        return DiscoNoAbierto;
    }


    disco.seekp(0,ios::beg);
    int tamArchivo= Utilerias::getFileSize(file);
    fclose(file);

    disco.read((char*)&InfoDisco, sizeof(InfoDisco));

    int pos=disco.tellp();

    disco.close();

    if (InfoDisco.TamanoDisco!=Utilerias::TamanoDisco && tamArchivo < Utilerias::TamanoSectorCero())
    {
        return DiscoSinFormato;
    }

    return DiscoConFormato;
}

string Operacion::ArrayToString(char *arreglo, int cant)
{
    string cad="";
    for(int i=0;i< cant;i++)
    {
        cad+=arreglo[i];
    }

    return cad;
}

bool Operacion::FormatearDisco(SectorCeroInfo &InfoDisco)
{
    if(!Utilerias::Preguntar("Desea formatear el disco?"))
        return false;

    fstream disco;
    disco.open(Utilerias::PathDisco);
    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir.");
        return false;
    }


    int TamanoDisco=Utilerias::TamanoDisco;//10 mb
    int TablaDatos=TamanoDisco*0.90;//90%
    int EspacioOtrasTablas=TamanoDisco*0.10;//10%
    int EspacioUsado=0;

    printf("\nEspacio para bloque de datos %u",TablaDatos);
    printf("\nEspacio para informacion y otras tablas %u",EspacioOtrasTablas);


    int NoCluster=TablaDatos/Utilerias::TamanoCluster();
    printf("\nCantidad de Cluster %u",NoCluster);

    //Definir espacio para mapa de bits
    int TamanoXMapaBits=Utilerias::TamanoMapaBits();
    int TamanoTMapaBits=NoCluster*TamanoXMapaBits;
    printf("\nIndices de mapas de bits %u",NoCluster);
    printf("\nEspacio para mapas de bits %u",TamanoTMapaBits);

    //Definir espacio para usuarios
    int UsuariosSoportado=Utilerias::UsuariosSoportado;
    int TamanoXUsuario=Utilerias::TamanoUsuario();
    int TamanoTUsuarios=UsuariosSoportado*TamanoXUsuario;
    printf("\nEspacio para usuarios %u",TamanoTUsuarios);

    //Definir espacio e informacion para sector Cero
    int TamanoTSectorCero=Utilerias::TamanoSectorCero();

    //Definir espacio para tabla de Directorios
    int TamanoTDirectorios=EspacioOtrasTablas-(TamanoTSectorCero+TamanoTUsuarios+TamanoTMapaBits);
    int TamanoXDirectorio=Utilerias::TamanoDirectorio();
    int CantDirectorios=TamanoTDirectorios/TamanoXDirectorio;
    printf("\nTamano para Directorios %u",TamanoTDirectorios);
    printf("\nCantidad de Directorios %u",CantDirectorios);

    //Definir informacion para sector Cero
    int BloqueInicioUsuarios=-1;//TamanoTSectorCero;
    int BloqueInicioMapaBits=-1;//(BloqueInicioUsuarios+1)+TamanoTUsuarios;
    int BloqueInicioDirectorio=-1;//(BloqueInicioMapaBits+1)+ TamanoTMapaBits;
    int BloqueInicioDatos=-1;//(BloqueInicioDirectorio+1)+TamanoTDirectorios;

    //    printf("\n\n\nInformacion sector cero");
    //    printf("\nTamano Disco %u",TamanoDisco);
    //    printf("\nNo Cluster %u",NoCluster);
    //    printf("\nBloque Inicio Sector 0 %u",0);
    //    printf("\nBloque Inicio Usuarios %u",BloqueInicioUsuarios);
    //    printf("\nBloque Inicio MapaBits %u",BloqueInicioMapaBits);
    //    printf("\nBloque Inicio Directorio %u",BloqueInicioDirectorio);
    //    printf("\nBloque Inicio Datos %u",BloqueInicioDatos);

    //    printf("\n\n\nEspacio asignado  %u",TamanoDisco);
    //    printf("\nEspacio consumido %u",(TamanoTSectorCero+TamanoTUsuarios+TamanoTMapaBits+TamanoTDirectorios+TablaDatos));


    printf("\n\n\n************* FORMATO DE DISCO *************");

    printf("\nEscribiendo Sector Cero");

    // Escribir informacion del sector 0
    SectorCeroInfo sectorCero;
    sectorCero.TamanoDisco=TamanoDisco;
    sectorCero.NoCluster=NoCluster;
    sectorCero.BloqueInicioUsuarios=BloqueInicioUsuarios;
    sectorCero.BloqueInicioMapaBits=BloqueInicioMapaBits;
    sectorCero.BloqueInicioDirectorio=BloqueInicioDirectorio;
    sectorCero.BloqueInicioDatos=BloqueInicioDatos;
    sectorCero.EspacioUsado=EspacioUsado;


    disco.seekp(0,ios::beg);
    int tam=sizeof(sectorCero);
    disco.write((char*)&sectorCero,sizeof(sectorCero));


    // crear espacio para usuarios
    // disco.seekp(BloqueInicioUsuarios);
    BloqueInicioUsuarios=disco.tellg();
    for(int i=0;i<UsuariosSoportado;i++)
    {
        int pos=disco.tellg();
        Usuario usuario;
        usuario.Indice=i+1;
        tam=sizeof(usuario);
        disco.write((char*)&usuario,sizeof(usuario));
        disco.seekp(pos+ usuario.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();
    }


    // Espacio tabla mapa de bits,crear un espacio por cada cluster
    // disco.seekp(BloqueInicioMapaBits);
    BloqueInicioMapaBits=disco.tellg();
    for(int i=0;i<NoCluster;i++)
    {
        int pos=disco.tellg();
        MapaBits mpb;
        mpb.Indice=i+1;
        tam=sizeof(mpb);
        disco.write((char*)&mpb,sizeof(mpb));
        disco.seekp(pos+mpb.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();
    }

    // Crear espacio para directorios,crear una estructura por cada directorio
    // disco.seekp(BloqueInicioDirectorio)
    BloqueInicioDirectorio=disco.tellg();
    TimeClass dt;
    for(int i=0; i<CantDirectorios ;i++)
    {
        Directorio dir;

        int pos=disco.tellg();
        dir.Indice=i+1;
        dir.Padre=-1;

        //qDebug() << "\nGuardando indice:" << (i+1) << " pos:" << pos <<" info Directorio= index" << dir.Indice << " Pos Hash:"<< BloqueInicioDirectorio+dir.BloqueInicio(&InfoDisco);

        if (i<2)
        {
            dt.RefrescarFecha();
            dir.SetNombre("Carpeta #" + QString::number(i+1).toStdString());
            dir.Padre=0;//Root
            dir.setFechaCreo();
            //dir.setHoraCreo(dt.HoraActual_103());
            dir.Propietario=Utilerias::IndiceUsuarioActual;
            //dir.Tamano=0;
            dir.status='1';
            EspacioUsado+=sizeof(dir);
        }

//        if (i>5 && i <=10)
//        {
//            dt.RefrescarFecha();
//            dir.setExtension("FFF");
//            dir.setFechaCreo();
//            //dir.setHoraCreo(dt.HoraActual_103());
//            dir.SetNombre("Carpeta #" + QString::number(i+1).toStdString());
//            dir.Padre=1;//Carpeta #1
//            dir.Propietario=Utilerias::IndiceUsuarioActual;
//            //dir.Tamano=0;
//            dir.status='1';
//            EspacioUsado+=sizeof(dir);
//        }

        tam=sizeof(dir);
        dir.Tamano=tam;

        if (tam != dir.TamanoEstructura())
        {
            Utilerias::MostraAlerta(QString("Algo raro ocurrio, la clase mide %0").arg(tam));
            break;
        }

        disco.write((char*)&dir,sizeof(dir));
        disco.seekp(pos+dir.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();
    }







    // Crear el espacio del bloque de datos,crear un bloque por cada cluster
    // disco.seekp(BloqueInicioDatos)
    BloqueInicioDatos=disco.tellg();
    for(int i=0;i< NoCluster;i++)
    {
        int pos=disco.tellg();
        DataBlock bloque;
        bloque.Siguiente=-1;
        tam=sizeof(bloque);
        disco.write((char*)&bloque,sizeof(bloque));
        disco.seekp(pos+bloque.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();
    }


    int UltimaPosicion=disco.tellg();


    //volver a grabar nuevas posiciones del sector cero(0)
    sectorCero.TamanoDisco=UltimaPosicion;
    sectorCero.NoCluster=NoCluster;
    sectorCero.BloqueInicioUsuarios=BloqueInicioUsuarios;
    sectorCero.BloqueInicioMapaBits=BloqueInicioMapaBits;
    sectorCero.BloqueInicioDirectorio=BloqueInicioDirectorio;
    sectorCero.BloqueInicioDatos=BloqueInicioDatos;
    sectorCero.EspacioUsado=EspacioUsado;
    disco.seekp(0,ios::beg);
    UltimaPosicion=disco.tellg();
    disco.write((char*)&sectorCero,sizeof(sectorCero));

    //liberar archivo
    disco.close();

    //Establecer informacion del disco en memoria
    InfoDisco=sectorCero;

    Utilerias::MostraAlerta("El disco ha sido formateado.");

    cout <<"\n\n\n";
    return true;
}

