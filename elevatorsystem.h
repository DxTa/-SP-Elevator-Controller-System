#ifndef ELEVATORSYSTEM_H
#define ELEVATORSYSTEM_H

#include <QObject>
#include <QTime>
#include <QThread>

class ElevatorSystem : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorSystem(QObject *parent = 0);
    void start();
    int tick();
    
signals:
    void valueChanged(int newValue);
    
public slots:
    void reset();

protected:
    void update(int elapsedTime);
    int currentValue;
    QTime time;
    
};

class ElevatorSystemThread : public QThread
{
    Q_OBJECT

public:
    ElevatorSystem *elevatorSystem;

protected:
    void run();
};

#endif // ELEVATORSYSTEM_H
