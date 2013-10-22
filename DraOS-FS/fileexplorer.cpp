#include "fileexplorer.h"
#include "ui_fileexplorer.h"
#include "directorio.h"
#include <QTimer>
#include <QDialog>
#include <QFileDialog>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mapabits.h>
#include <datablock.h>

QString Root="\\Root";

FileExplorer::FileExplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileExplorer)
{
    ui->setupUi(this);

    // ui->tableWidget->hideColumn(FS_BloqueDatosInicio);
    //  ui->tableWidget->hideColumn(FS_Padre);


    ui->btnesc->setVisible(false);
    ui->btnBack->setEnabled(false);
    SelectedItem=NULL;
    QTimer::singleShot(500,this,SLOT(On_LoadRoot()));

    ui->btnBack->setEnabled(false);
    ui->btnClose->setEnabled(false);
    ui->btnHome->setEnabled(false);
    ui->btnNewFolder->setEnabled(false);
    ui->btnNext->setEnabled(false);
    ui->btnOpen->setEnabled(false);
    ui->btnSave->setEnabled(false);
    ui->btnModificar->setEnabled(false);
    ui->btnEliminar->setEnabled(false);



}

FileExplorer::~FileExplorer()
{
    delete ui;
    while(!Pila.es_vacia())
    {
        Pila.Eliminar();
    }

}

void FileExplorer::On_LoadRoot()
{
    loadRoot();
}

void FileExplorer::loadRoot()
{
    Directorio item;
    item.Indice=1;
    item.Padre=0;

    item.SetNombre(Root.toStdString());

    while(!Pila.es_vacia())
    {
        Pila.Eliminar();//vaciar la pila en caso de presionar boton Home
    }

    LoadSchema(item.Padre,item,false,true);//cargar directorio root

    ui->btnBack->setEnabled(false);
    ui->btnClose->setEnabled(true);
    ui->btnHome->setEnabled(false);
    ui->btnNewFolder->setEnabled(true);
    ui->btnNext->setEnabled(true);
    ui->btnOpen->setEnabled(true);
    ui->btnSave->setEnabled(true);
    ui->btnModificar->setEnabled(true);
    ui->btnEliminar->setEnabled(true);

}

void FileExplorer::LoadSchema(int indexToShow,Directorio Item,bool HaciaAtras,bool InsertarEnPila)
{
    fstream disco;
    disco.open(Utilerias::PathDisco);

    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir.");
        return;
    }


    ui->tableWidget->clearSelection();
    ui->tableWidget->clearContents();
    ui->tableWidget->clearMask();
    ui->tableWidget->clearSelection();
    ui->tableWidget->clearSpans();
    archivos.clear();

    while(ui->tableWidget->rowCount()>0)
    {
        ui->tableWidget->removeRow(0);
    }


    int pos=disco.tellg();
    disco.seekp(0,ios::beg);
    int bid=infoDisco->BloqueInicioDirectorio;
    disco.seekp(bid);
    pos=disco.tellg();

    ui->btnBack->setEnabled(!Pila.es_vacia());



    //Eliminar el ultimo registro o insertar un nivel de profundidad
    if (HaciaAtras)
    {
        Pila.Eliminar();

        ui->btnBack->setEnabled(!Pila.es_vacia());
        ui->btnHome->setEnabled(!Pila.es_vacia());
    }
    else
    {
        if(InsertarEnPila)
            Pila.Insertar(Item);

        if (indexToShow>0)
        {
            ui->btnHome->setEnabled(true);
            ui->btnBack->setEnabled(!Pila.es_vacia());
        }
    }

    SetCurrentDir();//Establecer ubicacion actual en la barra de direcciones

    bool restart=false;
    int LastPos=0;
    while((pos>= infoDisco->BloqueInicioDirectorio) && (pos < infoDisco->BloqueInicioDatos))
    {

//        if (restart)
//        {
//            disco.close();
//            disco.flush();
//            disco.open(Utilerias::PathDisco);

//            if (!disco.is_open())
//            {
//                Utilerias::MostraAlerta("El disco no se pudo abrir.");
//                return;
//            }

//            disco.seekp(0,ios::beg);
//            disco.seekp(LastPos+Utilerias::TamanoDirectorio());
//            restart=false;
//        }

        pos=disco.tellg();//Debug si esta en la posicion correcta
        Directorio dir;
        disco.read((char*)&dir, sizeof(dir));

        //qDebug() << " Size:" << dir.TamanoEstructura() << " Index:" << dir.Indice << " Status:"<< dir.status << " Pos Hash:" << dir.BloqueInicio(infoDisco);

        disco.seekp(pos+dir.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();//Debug si se coloco correctamente
//        if(pos>0)
//            LastPos=pos;
//        else
//        {
//            pos=LastPos;
//            restart=true;
//            continue;
//        }

        if (dir.Padre==indexToShow && dir.status=='1')
        {

            archivos.push_back(dir);
            int cant=ui->tableWidget->rowCount();
            int row = cant;
            ui->tableWidget->insertRow(row);

            cant=ui->tableWidget->rowCount();

            QTableWidgetItem *indice=new QTableWidgetItem(QString("%0").arg(dir.Indice));
            ui->tableWidget->setItem(row,FS_Indice,indice);

            QTableWidgetItem *nombre=new QTableWidgetItem(dir.getNombre());
            ui->tableWidget->setItem(row,FS_Nombre,nombre);

            QString ext=dir.getExtension();
            if (ext.toUpper()=="FFF")
                ext="Carpeta";

            QTableWidgetItem *Extension=new QTableWidgetItem(ext);
            ui->tableWidget->setItem(row,FS_Extension,Extension);

            QTableWidgetItem *FechaCreo=new QTableWidgetItem(dir.getFechaCreado());
            ui->tableWidget->setItem(row,FS_FechaCreacion,FechaCreo);

            QTableWidgetItem *FechaMod=new QTableWidgetItem(dir.getFechaModificado());
            ui->tableWidget->setItem(row,FS_FechaModificacion,FechaMod);

            QTableWidgetItem *Tamano=new QTableWidgetItem(QString("%0").arg(dir.Tamano));
            ui->tableWidget->setItem(row,FS_Tamano,Tamano);

            QTableWidgetItem *Propietario=new QTableWidgetItem(QString("%0").arg(dir.Propietario));
            ui->tableWidget->setItem(row,FS_Propietario,Propietario);

            QTableWidgetItem *Permiso=new QTableWidgetItem(dir.getPermisos());
            ui->tableWidget->setItem(row,FS_Permiso,Permiso);

            QTableWidgetItem *BloqueInicio=new QTableWidgetItem(QString("%0").arg(dir.BloqueInicio(infoDisco)));
            ui->tableWidget->setItem(row,FS_BloqueDatosInicio,BloqueInicio);

            QTableWidgetItem *Padre=new QTableWidgetItem(QString("%0").arg(dir.Padre));
            ui->tableWidget->setItem(row,FS_Padre,Padre);

            QTableWidgetItem *NoCluster=new QTableWidgetItem(QString("%0").arg((QString::number(dir.NoCluster) =="-1"?"":QString::number( dir.NoCluster))));
            ui->tableWidget->setItem(row,FS_NoCluster,NoCluster);
       }
    }

    // Utilerias::MostraAlerta("Finalizado");
    disco.close();


}

