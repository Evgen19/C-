#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "mainwindow.h"
#include <QMenuBar>
#include <QSqlDatabase>
#include <QtSql>
#include <QFile>


namespace Ui {
class Form;
}

class QSqlTableModel;
class QSqlDatabase;

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

public:

private:
    Ui::Form *ui;
    QSqlDatabase *db;
    QSqlTableModel *mModel;
    QMenu *myMenu;
    QMenuBar *myBar;
    QAction *saveTable;
    QAction *inputData;
    QAction *closeTable;


private:
    void createMenu();
    void createTab();


private slots:
    void openMainWindow();
    void  saveTab();
};

#endif // FORM_H
