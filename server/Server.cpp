//
// Created by jolof on 2021-12-21.
//

#include "Server.h"
Server::Server(QObject *parent): QTcpServer(parent) {}

void Server::incomingConnection(qintptr socketDescriptor) {
    //QTcpSocket *testSocket = server->nextPendingConnection();
    //TODO: make socket RAII with unique_ptr
    ServerSocket *socket = new ServerSocket(this);
    // we attempt to bind the clientSocket to the client
    if(!socket->setSocketDescriptor(socketDescriptor)) {
        socket->deleteLater();
        return;
    }
    //Connect signals coming form the socket object
    connect(socket, &ServerSocket::disconnectedFromClient, this, [this, socket] { clientDisconnected(socket); });
    connect(socket, &ServerSocket::messageReceived, this, &Server::messageReceived);
    connect(socket, &ServerSocket::logMessage, this, &Server::logMessage);
    //Add the new socket to a list of all the objects that communicate to a single client
    clients.push_back(socket);
    // We log the event
    logMessage(QString("New client connected"));
    socket->sendMsg(QString("Connection successful"));


    //OLD
    /* socket->write("Hello client Vincent!\n");
     socket->flush();

     socket->waitForBytesWritten(3000);

     while(socket->canReadLine()) {
         QString line = QString::fromUtf8(socket->readLine()).trimmed();
         std::cout << "Read line: " << line.toStdString();
     }
     socket->close();*/
}

void Server::readyRead() {
    /*QTcpSocket *client = (QTcpSocket*) sender();
    std::cout << client->readLine().toStdString() << "\n";*/
}

void Server::disconnected()
{
    /*QTcpSocket *client = (QTcpSocket*)sender();
    std::cout << "Client disconnected:" << client->peerAddress().toString().toStdString();

    std::remove(clients.begin(), clients.end(), client);*/
}

void Server::clientDisconnected(ServerSocket *sender) {
    logMessage("client disconnected");
}

void Server::messageReceived(ServerSocket *sender, const QString &msg) {
    logMessage("Message received");
}

void Server::logMessage(const QString &msg) {
    std::cout << "status: "<< msg.toStdString() << "\n";
}

/*Server::Server(QObject *parent): QObject(parent) {
    server = std::make_unique<QTcpServer>(new QTcpServer(this));
    connect(server.get(), SIGNAL(incomingConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress("192.168.1.8"), 4040)) {
        std::cerr << "Server could not start" << "\n";
    } else {
        std::cout << "Server started!" << "\n";
    }
}

void Server::newConnection(qintptr socketDescriptor) {
    //QTcpSocket *testSocket = server->nextPendingConnection();
    ServerSocket *socket = new ServerSocket(this);
    std::cout << "Client connected!" << "\n";
    // we attempt to bind the clientSocket to the client
    if(!socket->setSocketDescriptor(socketDescriptor)) {
        socket->deleteLater();
        return;
    }
    //Connect signals coming form the socket object
    connect(socket, &ServerSocket::disconnectedFromClient, this, [this, socket] { clientDisconnected(socket); });
    connect(socket, &ServerSocket::messageReceived, this, std::bind(&Server::messageReceived, this, socket, std::placeholders::_1));
    connect(socket, &ServerSocket::logMessage, this, &Server::logMessage);
    //Add the new socket to a list of all the objects that communicate to a single client
    clients.push_back(socket);
    // We log the event
    emit logMessage(QString("New client connected"));


    //OLD
   socket->write("Hello client Vincent!\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    while(socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        std::cout << "Read line: " << line.toStdString();
    }
    socket->close();
}

void Server::readyRead() {
    QTcpSocket *client = (QTcpSocket*) sender();
    std::cout << client->readLine().toStdString() << "\n";
}

void Server::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    std::cout << "Client disconnected:" << client->peerAddress().toString().toStdString();

    std::remove(clients.begin(), clients.end(), client);
}

void Server::clientDisconnected(ServerSocket *sender) {

}

void Server::messageReceived(ServerSocket *sender, const QString &msg) {
    emit logMessage("Message received");
}*/

