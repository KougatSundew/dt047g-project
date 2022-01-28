//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// MessageList.h, 2022-01-06 - 2022-01-10

//
// Created by jolof on 2022-01-06.
//

#ifndef SERVER_MESSAGELIST_H
#define SERVER_MESSAGELIST_H

#include "AbstractData.h"
#include "Message.h"
#include <QVector>

class MessageList : public AbstractData {
public:
    MessageList() = default;
    explicit MessageList(QVector<class Message> messages);

    void add(const class Message& msg);
    QDataStream& toStream(QDataStream &stream) const override;
    QDataStream& fromStream(QDataStream &stream) override;
    DataType type() const override;

    size_t size();
    QVector<class Message>::iterator begin();
    QVector<class Message>::iterator end();

    QVector<class Message> getMessages();
    QVector<class Message> getMessageFromUser(const QString& sender, const QString& receiver);
private:
    QVector<class Message> messages;
};


#endif //SERVER_MESSAGELIST_H
