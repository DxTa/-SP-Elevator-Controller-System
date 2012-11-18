#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "elevatorsystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void startElevatorSimulator();

private:
    Ui::MainWindow *ui;
    ElevatorSystem *elevatorSystem;
};

#endif // MAINWINDOW_H
