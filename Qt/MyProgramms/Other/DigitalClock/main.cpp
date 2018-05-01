#include "digitalclock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigitalClock clock;
    clock.show();

    return a.exec();
}
