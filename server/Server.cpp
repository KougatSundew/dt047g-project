//
// Created by jolof on 2021-12-21.
//

#include "Server.h"

/**
 * Default constructor
 * @param parent - pointer to QObject, defaults to nullptr
 */
Server::Server(QObject *parent): QTcpServer(parent) {
    DataReader dataReader;
    usersRegistered = dataReader.getRegisteredUsers();
    friendLists = dataReader.getFriendLists();
}
/**
 * Function for handling an incommingconnection
 * @param socketDescriptor - socketDescriptor
 */
void Server::incomingConnection(qintptr socketDescriptor) {
    std::shared_ptr<ServerSocket> socket = std::make_shared<ServerSocket>(this);
    // we attempt to bind the clientSocket to the client
    if(!socket->setSocketDescriptor(socketDescriptor)) {
        socket->deleteLater();
        return;
    }
    //Connect signals coming from the ServerSocket
    connect(socket.get(), &ServerSocket::disconnectedFromClient, this, [this, socket] { clientDisconnected(socket.get()); });
    connect(socket.get(), &ServerSocket::messageReceived, this, &Server::messageReceived);
    connect(socket.get(), &ServerSocket::logMessage, this, &Server::logMessage);
    connect(socket.get(), &ServerSocket::authReceived, this, &Server::authMessageReceived);
    // We log the event
    logMessage("New client connected");
}
/**
 * Function for handling if an client/user disconnects from the server,
 * gets called when ServerSocket::disconnectedFromClient signal is emitted
 * @param sender - pointer to ServerSocket object of the sender
 */
void Server::clientDisconnected(ServerSocket *sender) {
    logMessage("client disconnected");
    auto user = clients.key(sender);

    std::cout << "Deleting socket for user: " << user.getUsername().toStdString() << "\n";
    clients.remove(user);
    std::cout << "Number of serversockets " << clients.size() << "\n";
}
/**
 * Function for handling private messages received of DataType Message,
 * this function gets called when the ServerSocket::messageReceived signal is emited
 * @param senderSocket - Ptr to ServerSocket object of the sender
 * @param stream - Reference to QDataStream, which contains the data to be read
 */
void Server::messageReceived(ServerSocket *senderSocket, QDataStream &stream) {
    class Message message;
    stream >> message;

    DataPrinter::save(message, "N:\\GitHub\\dt047g-project\\server\\data\\usermessages.txt");

    //TODO take out the code and make it to an function instead, because of DRY (Don't Repeat Yourself)
    class FriendList listFriend = friendLists.value(message.getSender());
    listFriend.addMessage(message.getReceiver(), message);
    friendLists[message.getSender()] = listFriend;
    class FriendList receivers = friendLists[message.getReceiver()];
    receivers.addMessage(message.getSender(), message);
    friendLists[message.getReceiver()] = receivers;

    //Finding the socket to send the private message to
    for(auto user : clients.values()) {
        if(clients.key(user).getUsername() != message.getSender() && clients.key(user).getUsername() == message.getReceiver())
            user->write(message);
    }
    logMessage(message.getSender() + ", " + message.getReceiver() + ", " +message.getMessage());
}
/**
 * Function for logging text in the console
 * @param msg - QString
 */
void Server::logMessage(const QString &msg) {
    std::cout << "status: "<< msg.toStdString() << "\n";
}
/**
 * Function for handling Authentication message of DataType AuthRequest
 * this function gets called when the ServerSocket::authReceived signal is emited
 * @param socket - pointer to an ServerSocket, which is the sender of the message
 * @param readStream - reference of type QDataStream which contains the data to be read
 */
void Server::authMessageReceived(ServerSocket *socket, QDataStream &readStream) {
    User userdata;
    readStream >> userdata;

    logMessage("User that is logging in " + userdata.getUsername());
    AuthAnswer auth;
    if(userExists(userdata)) {
        auth.setSigned(true);
        socket->write(auth);
        socket->write(friendLists.value(userdata.getUsername()));

        userdata.setType(DataType::ONLINE);

        clients.insert(userdata, socket);
        logMessage("Number of serversockets " + clients.size());
    } else {
        auth.setSigned(false);
        socket->write(auth);
    }
}

/**
 * Function for checking if an user exists in the server data
 * @param userdata - an User object containing user details
 * @return - returns an boolean which can be true or false, dependent on if a user exists
 */
bool Server::userExists(User userdata) {
    //Using the std find_if to iterate through the usersRegistered map, with lambda it checks if there exists a user with a username & password registered
    auto exists = std::find_if(usersRegistered.begin(), usersRegistered.end(), [userdata](const std::pair<QString, User> & registeredUser) {
        return registeredUser.second.getUsername() == userdata.getUsername() && registeredUser.second.getPassword() == userdata.getPassword();
    });
    return exists != usersRegistered.end();
}