void FileExplorer::LoadSchema(QTableWidgetItem *SelectedItem)
{

    if (ui->tableWidget->selectedItems().count()<=0 || !SelectedItem )
    {
        Utilerias::MostraAlerta("Seleccione un archivo");
        return;
    }

    if (SelectedItem->text().isEmpty() || SelectedItem->text().isNull())
        return;

    Directorio item=getDirectorio(SelectedItem->row());

    if (item.getExtension()=="FFF")
    {
        //Si es directorio,cargar los archivos/subdirectorios que contiene
        LoadSchema(item.Indice,item,false,true);
    }
    else
    {
        FileProperties *f=new FileProperties(this);
        f->setPointerClass(&item,infoDisco,archivos);
        f->MostrarInfoArchivo(ui->teDir->toPlainText(),false);
        f->exec();
    }

}

void FileExplorer::SetCurrentDir()
{
    if (Pila.es_vacia())
        ui->teDir->setText(Root);
    else
    {
        QString url=Pila.ObtenerFormatoURL(Root);
        if (url.trimmed().length()<=0)
            ui->teDir->setText(Root);
        else
            ui->teDir->setText(url);
    }

}

QString FileExplorer::GetTableValue(int row, ColumnIndex col)
{
    QString retorno="";
    QTableWidgetItem *item=ui->tableWidget->item(row,col);

    if (SelectedItem->text().isEmpty() || SelectedItem->text().isNull())
        retorno= QString("");
    else
        retorno=item->text();

    if(col==FS_Extension)
        if (retorno=="Carpeta")
            retorno="FFF";

    return retorno;
}

Directorio FileExplorer::getDirectorio(int row)
{
    Directorio dir;

    dir.Indice=GetTableValue(row,FS_Indice).toInt();
    bool encontrado=false;
    foreach (Directorio dirIter, archivos)
    {
        if (dirIter.Indice==dir.Indice)
        {
            dir=dirIter;
            encontrado=true;
            break;
        }
    }

    if (encontrado)
        return dir;

    //no deberia llegar hasta aqui.
    dir.SetNombre(GetTableValue(row,FS_Nombre).toStdString());
    dir.setExtension(GetTableValue(row,FS_Extension).toStdString());
    dir.setPermiso(GetTableValue(row,FS_Permiso).toStdString());
    dir.setFechaCreo();
    dir.setFechaMod();
    dir.Padre=GetTableValue(row,FS_Padre).toInt();
    dir.Tamano=GetTableValue(row,FS_Tamano).toInt();
    dir.Propietario=GetTableValue(row,FS_Propietario).toInt();

    return dir;
}

