//
// Created by jolof on 2021-12-29.
//

#include "ApplicationCore.h"
//TODO: Fix function orders and doxygen documentation
ApplicationCore::ApplicationCore(QObject *parent)
    : QObject(parent),
    m_client(std::make_unique<Client>(this, QHostAddress("192.168.1.8"), 4040)),
    m_start(std::make_unique<StartingWindow>()),
    m_timer(std::make_unique<QTimer>(this)) {

    m_start->show();
    connectSocketSignals();
    connect(m_timer.get(), &QTimer::timeout, this, &ApplicationCore::onConnectionTimeOut);
    connect(m_start.get(), &StartingWindow::loginButtonPressed, this, &ApplicationCore::onLoginBtnPressed);
    m_client->connectToServer();

    m_timer->start(TimeOut::SocketConnect);
}

void ApplicationCore::onSocketConnected() {
    m_timer->stop();
    std::cout << "Socket connected" << "\n";
    m_client->sendMessage("[STATUS][CONNECTED]");
    m_start->switchToLogin();
}

void ApplicationCore::onSocketDisconnected() {

}

void ApplicationCore::onConnectionTimeOut() {
    if(connectionRetryAttempts != maxConnectionRetryAttempts) {
        std::cerr << "[LOG] STATUS: connection timeout" << "\n";
        socketRetryConnection();
    } else {
        m_start->setSocketConnStatus("connection to server failed");
    }
}

void ApplicationCore::onSocketReadyRead() {
    m_client->sendMessage("Hello");
}

void ApplicationCore::onMessageSent() {

}

void ApplicationCore::connectSocketSignals() {
    connect(m_client.get(), &Client::connected, this, &ApplicationCore::onSocketConnected);
    //connect(m_client.get(), &Client::connected, this, &ApplicationCore::onSocketConnected);
    connect(m_client.get(), &Client::messageReceived, this, &ApplicationCore::onSocketReadyRead);
}

void ApplicationCore::onLoginBtnPressed(QString username, QString password) {
    std::cout << "LOGIN" << username.toStdString() << ", " << password.toStdString() << "\n";
}

void ApplicationCore::socketRetryConnection() {
    connectionRetryAttempts++;
    QString status = "Retrying connection.. (attempt " + QString::number(connectionRetryAttempts) + "/5)";
    m_start->setSocketConnStatus(status);
    m_client->connectToServer();
}
