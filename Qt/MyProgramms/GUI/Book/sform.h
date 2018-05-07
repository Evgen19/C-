#ifndef SFORM_H
#define SFORM_H

#include <QWidget>
#include "book.h"
#include "ui_book.h"
#include <QtSql>
#include <QMenu>
#include <QAction>
#include <QMenuBar>


namespace Ui {
class SForm;
}

class SForm : public QWidget
{
    Q_OBJECT

public:
    explicit SForm(QWidget *parent = 0);
    ~SForm();

private slots:
    void exportCSV();

private:
    Ui::SForm *ui;
    QSqlDatabase *db;
    QSqlTableModel *model;

    void createTab();



};

#endif // SFORM_H
