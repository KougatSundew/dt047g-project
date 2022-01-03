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


/*class Server : public QObject {
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
signals:
    void logMessage(const QString &msg);
public slots:
    void readyRead();
    void disconnected();
    void newConnection(qintptr socketDescriptor);

private slots:
    void clientDisconnected(ServerSocket *sender);
    void messageReceived(ServerSocket *sender, const QString &msg);
private:
    std::vector<ServerSocket*> clients;
    std::unique_ptr<QTcpServer> server;
};*/

class Server : public QTcpServer {
Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void logMessage(const QString &msg);
public slots:
    void readyRead();
    void disconnected();
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void clientDisconnected(ServerSocket *sender);
    void messageReceived(ServerSocket *sender, const QString &msg);
private:
    std::vector<ServerSocket*> clients;
};


#endif //SERVER_SERVER_H
