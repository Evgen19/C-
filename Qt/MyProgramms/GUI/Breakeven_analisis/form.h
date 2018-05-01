#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include <QtGui>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QString>
//#include <qwt_plot.h>
//#include <qwt_plot_curve.h>
//#include <QGlobal.h>
#include <QTextStream>

extern int q;
extern int s;
extern int X;

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();



private slots:
    void Sum();
    void createGrafic();
    void openPrinter();
    void openFile();
    void saveFile();
    void saveGrafik();



private:
    void createMenu();
    void createInterface();



    Ui::Form *ui;
    QMenu *myMenu;
    QMenuBar *myBar;
    QAction *closeAction;
    QAction *openAction;
    QAction *saveFileAs;
    QAction *saveGraficAction;
    QAction *printAction;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QTextEdit *textEdit1;
    QPushButton *countButton;
    QPushButton *createGraficButton;
    QPushButton *clearButton;
};

#endif // FORM_H
