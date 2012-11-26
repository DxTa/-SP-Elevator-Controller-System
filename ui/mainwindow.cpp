#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "elevatordialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->startButton,SIGNAL(clicked()),
                     this, SLOT(startElevatorSimulator()));
}

void MainWindow::startElevatorSimulator()
{
    this->elevatorSystem = new ElevatorSystem();
    elevatorSystem->start();

    ElevatorDialog *elevatorDialog;
    elevatorDialog = new ElevatorDialog(NULL);
    elevatorDialog->show();
    elevatorDialog->raise();
    elevatorDialog->activateWindow();

//    OutsideDialog *outsideDialog;
//    outsideDialog = new OutsideDialog(NULL, this->elevatorSystem);
//    outsideDialog->show();
//    outsideDialog->raise();
//    outsideDialog->activateWindow();

    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
