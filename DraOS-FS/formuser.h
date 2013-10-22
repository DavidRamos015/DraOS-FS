#ifndef FORMUSER_H
#define FORMUSER_H
#include <QListWidgetItem>
#include "sectorceroinfo.h"
#include "utilerias.h"

#include <QDialog>

using namespace std;

namespace Ui {
class formUser;
}

class formUser : public QDialog
{
    Q_OBJECT
    
public:
    explicit formUser(QWidget *parent = 0);
    list<QListWidgetItem> usuarios;
    SectorCeroInfo *infoDisco;
    QListWidgetItem *SelectedItem;
    void LoadUser();
    ~formUser();
    
private slots:


    void on_btnadd_clicked();

    void on_btndel_clicked();

    void on_ListaUsuarios_itemClicked(QListWidgetItem *item);

private:
    Ui::formUser *ui;
};

#endif // FORMUSER_H
