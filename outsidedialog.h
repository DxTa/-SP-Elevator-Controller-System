#ifndef OUTSIDEDIALOG_H
#define OUTSIDEDIALOG_H

#include <QDialog>

namespace Ui {
class OutsideDialog;
}

class OutsideDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OutsideDialog(QWidget *parent = 0);
    ~OutsideDialog();

public slots:
    void upClicked();
    void downClicked();
    void stepInsideClicked();
    
private:
    Ui::OutsideDialog *ui;
};

#endif // OUTSIDEDIALOG_H
