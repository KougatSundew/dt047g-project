//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// ApplicationCore.h, 2021-12-29 - 2021-01-10
// Denna fil håller hand om hela applikationen, signal hantering och data hantering
//

//
// Created by jolof on 2021-12-29.
//

#ifndef CLIENT_APPLICATIONCORE_H
#define CLIENT_APPLICATIONCORE_H

#include <QCoreApplication>
#include <QTimer>
#include <memory>
#include "Client.h"
#include "ui-components/startingwindow.h"
#include "ui-components/mainapplicationwindow.h"
#include "ui-components/statusdialog.h"
#include "data/User.h"
#include "data/Message.h"
#include "data/AuthAnswer.h"
#include "data/FriendList.h"


class ApplicationCore : public QObject {
    Q_OBJECT
public:
    explicit ApplicationCore(QObject *parent = nullptr);

    static int const EXIT_CODE_REBOOT = -1;
    static int const EXIT_CODE_QUIT = -2;
private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onConnectionTimeOut();
    void onMessageReceived(QDataStream &stream);
    void onAuthMessageReceived(QDataStream &stream);
    void onFriendListReceived(QDataStream &stream);

    void onLoginBtnPressed(QString username, QString password);
    void onSendMessage(QString receiver, QString message);
    void onDialogRetry(bool retry);
private:
    void login();
    void connectSocketSignals();
    void connectSignals();
    void socketRetryConnection();

    int connectionRetryAttempts = 0;

    //Timeout time 10seconds
    const int SOCKETCONNECTTIME = 10000;
    const int maxConnectionRetryAttempts = 5;

    std::unique_ptr<QTimer> m_timer;
    std::unique_ptr<Client> m_client;
    std::unique_ptr<StartingWindow> m_start;
    std::unique_ptr<MainApplicationWindow> m_mainWindow;
    std::unique_ptr<StatusDialog> m_retryDialogWindow;

    std::shared_ptr<class FriendList> friends;
    User userdata;
};


#endif //CLIENT_APPLICATIONCORE_H
