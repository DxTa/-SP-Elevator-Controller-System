#include "elevatordialog.h"
#include "ui_elevatordialog.h"

ElevatorDialog::ElevatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElevatorDialog)
{
    ui->setupUi(this);
}

ElevatorDialog::~ElevatorDialog()
{
    delete ui;
}
