#include "fileproperties.h"
#include "ui_fileproperties.h"
#include "timeclass.h"

using namespace std;

FileProperties::FileProperties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileProperties)
{
    ui->setupUi(this);
    ui->btnNewFolder->setVisible(false);
    Resultado=false;
    Modificar=false;
    ImportandoArchivo=false;
    dir=NULL;

    ui->txtNombre->setMaxLength(FS_SIZE_Dir_Nombre);
    ui->txtPermisos->setMaxLength(FS_SIZE_Dir_Permiso);
    ui->txtNombre->setFocus();
}

void FileProperties::setStatusControl()
{
    ui->txtNombre->setReadOnly(false);
    ui->txtPermisos->setReadOnly(false);
    ui->txtExtension->setReadOnly(true);
    ui->txtFechaCreacion->setReadOnly(true);
    ui->txtFechaMod->setReadOnly(true);
    ui->txtIndice->setReadOnly(true);
    ui->txtPadre->setReadOnly(true);
    ui->txtPosicion->setReadOnly(true);
    ui->txtPropietario->setReadOnly(true);
    ui->txtTamano->setReadOnly(true);
    ui->txtUbicacion->setReadOnly(true);
    ui->txtNombre->setFocus();
}

void FileProperties::setPointerClass(Directorio *Dir, SectorCeroInfo *infDisk,QList<Directorio> _archivos)
{
    this->dir=Dir;
    this->infoDisco=infDisk;
    this->archivos=_archivos;
}

bool FileProperties::NombreExiste(QString nombre,QString extension, int IndexOmitir)
{
    foreach (Directorio dirIer, archivos)
    {
        if(nombre.trimmed()==dirIer.getNombre().trimmed() && dirIer.getExtension().trimmed()==extension.trimmed() && dirIer.Indice!=IndexOmitir)
            return true;
    }

    return false;
}

FileProperties::~FileProperties()
{
    delete ui;
    //delete dir;
}

void FileProperties::grNuevaCarperta(QString rutaActual,int padre,bool modificar)
{
    ui->btnOpen->setVisible(false);
    ui->btnClose->setText("Cancelar");
    ui->btnNewFolder->setVisible(true);
    Modificar=modificar;

    if(!dir)
    {
        Utilerias::MostraAlerta("La información del archivo es invalida.");
        return;
    }

    if (!modificar)//nueva carpeta
    {
        dir->Padre=padre;
        dir->setFechaCreo();
        ui->txtFechaCreacion->setText(dir->getFechaCreado());

    }
    else//modificacion
    {

        ui->txtFechaCreacion->setText(dir->getFechaCreado());
        ui->btnNewFolder->setText("Modificar");
        ui->txtFechaMod->setText(dir->getFechaModificado());
        ui->txtNombre->setText(dir->getNombre().trimmed());
    }

    ui->txtExtension->setText(dir->getExtension());
    ui->txtPermisos->setText(dir->getPermisos());
    ui->txtPadre->setText(QString::number(padre));
    ui->txtIndice->setText(QString::number(dir->Indice));
    ui->txtPropietario->setText(QString::number(dir->Propietario));
    ui->txtTamano->setText(QString::number(dir->Tamano));
    ui->txtPosicion->setText(QString::number(dir->BloqueInicio(infoDisco)));
    ui->txtUbicacion->setText("Guardar en:"+rutaActual);

    setStatusControl();

}


