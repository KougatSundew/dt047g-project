//
// Created by jolof on 2021-12-28.
//

#include "ServerSocket.h"
/**
 * Constructor
 * @param parent - QObject parent for signals / slots
 */
ServerSocket::ServerSocket(QObject *parent) : QObject(parent), m_serverSocket(std::make_unique<QTcpSocket>(this)) {
    //connect readyRead() to the slot that will take care of reading the data in
    connect(m_serverSocket.get(), &QTcpSocket::readyRead, this, &ServerSocket::receiveMessage);
    connect(m_serverSocket.get(), &QTcpSocket::disconnected, this, &ServerSocket::disconnectedFromClient);
}
/**
 * Function for setting the socketdescriptor
 * @param socketDescriptor - type qintptr socketdescriptor
 * @return - returns the socketdescriptor of the socket
 */
bool ServerSocket::setSocketDescriptor(qintptr socketDescriptor) {
    return m_serverSocket.get()->setSocketDescriptor(socketDescriptor);
}
/**
 * Function for disconnecting the socket
 */
void ServerSocket::disconnectFromClient() {
    m_serverSocket.get()->disconnectFromHost();
}
/**
 * Function that parses the incomming data
 */
void ServerSocket::receiveMessage() {
    QDataStream readStream(m_serverSocket.get());
    qint16 sizeRead;
    short int type;
    readStream >> sizeRead;

    if(m_serverSocket->bytesAvailable() < sizeRead) return;
    readStream >> type;
    if(type == DataType::Message) {
        emit messageReceived(this, readStream);
    }
    if(type == DataType::AuthRequest) {
        emit authReceived(this, readStream);
    }
}
/**
 * Function for sending data to socket
 * @param data - const reference AbstractData
 */
void ServerSocket::write(const AbstractData &data) {
    short int type = data.type();

    QByteArray datagram;
    QDataStream writeStream(&datagram, QIODevice::WriteOnly);
    writeStream.setVersion(QDataStream::Qt_5_12);
    writeStream.startTransaction();
    writeStream << quint16(0) << type;
    writeStream << data;
    writeStream.device()->seek(0);
    writeStream << qint16(datagram.size() - sizeof(qint16)); // writing data size
    m_serverSocket->write(datagram);
    m_serverSocket->waitForBytesWritten();
}

