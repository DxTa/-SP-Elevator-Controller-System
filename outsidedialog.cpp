#include "outsidedialog.h"
#include "ui_outsidedialog.h"

OutsideDialog::OutsideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutsideDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->upButton, SIGNAL(clicked()), this, SLOT(upClicked()));
    QObject::connect(ui->downButton, SIGNAL(clicked()), this, SLOT(downClicked()));
    QObject::connect(ui->stepInsideButton, SIGNAL(clicked()), this, SLOT(getInsideClicked()));
}

OutsideDialog::~OutsideDialog()
{
    delete ui;
}

void OutsideDialog::upClicked()
{
    //TODO: make a request to the elevator system here
}

void OutsideDialog::downClicked()
{
    //TODO: make a request to the elevator system here
}

void OutsideDialog::stepInsideClicked()
{
    //TODO: check if elevator arrived first
}
