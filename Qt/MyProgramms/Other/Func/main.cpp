#include "func.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Func w;
    w.show();
    w.resize(800,400);
    w.setWindowTitle("Функции");

    return a.exec();
}