Directorio FileExplorer::getDataNuevoDirectorio(bool &Encontrado,int IndiceOmitir)
{
    fstream disco;
    disco.open(Utilerias::PathDisco);

    Encontrado=false;
    Directorio temp;

    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir.");
        return temp;
    }


    int pos=disco.tellg();
    disco.seekp(0,ios::beg);
    int bid=infoDisco->BloqueInicioDirectorio;
    disco.seekp(bid);
    pos=disco.tellg();

    while(!disco.eof() && (pos>= infoDisco->BloqueInicioDirectorio) && (pos < infoDisco->BloqueInicioDatos))
    {

        pos=disco.tellg();//Debug si esta en la posicion correcta
        Directorio dir;
        disco.read((char*)&dir, sizeof(dir));

        int temPos=disco.tellg();

        int tam=dir.TamanoEstructura();

        if(temPos<0)
        {
            disco.seekg(pos+tam);
            disco.seekp(pos+tam);//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        }
        //qDebug() << " Size:" << dir.TamanoEstructura() << " Index:" << dir.Indice << " Status:"<< dir.status << " Pos Hash:" << dir.BloqueInicio(infoDisco);

        disco.seekg(pos+tam);
        disco.seekp(pos+tam);//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();//Debug si se coloco correctamente

        if (dir.status=='0' && dir.Indice>0)
        {
            Encontrado=true;
            disco.close();
            return dir;

        }
    }

    disco.close();

    return temp;


}

list<Directorio> FileExplorer::getSubDirectorios(Directorio dir)
{
    list<Directorio> directorios;

    fstream disco;
    disco.open(Utilerias::PathDisco);

    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir. No se pudo obtener subDirectorios.");
        return directorios;
    }



    disco.seekp(0,ios::beg);
    disco.seekp(infoDisco->BloqueInicioDirectorio);
    int pos=disco.tellg();

    while(!disco.eof() && (pos>= infoDisco->BloqueInicioDirectorio) && (pos < infoDisco->BloqueInicioDatos))
    {
        pos=disco.tellg();//Debug si esta en la posicion correcta
        Directorio temp;
        disco.read((char*)&temp, sizeof(temp));

        disco.seekp(pos+temp.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco.tellg();//Debug si se coloco correctamente


        if(temp.Indice==dir.Indice || temp.status=='0')
            continue;

        if (temp.Padre==dir.Indice)
        {
            directorios.push_back(temp);
        }
    }

    disco.close();
    return directorios;
}

QList<int> FileExplorer::ListMpbToIdxList(QList<MapaBits> bits)
{
    QList<int> retorno;

    foreach (MapaBits mpbIter, bits)
    {
        retorno << mpbIter.Indice;
    }

    return retorno;
}

MapaBits FileExplorer::GetClusterDisponible(fstream *disco,QList<MapaBits> bitsReservados)
{
    MapaBits retorno;

    QList<int> indicesOmitir=ListMpbToIdxList(bitsReservados); //lista de indices a no tomar en cuenta

    int pos=disco->tellg();
    disco->seekp(0,ios::beg);
    pos=disco->tellg();
    disco->seekp(infoDisco->BloqueInicioMapaBits);
    pos=disco->tellg();

    while(!disco->eof() && (pos>= infoDisco->BloqueInicioMapaBits) && (pos < infoDisco->BloqueInicioDatos))
    {
        pos=disco->tellg();//Debug si esta en la posicion correcta
        MapaBits mpb;
        disco->read((char*)&mpb, sizeof(mpb));

        disco->seekp(pos+mpb.TamanoEstructura());//Colocarlo manualmente porque por alguna razon lee mas de lo debido
        pos=disco->tellg();//Debug si se coloco correctamente

        //obtener un mapa de bits que no este usado y que no este reservado para posterior uso.
        if(mpb.status=='0' && !indicesOmitir.contains(mpb.Indice))
        {
            retorno=mpb;
            break;
        }
    }

    return retorno;
}

void FileExplorer::CrearSubDirectorios(QString location, Directorio dir,bool Preguntar)
{
    qDebug()<<"\nCrear el directorio " << dir.getNombre().trimmed();
    CrearDirectorio(location,dir);
    qDebug()<<"\nObtener sub directorios de " << dir.getNombre().trimmed();

    if (dir.getExtension()!="FFF")
        return; //obtimizar, si no es carpeta,entonces no necesita recorrer subdirectorios


    list<Directorio> directorios=getSubDirectorios(dir);

    if (directorios.size()>0)
    {
        if (!Preguntar)
        {
            if (!Utilerias::Preguntar("¿Esta carpeta contiene subdirectorios, También desea crear estas carpetas?"))
                return;

            Preguntar=true;
        }

        QString url=location+"\\"+dir.getNombre().trimmed();

        foreach (Directorio dirIterador, directorios)
        {
            CrearSubDirectorios(url,dirIterador,Preguntar);
        }
    }
}

