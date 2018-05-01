#include "func.h"
#include "ui_func.h"
#include <math.h>

Func::Func(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Func)
{
    ui->setupUi(this);


    labelFunc = new QLabel(this);
    labelFunc->setGeometry(10,10,80,20);
    labelFunc->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelFunc->setText("Функция");
    labelFunc->show();

    labelDesc = new QLabel(this);
    labelDesc->setGeometry(150,10,150,20);
    labelDesc->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelDesc->setText("Описание функции");
    labelDesc->show();

    labelExam = new QLabel(this);
    labelExam->setGeometry(400,10,70,20);
    labelExam->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelExam->setText("Пример");
    labelExam->show();

    labelOut = new QLabel(this);
    labelOut->setGeometry(530,10,60,20);
    labelOut->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelOut->setText("Вывод");
    labelOut->show();

    //функция Sqrt
    labelSqrt = new QLabel(this);
    labelSqrt->setGeometry(10,40,80,20);
    labelSqrt->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelSqrt->setText("Sqrt(x)");
    labelSqrt->show();

    labelDescSqrt = new QLabel(this);
    labelDescSqrt->setGeometry(150,40,200,20);
    labelDescSqrt->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelDescSqrt->setText("Квадратный корень из х");
    labelDescSqrt->show();

    labelExamSqrt = new QLabel(this);
    labelExamSqrt->setGeometry(400,40,60,20);
    labelExamSqrt->setFrameStyle(QFrame::Panel | QFrame::Plain);
    labelExamSqrt->setText("Sqrt(x)");
    labelExamSqrt->show();

    lineEditSqrt = new QLineEdit(this);
    lineEditSqrt->setGeometry(460,40,50,20);
    lineEditSqrt->show();

    labelOutSqrt = new QLabel(this);
    labelOutSqrt->setGeometry(540,40,50,20);
    labelOutSqrt->show();

    buttonSqrt = new QPushButton(this);
    buttonSqrt->setGeometry(590,40,95,20);
    buttonSqrt->setText("Рассчитать");
    buttonSqrt->show();

    connect(buttonSqrt, SIGNAL(clicked()), this, SLOT(buttonSqrtClicked()));
}

Func::~Func()
{
    delete ui;
}

void Func::buttonSqrtClicked()
{
    double x,y;
    QString s1 = Func::lineEditSqrt->text();
    x = s1.toDouble();
    y = sqrt(x);
    labelOutSqrt->setText(QString::number(y));
}
