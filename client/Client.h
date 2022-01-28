//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// Client.h, 2021-12-29 - 2021-01-11
// Contains the header definitions
//

//
// Created by jolof on 2021-12-29.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H


#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>
#include <memory>
#include "data/AbstractData.h"
#include "data/Message.h"
#include "data/User.h"
#include "data/AuthAnswer.h"

class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, QHostAddress ip = QHostAddress::Null, int port = 0);

    void abort();
    bool isSocketConnected();
private slots:
    void onReadyRead();
signals:
    void disconnected();
    void connected();
    void messageReceived(QDataStream &stream);
    void authReceived(QDataStream &stream);
    void friendListReceived(QDataStream &stream);
public slots:
    void connectToServer(const QHostAddress &address, int port);
    void connectToServer();
    void write(const AbstractData &data);
    void disconnectFromServer();
private:
    QHostAddress m_ip; int m_port;
    std::unique_ptr<QTcpSocket> m_clientSocket;
    bool m_connected;
};


#endif //CLIENT_CLIENT_H
