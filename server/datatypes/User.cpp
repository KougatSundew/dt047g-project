//
// Created by jolof on 2022-01-04.
//

#include "User.h"

QDataStream &User::toStream(QDataStream &stream) const {
    stream << username << password;
    return stream;
}

QDataStream &User::fromStream(QDataStream &stream) {
    stream >> username >> password;
    return stream;
}

DataType User::type() const {
    return currentType;
}

void User::setUsername(const QString &username) {
    this->username = username;
}

void User::setPassword(const QString &password) {
    this->password = password;
}

void User::setType(const DataType &type) {
    currentType = type;
}

void User::setIsLoggedIn(const bool &isLoggedIn) {
    this->isLoggedIn = isLoggedIn;
}

QString User::getUsername() const {
    return username;
}

QString User::getPassword() const {
    return password;
}



bool User::getIsLoggedIn() const {
    return isLoggedIn;
}
/**
 * Function neccesary for having a User object as an key in QMap
 * @param tmp1 - const User& tmp1
 * @param tmp2 - const User& tmp2
 * @return - returns a boolean, if tmp1 username is smaller than tmp2's username
 */
bool operator <(const User &tmp1, const User &tmp2) {
    return tmp1.getUsername() < tmp2.getUsername();
}
