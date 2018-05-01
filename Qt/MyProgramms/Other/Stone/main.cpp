#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a main widget
    Widget wgt;

    //Create a new widget
    QWidget* pwgt1 = new QWidget(&wgt);

    //Create a new pallete
    QPalette pal1;

    /*Add a new background for the widget, the color is blue.
    Change the size of the widget and move it to a specific place.*/

    pal1.setColor(pwgt1->backgroundRole(), Qt::blue);
    pwgt1->setPalette(pal1);
    pwgt1->resize(100,100);
    pwgt1->move(25,25);
    pwgt1->setAutoFillBackground(true);


    /*Add another widget to the main widget, add a picture as a background.
    We change the size and move it to a certain place.*/

    QWidget* pwgt2 = new QWidget(&wgt);
    QPalette pal2;
    pal2.setBrush(pwgt2->backgroundRole(), QBrush(QPixmap(":/images/stone.jpg")));
    pwgt2->setPalette(pal2);
    pwgt2->resize(100,100);
    pwgt2->move(75,75);
    pwgt2->setAutoFillBackground(true);


    //Change the size of the main widget and display it.
    wgt.resize(200,200);
    wgt.show();

    return a.exec();
}
