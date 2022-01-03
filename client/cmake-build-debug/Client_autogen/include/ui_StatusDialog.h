/********************************************************************************
** Form generated from reading UI file 'statusdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSDIALOG_H
#define UI_STATUSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_StatusDialog
{
public:

    void setupUi(QDialog *StatusDialog)
    {
        if (StatusDialog->objectName().isEmpty())
            StatusDialog->setObjectName(QString::fromUtf8("StatusDialog"));
        StatusDialog->resize(400, 300);

        retranslateUi(StatusDialog);

        QMetaObject::connectSlotsByName(StatusDialog);
    } // setupUi

    void retranslateUi(QDialog *StatusDialog)
    {
        StatusDialog->setWindowTitle(QApplication::translate("StatusDialog", "StatusDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatusDialog: public Ui_StatusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSDIALOG_H
