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
    modules/respmaker.c \
    modules/actioner.c \
    modules/FunctionQueue/fqueue.c \
    modules/planner.c \
    modules/engine.c \
    modules/door.c \
    modules/informer.c \
    modules/checker.c \
    modules/displayer.c \
    modules/alarmer.c \
    elevatorsystem.cpp \
    ui/elevatordialog.cpp

HEADERS  += ui/mainwindow.h \
    modules/request.h \
    modules/responder.h \
    modules/requestor.h \
    modules/data.h \
    modules/actmaker.h \
    modules/respmaker.h \
    modules/actioner.h \
    modules/FunctionQueue/fqueue.h \
    modules/planner.h \
    modules/engine.h \
    modules/door.h \
    modules/informer.h \
    modules/checker.h \
    modules/displayer.h \
    modules/alarmer.h \
    elevatorsystem.h \
    ui/elevatordialog.h

FORMS    += ui/mainwindow.ui \
    ui/elevatordialog.ui
