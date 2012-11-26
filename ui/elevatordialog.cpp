#include "elevatordialog.h"
#include "ui_elevatordialog.h"

extern "C"
{
	#include <stdio.h>
	#include "modules/request.h"
// include C library here
}

int ElevatorDialog::ElevatorViewY = 590;

ElevatorDialog::ElevatorDialog(QWidget *parent, ElevatorSystem *elevatorSystem) :
    QDialog(parent),
    ui(new Ui::ElevatorDialog)
{

    ui->setupUi(this);

	/* Add arguments to slots */
	QSignalMapper* signalMapperCUP = new QSignalMapper (this) ;
	QSignalMapper* signalMapperCDOWN = new QSignalMapper (this) ;
	QSignalMapper* signalMapperFloor = new QSignalMapper (this) ;
	QSignalMapper* signalMapperDoor = new QSignalMapper (this) ;
	QSignalMapper* signalMapperWeight = new QSignalMapper (this) ;

	connect (ui->openDoorButton, SIGNAL(clicked()), signalMapperWeight, SLOT(map())) ;
	connect (ui->closeDoorButton, SIGNAL(clicked()), signalMapperWeight, SLOT(map())) ;

	signalMapperWeight -> setMapping (ui->closeDoorButton, -10) ;
	signalMapperWeight -> setMapping (ui->openDoorButton, 10) ;
	connect (signalMapperWeight, SIGNAL(mapped(int)), this, SLOT(changeWeight(int))) ;

	connect (ui->digitButton_1, SIGNAL(clicked()), signalMapperFloor, SLOT(map())) ;
	connect (ui->digitButton_2, SIGNAL(clicked()), signalMapperFloor, SLOT(map())) ;
	connect (ui->digitButton_3, SIGNAL(clicked()), signalMapperFloor, SLOT(map())) ;
	connect (ui->digitButton_4, SIGNAL(clicked()), signalMapperFloor, SLOT(map())) ;
	connect (ui->digitButton_5, SIGNAL(clicked()), signalMapperFloor, SLOT(map())) ;
	connect (ui->digitButton_6, SIGNAL(clicked()), signalMapperFloor, SLOT(map())) ;

	signalMapperFloor -> setMapping (ui->digitButton_1, 1) ;
	signalMapperFloor -> setMapping (ui->digitButton_2, 2) ;
	signalMapperFloor -> setMapping (ui->digitButton_3, 3) ;
	signalMapperFloor -> setMapping (ui->digitButton_4, 4) ;
	signalMapperFloor -> setMapping (ui->digitButton_5, 5) ;
	signalMapperFloor -> setMapping (ui->digitButton_6, 6) ;

	connect (signalMapperFloor, SIGNAL(mapped(int)), this, SLOT(floor(int))) ;

	connect (ui->downButton_1, SIGNAL(clicked()), signalMapperCDOWN, SLOT(map())) ;
	connect (ui->upButton_1, SIGNAL(clicked()), signalMapperCUP, SLOT(map())) ;
	connect (ui->downButton_2, SIGNAL(clicked()), signalMapperCDOWN, SLOT(map())) ;
	connect (ui->upButton_2, SIGNAL(clicked()), signalMapperCUP, SLOT(map())) ;
	connect (ui->downButton_3, SIGNAL(clicked()), signalMapperCDOWN, SLOT(map())) ;
	connect (ui->upButton_3, SIGNAL(clicked()), signalMapperCUP, SLOT(map())) ;
	connect (ui->downButton_4, SIGNAL(clicked()), signalMapperCDOWN, SLOT(map())) ;
	connect (ui->upButton_4, SIGNAL(clicked()), signalMapperCUP, SLOT(map())) ;
	connect (ui->downButton_5, SIGNAL(clicked()), signalMapperCDOWN, SLOT(map())) ;
	connect (ui->upButton_5, SIGNAL(clicked()), signalMapperCUP, SLOT(map())) ;
	connect (ui->downButton_6, SIGNAL(clicked()), signalMapperCDOWN, SLOT(map())) ;
	connect (ui->upButton_6, SIGNAL(clicked()), signalMapperCUP, SLOT(map())) ;

	signalMapperCDOWN -> setMapping (ui->downButton_1, 1) ;
	signalMapperCDOWN -> setMapping (ui->downButton_2, 2) ;
	signalMapperCDOWN -> setMapping (ui->downButton_3, 3) ;
	signalMapperCDOWN -> setMapping (ui->downButton_4, 4) ;
	signalMapperCDOWN -> setMapping (ui->downButton_5, 5) ;
	signalMapperCDOWN -> setMapping (ui->downButton_6, 6) ;

	signalMapperCUP -> setMapping (ui->upButton_1, 1) ;
	signalMapperCUP -> setMapping (ui->upButton_2, 2) ;
	signalMapperCUP -> setMapping (ui->upButton_3, 3) ;
	signalMapperCUP -> setMapping (ui->upButton_4, 4) ;
	signalMapperCUP -> setMapping (ui->upButton_5, 5) ;
	signalMapperCUP -> setMapping (ui->upButton_6, 6) ;

	connect (signalMapperCDOWN, SIGNAL(mapped(int)), this, SLOT(downClicked(int))) ;
	connect (signalMapperCUP, SIGNAL(mapped(int)), this, SLOT(upClicked(int))) ;

    this->elevatorSystem = elevatorSystem;

    // Elevator view
    this->connect(this->elevatorSystem, SIGNAL(changeElevatorPosition(int)), this, SLOT(changeElevatorPosition(int)));
}

ElevatorDialog::~ElevatorDialog()
{
    delete ui;
}


void ElevatorDialog::upClicked(int i) {
 	curReq = sendRequest(REQ_CUP,makeInt(i*20));
}

void ElevatorDialog::downClicked(int i) {
 	curReq = sendRequest(REQ_CDOWN,makeInt(i*20));
}

void ElevatorDialog::floor(int i ) {
	curReq = sendRequest(REQ_FLOOR,makeInt(i*20));
}

void ElevatorDialog::changeWeight(int i) {
	addWeight(1,i);
}

void ElevatorDialog::changeElevatorPosition(int position)
{
    QRect geometry = ui->elevatorView->geometry();

    geometry.setY(ElevatorDialog::ElevatorViewY - position*((30-2)/6));

    ui->elevatorView->setGeometry(geometry);
}
