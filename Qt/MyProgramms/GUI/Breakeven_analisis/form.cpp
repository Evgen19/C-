#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include <QWidget>
#include <QtGui>
#include <QTextCodec>
#include <QFont>
#include <QFile>

int q;  //Number of students accepted for training
int s;  //Weighted average cost of education per year (rub.)
int X1;  //Variable costs per student (rub.)
const int K=7500000;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)

{
    ui->setupUi(this);
    QTextCodec *codec1 = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec1);
    //QTextCodec::setCodecForTr(codec1);
    //QTextCodec::setCodecForCStrings(codec1);
    Form::setWindowTitle(tr("Calculation of breakeven point"));
    Form::setFixedSize(1100,540);

    createMenu();
    createInterface();

}

Form::~Form()
{
    delete ui;
}

void Form::createMenu()
{
    myBar = new QMenuBar(this);
    myMenu = myBar->addMenu(tr("Calculation"));
    openAction = new QAction(tr("Open file"),this);
    saveFileAs = new QAction(tr("Save file as"),this);
    saveGraficAction = new QAction(tr("Save grafic as"),this);
    printAction = new QAction(tr("Print"),this);
    closeAction = new QAction(tr("Close"),this);
    myMenu->addAction(openAction);
    myMenu->addAction(saveFileAs);
    myMenu->addAction(saveGraficAction);
    myMenu->addAction(printAction);
    myMenu->addAction(closeAction);
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(printAction, SIGNAL(triggered()), this, SLOT(OpenPrinter()));
    connect(saveFileAs, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(saveGraficAction, SIGNAL(triggered()), this, SLOT(saveGrafik()));
}

void Form::createInterface()
{
label1 = new QLabel(tr("Number of students\naccepted for training"),this);
label1->setGeometry(20,20,140,50);
lineEdit1 = new QLineEdit(tr(""),this);
lineEdit1->setGeometry(200,35,80,20);

label2 = new QLabel(tr("Weighted average cost\nof education per year (rub.)"),this);
label2->setGeometry(20,60,200,50);
lineEdit2 = new QLineEdit(tr(""),this);
lineEdit2->setGeometry(200,75,80,20);

label3 = new QLabel(tr("Variable costs\nper student (rub.)"),this);
label3->setGeometry(20,100,200,50);
lineEdit3 = new QLineEdit(tr(""),this);
lineEdit3->setGeometry(200,115,80,20);

label4 = new QLabel(tr("Output of result"),this);
label4->setGeometry(20,145,200,50);
textEdit1 = new QTextEdit(tr(""),this);
textEdit1->setGeometry(200,155,280,50);

countButton = new QPushButton(tr("Count"),this);
countButton->setGeometry(20,220,120,25);
connect(countButton, SIGNAL(clicked()), this, SLOT(Sum()));

createGraficButton = new QPushButton(tr("Create grafic"),this);
createGraficButton->setGeometry(20,250,120,25);
connect(createGraficButton, SIGNAL(clicked()), this, SLOT(createGrafic()));

clearButton = new QPushButton(tr("Clear"),this);
clearButton->setGeometry(20,280,120,25);
connect(clearButton, SIGNAL(clicked()), lineEdit1, SLOT(clear()));
connect(clearButton, SIGNAL(clicked()), lineEdit2, SLOT(clear()));
connect(clearButton, SIGNAL(clicked()), lineEdit3, SLOT(clear()));
connect(clearButton, SIGNAL(clicked()), textEdit1, SLOT(clear()));
}

void Form::Sum()
{
q = Form::lineEdit1->text().toInt();
s = Form::lineEdit2->text().toInt();
X1 = Form::lineEdit3->text().toInt();
int G = s*q;                           //Income of the university per year
int V=X1*q+K;                          //Total costs of the university
int q1=K/(s-X1);
QString dohod = "The income of the university was:";
QString izder = "Total costs amounted to: ";
QString breakeven = "The break-even point value is: ";
QString perenos = "\n";
QString rub = "(rub.)";
QString student = " students.";
QString finalStr1 = dohod + QString::number(G) + rub + perenos;
QString finalStr2 = izder + QString::number(V) + rub + perenos;
QString finalStr3 = breakeven + QString::number(q1) + student;
Form::textEdit1->setText(finalStr1 + finalStr2 +finalStr3);
}

void Form::createGrafic()
{
    //The method that creates the graph
    double a = 0;
    double b =  500; //Number of students Ox
    double h = 0.01; //Step chart Ox

    int N=(b-a)/h + 2;
    QVector<double> x(N), y(N), y1(N);


    int i=0;
    //int s=74000;
    //int X1=10000;
    //int K=7500000;
    for (double X=a; X<=b; X+=h)
    {
        x[i] = X;
        y[i] = X*s;
        y1[i] = X*X1+K;
        i++;
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();

    ui->widget->graph(0)->setData(x, y);
    ui->widget->graph(0)->setPen(QPen(Qt::green));
    ui->widget->graph(0)->setName("Income of the university");
    ui->widget->addGraph();
    ui->widget->graph(1)->setData(x, y1);
    ui->widget->graph(1)->setPen(QPen(Qt::red));
    ui->widget->graph(1)->setName(tr("Total costs university"));


    ui->widget->xAxis->setLabel("Number of students");
    ui->widget->yAxis->setLabel("Income of the university/Total costs university");

    ui->widget->xAxis->setRange(a, b);


    double minY = y[0], maxY = y[0];
    for (int i=1; i<N; i++)
    {
        if (y[i]<minY) minY = y[i];
        if (y[i]>maxY) maxY = y[i];
    }
    ui->widget->yAxis->setRange(minY, maxY);


    ui->widget->legend->setVisible(true);
    ui->widget->replot();
}

void Form::openPrinter()
{
    QPrinter printer;
    QPrintDialog* pPrintDialog = new QPrintDialog(&printer);
    if (pPrintDialog->exec()== QDialog::Accepted)
    {

    }
    delete pPrintDialog;
}

void Form::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt);;Text Files(*.doc)"));

        if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                // error message
            } else {
                QTextStream stream(&file);
                stream << textEdit1->toPlainText().toUtf8();
                stream.flush();
                file.close();
            }
        }
}

void Form::openFile()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("OpenFile"),"",tr("Text Files (*.txt);;Text Files(*.doc)"));
        if (fileName !=""){
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)){
                QMessageBox::critical(this,tr("Error"),tr("Could not open file"));
                return;
            }
            QTextStream in(&file);
            textEdit1->setText(in.readAll());
            file.close();
        }
}

void Form::saveGrafik()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Choose a filename to save under"),
                                                        QString(),
                                                        tr("PNG(*.png);;JPG(*.jpg);;PDF(*.pdf);;BMP(*.bmp);;All Files(*)")
                                                        );
        if(!fileName.isEmpty())
        {
            if(fileName.endsWith(".png", Qt::CaseInsensitive))
            {

                ui->widget->savePng(fileName);
            }
            else if(fileName.endsWith(".jpg", Qt::CaseInsensitive))
            {

                ui->widget->saveJpg(fileName);
            }
            else if(fileName.endsWith(".pdf", Qt::CaseInsensitive))
            {

                ui->widget->savePdf(fileName);
            }
            else if(fileName.endsWith(".bmp", Qt::CaseInsensitive))
            {

                ui->widget->saveBmp(fileName);
            }
            else
            {
                fileName += ".png";

                ui->widget->savePng(fileName);
            }
        }
}

