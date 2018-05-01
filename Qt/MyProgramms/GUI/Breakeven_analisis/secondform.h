#ifndef SECONDFORM_H
#define SECONDFORM_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class SecondForm;
}

class SecondForm : public QWidget
{
    Q_OBJECT

public:
    explicit SecondForm(QWidget *parent = 0);
    ~SecondForm();

private:
    Ui::SecondForm *ui;

};

#endif // SECONDFORM_H
