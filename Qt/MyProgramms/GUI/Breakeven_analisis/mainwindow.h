#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QImage>
#include <QLabel>
#include "form.h"
#include <QPushButton>
#include <QMessageBox>
#include <QTextCodec>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
void about();


private:
    void createMenu();
    void mainFone();
    void exit();
    void create();


    Ui::MainWindow *ui;
    Form *myform;
    QMenu *mainMenu;
    QAction *createAction;
    QAction *exitAction;
    QAction *aboutAction;
    QImage *image;
    QLabel *mainLabel;
    QLabel *titleLabel;
    QPushButton *button;
    QMessageBox *MsgBox;

};

#endif // MAINWINDOW_H
