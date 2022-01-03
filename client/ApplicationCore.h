//
// Created by jolof on 2021-12-29.
//

#ifndef CLIENT_APPLICATIONCORE_H
#define CLIENT_APPLICATIONCORE_H

#include <QTimer>
#include <memory>
#include "Client.h"
#include "ui-components/startingwindow.h"

enum TimeOut {
    SocketConnect = 10000,
    Login = 3000,
};

class ApplicationCore : public QObject {
    Q_OBJECT
public:
    explicit ApplicationCore(QObject *parent = nullptr);
private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onConnectionTimeOut();
    void onSocketReadyRead();
    void onMessageSent();

    void onLoginBtnPressed(QString username, QString password);
private:
    void connectSocketSignals();
    void socketRetryConnection();
    int connectionRetryAttempts = 0;
    int maxConnectionRetryAttempts = 5;

    std::unique_ptr<QTimer> m_timer;
    std::unique_ptr<Client> m_client;
    std::unique_ptr<StartingWindow> m_start;
};


#endif //CLIENT_APPLICATIONCORE_H
