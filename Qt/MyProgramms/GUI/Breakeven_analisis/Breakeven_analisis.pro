#-------------------------------------------------
#
# Project created by QtCreator 2016-12-23T15:46:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = Breakeven_analisis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    form.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    form.ui

//INCLUDEPATH += C:/Documentation/QWT/include
//LIBS += -LC:/Documentation/QWT/lib -lqwt

RESOURCES += \
    res.qrc
