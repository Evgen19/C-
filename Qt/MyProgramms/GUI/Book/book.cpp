/*Программа-локальная база данных для книг подключенная к Microsoft Access*/
//Подключаем необходимые библиотеки
#include "book.h"
#include "ui_book.h"
#include "sform.h"
#include "ui_sform.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QPushButton>
#include <QTextCodec>
#include <QBuffer>
#include <QByteArray>

//константа для подключения базы данных
#define ACCESS ("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\Evgen\\Documents\\db2.mdb")

Book::Book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);
    createMenu();
}

Book::~Book()
{
    delete ui;
}

//метод создает меню главного окна
void Book::createMenu()
{
  mainMenu =  menuBar()->addMenu("Меню");
  openTbl = new QAction(("Открыть таблицу"),this);
  mainMenu->addAction(openTbl);
  connect(openTbl, SIGNAL(triggered()), this, SLOT(openTable()));
  closeApp = new QAction(("Закрыть приложение"), this);
  mainMenu->addAction(closeApp);
  connect(closeApp, SIGNAL(triggered(bool)), this, SLOT(close()));
}

//метод открывает форму с таблицей базы данных
void Book::openTable()
{
  SForm *f = new SForm();
  f->show();
  f->setWindowTitle("Табличные данные");
}



void Book::on_pushButton_save_clicked()
{
    //Подключаем базу данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(ACCESS);

    if(!db.open())
    {
        QMessageBox::critical(this, "Error", db.lastError().text());
        return;
    }


    //Создаем подключение для занесения данных
    QSqlQuery *query = new QSqlQuery(ACCESS);
    query->prepare("INSERT INTO book(name, author_name, author_fname, release_year, publishing, country, genre)" "VALUES(:name, :author_name, :author_fname, :release_year, :publishing, :country, :genre);");
    query->bindValue(":name", ui->lineEdit_name->text());
    query->bindValue(":author_name", ui->lineEdit_1->text());
    query->bindValue(":author_fname", ui->lineEdit_2->text());
    query->bindValue(":release_year", ui->lineEdit_release->text());
    query->bindValue(":publishing", ui->lineEdit_publishing->text());
    query->bindValue(":country", ui->comboBox_country->currentText());
    query->bindValue(":genre", ui->comboBox_genre->currentText());
    //query->bindValue(":picture", inByteArray );
    query->exec();
}



