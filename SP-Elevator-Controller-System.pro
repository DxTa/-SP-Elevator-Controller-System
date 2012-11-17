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
        ui/mainwindow.cpp \
    modules/request.c \
    modules/error.c \
    modules/elevator.c \
    modules/data.c \
    modules/action.c \
    modules/FunctionQueue/fqueue.c \
    ui/outsidedialog.cpp

HEADERS  += ui/mainwindow.h \
    modules/request.h \
    modules/error.h \
    modules/elevator.h \
    modules/data.h \
    modules/action.h \
    modules/FunctionQueue/fqueue.h \
    ui/outsidedialog.h

FORMS    += ui/mainwindow.ui \
    ui/outsidedialog.ui
