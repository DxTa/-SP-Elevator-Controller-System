#ifndef INSIDEDIALOG_H
#define INSIDEDIALOG_H

#include <QDialog>

namespace Ui {
class InsideDialog;
}

class InsideDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsideDialog(QWidget *parent = 0);
    ~InsideDialog();
    
private:
    Ui::InsideDialog *ui;
};

#endif // INSIDEDIALOG_H
