//
// Created by jolof on 2021-12-28.
//

#include "ServerSocket.h"

ServerSocket::ServerSocket(QObject *parent) : QObject(parent), m_serverSocket(std::make_unique<QTcpSocket>(new QTcpSocket(this))) {
    //connect readyRead() to the slot that will take care of reading the data in
    connect(m_serverSocket.get(), &QTcpSocket::readyRead, this, &ServerSocket::receiveMessage);
    connect(m_serverSocket.get(), &QTcpSocket::disconnected, this, &ServerSocket::disconnectedFromClient);
}

bool ServerSocket::setSocketDescriptor(qintptr socketDescriptor) {
    return m_serverSocket.get()->setSocketDescriptor(socketDescriptor);
}

void ServerSocket::disconnectFromClient() {
    m_serverSocket.get()->disconnectFromHost();
}

void ServerSocket::receiveMessage() {
    QString message = m_serverSocket->readLine();
    emit logMessage(message);
    emit messageReceived(this, message);
}

void ServerSocket::sendMsg(const QString &msg) {
    emit logMessage("Sent message");

    m_serverSocket.get()->write(msg.toUtf8());
}

