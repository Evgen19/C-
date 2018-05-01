#include "oglpyramid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLPyramid oglPyramid;

    oglPyramid.resize(200,200);
    oglPyramid.show();

    return a.exec();
}
