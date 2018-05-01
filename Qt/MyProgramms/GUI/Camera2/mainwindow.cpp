#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <math.h>
#include <QString>

#define ACCESS ("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\Evgen\\Documents\\base.mdb")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle(tr("Input Data"));
    myForm = new Form();

    createMenu();
    createInterface();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenu()
{

    mainMenu = menuBar()->addMenu(tr("Menu"));
    openTable = new QAction(tr("Open table"), this);
    mainMenu->addAction(openTable);
    closeApp = new QAction(tr("Close app"), this);
    mainMenu->addAction(closeApp);
    connect(openTable, SIGNAL(triggered()), this, SLOT(openTbl()));
    connect(closeApp, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::openTbl()
{
    myForm->show();
}

void MainWindow::createInterface()
{
    saveButton = new QPushButton(this);
    saveButton->setGeometry(230,210,100,25);
    saveButton->setText(tr("Save"));
    saveButton->show();
    connect(saveButton, SIGNAL(clicked()), this, SLOT(inputData()));

    lineLength = new QLineEdit(this);
    lineLength->setGeometry(230,70,100,20);
    lineLength->show();

    lineWidth = new QLineEdit(this);
    lineWidth->setGeometry(230,105,100,20);
    lineWidth->show();

    lineHeight = new QLineEdit(this);
    lineHeight->setGeometry(230,140,100,20);
    lineHeight->show();

    lineVolume = new QLineEdit(this);
    lineVolume->setGeometry(230,175,100,20);
    lineVolume->show();
}

void MainWindow::count()
{
    double a=lineLength->text().toDouble();
    double b=lineWidth->text().toDouble();
    double h=lineHeight->text().toDouble();
    double L=lineVolume->text().toDouble();
    double AN;
    double CD=L;
    double s;
    double angle_CND;
    double angle_DCN;
    double angle_BAN=0;
    angle_BAN=angle_DCN;
    double angle_CDN;
    double CN;
    double AC, NK, ND;
    double AP,R, V;
    double W;
    double K=1.3; //Разрешение камеры (4:3, 16:9)=(1,3; 1,7)
    double L1, r;
    double SV, SH;

    s=h-L;
    c = sqrt(a*a+b*b);
    angle_av = atan(c/s)-atan(c/(2*h));
    angle_av=round(angle_av);
    AN=sqrt(c*c+pow(s,2));
    angle_CND=90-(angle_av/2);
    angle_CND=round(angle_CND);
    angle_BAN=atan(c/s);
    angle_CDN=(90+(angle_av/2))-atan(c/s);
    CN=(CD*sin(angle_CDN*angle_CDN))/sin(angle_CDN);
    AC=CN-AN;
    AP=(CN+AC)*cos(angle_ag/2);
    R=AP;
    AN=AC+CN;
    NK=2*((AN*AN)-(R*R));
    V=NK;
    f=(R*W)/V;

    //Пересчет реальных углов
    angle_av = 2*atan(W/(2*f));
    angle_ag=K*angle_av;
    angle_CND=90-(angle_av/2);
    angle_BAN=atan(c/s);
    angle_CDN=(90+(angle_av/2))-atan(c/s);
    CN=(CD*sin(angle_CDN*angle_CDN))/sin(angle_CDN);
    AC=CN-AN;
    AP=(CN+AC)*cos(angle_ag/2);
    R=AP;
    AN=AC+CN;
    NK=2*((AN*AN)-(R*R));
    V=NK;
    ND=(CD*sin(angle_CDN))/sin(angle_CND);
    L1=(ND/NK)*(ND/NK);
    SV=1;
    r=10;
    RV=((2000*R)/SV)*tan(angle_av/2)*(r/L1);
    SH=1;
    RG = ((2000*R)/SH)*tan(angle_ag/2)*(r/L1);
    RK = RV*RG;
}

void MainWindow::inputData()
{
     count();

     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName(ACCESS);

     if(!db.open())
     {
         QMessageBox::critical(this, "Error", db.lastError().text());
         return;
     }

     QSqlQuery *query = new QSqlQuery(ACCESS);
     query->prepare("INSERT INTO camera (a, b, h, L, angle_av, angle_ag, f, RV, RG, RK)" "VALUES(:a, :b, :h, :L, :angle_av, :angle_ag, :f, :RV, :RG, :RK);");
     query->bindValue(":a", lineLength->text());
     query->bindValue(":b", lineWidth->text());
     query->bindValue(":h", lineHeight->text());
     query->bindValue(":L", lineVolume->text());
     query->bindValue(":angle_av", angle_av );
     query->bindValue(":angle_ag", angle_ag);
     query->bindValue(":f", f);
     query->bindValue(":RV", RV);
     query->bindValue(":RG", RG);
     query->bindValue(":RK", RK);
     query->exec();


}
