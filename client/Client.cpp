
//
// Created by jolof on 2021-12-29.
//

#include "Client.h"
/**
 * Default constructor
 * @param parent - QObject parent for signals & slots
 * @param ip - type of QHostAddress that contains the IP to the server
 * @param port - type of int that contains port number
 */
Client::Client(QObject *parent, QHostAddress ip, int port): QObject(parent), m_ip(ip), m_port(port) {
    m_clientSocket = std::make_unique<QTcpSocket>(this);

    connect(m_clientSocket.get(), &QTcpSocket::connected, this, [this]() { emit connected(); m_connected = true;});
    connect(m_clientSocket.get(), &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(m_clientSocket.get(), &QTcpSocket::disconnected, this, [this](){ emit disconnected(); m_connected = false;});
}
/**
 * Function that handles when the socket is ready for incomming data
 */
void Client::onReadyRead() {
    QByteArray datagram;
    datagram.reserve(m_clientSocket->bytesAvailable());
    datagram = m_clientSocket->readAll();

    QDataStream readStream(&datagram, QIODevice::ReadOnly);

    qint16 sizeRead;
    short int type;
    readStream >> sizeRead;

    //if(m_clientSocket->bytesAvailable() < sizeRead) return; TODO: check if the data is 0
    readStream >> type;
    if(type == DataType::Message) {
        emit messageReceived(readStream);
    }
    if(type == DataType::AuthResponse) {
        emit authReceived(readStream);
    }
    if(type == DataType::FriendList) {
        emit friendListReceived(readStream);
    }
}
/**
 * Function for connecting to server with IP and port
 * @param address - QHostAddress with IP
 * @param port - int with port
 */
void Client::connectToServer(const QHostAddress &address, int port) {
    m_clientSocket->connectToHost(address, port);
}
/**
 * Function for connecting to server with use of member m_ip and m_port
 */
void Client::connectToServer() {
    m_clientSocket->connectToHost(m_ip, m_port);
}
/**
 * Function for disconnecting the socket
 */
void Client::disconnectFromServer() {
    m_clientSocket->disconnectFromHost();
}
/**
 * Function that Aborts the current connection and resets the socket
 */
void Client::abort() {
    m_clientSocket->abort();
}
/**
 * Function for sending data with AbstractData
 * @param data - type of AbstractData
 */
void Client::write(const AbstractData &data) {
    short int type = data.type();
    QByteArray datagram;
    QDataStream writeStream(&datagram, QIODevice::WriteOnly);

    writeStream.setVersion(QDataStream::Qt_5_12);
    writeStream.startTransaction();

    writeStream << quint16(0) << type;
    writeStream << data;
    writeStream.device()->seek(0);
    writeStream << qint16(datagram.size() - sizeof(qint16)); // writing data size
    m_clientSocket->write(datagram);
    m_clientSocket->waitForBytesWritten();
}
/**
 * Function for checking the connection
 * @return - returns boolean that can be true or false
 */
bool Client::isSocketConnected() {
    return m_connected;
}
