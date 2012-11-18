#include "insidedialog.h"
#include "ui_insidedialog.h"

InsideDialog::InsideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsideDialog)
{
    ui->setupUi(this);
}

InsideDialog::~InsideDialog()
{
    delete ui;
}
