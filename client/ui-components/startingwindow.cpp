//
// Created by jolof on 2021-12-29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StartingWindow.h" resolved

#include <QMovie>
#include "startingwindow.h"
#include "ui_StartingWindow.h"

/**
 * Constructor
 * @param parent - QObject parent for signals and slots
 */
StartingWindow::StartingWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::StartingWindow) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->grpBoxLogin->hide();

    setStyleSettings();
    initLoadAnimation();

    connect(ui->btnLogin, &QPushButton::clicked, this, &StartingWindow::onLoginBtnPress);
}
/**
 * Destructor for ui
 */
StartingWindow::~StartingWindow() {
    delete ui;
}

/**
 * Function for switching the ui to the login form
 */
void StartingWindow::switchToLogin() {
    ui->grpBoxLoading->hide();
    loadAnimation->stop();
    ui->grpBoxLogin->show();
}
/**
 * Function for switching the ui from login form to the loading window
 */
void StartingWindow::switchToLoading() {
    ui->grpBoxLogin->hide();
    loadAnimation->start();
    ui->grpBoxLoading->show();
}
/**
 * Function slot for login button pressed
 */
void StartingWindow::onLoginBtnPress() {
    if(!ui->txtLineUsername->text().isEmpty() && !ui->txtLinePassword->text().isEmpty()) {
        resetLoginStatus();
        emit loginButtonPressed(ui->txtLineUsername->text(), ui->txtLinePassword->text());
    } else {
        setLoginStatus("Username or password is empty");
    }
}
/**
 * Function for setting the login status
 * @param status - QString containing the status
 */
void StartingWindow::setLoginStatus(const QString &status) {
    ui->lblStatusLogin->setText(status);
}
/**
 * Function for setting the login status to empty
 */
void StartingWindow::resetLoginStatus() {
    ui->lblStatusLogin->setText("");
}
/**
 * Function for setting the connection status
 * @param status - QString containing the status
 */
void StartingWindow::setSocketConnStatus(const QString &status) {
    ui->lblStatus->setText(status);
}
/**
 * Function for init the loader
 */
void StartingWindow::initLoadAnimation() {
    //Adds a loader of type QMovie to lblLoader
    loadAnimation = std::make_unique<QMovie>("../gif/loader.gif");
    ui->lblLoader->setMovie(loadAnimation.get());
    loadAnimation->start();
}
/**
 * Function for setting style properties on the ui
 */
void StartingWindow::setStyleSettings() {
    //Sets label color styles
    ui->lblTitle->setStyleSheet("color: white;");
    ui->lblStatus->setStyleSheet("color: white");
    ui->txtLineUsername->setStyleSheet("color: white");
    ui->txtLinePassword->setStyleSheet("color: white");
    ui->lblStatusLogin->setStyleSheet("color: red");
    //Set password mode for txtLinePassword
    ui->txtLinePassword->setEchoMode(QLineEdit::Password);
}

