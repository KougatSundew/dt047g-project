//
// Created by jolof on 2022-01-04.
//

#include "AbstractData.h"
/**
 * Operator << overloading of QDataStream
 * @param ostream . QDataStream
 * @param data - AbstractData
 * @return - returns QDataStream
 */
QDataStream &operator << (QDataStream &ostream, const AbstractData &data) {
    return data.toStream(ostream);
}
/**
 * Operator >> overloading of QDataStream
 * @param istream . QDataStream
 * @param data - AbstractData
 * @return - returns QDataStream
 */
QDataStream &operator >> (QDataStream &istream, AbstractData &data) {
    return data.fromStream(istream);
}