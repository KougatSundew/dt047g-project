#include <QCoreApplication>
#include <QDebug>
#include "Server.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Server application started";
    Server srv; const QHostAddress ADDRESS("192.168.1.8"); const int PORT = 4040;

    if(!srv.listen(ADDRESS, PORT)) {
        std::cerr << "Server could not start" << "\n";
    }
    std::cout << "Server started on IP: 192.168.1.8 PORT: 4040" << "\n";
    return QCoreApplication::exec();
}
