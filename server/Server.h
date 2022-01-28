//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// ServerSocket.h, 2021-12-21 - 2022-01-10
// Contains the header definitions
//

//
// Created by jolof on 2021-12-21.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <memory>
#include "ServerSocket.h"
#include "datatypes/AuthAnswer.h"
#include "datatypes/Message.h"
#include "datatypes/User.h"
#include "data/DataReader.h"
#include "datatypes/FriendList.h"
#include "data/DataPrinter.h"

class Server : public QTcpServer {
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void logMessage(const QString &msg);
public slots:
    void incomingConnection(qintptr socketDescriptor) override;
private slots:
    void clientDisconnected(ServerSocket *sender);
    void messageReceived(ServerSocket *senderSocket, QDataStream &stream);
    void authMessageReceived(ServerSocket *socket, QDataStream &stream);
private:
    bool userExists(User userdata);

    QMap<User, ServerSocket*> clients;
    std::map<QString, User> usersRegistered;
    QMap<QString, class FriendList> friendLists;
};


#endif //SERVER_SERVER_H
