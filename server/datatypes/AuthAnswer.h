//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// AuthAnswer.h, 2022-01-04 - 2022-01-13
// Contains the header definitions
//

//
// Created by jolof on 2022-01-04.
//

#ifndef CLIENT_AUTHANSWER_H
#define CLIENT_AUTHANSWER_H
#include "AbstractData.h"

class AuthAnswer : public AbstractData {
public:
    AuthAnswer() = default;
    explicit AuthAnswer(bool isSignedIn): isSignedIn(isSignedIn) {};

    QDataStream& toStream(QDataStream &stream) const override;
    QDataStream& fromStream(QDataStream &stream) override;
    [[nodiscard]] DataType type() const override;

    [[nodiscard]] bool isSigned() const;
    void setSigned(bool isSignedIn);

private:
    bool isSignedIn;
};


#endif //CLIENT_AUTHANSWER_H
