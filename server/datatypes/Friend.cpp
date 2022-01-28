//
// Created by jolof on 2022-01-07.
//

#include "Friend.h"
/**
 * Override virtual function toStream
 * @param stream - QDataStream containing the data
 * @return - returns a reference QDataStream
 */
QDataStream &Friend::toStream(QDataStream &stream) const {
    stream << username;
    stream << messages;
    return stream;
}
/**
 * Override virtual function fromStream
 * @param stream - QDataStream containing the data
 * @return - returns a reference QDataStream
 */
QDataStream &Friend::fromStream(QDataStream &stream) {
    stream >> username;
    stream >> messages;
    return stream;
}
/**
 * Function for getting the type of data
 * @return - returns a type of DataType, in this case FriendList
 */
DataType Friend::type() const {
    return FriendList;
}
/**
 * Function getter getUsername
 * @return - returns QString containing the username of the friend
 */
QString Friend::getUsername() const {
    return username;
}
/**
 * Function for getting a QVector containing the messages from the friend
 * @return - returns QVector<class Message>
 */
QVector<class Message> Friend::getMessages() const {
    return messages;
}
/**
 * Function for adding a message to a friend
 * @param message - class Message containing message data
 */
void Friend::addMessage(class Message message) {
    messages.push_back(message);
}
/**
 * Setter for setting the username of the friend
 * @param username - const QString& containing the username
 */
void Friend::setUsername(const QString &username) {
    Friend::username = username;
}
/**
 * Setter for setting the messages
 * @param messages - const QVector<class Message>& containing messages
 */
void Friend::setMessages(const QVector<class Message> &messages) {
    Friend::messages = messages;
}
