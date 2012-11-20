#include "outsidedialog.h"
#include "ui_outsidedialog.h"

extern "C"
{
	#include <stdio.h>
	#include "modules/data.h"
	#include "modules/request.h"
// include C library here
}

OutsideDialog::OutsideDialog(QWidget *parent, ElevatorSystem *elevatorSystem) :
    QDialog(parent),
    ui(new Ui::OutsideDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->upButton, SIGNAL(clicked()), this, SLOT(upClicked()));
    QObject::connect(ui->downButton, SIGNAL(clicked()), this, SLOT(downClicked()));
    // QObject::connect(ui->stepInsideButton, SIGNAL(clicked()), this, SLOT(getInsideClicked()));

    this->elevatorSystem = elevatorSystem;
    // connect signal & slot of elevator system
}

OutsideDialog::~OutsideDialog()
{
    delete ui;
}

void OutsideDialog::upClicked()
{
 	curReq = sendRequest(REQ_CUP,makeInt(50));
//	qDebug() << *((int*)curReq->key);
    //TODO: make a request to the elevator system here
}

void OutsideDialog::downClicked()
{
 	curReq = sendRequest(REQ_CDOWN,makeInt(100));
//	qDebug() << *((int*)curReq->key);
    //TODO: make a request to the elevator system here
}

void OutsideDialog::stepInsideClicked()
{
    //TODO: check if elevator arrived first
}
