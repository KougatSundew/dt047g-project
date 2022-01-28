//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// AbstractData.h, 2022-01-04 - 2022-01-13
// Contains the header definitions and implementation of the abstract class
//

//
// Created by jolof on 2022-01-04.
//

#ifndef DT047G_PROJECT_ABSTRACTDATA_H
#define DT047G_PROJECT_ABSTRACTDATA_H

#include <QDataStream>
#include <QTextStream>
//enum containing different datatypes
enum DataType : short int {
    AuthRequest,
    AuthResponse,
    Message,
    FriendList,
    MessageList,
    ONLINE,
    OFFLINE,
};

class AbstractData {
public:
    explicit AbstractData() = default;

    friend QDataStream &operator >> (QDataStream &ostream, AbstractData &data);
    friend QDataStream &operator << (QDataStream &istream, const AbstractData &data);

    virtual QDataStream& toStream(QDataStream &stream) const = 0;
    virtual QDataStream& fromStream(QDataStream &stream) = 0;

    virtual DataType type() const = 0;
};

QDataStream &operator >> (QDataStream &stream, AbstractData &data);
QDataStream &operator << (QDataStream &stream, AbstractData &data);

#endif //DT047G_PROJECT_ABSTRACTDATA_H
