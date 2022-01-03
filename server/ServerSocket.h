//
// Created by jolof on 2021-12-28.
//

#ifndef SERVER_SERVERSOCKET_H
#define SERVER_SERVERSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <memory>
#include <iostream>

class ServerSocket : public QObject{
    Q_OBJECT
    Q_DISABLE_COPY(ServerSocket)
public:
    explicit ServerSocket(QObject *parent = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    void sendMsg(const QString &msg);
signals:
    void disconnectedFromClient();
    void messageReceived(ServerSocket* sender, const QString &message);
    void logMessage(const QString &msg);
public slots:
    void disconnectFromClient();
private slots:
    void receiveMessage();

private:
    std::unique_ptr<QTcpSocket> m_serverSocket;
    QString m_username;
};


#endif //SERVER_SERVERSOCKET_H
