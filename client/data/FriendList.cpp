//
// Created by jolof on 2022-01-06.
//

#include "FriendList.h"

/**
 * Function override of virtual toStream
 * @param stream - QDataStream& containing the data
 * @return - returns a QDataStream&
 */
QDataStream &FriendList::toStream(QDataStream &stream) const {
    stream << friends;
    return stream;
}
/**
 * Function override of virtual fromStream
 * @param stream - QDataStream& containing the data
 * @return - returns a QDataStream&
 */
QDataStream &FriendList::fromStream(QDataStream &stream) {
    stream >> friends;
    return stream;
}
/**
 * Override virtual function type
 * @return - Returns DataType
 */
DataType FriendList::type() const {
    return DataType::FriendList;
}

/**
 * Function for adding a friend with messages
 * @param username - QString containing the username
 * @param messages - QVector<class Message> containing the messages
 */
void FriendList::add(QString username, QVector<class Message> messages) {
    friends.push_back(Friend(username, messages));
}
/**
 * Function for adding a specific message to a friend
 * @param receiver - QString containing the username of the friend
 * @param message - Message containing the message
 */
void FriendList::addMessage(QString receiver, class Message message) {
    for(auto iterator = friends.begin(); iterator != friends.end(); iterator++) {
        if(iterator->getUsername() == receiver) {
            iterator->addMessage(message);
        }
    }
}
/**
 * Function for getting the size
 * @return
 */
size_t FriendList::size() {
    return friends.size();
}
/**
 * Function for getting the begin iterator of the QVector<Friend>
 * @return
 */
QVector<Friend>::iterator FriendList::begin() {
    return friends.begin();
}
/**
 * Function for getting the end iterator of the QVector<Friend>
 * @return
 */
QVector<Friend>::iterator FriendList::end() {
    return friends.end();
}
/**
 * Function for getting the friendslist
 * @return
 */
QVector<Friend> FriendList::getFriends() const {
    return friends;
}
/**
 * Function for getting a specific friend
 * @param username - QString containing the username
 * @return - returns const Friend pointer
 */
const Friend *FriendList::getFriend(QString username) const {
    auto user = std::find_if(friends.begin(), friends.end(), [username](Friend user) {
        return username == user.getUsername();
    });
    return user;
}
/**
 * Function for getting the pointer of a specific Friend
 * @param username - QString containing the username
 * @return - returns Friend pointer
 */
Friend *FriendList::getFriendPtr(QString username) {
    Friend* tmpUser;
    for(auto user : friends) {
        if(username == user.getUsername()) {
            tmpUser = &user;
            return tmpUser;
        }
    }
    return nullptr;
}