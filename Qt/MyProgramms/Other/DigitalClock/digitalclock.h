#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>

namespace Ui {
class DigitalClock;
}

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    explicit DigitalClock(QWidget *parent = 0);
    ~DigitalClock();

private:
    Ui::DigitalClock *ui;

private slots:
    void showTime();
};

#endif // DIGITALCLOCK_H
