#ifndef FSEXPLORER_H
#define FSEXPLORER_H

#include <QMainWindow>
#include "operacion.h"
#include "fileexplorer.h"

namespace Ui {
class FSExplorer;
}

class FSExplorer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FSExplorer(QWidget *parent = 0);
    Operacion *operacion;
    SectorCeroInfo InfoDisco;
    FSStatus status;
    void EstablecerInformacionDisco();
    ~FSExplorer();
    
private slots:

    void on_btnUsuario_clicked();

    void on_btnFormato_clicked();

    void on_btnFilesSystem_clicked();

private:
    Ui::FSExplorer *ui;
};

#endif // FSEXPLORER_H
