#include "fsexplorer.h"
#include "ui_fsexplorer.h"
#include "datablock.h"
#include "directorio.h"
#include "sectorceroinfo.h"
#include "usuario.h"
#include "operacion.h"
#include <fstream>
#include <iostream>
#include "formuser.h"

using namespace std;

FSExplorer::FSExplorer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FSExplorer)
{
    ui->setupUi(this);
    // operacion=new operacion();

    status=operacion->StatusDisco(InfoDisco);

    if(status==DiscoConFormato)
    {
        EstablecerInformacionDisco();
    }




}

FSExplorer::~FSExplorer()
{
    delete ui;
}

void FSExplorer::EstablecerInformacionDisco()
{
    ui->lcdNoCluster->display(InfoDisco.NoCluster);
    ui->lcdTamDisco->display(InfoDisco.TamanoDisco);
    ui->lcdUsuarios->display(InfoDisco.BloqueInicioUsuarios);
    ui->lcdMapabits->display(InfoDisco.BloqueInicioMapaBits);
    ui->LcdDirectorios->display(InfoDisco.BloqueInicioDirectorio);
    ui->lcdBloqueDatos->display(InfoDisco.BloqueInicioDatos);
    ui->lcdEspacioUsado->display(InfoDisco.EspacioUsado);
    ui->lcdEspacioDisponible->display(InfoDisco.TamanoDisco-InfoDisco.EspacioUsado);

}



void FSExplorer::on_btnUsuario_clicked()
{
    if (status!=DiscoConFormato)
    {
        Utilerias::MostraAlerta("El disco no esta preparado para esta operación.");
        return;
    }

    list<QListWidgetItem> lista=operacion->LeerUsuarios(InfoDisco);
    formUser *user=new formUser(this);
    user->usuarios=lista;
    user->infoDisco=&InfoDisco;
    user->LoadUser();
    user->exec();
}

void FSExplorer::on_btnFormato_clicked()
{

    status=operacion->StatusDisco(InfoDisco);
    if (status==DiscoNoExiste || status==DiscoSinFormato)
    {
        if (operacion->FormatearDisco(InfoDisco))
        {
            status=operacion->StatusDisco(InfoDisco);
            if(status==DiscoConFormato)
            {
                EstablecerInformacionDisco();
                return;
            }

        }

    }
    else if(status==DiscoConFormato)
    {
        if (Utilerias::Preguntar("El disco tiene formato, Desea volver a formatearlo?"))
        {
            if (operacion->FormatearDisco(InfoDisco))
            {
                status=operacion->StatusDisco(InfoDisco);
                if(status==DiscoConFormato)
                {
                    EstablecerInformacionDisco();
                }

            }
        }
        else
            EstablecerInformacionDisco();
    }

}

void FSExplorer::on_btnFilesSystem_clicked()
{
    if (status!=DiscoConFormato)
    {
        Utilerias::MostraAlerta("El disco no esta preparado para esta operación.");
        return;
    }

    FileExplorer *f=new FileExplorer(this);
    f->infoDisco=&InfoDisco;
    f->exec();

    status=operacion->StatusDisco(InfoDisco);
    if(status==DiscoConFormato)
    {
        EstablecerInformacionDisco();
    }
}
