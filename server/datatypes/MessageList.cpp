//
// Created by jolof on 2022-01-06.
//

#include "MessageList.h"
/**
 * Constructor
 * @param messages - QVector<Message>
 */
MessageList::MessageList(QVector<class Message> messages) : messages(messages) {

}
/**
 * Override virtual function toStream
 * @param stream - QDataStream& containing the data
 * @return - returns QDataStream&
 */
QDataStream &MessageList::toStream(QDataStream &stream) const {
    stream << messages;
    return stream;
}
/**
 * Override virtual function fromStream
 * @param stream - QDataStream& containing the data
 * @return - returns QDataStream&
 */
QDataStream &MessageList::fromStream(QDataStream &stream) {
    stream >> messages;
    return stream;
}
/**
 * Override virtual function type
 * @return - returns DataType
 */
DataType MessageList::type() const {
    return DataType::MessageList;
}
/**
 * Function for adding a message to messages
 * @param msg - const Message&
 */
void MessageList::add(const class Message& msg) {
    messages.push_back(msg);
}
/**
 * Function for getting the size of QVector<Message> messages
 * @return - returns a size_t
 */
size_t MessageList::size() {
    return messages.size();
}
/**
 * Function for getting the begin iterator of QVector<Message>
 * @return - returns QVector<class Message>::iterator
 */
QVector<class Message>::iterator MessageList::begin() {
    return messages.begin();
}
/**
 * Function for getting the end iterator of QVector<Message>
 * @return - returns QVector<class Message>::iterator
 */
QVector<class Message>::iterator MessageList::end() {
    return messages.end();
}
/**
 * Function for getting the QVector<Message> messages
 * @return - returns QVector<Message>
 */
QVector<class Message> MessageList::getMessages() {
    return messages;
}
/**
 * Function for getting a messages from a user to a specific receiver
 * @param sender - const QString& containing the username of the sender
 * @param receiver - const QString& containing the username of the receiver
 * @return - returns a QVector<Messsage> containing all the messages that meet the specific requeriment
 */
QVector<class Message> MessageList::getMessageFromUser(const QString& sender, const QString& receiver) {
    QVector<class Message> tmpMessages;
    std::copy_if(messages.begin(), messages.end(), tmpMessages.begin(),[sender, receiver](const class Message& message) {
        return (sender == message.getSender() && receiver == message.getReceiver());
    });
    return tmpMessages;
}
