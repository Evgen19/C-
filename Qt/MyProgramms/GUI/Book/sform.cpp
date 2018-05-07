#include "sform.h"
#include "ui_sform.h"
#include "book.h"
#include "ui_book.h"
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QFile>
#include <QString>

//константа для подключения к базе данных
#define ACCESS ("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\Evgen\\Documents\\db2.mdb")

SForm::SForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SForm)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(exportCSV()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    createTab();
}

SForm::~SForm()
{
    delete ui;
}


//метод подключает базу данных и выводит в tableview
void SForm::createTab()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(ACCESS);

    if(!db.open())
    {
        QMessageBox::critical(this, "Error", db.lastError().text());
        return;
    }

    //вывод базы
    model = new QSqlTableModel();
    model->setTable("book");
    model->select();
    ui->tableView->setModel(model);

    //установка ширины определенных столбцов таблицы
    ui->tableView->setColumnWidth(0,30);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,80);
    ui->tableView->setColumnWidth(3,80);
}

//метод сохраняет данные базы в файл в формате CSV
void SForm::exportCSV()
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


