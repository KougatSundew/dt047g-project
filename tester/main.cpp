#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>
#include <QTcpSocket>
#include "Client.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Client started";
    Client client(QHostAddress("127.0.0.1"));
    client.connectToServer(QHostAddress("192.168.1.8"), 4040);
    client.sendMessage("dadadada");
    return QCoreApplication::exec();
}
