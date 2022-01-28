//
// Created by jolof on 2022-01-06.
//


#include "DataReader.h"


DataReader::DataReader():
    fileRegisteredUsers("N:\\GitHub\\miun\\dt047g-project\\server\\data\\registered.txt"),
    fileFriends("N:\\GitHub\\miun\\dt047g-project\\server\\data\\friends.txt"),
    fileUserMessages("N:\\GitHub\\miun\\dt047g-project\\server\\data\\usermessages.txt") {
    //Reads in all data that is necessary for the server
    loadRegisteredUsers();
    loadMessages();
    loadFriendLists();
}


void DataReader::loadRegisteredUsers() {
    if(fileRegisteredUsers.open(QIODevice::ReadOnly)) {
        QTextStream reader(&fileRegisteredUsers);
        while (!reader.atEnd()) {
            QString username;
            QString password;
            reader >> username >> password;
            User userdata(username, password);
            registeredUsers.insert(std::make_pair(userdata.getUsername(), userdata));
        }
        fileRegisteredUsers.close();
    }
}

void DataReader::loadFriendLists() {
    if (fileFriends.open(QIODevice::ReadOnly)) {
        for(auto registeredUser : registeredUsers) {
            QString username = registeredUser.first;
            class FriendList friends;
            QTextStream reader(&fileFriends);

            while (!reader.atEnd()) {
                QString readUser;
                QString friendUsername;
                reader >> readUser;
                reader >> friendUsername;

                if(username == readUser) {
                    QVector<class Message> messageConversation;
                    for(auto it = messageList.begin(); it != messageList.end(); it++) {
                        if(username == it->getSender() && friendUsername == it->getReceiver() || username == it->getReceiver() && friendUsername == it->getSender()) {
                            messageConversation.push_back(*it);
                        }
                    }
                    friends.add(friendUsername, messageConversation);
                }
            }
            friendLists.insert(username, friends);
            fileFriends.reset();
        }
        fileFriends.close();
    }
}

void DataReader::loadMessages() {
    if (fileUserMessages.open(QIODevice::ReadOnly)) {
        QTextStream reader(&fileUserMessages);
        while (!reader.atEnd()) {
            //reader >> messageList;
            QString sender;
            QString receiver;
            QString message;
            reader >> sender >> receiver;
            message = reader.readLine();
            class Message msg(sender, receiver, message);
            messageList.add(msg);
        }
        fileUserMessages.close();
    }
}

QMap<QString, class FriendList> DataReader::getFriendLists() {
    return friendLists;
}

class MessageList DataReader::getMessages() {
    return messageList;
}


std::map<QString, User> DataReader::getRegisteredUsers() {
    return registeredUsers;
}