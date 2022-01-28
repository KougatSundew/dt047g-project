//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// ServerSocket.h, 2021-12-2 - 2021-01-10
// Contains the header definitions
//

//
// Created by jolof on 2021-12-2 8.
//

#ifndef SERVER_SERVERSOCKET_H
#define SERVER_SERVERSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <memory>
#include <iostream>
#include <QDataStream>
#include "datatypes/AbstractData.h"
#include "datatypes/Message.h"

class ServerSocket : public QObject{
    Q_OBJECT
    Q_DISABLE_COPY(ServerSocket)
public:
    explicit ServerSocket(QObject *parent = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    void write(const AbstractData &data);
signals:
    void disconnectedFromClient();
    void messageReceived(ServerSocket* senderSocket, QDataStream &stream);
    void logMessage(const QString &msg);
    void authReceived(ServerSocket *socket, QDataStream &stream);
public slots:
    void disconnectFromClient();
private slots:
    void receiveMessage();

private:
    std::unique_ptr<QTcpSocket> m_serverSocket;
};


#endif //SERVER_SERVERSOCKET_H