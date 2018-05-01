#ifndef SFORM_H
#define SFORM_H

#include <QWidget>
#include "book.h"
#include "ui_book.h"
#include <QtSql>


namespace Ui {
class SForm;
}

class SForm : public QWidget
{
    Q_OBJECT

public:
    explicit SForm(QWidget *parent = 0);
    ~SForm();

private:
    Ui::SForm *ui;
    QSqlDatabase *db;
    QSqlTableModel *model;

    void createTab();

};

#endif // SFORM_H
