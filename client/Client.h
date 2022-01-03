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

class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, QHostAddress ip = QHostAddress::Null, int port = 0);
private slots:
    void onReadyRead();
signals:
    void connected();
    void messageReceived(const QString& sender, const QString &text);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void connectToServer();
    void sendMessage(const char *text);
    void disconnectFromServer();
    void login(const QString &userName);
private:
    QHostAddress m_ip; int m_port;
    QTcpSocket* m_clientSocket;
    bool m_loggedIn;
};


#endif //CLIENT_CLIENT_H
