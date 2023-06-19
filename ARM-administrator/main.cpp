#include "selectionwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    selectionWindow w;
    w.show();
    return a.exec();
}
