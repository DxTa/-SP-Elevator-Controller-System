#include "elevatorsystem.h"

ElevatorSystem::ElevatorSystem(QObject *parent) :
    QObject(parent)
{
    this->thread = new ElevatorSystemThread();
    this->thread->elevatorSystem = this;
}

void ElevatorSystem::start()
{
    this->time.start();

    this->thread->start();
}

void ElevatorSystem::ElevatorSystemThread::run()
{
    while (1)
    {
        if (this->elevatorSystem->tick() != 0) break;

        // 60fps
        this->msleep(1000/60);
    }
}

int ElevatorSystem::tick()
{
    // Get the time between frame
    int elapsed = this->time.elapsed();
    this->time.restart();

    if (this->update(elapsed) != 0)
    {
        return 1;
    }

    this->draw();
    return 0;
}

int ElevatorSystem::update(int elapsedTime)
{
    // Update your system here
    if(curResp) {
        curAct = executeRespond(curResp);
        curResp = executeAction(curAct);
        curAct = NULL;
    } else
        curResp = executeAction(curAct);


    //Uu tien Respond

    if(curReq) {
        curAct = executeRequest(curReq);
        if(curAct != NULL)
            qDebug() << "\n-----------\n";
        curResp = executeAction(curAct);
        curReq = NULL;
        curAct = NULL;
    }

    return 0;
}

void ElevatorSystem::draw()
{
    if (this->currentElevatorPosition != elevator[0])
    {
        this->currentElevatorPosition = elevator[0];
        this->elevatorPositionChanged(this->currentElevatorPosition);
    }

    if (this->currentDoorPosition != eleDoor[0])
    {
        this->currentDoorPosition = eleDoor[0];
        this->doorPositionChanged(this->currentDoorPosition);
    }
}
