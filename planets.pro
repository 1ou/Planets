#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T03:00:05
#
#-------------------------------------------------

QT           += opengl widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = planets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    planet.cpp \
    mainworker.cpp \
    coordinate.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    planet.h \
    mainworker.h \
    coordinate.h
