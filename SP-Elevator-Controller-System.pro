#-------------------------------------------------
#
# Project created by QtCreator 2012-11-15T21:23:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SP-Elevator-Controller-System
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    request.c \
    error.c \
    elevator.c \
    data.c \
    action.c \
    FunctionQueue/fqueue.c

HEADERS  += mainwindow.h \
    request.h \
    error.h \
    elevator.h \
    data.h \
    action.h \
    FunctionQueue/fqueue.h

FORMS    += mainwindow.ui
