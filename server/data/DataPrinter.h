//
// Created by jolof on 2022-01-10.
//

#ifndef SERVER_DATAPRINTER_H
#define SERVER_DATAPRINTER_H

#include <QFile>
#include "../datatypes/AbstractData.h"
#include "../datatypes/Message.h"


class DataPrinter {
public:
    DataPrinter() = default;

    static void save(const class Message &data, QString path) {
        QFile _path(path);
        if(_path.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream printer(&_path);
            printer << "\n";
            printer << data;
            _path.close();
        }
    }
};


#endif //SERVER_DATAPRINTER_H
