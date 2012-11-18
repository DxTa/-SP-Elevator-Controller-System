#ifndef OUTSIDEDIALOG_H
#define OUTSIDEDIALOG_H

#include <QDialog>

#include "elevatorsystem.h"

namespace Ui {
class OutsideDialog;
}

class OutsideDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutsideDialog(QWidget *parent = 0, ElevatorSystem *elevatorSystem = NULL);
    ~OutsideDialog();

public slots:
    void upClicked();
    void downClicked();
    void stepInsideClicked();
    void valueChanged(int newValue);

private:
    Ui::OutsideDialog *ui;
    ElevatorSystem *elevatorSystem;
};

#endif // OUTSIDEDIALOG_H
