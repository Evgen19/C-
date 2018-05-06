#include "sform.h"
#include "ui_sform.h"
#include "book.h"
#include "ui_book.h"
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

//константа для подключения к базе данных
#define ACCESS ("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\Evgen\\Documents\\db2.mdb")

SForm::SForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SForm)
{
    ui->setupUi(this);
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
