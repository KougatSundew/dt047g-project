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
    Q_DISABLE_COPY(StartingWindow)
public:
    explicit StartingWindow(QWidget *parent = nullptr);
    ~StartingWindow() override;

    void switchToLogin();
    void switchToLoading();

    void setLoginStatus(const QString &status);
    void setSocketConnStatus(const QString &status);
signals:
    void loginButtonPressed(QString username, QString password);
private:
    Ui::StartingWindow *ui;
    QMovie *loadAnimation;
private slots:
    void attemptConnection();
    void connectedToServer();
    void disconnectedFromServer();
    void onLoginBtnPress();
};


#endif //CLIENT_STARTINGWINDOW_H
