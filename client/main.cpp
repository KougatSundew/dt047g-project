#include <QApplication>
#include <QPushButton>
#include "Client.h"
#include "ApplicationCore.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    const QHostAddress ADDRESS("192.168.1.8"); const int PORT = 4040;
    ApplicationCore core;
    /*std::unique_ptr<Client> client = std::make_unique<Client>(nullptr, ADDRESS, PORT);

    StartingWindow main(nullptr,client.get());
    main.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main.show();

    client->sendMessage("Hello");
    */
    return QApplication::exec();
}
