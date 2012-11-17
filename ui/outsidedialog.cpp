#include "outsidedialog.h"
#include "ui_outsidedialog.h"

int curFloor = 0;

extern "C"
{
	#include <stdio.h>
	#include "modules/data.h"
	#include "modules/request.h"
// include C library here
}

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
	curFloor++;
	sendRequest(REQ_CUP,makeInt(curFloor));
    //TODO: make a request to the elevator system here
}

void OutsideDialog::downClicked()
{
	curFloor--;
	sendRequest(REQ_CUP,makeInt(curFloor));
    //TODO: make a request to the elevator system here
}

void OutsideDialog::stepInsideClicked()
{
    //TODO: check if elevator arrived first
}
