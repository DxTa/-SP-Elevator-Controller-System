#include "elevatordialog.h"
#include "ui_elevatordialog.h"


extern "C"
{
	#include <stdio.h>
	#include "modules/data.h"
	#include "modules/request.h"
// include C library here
}

ElevatorDialog::ElevatorDialog(QWidget *parent, ElevatorSystem *elevatorSystem) :
    QDialog(parent),
    ui(new Ui::ElevatorDialog)
{

    ui->setupUi(this);

	/* Add arguments to slots */
	QSignalMapper* signalMapper = new QSignalMapper (this) ;

	connect (ui->openDoorButton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->closeDoorButton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->digitButton_1, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->digitButton_2, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->digitButton_3, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->digitButton_4, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->digitButton_5, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->digitButton_6, SIGNAL(clicked()), signalMapper, SLOT(map())) ;

	connect (ui->downButton_1, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->upButton_1, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->downButton_2, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->upButton_2, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->downButton_3, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->upButton_3, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->downButton_4, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->upButton_4, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->downButton_5, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->upButton_5, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->downButton_6, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
	connect (ui->upButton_6, SIGNAL(clicked()), signalMapper, SLOT(map())) ;

	signalMapper -> setMapping (ui->digitButton_1, 1) ;
	signalMapper -> setMapping (ui->digitButton_2, 2) ;
	signalMapper -> setMapping (ui->digitButton_3, 3) ;
	signalMapper -> setMapping (ui->digitButton_4, 4) ;
	signalMapper -> setMapping (ui->digitButton_5, 5) ;
	signalMapper -> setMapping (ui->digitButton_6, 6) ;

	signalMapper -> setMapping (ui->downButton_1, 1) ;
	signalMapper -> setMapping (ui->downButton_2, 2) ;
	signalMapper -> setMapping (ui->downButton_3, 3) ;
	signalMapper -> setMapping (ui->downButton_4, 4) ;
	signalMapper -> setMapping (ui->downButton_5, 5) ;
	signalMapper -> setMapping (ui->downButton_6, 6) ;

	signalMapper -> setMapping (ui->upButton_1, 1) ;
	signalMapper -> setMapping (ui->upButton_2, 2) ;
	signalMapper -> setMapping (ui->upButton_3, 3) ;
	signalMapper -> setMapping (ui->upButton_4, 4) ;
	signalMapper -> setMapping (ui->upButton_5, 5) ;
	signalMapper -> setMapping (ui->upButton_6, 6) ;

	connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(floor(int))) ;

    this->elevatorSystem = elevatorSystem;

}

ElevatorDialog::~ElevatorDialog()
{
    delete ui;
}


void ElevatorDialog::upClicked(int i) {
 	curReq = sendRequest(REQ_CUP,makeInt(i));
	qDebug() << i;
}

void ElevatorDialog::downClicked(int i) {
 	curReq = sendRequest(REQ_CDOWN,makeInt(i));
	qDebug() << i;
}

void ElevatorDialog::floor(int i ) {
	curReq = sendRequest(REQ_FLOOR,makeInt(i));
	qDebug() << i;
}
