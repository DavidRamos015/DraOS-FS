/********************************************************************************
** Form generated from reading UI file 'fileproperties.ui'
**
** Created: Fri Dec 14 18:15:22 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPROPERTIES_H
#define UI_FILEPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FileProperties
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *txtExtension;
    QLineEdit *txtFechaCreacion;
    QLineEdit *txtFechaMod;
    QTextEdit *txtUbicacion;
    QLineEdit *txtPermisos;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *txtIndice;
    QCommandLinkButton *btnOpen;
    QCommandLinkButton *btnClose;
    QCommandLinkButton *btnNewFolder;
    QLabel *label_18;
    QLineEdit *txtPosicion;
    QLineEdit *txtPadre;
    QLineEdit *txtTamano;
    QLineEdit *txtNombre;
    QLineEdit *txtPropietario;

    void setupUi(QDialog *FileProperties)
    {
        if (FileProperties->objectName().isEmpty())
            FileProperties->setObjectName(QString::fromUtf8("FileProperties"));
        FileProperties->resize(317, 461);
        FileProperties->setMinimumSize(QSize(317, 461));
        FileProperties->setMaximumSize(QSize(317, 461));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        FileProperties->setWindowIcon(icon);
        label = new QLabel(FileProperties);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(27, 106, 46, 13));
        label_2 = new QLabel(FileProperties);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(209, 267, 46, 13));
        label_3 = new QLabel(FileProperties);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(27, 305, 51, 16));
        label_4 = new QLabel(FileProperties);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(27, 186, 141, 16));
        label_5 = new QLabel(FileProperties);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(27, 50, 46, 13));
        label_6 = new QLabel(FileProperties);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(206, 105, 46, 16));
        label_7 = new QLabel(FileProperties);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(27, 227, 46, 13));
        label_8 = new QLabel(FileProperties);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(116, 226, 46, 13));
        label_9 = new QLabel(FileProperties);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(27, 145, 81, 16));
        label_10 = new QLabel(FileProperties);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(206, 225, 91, 16));
        txtExtension = new QLineEdit(FileProperties);
        txtExtension->setObjectName(QString::fromUtf8("txtExtension"));
        txtExtension->setEnabled(true);
        txtExtension->setGeometry(QRect(205, 120, 81, 20));
        txtExtension->setMaxLength(3);
        txtExtension->setReadOnly(false);
        txtFechaCreacion = new QLineEdit(FileProperties);
        txtFechaCreacion->setObjectName(QString::fromUtf8("txtFechaCreacion"));
        txtFechaCreacion->setEnabled(true);
        txtFechaCreacion->setGeometry(QRect(27, 160, 260, 20));
        txtFechaCreacion->setMaxLength(32767);
        txtFechaCreacion->setReadOnly(false);
        txtFechaMod = new QLineEdit(FileProperties);
        txtFechaMod->setObjectName(QString::fromUtf8("txtFechaMod"));
        txtFechaMod->setEnabled(true);
        txtFechaMod->setGeometry(QRect(27, 200, 260, 20));
        txtFechaMod->setMaxLength(32767);
        txtFechaMod->setReadOnly(false);
        txtUbicacion = new QTextEdit(FileProperties);
        txtUbicacion->setObjectName(QString::fromUtf8("txtUbicacion"));
        txtUbicacion->setEnabled(true);
        txtUbicacion->setGeometry(QRect(27, 320, 261, 71));
        txtUbicacion->setReadOnly(false);
        txtPermisos = new QLineEdit(FileProperties);
        txtPermisos->setObjectName(QString::fromUtf8("txtPermisos"));
        txtPermisos->setEnabled(true);
        txtPermisos->setGeometry(QRect(205, 280, 81, 20));
        txtPermisos->setMaxLength(3);
        txtPermisos->setReadOnly(false);
        label_11 = new QLabel(FileProperties);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(18, 40, 280, 2));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/barra.png);\n"
""));
        label_13 = new QLabel(FileProperties);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(17, 400, 280, 2));
        label_13->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/barra.png);\n"
""));
        label_14 = new QLabel(FileProperties);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(297, 40, 2, 362));
        label_14->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/barra.png);\n"
""));
        label_14->setLineWidth(1);
        label_15 = new QLabel(FileProperties);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(18, 40, 2, 362));
        label_15->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/barra.png);\n"
""));
        label_16 = new QLabel(FileProperties);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 10, 281, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Nyala"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_16->setFont(font);
        txtIndice = new QLineEdit(FileProperties);
        txtIndice->setObjectName(QString::fromUtf8("txtIndice"));
        txtIndice->setEnabled(true);
        txtIndice->setGeometry(QRect(27, 65, 261, 20));
        txtIndice->setFrame(true);
        txtIndice->setReadOnly(false);
        btnOpen = new QCommandLinkButton(FileProperties);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(200, 411, 101, 41));
        btnOpen->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/db_comit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpen->setIcon(icon1);
        btnOpen->setAutoDefault(false);
        btnClose = new QCommandLinkButton(FileProperties);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(20, 411, 101, 41));
        btnClose->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/button_delete_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon2);
        btnClose->setAutoDefault(false);
        btnNewFolder = new QCommandLinkButton(FileProperties);
        btnNewFolder->setObjectName(QString::fromUtf8("btnNewFolder"));
        btnNewFolder->setGeometry(QRect(170, 410, 131, 41));
        btnNewFolder->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/Folder-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewFolder->setIcon(icon3);
        btnNewFolder->setAutoDefault(false);
        label_18 = new QLabel(FileProperties);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(28, 266, 81, 16));
        txtPosicion = new QLineEdit(FileProperties);
        txtPosicion->setObjectName(QString::fromUtf8("txtPosicion"));
        txtPosicion->setGeometry(QRect(27, 280, 171, 20));
        txtPadre = new QLineEdit(FileProperties);
        txtPadre->setObjectName(QString::fromUtf8("txtPadre"));
        txtPadre->setGeometry(QRect(116, 240, 81, 20));
        txtTamano = new QLineEdit(FileProperties);
        txtTamano->setObjectName(QString::fromUtf8("txtTamano"));
        txtTamano->setGeometry(QRect(27, 240, 81, 20));
        txtNombre = new QLineEdit(FileProperties);
        txtNombre->setObjectName(QString::fromUtf8("txtNombre"));
        txtNombre->setGeometry(QRect(27, 120, 171, 20));
        txtNombre->setMaxLength(20);
        txtPropietario = new QLineEdit(FileProperties);
        txtPropietario->setObjectName(QString::fromUtf8("txtPropietario"));
        txtPropietario->setGeometry(QRect(205, 240, 81, 20));
        QWidget::setTabOrder(txtIndice, txtNombre);
        QWidget::setTabOrder(txtNombre, btnNewFolder);
        QWidget::setTabOrder(btnNewFolder, btnOpen);
        QWidget::setTabOrder(btnOpen, txtExtension);
        QWidget::setTabOrder(txtExtension, txtFechaCreacion);
        QWidget::setTabOrder(txtFechaCreacion, txtFechaMod);
        QWidget::setTabOrder(txtFechaMod, txtTamano);
        QWidget::setTabOrder(txtTamano, txtPadre);
        QWidget::setTabOrder(txtPadre, txtPropietario);
        QWidget::setTabOrder(txtPropietario, txtPosicion);
        QWidget::setTabOrder(txtPosicion, txtPermisos);
        QWidget::setTabOrder(txtPermisos, txtUbicacion);
        QWidget::setTabOrder(txtUbicacion, btnClose);

        retranslateUi(FileProperties);

        QMetaObject::connectSlotsByName(FileProperties);
    } // setupUi

    void retranslateUi(QDialog *FileProperties)
    {
        FileProperties->setWindowTitle(QApplication::translate("FileProperties", "Propiedades", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FileProperties", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FileProperties", "Permisos:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FileProperties", "Ubicaci\303\263n:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FileProperties", "Fecha ultima modificaci\303\263n", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FileProperties", "Indice:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FileProperties", "Extensi\303\263n:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FileProperties", "Tama\303\261o:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FileProperties", "Padre:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FileProperties", "Fecha creaci\303\263n:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("FileProperties", "Propietario:", 0, QApplication::UnicodeUTF8));
        txtExtension->setText(QString());
        txtFechaCreacion->setText(QString());
        txtFechaMod->setText(QString());
        txtPermisos->setText(QString());
        label_11->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QApplication::translate("FileProperties", "Informaci\303\263n del archivo", 0, QApplication::UnicodeUTF8));
        txtIndice->setText(QString());
        btnOpen->setText(QApplication::translate("FileProperties", "Exportar", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("FileProperties", "Cerrar", 0, QApplication::UnicodeUTF8));
        btnNewFolder->setText(QApplication::translate("FileProperties", "Nueva Carpeta", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("FileProperties", "Posici\303\263n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileProperties: public Ui_FileProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPROPERTIES_H