void FileExplorer::GetDirectoriosEliminar(list<Directorio> &ListaDir , Directorio dir)
{
    list<Directorio> directorios=getSubDirectorios(dir);

    if (directorios.size()>0)
    {
        foreach (Directorio dirIterador, directorios)
        {
            GetDirectoriosEliminar(ListaDir,dirIterador);
        }

        ListaDir.push_back(dir);
    }
    else
    {
        ListaDir.push_back(dir);
    }

}

void FileExplorer::CrearDirectorio(QString location, Directorio dir)
{
    if (dir.getExtension()=="FFF")
    {

        location=location+"\\"+dir.getNombre().trimmed();
        string ur =location.toStdString();

        qDebug()<<"Folder creado:" << location;

        int permiso=dir.getPermisos().toInt();

        char *a=new char[strlen(ur.c_str())];
        strcpy(a,ur.c_str());

        //cout << endl << a <<endl;

        int i=0;

#if defined(_WIN32)
        i=mkdir(a);

#elif defined(__linux__)
        i=mkdir(a,permiso);
#else
        i=mkdir(a);
#endif

    }
    else
    {
        location=location+"\\"+dir.getNombre().trimmed();
        ExportarArchivo(false,dir,location);

    }
}

bool FileExplorer::ExportarArchivo(bool MostrarAlertas,Directorio dir,QString location)
{
    if(dir.getExtension()=="FFF")
    {
        if(MostrarAlertas)
            Utilerias::MostraAlerta("Solamente se pueden exportar archivos.");

        return false;
    }

    if(dir.NoCluster<=0)
    {
        if(MostrarAlertas)
            Utilerias::MostraAlerta("El archivo no está asociado a ningún clúster, imposible exportar.");

        return false;
    }

    fstream disco;
    disco.open(Utilerias::PathDisco);

    if (!disco.is_open())
    {
        if(MostrarAlertas)
            Utilerias::MostraAlerta("El disco no se pudo abrir. El archivo no se pudo exportar.");

        return false;
    }

    //Ya contiene el nombre,colocar la extension
    location+="."+dir.getExtension().trimmed();

    //crear archivo
    fstream archivo;
    archivo.open(location.toStdString().c_str(),ios::out);

    if(!archivo.is_open())
    {
        if(MostrarAlertas)
            Utilerias::MostraAlerta("El archivo no se pudo expotar.");

        return false;
    }

    //leer primer cluster de datos
    int posCluster=dir.BloqueInicioClusterDatos(infoDisco);
    disco.seekp(0,ios::beg);
    disco.seekp(posCluster);
    int pos=disco.tellp();

    archivo.seekp(0,ios::beg);

    DataBlock bloque;
    disco.read((char*)&bloque,sizeof(bloque));

    LeerCluster(bloque,&disco,&archivo);

}

void FileExplorer::LeerCluster(DataBlock bloque, fstream *disco,fstream *Archivo)
{
    int BufferPosicion=bloque.BufferPosicion;
    int NextCluster=bloque.Siguiente;
    int currentPosicion=0;

    while(currentPosicion<=BufferPosicion && currentPosicion <FS_SIZE_BUFFER)
    {        
        char ch=bloque.Buffer[currentPosicion];
        Archivo->write((char*)&ch,sizeof(ch));
        currentPosicion++;
    }

    if(NextCluster<=0)
        return;//no hay mas cluster

    int posCluster=bloque.BloqueInicio(infoDisco,NextCluster);
    disco->seekp(0,ios::beg);
    disco->seekp(posCluster);

    DataBlock b2;
    disco->read((char*)&b2,sizeof(b2));

    LeerCluster(b2,disco,Archivo); //leer siguiente cluster

}

void FileExplorer::EliminarCluster(MapaBits mpb, fstream *disco,int &ContadorEspacioLiberado)
{

    mpb.status='0';//colocar como disponible
    int posCluster=mpb.BloqueInicio(infoDisco);
    disco->seekp(0,ios::beg);
    disco->seekp(posCluster);
    disco->write((char*)&mpb,sizeof(mpb));//escribir nuevo estado de mapa de bits
    ContadorEspacioLiberado+=sizeof(mpb); //aumentar contador de espacio liberado

    //obtener bloque de datos del cluster
    posCluster=mpb.BloqueInicioCluster(infoDisco);
    disco->seekp(0,ios::beg);
    disco->seekp(posCluster);
    DataBlock dtBlock;
    disco->read((char*)&dtBlock,sizeof(dtBlock));

    int NextCluster=dtBlock.Siguiente;
    dtBlock.Siguiente=-1;
    dtBlock.BufferPosicion=FS_SIZE_BUFFER-1;
    //vaciar
    for(int i=0;i<FS_SIZE_BUFFER;i++)
    {
        dtBlock.Buffer[i]=' ';
    }

    disco->write((char*)&dtBlock,sizeof(dtBlock)); //escribir nuevo estado de bloque de datos
    ContadorEspacioLiberado+=sizeof(dtBlock); //aumentar contador de espacio liberado

    if(NextCluster<=0)
        return;//no hay mas cluster usados


    posCluster=mpb.BloqueInicio(infoDisco,NextCluster);//obtener la posicion del siguiente bloque

    disco->seekp(0,ios::beg);
    disco->seekp(posCluster);
    MapaBits bmp2;
    disco->write((char*)&bmp2,sizeof(bmp2));//leer siguiente mapa de bits

    EliminarCluster(bmp2,disco,ContadorEspacioLiberado);


}


