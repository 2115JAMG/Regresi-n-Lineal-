#include "rregresion_lineal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Rregresion_Lineal w;
    w.show();

    return a.exec();
}
