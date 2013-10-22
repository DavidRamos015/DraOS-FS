/********************************************************************************
** Form generated from reading UI file 'formuser.ui'
**
** Created: Fri Dec 14 18:15:22 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMUSER_H
#define UI_FORMUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_formUser
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *ListaUsuarios;
    QLabel *label;
    QCommandLinkButton *btnadd;
    QCommandLinkButton *btndel;
    QGroupBox *groupBox;
    QSpinBox *spinID;
    QLineEdit *TeKey;
    QLineEdit *TeName;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *formUser)
    {
        if (formUser->objectName().isEmpty())
            formUser->setObjectName(QString::fromUtf8("formUser"));
        formUser->setWindowModality(Qt::ApplicationModal);
        formUser->resize(390, 450);
        formUser->setMinimumSize(QSize(390, 400));
        formUser->setMaximumSize(QSize(390, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        formUser->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(formUser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 390, 321, 56));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ListaUsuarios = new QListWidget(formUser);
        ListaUsuarios->setObjectName(QString::fromUtf8("ListaUsuarios"));
        ListaUsuarios->setGeometry(QRect(33, 130, 321, 251));
        label = new QLabel(formUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(33, 114, 640, 21));
        label->setStyleSheet(QString::fromUtf8("font: 75 8pt \"MS Shell Dlg 2\";"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnadd = new QCommandLinkButton(formUser);
        btnadd->setObjectName(QString::fromUtf8("btnadd"));
        btnadd->setGeometry(QRect(30, 5, 151, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/add-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnadd->setIcon(icon1);
        btndel = new QCommandLinkButton(formUser);
        btndel->setObjectName(QString::fromUtf8("btndel"));
        btndel->setGeometry(QRect(200, 5, 151, 41));
        btndel->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/delete-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        btndel->setIcon(icon2);
        groupBox = new QGroupBox(formUser);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 50, 331, 61));
        spinID = new QSpinBox(groupBox);
        spinID->setObjectName(QString::fromUtf8("spinID"));
        spinID->setEnabled(false);
        spinID->setGeometry(QRect(10, 32, 46, 22));
        TeKey = new QLineEdit(groupBox);
        TeKey->setObjectName(QString::fromUtf8("TeKey"));
        TeKey->setGeometry(QRect(210, 33, 113, 20));
        TeKey->setMaxLength(10);
        TeKey->setEchoMode(QLineEdit::Password);
        TeName = new QLineEdit(groupBox);
        TeName->setObjectName(QString::fromUtf8("TeName"));
        TeName->setGeometry(QRect(70, 33, 113, 20));
        TeName->setMaxLength(12);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 17, 60, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 17, 60, 12));
        label->raise();
        buttonBox->raise();
        ListaUsuarios->raise();
        btnadd->raise();
        btndel->raise();
        groupBox->raise();

        retranslateUi(formUser);
        QObject::connect(buttonBox, SIGNAL(accepted()), formUser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), formUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(formUser);
    } // setupUi

    void retranslateUi(QDialog *formUser)
    {
        formUser->setWindowTitle(QApplication::translate("formUser", "Administrar Usuarios", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formUser", "Indice    -  Nombre       - Clave", 0, QApplication::UnicodeUTF8));
        btnadd->setText(QApplication::translate("formUser", "Agregar", 0, QApplication::UnicodeUTF8));
        btndel->setText(QApplication::translate("formUser", "Eliminar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("formUser", "Agregar/Modificar usuario", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formUser", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formUser", "Usuario", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formUser: public Ui_formUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUSER_H