void FileExplorer::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    SelectedItem=item;
    LoadSchema(item);

}

void FileExplorer::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    SelectedItem=item;
}

void FileExplorer::on_btnNext_clicked()
{
    LoadSchema(SelectedItem);
}

void FileExplorer::on_btnBack_clicked()
{
    if (!Pila.es_vacia())
    {
        Directorio item=Pila.MostrarUltimo();
        LoadSchema(item.Padre,item,true,true);
    }
}

void FileExplorer::on_btnClose_clicked()
{
    if(Utilerias::Preguntar("Desea cerrar el explorador de archivos?"))
        this->close();
}

void FileExplorer::on_btnHome_clicked()
{
    //if(Utilerias::Preguntar("Desea volver al directorio de inicio?"))
    this->loadRoot();
}

void FileExplorer::on_btnNewFolder_clicked()
{
    bool encontrado=false;
    Directorio dir=getDataNuevoDirectorio(encontrado,-2);

    Directorio tempPila;
    tempPila.Indice=1;
    tempPila.Padre=0;
    tempPila.SetNombre(Root.toStdString());

    if (!encontrado || !&dir || dir.Indice<=0)
    {
        Utilerias::MostraAlerta("No se pueden crear mas directorios.");
        return;
    }

    int padre=-1;
    if (Pila.es_vacia() || Pila.Tamano()==1)
        padre=0;//Root
    else
    {
        tempPila=Pila.MostrarUltimo();
        padre=tempPila.Indice;
    }

    if (padre<0)
    {
        Utilerias::MostraAlerta("No se puede determinar la carpeta contenedora para una nueva carpeta.");
        return;
    }

    dir.Propietario=Utilerias::IndiceUsuarioActual;
    FileProperties *f=new FileProperties(this);
    f->setPointerClass(&dir,infoDisco,archivos);
    f->grNuevaCarperta(ui->teDir->toPlainText(),padre,false);
    f->exec();

    if (f->Resultado)
    {
        fstream disco;
        disco.open(Utilerias::PathDisco);

        if (!disco.is_open())
        {
            Utilerias::MostraAlerta("El disco no se pudo abrir.");
            return;
        }

        disco.seekp(0,ios::beg);
        disco.seekp(dir.BloqueInicio(infoDisco));
        int pos=disco.tellg();
        disco.write((char*)&dir,sizeof(dir));
        pos=disco.tellg();

        //Aumentar espacio usado
        infoDisco->EspacioUsado+=sizeof(dir);
        disco.seekp(0,ios::beg);

        SectorCeroInfo disk;
        disk.BloqueInicioDatos=infoDisco->BloqueInicioDatos;
        disk.BloqueInicioDirectorio=infoDisco->BloqueInicioDirectorio;
        disk.BloqueInicioMapaBits=infoDisco->BloqueInicioMapaBits;
        disk.BloqueInicioUsuarios=infoDisco->BloqueInicioUsuarios;
        disk.EspacioUsado=infoDisco->EspacioUsado;
        disk.NoCluster=infoDisco->NoCluster;
        disk.TamanoDisco=infoDisco->TamanoDisco;

        disco.write((char*)&disk,sizeof(disk));
        pos=disco.tellg();
        disco.close();

        //Refrescar listado
        LoadSchema(padre,tempPila,false,false);

    }
}

