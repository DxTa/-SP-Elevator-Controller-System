#ifndef ELEVATORSYSTEM_H
#define ELEVATORSYSTEM_H

#include <QObject>
#include <QTime>
#include <QThread>
#include <QDebug>

extern "C"
{
	#include "modules/data.h"
	#include "modules/request.h"
	#include "modules/requestor.h"
	#include "modules/actioner.h"
	#include "modules/responder.h"
// include C library here
}


class ElevatorSystem : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorSystem(QObject *parent = 0);
    void start();

private:
    int update(int elapsedTime);

    // Nested class
    class ElevatorSystemThread : public QThread
    {
    public:
        ElevatorSystem *elevatorSystem;

    protected:
        void run();
    };

    // Variable
    QTime time;
    ElevatorSystemThread *thread;

signals:

public slots:

protected:
    int tick();

};

#endif // ELEVATORSYSTEM_H
