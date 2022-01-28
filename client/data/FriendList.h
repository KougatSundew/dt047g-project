//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// FriendList.h, 2022-01-06 - 2022-01-10

//
// Created by jolof on 2022-01-06.
//

#ifndef SERVER_FRIENDLIST_H
#define SERVER_FRIENDLIST_H

#include "AbstractData.h"
#include "Message.h"
#include "Friend.h"

class FriendList : public AbstractData {
public:
    FriendList() = default;
    void add(QString username, QVector<class Message> messages);
    void addMessage(QString receiver, class Message message);

    QDataStream& toStream(QDataStream &stream) const override;
    QDataStream& fromStream(QDataStream &stream) override;
    DataType type() const override;

    size_t size();
    QVector<Friend>::iterator begin();
    QVector<Friend>::iterator end();

    QVector<Friend> getFriends() const;
    const Friend *getFriend(QString username) const;
    Friend* getFriendPtr(QString username);
private:
    QVector<Friend> friends;
};


#endif //SERVER_FRIENDLIST_H