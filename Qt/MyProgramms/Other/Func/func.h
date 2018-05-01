#ifndef FUNC_H
#define FUNC_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


namespace Ui {
class Func;
}

class Func : public QMainWindow
{
    Q_OBJECT

public:
    explicit Func(QWidget *parent = 0);
    ~Func();

private:
    Ui::Func *ui;
    QLabel *labelFunc;
    QLabel *labelDesc;
    QLabel *labelExam;
    QLabel *labelOut;

    //sqrt
    QLabel *labelSqrt;
    QLabel *labelDescSqrt;
    QLabel *labelExamSqrt;
    QLabel *labelOutSqrt;
    QLineEdit *lineEditSqrt;
    QPushButton *buttonSqrt;



private slots:

void buttonSqrtClicked();

};

#endif // FUNC_H
