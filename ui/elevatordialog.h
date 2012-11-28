#ifndef ELEVATORDIALOG_H
#define ELEVATORDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSignalMapper>
#include <QFrame>

#include "elevatorsystem.h"

namespace Ui {
class ElevatorDialog;
}

class ElevatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ElevatorDialog(QWidget *parent = 0,ElevatorSystem *elevatorSystem = NULL);
    ~ElevatorDialog();

public slots:
    void upClicked(int);
    void downClicked(int);
	void floor(int );
	void changeWeight(int );
    void changeElevatorPosition(int position);
    void changeDoorPosition(double position);
	void openDoorClicked();
	void closeDoorClicked();
	void alarmClicked();
	void blockDoorClicked();
	void freeFallClicked();
    void changeCurrentMessage(QString message);
    void changeCurrentWeight(int weight);

private:
    Ui::ElevatorDialog *ui;
    ElevatorSystem *elevatorSystem;
    static int ElevatorViewY;
};

#endif // ELEVATORDIALOG_H
