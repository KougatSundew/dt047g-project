//
// Created by jolof on 2022-01-04.
//

#include "Message.h"

Message::Message(const QString &sender, const QString &receiver, const QString &message): sender(sender), receiver(receiver), message(message) {}

QDataStream& Message::fromStream(QDataStream &stream) {
    stream >> sender;
    stream >> receiver;
    stream >> message;
    return stream;
}

QDataStream& Message::toStream(QDataStream &stream) const {
    stream << sender << receiver << message;
    return stream;
}

QTextStream &Message::toStream(QTextStream &stream) const {
    stream << sender << " " << receiver << " " << message;
    return stream;
}

QTextStream &Message::fromStream(QTextStream &stream) {
    stream >> sender;
    stream >> receiver;
    message = stream.readAll();
    return stream;
}

DataType Message::type() const {
    return DataType::Message;
}

void Message::setSender(const QString &sender) {
    this->sender = sender;
}

void Message::setReceiver(const QString &receiver) {
    this->receiver = receiver;
}

void Message::setMessage(const QString &message) {
    this->message = message;
}

QString Message::getSender() const {
    return sender;
}

QString Message::getReceiver() const {
    return receiver;
}

QString Message::getMessage() const {
    return message;
}

QTextStream &operator>>(QTextStream &stream, class Message &data) {
    return data.fromStream(stream);
}

QTextStream &operator<<(QTextStream &stream, const class Message &data) {
    return data.toStream(stream);
}



