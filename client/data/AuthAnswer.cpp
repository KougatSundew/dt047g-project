//
// Created by jolof on 2022-01-04.
//

#include "AuthAnswer.h"
/**
 * Overridoing the toStream function
 * @param stream - QDataStream
 * @return
 */
QDataStream &AuthAnswer::toStream(QDataStream &stream) const {
    stream << isSignedIn;
    return stream;
}

QDataStream &AuthAnswer::fromStream(QDataStream &stream) {
    stream >> isSignedIn;
    return stream;
}

DataType AuthAnswer::type() const {
    return DataType::AuthResponse;
}

bool AuthAnswer::isSigned() const {
    return isSignedIn;
}

void AuthAnswer::setSigned(bool isSignedIn) {
    this->isSignedIn = isSignedIn;
}