#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <sstream>
#include <QTableWidgetItem>
#include <QDataStream>
#include <QSplitter>
#include <QAbstractItemModel>
#include <QItemSelectionModel>
#include <QTableView>
#include <QSqlTableModel>
#include <QString>
#include "pila.h"
#include "sectorceroinfo.h"
#include "directorio.h"
#include "utilerias.h"
#include "fileproperties.h"
#include "mapabits.h"
#include "datablock.h"


using namespace std;

namespace Ui {
class FileExplorer;
}

class FileExplorer : public QDialog
{
    Q_OBJECT
    
public:
    explicit FileExplorer(QWidget *parent = 0);

    pila_ Pila;
    SectorCeroInfo *infoDisco;
    QList<Directorio> archivos;
    QTableWidgetItem *SelectedItem;

    QString GetTableValue(int row,ColumnIndex col);
    Directorio getDirectorio(int row);
    Directorio getDataNuevoDirectorio(bool &Encontrado,int IndiceOmitir);
    list<Directorio> getSubDirectorios(Directorio dir);
    MapaBits GetClusterDisponible(fstream *disco,QList<MapaBits> bitsReservados);
    QList<int> ListMpbToIdxList(QList<MapaBits> bits);
    bool ExportarArchivo(bool MostrarAlertas,Directorio dir,QString location);
    void LeerCluster(DataBlock bloque, fstream *disco,fstream *Archivo);
    void EliminarCluster(MapaBits mpb, fstream *disco,int &ContadorEspacioLiberado);
    void GetDirectoriosEliminar(list<Directorio> &ListaDir,Directorio dir);
    void CrearDirectorio(QString location,Directorio dir);
    void CrearSubDirectorios(QString location, Directorio dir, bool Preguntar);

    void loadRoot();
    void LoadSchema(int indexToShow,Directorio Item,bool HaciaAtras,bool InsertarEnPila);
    void LoadSchema(QTableWidgetItem *SelectedItem);
    void SetCurrentDir();


    ~FileExplorer();
    
private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_btnNext_clicked();
    void on_btnBack_clicked();
    void On_LoadRoot();

    void on_btnClose_clicked();

    void on_btnHome_clicked();

    void on_btnNewFolder_clicked();

    void on_btnModificar_clicked();

    void on_btnEliminar_clicked();

    void on_btnOpen_clicked();

    void on_btnSave_clicked();

private:
    Ui::FileExplorer *ui;
};

#endif // FILEEXPLORER_H
