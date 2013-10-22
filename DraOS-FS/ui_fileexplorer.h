/********************************************************************************
** Form generated from reading UI file 'fileexplorer.ui'
**
** Created: Fri Dec 14 18:15:22 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXPLORER_H
#define UI_FILEEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FileExplorer
{
public:
    QCommandLinkButton *btnClose;
    QCommandLinkButton *btnBack;
    QCommandLinkButton *btnNext;
    QCommandLinkButton *btnHome;
    QCommandLinkButton *btnSave;
    QCommandLinkButton *btnOpen;
    QCommandLinkButton *btnesc;
    QTextEdit *teDir;
    QLabel *label;
    QCommandLinkButton *btnNewFolder;
    QTableWidget *tableWidget;
    QCommandLinkButton *btnModificar;
    QCommandLinkButton *btnEliminar;

    void setupUi(QDialog *FileExplorer)
    {
        if (FileExplorer->objectName().isEmpty())
            FileExplorer->setObjectName(QString::fromUtf8("FileExplorer"));
        FileExplorer->resize(1024, 556);
        FileExplorer->setMinimumSize(QSize(1024, 556));
        FileExplorer->setMaximumSize(QSize(1024, 556));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        FileExplorer->setWindowIcon(icon);
        FileExplorer->setStyleSheet(QString::fromUtf8(""));
        btnClose = new QCommandLinkButton(FileExplorer);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(0, 2, 101, 41));
        btnClose->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/button_delete_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon1);
        btnClose->setAutoDefault(false);
        btnBack = new QCommandLinkButton(FileExplorer);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setGeometry(QRect(210, 1, 101, 41));
        btnBack->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon2);
        btnBack->setAutoDefault(false);
        btnNext = new QCommandLinkButton(FileExplorer);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(310, 2, 101, 41));
        btnNext->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon3);
        btnNext->setAutoDefault(false);
        btnHome = new QCommandLinkButton(FileExplorer);
        btnHome->setObjectName(QString::fromUtf8("btnHome"));
        btnHome->setGeometry(QRect(100, 2, 101, 41));
        btnHome->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resources/home_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHome->setIcon(icon4);
        btnHome->setAutoDefault(false);
        btnSave = new QCommandLinkButton(FileExplorer);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(420, 2, 101, 41));
        btnSave->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Resources/Downloads.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon5);
        btnSave->setAutoDefault(false);
        btnOpen = new QCommandLinkButton(FileExplorer);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(523, 2, 101, 41));
        btnOpen->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Resources/db_comit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpen->setIcon(icon6);
        btnOpen->setAutoDefault(false);
        btnesc = new QCommandLinkButton(FileExplorer);
        btnesc->setObjectName(QString::fromUtf8("btnesc"));
        btnesc->setGeometry(QRect(0, 0, 0, 0));
        teDir = new QTextEdit(FileExplorer);
        teDir->setObjectName(QString::fromUtf8("teDir"));
        teDir->setEnabled(true);
        teDir->setGeometry(QRect(5, 511, 1011, 41));
        teDir->setFrameShape(QFrame::Box);
        teDir->setFrameShadow(QFrame::Plain);
        teDir->setMidLineWidth(1);
        teDir->setReadOnly(true);
        label = new QLabel(FileExplorer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 43, 1024, 2));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/barra.png);\n"
""));
        btnNewFolder = new QCommandLinkButton(FileExplorer);
        btnNewFolder->setObjectName(QString::fromUtf8("btnNewFolder"));
        btnNewFolder->setGeometry(QRect(889, 2, 131, 41));
        btnNewFolder->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Resources/Folder-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewFolder->setIcon(icon7);
        btnNewFolder->setAutoDefault(false);
        tableWidget = new QTableWidget(FileExplorer);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Resources/edit-number.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setIcon(icon8);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Resources/textfield_rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon9);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Resources/file_extension_bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setIcon(icon10);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Resources/001_44.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setIcon(icon11);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setIcon(icon11);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Resources/layer-resize.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setIcon(icon12);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Resources/user_business_boss.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setIcon(icon13);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Resources/001_41.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setIcon(icon14);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem12);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(5, 48, 1011, 461));
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setLineWidth(0);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideNone);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(2);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(16);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        btnModificar = new QCommandLinkButton(FileExplorer);
        btnModificar->setObjectName(QString::fromUtf8("btnModificar"));
        btnModificar->setGeometry(QRect(737, 2, 151, 41));
        btnModificar->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);\n"
""));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Resources/interact.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModificar->setIcon(icon15);
        btnModificar->setAutoDefault(false);
        btnEliminar = new QCommandLinkButton(FileExplorer);
        btnEliminar->setObjectName(QString::fromUtf8("btnEliminar"));
        btnEliminar->setGeometry(QRect(634, 2, 101, 41));
        btnEliminar->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/fondo.png);"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Resources/emblem-nowrite.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEliminar->setIcon(icon16);
        btnEliminar->setAutoDefault(false);

        retranslateUi(FileExplorer);

        QMetaObject::connectSlotsByName(FileExplorer);
    } // setupUi

    void retranslateUi(QDialog *FileExplorer)
    {
        FileExplorer->setWindowTitle(QApplication::translate("FileExplorer", "Explorador de Archivos", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("FileExplorer", "Cerrar", 0, QApplication::UnicodeUTF8));
        btnClose->setShortcut(QApplication::translate("FileExplorer", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        btnBack->setText(QApplication::translate("FileExplorer", "Atras", 0, QApplication::UnicodeUTF8));
        btnBack->setShortcut(QApplication::translate("FileExplorer", "Alt+Left", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("FileExplorer", "Siguiente", 0, QApplication::UnicodeUTF8));
        btnNext->setShortcut(QApplication::translate("FileExplorer", "Alt+Right", 0, QApplication::UnicodeUTF8));
        btnHome->setText(QApplication::translate("FileExplorer", "Inicio", 0, QApplication::UnicodeUTF8));
        btnHome->setShortcut(QApplication::translate("FileExplorer", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("FileExplorer", "Importar", 0, QApplication::UnicodeUTF8));
        btnSave->setShortcut(QApplication::translate("FileExplorer", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        btnOpen->setText(QApplication::translate("FileExplorer", "Exportar", 0, QApplication::UnicodeUTF8));
        btnOpen->setShortcut(QApplication::translate("FileExplorer", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        btnesc->setText(QString());
        teDir->setHtml(QApplication::translate("FileExplorer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\\</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        btnNewFolder->setText(QApplication::translate("FileExplorer", "Nueva Carpeta", 0, QApplication::UnicodeUTF8));
        btnNewFolder->setShortcut(QApplication::translate("FileExplorer", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FileExplorer", "Indice", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FileExplorer", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FileExplorer", "Tipo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FileExplorer", "Creado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FileExplorer", "Modificado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FileExplorer", "Tama\303\261o", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FileExplorer", "Propietario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("FileExplorer", "Permisos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("FileExplorer", "BloqueInicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("FileExplorer", "Padre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("FileExplorer", "No Cluster", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("FileExplorer", "New Row", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("FileExplorer", "New Row", 0, QApplication::UnicodeUTF8));
        btnModificar->setText(QApplication::translate("FileExplorer", "Modificar Carpeta", 0, QApplication::UnicodeUTF8));
        btnModificar->setShortcut(QApplication::translate("FileExplorer", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        btnEliminar->setText(QApplication::translate("FileExplorer", "Eliminar", 0, QApplication::UnicodeUTF8));
        btnEliminar->setShortcut(QApplication::translate("FileExplorer", "Ctrl+D", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileExplorer: public Ui_FileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXPLORER_H
