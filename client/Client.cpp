//
// Created by jolof on 2021-12-29.
//

#include "Client.h"

Client::Client(QObject *parent, QHostAddress ip, int port): QObject(parent), m_ip(ip), m_port(port), m_loggedIn(false) {
    m_clientSocket = new QTcpSocket(this); //TODO: Change to unique_ptr for RAII
    //TODO: fix socket exception
    //connect(m_clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
    //connect(m_clientSocket, &QTcpSocket::connected, this, &Client::connectToServer);
    connect(m_clientSocket, &QTcpSocket::connected, this, &Client::connected);
    connect(m_clientSocket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, [this](){m_loggedIn = false;});
}

void Client::onReadyRead() {
    std::cout << "Message from server received" << "\n";
    QString message = m_clientSocket->readLine();
    std::cout << "Server: " << message.toStdString() << "\n";
}

void Client::connectToServer(const QHostAddress &address, quint16 port) {
    m_clientSocket->connectToHost(address, port);
}

void Client::connectToServer() {
    m_clientSocket->connectToHost(m_ip, m_port);
}

void Client::sendMessage(const char *text) {
    //if(text != nullptr) return; //Exception for empty text //TODO: fix exception for when message is empty
    m_clientSocket->write(text);
}

void Client::disconnectFromServer() {
    m_clientSocket->disconnectFromHost();
}

void Client::login(const QString &userName) {

}

