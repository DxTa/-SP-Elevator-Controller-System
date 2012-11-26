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

	/* Add normal slots */
    QObject::connect(ui->upButton, SIGNAL(clicked()), this, SLOT(upClicked()));
    QObject::connect(ui->downButton, SIGNAL(clicked()), this, SLOT(downClicked()));
    QObject::connect(ui->stepInsideButton, SIGNAL(clicked()), this, SLOT(stepInsideClicked()));


	/* Add arguments to slots */
	QSignalMapper* signalMapper = new QSignalMapper (this) ;
	connect (ui->floor_1, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->floor_2, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->floor_3, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->floor_4, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->floor_5, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->floor_6, SIGNAL(clicked()), signalMapper, SLOT(map())) ;

	signalMapper -> setMapping (ui->floor_1, 1) ;
	signalMapper -> setMapping (ui->floor_2, 2) ;
	signalMapper -> setMapping (ui->floor_3, 3) ;
	signalMapper -> setMapping (ui->floor_4, 4) ;
	signalMapper -> setMapping (ui->floor_5, 5) ;
	signalMapper -> setMapping (ui->floor_6, 6) ;

	connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(floor(int))) ;

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

void OutsideDialog::floor(int i) {
	curReq = sendRequest(REQ_FLOOR,makeInt(i*10));
	qDebug() << i*10;
}

void OutsideDialog::stepInsideClicked()
{
	curReq = sendRequest(REQ_DCLOSE,makeInt(10));
    //TODO: check if elevator arrived first
}
