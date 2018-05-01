#include "analogclock.h"
#include "ui_analogclock.h"
#include <QtGui>
#include <QTextCodec>

AnalogClock::AnalogClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogClock)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this, SLOT(update()));
    timer->start(1000);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));

    setWindowTitle("Аналоговые часы");
    resize(200,200);
}

AnalogClock::~AnalogClock()
{
    delete ui;
}

//Method of drawing watches
void AnalogClock::paintEvent(QPaintEvent *)
{
    //Declare the three structures that draw the hands of the clock
    static const QPoint hourHand[3]={
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-40)
    };

    static const QPoint minuteHand[3]={
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-70)
    };

    static const QPoint secondHand[3]={
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-90)

    };

    //Set the colors for the arrows
    QColor hourColor(127,0,127);
    QColor minuteColor(0,127,127,191);
    QColor secondColor(0,0,255);

    int side = qMin(width(), height());

    QTime time = QTime::currentTime();

    //Create frame a clock
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width()/2, height()/2);
    painter.scale(side/200.0, side/200.0);
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    //Create a hour hand
    painter.save();
    painter.rotate(30.0 * ((time.hour()+ time.minute()/60.0)));
    painter.drawConvexPolygon(hourHand,3);
    painter.restore();

    //Create the hour dial and give the division a certain color
    painter.setPen(hourColor);
    for(int i=0; i<12; ++i)
    {
        painter.drawLine(88,0,96,0);
        painter.rotate(30.0);
    }
    //Create a minute hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0*(time.minute()+time.second()/60));
    painter.drawConvexPolygon(minuteHand,3);
    painter.restore();

    //Create a minute dial and assign a color to the parts
    painter.setPen(minuteColor);
    for(int j=0; j<60; ++j)
    {
        if((j%5)!=0)
            painter.drawLine(92,0,96,0);
        painter.rotate(6.0);
    }

    //Create a second  hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    painter.rotate(6.0*(time.second()+time.msec()/60));
    painter.drawConvexPolygon(secondHand,3);
    painter.restore();


}
