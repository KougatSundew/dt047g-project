//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// Friend.h, 2022-01-07 - 2022-01-10
// Contains the neccesary functions
//


//
// Created by jolof on 2022-01-07.
//

#ifndef SERVER_FRIEND_H
#define SERVER_FRIEND_H

#include <QVector>
#include "AbstractData.h"
#include "Message.h"

class Friend : public AbstractData {
public:
    Friend() = default;
    Friend(QString username, QVector<class Message> messages) : username(username), messages(messages) {};
    Friend(QString username) : username(username) {};

    void addMessage(class Message message);

    QDataStream& toStream(QDataStream &stream) const override;
    QDataStream& fromStream(QDataStream &stream) override;
    DataType type() const override;

    void setUsername(const QString &username);
    void setMessages(const QVector<struct Message> &messages);

    QString getUsername() const;
    QVector<class Message> getMessages() const;
private:
    QString username;
    QVector<class Message> messages;
};


#endif //SERVER_FRIEND_H
