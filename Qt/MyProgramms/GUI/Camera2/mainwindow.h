#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QTextCodec>
#include "form.h"
#include <QPushButton>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class QSqlTableModel;
class QSqlDatabase;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:


private:
    Ui::MainWindow *ui;
    QMenu *mainMenu;
    QAction *closeApp;
    QAction *openTable;
    QWidget *myForm;
    QPushButton *saveButton;
    QSqlDatabase *db;
    QSqlTableModel *mModel;
    QSqlQuery *query;
    QLineEdit *lineLength;
    QLineEdit *lineWidth;
    QLineEdit *lineHeight;
    QLineEdit *lineVolume;

    double angle_av;
    double angle_ag;
    double f, c;
    double RV;
    double RG;
    double RK;

private:
    void createMenu();
    void createInterface();
    void count();

private slots:
    void inputData();
    void openTbl();
};

#endif // MAINWINDOW_H
