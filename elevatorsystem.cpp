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
    this->currentValue = 0;

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
    // update the time
    int elapsed = this->time.elapsed();
    this->time.restart();

    this->update(elapsed);

    return 0;
}

void ElevatorSystem::update(int elapsedTime)
{
    this->currentValue += elapsedTime;
    this->valueChanged(this->currentValue);
}

void ElevatorSystem::reset()
{
    this->currentValue = 0;
}
