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
    modules/responder.c \
    modules/requestor.c \
    modules/data.c \
    modules/actmaker.c \
    modules/actioner.c \
    modules/FunctionQueue/fqueue.c \
    modules/planner.c \
    modules/engine.c \
    ui/outsidedialog.cpp \
    elevatorsystem.cpp \
    ui/insidedialog.cpp

HEADERS  += ui/mainwindow.h \
    modules/request.h \
    modules/responder.h \
    modules/requestor.h \
    modules/data.h \
    modules/actmaker.h \
    modules/actioner.h \
    modules/FunctionQueue/fqueue.h \
    modules/planner.h \
    modules/engine.h \
    ui/outsidedialog.h \
    elevatorsystem.h \
    ui/insidedialog.h

FORMS    += ui/mainwindow.ui \
    ui/outsidedialog.ui \
    ui/insidedialog.ui
