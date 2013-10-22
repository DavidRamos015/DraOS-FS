#ifndef FILEPROPERTIES_H
#define FILEPROPERTIES_H

#include <QDialog>
#include "directorio.h"
#include <iostream>
#include "utilerias.h"
#include "sectorceroinfo.h"

using namespace std;

namespace Ui {
class FileProperties;
}

class FileProperties : public QDialog
{
    Q_OBJECT
    
public:
    explicit FileProperties(QWidget *parent = 0);

    bool Modificar;
    bool ImportandoArchivo;
    bool Resultado;
    Directorio *dir;
    SectorCeroInfo *infoDisco;
    QList<Directorio> archivos;

    ~FileProperties();
    void setPointerClass(Directorio *Dir,SectorCeroInfo *infDisk,QList<Directorio> _archivos);
    void MostrarInfoArchivo(QString rutaActual,bool Importando);
    void grNuevaCarperta(QString rutaActual,int padre,bool modificar);
    void setStatusControl();

    bool NombreExiste(QString nombre,QString extension, int IndexOmitir);

protected:

private slots:
    void on_btnClose_clicked();

    void on_btnNewFolder_clicked();


    void on_btnOpen_clicked();

private:

    Ui::FileProperties *ui;
};

#endif // FILEPROPERTIES_H
