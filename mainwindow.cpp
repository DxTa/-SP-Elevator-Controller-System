#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "outsidedialog.h"

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
    OutsideDialog *outsideDialog;
    outsideDialog = new OutsideDialog(NULL);
    outsideDialog->show();
    outsideDialog->raise();
    outsideDialog->activateWindow();

    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
