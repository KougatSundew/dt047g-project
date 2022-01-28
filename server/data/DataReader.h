//
// Created by jolof on 2022-01-06.
//

#ifndef SERVER_DATAREADER_H
#define SERVER_DATAREADER_H

#include <QDataStream>
#include <QTextStream>
#include <fstream>
#include <QFile>
#include <iostream>
#include <memory>
#include "../datatypes/User.h"
#include "../datatypes/FriendList.h"
#include "../datatypes/MessageList.h"

enum TypeOfData {
    RegisteredUsers,
    Groups,
    UserJoinedGroups,
    Friends,
    UserMessages,
    GroupMessages
};

class DataReader {
public:
    DataReader();
    std::map<QString, User> getRegisteredUsers();
    QMap<QString, class FriendList> getFriendLists();
    class MessageList getMessages();
private:
    void loadMessages();
    void loadRegisteredUsers();
    void loadFriendLists();
    void read(TypeOfData);

    std::map<QString, User> registeredUsers;
    QMap<QString, class FriendList> friendLists;
    class MessageList messageList;

    QFile fileRegisteredUsers;
    QFile fileFriends;
    QFile fileUserMessages;
};


#endif //SERVER_DATAREADER_H