void FileProperties::MostrarInfoArchivo(QString rutaActual,bool Importando)
{
    if(!dir)
    {
        Utilerias::MostraAlerta("La información del archivo es invalida.");
        return;
    }

    ui->btnNewFolder->setVisible(false);
    ui->btnOpen->setVisible(true);
    ImportandoArchivo=Importando;

    ui->txtIndice->setText(QString::number(dir->Indice));
    ui->txtExtension->setText(dir->getExtension().trimmed());


    if (Importando)
    {
        ui->btnOpen->setText("Importar");
        ui->btnClose->setText("Cancelar");
        ui->txtFechaCreacion->setText(dir->getFechaCreado());
    }
    else
    {
        ui->txtFechaCreacion->setText(dir->getFechaCreado());
        ui->txtFechaMod->setText(dir->getFechaModificado());
    }

    ui->txtNombre->setText(dir->getNombre().trimmed());
    ui->txtPadre->setText(QString::number(dir->Padre));
    ui->txtPermisos->setText(dir->getPermisos().trimmed());
    ui->txtPropietario->setText(QString::number(dir->Propietario));
    ui->txtTamano->setText(QString::number(dir->Tamano));
    ui->txtPosicion->setText(QString::number(dir->BloqueInicio(infoDisco)));
    ui->txtUbicacion->setText(rutaActual);
    ui->txtNombre->setFocus();

    setStatusControl();

}

void FileProperties::on_btnClose_clicked()
{
    if(Utilerias::Preguntar("Cerrar ventana de propiedades?"))
    {
        Resultado=false;
        this->close();
    }
}

void FileProperties::on_btnNewFolder_clicked()
{




    //Refrescar textboxs
    if (!Modificar)//nueva carpeta
    {
        if(NombreExiste(ui->txtNombre->text(),ui->txtExtension->text(),-1))
        {
            Utilerias::MostraAlerta("Ya existe un tipo de registro con el mismo nombre,intente con otro.");
            return;
        }

        dir->setFechaCreo();
        ui->txtFechaCreacion->setText(dir->getFechaCreado());
    }
    else//modificacion
    {
        if(NombreExiste(ui->txtNombre->text(),ui->txtExtension->text(),dir->Indice))
        {
            Utilerias::MostraAlerta("Ya existe un tipo de registro con el mismo nombre,intente con otro.");
            return;
        }

        dir->setFechaMod();
        ui->txtFechaMod->setText(dir->getFechaModificado());
    }

    if(!Utilerias::Preguntar(Modificar?"Modificar carperta?":"Crear nueva carpeta?"))
    {
        return;
    }


    if (!Modificar)//nueva carpeta
    {
        dir->setFechaCreo();
        ui->txtFechaCreacion->setText(dir->getFechaCreado());
    }
    else//modificacion
    {
        dir->setFechaMod();
        ui->txtFechaMod->setText(dir->getFechaModificado());
    }

    dir->SetNombre(ui->txtNombre->text().toStdString());
    dir->setPermiso(ui->txtPermisos->text().toStdString());
    dir->status='1';
    Resultado=true;
    this->close();

}


void FileProperties::on_btnOpen_clicked()
{
    if (ImportandoArchivo)
    {
        if(NombreExiste(ui->txtNombre->text(),ui->txtExtension->text(),-1))
        {
            Utilerias::MostraAlerta("Ya existe un tipo de registro con el mismo nombre,intente con otro.");
            return;
        }

        ui->txtFechaCreacion->setText(dir->getFechaCreado());
    }
    else
    {
        if(NombreExiste(ui->txtNombre->text(),ui->txtExtension->text(),dir->Indice))
        {
            Utilerias::MostraAlerta("Ya existe un tipo de registro con el mismo nombre,intente con otro.");
            return;
        }

        ui->txtFechaMod->setText(dir->getFechaModificado());
    }

    if (ImportandoArchivo)//nuevo archivo
    {
        dir->setFechaCreo();
        ui->txtFechaCreacion->setText(dir->getFechaCreado());
    }
    else//modificacion
    {
        dir->setFechaMod();
        ui->txtFechaMod->setText(dir->getFechaModificado());
    }

    dir->SetNombre(ui->txtNombre->text().toStdString());
    dir->setPermiso(ui->txtPermisos->text().toStdString());
    dir->status='1';
    Resultado=true;
    this->close();


}
