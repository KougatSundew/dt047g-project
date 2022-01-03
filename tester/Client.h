//
// Created by jolof on 2021-12-21.
//

#ifndef TESTER_CLIENT_H
#define TESTER_CLIENT_H


#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>

class Client : public QObject {
    QHostAddress m_ip;
    QTcpSocket* m_clientSocket;
    bool m_loggedIn;

    void jsonReceived(const QJsonObject &doc);
private slots:
    void onReadyRead();
signals:
    void messageReceived(const QString& sender, const QString &text);
public:
    Client(QHostAddress ip);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void sendMessage(const QString &text);
    void disconnectFromServer();
    void login(const QString &userName);

};


#endif //TESTER_CLIENT_H
