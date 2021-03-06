#include "elevatordialog.h"
#include "ui_elevatordialog.h"

extern "C"
{
	#include <stdio.h>
	#include "modules/request.h"
	#include "modules/engine.h"
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

	/* Weight Buttons */
	connect (ui->increaseWeightButton, SIGNAL(clicked()), signalMapperWeight, SLOT(map())) ;
	connect (ui->decreaseWeightButton, SIGNAL(clicked()), signalMapperWeight, SLOT(map())) ;

	signalMapperWeight -> setMapping (ui->increaseWeightButton, 10) ;
	signalMapperWeight -> setMapping (ui->decreaseWeightButton, -10) ;

	connect (signalMapperWeight, SIGNAL(mapped(int)), this, SLOT(changeWeight(int))) ;

	/* Digit Buttons */
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

	/*Up Down Buttons */
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

	/* Door Buttons */
    QObject::connect(ui->openDoorButton, SIGNAL(clicked()), this, SLOT(openDoorClicked()));
    QObject::connect(ui->closeDoorButton, SIGNAL(clicked()), this, SLOT(closeDoorClicked()));

	/* Connect system */
    this->elevatorSystem = elevatorSystem;

    // Elevator position
    this->connect(this->elevatorSystem, SIGNAL(elevatorPositionChanged(int)), this, SLOT(changeElevatorPosition(int)));
    // Door position
    this->connect(this->elevatorSystem, SIGNAL(doorPositionChanged(double)), this, SLOT(changeDoorPosition(double)));

    /* Function Buttons */
    QObject::connect(ui->alarmButton, SIGNAL(clicked()), this, SLOT(alarmClicked()));
    QObject::connect(ui->blockDoorButton, SIGNAL(clicked()), this, SLOT(blockDoorClicked()));
    // Current message
    this->connect(this->elevatorSystem, SIGNAL(currentMessageChanged(QString)), this, SLOT(changeCurrentMessage(QString)));

    // Current weight
    this->connect(this->elevatorSystem, SIGNAL(currentWeightChanged(int)), this, SLOT(changeCurrentWeight(int)));

    // current log
    this->connect(this->elevatorSystem, SIGNAL(currentLogChanged(QString)), this, SLOT(changeCurrentLog(QString)));

    // Hide the block object
    this->ui->blockObject->setVisible(false);

    // Hide up of f6 and down of f1
    ui->upButton_6->setVisible(false);
    ui->downButton_1->setVisible(false);
}

ElevatorDialog::~ElevatorDialog()
{
    delete ui;
}


void ElevatorDialog::upClicked(int i) {
 	curReq = sendRequest(REQ_CUP,makeInt(i));
}

void ElevatorDialog::downClicked(int i) {
 	curReq = sendRequest(REQ_CDOWN,makeInt(i));
}

void ElevatorDialog::floor(int i ) {
	curReq = sendRequest(REQ_FLOOR,makeInt(i));
}

void ElevatorDialog::changeWeight(int i) {
	addWeight(1,i);
	curReq = sendRequest(REQ_DOPEN,makeInt(1));
}

void ElevatorDialog::changeElevatorPosition(int position)
{
    QRect geometry = ui->elevatorView->geometry();

    int newY = ElevatorDialog::ElevatorViewY - 7 - 107*(position-20)/20;
    geometry.setY(newY);

    ui->elevatorView->setGeometry(geometry);
}

void ElevatorDialog::changeDoorPosition(double position)
{
    double reversePosition = 1 - position;

    QRect leftDoorGeometry = ui->leftDoor->geometry();
    QRect rightDoorGeometry = ui->rightDoor->geometry();

    leftDoorGeometry.setWidth(81*reversePosition);

    rightDoorGeometry.setX(2*81 - 81*reversePosition);
    rightDoorGeometry.setWidth(81*reversePosition);

    ui->leftDoor->setGeometry(leftDoorGeometry);
    ui->rightDoor->setGeometry(rightDoorGeometry);

    // Enable block door button if door is opening
    // also enable weight buttons
    if (position > 0)
    {
        ui->blockDoorButton->setEnabled(true);
        ui->increaseWeightButton->setEnabled(true);
        ui->decreaseWeightButton->setEnabled(true);
    }
    else
    {
        ui->blockDoorButton->setEnabled(false);
        ui->decreaseWeightButton->setEnabled(false);
        ui->increaseWeightButton->setEnabled(false);
    }
}

void ElevatorDialog::openDoorClicked() {
	curReq = sendRequest(REQ_DOPEN,makeInt(1));
}

void ElevatorDialog::closeDoorClicked() {
	curReq = sendRequest(REQ_DCLOSE,makeInt(1));
}

void ElevatorDialog::alarmClicked() {
	curReq = sendRequest(REQ_ALARM,makeInt(elevator[0]));

    // change alarm button text
    if (ui->alarmButton->text() == "Alarm ON")
    {
        ui->alarmButton->setText("Alarm OFF");
    }
    else
    {
        ui->alarmButton->setText("Alarm ON");
    }
}

void ElevatorDialog::blockDoorClicked() {
    if (blocker[0] == 0)
    {
		blocker[0] = 1;

        // Show the blockObject
        ui->blockObject->setVisible(true);
        ui->blockDoorButton->setText("Unblock door");
    }
	else
    {
		blocker[0] = 0;

        // Hide the blockObject
        ui->blockObject->setVisible(false);
        ui->blockDoorButton->setText("Block door");
    }
}

void ElevatorDialog::changeCurrentMessage(QString message)
{
    ui->floorIndicatorLabel->setText(message);
}

void ElevatorDialog::changeCurrentWeight(int weight)
{
    ui->weightLabel->setText(QString::number(weight));

    if (weight > maxWeight)
    {
        // Warning overload by making weight label red
        ui->weightLabel->setStyleSheet("color:red;");
    }
    else
    {
        ui->weightLabel->setStyleSheet("");
    }
}

void ElevatorDialog::changeCurrentLog(QString log)
{
    ui->logLabel->setText(log);
}
