//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// User.h, 2022-01-04 - 2022-01-10

//
// Created by jolof on 2022-01-04.
//

#ifndef CLIENT_USER_H
#define CLIENT_USER_H
#include "AbstractData.h"

class User : public AbstractData {
public:
    User() = default;
    User(const QString &username, const QString &password): username(username), password(password), currentType(DataType::OFFLINE), isLoggedIn(false) {};

    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setType(const DataType &type);
    void setIsLoggedIn(const bool &isLoggedIn);

    [[nodiscard]] QString getUsername() const;
    [[nodiscard]] QString getPassword() const;
    [[nodiscard]] bool getIsLoggedIn() const;

    QDataStream& toStream(QDataStream &stream) const override;
    QDataStream& fromStream(QDataStream &stream) override;
    [[nodiscard]] DataType type() const override;
private:
    QString username;
    QString password;
    DataType currentType;
    bool isLoggedIn;
};

// Compare order for UserData if it is a key in QMap
bool operator <(const User &tmp1, const User &tmp2);

#endif //CLIENT_USER_H
