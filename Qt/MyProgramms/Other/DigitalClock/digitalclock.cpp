#include "digitalclock.h"
#include "ui_digitalclock.h"

#include <QtGui>

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent),
    ui(new Ui::DigitalClock)
{
    ui->setupUi(this);


    //Fills with foreground color
    setSegmentStyle(Filled);

    //A new timer is created. The interval is one second
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    //Time display
    showTime();

    //Specifies a new name for the widget and changes its size.
    setWindowTitle(tr("Digital Clock"));
    resize(150,60);
}

DigitalClock::~DigitalClock()
{
    delete ui;
}

//This method displays the current time.
void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text= time.toString("hh:mm");
    if ((time.second()% 2)== 0)
        text[2] = ' ';
    display(text);
}
