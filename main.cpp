#include "./ui/mainwindow.h"
#include <QApplication>

#include <iostream>

extern "C"
{
// include C library here
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
