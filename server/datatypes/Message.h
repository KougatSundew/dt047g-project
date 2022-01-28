//
// Created by jolof on 2022-01-04.
//

#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H
#include "AbstractData.h"

class Message : public AbstractData {
    QString sender;
    QString receiver;
    QString message;
public:
    Message() = default;
    Message(const QString &sender, const QString &receiver, const QString &message);

    virtual QDataStream& toStream(QDataStream &stream) const override;
    virtual QDataStream& fromStream(QDataStream &stream) override;
    virtual DataType type() const override;

    friend QTextStream &operator >> (QTextStream &stream, class Message  &data);
    friend QTextStream &operator << (QTextStream &stream, const class Message  &data);

    QTextStream& toStream(QTextStream &stream) const;
    QTextStream& fromStream(QTextStream &stream);

    //Getters & setters
    void setSender(const QString &sender);
    void setReceiver(const QString &receiver);
    void setMessage(const QString &message);

    QString getSender() const;
    QString getReceiver() const;
    QString getMessage() const;
};

QTextStream &operator >> (QTextStream &stream, AbstractData &data);
QTextStream &operator << (QTextStream &stream, AbstractData &data);


#endif //SERVER_MESSAGE_H
