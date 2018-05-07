#ifndef BOOK_H
#define BOOK_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMenu>
#include <QAction>
#include "sform.h"
#include "ui_sform.h"

namespace Ui {
class Book;
}

class Book : public QMainWindow
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = 0);
    ~Book();

private:
    Ui::Book *ui;
    QMenu *mainMenu;
    QAction *openTbl;
    QAction *closeApp;



    void createMenu();

private slots:
    void openTable();
    void on_pushButton_save_clicked();

};

#endif // BOOK_H
