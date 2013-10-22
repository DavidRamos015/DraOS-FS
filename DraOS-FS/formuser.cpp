#include "formuser.h"
#include "ui_formuser.h"

formUser::formUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formUser)
{
    ui->setupUi(this);
    ui->groupBox->setVisible(false);
}

formUser::~formUser()
{
    delete ui;
}

void formUser::LoadUser()
{
    foreach(QListWidgetItem item,usuarios)
    {
        QString txt=item.text();
        ui->ListaUsuarios->addItem(txt);
    }

    ui->ListaUsuarios->update();

}



void formUser::on_btnadd_clicked()
{
    if (ui->groupBox->isVisible())
    {
        QString nombre=Utilerias::PadLeft(ui->TeName->text(),FS_SIZE_User_Nombre,'*');
        QString Clave= Utilerias::PadLeft(ui->TeKey->text(),FS_SIZE_User_Clave,'*');
        QString indice=QString("%0").arg(ui->spinID->value());

        if (ui->spinID->value()>=10)
            indice=indice.leftJustified(9,' ');
        else
            indice=indice.leftJustified(10,' ');

        QString txt=(QString("%0 - %1 - %2").arg(indice).arg(nombre).arg(Clave));
        ui->ListaUsuarios->addItem(txt);
        ui->ListaUsuarios->update();
        ui->TeName->setText("");
        ui->TeKey->setText("");
        ui->spinID->setValue(0);
        ui->groupBox->setVisible(false);
        ui->btndel->setText("Eliminar");

    }
    else
    {
        if (ui->ListaUsuarios->count() +1> Utilerias::UsuariosSoportado)
        {
            Utilerias::MostraAlerta("No se permite agregar mas usuarios");
            return;
        }

        ui->spinID->setValue(ui->ListaUsuarios->count()+1);
        ui->groupBox->setVisible(true);
        ui->btndel->setText("Cancelar");
    }
}

void formUser::on_btndel_clicked()
{
    if (ui->groupBox->isVisible())
    {
        ui->groupBox->setVisible(false);
        ui->btndel->setText("Eliminar");
    }
    else
    {
        if (SelectedItem==NULL)
        {
            Utilerias::MostraAlerta("Seleccionar usuario a eliminar.");
            return;
        }

        ui->ListaUsuarios->removeItemWidget(SelectedItem);
        delete SelectedItem;
        ui->ListaUsuarios->update();

    }
}

void formUser::on_ListaUsuarios_itemClicked(QListWidgetItem *item)
{
    SelectedItem=item;
}
