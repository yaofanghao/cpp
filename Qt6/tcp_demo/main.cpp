#include "frmtcp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmTcp w;
    w.show();
    return a.exec();
}
