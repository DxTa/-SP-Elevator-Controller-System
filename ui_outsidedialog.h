/********************************************************************************
** Form generated from reading UI file 'outsidedialog.ui'
**
** Created: Fri Nov 16 16:09:32 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTSIDEDIALOG_H
#define UI_OUTSIDEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutsideDialog
{
public:
    QPushButton *stepInsideButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *upButton;
    QPushButton *downButton;

    void setupUi(QDialog *OutsideDialog)
    {
        if (OutsideDialog->objectName().isEmpty())
            OutsideDialog->setObjectName(QString::fromUtf8("OutsideDialog"));
        OutsideDialog->resize(400, 300);
        stepInsideButton = new QPushButton(OutsideDialog);
        stepInsideButton->setObjectName(QString::fromUtf8("stepInsideButton"));
        stepInsideButton->setGeometry(QRect(80, 240, 181, 32));
        widget = new QWidget(OutsideDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 110, 114, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        upButton = new QPushButton(widget);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        verticalLayout->addWidget(upButton);

        downButton = new QPushButton(widget);
        downButton->setObjectName(QString::fromUtf8("downButton"));

        verticalLayout->addWidget(downButton);


        retranslateUi(OutsideDialog);

        QMetaObject::connectSlotsByName(OutsideDialog);
    } // setupUi

    void retranslateUi(QDialog *OutsideDialog)
    {
        OutsideDialog->setWindowTitle(QApplication::translate("OutsideDialog", "Outside", 0, QApplication::UnicodeUTF8));
        stepInsideButton->setText(QApplication::translate("OutsideDialog", "Step inside elevator", 0, QApplication::UnicodeUTF8));
        upButton->setText(QApplication::translate("OutsideDialog", "Up", 0, QApplication::UnicodeUTF8));
        downButton->setText(QApplication::translate("OutsideDialog", "Down", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OutsideDialog: public Ui_OutsideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTSIDEDIALOG_H
