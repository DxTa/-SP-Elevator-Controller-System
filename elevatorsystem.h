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

private:
    void update(int elapsedTime);

    // Nested class
    class ElevatorSystemThread : public QThread
    {
    public:
        ElevatorSystem *elevatorSystem;

    protected:
        void run();
    };

    // Variable
    int currentValue;
    QTime time;
    ElevatorSystemThread *thread;
    
signals:
    void valueChanged(int newValue);
    
public slots:
    void reset();

protected:
    int tick();
    
};

#endif // ELEVATORSYSTEM_H