void FileExplorer::on_btnOpen_clicked()
{
    if (ui->tableWidget->selectedItems().count()<=0 || !SelectedItem )
    {
        Utilerias::MostraAlerta("Seleccione un archivo.");
        return;
    }

    if (SelectedItem->text().isEmpty() || SelectedItem->text().isNull())
        return;

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setViewMode(QFileDialog::List);

    Directorio CurrentDir=getDirectorio(SelectedItem->row());

    if(CurrentDir.getExtension()=="FFF")
    {
        QString location=dialog.getExistingDirectory(this);

        if(location.trimmed().length()<=0)
        {
            return;
        }

        location=location+"\\";

        qDebug()<<"\n\n\n********* Entrando al proceso de creacion de directorios *********\n\n";
        CrearSubDirectorios(location,CurrentDir,false);
        qDebug()<<"\n\n\n ********* Saliendo de proceso de creacion de directorios *********\n\n";
    }
    else
    {
        FileProperties *f=new FileProperties(this);
        f->setPointerClass(&CurrentDir,infoDisco,archivos);
        f->MostrarInfoArchivo(ui->teDir->toPlainText(),false);
        f->exec();

        if (f->Resultado)
        {
            //preguntar ruta despues de aceptar
            QString location=dialog.getExistingDirectory(this);

            if(location.trimmed().length()<=0)
            {
                return;
            }

            location=location+"\\"+CurrentDir.getNombre().trimmed();
            if (ExportarArchivo(true,CurrentDir,location))
                Utilerias::MostraAlerta("El archivo ha sido exportando en:" +location.trimmed());
        }

    }
}

void FileExplorer::on_btnModificar_clicked()
{
    if (ui->tableWidget->selectedItems().count()<=0 || !SelectedItem )
    {
        Utilerias::MostraAlerta("Seleccione un archivo");
        return;
    }

    if (SelectedItem->text().isEmpty() || SelectedItem->text().isNull())
        return;

    Directorio dir=getDirectorio(SelectedItem->row());
    Directorio tempPila;
    tempPila.Indice=1;
    tempPila.Padre=0;
    tempPila.SetNombre(Root.toStdString());

    int padre=-1;
    if (Pila.es_vacia() ||  Pila.Tamano()==1)
        padre=0;//Root
    else
    {
        tempPila=Pila.MostrarUltimo();
        padre=tempPila.Indice;
    }

    if (padre<0)
    {
        Utilerias::MostraAlerta("No se puede determinar la carpeta contenedora para una nueva carpeta.");
        return;
    }

    FileProperties *f=new FileProperties(this);
    f->setPointerClass(&dir,infoDisco,archivos);
    f->grNuevaCarperta(ui->teDir->toPlainText(),padre,true);
    f->exec();

    if (f->Resultado)
    {
        fstream disco;
        disco.open(Utilerias::PathDisco);

        if (!disco.is_open())
        {
            Utilerias::MostraAlerta("El disco no se pudo abrir.");
            return;
        }


        disco.seekp(0,ios::beg);
        disco.seekp(dir.BloqueInicio(infoDisco));
        int pos=disco.tellg();
        dir.status='1';
        disco.write((char*)&dir,sizeof(dir));
        pos=disco.tellg();
        disco.close();
        LoadSchema(padre,tempPila,false,false);
    }
}

void FileExplorer::on_btnEliminar_clicked()
{
    if (ui->tableWidget->selectedItems().count()<=0 || !SelectedItem )
    {
        Utilerias::MostraAlerta("Seleccione un archivo");
        return;
    }

    if (SelectedItem->text().isEmpty() || SelectedItem->text().isNull())
        return;

    if(!Utilerias::Preguntar("Desea eliminar el archivo seleccionado?"))
        return;

    Directorio dir=getDirectorio(SelectedItem->row());
    Directorio tempPila;
    tempPila.Indice=1;
    tempPila.Padre=0;
    tempPila.SetNombre(Root.toStdString());

    int padre=-1;
    if (Pila.es_vacia() || Pila.Tamano()==1)
        padre=0;//Root
    else
    {
        tempPila=Pila.MostrarUltimo();
        padre=tempPila.Indice;
    }

    list<Directorio> ListaDir ;

    GetDirectoriosEliminar(ListaDir,dir);

    if (ListaDir.size()>1)
    {
        if(!Utilerias::Preguntar("Este directorio contiene subdirectorios, al eliminarlo, estos tambien seran eliminados, Desea continuar?"))
            return;
    }

    fstream disco;
    disco.open(Utilerias::PathDisco);

    if (!disco.is_open())
    {
        Utilerias::MostraAlerta("El disco no se pudo abrir. No se pueden borrar los directorios");
        return;
    }

    disco.seekp(0,ios::beg);
    disco.seekp(infoDisco->BloqueInicioDirectorio);
    int pos=disco.tellg();
    int EspacioLiberado=0;
    foreach (Directorio dirIte, ListaDir)
    {
        //Desabilitar registro
        disco.seekp(dirIte.BloqueInicio(infoDisco));
        pos=disco.tellg();
        dirIte.status='0';

        //Disminuir espacio usado
        EspacioLiberado+=sizeof(dirIte);

        //Escribir cambios en el archivo
        disco.write((char*)&dirIte,sizeof(dirIte));
        pos=disco.tellg();

        if (dirIte.NoCluster>0) // si tiene mapa de bits
        {
            int posMpb=dirIte.BloqueInicioMapaBits(infoDisco);//obtener ubicacion de mapa de bits

            disco.seekp(0,ios::beg);
            disco.seekp(posMpb);
            MapaBits bmp;
            disco.read((char*)&bmp,sizeof(bmp));//leer siguiente mapa de bits
            EliminarCluster(bmp,&disco,EspacioLiberado);
        }
    }

    //Preparar Sector cero para Re-Escribir datos
    SectorCeroInfo disk;
    disk.EspacioUsado=infoDisco->EspacioUsado;//asignar espacio


    disk.BloqueInicioDatos=infoDisco->BloqueInicioDatos;
    disk.BloqueInicioDirectorio=infoDisco->BloqueInicioDirectorio;
    disk.BloqueInicioMapaBits=infoDisco->BloqueInicioMapaBits;
    disk.BloqueInicioUsuarios=infoDisco->BloqueInicioUsuarios;
    disk.NoCluster=infoDisco->NoCluster;
    disk.TamanoDisco=infoDisco->TamanoDisco;

    disk.EspacioUsado=infoDisco->EspacioUsado-EspacioLiberado;//restar espacio liberado
    infoDisco->EspacioUsado=disk.EspacioUsado;//refrescar la clase

    //Escribir nuevos cambios en el sector cero
    disco.seekp(0,ios::beg);
    disco.seekp(0);
    disco.write((char*)&disk,sizeof(disk));
    pos=disco.tellg();
    disco.close();

    //Refrescar listado
    LoadSchema(padre,tempPila,false,false);


}

