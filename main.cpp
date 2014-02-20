#include <QtGui/QApplication>
#include "qtpolymer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtpolymer w;
    w.show();
    
    return a.exec();
}
