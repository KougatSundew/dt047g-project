//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// startingwindow.h, 2021-12-29 - 2021-01-11
//

//
// Created by jolof on 2021-12-29.
//

#ifndef CLIENT_STARTINGWINDOW_H
#define CLIENT_STARTINGWINDOW_H

#include <QWidget>
#include "../Client.h"


QT_BEGIN_NAMESPACE
namespace Ui { class StartingWindow; }
QT_END_NAMESPACE

class StartingWindow : public QWidget {
    Q_OBJECT
    //Makes is so that this object cant be copied
    Q_DISABLE_COPY(StartingWindow)
public:
    explicit StartingWindow(QWidget *parent = nullptr);

    ~StartingWindow() override;

    void switchToLogin();
    void switchToLoading();

    void setLoginStatus(const QString &status);
    void setSocketConnStatus(const QString &status);

    void resetLoginStatus();
signals:
    void loginButtonPressed(QString username, QString password);
private slots:
    void onLoginBtnPress();
private:
    void initLoadAnimation();
    void setStyleSettings();

    Ui::StartingWindow *ui;
    std::unique_ptr<QMovie> loadAnimation;

};


#endif //CLIENT_STARTINGWINDOW_H
