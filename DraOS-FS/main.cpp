#include <QtGui/QApplication>
#include "fsexplorer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FSExplorer w;
    w.show();
    
    return a.exec();
}
