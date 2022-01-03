/********************************************************************************
** Form generated from reading UI file 'startingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTINGWINDOW_H
#define UI_STARTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartingWindow
{
public:
    QGroupBox *grpBoxLoading;
    QLabel *lblLoader;
    QLabel *lblTitle;
    QLabel *lblStatus;
    QGroupBox *grpBoxLogin;
    QLabel *lblTitle_3;
    QTextEdit *txtBoxUsername;
    QTextEdit *txtBoxPassword;
    QLabel *lblPassword;
    QLabel *lblUsername;
    QPushButton *btnLogin;

    void setupUi(QWidget *StartingWindow)
    {
        if (StartingWindow->objectName().isEmpty())
            StartingWindow->setObjectName(QString::fromUtf8("StartingWindow"));
        StartingWindow->resize(400, 500);
        StartingWindow->setMinimumSize(QSize(400, 500));
        StartingWindow->setStyleSheet(QString::fromUtf8("background-color: #1e1e1e;"));
        grpBoxLoading = new QGroupBox(StartingWindow);
        grpBoxLoading->setObjectName(QString::fromUtf8("grpBoxLoading"));
        grpBoxLoading->setGeometry(QRect(10, 10, 381, 481));
        grpBoxLoading->setStyleSheet(QString::fromUtf8(""));
        grpBoxLoading->setFlat(true);
        lblLoader = new QLabel(grpBoxLoading);
        lblLoader->setObjectName(QString::fromUtf8("lblLoader"));
        lblLoader->setGeometry(QRect(150, 160, 141, 111));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        lblLoader->setFont(font);
        lblTitle = new QLabel(grpBoxLoading);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(90, 60, 181, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        lblTitle->setFont(font1);
        lblStatus = new QLabel(grpBoxLoading);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(130, 350, 181, 41));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        lblStatus->setFont(font2);
        grpBoxLogin = new QGroupBox(grpBoxLoading);
        grpBoxLogin->setObjectName(QString::fromUtf8("grpBoxLogin"));
        grpBoxLogin->setGeometry(QRect(0, 0, 381, 481));
        grpBoxLogin->setStyleSheet(QString::fromUtf8(""));
        grpBoxLogin->setFlat(true);
        lblTitle_3 = new QLabel(grpBoxLogin);
        lblTitle_3->setObjectName(QString::fromUtf8("lblTitle_3"));
        lblTitle_3->setGeometry(QRect(100, 70, 181, 41));
        lblTitle_3->setFont(font1);
        lblTitle_3->setStyleSheet(QString::fromUtf8("color: white;"));
        txtBoxUsername = new QTextEdit(grpBoxLogin);
        txtBoxUsername->setObjectName(QString::fromUtf8("txtBoxUsername"));
        txtBoxUsername->setGeometry(QRect(100, 170, 171, 31));
        txtBoxUsername->setStyleSheet(QString::fromUtf8("color: white;"));
        txtBoxPassword = new QTextEdit(grpBoxLogin);
        txtBoxPassword->setObjectName(QString::fromUtf8("txtBoxPassword"));
        txtBoxPassword->setGeometry(QRect(100, 230, 171, 31));
        txtBoxPassword->setStyleSheet(QString::fromUtf8("color: white;"));
        lblPassword = new QLabel(grpBoxLogin);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));
        lblPassword->setGeometry(QRect(100, 210, 49, 16));
        lblPassword->setStyleSheet(QString::fromUtf8("color: white;"));
        lblUsername = new QLabel(grpBoxLogin);
        lblUsername->setObjectName(QString::fromUtf8("lblUsername"));
        lblUsername->setGeometry(QRect(100, 150, 61, 16));
        lblUsername->setStyleSheet(QString::fromUtf8("color: white;"));
        btnLogin = new QPushButton(grpBoxLogin);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(100, 290, 80, 24));
        btnLogin->setStyleSheet(QString::fromUtf8("color: white"));
        btnLogin->setFlat(false);

        retranslateUi(StartingWindow);

        QMetaObject::connectSlotsByName(StartingWindow);
    } // setupUi

    void retranslateUi(QWidget *StartingWindow)
    {
        StartingWindow->setWindowTitle(QApplication::translate("StartingWindow", "StartingWindow", nullptr));
        grpBoxLoading->setTitle(QString());
        lblLoader->setText(QString());
        lblTitle->setText(QApplication::translate("StartingWindow", "Chatter 3000", nullptr));
        lblStatus->setText(QApplication::translate("StartingWindow", "Starting...", nullptr));
        grpBoxLogin->setTitle(QString());
        lblTitle_3->setText(QApplication::translate("StartingWindow", "Chatter 3000", nullptr));
        lblPassword->setText(QApplication::translate("StartingWindow", "Password", nullptr));
        lblUsername->setText(QApplication::translate("StartingWindow", "Username", nullptr));
        btnLogin->setText(QApplication::translate("StartingWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartingWindow: public Ui_StartingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTINGWINDOW_H
