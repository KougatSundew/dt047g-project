#include <QApplication>
#include <QPushButton>
#include "Client.h"
#include "ApplicationCore.h"

int main(int argc, char *argv[]) {
    int currentExitCode = 0;
    do {
        QApplication a(argc, argv);

        const QHostAddress ADDRESS("192.168.1.8"); const int PORT = 4040;
        ApplicationCore core;

        currentExitCode = a.exec();
    } while(currentExitCode == ApplicationCore::EXIT_CODE_REBOOT);
    return currentExitCode;
}
