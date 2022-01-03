//
// Created by jolof on 2021-12-29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StartingWindow.h" resolved

#include <QMovie>
#include "startingwindow.h"
#include "ui_StartingWindow.h"


StartingWindow::StartingWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::StartingWindow) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->grpBoxLogin->hide();
    //Sets label color styles TODO: move to .ui file instead maybe?
    ui->lblTitle->setStyleSheet("color: white;");
    ui->lblStatus->setStyleSheet("color: white");
    ui->txtLineUsername->setStyleSheet("color: white");
    ui->txtLinePassword->setStyleSheet("color: white");
    ui->lblStatusLogin->setStyleSheet("color: red");
    //Set password mode for txtLinePassword
    ui->txtLinePassword->setEchoMode(QLineEdit::Password);
    //Adds a loader of type QMovie to lblLoader
    loadAnimation = new QMovie("C:/Users/jolof/Downloads/45.gif");
    ui->lblLoader->setMovie(loadAnimation);
    loadAnimation->start();

    //connect(client, &Client::connected, this, &StartingWindow::connectedToServer);
    connect(ui->btnLogin, &QPushButton::pressed, this, &StartingWindow::onLoginBtnPress);
    attemptConnection();
}

StartingWindow::~StartingWindow() {
    delete ui;
}

void StartingWindow::attemptConnection() {

}

void StartingWindow::connectedToServer() {
    ui->lblStatus->setText("Connected");
}

void StartingWindow::disconnectedFromServer() {

}

void StartingWindow::switchToLogin() {
    ui->grpBoxLoading->hide();
    loadAnimation->stop();
    ui->grpBoxLogin->show();
}

void StartingWindow::switchToLoading() {
    ui->grpBoxLogin->hide();
    loadAnimation->start();
    ui->grpBoxLoading->show();
}

void StartingWindow::onLoginBtnPress() {
    std::cout << "StartingWindow btn press" << "\n";
    emit loginButtonPressed(ui->txtLineUsername->text(), ui->txtLinePassword->text());
}

void StartingWindow::setLoginStatus(const QString &status) {
    ui->lblStatusLogin->setText(status);
}

void StartingWindow::setSocketConnStatus(const QString &status) {
    ui->lblStatus->setText(status);
}