void FileExplorer::on_btnSave_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setViewMode(QFileDialog::List);


    QString path=dialog.getOpenFileName(this,"Seleccionar archivo");

    if (path.trimmed().length()<=0)
        return;

    //abrir archivo seleccionado
    fstream archivo;
    archivo.open(path.toStdString().c_str());

    if(!archivo.is_open())
    {
        Utilerias::MostraAlerta("El archivo no se pudo abrir. No se podra guardar el registro.");
        return;
    }

    string name=Utilerias::getFileName(path.toStdString());
    string ext=Utilerias::getFileExtension(path.toStdString());
    long size=Utilerias::getFileSize(path.toStdString());

    bool encontrado=false;
    Directorio dir=getDataNuevoDirectorio(encontrado,-2);//obtener siguiente directorio disponible

    if (!encontrado || !&dir || dir.Indice<=0)
    {
        Utilerias::MostraAlerta("No se pudo crear el directorio, es posible que no hayan mas espacio disponible para nuevos archivos.");
        return;
    }

    dir.setFechaCreo();
    dir.SetNombre(name);
    dir.setExtension(ext);
    dir.Tamano=(int)size;
    dir.Propietario=Utilerias::IndiceUsuarioActual;

    //Temporal para obtener cual es el padre/directorio actual
    Directorio tempPila;
    tempPila.Indice=1;
    tempPila.Padre=0;
    tempPila.SetNombre(Root.toStdString());

    int padre=-1;
    if (Pila.es_vacia() || Pila.Tamano()==1)
        padre=0;//Root
    else
    {
        tempPila=Pila.MostrarUltimo();
        padre=tempPila.Indice;
    }

    if (padre<0)
    {
        Utilerias::MostraAlerta("No se puede determinar la carpeta contenedora para este archivo.");
        return;
    }

    dir.Padre=padre;

    FileProperties *f=new FileProperties(this);
    f->setPointerClass(&dir,infoDisco,archivos);
    f->MostrarInfoArchivo(ui->teDir->toPlainText(),true);
    f->exec();

    if (f->Resultado)//si desea guardar el archivo
    {
        fstream disco;
        disco.open(Utilerias::PathDisco);

        if (!disco.is_open())
        {
            Utilerias::MostraAlerta("El disco no se pudo abrir. No se podra guardar el archivo");
            return;
        }

        QList<MapaBits> bits; //listar los mapas de bits usados para escribir posteriormente
        MapaBits mpb=GetClusterDisponible(&disco,bits);

        if(mpb.Indice<=0)
        {
            Utilerias::MostraAlerta("No se puede almacenar este registro, No hay espacio suficiente.");
            return;
        }

        //Crear lista de mapas de bits y bloques de datos usados, y grabar si encontra espacio disponible
        //en caso de no encontrar suficientes cluster disponibles,entonces no grabara nada del bloque de datos, solo

        mpb.status='1';//Colocarlo como activo para solo guardar

        //bits.push_back(&mpb);
        bits << mpb;



        DataBlock bloque;
        QList<DataBlock> blocks;//listar los bloque de datos usados para escribir posteriormente
        //blocks.push_back(&bloque);
        blocks << bloque;

        bool completado=true;
        bool recorrido=false;

        int CurrentPosicion=0;//contador que indica que posicion del buffer se debe asignar

        int CurrentPosPointer=0;
        archivo.seekp(0,ios::beg);
        int pos=archivo.tellg();

        while(!archivo.eof() && CurrentPosPointer <dir.Tamano)
        {
            pos=archivo.tellg();

            char ch;
            archivo.read((char*)&ch,sizeof(ch));
            pos=archivo.tellg();
            archivo.seekp(++CurrentPosPointer);
            pos=archivo.tellg();


            //qDebug() << "\nPos:" << pos << "Contador" << CurrentPosPointer << " tam:" <<dir.Tamano << " char:" << ch;

            if (CurrentPosicion >=FS_SIZE_BUFFER)
            {
                MapaBits NuevoMapaBits=GetClusterDisponible(&disco,bits);//obtener el siguiente mapa de bits disponible
                NuevoMapaBits.status='1';//Colocarlo como activo para solo guardar

                if (NuevoMapaBits.Indice<=0)
                {
                    //generar error, porque si continua asi no encuentra espacio disponible para almacenar todo el registro
                    Utilerias::MostraAlerta("No se puede almacenar este registro, No hay espacio suficiente. No cluster usados:"+QString::number(bits.count()));
                    completado=false;
                    recorrido=false;
                    break;
                }

                bits << NuevoMapaBits;//guardar el mapa de bits usado,este pasara a ser el back

                blocks.back().Siguiente=NuevoMapaBits.Indice; //Establecer al cluster anterior, cual es el siguiente cluster
                blocks.back().BufferPosicion=CurrentPosicion-1;



                DataBlock Nuevobloque;
                blocks << Nuevobloque; //insertar otro bloque,este pasara a ser el back
                CurrentPosicion=0;//reiniciar contador de posicion en el arreglo del buffer
            }

            blocks.back().Buffer[CurrentPosicion]=ch;//almacenar el registro en el ultimo datablock
            blocks.back().BufferPosicion=CurrentPosicion;//en esta variable va almacenando hasta donde leer en cada cluster en caso de que no abarque todo el cluster
            recorrido=true;
            CurrentPosicion++;
        }

        if(completado && recorrido)
        {
            int EspacioConsumido=0;//acumular el espacio ocupado por este registro

            dir.NoCluster=mpb.Indice; //asignar cluster inicial correspondiente

            //Escribir en la tabla de registros
            disco.seekp(0,ios::beg);
            disco.seekp(dir.BloqueInicio(infoDisco));
            int pos=disco.tellg();
            dir.status='1';
            disco.write((char*)&dir,sizeof(dir));
            pos=disco.tellg();//para debug

            EspacioConsumido=sizeof(dir);//usar espacio del directorio

            //Recorrer los mapas de bits usados y ponerlos como no disponibles,escribir el bloque asociado al mapa bits
            CurrentPosicion=0;//inicializar el contador y usarlo como secuencia del mapa de bits para guardar datablock
            foreach (MapaBits mpbIer, bits)
            {
                pos=disco.tellg();

                disco.seekp(0,ios::beg);
                disco.seekp(mpbIer.BloqueInicio(infoDisco)); //posicionar en la ubicacion del mapa de bits
                pos=disco.tellg();//para debug
                disco.write((char*)&mpbIer,sizeof(mpbIer));
                pos=disco.tellg();//para debug

                EspacioConsumido+=sizeof(mpbIer);//aumentar espacio usado por cada mapa bits

                //obtener el datablock asociado al mapa de bits que se esta iterando
                if ( CurrentPosicion<blocks.count())
                {
                    DataBlock blockOfMpb=blocks.at(CurrentPosicion);

                    pos=disco.tellg();
                    disco.seekp(0,ios::beg);
                    disco.seekp(blockOfMpb.BloqueInicio(infoDisco,mpbIer.Indice));//ubicar el puntero en la posicion del cluster segun el mapa bits
                    //pos=disco.tellg();//para debug

                    disco.write((char*)&blockOfMpb,sizeof(blockOfMpb));

                   // pos=disco.tellg();//para debug
                    EspacioConsumido+=sizeof(blockOfMpb);//aumentar espacio usado por cada bloque de datos

                }
                CurrentPosicion++;//aumentar posicion

            }

            //Aumentar espacio usado en sector cero
            infoDisco->EspacioUsado+=EspacioConsumido;
            disco.seekp(0,ios::beg);

            SectorCeroInfo disk;
            disk.BloqueInicioDatos=infoDisco->BloqueInicioDatos;
            disk.BloqueInicioDirectorio=infoDisco->BloqueInicioDirectorio;
            disk.BloqueInicioMapaBits=infoDisco->BloqueInicioMapaBits;
            disk.BloqueInicioUsuarios=infoDisco->BloqueInicioUsuarios;
            disk.EspacioUsado=infoDisco->EspacioUsado;
            disk.NoCluster=infoDisco->NoCluster;
            disk.TamanoDisco=infoDisco->TamanoDisco;

            disco.write((char*)&disk,sizeof(disk));
            pos=disco.tellg();

        }


        archivo.close();
        disco.close();

        //Refrescar listado
        LoadSchema(padre,tempPila,false,false);
    }


}
