#include "mcmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MCManager w;
    w.show();
    
    return a.exec();
}
