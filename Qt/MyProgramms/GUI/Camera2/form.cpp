#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include <QWidget>
#include <QTextCodec>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QFile>
#include <QFileDialog>

#define ACCESS ("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\Evgen\\Documents\\base.mdb")

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    Form::setWindowTitle(tr("Table data"));
    createMenu();
    createTab();
}

Form::~Form()
{
    delete ui;
}


void Form::createMenu()
{
  myBar = new QMenuBar(this);
  myMenu = myBar->addMenu(tr("Menu"));

  saveTable = new QAction(tr("Save table"),this);
  myMenu->addAction(saveTable);
  connect(saveTable, SIGNAL(triggered()), this, SLOT(saveTab()));

  inputData = new QAction(tr("Input data again"), this);
  myMenu->addAction(inputData);
  connect(inputData, SIGNAL(triggered()), this, SLOT(openMainWindow()));

  closeTable = new QAction(tr("Close table"), this);
  myMenu->addAction(closeTable);
  connect(closeTable, SIGNAL(triggered()), this, SLOT(close()));

}

void Form::createTab()
{
     QSqlDatabase *db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName(ACCESS);

     if(!db.open())
     {
         QMessageBox::critical(this, "Error", db.lastError().text());
         return;
     }

     mModel = new QSqlTableModel(this);
     mModel->setTable("camera");
     mModel->select();
     ui->tableView->setModel(mModel);


     ui->tableView->setColumnWidth(0,30);
     ui->tableView->setColumnWidth(1,40);
     ui->tableView->setColumnWidth(2,40);
     ui->tableView->setColumnWidth(3,40);
     ui->tableView->setColumnWidth(4,70);
     ui->tableView->setColumnWidth(5,70);
     ui->tableView->setColumnWidth(6,70);
     ui->tableView->setColumnWidth(7,50);
     ui->tableView->setColumnWidth(8,50);
     ui->tableView->setColumnWidth(9,50);


}

void Form::openMainWindow()
{
    Form::close();
}

void Form::saveTab()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Table"),"",tr("Text Files(*.csv)"));
    QFile f(fileName);

        if( f.open( QIODevice::WriteOnly ) )
        {
            QTextStream ts( &f );
            QStringList strList;

            strList << "\" \"";
            for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
                strList << "\""+ui->tableView->model()->headerData(c, Qt::Horizontal).toString()+"\"";
            ts << strList.join( ";" )+"\n";

            for( int r = 0; r < ui->tableView->verticalHeader()->count(); ++r )
            {
                strList.clear();
                strList << "\""+ui->tableView->model()->headerData(r, Qt::Vertical).toString()+"\"";
                for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
                {
                    strList << "\""+ui->tableView->model()->data(ui->tableView->model()->index(r, c), Qt::DisplayRole).toString()+"\"";
                }
                ts << strList.join( ";" )+"\n";
            }
            f.close();
        }
}
