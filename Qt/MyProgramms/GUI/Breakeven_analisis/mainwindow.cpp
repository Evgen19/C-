#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include <QWidget>
#include <QTextCodec>
#include <QFont>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myform = new Form();
    MainWindow::setWindowTitle(tr("Breakeven-analisis"));
    MainWindow::setFixedSize(516,380);
    createMenu();
    mainFone();
    connect(exitAction, SIGNAL(triggered()),this, SLOT(close()));
    connect(createAction, SIGNAL(triggered()),myform, SLOT(show()));


}

MainWindow::~MainWindow()
{
    delete ui;

}

//The method that creates the menu
void MainWindow::createMenu()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    mainMenu = menuBar()->addMenu(tr("Menu"));
    createAction = new QAction(tr("Create"),this);
    exitAction = new QAction(tr("Exit"),this);
    mainMenu->addAction(createAction);
    mainMenu->addAction(exitAction);
    mainMenu = menuBar()->addMenu(tr("Help"));
    aboutAction = new QAction(tr("About program"),this);
    mainMenu->addAction(aboutAction);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

//The method that creates the background of the main program window
void MainWindow::mainFone()
{
    titleLabel = new QLabel(tr("Breakeven-analisis breakout program"),this);
    titleLabel->setGeometry(70,40,330,40);
    titleLabel->setFont(QFont("Times",13, QFont::Bold));
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLabel = new QLabel(tr(""),this);
    mainLabel->setGeometry(8,80,500,300);
    QPixmap myPixmap(":/images/fone.jpg");
    mainLabel->setPixmap(myPixmap);
}

void MainWindow::about()
{
    MsgBox = new QMessageBox;
    MsgBox->setWindowTitle("About program");
    MsgBox->setText("Breakeven-analisis-break-even calculation.\nThe program is developed in Qt 4.8.5.\nAuthor Smirnov Eugene.\nAll rights reserved. 2017 year.");
    MsgBox->setIcon(QMessageBox::Information);
    MsgBox->show();
}


