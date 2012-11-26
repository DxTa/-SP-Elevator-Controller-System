#ifndef ELEVATORDIALOG_H
#define ELEVATORDIALOG_H

#include <QDialog>

namespace Ui {
class ElevatorDialog;
}

class ElevatorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ElevatorDialog(QWidget *parent = 0);
    ~ElevatorDialog();
    
private:
    Ui::ElevatorDialog *ui;
};

#endif // ELEVATORDIALOG_H
