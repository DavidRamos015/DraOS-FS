/********************************************************************************
** Form generated from reading UI file 'fsexplorer.ui'
**
** Created: Fri Dec 14 18:15:22 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSEXPLORER_H
#define UI_FSEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FSExplorer
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label;
    QLCDNumber *lcdTamDisco;
    QLabel *label_2;
    QLCDNumber *lcdUsuarios;
    QLabel *label_3;
    QLCDNumber *lcdMapabits;
    QLabel *label_4;
    QLCDNumber *lcdNoCluster;
    QLabel *label_5;
    QLCDNumber *LcdDirectorios;
    QLabel *label_6;
    QLCDNumber *lcdBloqueDatos;
    QLabel *label_8;
    QLCDNumber *lcdEspacioDisponible;
    QLabel *label_9;
    QLCDNumber *lcdEspacioUsado;
    QCommandLinkButton *btnUsuario;
    QCommandLinkButton *btnFormato;
    QCommandLinkButton *btnFilesSystem;
    QCommandLinkButton *blogo;
    QLabel *label_7;

    void setupUi(QMainWindow *FSExplorer)
    {
        if (FSExplorer->objectName().isEmpty())
            FSExplorer->setObjectName(QString::fromUtf8("FSExplorer"));
        FSExplorer->resize(800, 461);
        FSExplorer->setMinimumSize(QSize(800, 461));
        FSExplorer->setMaximumSize(QSize(800, 461));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        FSExplorer->setWindowIcon(icon);
        FSExplorer->setWindowOpacity(1);
        FSExplorer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(FSExplorer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(3, 335, 791, 121));
        frame->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.0, cy:0.0, radius:0.0, fx:0.0, fy:0.0, stop:0 rgba(0, 0, 0, 0), stop:0.35 rgba(0, 0, 0, 0), stop:0.0 rgba(0, 0, 0, 0), stop:0.425 rgba(0, 0, 0, 0), stop:0.0 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 0));\n"
"\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 21));
        label->setStyleSheet(QString::fromUtf8(""));
        lcdTamDisco = new QLCDNumber(frame);
        lcdTamDisco->setObjectName(QString::fromUtf8("lcdTamDisco"));
        lcdTamDisco->setGeometry(QRect(120, 20, 101, 23));
        lcdTamDisco->setFrameShape(QFrame::Box);
        lcdTamDisco->setFrameShadow(QFrame::Plain);
        lcdTamDisco->setNumDigits(10);
        lcdTamDisco->setSegmentStyle(QLCDNumber::Flat);
        lcdTamDisco->setProperty("value", QVariant(0));
        lcdTamDisco->setProperty("intValue", QVariant(0));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(238, 20, 141, 21));
        lcdUsuarios = new QLCDNumber(frame);
        lcdUsuarios->setObjectName(QString::fromUtf8("lcdUsuarios"));
        lcdUsuarios->setGeometry(QRect(378, 20, 101, 23));
        lcdUsuarios->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.0, cy:0.0, radius:0.0, fx:0.0, fy:0.0, stop:0 rgba(0, 0, 0, 0), stop:0.35 rgba(0, 0, 0, 0), stop:0.0 rgba(0, 0, 0, 0), stop:0.425 rgba(0, 0, 0, 0), stop:0.0 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 0));"));
        lcdUsuarios->setFrameShadow(QFrame::Plain);
        lcdUsuarios->setNumDigits(10);
        lcdUsuarios->setSegmentStyle(QLCDNumber::Flat);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(238, 60, 141, 21));
        lcdMapabits = new QLCDNumber(frame);
        lcdMapabits->setObjectName(QString::fromUtf8("lcdMapabits"));
        lcdMapabits->setGeometry(QRect(378, 60, 101, 23));
        lcdMapabits->setFrameShadow(QFrame::Plain);
        lcdMapabits->setNumDigits(10);
        lcdMapabits->setSegmentStyle(QLCDNumber::Flat);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 90, 61, 21));
        lcdNoCluster = new QLCDNumber(frame);
        lcdNoCluster->setObjectName(QString::fromUtf8("lcdNoCluster"));
        lcdNoCluster->setGeometry(QRect(378, 90, 101, 23));
        lcdNoCluster->setFrameShadow(QFrame::Plain);
        lcdNoCluster->setNumDigits(10);
        lcdNoCluster->setSegmentStyle(QLCDNumber::Flat);
        lcdNoCluster->setProperty("value", QVariant(0));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(495, 20, 141, 21));
        LcdDirectorios = new QLCDNumber(frame);
        LcdDirectorios->setObjectName(QString::fromUtf8("LcdDirectorios"));
        LcdDirectorios->setGeometry(QRect(635, 20, 101, 23));
        LcdDirectorios->setFrameShadow(QFrame::Plain);
        LcdDirectorios->setNumDigits(10);
        LcdDirectorios->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(495, 60, 141, 21));
        lcdBloqueDatos = new QLCDNumber(frame);
        lcdBloqueDatos->setObjectName(QString::fromUtf8("lcdBloqueDatos"));
        lcdBloqueDatos->setGeometry(QRect(635, 60, 101, 23));
        lcdBloqueDatos->setFrameShadow(QFrame::Plain);
        lcdBloqueDatos->setNumDigits(10);
        lcdBloqueDatos->setSegmentStyle(QLCDNumber::Flat);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 90, 91, 21));
        lcdEspacioDisponible = new QLCDNumber(frame);
        lcdEspacioDisponible->setObjectName(QString::fromUtf8("lcdEspacioDisponible"));
        lcdEspacioDisponible->setGeometry(QRect(120, 90, 101, 23));
        lcdEspacioDisponible->setFrameShadow(QFrame::Plain);
        lcdEspacioDisponible->setNumDigits(10);
        lcdEspacioDisponible->setSegmentStyle(QLCDNumber::Flat);
        lcdEspacioDisponible->setProperty("value", QVariant(0));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 53, 91, 21));
        lcdEspacioUsado = new QLCDNumber(frame);
        lcdEspacioUsado->setObjectName(QString::fromUtf8("lcdEspacioUsado"));
        lcdEspacioUsado->setGeometry(QRect(120, 57, 101, 23));
        lcdEspacioUsado->setFrameShadow(QFrame::Plain);
        lcdEspacioUsado->setNumDigits(10);
        lcdEspacioUsado->setSegmentStyle(QLCDNumber::Flat);
        lcdEspacioUsado->setProperty("value", QVariant(0));
        btnUsuario = new QCommandLinkButton(centralWidget);
        btnUsuario->setObjectName(QString::fromUtf8("btnUsuario"));
        btnUsuario->setGeometry(QRect(340, 134, 131, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/config-users.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUsuario->setIcon(icon1);
        btnUsuario->setIconSize(QSize(48, 48));
        btnFormato = new QCommandLinkButton(centralWidget);
        btnFormato->setObjectName(QString::fromUtf8("btnFormato"));
        btnFormato->setGeometry(QRect(340, 200, 131, 61));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/harddrive2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFormato->setIcon(icon2);
        btnFormato->setIconSize(QSize(48, 48));
        btnFilesSystem = new QCommandLinkButton(centralWidget);
        btnFilesSystem->setObjectName(QString::fromUtf8("btnFilesSystem"));
        btnFilesSystem->setGeometry(QRect(340, 269, 131, 61));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/system-file-manager.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFilesSystem->setIcon(icon3);
        btnFilesSystem->setIconSize(QSize(48, 48));
        blogo = new QCommandLinkButton(centralWidget);
        blogo->setObjectName(QString::fromUtf8("blogo"));
        blogo->setEnabled(false);
        blogo->setGeometry(QRect(350, 10, 91, 131));
        blogo->setInputMethodHints(Qt::ImhHiddenText);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Disabled, QIcon::Off);
        blogo->setIcon(icon4);
        blogo->setIconSize(QSize(80, 94));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 120, 800, 2));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/barra.png);\n"
""));
        FSExplorer->setCentralWidget(centralWidget);

        retranslateUi(FSExplorer);

        QMetaObject::connectSlotsByName(FSExplorer);
    } // setupUi

    void retranslateUi(QMainWindow *FSExplorer)
    {
        FSExplorer->setWindowTitle(QApplication::translate("FSExplorer", "FS - Explorer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FSExplorer", "Disco Duro:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FSExplorer", "Inicio de bloque usuarios:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FSExplorer", "Inicio de bloque  mapa bits:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FSExplorer", "No. Cluster:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FSExplorer", "Inicio de bloque directorios:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FSExplorer", "Inicio de bloque de datos:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FSExplorer", "Espacio Disponible:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FSExplorer", "Espacio Usado:", 0, QApplication::UnicodeUTF8));
        btnUsuario->setText(QApplication::translate("FSExplorer", "Usuarios", 0, QApplication::UnicodeUTF8));
        btnUsuario->setShortcut(QApplication::translate("FSExplorer", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        btnFormato->setText(QApplication::translate("FSExplorer", "Formato", 0, QApplication::UnicodeUTF8));
        btnFormato->setShortcut(QApplication::translate("FSExplorer", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        btnFilesSystem->setText(QApplication::translate("FSExplorer", "Archivos", 0, QApplication::UnicodeUTF8));
        btnFilesSystem->setShortcut(QApplication::translate("FSExplorer", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        blogo->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FSExplorer: public Ui_FSExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSEXPLORER_H
